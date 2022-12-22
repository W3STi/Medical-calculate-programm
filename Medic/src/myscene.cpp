#include "myscene.h"
#include "arrow.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>

MyScene::MyScene( QObject* parent )
    : QGraphicsScene( parent )
{
    line = 0;
    setSceneRect( 0, 0, 5000, 5000 );
}

void MyScene::SetPixmap( const QPixmap pix )
{
    pixmap = pix;
    auto item = addPixmap( pix );
    item->setZValue( -2000.0 );
    item->setPos( 2500 - pixmap.width() / 2, 2500 - pixmap.height() / 2 );
}

void MyScene::SetRatio( const double rat )
{
    ratio = rat;
}

void MyScene::SetState( const State st )
{
    state = st;
}

QPixmap MyScene::GetPixmap()
{
    return pixmap;
}

double MyScene::GetRatio()
{
    return ratio;
}

MyScene::State MyScene::GetState()
{
    return state;
}

MyGraphicsItem* MyScene::CreatePoint()
{
    MyGraphicsItem* item = new MyGraphicsItem();
    QPolygonF polygon;
    polygon << QPointF( -5, -5 )
            << QPointF( -5, 5 )
            << QPointF( 5, 5 )
            << QPointF( 5, -5 );

    /*
    int n = 32;
    double Pi = 3.1415926535;
    double step = 2 * Pi / n;
    int razmer = 7;

    for( int i = 0; i < n; i++ )
    {
        polygon << QPointF( razmer * cos( i * step ), razmer * sin( i * step ) );
    }
*/
    item->setPolygon( polygon );
    item->setPen( QPen( Qt::green ) );
    // item->setBrush( QBrush( Qt::green ) );
    return item;
}

Arrow* MyScene::CreateArrow( MyGraphicsItem* startItem, MyGraphicsItem* endItem )
{
    Arrow* arrow = new Arrow( startItem, endItem, ratio );
    arrow->setColor( color_arrow );
    startItem->AddArrow( arrow );
    endItem->AddArrow( arrow );
    arrow->setZValue( -1000.0 );
    addItem( arrow );
    arrow->updatePosition();
    return arrow;
}

void MyScene::mousePressEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
    MyGraphicsItem* item;
    switch ( state )
    {
    case None:
        break;
    case Line:
        item = CreatePoint();
        item->setPos( mouseEvent->scenePos() );
        addItem( item );
        last_item = item;

        line = new QGraphicsLineItem( QLineF( mouseEvent->scenePos(),
            mouseEvent->scenePos() ) );
        line->setPen( QPen( Qt::black, 2 ) );
        addItem( line );
        state = LineStart;
        break;
    case LineStart:
        break;
    case Angle:
        item = CreatePoint();
        item->setPos( mouseEvent->scenePos() );
        addItem( item );
        last_item = item;

        line = new QGraphicsLineItem( QLineF( mouseEvent->scenePos(),
            mouseEvent->scenePos() ) );
        line->setPen( QPen( Qt::black, 2 ) );
        addItem( line );
        state = AngleStart;
        break;
    case AngleStart:
        break;
    case AngleMiddle:
        item = CreatePoint();
        item->setPos( mouseEvent->scenePos() );
        addItem( item );

        removeItem( line );
        delete line;

        CreateArrow( last_item, item );
        last_item = item;
        state = None;
        break;
    default:
        break;
    };
    QGraphicsScene::mousePressEvent( mouseEvent );
}

void MyScene::mouseMoveEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
    if ( ( LineStart == state || AngleStart == state || AngleMiddle == state )
        && line != 0 )
    {
        QLineF newLine( line->line().p1(), mouseEvent->scenePos() );
        line->setLine( newLine );
    }
    else if ( None == state && this->selectedItems().size() && MyGraphicsItem::Type == this->selectedItems()[0]->type() )
    {
        QGraphicsScene::mouseMoveEvent( mouseEvent );
    }
}

void MyScene::mouseReleaseEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
    if ( ( LineStart == state || AngleStart == state || AngleMiddle == state )
        && line != 0 )
    {
        MyGraphicsItem* item = CreatePoint();
        item->setPos( mouseEvent->scenePos() );
        addItem( item );

        removeItem( line );
        delete line;

        MyGraphicsItem* startItem = last_item;
        MyGraphicsItem* endItem = item;
        last_item = item;
        CreateArrow( startItem, endItem );
        if ( AngleStart == state )
        {
            line = new QGraphicsLineItem( QLineF( mouseEvent->scenePos(),
                mouseEvent->scenePos() ) );
            line->setPen( QPen( Qt::black, 2 ) );
            addItem( line );

            state = AngleMiddle;
        }
        else
        {
            line = 0;
            state = None;
        }
    }

    QGraphicsScene::mouseReleaseEvent( mouseEvent );
}

void MyScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
}
