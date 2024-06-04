//
// Created by g_alex on 2/19/23.
//

#include "editWindow.h"

editWindow::editWindow(projectClass **listOfClass, int *nmbOfClasses) {

    setWindowTitle("Edit/Delete");

    arrayOfItems = listOfClass;
    nmbOfItems = nmbOfClasses;
    auto *mainVB = new QVBoxLayout;
    comboBox->setFixedHeight(150);
    mainVB->addWidget(comboBox, 4);
    QString all = "";
    for (int i = 0; i < *nmbOfItems; i++) {
        if (all.indexOf(listOfClass[i]->getAllInfo()) < 0) {
            comboBox->addItem(listOfClass[i]->getAllInfo());
            all += listOfClass[i]->getAllInfo();
        }
    }

    mainVB->addWidget(labelAddNew, 1);

    mainVB->addWidget(addProjNameLbl, 1);
    mainVB->addWidget(addProjNameEdit, 1);

    mainVB->addWidget(addTaskLbl, 1);
    mainVB->addWidget(addTaskEdit, 1);

    mainVB->addWidget(addNamePmLbl, 1);
    mainVB->addWidget(addNamePmEdit, 1);

    mainVB->addWidget(addNameEmployeeLbl, 1);
    mainVB->addWidget(addNameEmployeeEdit, 1);

    mainVB->addWidget(calendarStartDateLbl, 1);
    mainVB->addWidget(calendarStartDate, 1);

    mainVB->addWidget(calendarBanDateLbl, 1);
    mainVB->addWidget(calendarBanDate, 1);

    mainVB->addWidget(calendarEndDateLbl, 1);
    mainVB->addWidget(calendarEndDate, 1);

    calendarStartDate->setDisplayFormat("dd MMM yyyy");
    calendarStartDate->setDate(QDate::currentDate());
    calendarStartDate->setCalendarPopup(true);
    calendarStartDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);

    calendarBanDate->setDisplayFormat("dd MMM yyyy");
    calendarBanDate->setDate(QDate::currentDate().addDays(2));
    calendarBanDate->setCalendarPopup(true);
    calendarBanDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);

    calendarEndDate->setDisplayFormat("dd MMM yyyy");
    calendarEndDate->setDate(QDate::currentDate().addDays(1));
    calendarEndDate->setCalendarPopup(true);
    calendarEndDate->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);

    mainVB->addSpacing(5);

    mainVB->addWidget(applyBtn);
    connect(applyBtn, SIGNAL(clicked()), SLOT(applyBtnClicked()));

    mainVB->addWidget(deleteBtn);
    connect(deleteBtn, SIGNAL(clicked()), SLOT(deleteBtnClicked()));

    mainVB->addWidget(closeBtn);
    connect(closeBtn, SIGNAL(clicked()), SLOT(onBtn_close_clicked()));

    setLayout(mainVB);

}

void editWindow::applyBtnClicked() {
    QString a = comboBox->currentText();

    QString projName = addProjNameEdit->text();
    QString task = addTaskEdit->text();
    QString pmName = addNamePmEdit->text();
    QString employeeName = addNameEmployeeEdit->text();
    QDate startDate = calendarStartDate->date();
    QDate banDate = calendarBanDate->date();
    QDate endDate = calendarEndDate->date();

    if (projName.isEmpty() || task.isEmpty() || pmName.isEmpty() || employeeName.isEmpty() || startDate.isNull() ||
        banDate.isNull() || endDate.isNull()) {
        QMessageBox::warning(this, "Add something", "You skip some fields");
        return;
    }
    projectClass aClass;
    aClass.setProjName(projName);
    aClass.setTask(task);
    aClass.setPmName(pmName);
    aClass.setEmployeeName(employeeName);
    aClass.setStartDate(startDate);
    aClass.setEndDate(endDate);
    aClass.setBanDate(banDate);


    for (int i = 0; i < *nmbOfItems; i++) {
        if (aClass.getAllInfo() == arrayOfItems[i]->getAllInfo()) {
            QMessageBox::information(this, "Error", "Find Similar Item");
            return;
        }
    }

    if (startDate > endDate || startDate > banDate) {
        QMessageBox::warning(this, "Error", "Date Error");
        return;
    }

    for (int i = 0; i < *nmbOfItems; i++) {
        if (arrayOfItems[i]->getAllInfo() == a) {
            arrayOfItems[i]->setProjName(projName);
            arrayOfItems[i]->setTask(task);
            arrayOfItems[i]->setPmName(pmName);
            arrayOfItems[i]->setEmployeeName(employeeName);
            arrayOfItems[i]->setStartDate(startDate);
            arrayOfItems[i]->setEndDate(endDate);
            arrayOfItems[i]->setBanDate(banDate);
        }
    }
    close();
}

void editWindow::deleteBtnClicked() {
    QString a = comboBox->currentText();
    for (int i = 0; i < *nmbOfItems; i++) {
        if (arrayOfItems[i]->getAllInfo() == a) {
            for (int j = i + 1; j < *nmbOfItems; j++) {
                arrayOfItems[j - 1] = arrayOfItems[j];
            }
            (*nmbOfItems)--;
        }
    }
    close();
}

