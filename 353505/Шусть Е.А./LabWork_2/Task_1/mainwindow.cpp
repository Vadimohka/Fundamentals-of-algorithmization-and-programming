#include "mainwindow.h"

mainWindow::mainWindow() {

    openBtn = new QPushButton("Open...");
    connect(openBtn, SIGNAL(clicked(bool)), SLOT(openDolphin()));

    prevDayBtn = new QPushButton("Previous Day");
    connect(prevDayBtn, SIGNAL(clicked(bool)), SLOT(funPrevDay()));

    leapOrNotBtn = new QPushButton("Is Year Leap?");
    connect(leapOrNotBtn, SIGNAL(clicked(bool)), SLOT(funIsLeapYear()));

    weekNumberBtn = new QPushButton("Get Week Number");
    connect(weekNumberBtn, SIGNAL(clicked(bool)), SLOT(funWeekNumber()));

    selectDateLbl = new QLabel("Select BirthDay");

    calendarToSelectBD = new QDateEdit;
    QDate date;
    date.setDate(1, 1, 1);
    calendarToSelectBD->setMinimumDate(date);
    date.setDate(9999, 12, 31);
    calendarToSelectBD->setMaximumDate(date);
    calendarToSelectBD->setDisplayFormat("dd MMM yyyy");
    calendarToSelectBD->setDate(QDate::currentDate());
    calendarToSelectBD->setCalendarPopup(true);

    cntDayToBDBtn = new QPushButton("Count Days To Next Birthday");
    connect(cntDayToBDBtn, SIGNAL(clicked(bool)), SLOT(funBirthDay()));

    addThisDateBtn = new QPushButton("Add Date");
    connect(addThisDateBtn, SIGNAL(clicked(bool)), SLOT(funAddDate()));

    cngThisDateBtn = new QPushButton("Change Date");
    connect(cngThisDateBtn, SIGNAL(clicked(bool)), SLOT(funReplaceDate()));

    selectDateToFindLbl = new QLabel("Select Date To Add/Find");

    calendarAddOrFindDate = new QDateEdit;
    calendarAddOrFindDate->setDisplayFormat("dd MMM yyyy");
    calendarAddOrFindDate->setDate(QDate::currentDate());
    calendarAddOrFindDate->setCalendarPopup(true);

    selectDateToReplaceLbl = new QLabel("Select Date to Replace");

    calendarReplaceToDate = new QDateEdit;
    calendarReplaceToDate->setDisplayFormat("dd MMM yyyy");
    calendarReplaceToDate->setDate(QDate::currentDate());
    calendarReplaceToDate->setCalendarPopup(true);

    closeBtn = new QPushButton("Close");
    connect(closeBtn, SIGNAL(clicked(bool)), SLOT(onBtn_close_clicked()));

    auto *mainHL = new QHBoxLayout;
    auto *actionsVL = new QVBoxLayout;

    actionsVL->addWidget(openBtn);
    actionsVL->addWidget(prevDayBtn);
    actionsVL->addWidget(leapOrNotBtn);
    actionsVL->addWidget(weekNumberBtn);
    actionsVL->addSpacing(20);
    actionsVL->addWidget(selectDateLbl);
    actionsVL->addWidget(calendarToSelectBD);
    actionsVL->addWidget(cntDayToBDBtn);
    actionsVL->addSpacing(20);
    actionsVL->addWidget(selectDateToFindLbl);
    actionsVL->addWidget(calendarAddOrFindDate);
    actionsVL->addWidget(addThisDateBtn);
    actionsVL->addSpacing(10);
    actionsVL->addWidget(selectDateToReplaceLbl);
    actionsVL->addWidget(calendarReplaceToDate);
    actionsVL->addWidget(cngThisDateBtn);
    actionsVL->addStretch(2000);
    actionsVL->addWidget(closeBtn);


    table = new QTableView;
    model = new QStandardItemModel(0, 4, this);

    table->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "File Value");
    model->setHeaderData(1, Qt::Horizontal, "Next Day");
    model->setHeaderData(2, Qt::Horizontal, "Difference");
    model->setHeaderData(3, Qt::Horizontal, "Function Result");

    table->setColumnWidth(0, 160);
    table->setColumnWidth(1, 160);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mainHL->addLayout(actionsVL, 2);
    mainHL->addSpacing(5);
    mainHL->addWidget(table, 19);
    setLayout(mainHL);

    hideBtn();
}

