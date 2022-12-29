#ifndef FORM6_H
#define FORM6_H

#include <QGraphicsView>
#include <QWidget>

#include <myscene.h>

namespace Ui
{
class Form6;
}

class Form6 : public QWidget
{
    Q_OBJECT

public:
    explicit Form6( QWidget* parent = nullptr );
    ~Form6();

    double D;
    double W;

signals:
    void signal();
    void signal2( double p );

private slots:
    MyScene* getCurrentScene();

    void on_pushButton_5_clicked();

    void on_doubleSpinBox_valueChanged( double arg1 );

    void on_doubleSpinBox_2_valueChanged( double arg1 );

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form6* ui;
};

#endif // FORM6_H
