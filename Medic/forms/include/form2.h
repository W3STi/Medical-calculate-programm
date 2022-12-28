#ifndef FORM2_H
#define FORM2_H

#include <QGraphicsView>
#include <QWidget>

#include <myscene.h>

namespace Ui
{
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2( QWidget* parent = nullptr );
    ~Form2();

    double indOkano;
    double rA;
    double rB;

signals:
    void signal( bool flag );

private slots:
    MyScene* getCurrentScene();

    void on_pushButton_5_clicked();

    void on_doubleSpinBox_valueChanged( double arg1 );

    void on_doubleSpinBox_2_valueChanged( double arg1 );

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form2* ui;
};

#endif // FORM2_H
