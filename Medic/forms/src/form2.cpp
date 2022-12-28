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
    ui->tabWidget->addTab( new QGraphicsView( this ), tr( "Рентгенограмма 1" ) );
    ui->tabWidget->addTab( new QGraphicsView( this ), tr( "Рентгенограмма 2" ) );
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
    getCurrentScene()->SetState( MyScene::Circle );
    getCurrentScene()->setColorArrow( 0xff7a83 );
    getCurrentScene()->setSpinBox( ui->doubleSpinBox );
}
