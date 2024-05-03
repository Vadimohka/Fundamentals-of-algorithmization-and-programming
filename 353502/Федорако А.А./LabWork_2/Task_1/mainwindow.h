#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "date.h"
#include <QMainWindow>
#include "fileprocessing.h"
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

     explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void on_addBirthdayDay_clicked();
    void on_ButtonAddDate_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
private:
    Date* date = new Date;
    void showDateTime();
    bool isLineCorrect(QString line);
    void setAllTableWidget();
    void showErrorEvent(QString line);
    void showInformationEvent(QString line);
    FileProcessing* file = new FileProcessing();
    void addNewDate(QString strNewDate);
    bool isFileOpen = false;
    QString filePath = "";
    std::vector<Date> arrDate;
    Ui::MainWindow *ui;
    Date dateBirthday;
    QString strDateBirthday = "";
    bool checkIsCorrectFile();
    int const TimePeriodToChange = 100;
    int const NumberCoordinateOfSpaceFirst = 2;
    int const NumberCoordinateOfSpaceSecond = 5;
    int const NumberCoordinateOfYear = 6;
    int const CorrectSizeLine = 10;
    int const NumberFirstColumb = 0;
    int const NumberSecondColumb = 1;
    int const NumberThirdColumb = 2;
    int const NumberFourColumb = 3;
    int const NumberFiveColumb = 4;
    int const NumberSixColumb = 5;
    int const NumberSevenColumb = 6;
    int const NumberEightColumb = 7;
    int const NumberRows = 8;
    int const NumberMaxDaysInMonth = 31;
    int const NumberMaxMonthInYear = 12;
};
#endif // MAINWINDOW_H
