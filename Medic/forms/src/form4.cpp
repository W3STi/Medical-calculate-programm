#include "form4.h"
#include "form1.h"
#include "ui_form4.h"
#include <QGraphicsDropShadowEffect>

Form4::Form4( QWidget* parent )
    : QWidget( parent )
    , ui( new Ui::Form4 )
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

Form4::~Form4()
{
    delete ui;
}

void Form4::on_pushButton_5_clicked()
{
    qApp->exit( 0 );
}

void Form4::on_doubleSpinBox_valueChanged( double arg1 )
{
    DA = arg1;
}

void Form4::on_doubleSpinBox_2_valueChanged( double arg1 )
{
    R = arg1;
}

void Form4::on_pushButton_3_clicked()
{
    ISA = DA / ( 0.5 * R );
    ui->doubleSpinBox_3->setValue( ISA );
    ICAS = ISA / indSphere;
    ui->doubleSpinBox_4->setValue( ICAS );
    emit signal2( ICAS, ISA );
}

void Form4::on_pushButton_4_clicked()
{
    emit signal();
}

void Form4::getParam( double p )
{
    indSphere = p;
}

MyScene* Form4::getCurrentScene()
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

void Form4::on_toolButton_clicked()
{
    getCurrentScene()->SetState( MyScene::Circle );
    getCurrentScene()->setColorArrow( 0xf2ff66 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}

void Form4::on_toolButton_2_clicked()
{
    getCurrentScene()->SetState( MyScene::Line );
    getCurrentScene()->setColorArrow( 0xff7a83 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox_2 );
}

void Form4::on_pushButton_clicked()
{
    getCurrentScene()->clear();
}
