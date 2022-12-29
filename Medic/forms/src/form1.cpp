#include "form1.h"
#include "ui_form1.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QString>

Form1::Form1( QWidget* parent )
    : QWidget( parent )
    , ui( new Ui::Form1 )
{
    ui->setupUi( this );
    ui->tabWidget->clear();
    ui->tabWidget->addTab( new QGraphicsView( new MyScene(), this ), tr( "Рентгенограмма 1" ) );
    ui->tabWidget->addTab( new QGraphicsView( new MyScene(), this ), tr( "Рентгенограмма 2" ) );
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect( this );
    effect->setBlurRadius( 20 );
    effect->setColor( Qt::white );
    effect->setOffset( QPointF( 0, 0 ) );
    ui->label_12->setGraphicsEffect( effect );
}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_pushButton_5_clicked()
{
    qApp->exit( 0 );
}

void Form1::on_pushButton_3_clicked()
{
    ui->doubleSpinBox_3->setValue( diametr / distance * 0.5 );
}

void Form1::on_pushButton_4_clicked()
{
    /*if (ui->doubleSpinBox_3->value() < 0.6 || ui->doubleSpinBox_3->value() > 1.0)
    {
        QMessageBox::critical(this, "Предупреждение", "Индекс сферичности головки ISh выходит за пределы требуемого диапазона. Применение программы невозможно");
        emit signal(false);
    }
    else
    {*/
    emit signal( true );
    //}
    emit signal2( ui->doubleSpinBox_3->value(), diametr );
}

void Form1::on_doubleSpinBox_valueChanged( double arg1 )
{
    diametr = arg1;
}

void Form1::on_doubleSpinBox_2_valueChanged( double arg1 )
{
    distance = arg1;
}

MyScene* Form1::getCurrentScene()
{
    auto widget = ui->tabWidget->currentWidget();
    if ( QString( widget->metaObject()->className() ) == "QGraphicsView" )
    {
        auto graphics_widget = static_cast<QGraphicsView*>( widget );
        auto scene = graphics_widget->scene();
        if ( QString( scene->metaObject()->className() ) == "MyScene" )
        {
            return static_cast<MyScene*>( scene );
        }
    }
    qDebug() << "Form1 Scene nullptr";
    return {};
}

void Form1::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName( this, "Choose Config", QDir::currentPath(), tr( "Png (*.png);;Jpg (*.jpg,*.jpeg);;All files (*)" ) );
    QPixmap pixmap( path );
    getCurrentScene()->SetPixmap( pixmap );
}

void Form1::on_toolButton_clicked()
{
    getCurrentScene()->SetState( MyScene::Circle );
    getCurrentScene()->setColorArrow( 0xf2ff66 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}

void Form1::on_toolButton_2_clicked()
{
    getCurrentScene()->SetState( MyScene::Line );
    getCurrentScene()->setColorArrow( 0xff7a83 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox_2 );
}

void Form1::on_pushButton_6_clicked()
{
    getCurrentScene()->clear();
}
