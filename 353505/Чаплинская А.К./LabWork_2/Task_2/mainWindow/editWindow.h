#ifndef LAB1T2_EDITWINDOW_H
#define LAB1T2_EDITWINDOW_H

#include <QtWidgets>
#include "../projects/projectClass.h"

class editWindow : public QDialog {
Q_OBJECT
public:
    explicit editWindow(projectClass **listOfClass, int *nmbOfClasses);

private:
    int *nmbOfItems;
    projectClass **arrayOfItems;

    QComboBox *comboBox = new QComboBox;
    QPushButton *applyBtn = new QPushButton("Edit selected to ↑");
    QPushButton *deleteBtn = new QPushButton("Delete Selected");
    QPushButton *closeBtn = new QPushButton("Close");

    QLabel *labelAddNew = new QLabel("Edit to:");

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

private slots:

    void applyBtnClicked();

    void deleteBtnClicked();

    void onBtn_close_clicked() {
        close();
    }

};


#endif //LAB1T2_EDITWINDOW_H
