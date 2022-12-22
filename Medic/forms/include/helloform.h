#ifndef HELLOFORM_H
#define HELLOFORM_H

#include <QGroupBox>
#include <QPixmap>
#include <QWidget>

namespace Ui
{
class HelloForm;
}

class HelloForm : public QWidget
{
    Q_OBJECT

public:
    explicit HelloForm(QWidget* parent = nullptr);
    ~HelloForm();
    unsigned int age = 0;

signals:
    void signal();

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::HelloForm* ui;
};

#endif // HELLOFORM_H
