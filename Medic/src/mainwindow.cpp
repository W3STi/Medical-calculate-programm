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
    connect(form6, &Form6::signal, this, &MainWindow::setLastWin);

    connect(form1, &Form1::signal2, this, &MainWindow::getIndSphere);
    connect(form3, &Form3::signal2, this, &MainWindow::getAngleAB);
    connect(this, &MainWindow::signal, form4, &Form4::getParam);
    connect(form4, &Form4::signal2, this, &MainWindow::getICASandISA);
    connect(form5, &Form5::signal2, this, &MainWindow::getAngleC);
    connect(form6, &Form6::signal2, this, &MainWindow::getAK);
    connect(form7, &Form7::signal, this, &MainWindow::getlN);

    connect(form8, &Form8::signal, this, &MainWindow::checkParams);
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

void MainWindow::setLastWin()
{
    form6->hide();

    if ((ICAS > 1.7 && angleA <= 35) || (ICAS >= 1.0 && ICAS <= 1.7))
    {
        form7->show();
        setCentralWidget(form7);
    }
    else
    {
        form8->show();
        setCentralWidget(form8);
    }
}

void MainWindow::checkParams(double p)
{
    pN = p;

    if (ICAS > 1.7)
    {
        if (angleA > 35.0)
        {
            form8->show();
            setCentralWidget(form8);

            if (angleC > 20.0)
            {
                conc = "Ацетабулярный коэффициент≥150.\n За счет остеотомии таза осуществляется наклон в сагиттальной и горизонтальной плоскости\n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n Горизонтальная плоскость.\n Наружная ротация ацетабулярного фрагмента: В - 20°= " + QString::number(angleC - 20.0) + "\n За счет неполной ПАО осуществляется латеральный наклон\n Степень латерального наклона соответствует углу наклона опорной поверхности Б = " + QString::number(angleB);
            }
            else if (angleC >= 10.0 && angleC <= 20.0)
            {
                conc = "Ацетабулярный коэффициент≥150.\n Степень латерального наклона соответствует углу наклона опорной поверхности Б = " + QString::number(angleB) + "\n Степень переднего наклона фрагмента равна: " + QString::number(pN);
            }
            else if (angleC < 10.0)
            {
                conc = "Ацетабулярный коэффициент≥150.\n За счет остеотомии таза осуществляется наклон в сагиттальной и горизонтальной плоскости\n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n Горизонтальная плоскость.\n Наружная ротация ацетабулярного фрагмента: В - 20°= " + QString::number(15.0 - angleC) + "\n За счет неполной ПАО осуществляется латеральный наклон\n Степень латерального наклона соответствует углу наклона опорной поверхности Б = " + QString::number(angleB);
            }
        }
        else
        {
            form7->show();
            setCentralWidget(form7);

            form8->show();
            setCentralWidget(form8);

            if (angleC > 20.0)
            {
                conc = "За счет остеотомии таза осуществляется наклон во фронтальной, сагиттальной и горизонтальной плоскости\n Во фронтальной плоскости (латеральный наклон)\n Степень латерального наклона ацетабулярного фрагмента равна: " + QString::number(lN) + "\n В сагиттальной плоскости (передний наклон)\n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n Горизонтальная плоскость. Наружная ротация ацетабулярного фрагмента: В - 20° = " + QString::number(angleC - 20.0) + "За счет неполной ПАО осуществляется дополнительный латеральный наклон\n Степень дополнительного латерального наклона:  угол  наклона опорной поверхности Б – \n Угол наклона впадины после остеотомии таза-? = ";
            }
            else if (angleC >= 10.0 && angleC <= 20.0)
            {
                conc = "За счет остеотомии таза осуществляется наклон во фронтальной и сагиттальной плоскости\n Во фронтальной плоскости (латеральный наклон)\n Степень латерального наклона ацетабулярного фрагмента равна: " + QString::number(lN) + "\n В сагиттальной плоскости (передний наклон)\n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n За счет неполной ПАО осуществляется дополнительный латеральный наклон\n Степень дополнительного латерального наклона:  угол  наклона опорной поверхности Б – \n Угол наклона впадины после остеотомии таза-? = ";
            }
            else if (angleC < 10.0)
            {
                conc = "За счет остеотомии таза осуществляется наклон во фронтальной, сагиттальной и горизонтальной плоскости\n Во фронтальной плоскости (латеральный наклон)\n Степень латерального наклона ацетабулярного фрагмента равна: " + QString::number(lN) + "\n В сагиттальной плоскости (передний наклон)\n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n Горизонтальная плоскость. Наружная ротация ацетабулярного фрагмента: В - 20° = " + QString::number(15.0 - angleC) + "За счет неполной ПАО осуществляется дополнительный латеральный наклон\n Степень дополнительного латерального наклона:  угол  наклона опорной поверхности Б – \n Угол наклона впадины после остеотомии таза-? = ";
            }
        }
    }
    else if (ICAS >= 1.0 && ICAS <= 1.7)
    {
        if (angleB > 15.0)
        {
            form7->show();
            setCentralWidget(form7);

            form8->show();
            setCentralWidget(form8);

            if (angleC > 20.0)
            {
                conc = "Ацетабулярный коэффициент≥150.\n Степень латерального наклона ацетабулярного фрагмента равна: " + QString::number(lN) + "\n Степень переднего наклона равна: " + QString::number(pN) + "\n Наружная ротация ацетабулярного фрагмента:  равна" + QString::number(angleC - 20.0);
            }
            else if (angleC >= 10.0 && angleC <= 20.0)
            {
                conc = "Ацетабулярный коэффициент≥150.\n Степень латерального наклона ацетабулярного фрагмента равна: " + QString::number(lN) + "\n Степень переднего наклона равна: " + QString::number(pN);
            }
            else if (angleC < 10.0)
            {
                conc = "Ацетабулярный коэффициент≥150.\n Степень латерального наклона ацетабулярного фрагмента равна: " + QString::number(lN) + "\n Степень переднего наклона равна: " + QString::number(pN) + "\n Наружная ротация ацетабулярного фрагмента:  равна" + QString::number(15.0 - angleC);
            }
        }
        else
        {
            QMessageBox::critical(this, "Предупреждение", "Угол наклона опорной поверхности Б менее 15 градусов. Применение программы невозможно");
            qApp->exit(0);
        }
    }
    else if (ICAS >= 0.88 && ICAS <= 0.99)
    {
        form8->show();
        setCentralWidget(form8);

        if (angleC > 20.0)
        {
            conc = "За счет остеотомии таза осуществляется наклон во фронтальной, сагиттальной и горизонтальной плоскости.\n Во фронтальной плоскости (латеральный наклон):\n Степень латерального наклона ацетабулярного фрагмента соответствует величине угла наклона опорной поверхности Б = " + QString::number(angleB) + "\n В сагиттальной плоскости (передний наклон): \n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n  Горизонтальная плоскость.\n Наружная ротация ацетабулярного фрагмента:  В - 20° = " + QString::number(angleC - 20.0) + "\nЗа счет ацетабулопластики осуществляется дополнительное  латеральное покрытие наклон.\n Величина трансплантата:  ";
        }
        else if (angleC >= 10.0 && angleC <= 20.0)
        {
            conc = "За счет остеотомии таза осуществляется наклон во фронтальной и сагиттальной плоскости.\n Во фронтальной плоскости (латеральный наклон):\n Степень латерального наклона ацетабулярного фрагмента соответствует величине угла наклона опорной поверхности Б = " + QString::number(angleB) + "\n В сагиттальной плоскости (передний наклон): \n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n За счет ацетабулопластики осуществляется дополнительное латеральное покрытие наклон.\n Величина трансплантата: ";
        }
        else if (angleC < 10.0)
        {
            conc = "За счет остеотомии таза осуществляется наклон во фронтальной, сагиттальной и горизонтальной плоскости.\n Во фронтальной плоскости (латеральный наклон):\n Степень латерального наклона ацетабулярного фрагмента соответствует величине угла наклона опорной поверхности Б = " + QString::number(angleB) + "\n В сагиттальной плоскости (передний наклон): \n Степень переднего наклона фрагмента равна: " + QString::number(pN) + "\n  Горизонтальная плоскость.\n Наружная ротация ацетабулярного фрагмента:  В - 20° = " + QString::number(15.0 - angleC) + "\nЗа счет ацетабулопластики осуществляется дополнительное  латеральное покрытие наклон.\n Величина трансплантата:  ";
        }
    }
    else
    {
        QMessageBox::critical(this, "Предупреждение", "Индекс конгруэнтности ICAS менее 0.8. Применение программы невозможно");
        qApp->exit(0);
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

void MainWindow::getlN(double p)
{
    lN = p;

    form7->hide();
    form8->show();
    setCentralWidget(form8);
}

void MainWindow::createForm()
{
    MainWindow::hForm = new HelloForm(ui->centralwidget);
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
    //MainWindow::con = new conclusion(this);
    //con->hide();
}
