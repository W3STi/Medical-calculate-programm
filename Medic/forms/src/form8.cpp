#include "form8.h"
#include "ui_form8.h"

Form8::Form8(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form8)
{
    ui->setupUi(this);
}

Form8::~Form8()
{
    delete ui;
}
