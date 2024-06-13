#include "mainwindow.h"

enum {
    MINYEAR = 1,
    MINMONTH = 1,
    MINDAY = 1,
    MAXYEAR = 9999,
    MAXMONTH = 12,
    MAXDAY = 31,
    LENGTH_OF_DATE = 11
};

void MainWindow::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::ActivationChange && this->isActiveWindow()) {
        if (pathToFile.isEmpty()) {
            return;
        }

        myModel->removeRows(0, numOfRow);
        numOfRow = 0;

        myFile.setFileName(pathToFile);
        myFile.open(QIODevice::ReadWrite);
        QTextStream myFileStream(&myFile);

        QString tempString;

        do {
            myFileStream >> tempString;
            if (!tempString.isEmpty()) {
                dates->addDate(QDate::fromString(tempString, "dd.MM.yyyy"));
                if (!dates->getDate(numOfRow).isEmpty()) {
                    myModel->insertRow(numOfRow);
                    feelSelectedColumn(numOfRow);
                    numOfRow++;
                }
            }
        } while (!myFileStream.atEnd());
        myFile.close();
    }
}

MainWindow::MainWindow()
    : myTable(new QTableView)
    , myModel(new QStandardItemModel(0, 4, this))
    , addOrFindDateEdit(new QDateEdit)
    , birthdayDateEdit(new QDateEdit)
    , replaceToDateEdit(new QDateEdit)
    , mainHBoxLayout(new QHBoxLayout)
    , actionVBoxLayout(new QVBoxLayout)

{
    //My Buttons
    openButton = new QPushButton("Open");
    connect(openButton, SIGNAL(clicked(bool)), SLOT(openFile()));

    previousDayButton = new QPushButton("Previous day");
    connect(previousDayButton, SIGNAL(clicked(bool)), SLOT(previousDate()));

    isLeapYearButton = new QPushButton("Is leap year?");
    connect(isLeapYearButton, SIGNAL(clicked(bool)), SLOT(isLeapYear()));

    weekNumberButton = new QPushButton("Week number?");
    connect(weekNumberButton, SIGNAL(clicked(bool)), SLOT(weekNumber()));

    daysTillBirthdayButton = new QPushButton("Days till your birthday");
    connect(daysTillBirthdayButton, SIGNAL(clicked(bool)), SLOT(daysTillBirthday()));

    addDateButton = new QPushButton("Add Date");
    connect(addDateButton, SIGNAL(clicked(bool)), SLOT(addDate()));

    changeDateButton = new QPushButton("Change this date");
    connect(changeDateButton, SIGNAL(clicked(bool)), SLOT(changeDate()));

    closeButton = new QPushButton("Close");
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(closeButtonClicked()));

    //My Labels
    selectBirthdayDateLabel = new QLabel("Enter your birthday date");

    selectDateToFindLabel = new QLabel("Enter date you want to find/edit");

    selectDateToChangeLabel = new QLabel("Enter date to replace");

    openButtonLabel = new QLabel("(Open file to see more functions)");

    //My date edits

    addOrFindDateEdit->setDisplayFormat("dd.MM.yyyy");
    addOrFindDateEdit->setDate(QDate::currentDate());
    birthdayDateEdit->setMinimumDate(QDate(MINYEAR, MINMONTH, MINDAY));
    birthdayDateEdit->setMaximumDate(QDate(MAXYEAR, MAXMONTH, MAXDAY));
    birthdayDateEdit->setDisplayFormat("dd.MM.yyyy");
    birthdayDateEdit->setDate(QDate::currentDate());

    replaceToDateEdit->setDisplayFormat("dd.MM.yyyy");
    replaceToDateEdit->setDate(QDate::currentDate());

    //Layout
    actionVBoxLayout->addWidget(openButton);
    actionVBoxLayout->addWidget(openButtonLabel);
    actionVBoxLayout->addWidget(previousDayButton);
    actionVBoxLayout->addWidget(isLeapYearButton);
    actionVBoxLayout->addWidget(weekNumberButton);
    actionVBoxLayout->addSpacing(500);
    actionVBoxLayout->addWidget(selectDateToFindLabel);
    actionVBoxLayout->addWidget(addOrFindDateEdit);
    actionVBoxLayout->addWidget(addDateButton);
    actionVBoxLayout->addSpacing(10);
    actionVBoxLayout->addWidget(selectDateToChangeLabel);
    actionVBoxLayout->addWidget(replaceToDateEdit);
    actionVBoxLayout->addWidget(changeDateButton);
    actionVBoxLayout->addSpacing(20);
    actionVBoxLayout->addWidget(selectBirthdayDateLabel);
    actionVBoxLayout->addWidget(birthdayDateEdit);
    actionVBoxLayout->addWidget(daysTillBirthdayButton);

    actionVBoxLayout->addSpacing(500);
    actionVBoxLayout->addWidget(closeButton);

    //Table and model
    myTable->setModel(myModel);
    myTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    myModel->setHeaderData(0, Qt::Horizontal, "Date from file");
    myModel->setHeaderData(1, Qt::Horizontal, "Next day");
    myModel->setHeaderData(2, Qt::Horizontal, "Duration");
    myModel->setHeaderData(3, Qt::Horizontal, "My functions");

    myTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mainHBoxLayout->addWidget(myTable, 85);
    mainHBoxLayout->addSpacing(10);
    mainHBoxLayout->addLayout(actionVBoxLayout, 5);

    setLayout(mainHBoxLayout);

    hideButtons();
}