void mainWindow::openDolphin() {
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", projDir + "/..", tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "No one file selected.");
        return;
    }

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    QString s;
    while (!fileStream.atEnd()) {
        s = fileStream.readLine();
        auto date = QDate::fromString(s, "dd.MM.yyyy");
        if (date.isNull()) {
            QMessageBox::warning(this, "Error", "Error to read information from file / Wrong Format.");
            file.close();
            return;
        }

    }

    file.close();

    putDataFromFileToTable();
    showBtn();

}

void mainWindow::putDataFromFileToTable() {
    if (pathToFile.isEmpty()) return;

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString s;
    do {
        fileStream >> s;
        if (!s.isEmpty()) {
            QDate date = QDate::fromString(s, "dd.MM.yyyy");
            if (!date.isNull()) {
                dates->addDate(date);
                if (!dates->getDate(nmbOfRow).isEmpty()) {
                    model->insertRow(nmbOfRow);
                    feelClm(nmbOfRow);
                    nmbOfRow++;
                }
            }
        }
    } while (!fileStream.atEnd());
    file.close();
}

void mainWindow::feelClm(int nmb) {
    index = model->index(nmb, COLUMN_CURRENT_DATE);
    model->setData(index, dates->getDate(nmb));

    index = model->index(nmb, COLUMN_NEXT_DATE);
    model->setData(index, dates->getNextDate(nmb));

    index = model->index(nmb, COLUMN_DIFFERENCE);
    model->setData(index, dates->getDefWithPrev(nmb));
}

void mainWindow::funPrevDay() {
    lastFun = 1;
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->getPrevDate(i));
    }
}

void mainWindow::funIsLeapYear() {
    lastFun = 2;
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->getIsYearLeap(i) ? "Leap" : "Not Leap");
    }
}

void mainWindow::funWeekNumber() {
    lastFun = 3;
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->getWeekNumber(i));
    }
}

void mainWindow::funBirthDay() {
    lastFun = 4;
    QDate dateToBD = calendarToSelectBD->date();
    for (int i = 0; i < nmbOfRow; i++) {
        index = model->index(i, COLUMN_FUN);
        model->setData(index, dates->cntDaysToBD(dateToBD, i));
    }
}

void mainWindow::funAddDate() {
    model->insertRow(nmbOfRow);
    QDate date = calendarAddOrFindDate->date();
    dates->addDate(date);
    feelClm(nmbOfRow);
    nmbOfRow++;
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString format = "dd.MM.yyyy";
    fileStream.seek((nmbOfRow - 1) * 11 * sizeof(char));
    fileStream << date.toString(format) << "\n";
    file.close();

    switch (lastFun) {
    case 1:
        funPrevDay();
        break;
    case 2:
        funIsLeapYear();
        break;
    case 3:
        funWeekNumber();
        break;
    case 4:
        funBirthDay();
        break;
    default:
        break;
    }

}

void mainWindow::funReplaceDate() {
    QDate dateFind = calendarAddOrFindDate->date();
    QDate dateReplace = calendarReplaceToDate->date();
    int firstFind = dates->changeDate(dateFind, dateReplace);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek(firstFind * 11 * sizeof(char));
    for (int i = firstFind; i < nmbOfRow; i++) {
        feelClm(i);
        fileStream << dates->getDate(i) << "\n";
    }
    file.close();
    switch (lastFun) {
    case 1:
        funPrevDay();
        break;
    case 2:
        funIsLeapYear();
        break;
    case 3:
        funWeekNumber();
    case 4:
        funBirthDay();
        break;
    default:
        break;
    }
}

void mainWindow::showBtn() {
    prevDayBtn->setVisible(true);
    leapOrNotBtn->setVisible(true);
    weekNumberBtn->setVisible(true);
    selectDateLbl->setVisible(true);
    selectDateToFindLbl->setVisible(true);
    selectDateToReplaceLbl->setVisible(true);
    calendarToSelectBD->setVisible(true);
    cntDayToBDBtn->setVisible(true);
    addThisDateBtn->setVisible(true);
    cngThisDateBtn->setVisible(true);
    calendarAddOrFindDate->setVisible(true);
    calendarReplaceToDate->setVisible(true);
    openBtn->setVisible(false);
}

void mainWindow::hideBtn() {
    openBtn->setVisible(true);
    prevDayBtn->setVisible(false);
    leapOrNotBtn->setVisible(false);
    weekNumberBtn->setVisible(false);
    selectDateLbl->setVisible(false);
    selectDateToFindLbl->setVisible(false);
    selectDateToReplaceLbl->setVisible(false);
    calendarToSelectBD->setVisible(false);
    cntDayToBDBtn->setVisible(false);
    addThisDateBtn->setVisible(false);
    cngThisDateBtn->setVisible(false);
    calendarAddOrFindDate->setVisible(false);
    calendarReplaceToDate->setVisible(false);
}


