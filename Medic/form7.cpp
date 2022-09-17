#include "form7.h"
#include "ui_form7.h"

Form7::Form7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form7)
{
    ui->setupUi(this);
}

Form7::~Form7()
{
    delete ui;
}
