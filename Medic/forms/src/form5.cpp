#include "form5.h"
#include "ui_form5.h"
#include <QGraphicsDropShadowEffect>

Form5::Form5( QWidget* parent )
    : QWidget( parent )
    , ui( new Ui::Form5 )
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

Form5::~Form5()
{
    delete ui;
}

void Form5::on_pushButton_5_clicked()
{
    qApp->exit( 0 );
}

void Form5::on_doubleSpinBox_valueChanged( double arg1 )
{
    emit signal2( arg1 );
}

void Form5::on_pushButton_4_clicked()
{
    emit signal();
}

MyScene* Form5::getCurrentScene()
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

void Form5::on_toolButton_clicked()
{
    getCurrentScene()->SetState( MyScene::Angle );
    getCurrentScene()->setColorArrow( 0xf2ff66 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}
