#ifndef FORM1_H
#define FORM1_H

#include <QDoubleSpinBox>
#include <QGraphicsView>
#include <QWidget>

#include <myscene.h>

namespace Ui
{
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget* parent = nullptr);
    ~Form1();

    double diametr;
    double distance;

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_pushButton_clicked();

    MyScene* getCurrentScene();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

signals:
    void signal(bool flag);
    void signal2(double p, double p2);

private:
    Ui::Form1* ui;
};

#endif // FORM1_H
