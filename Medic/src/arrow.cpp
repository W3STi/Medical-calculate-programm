#include "arrow.h"

#include "arrow.h"

#include <QPainter>
#include <QPen>
#include <qmath.h>

Arrow::Arrow(MyGraphicsItem* startItem, MyGraphicsItem* endItem, double ratio, QGraphicsItem* parent)
    : QGraphicsLineItem(parent)
{
    scene_ratio = ratio;
    myStartItem = startItem;
    myEndItem = endItem;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = Qt::black;
    setPen(QPen(myColor, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    proxy_widget = new QGraphicsProxyWidget(this);
    label = new QLabel(QString::number(sqrt(pow(endItem->pos().x() - startItem->pos().x(), 2) + pow(endItem->pos().y() - startItem->pos().y(), 2)) * scene_ratio) + "mm");
    label->setVisible(true);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setStyleSheet("background-color: #FAEBD7");
    proxy_widget->setWidget(label);
}

QRectF Arrow::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(), line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
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
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
    QRectF rect = boundingRect();
    // костыль
    if (label->text().isEmpty())
    {
        label->setVisible(false);
    }
    label->setGeometry(rect.x() + rect.width() / 2 - 40, rect.y() + rect.height() / 2 - 12, 80, 25);

    if (Circle == type_arrow)
    {
        if (circle == nullptr)
        {
            circle = new QGraphicsEllipseItem(this);
            circle->setPen(QPen(myColor, 2));
        }

        int radius = qSqrt(qPow(line.p1().x() - line.p2().x(), 2) + qPow(line.p1().y() - line.p2().y(), 2));

        circle->setRect(line.p1().x() - radius,
            line.p1().y() - radius,
            2 * radius,
            2 * radius);
    }
    if (Angle == type_arrow)
    {
        Arrow* arrow = 0;
        auto point_A = myStartItem;
        auto point_B = myEndItem;
        auto point_C = point_B;
        if (point_A->getArrows().size() > 1)
        {
            point_A = myEndItem;
            point_B = myStartItem;
        }

        auto arrow_mid = point_B->getArrows();
        if (arrow_mid.size() == 1)
        {
            label->setText(QString::number(0) + " °");
        }
        else
        {
            if (arrow_mid[0] != this)
            {
                arrow = arrow_mid[0];
            }
            else if (arrow_mid[1] != this)
            {
                arrow = arrow_mid[1];
            }

            if (arrow->startItem() != point_B)
            {
                point_C = arrow->startItem();
            }
            else
            {
                point_C = arrow->endItem();
            }
        }
        spin_box->setValue(qAbs((int)(getAngleABC(point_A->pos(), point_B->pos(), point_C->pos())) % 180));
        if (arrow != nullptr)
            arrow->setValue(spin_box->value());
        label->setText(QString::number(spin_box->value()) + " °");
    }
    else
    {
        razmer = sqrt(pow(myEndItem->pos().x() - myStartItem->pos().x(), 2) + pow(myEndItem->pos().y() - myStartItem->pos().y(), 2)) * scene_ratio;
        if (Circle == type_arrow)
            razmer *= 2;
        label->setText(QString::number(razmer) + "px");
        spin_box->setValue(razmer);
    }
}

void Arrow::setValue(double value)
{
    label->setText(QString::number(value) + " °");
}

double Arrow::getAngleABC(QPointF point_a, QPointF point_b, QPointF point_c)
{
    QPointF ab = { point_b.x() - point_a.x(), point_b.y() - point_a.y() };
    QPointF cb = { point_b.x() - point_c.x(), point_b.y() - point_c.y() };

    float dot = (ab.x() * cb.x() + ab.y() * cb.y());   // dot product
    float cross = (ab.x() * cb.y() - ab.y() * cb.x()); // cross product

    float alpha = atan2(cross, dot);

    return (int)floor(alpha * 180. / 3.1415926 + 0.5);
}

void Arrow::paint(QPainter* painter, const QStyleOptionGraphicsItem*,
    QWidget*)
{
    if (myStartItem->collidesWithItem(myEndItem))
        return;

    QPen myPen = pen();
    myPen.setColor(myColor);
    painter->setPen(myPen);
    painter->setBrush(myColor);

    QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    QPolygonF endPolygon = myEndItem->polygon();
    setLine(QLineF(myEndItem->pos(), myStartItem->pos()));

    painter->drawLine(line());
    if (isSelected())
    {
        painter->setPen(QPen(myColor, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0, -8.0);
        painter->drawLine(myLine);
    }
}

void Arrow::setSpinBox(QDoubleSpinBox* spin)
{
    spin_box = spin;
}