void MainWindow::enterDataFromFile()
{
    if (pathToFile.isEmpty()) {
        return;
    }

    myFile.setFileName(pathToFile);
    myFile.open(QIODevice::ReadWrite);
    QTextStream myFileStream(&myFile);

    QString tempString;

    do {
        myFileStream >> tempString;
        if (!tempString.isEmpty()) {
            dates->addDate(QDate::fromString(tempString, "dd.MM.yyyy"));
            if (!dates->getDate(numOfRow).isEmpty()) {
                myModel->insertRow(numOfRow);
                feelSelectedColumn(numOfRow);
                numOfRow++;
            }
        }
    } while (!myFileStream.atEnd());
    myFile.close();
}

void MainWindow::feelSelectedColumn(int num)
{
    Q_UNUSED(num);
    index = myModel->index(num, COLUMN_DATE_FROM_FILE);
    myModel->setData(index, dates->getDate(num));

    index = myModel->index(num, COLUMN_NEXT_DATE);
    myModel->setData(index, dates->getNextDate(num));

    index = myModel->index(num, COLUMN_DURATION);
    myModel->setData(index, dates->duration(num));
}

void MainWindow::hideButtons()
{
    openButton->setVisible(true);
    previousDayButton->setVisible(false);
    isLeapYearButton->setVisible(false);
    weekNumberButton->setVisible(false);
    selectDateToFindLabel->setVisible(false);
    selectDateToChangeLabel->setVisible(false);
    selectBirthdayDateLabel->setVisible(false);
    addOrFindDateEdit->setVisible(false);
    replaceToDateEdit->setVisible(false);
    birthdayDateEdit->setVisible(false);
    addDateButton->setVisible(false);
    changeDateButton->setVisible(false);
    daysTillBirthdayButton->setVisible(false);
}

void MainWindow::showButtons()
{
    openButton->setVisible(false);
    openButtonLabel->setVisible(false);
    previousDayButton->setVisible(true);
    isLeapYearButton->setVisible(true);
    weekNumberButton->setVisible(true);
    selectDateToFindLabel->setVisible(true);
    selectDateToChangeLabel->setVisible(true);
    selectBirthdayDateLabel->setVisible(true);
    addOrFindDateEdit->setVisible(true);
    replaceToDateEdit->setVisible(true);
    birthdayDateEdit->setVisible(true);
    addDateButton->setVisible(true);
    changeDateButton->setVisible(true);
    daysTillBirthdayButton->setVisible(true);
}

void MainWindow::clearTableColumn()
{
    for (int i = 0; i < numOfRow; i++) {
        index = myModel->index(i, COLUMN_MY_FUNCTIONS);
        myModel->setData(index, "");
    }
}

void MainWindow::openFile()
{
    pathToFile = QFileDialog::getOpenFileName(this,
                                              "Open .txt",
                                              QCoreApplication::applicationDirPath(),
                                              tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "No one file selected.", "Please, select file");
        return;
    }

    myFile.setFileName(pathToFile);
    myFile.open(QIODevice::ReadWrite);
    QTextStream myFileStream(&myFile);

    QString tempString;
    while (!myFileStream.atEnd()) {
        tempString = myFileStream.readLine();
        QDate date = QDate::fromString(tempString, "dd.MM.yyyy");
        if (date.isNull()) {
            QMessageBox::warning(this,
                                 "You are gay",
                                 "Some difficults in reading information fron file");
            myFile.close();
            return;
        }
    }

    myFile.close();

    enterDataFromFile();
    showButtons();
}

void MainWindow::previousDate()
{
    for (int i = 0; i < numOfRow; i++) {
        index = myModel->index(i, COLUMN_MY_FUNCTIONS);
        myModel->setData(index, dates->getPreviousDate(i));
    }
}

void MainWindow::isLeapYear()
{
    for (int i = 0; i < numOfRow; i++) {
        index = myModel->index(i, COLUMN_MY_FUNCTIONS);
        myModel->setData(index, dates->isLeapYear(i));
    }
}

void MainWindow::weekNumber()
{
    for (int i = 0; i < numOfRow; i++) {
        index = myModel->index(i, COLUMN_MY_FUNCTIONS);
        myModel->setData(index, dates->weekNumber(i));
    }
}

void MainWindow::addDate()
{
    myModel->insertRow(numOfRow);

    QDate date = addOrFindDateEdit->date();
    dates->addDate(date);

    feelSelectedColumn(numOfRow);
    numOfRow++;
    myFile.open(QIODevice::ReadWrite);
    QTextStream myFileStream(&myFile);
    myFileStream.seek((numOfRow - 1) * LENGTH_OF_DATE * (int) sizeof(char));
    myFileStream << date.toString("dd.MM.yyyy") << "\n";
    myFile.close();
    clearTableColumn();
}

void MainWindow::changeDate()
{
    QDate dateToFind = addOrFindDateEdit->date();
    QDate dateToChange = replaceToDateEdit->date();
    int firstEntry = dates->changeDate(dateToFind, dateToChange);
    myFile.open(QIODevice::ReadWrite);
    QTextStream myFileStream(&myFile);
    myFileStream.seek(
        static_cast<qint64>((firstEntry * LENGTH_OF_DATE * static_cast<int>(sizeof(char)))));
    for (int i = firstEntry; i < numOfRow; i++) {
        feelSelectedColumn(i);
        myFileStream << dates->getDate(i) << "\n";
    }
    myFile.close();
    clearTableColumn();
}

void MainWindow::daysTillBirthday()
{
    QDate birthdayDate = birthdayDateEdit->date();
    for (int i = 0; i < numOfRow; i++) {
        index = myModel->index(i, COLUMN_MY_FUNCTIONS);
        myModel->setData(index, dates->daysTillBirthday(birthdayDate, i));
    }
}

void MainWindow::closeButtonClicked()
{
    myFile.close();
    close();
}
