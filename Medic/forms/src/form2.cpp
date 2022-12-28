#include "form2.h"
#include "ui_form2.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

Form2::Form2( QWidget* parent )
    : QWidget( parent )
    , ui( new Ui::Form2 )
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

Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_5_clicked()
{
    qApp->exit( 0 );
}

void Form2::on_doubleSpinBox_valueChanged( double arg1 )
{
    rA = arg1;
}

void Form2::on_doubleSpinBox_2_valueChanged( double arg1 )
{
    rB = arg1;
}

void Form2::on_pushButton_3_clicked()
{
    indOkano = ( rA * rB ) / 100;
    ui->doubleSpinBox_3->setValue( indOkano );
}

MyScene* Form2::getCurrentScene()
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

void Form2::on_pushButton_4_clicked()
{
    if ( indOkano < 0.43 || indOkano > 0.58 )
    {
        QMessageBox::critical( this, "Предупреждение", "Индекс Окано выходит за пределы требуемого диапазона. Применение программы невозможно" );
        emit signal( false );
    }
    else
    {
        emit signal( true );
    }
}

void Form2::on_toolButton_2_clicked()
{
    getCurrentScene()->SetState( MyScene::Line );
    getCurrentScene()->setColorArrow( 0xff7a83 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox_2 );
}

void Form2::on_toolButton_clicked()
{
    getCurrentScene()->SetState( MyScene::Line );
    getCurrentScene()->setColorArrow( 0xf2ff66 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}
