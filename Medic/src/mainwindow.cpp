#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    createForm();

    connect(hForm, &HelloForm::signal, this, &MainWindow::set1Win);
    connect(form1, &Form1::signal, this, &MainWindow::set2Win);
    connect(form2, &Form2::signal, this, &MainWindow::set3Win);
    connect(form3, &Form3::signal, this, &MainWindow::set4Win);
    connect(form4, &Form4::signal, this, &MainWindow::set5Win);
    connect(form5, &Form5::signal, this, &MainWindow::set6Win);

    connect(form6, &Form6::signal, this, &MainWindow::checkParams);

    connect(form1, &Form1::signal2, this, &MainWindow::getIndSphere);
    connect(form3, &Form3::signal2, this, &MainWindow::getAngleAB);
    connect(this, &MainWindow::signal, form4, &Form4::getParam);
    connect(form4, &Form4::signal2, this, &MainWindow::getICASandISA);
    connect(form5, &Form5::signal2, this, &MainWindow::getAngleC);
    connect(form6, &Form6::signal2, this, &MainWindow::getAK);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set1Win()
{
    hForm->hide();
    form1->show();
    setCentralWidget(form1);
}

void MainWindow::set2Win(bool flag)
{
    form1->hide();

    if (flag)
    {
        form2->show();
        setCentralWidget(form2);
    }
    else
    {
        hForm->show();
        setCentralWidget(hForm);
    }
}

void MainWindow::set3Win(bool flag)
{
    form2->hide();

    if (flag)
    {
        form3->show();
        setCentralWidget(form3);
    }
    else
    {
        hForm->show();
        setCentralWidget(hForm);
    }
}

void MainWindow::set4Win()
{
    form3->hide();
    form4->show();
    setCentralWidget(form4);
}

void MainWindow::set5Win()
{
    form4->hide();
    form5->show();
    setCentralWidget(form5);
}

void MainWindow::set6Win()
{
    form5->hide();
    form6->show();
    setCentralWidget(form6);
}

void MainWindow::checkParams()
{
    if (ICAS > 1.7)
    {
        if (angleA > 35.0)
        {
            if (angleC > 20.0)
            {
            }
            else if (angleC >= 10.0 && angleC <= 20.0)
            {
            }
            else if (angleC < 10.0)
            {
            }
        }
        else
        {
            if (angleC > 20.0)
            {
            }
            else if (angleC >= 10.0 && angleC <= 20.0)
            {
            }
            else if (angleC < 10.0)
            {
            }
        }
    }
    else if (ICAS >= 1.0 && ICAS <= 1.7)
    {
        if (angleB > 15.0)
        {
            if (angleC > 20.0)
            {
            }
            else if (angleC >= 10.0 && angleC <= 20.0)
            {
            }
            else if (angleC < 10.0)
            {
            }
        }
        else
        {
        }
    }
    else if (ICAS >= 0.88 && ICAS <= 0.99)
    {
        if (angleC > 20.0)
        {
        }
        else if (angleC >= 10.0 && angleC <= 20.0)
        {
        }
        else if (angleC < 10.0)
        {
        }
    }
    else
    {
    }
}

void MainWindow::getIndSphere(double p)
{
    indSphere = p;
    emit signal(indSphere);
}

void MainWindow::getAngleAB(double pA, double pB)
{
    angleA = pA;
    angleB = pB;
}

void MainWindow::getICASandISA(double pIC, double pIS)
{
    ICAS = pIC;
    ISA = pIS;
}

void MainWindow::getAngleC(double p)
{
    angleC = p;
}

void MainWindow::getAK(double p)
{
    aK = p;
}

void MainWindow::createForm()
{
    MainWindow::hForm = new HelloForm(this);
    MainWindow::form1 = new Form1(this);
    form1->hide();
    MainWindow::form2 = new Form2(this);
    form2->hide();
    MainWindow::form3 = new Form3(this);
    form3->hide();
    MainWindow::form4 = new Form4(this);
    form4->hide();
    MainWindow::form5 = new Form5(this);
    form5->hide();
    MainWindow::form6 = new Form6(this);
    form6->hide();
    MainWindow::form7 = new Form7(this);
    form7->hide();
    MainWindow::form8 = new Form8(this);
    form8->hide();
}
