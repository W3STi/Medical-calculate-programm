#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "conclusion.h"
#include "form1.h"
#include "form2.h"
#include "form3.h"
#include "form4.h"
#include "form5.h"
#include "form6.h"
#include "form7.h"
#include "form8.h"
#include "helloform.h"

#include <QGridLayout>
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
    Conclusion* con;

    double indSphere = 0.0;
    double Dh = 0.0;
    double angleA = 0.0;
    double angleB = 0.0;
    double ICAS = 0.0;
    double ISA = 0.0;
    double angleC = 0.0;
    double aK = 0.0;
    double lN = 0.0;
    double pN = 0.0;
    QString conc = "";

    void setStandValues();

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
    void getIndSphere(double p, double p2);
    void getAngleAB(double pA, double pB);
    void getICASandISA(double pIC, double pIS);
    void getAngleC(double p);
    void getAK(double p);
    void getlN(double p);

signals:
    void signal(double p);
    void signal2(QString s);

private:
    Ui::MainWindow* ui;
    QGridLayout* gridLayout;
};
#endif // MAINWINDOW_H
