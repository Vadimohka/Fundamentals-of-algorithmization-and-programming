#ifndef LAB1T1_MAINWINDOW_H
#define LAB1T1_MAINWINDOW_H

#include "date.h"

#include <QtWidgets>

class mainWindow : public QWidget {
    Q_OBJECT
public:
    mainWindow();

    QString projDir;

private:

    QFile file;

    QTableView *table;
    QStandardItemModel *model;
    QModelIndex index;

    QPushButton *openBtn;
    QPushButton *prevDayBtn;
    QPushButton *leapOrNotBtn;
    QPushButton *weekNumberBtn;
    QLabel *selectDateLbl;
    QLabel *selectDateToFindLbl;
    QLabel *selectDateToReplaceLbl;
    QDateEdit *calendarToSelectBD;
    QPushButton *cntDayToBDBtn;
    QPushButton *addThisDateBtn;
    QPushButton *cngThisDateBtn;
    QDateEdit *calendarAddOrFindDate;
    QDateEdit *calendarReplaceToDate;
    QPushButton *closeBtn;

    int nmbOfRow{0};
    int lastFun = 1;

    workWithDate *dates = new workWithDate;

    QString pathToFile;

    void putDataFromFileToTable();

    void feelClm(int nmb);

    void showBtn();
    void hideBtn();


    const int COLUMN_CURRENT_DATE = 0;
    const int COLUMN_NEXT_DATE = 1;
    const int COLUMN_DIFFERENCE = 2;
    const int COLUMN_FUN = 3;

protected slots:

    void openDolphin();

    void funPrevDay();

    void funIsLeapYear();

    void funWeekNumber();

    void funBirthDay();

    void funAddDate();

    void funReplaceDate();

    void onBtn_close_clicked() {
        file.close();
        close();
    };
};


#endif
