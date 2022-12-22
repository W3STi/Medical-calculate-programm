#ifndef FORM7_H
#define FORM7_H

#include <QGraphicsView>
#include <QWidget>

namespace Ui
{
class Form7;
}

class Form7 : public QWidget
{
    Q_OBJECT

public:
    explicit Form7(QWidget* parent = nullptr);
    ~Form7();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::Form7* ui;
};

#endif // FORM7_H
