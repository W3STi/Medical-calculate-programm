#include "form3.h"
#include "ui_form3.h"
#include <QGraphicsDropShadowEffect>

Form3::Form3( QWidget* parent )
    : QWidget( parent )
    , ui( new Ui::Form3 )
{
    ui->setupUi( this );
    ui->tabWidget->clear();
    ui->tabWidget->addTab( new QGraphicsView( this ), tr( "Рентгенограмма 1" ) );
    ui->tabWidget->addTab( new QGraphicsView( this ), tr( "Рентгенограмма 2" ) );
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect( this );
    effect->setBlurRadius( 20 );
    effect->setColor( Qt::white );
    effect->setOffset( QPointF( 0, 0 ) );
    ui->label_12->setGraphicsEffect( effect );
}

Form3::~Form3()
{
    delete ui;
}

void Form3::on_pushButton_5_clicked()
{
    qApp->exit( 0 );
}

void Form3::on_doubleSpinBox_valueChanged( double arg1 )
{
    angleA = arg1;
}

void Form3::on_doubleSpinBox_2_valueChanged( double arg1 )
{
    angleB = arg1;
}

void Form3::on_pushButton_4_clicked()
{
    emit signal();
    emit signal2( angleA, angleB );
}

MyScene* Form3::getCurrentScene()
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

void Form3::on_toolButton_clicked()
{
    getCurrentScene()->SetState( MyScene::Angle );
    getCurrentScene()->setColorArrow( 0xf2ff66 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}

void Form3::on_toolButton_2_clicked()
{
    getCurrentScene()->SetState( MyScene::Angle );
    getCurrentScene()->setColorArrow( 0xff7a83 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox_2 );
}
