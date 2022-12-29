#ifndef FORM7_H
#define FORM7_H

#include <QGraphicsView>
#include <QWidget>

#include <myscene.h>

namespace Ui
{
class Form7;
}

class Form7 : public QWidget
{
    Q_OBJECT

public:
    explicit Form7( QWidget* parent = nullptr );
    ~Form7();

    double YOB;
    double G;

signals:
    void signal( double p );

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
    Ui::Form7* ui;
};

#endif // FORM7_H
