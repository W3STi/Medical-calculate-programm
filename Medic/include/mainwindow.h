#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "conclusion.h"
#include "form1.h"
#include "form2.h"
#include "form3.h"
#include "form4.h"
#include "form5.h"
#include "form6.h"
#include "form7.h"
#include "form8.h"
#include "helloform.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    HelloForm* hForm;
    Form1* form1;
    Form2* form2;
    Form3* form3;
    Form4* form4;
    Form5* form5;
    Form6* form6;
    Form7* form7;
    Form8* form8;
    //conclusion* con;

    double indSphere;
    double angleA;
    double angleB;
    double ICAS;
    double ISA;
    double angleC;
    double aK;
    double lN;
    double pN;
    QString conc;

    //QVector<QWidget*> formList;

    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void createForm();

public slots:
    void set1Win();
    void set2Win(bool flag);
    void set3Win(bool flag);
    void set4Win();
    void set5Win();
    void set6Win();
    void setLastWin();
    void checkParams(double p);
    void getIndSphere(double p);
    void getAngleAB(double pA, double pB);
    void getICASandISA(double pIC, double pIS);
    void getAngleC(double p);
    void getAK(double p);
    void getlN(double p);

signals:
    void signal(double p);

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
