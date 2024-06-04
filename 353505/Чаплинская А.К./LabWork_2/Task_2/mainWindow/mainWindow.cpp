#include "mainWindow.h"

mainWindow::mainWindow() {

    auto *mainVL = new QVBoxLayout;
        auto *buttonGL = new QGridLayout;
    auto *addInfoVLayout = new QVBoxLayout;

    arrayOfItems = (projectClass **) calloc(1, sizeof(projectClass *));

    auto *HL = new QHBoxLayout;

    buttonGL->addWidget(openFileBtn, 0, 0);
    connect(openFileBtn, SIGNAL(clicked(bool)), SLOT(openDolphin()));

    buttonGL->addWidget(sortBtn, 0, 1);
    connect(sortBtn, SIGNAL(clicked(bool)), SLOT(sortAll()));

    buttonGL->addWidget(saveToFileBtn, 0, 2);
    connect(saveToFileBtn, SIGNAL(clicked(bool)), SLOT(saveToFile()));

    buttonGL->addWidget(closeBtn, 0, 3);
    connect(closeBtn, SIGNAL(clicked(bool)), SLOT(onBtn_close_clicked()));

    buttonGL->addWidget(getListOfProjectsBtn, 1, 0);
    connect(getListOfProjectsBtn, SIGNAL(clicked(bool)), SLOT(getListOfPmProjects()));

    buttonGL->addWidget(getTaskListBtn, 1, 1);
    connect(getTaskListBtn, SIGNAL(clicked(bool)), SLOT(getEmployeeTaskList()));

    buttonGL->addWidget(getStaffListBtn, 1, 2);
    connect(getStaffListBtn, SIGNAL(clicked(bool)), SLOT(getProjectStaffList()));

    buttonGL->addWidget(getBanList, 1, 3);
    connect(getBanList, SIGNAL(clicked(bool)), SLOT(getBanListForEmployee()));

    addInfoVLayout->addWidget(labelAddNew, 1);

    addInfoVLayout->addWidget(addProjNameLbl, 1);
    addInfoVLayout->addWidget(addProjNameEdit, 1);

    addInfoVLayout->addWidget(addTaskLbl, 1);
    addInfoVLayout->addWidget(addTaskEdit, 1);

    addInfoVLayout->addWidget(addNamePmLbl, 1);
    addInfoVLayout->addWidget(addNamePmEdit, 1);

    addInfoVLayout->addWidget(addNameEmployeeLbl, 1);
    addInfoVLayout->addWidget(addNameEmployeeEdit, 1);

    addInfoVLayout->addWidget(calendarStartDateLbl, 1);
    addInfoVLayout->addWidget(calendarStartDate, 1);

    addInfoVLayout->addWidget(calendarBanDateLbl, 1);
    addInfoVLayout->addWidget(calendarBanDate, 1);

    addInfoVLayout->addWidget(calendarEndDateLbl, 1);
    addInfoVLayout->addWidget(calendarEndDate, 1);

    addInfoVLayout->addStretch(1000);
    addInfoVLayout->addWidget(addBtn);
    connect(addBtn, SIGNAL(clicked(bool)), SLOT(addToArray()));

    addInfoVLayout->addWidget(editBtn);
    connect(editBtn, SIGNAL(clicked(bool)), SLOT(editSomeThing()));


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

    informationView->setReadOnly(true);
    answerView->setReadOnly(true);

    HL->addLayout(addInfoVLayout, 2);
    HL->addWidget(informationView, 3);
    HL->addWidget(answerView, 3);

    mainVL->addLayout(HL);
    mainVL->addLayout(buttonGL);

    setLayout(mainVL);

    disableBtn();

}

