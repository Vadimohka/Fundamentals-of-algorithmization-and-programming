#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include"workwithdate.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton * openBtn;

    QPushButton * fun_proshl_day;
    QPushButton * Year_visok;
    QPushButton * What_number_week;

    QLabel * selectDateToFindLbl;
    //QDateEdit * add_new_date;
    QPushButton * addThisDateBtn;

    QLabel * Date_Birthday;
    //QDateEdit *calendar_To_Se_Date_Birthday;
    QPushButton * fun_Day_for_next_HB;

    QLineEdit * edit;
    QLineEdit * edit1;


    QLabel * prob;
    QLineEdit * calendarReplaceToDate;
    QPushButton * cngThisDateBtn;

    QPushButton * Close;


    QTableView *table;
    QStandardItemModel *model;
    QModelIndex index;

    QFile file;
    QString pathToFile;

    int nmbOfRow = 0;
    int lastFun = 1;

    workWithDate *dates = new workWithDate;

    void show_pushBtn();
    void un_show_pushBtn();

    void putDataFromFileToTable();

    void feelClm(int nmb);

    const int COLUMN_CURRENT_DATE = 0;
    const int COLUMN_NEXT_DATE = 1;
    const int COLUMN_DIFFERENCE = 2;
    const int COLUMN_FUN = 3;



public slots:

    void My_close(){
        file.close();
        close();
    };

    void funPrevDay();

    void funIsLeapYear();

    void funWeekNumber();

    void funBirthDay();

    void funAddDate();

    void funReplaceDate();

    void openDolphin();

};
#endif // WIDGET_H
