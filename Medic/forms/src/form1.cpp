#include "form1.h"
#include "ui_form1.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QString>

Form1::Form1(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Form1)
{
    ui->setupUi(this);
    ui->tabWidget->clear();
    ui->tabWidget->addTab(new QGraphicsView(this), tr("Рентгенограмма 1"));
    ui->tabWidget->addTab(new QGraphicsView(this), tr("Рентгенограмма 2"));
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(20);
    effect->setColor(Qt::white);
    effect->setOffset(QPointF(0, 0));
    ui->label_12->setGraphicsEffect(effect);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_pushButton_5_clicked()
{
    qApp->exit(0);
}

void Form1::on_pushButton_3_clicked()
{
    ui->doubleSpinBox_3->setValue(diametr * distance);
}

void Form1::on_pushButton_4_clicked()
{
    if (diametr * distance < 0.6 || diametr * distance > 1.0)
    {
        QMessageBox::critical(this, "Предупреждение", "Индекс сферичности головки ISh выходит за пределы требуемого диапазона. Применение программы невозможно");
        emit signal(false);
    }
    else
    {
        emit signal(true);
    }
    emit signal2(diametr * distance);
}

void Form1::on_doubleSpinBox_valueChanged(double arg1)
{
    diametr = arg1;
}

void Form1::on_doubleSpinBox_2_valueChanged(double arg1)
{
    distance = arg1;
}
