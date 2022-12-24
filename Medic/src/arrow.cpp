#include "arrow.h"

#include "arrow.h"

#include <QPainter>
#include <QPen>
#include <qmath.h>

Arrow::Arrow( MyGraphicsItem* startItem, MyGraphicsItem* endItem, double ratio, QGraphicsItem* parent )
    : QGraphicsLineItem( parent )
{
    scene_ratio = ratio;
    myStartItem = startItem;
    myEndItem = endItem;
    setFlag( QGraphicsItem::ItemIsSelectable, true );
    myColor = Qt::black;
    setPen( QPen( myColor, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin ) );

    proxy_widget = new QGraphicsProxyWidget( this );
    label = new QLabel( QString::number( sqrt( pow( endItem->pos().x() - startItem->pos().x(), 2 ) + pow( endItem->pos().y() - startItem->pos().y(), 2 ) ) * scene_ratio ) + "mm" );
    label->setVisible( true );
    label->setAlignment( Qt::AlignHCenter | Qt::AlignVCenter );
    label->setStyleSheet( "background-color: #FAEBD7" );
    proxy_widget->setWidget( label );
}

QRectF Arrow::boundingRect() const
{
    qreal extra = ( pen().width() + 20 ) / 2.0;

    return QRectF( line().p1(), QSizeF( line().p2().x() - line().p1().x(), line().p2().y() - line().p1().y() ) )
        .normalized()
        .adjusted( -extra, -extra, extra, extra );
}
/*
QPainterPath Arrow::shape() const
{
    //QPainterPath path = QGraphicsLineItem::shape();
    //path.addPolygon(arrowHead);
    //return path;
}
*/
void Arrow::updatePosition()
{
    QLineF line( mapFromItem( myStartItem, 0, 0 ), mapFromItem( myEndItem, 0, 0 ) );
    setLine( line );
    QRectF rect = boundingRect();
    // костыль
    if ( label->text().isEmpty() )
    {
        label->setVisible( false );
    }
    label->setGeometry( rect.x() + rect.width() / 2 - 60, rect.y() + rect.height() / 2 - 12, 120, 25 );
    razmer = sqrt( pow( myEndItem->pos().x() - myStartItem->pos().x(), 2 ) + pow( myEndItem->pos().y() - myStartItem->pos().y(), 2 ) ) * scene_ratio;
    label->setText( QString::number( razmer ) + "mm" );
    spin_box->setValue( razmer );
}

void Arrow::paint( QPainter* painter, const QStyleOptionGraphicsItem*,
    QWidget* )
{
    if ( myStartItem->collidesWithItem( myEndItem ) )
        return;

    QPen myPen = pen();
    myPen.setColor( myColor );
    // qreal arrowSize = 20;
    painter->setPen( myPen );
    painter->setBrush( myColor );

    QLineF centerLine( myStartItem->pos(), myEndItem->pos() );
    QPolygonF endPolygon = myEndItem->polygon();
    // QPointF p1 = endPolygon.first() + myEndItem->pos();
    // QPointF p2;
    // QPointF intersectPoint = p1;
    // QLineF polyLine;
    /*
        for (int i = 1; i < endPolygon.count(); ++i) {
            p2 = endPolygon.at(i) + myEndItem->pos();
            polyLine = QLineF(p1, p2);
            QLineF::IntersectType intersectType =
                polyLine.intersect(centerLine, &intersectPoint);
            if (intersectType == QLineF::BoundedIntersection)
                break;
            p1 = p2;
        }
    */
    setLine( QLineF( myEndItem->pos(), myStartItem->pos() ) );
    /*
        double angle = std::atan2(-line().dy(), line().dx());

        QPointF arrowP1 = line().p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                        cos(angle + M_PI / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                        cos(angle + M_PI - M_PI / 3) * arrowSize);

        arrowHead.clear();
        arrowHead << line().p1() << arrowP1 << arrowP2;

        //painter->drawPolygon(arrowHead);
    */

    painter->drawLine( line() );
    if ( isSelected() )
    {
        painter->setPen( QPen( myColor, 1, Qt::DashLine ) );
        QLineF myLine = line();
        myLine.translate( 0, 4.0 );
        painter->drawLine( myLine );
        myLine.translate( 0, -8.0 );
        painter->drawLine( myLine );
    }
}

void Arrow::setSpinBox( QDoubleSpinBox* spin )
{
    spin_box = spin;
}
