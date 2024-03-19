#ifndef FORM3_H
#define FORM3_H

#include <QGraphicsView>
#include <QWidget>

#include <myscene.h>

namespace Ui
{
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3( QWidget* parent = nullptr );
    ~Form3();

    double angleA;
    double angleB;

signals:
    void signal();
    void signal2( double pA, double pB );

private slots:
    MyScene* getCurrentScene();

    void on_pushButton_5_clicked();

    void on_doubleSpinBox_valueChanged( double arg1 );

    void on_doubleSpinBox_2_valueChanged( double arg1 );

    void on_pushButton_4_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form3* ui;
};

#endif // FORM3_H