void mainWindow::disableBtn() {
    addBtn->setEnabled(false);
    sortBtn->setEnabled(false);
    saveToFileBtn->setEnabled(false);
    getListOfProjectsBtn->setEnabled(false);
    getTaskListBtn->setEnabled(false);
    getStaffListBtn->setEnabled(false);
    getBanList->setEnabled(false);
    informationView->setEnabled(false);
    labelAddNew->setEnabled(false);
    addProjNameLbl->setEnabled(false);
    addProjNameEdit->setEnabled(false);
    addTaskLbl->setEnabled(false);
    addTaskEdit->setEnabled(false);
    addNamePmLbl->setEnabled(false);
    addNamePmEdit->setEnabled(false);
    addNameEmployeeLbl->setEnabled(false);
    addNameEmployeeEdit->setEnabled(false);
    calendarStartDateLbl->setEnabled(false);
    calendarStartDate->setEnabled(false);
    calendarBanDateLbl->setEnabled(false);
    calendarBanDate->setEnabled(false);
    calendarEndDateLbl->setEnabled(false);
    calendarEndDate->setEnabled(false);
    editBtn->setEnabled(false);
}

void mainWindow::enableBtn() {
    openFileBtn->setEnabled(false);
    addBtn->setEnabled(true);
    sortBtn->setEnabled(true);
    saveToFileBtn->setEnabled(true);
    getListOfProjectsBtn->setEnabled(true);
    getTaskListBtn->setEnabled(true);
    getStaffListBtn->setEnabled(true);
    getBanList->setEnabled(true);
    informationView->setEnabled(true);
    labelAddNew->setEnabled(true);
    addProjNameLbl->setEnabled(true);
    addProjNameEdit->setEnabled(true);
    addTaskLbl->setEnabled(true);
    addTaskEdit->setEnabled(true);
    addNamePmLbl->setEnabled(true);
    addNamePmEdit->setEnabled(true);
    addNameEmployeeLbl->setEnabled(true);
    addNameEmployeeEdit->setEnabled(true);
    calendarStartDateLbl->setEnabled(true);
    calendarStartDate->setEnabled(true);
    calendarBanDateLbl->setEnabled(true);
    calendarBanDate->setEnabled(true);
    calendarEndDateLbl->setEnabled(true);
    calendarEndDate->setEnabled(true);
    editBtn->setEnabled(true);
}

void mainWindow::openDolphin() {
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", projDir + "/..", tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    while (!fileStream.atEnd()) {
        QString s1, s2, s3, s4, s5, s6, s7;

        s1 = fileStream.readLine();
        s2 = fileStream.readLine();
        s3 = fileStream.readLine();
        s4 = fileStream.readLine();
        s5 = fileStream.readLine();
        s6 = fileStream.readLine();
        s7 = fileStream.readLine();

        if (s1.isEmpty() || s2.isEmpty() || s3.isEmpty() || s4.isEmpty() ||
            QDate::fromString(s5, "d.M.yyyy").isNull()
            || QDate::fromString(s6, "d.M.yyyy").isNull()
            || QDate::fromString(s7, "d.M.yyyy").isNull()) {
            QMessageBox::warning(this, "Error", "Wrong file");
            return;
        }

    }

    file.close();
    enableBtn();
    loadFromFile();

}

void mainWindow::loadFromFile() {
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QString projName;
    QString task;
    QString pmName;
    QString employeeName;
    QString startDate;
    QString banDate;
    QString endDate;

    QString all = "";

    do {
        stream >> projName;
        if (!projName.isEmpty()) {
            arrayOfItems = (projectClass **) realloc(arrayOfItems, (nmbOfItems + 1) * sizeof(projectClass *));
            arrayOfItems[nmbOfItems] = new projectClass;
            arrayOfItems[nmbOfItems]->setProjName(projName);
            stream >> task;
            arrayOfItems[nmbOfItems]->setTask(task);
            stream >> pmName;
            arrayOfItems[nmbOfItems]->setPmName(pmName);
            stream >> employeeName;
            arrayOfItems[nmbOfItems]->setEmployeeName(employeeName);
            stream >> startDate;
            arrayOfItems[nmbOfItems]->setStartDate(QDate::fromString(startDate, "d.M.yyyy"));
            stream >> endDate;
            arrayOfItems[nmbOfItems]->setEndDate(QDate::fromString(endDate, "d.M.yyyy"));
            stream >> banDate;
            arrayOfItems[nmbOfItems]->setBanDate(QDate::fromString(banDate, "d.M.yyyy"));
            if (all.indexOf(arrayOfItems[nmbOfItems]->getAllInfo()) < 0) {
                all += arrayOfItems[nmbOfItems]->getAllInfo();
                nmbOfItems++;
            }
        }
    } while (!projName.isEmpty());
    informationView->setPlainText(all);
    answerView->clear();
    file.close();
}

