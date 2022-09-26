#ifndef FORM5_H
#define FORM5_H

#include <QWidget>

namespace Ui {
class Form5;
}

class Form5 : public QWidget
{
    Q_OBJECT

public:
    explicit Form5(QWidget *parent = nullptr);
    ~Form5();

private:
    Ui::Form5 *ui;
};

#endif // FORM5_H
