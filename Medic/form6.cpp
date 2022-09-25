#include "form6.h"
#include "ui_form6.h"

Form6::Form6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form6)
{
    ui->setupUi(this);
}

Form6::~Form6()
{
    delete ui;
}
