#include "conclusion.h"
#include "ui_conclusion.h"

Conclusion::Conclusion(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Conclusion)
{
    ui->setupUi(this);
}

Conclusion::~Conclusion()
{
    delete ui;
}

void Conclusion::getCon(QString s)
{
    ui->textBrowser->setHtml("Вывод: " + s);
}

void Conclusion::on_pushButton_clicked()
{
    emit signal();
}

void Conclusion::on_pushButton_2_clicked()
{
    qApp->exit(0);
}
