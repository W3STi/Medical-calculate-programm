#ifndef FORM6_H
#define FORM6_H

#include <QWidget>

namespace Ui {
class Form6;
}

class Form6 : public QWidget
{
    Q_OBJECT

public:
    explicit Form6(QWidget *parent = nullptr);
    ~Form6();

private:
    Ui::Form6 *ui;
};

#endif // FORM6_H
