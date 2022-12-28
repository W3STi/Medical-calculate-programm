#include "myscene.h"
#include "arrow.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>

MyScene::MyScene( QObject* parent )
    : QGraphicsScene( parent )
{
    line = 0;
    circle = 0;
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
    polygon << QPointF( -7, -7 )
            << QPointF( -7, 7 )
            << QPointF( 7, 7 )
            << QPointF( 7, -7 );

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

Arrow* MyScene::CreateArrow( MyGraphicsItem* startItem, MyGraphicsItem* endItem, Arrow::TypeArrow type_arrow )
{
    Arrow* arrow = new Arrow( startItem, endItem, ratio );
    arrow->setTypeArrow( type_arrow );
    arrow->setColor( color_arrow );
    if ( spin_box != nullptr )
    {
        arrow->setSpinBox( spin_box );
    }
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
    int radius;
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
        line->setPen( QPen( color_arrow, 3 ) );
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

        CreateArrow( last_item, item, Arrow::Angle );
        last_item = item;
        state = None;
        break;
    case Circle:
        item = CreatePoint();
        item->setPos( mouseEvent->scenePos() );
        addItem( item );
        last_item = item;

        line = new QGraphicsLineItem( QLineF( mouseEvent->scenePos(),
            mouseEvent->scenePos() ) );
        line->setPen( QPen( color_arrow, 3 ) );
        addItem( line );
        radius = qSqrt( qPow( item->pos().x() - mouseEvent->scenePos().x(), 2 ) + qPow( item->pos().y() - mouseEvent->scenePos().y(), 2 ) );

        circle
            = new QGraphicsEllipseItem( mouseEvent->scenePos().x() - radius,
                mouseEvent->scenePos().y() - radius,
                radius,
                radius );
        addItem( circle );
        state = CircleStart;
    default:
        break;
    };
    QGraphicsScene::mousePressEvent( mouseEvent );
}

void MyScene::mouseMoveEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
    if ( ( LineStart == state || AngleStart == state || AngleMiddle == state || CircleStart == state )
        && line != 0 )
    {
        QLineF newLine( line->line().p1(), mouseEvent->scenePos() );
        line->setLine( newLine );
        if ( CircleStart == state )
        {
            int radius = qSqrt( qPow( line->line().p1().x() - mouseEvent->scenePos().x(), 2 ) + qPow( line->line().p1().y() - mouseEvent->scenePos().y(), 2 ) );

            circle->setRect( line->line().p1().x() - radius,
                line->line().p1().y() - radius,
                2 * radius,
                2 * radius );
        }
    }
    else if ( None == state && this->selectedItems().size() && MyGraphicsItem::Type == this->selectedItems()[0]->type() )
    {
        QGraphicsScene::mouseMoveEvent( mouseEvent );
    }
}

void MyScene::mouseReleaseEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
    if ( ( LineStart == state || AngleStart == state || AngleMiddle == state || CircleStart == state )
        && line != 0 )
    {
        MyGraphicsItem* item = CreatePoint();
        item->setPos( mouseEvent->scenePos() );
        addItem( item );

        removeItem( line );
        delete line;
        if ( CircleStart == state )
        {
            removeItem( circle );
            delete circle;
        }

        MyGraphicsItem* startItem = last_item;
        MyGraphicsItem* endItem = item;
        last_item = item;

        switch ( state )
        {
        case LineStart:
            CreateArrow( startItem, endItem, Arrow::Line );
            break;
        case AngleStart:
        case AngleMiddle:
            CreateArrow( startItem, endItem, Arrow::Angle );
            break;
        case CircleStart:
            CreateArrow( startItem, endItem, Arrow::Circle );
            break;
        default:
            break;
        }

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
            circle = 0;
            state = None;
        }
    }

    QGraphicsScene::mouseReleaseEvent( mouseEvent );
}

void MyScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent* mouseEvent )
{
}

void MyScene::setSpinBox( QDoubleSpinBox* spin )
{
    spin_box = spin;
}
