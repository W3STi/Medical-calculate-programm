#include "mygraphicsitem.h"
#include "arrow.h"

#include <QGraphicsScene>

MyGraphicsItem::MyGraphicsItem( QGraphicsItem* parent )
    : QGraphicsPolygonItem( parent )
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void MyGraphicsItem::RemoveArrow( Arrow* arrow )
{
    int index = arrows.indexOf( arrow );

    if ( -1 != index )
    {
        arrows.removeAt(index);
    }
}

void MyGraphicsItem::RemoveArrows()
{
    foreach ( Arrow *arrow, arrows )
    {
        arrow->startItem()->RemoveArrow(arrow);
        arrow->endItem()->RemoveArrow(arrow);
        scene()->removeItem(arrow);
        delete arrow;
    }
}

void MyGraphicsItem::AddArrow( Arrow* arrow )
{
    arrows.append(arrow);
}

QList<Arrow*> MyGraphicsItem::getArrows()
{
    return arrows;
}

QVariant MyGraphicsItem::itemChange( GraphicsItemChange change, const QVariant& value )
{
    if ( QGraphicsItem::ItemPositionChange == change )
    {
        foreach (Arrow *arrow, arrows)
        {
            arrow->updatePosition();
        }
    }

    return value;
}
