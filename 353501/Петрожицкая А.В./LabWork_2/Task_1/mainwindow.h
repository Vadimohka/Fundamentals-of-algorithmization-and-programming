#ifndef LAB2T1_MAINWINDOW_H
#define LAB2T1_MAINWINDOW_H

#include "workWithDate.h"


#include <QtWidgets>
namespace Ui {
class MainWindow;
}

class mainWindow : public QWidget {
    Q_OBJECT
public:
    mainWindow();

    QString projDir;

private:
    Ui::MainWindow *ui;

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
private slots:
    void on_pushButton_clicked(bool checked);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};


#endif
