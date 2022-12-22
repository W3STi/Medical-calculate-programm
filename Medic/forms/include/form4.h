#ifndef FORM4_H
#define FORM4_H

#include <QGraphicsView>
#include <QWidget>

namespace Ui
{
class Form4;
}

class Form4 : public QWidget
{
    Q_OBJECT

public:
    explicit Form4(QWidget* parent = nullptr);
    ~Form4();

    double indSphere;
    double ICAS;
    double ISA;
    double DA;
    double R;

private slots:
    void on_pushButton_5_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

public slots:
    void getParam(double p);

signals:
    void signal();
    void signal2(double pIC, double pIS);

private:
    Ui::Form4* ui;
};

#endif // FORM4_H
