#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsPolygonItem>

class Arrow;

class MyGraphicsItem : public QGraphicsPolygonItem
{
public:
    enum { Type = UserType + 2 };

    MyGraphicsItem( QGraphicsItem* parent = 0 );

    int type() const override { return Type;}
    void RemoveArrow(Arrow* arrow);
    void RemoveArrows();
    void AddArrow(Arrow* arrow);
    QList<Arrow*> getArrows();

    QVariant itemChange( GraphicsItemChange change, const QVariant& value ) override;

private:
    QList<Arrow *> arrows;
};

#endif // MYGRAPHICSITEM_H
