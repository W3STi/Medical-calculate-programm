#ifndef MYSCENE_H
#define MYSCENE_H

#include "mygraphicsitem.h"
#include <QDoubleSpinBox>
#include <QGraphicsScene>
#include <QLineEdit>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum State
    {
        None = 0,
        Line = 1,
        LineStart = 2,
        Angle = 3,
        AngleStart = 4,
        AngleMiddle = 5
    };

    explicit MyScene( QObject* parent = 0 );
    void SetPixmap( const QPixmap );
    void SetRatio( const double );
    void SetState( const State );
    void setColorArrow( QColor color ) { color_arrow = color; }
    void setSpinBox( QDoubleSpinBox* );

    QPixmap GetPixmap();
    double GetRatio();
    State GetState();
    MyGraphicsItem* CreatePoint();
    Arrow* CreateArrow( MyGraphicsItem*, MyGraphicsItem* );

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent* mouseEvent ) override;
    void mouseMoveEvent( QGraphicsSceneMouseEvent* mouseEvent ) override;
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* mouseEvent ) override;
    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent* mouseEvent ) override;

private:
    class Measurement
    {
    public:
        enum Type
        {
            Line,
            Angle,
            Cycle
        };

        Type type;
        QVector<MyGraphicsItem> points;
        QLineEdit* lineedit;
    };

    QGraphicsLineItem* line;
    MyGraphicsItem* last_item;
    QPixmap pixmap;
    double ratio = 1.0; ///< mm / pix
    State state = None;
    QColor color_arrow = Qt::red;
    QDoubleSpinBox* spin_box = nullptr;
};

#endif // MYSCENE_H
