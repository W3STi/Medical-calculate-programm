#ifndef FORM8_H
#define FORM8_H

#include <QWidget>

namespace Ui {
class Form8;
}

class Form8 : public QWidget
{
    Q_OBJECT

public:
    explicit Form8(QWidget *parent = nullptr);
    ~Form8();

private:
    Ui::Form8 *ui;
};

#endif // FORM8_H
