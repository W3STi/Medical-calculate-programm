#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QLabel>
#include <QGraphicsProxyWidget>

#include "mygraphicsitem.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE

class Arrow : public QGraphicsLineItem
{
public:

    Arrow(MyGraphicsItem *startItem, MyGraphicsItem *endItem, double ratio = 0.0,
      QGraphicsItem *parent = 0);

    int type() const override { return Type; }
    QRectF boundingRect() const override;
    //QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    MyGraphicsItem* startItem() const { return myStartItem; }
    MyGraphicsItem* endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    double scene_ratio = 0.0;
    MyGraphicsItem* myStartItem;
    MyGraphicsItem* myEndItem;
    QColor myColor;
    //QPolygonF arrowHead;
    QLabel* label;
    QGraphicsProxyWidget* proxy_widget;
};

#endif // ARROW_H
