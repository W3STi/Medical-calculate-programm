#ifndef FORM5_H
#define FORM5_H

#include <QGraphicsView>
#include <QWidget>

namespace Ui
{
class Form5;
}

class Form5 : public QWidget
{
    Q_OBJECT

public:
    explicit Form5(QWidget* parent = nullptr);
    ~Form5();

signals:
    void signal();
    void signal2(double p);

private slots:
    void on_pushButton_5_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_pushButton_4_clicked();

private:
    Ui::Form5* ui;
};

#endif // FORM5_H
