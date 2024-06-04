#ifndef LAB1T2_MAINWINDOW_H
#define LAB1T2_MAINWINDOW_H

#include <QtWidgets>
#include "../projects/projectClass.h"
#include "editWindow.h"


class mainWindow : public QWidget {
Q_OBJECT
public:
    mainWindow();

    QString projDir;

private:
    QString pathToFile;
    QFile file;

    projectClass **arrayOfItems;
    int nmbOfItems = 0;

    QPushButton *openFileBtn = new QPushButton("Open...");
    QPushButton *closeBtn = new QPushButton("Close");
    QPushButton *addBtn = new QPushButton("Add");
    QPushButton *editBtn = new QPushButton("Edit/Delete");
    QPushButton *sortBtn = new QPushButton("Sort");
    QPushButton *saveToFileBtn = new QPushButton("Save");
    QPushButton *getListOfProjectsBtn = new QPushButton("Get List Of PM Projects");
    QPushButton *getTaskListBtn = new QPushButton("Get Employee Task List");
    QPushButton *getStaffListBtn = new QPushButton("Get Projects Staff List");
    QPushButton *getBanList = new QPushButton("Get Ban List");

    QPlainTextEdit   *informationView = new QPlainTextEdit;
    QPlainTextEdit *answerView = new QPlainTextEdit;

    QLabel *labelAddNew = new QLabel("Information of project to Add or Find");

    QLabel *addProjNameLbl = new QLabel("Project Name");
    QLineEdit *addProjNameEdit = new QLineEdit;

    QLabel *addTaskLbl = new QLabel("Task Description");
    QLineEdit *addTaskEdit = new QLineEdit;

    QLabel *addNamePmLbl = new QLabel("PM Name");
    QLineEdit *addNamePmEdit = new QLineEdit;

    QLabel *addNameEmployeeLbl = new QLabel("Employee Name");
    QLineEdit *addNameEmployeeEdit = new QLineEdit;

    QLabel *calendarStartDateLbl = new QLabel("Start Date");
    QDateEdit *calendarStartDate = new QDateEdit;

    QLabel *calendarBanDateLbl = new QLabel("Ban Date");
    QDateEdit *calendarBanDate = new QDateEdit;

    QLabel *calendarEndDateLbl = new QLabel("Release Date");
    QDateEdit *calendarEndDate = new QDateEdit;

    void disableBtn();

    void enableBtn();

    void loadFromFile();

    bool compare(projectClass *a, projectClass *b);

    void qsort(int b, int e);

protected slots:

    void openDolphin();

    void onBtn_close_clicked();

    void saveToFile();

    void addToArray();

    void getListOfPmProjects();

    void getEmployeeTaskList();

    void getProjectStaffList();

    void getBanListForEmployee();

    void editSomeThing();

    void sortAll();

};


#endif //LAB1T2_MAINWINDOW_H
