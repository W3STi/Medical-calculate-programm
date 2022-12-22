#include "form6.h"
#include "ui_form6.h"
#include <QGraphicsDropShadowEffect>

Form6::Form6(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Form6)
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

Form6::~Form6()
{
    delete ui;
}

void Form6::on_pushButton_5_clicked()
{
    qApp->exit(0);
}

void Form6::on_doubleSpinBox_valueChanged(double arg1)
{
    D = arg1;
}

void Form6::on_doubleSpinBox_2_valueChanged(double arg1)
{
    W = arg1;
}

void Form6::on_pushButton_3_clicked()
{
    ui->doubleSpinBox_3->setValue((D / W) * 1000);
    emit signal2((D / W) * 1000);
}

void Form6::on_pushButton_4_clicked()
{
    emit signal();
}
