#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    form1.show();
}

void MainWindow::on_pushButton_2_clicked()
{
    form2.show();
}

void MainWindow::on_pushButton_3_clicked()
{
    form3.show();
}

void MainWindow::on_pushButton_4_clicked()
{
    form4.show();
}

void MainWindow::on_pushButton_5_clicked()
{
    form5.show();
}

void MainWindow::on_pushButton_6_clicked()
{
    form6.show();
}

void MainWindow::on_pushButton_7_clicked()
{
    form7.show();
}

void MainWindow::on_pushButton_8_clicked()
{
    form8.show();
}

