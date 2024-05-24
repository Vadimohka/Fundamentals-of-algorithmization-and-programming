#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QElapsedTimer>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStandardPaths>
#include <QDebug>
#include <QTime>
#include <QDate>
#include <QScreen>
#include <QMessageBox>
#include <vector>
#include <counter.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonMove_clicked();
    void on_comboBoxAmmount_currentIndexChanged(int index);
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_pushButtonMinus_clicked();
    void on_pushButtonPlus_clicked();
    void TimeChanged();
    void on_pushButtonTotal_clicked();
    void on_comboBoxCurrency_currentIndexChanged(int index);
    void on_comboBoxPacksPerDay_currentIndexChanged(int index);

private:

    Ui::MainWindow *ui;

    QScreen* screen;
    long long ScreenWidth;
    long long ScreenHeigth;

    bool moveWasPressed = false;
    long long SigarettAmmount = 5;
    long double SigarettCost = 1.0;
    long double PricePerPack = 0;
    QVector < long long > AmmounDay;
    long long CigsCurrentDay = 0;
    long long PositivityIndex;
    QElapsedTimer timer;
    long long timerValue = 0;

    short int secundes = 0;
    short int minutes = 0;
    short int hours = 0;
    long int days = 0;
    QTimer Timer;

    QTime LastSigTime;
    QDate LastSigDate;

    int* t;

private:

    long long CalculateIndex();
    void MakeVector();
    void WriteVector();
    void AddNewDay();
    void MakeTime();
    void WriteTime();
    void MakeSettings();
    void WriteSettings();
    void SetBack();
    void setMotivationText();
    long double TotalPrice();
    long long QSToLL( QString number );
    long long GenerateRandomNum();
    long long GenerateRandomNumMod( long long mod );
    QString XorEncrypt( QString str );
    void bitseqsort( int* l , int* r , bool inv );
    void makebitonic( int* l , int* r );
    void bitonicsort( int* l , int* r );
    int* max_element( int* a , int* b );
    int BinSearch( int val , int* a , int l , int r );
    void build (int a[], int v, int tl, int tr);
    int sum (int v, int tl, int tr, int l, int r);
    void update (int v, int tl, int tr, int pos, int new_val);

};
#endif // MAINWINDOW_H
