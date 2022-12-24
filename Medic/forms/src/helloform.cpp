#include "helloform.h"
#include "ui_helloform.h"
#include <QGridLayout>

#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QSpacerItem>
#include <QSpinBox>
#include <QTimer>

HelloForm::HelloForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::HelloForm)
{
    ui->setupUi(this);
}

HelloForm::~HelloForm()
{
    delete ui;
}

void HelloForm::on_pushButton_5_clicked()
{
    qApp->exit(0);
}

void HelloForm::on_pushButton_4_clicked()
{
    if (age <= 12)
    {
        QMessageBox::critical(this, "Предупреждение", "Программа для планирования операции данной возрастной группы в настоящий момент не подходит (планируется расширить далее для других возрастных групп)");
    }
    else
    {
        emit signal();
    }
}

void HelloForm::on_spinBox_valueChanged(int arg1)
{
    age = arg1;
}
