#include "form5.h"
#include "ui_form5.h"
#include <QGraphicsDropShadowEffect>

Form5::Form5(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Form5)
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

Form5::~Form5()
{
    delete ui;
}

void Form5::on_pushButton_5_clicked()
{
    qApp->exit(0);
}

void Form5::on_doubleSpinBox_valueChanged(double arg1)
{
    emit signal2(arg1);
}

void Form5::on_pushButton_4_clicked()
{
    emit signal();
}
