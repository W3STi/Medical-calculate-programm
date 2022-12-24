#include "form3.h"
#include "ui_form3.h"
#include <QGraphicsDropShadowEffect>

Form3::Form3(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Form3)
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

Form3::~Form3()
{
    delete ui;
}

void Form3::on_pushButton_5_clicked()
{
    qApp->exit(0);
}

void Form3::on_doubleSpinBox_valueChanged(double arg1)
{
    angleA = arg1;
}

void Form3::on_doubleSpinBox_2_valueChanged(double arg1)
{
    angleB = arg1;
}

void Form3::on_pushButton_4_clicked()
{
    emit signal();
    emit signal2(angleA, angleB);
}
