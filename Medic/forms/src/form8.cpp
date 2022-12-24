#include "form8.h"
#include "ui_form8.h"
#include <QGraphicsDropShadowEffect>

Form8::Form8(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Form8)
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

Form8::~Form8()
{
    delete ui;
}

void Form8::on_pushButton_5_clicked()
{
    qApp->exit(0);
}
