#pragma once

#include "../dateService/dateHandler.h"
#include <QtWidgets>

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow();
    QString rootDir;

private:
    QFile file;

    QTableView *table;
    QStandardItemModel *standartModel; // model
    QModelIndex indexModel; // index

    QPushButton *openBtn;
    QPushButton *previousDayBtn; // prevDayBtn
    QPushButton *leapYearOrNotBtn; // leapOrNotBtn
    QPushButton *weekNumBtn; // weekNumberBtn
    QPushButton *daysToBirthdayBtn; // cntDayToBDBtn
    QPushButton *insertDateBtn; // addThisDateBtn
    QPushButton *modifyDateBtn; // cngThisDateBtn
    QPushButton *closeBtn;

    QLabel *dateSelectionLabel; // selectDateLbl
    QLabel *findDateLabel; // selectDateToFindLbl
    QLabel *replaceDateLabel; // selectDateToReplaceLbl

    QDateEdit *birthdayCalendar; // calendarToSelectBD
    QDateEdit *calendarDateOperation; // calendarAddOrFindDate
    QDateEdit *calendarSwapToDate; // calendarReplaceToDate

    int numberOfRows{0}; // nmbOfRow
    int lastFunction = 1; // lastFun

    Date *dates = new Date;
    QString filePath; // pathToFile

    void loadDataFromFileToTable(); //  putDataFromFileToTable
    void fillColumn(int num); // fillClm
    void displayBtn(); //showBtn
    void hideBtn();

    const int COLUMN_DATE_TODAY = 0;
    const int COLUMN_DATE_NEXT = 1;
    const int COLUMN_DELTA = 2;
    const int COLUMN_FUNCTION = 3;

protected slots:
    void openFileWithDolphin(); // openDolphin
    void previousDayFun(); // funPrevDay
    void isLeapYearFunc(); // funIsLeapYear
    void weekNumberFunc(); // funWeekNumber
    void birthdayDayFunc(); // funBirthDay
    void replaceDateFunc(); // funReplaceDate
    void addDateFunc(); // funAddDate

    void onBtn_close_clicked()
    {
        file.close();
        close();
    };
};