void mainWindow::saveToFile() {
    file.open(QIODevice::ReadWrite);
    file.resize(0);
    QTextStream stream(&file);
    for (int i = 0; i < nmbOfItems; i++) {
        stream << arrayOfItems[i]->getProjName() << "\n";
        stream << arrayOfItems[i]->getTask() << "\n";
        stream << arrayOfItems[i]->getPmName() << "\n";
        stream << arrayOfItems[i]->getEmployeeName() << "\n";
        stream << arrayOfItems[i]->getStartDate().toString("dd.MM.yyyy") << "\n";
        stream << arrayOfItems[i]->getEndDate().toString("dd.MM.yyyy") << "\n";
        stream << arrayOfItems[i]->getBanDate().toString("dd.MM.yyyy") << "\n";
    }
    file.close();
    QMessageBox::information(this, "Saved", "Saved!");
}

void mainWindow::addToArray() {
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
    } else {
        if (startDate > endDate || startDate > banDate) {
            QMessageBox::warning(this, "Error", "Date Error");
            return;
        }
        arrayOfItems = (projectClass **) realloc(arrayOfItems, (nmbOfItems + 1) * sizeof(projectClass *));
        arrayOfItems[nmbOfItems] = new projectClass;
        arrayOfItems[nmbOfItems]->setProjName(projName);
        arrayOfItems[nmbOfItems]->setTask(task);
        arrayOfItems[nmbOfItems]->setPmName(pmName);
        arrayOfItems[nmbOfItems]->setEmployeeName(employeeName);
        arrayOfItems[nmbOfItems]->setStartDate(startDate);
        arrayOfItems[nmbOfItems]->setEndDate(endDate);
        arrayOfItems[nmbOfItems]->setBanDate(banDate);
        if (informationView->toPlainText().indexOf(arrayOfItems[nmbOfItems]->getAllInfo()) < 0) {
            nmbOfItems++;
        } else {
            QMessageBox::warning(this, "Error", "Founded the same item");
        }
    }

    QString all = "";
    for (int i = 0; i < nmbOfItems; i++) all += arrayOfItems[i]->getAllInfo();
    informationView->setPlainText(all);
    answerView->clear();
    file.close();
}

void mainWindow::getListOfPmProjects() {
    QString pmName = addNamePmEdit->text();
    if (pmName.isEmpty()) {
        QMessageBox::warning(this, "Add something", "Add Name of PM");
    } else {
        QString all = "Projects of " + pmName + ":\n\n";
        for (int i = 0; i < nmbOfItems; i++) {
            QString a = arrayOfItems[i]->getPmName();
            if (a == pmName) {
                all += arrayOfItems[i]->getProjName() + "\n";
            }
        }
        if (all == "Projects of " + pmName + ":\n\n") all += "Nothing";
        answerView->setPlainText(all);
    }
}

void mainWindow::getEmployeeTaskList() {
    QString employeeName = addNameEmployeeEdit->text();
    if (employeeName.isEmpty()) {
        QMessageBox::warning(this, "Add something", "Add Name of Employee");
    } else {
        QString all = "Task(s) of " + employeeName + ":\n\n";
        for (int i = 0; i < nmbOfItems; i++) {
            QString a = arrayOfItems[i]->getEmployeeName();
            if (a == employeeName) {
                all += arrayOfItems[i]->getTask() + "\n";
            }
        }
        if (all == "Task(s) of " + employeeName + ":\n\n") all += "Nothing";
        answerView->setPlainText(all);
    }
}

void mainWindow::getProjectStaffList() {
    QString projectName = addProjNameEdit->text();
    if (projectName.isEmpty()) {
        QMessageBox::warning(this, "Add something", "Add Project Name");
    } else {
        QString all = "Staff of " + projectName + ":\n\n";
        QString pmNames = "";
        QString empNames = "";
        for (int i = 0; i < nmbOfItems; i++) {
            QString a = arrayOfItems[i]->getProjName();
            if (a == projectName) {
                if (pmNames.indexOf(arrayOfItems[i]->getPmName()) < 0) pmNames += arrayOfItems[i]->getPmName() + "\n";
                if (empNames.indexOf(arrayOfItems[i]->getEmployeeName()) < 0)
                    empNames +=
                            arrayOfItems[i]->getEmployeeName() +
                            "\n";
            }
        }
        if (pmNames == "") {
            all += "Nothing";
        } else {
            all += "PMs:\n" + pmNames + "\n";
            all += "Employees:\n" + empNames + "\n";
        }
        answerView->setPlainText(all);
    }

}

