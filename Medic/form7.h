#ifndef FORM7_H
#define FORM7_H

#include <QWidget>

namespace Ui {
class Form7;
}

class Form7 : public QWidget
{
    Q_OBJECT

public:
    explicit Form7(QWidget *parent = nullptr);
    ~Form7();

private:
    Ui::Form7 *ui;
};

#endif // FORM7_H
