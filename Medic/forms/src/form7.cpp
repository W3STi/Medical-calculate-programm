#include "form7.h"
#include "ui_form7.h"
#include <QGraphicsDropShadowEffect>

Form7::Form7(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Form7)
{
    ui->setupUi(this);
    ui->tabWidget->clear();
    ui->tabWidget->addTab(new QGraphicsView(new MyScene(), this), tr("Рентгенограмма 1"));
    ui->tabWidget->addTab(new QGraphicsView(new MyScene(), this), tr("Рентгенограмма 2"));
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(20);
    effect->setColor(Qt::white);
    effect->setOffset(QPointF(0, 0));
    ui->label_12->setGraphicsEffect(effect);
}

Form7::~Form7()
{
    delete ui;
}

void Form7::on_pushButton_5_clicked()
{
    qApp->exit(0);
}

void Form7::on_doubleSpinBox_valueChanged(double arg1)
{
    G = arg1;
}

void Form7::on_doubleSpinBox_2_valueChanged(double arg1)
{
    YOB = arg1;
}

void Form7::on_pushButton_3_clicked()
{
    ui->doubleSpinBox_3->setValue(YOB + (30.0 - G));
}

void Form7::on_pushButton_4_clicked()
{
    emit signal(ui->doubleSpinBox_3->value());
}

MyScene* Form7::getCurrentScene()
{
    auto widget = ui->tabWidget->currentWidget();
    if (QString(widget->metaObject()->className()) == "QGraphicsView")
    {
        auto graphics_widget = static_cast<QGraphicsView*>(widget);
        auto scene = graphics_widget->scene();
        if (QString(scene->metaObject()->className()) == "MyScene")
        {
            return static_cast<MyScene*>(scene);
        }
    }
    return {};
}

void Form7::on_toolButton_clicked()
{
    getCurrentScene()->SetState(MyScene::Angle);
    getCurrentScene()->setColorArrow(0xf2ff66);
    getCurrentScene()->setSpinBox(ui->doubleSpinBox);
}

void Form7::on_toolButton_2_clicked()
{
    getCurrentScene()->SetState(MyScene::Angle);
    getCurrentScene()->setColorArrow(0xff7a83);
    getCurrentScene()->setSpinBox(ui->doubleSpinBox_2);
}

void Form7::on_pushButton_clicked()
{
    getCurrentScene()->clear();
}
