#include "helloform.h"
#include "ui_helloform.h"
#include <QGridLayout>

#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QLayout>
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

    /*ui->img->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->img->setScaledContents(true);

    QPixmap pM(":/styles/background.jpg");
    ui->img->setPixmap(pM.scaled(pM.size()));

    ui->img->setPixmap(pM.scaled(QApplication::desktop()->screenGeometry().width(),
        QApplication::desktop()->screenGeometry().height(), Qt::KeepAspectRatio));*/
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
    if (ui->spinBox->value() <= 12)
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
