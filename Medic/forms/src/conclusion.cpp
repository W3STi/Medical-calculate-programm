#include "conclusion.h"
#include "ui_conclusion.h"

conclusion::conclusion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conclusion)
{
    ui->setupUi(this);
}

conclusion::~conclusion()
{
    delete ui;
}