void mainWindow::getBanListForEmployee() {
    QString all = "Ban list:\n\n";
    for (int i = 0; i < nmbOfItems; i++) {
        if (arrayOfItems[i]->isEmployeeBanned())
            all += "Proj: " + arrayOfItems[i]->getProjName()
                   + "\nEmployee: " + arrayOfItems[i]->getEmployeeName()
                   + "\tPM: " + arrayOfItems[i]->getPmName()
                   + "\nTask: " + arrayOfItems[i]->getTask()
                   + "\nStart: " + arrayOfItems[i]->getStartDate().toString("dd MMM yyyy")
                   + "\tEnd: " + arrayOfItems[i]->getEndDate().toString("dd MMM yyyy")
                   + "\tBan Day: " + arrayOfItems[i]->getBanDate().toString("dd MMM yyyy")
                   + "\nBanned " +
                   QString::number(arrayOfItems[i]->getBanDate().daysTo(arrayOfItems[i]->getEndDate()), 'd', 0) +
                   " Day(s)\n\n";
    }
    if (all == "Ban list:\n\n") all += "Nothing";
    answerView->setPlainText(all);
}

void mainWindow::editSomeThing() {

    editWindow a(arrayOfItems, &nmbOfItems);
    a.exec();
    QString all = "";
    for (int i = 0; i < nmbOfItems; i++) all += arrayOfItems[i]->getAllInfo();
    informationView->setPlainText(all);
    answerView->clear();

}

void mainWindow::onBtn_close_clicked() {
    QMessageBox::StandardButton reply;
    if (file.fileName() != "") {
        reply = QMessageBox::question(this, "Save", "Save items to file?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            saveToFile();
            close();
        } else if (reply == QMessageBox::No) {
            close();
        }

    } else {
        close();
    }
}

void mainWindow::sortAll() {
    qsort(0, nmbOfItems - 1);
    QString all = "";
    for (int i = 0; i < nmbOfItems; i++) all += arrayOfItems[i]->getAllInfo();
    informationView->setPlainText(all);
    answerView->clear();
}

void mainWindow::qsort(int b, int e) {
    int l = b, r = e;
    int mid = (l + r) / 2;
    while (l <= r) {
        while (compare(arrayOfItems[l], arrayOfItems[mid]))
            l++;
        while (compare(arrayOfItems[mid], arrayOfItems[r]))
            r--;
        if (l <= r)
            qSwap(arrayOfItems[l++], arrayOfItems[r--]);
    }
    if (b < r)
        qsort(b, r);
    if (e > l)
        qsort(l, e);
}

bool mainWindow::compare(projectClass *a, projectClass *b) {
    if (a->getProjName() < b->getProjName()) {
        return true;
    } else if (a->getProjName() > b->getProjName()) {
        return false;
    } else if (a->getPmName() < b->getPmName()) {
        return true;
    } else if (a->getPmName() > b->getPmName()) {
        return false;
    } else if (a->getEmployeeName() < b->getEmployeeName()) {
        return true;
    } else if (a->getEmployeeName() > b->getEmployeeName()) {
        return false;
    } else if (a->getTask() < b->getTask()) {
        return true;
    } else if (a->getTask() > b->getTask()) {
        return false;
    } else if (a->getStartDate() < b->getStartDate()) {
        return true;
    } else if (a->getStartDate() > b->getStartDate()) {
        return false;
    } else if (a->getEndDate() < b->getEndDate()) {
        return true;
    } else if (a->getEndDate() > b->getEndDate()) {
        return false;
    } else if (a->getBanDate() < b->getBanDate()) {
        return true;
    } else if (a->getBanDate() > b->getBanDate()) {
        return false;
    } else return false;
}







