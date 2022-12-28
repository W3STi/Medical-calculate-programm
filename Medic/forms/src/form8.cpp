#include "form8.h"
#include "ui_form8.h"
#include <QGraphicsDropShadowEffect>

Form8::Form8( QWidget* parent )
    : QWidget( parent )
    , ui( new Ui::Form8 )
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

Form8::~Form8()
{
    delete ui;
}

void Form8::on_pushButton_5_clicked()
{
    qApp->exit( 0 );
}

void Form8::on_doubleSpinBox_valueChanged( double arg1 )
{
    D = arg1;
}

void Form8::on_pushButton_3_clicked()
{
    ui->doubleSpinBox_2->setValue( 25.0 - D );
}

void Form8::on_pushButton_4_clicked()
{
    emit signal( 25.0 - D );
}

MyScene* Form8::getCurrentScene()
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
    return {};
}

void Form8::on_toolButton_clicked()
{
    getCurrentScene()->SetState( MyScene::Angle );
    getCurrentScene()->setColorArrow( 0xf2ff66 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}

void Form8::on_pushButton_clicked()
{
    getCurrentScene()->clear();
}
