#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "MyDateClass/mydateclass.h"

enum {
    COLUMN_DATE_FROM_FILE = 0,
    COLUMN_NEXT_DATE = 1,
    COLUMN_DURATION = 2,
    COLUMN_MY_FUNCTIONS = 3
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private:
    //File
    QFile myFile;

    //Table
    QTableView *myTable;

    //Model
    QStandardItemModel *myModel;
    QModelIndex index;

    //Buttons
    QPushButton *openButton;
    QPushButton *previousDayButton;
    QPushButton *isLeapYearButton;
    QPushButton *weekNumberButton;
    QPushButton *daysTillBirthdayButton;
    QPushButton *addDateButton;
    QPushButton *changeDateButton;
    QPushButton *closeButton;

    //Labels
    QLabel *selectBirthdayDateLabel;
    QLabel *selectDateToFindLabel;
    QLabel *selectDateToChangeLabel;
    QLabel *openButtonLabel;

    //DateEdit
    QDateEdit *addOrFindDateEdit;
    QDateEdit *birthdayDateEdit;
    QDateEdit *replaceToDateEdit;

    //Layouts
    QHBoxLayout *mainHBoxLayout;
    QVBoxLayout *actionVBoxLayout;

    //My class
    MyDateClass *dates = new MyDateClass;

    //Path to my file
    QString pathToFile;

    //
    int numOfRow = 0;

    //Functions
    void enterDataFromFile();

    void feelSelectedColumn(int num);

    void hideButtons();
    void showButtons();
    void clearTableColumn();

public slots:
    void handleWindowActivation()
    {
        QMessageBox::information(this, "Window Activated", "Window has been activated!");
    }

protected slots:
    void openFile();
    void previousDate();
    void isLeapYear();
    void weekNumber();
    void addDate();
    void changeDate();
    void daysTillBirthday();
    void closeButtonClicked();
    void changeEvent(QEvent *event) override;
};
#endif // MAINWINDOW_H
