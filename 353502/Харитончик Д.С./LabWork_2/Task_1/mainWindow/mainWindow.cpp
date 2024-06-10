#include "mainWindow.h"

mainWindow::mainWindow() {
    // connecting button slots
    openBtn = new QPushButton("Open");
    connect(openBtn, SIGNAL(clicked(bool)), SLOT(openFileWithDolphin()));

    previousDayBtn = new QPushButton("Previous Day");
    connect(previousDayBtn, SIGNAL(clicked(bool)), SLOT(previousDayFun()));

    leapYearOrNotBtn = new QPushButton("Leap year or not");
    connect(leapYearOrNotBtn, SIGNAL(clicked(bool)), SLOT(isLeapYearFunc()));

    weekNumBtn = new QPushButton("Week number");
    connect(weekNumBtn, SIGNAL(clicked(bool)), SLOT(weekNumberFunc()));

    daysToBirthdayBtn = new QPushButton("Days to next birthday");
    connect(daysToBirthdayBtn, SIGNAL(clicked(bool)), SLOT(birthdayDayFunc()));

    insertDateBtn = new QPushButton("Insert date");
    connect(insertDateBtn, SIGNAL(clicked(bool)), SLOT(addDateFunc()));

    modifyDateBtn = new QPushButton("Modify date");
    connect(modifyDateBtn, SIGNAL(clicked(bool)), SLOT(replaceDateFunc()));

    closeBtn = new QPushButton("Close");
    connect(closeBtn, SIGNAL(clicked(bool)), SLOT(onBtn_close_clicked()));

    // labels
    dateSelectionLabel = new QLabel("Select birthday");
    findDateLabel = new QLabel("Opinion: Select Date To Add/Find");
    replaceDateLabel = new QLabel("Select date to replace");

    // QDate objects
    birthdayCalendar = new QDateEdit;
    QDate date;
    date.setDate(1, 1, 1);
    birthdayCalendar->setMinimumDate(date);
    date.setDate(9999, 12, 31); // set max date for choise
    birthdayCalendar->setMaximumDate(date);
    birthdayCalendar->setDisplayFormat("dd MM yyyy");
    birthdayCalendar->setDate(QDate::currentDate());
    birthdayCalendar->setCalendarPopup(true);

    calendarDateOperation = new QDateEdit;
    calendarDateOperation->setDisplayFormat("dd MM yyyy");
    calendarDateOperation->setDate(QDate::currentDate());
    calendarDateOperation->setCalendarPopup(true);

    calendarSwapToDate = new QDateEdit;
    calendarSwapToDate->setDisplayFormat("dd MM yyyy");
    calendarSwapToDate->setDate(QDate::currentDate());
    calendarSwapToDate->setCalendarPopup(true);

    // layouts
    auto *mainHorizontalLayout = new QHBoxLayout;
    auto *verticalLayoutAction = new QVBoxLayout;

    verticalLayoutAction->addWidget(openBtn);
    verticalLayoutAction->addWidget(previousDayBtn);
    verticalLayoutAction->addWidget(leapYearOrNotBtn);
    verticalLayoutAction->addWidget(weekNumBtn);
    verticalLayoutAction->addSpacing(20);
    verticalLayoutAction->addWidget(dateSelectionLabel);
    verticalLayoutAction->addWidget(birthdayCalendar);
    verticalLayoutAction->addWidget(daysToBirthdayBtn);
    verticalLayoutAction->addSpacing(20);
    verticalLayoutAction->addWidget(findDateLabel);
    verticalLayoutAction->addWidget(calendarDateOperation);
    verticalLayoutAction->addWidget(insertDateBtn);
    verticalLayoutAction->addSpacing(15);
    verticalLayoutAction->addWidget(replaceDateLabel);
    verticalLayoutAction->addWidget(calendarSwapToDate);
    verticalLayoutAction->addWidget(modifyDateBtn);
    verticalLayoutAction->addStretch(1000);
    verticalLayoutAction->addWidget(closeBtn);

    // table and model objects
    table = new QTableView;
    standartModel = new QStandardItemModel(0, 4, this);

    table->setModel(standartModel);

    standartModel->setHeaderData(0, Qt::Horizontal, "Value of file");
    standartModel->setHeaderData(1, Qt::Horizontal, "Next day");
    standartModel->setHeaderData(2, Qt::Horizontal, "Difference");
    standartModel->setHeaderData(3, Qt::Horizontal, "Result");

    table->setColumnWidth(0, 130);
    table->setColumnWidth(1, 130);

    // no edit for columns
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mainHorizontalLayout->addLayout(verticalLayoutAction, 2);
    mainHorizontalLayout->addSpacing(5);
    mainHorizontalLayout->addWidget(table, 20);
    setLayout(mainHorizontalLayout);

    hideBtn();
}

// Функция для открытия файла с помощью диалогового окна
void mainWindow::openFileWithDolphin()
{
    // Получаем путь к выбранному файлу с помощью QFileDialog::getOpenFileName.
    // Указываем фильтр для выбора только файлов с расширением .txt.
    filePath = QFileDialog::getOpenFileName(this, "Open .txt", rootDir + "/..", tr("Text file (*.txt)"));

    // Предупреждение, если файл пуст
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No file currently selected.");
        return;
    }

    // Открытие файла для чтения и записи
    file.setFileName(filePath);
    file.open(QIODevice::ReadWrite);
    QTextStream fileReader(&file);

    QString str;
    // Чтение файла построчно
    while (!fileReader.atEnd())
    {
        str = fileReader.readLine();
        // Преобразование считанной строку в QDate, ожидая формат "dd.MM.yyyy"
        auto date = QDate::fromString(str, "dd.MM.yyyy");
        // Если строка не соответствует ожидаемому формату, вывод ошибку и завершения функции
        if (date.isNull())
        {
            QMessageBox::warning(this, "Error", "Error reading file information / Incorrect format.");
            file.close();
            return;
        }
    }

    // Закрытие файла и загрузка данных из файла в таблицу
    file.close();
    loadDataFromFileToTable();
    displayBtn();
}

// Функция для загрузки данных из файла в таблицу
void mainWindow::loadDataFromFileToTable()
{
    // Если путь к файлу пустой, выходим из функции
    if (filePath.isEmpty()) return;

    // Открытие файла для чтения и записи
    file.setFileName(filePath);
    file.open(QIODevice::ReadWrite);
    QTextStream fileReader(&file);
    QString str;
    do
    {
        fileReader >> str;
        if (!str.isEmpty())
        {
            QDate date = QDate::fromString(str, "dd.MM.yyyy");
            // Если дата валидна, добавляем её в модель данных и обновляем таблицу.
            if (!date.isNull())
            {
                dates->addDate(date);
                if (!dates->getDate(numberOfRows).isEmpty())
                {
                    standartModel->insertRow(numberOfRows);
                    fillColumn(numberOfRows);
                    numberOfRows++;
                }
            }
        }
    } while (!fileReader.atEnd());
    file.close();
}

void mainWindow::fillColumn(int num)
{
    indexModel = standartModel->index(num, COLUMN_DATE_TODAY);
    standartModel->setData(indexModel, dates->getDate(num));

    indexModel = standartModel->index(num, COLUMN_DATE_NEXT);
    standartModel->setData(indexModel, dates->nextDate(num));

    indexModel = standartModel->index(num, COLUMN_DELTA);
    standartModel->setData(indexModel, dates->getDefWithPrev(num));
}

void mainWindow::previousDayFun()
{
    lastFunction = 1;
    for (int i = 0; i < numberOfRows; i++)
    {
        indexModel = standartModel->index(i, COLUMN_FUNCTION);
        standartModel->setData(indexModel, dates->previousDay(i));
    }
}

void mainWindow::isLeapYearFunc()
{
    lastFunction = 2;
    for (int i = 0; i < numberOfRows; i++)
    {
        indexModel = standartModel->index(i, COLUMN_FUNCTION);
        standartModel->setData(indexModel, dates->isLeapYear(i) ? "Leap" : "Not");
    }
}

void mainWindow::weekNumberFunc()
{
    lastFunction = 3;
    for (int i = 0; i < numberOfRows; i++)
    {
        indexModel = standartModel->index(i, COLUMN_FUNCTION);
        standartModel->setData(indexModel, dates->getWeekNumber(i));
    }
}

void mainWindow::birthdayDayFunc()
{
    lastFunction = 4;
    QDate dateUntilBD = birthdayCalendar->date();
    for (int i = 0; i < numberOfRows; i++)
    {
        indexModel = standartModel->index(i, COLUMN_FUNCTION);
        standartModel->setData(indexModel, dates->dayUntilYourBirthday(dateUntilBD, i));
    }
}

void mainWindow::addDateFunc()
{
    standartModel->insertRow(numberOfRows);
    QDate date = calendarDateOperation->date();
    dates->addDate(date);
    fillColumn(numberOfRows);
    numberOfRows++;
    file.open(QIODevice::ReadWrite);
    QTextStream fileReader(&file);
    QString format = "dd.MM.yyyy";
    fileReader.seek((numberOfRows - 1) * 11 * sizeof(char));
    fileReader << date.toString(format) << "\n";
    file.close();

    switch (lastFunction)
    {
        case 1:
            previousDayFun();
            break;
        case 2:
            isLeapYearFunc();
            break;
        case 3:
            weekNumberFunc();
            break;
        case 4:
            birthdayDayFunc();
            break;
        default:
            break;
    }
}

void mainWindow::replaceDateFunc()
{
    QDate dateFind = calendarDateOperation->date();
    QDate replaceDate = calendarSwapToDate->date();
    int firstFoundIndex = dates->changeDate(dateFind, replaceDate);
    file.open(QIODevice::ReadWrite);
    QTextStream fileReader(&file);
    fileReader.seek(firstFoundIndex * 11 * sizeof(char));
    for (int i = firstFoundIndex; i < numberOfRows; i++)
    {
        fillColumn(i);
        fileReader << dates->getDate(i) << "\n";
    }
    file.close();

    switch (lastFunction)
    {
        case 1:
            previousDayFun();
            break;
        case 2:
            isLeapYearFunc();
            break;
        case 3:
            weekNumberFunc();
        case 4:
            birthdayDayFunc();
            break;
        default:
            break;
    }
}

void mainWindow::displayBtn()
{
    previousDayBtn->setVisible(true);
    leapYearOrNotBtn->setVisible(true);
    weekNumBtn->setVisible(true);
    daysToBirthdayBtn->setVisible(true);
    insertDateBtn->setVisible(true);
    modifyDateBtn->setVisible(true);
    closeBtn->setVisible(true);

    dateSelectionLabel->setVisible(true);
    findDateLabel->setVisible(true);
    replaceDateLabel->setVisible(true);

    birthdayCalendar->setVisible(true);
    calendarDateOperation->setVisible(true);
    calendarSwapToDate->setVisible(true);
}

void mainWindow::hideBtn()
{
    openBtn->setVisible(true);
    previousDayBtn->setVisible(false);
    leapYearOrNotBtn->setVisible(false);
    weekNumBtn->setVisible(false);
    daysToBirthdayBtn->setVisible(false);
    insertDateBtn->setVisible(false);
    modifyDateBtn->setVisible(false);
    closeBtn->setVisible(true);

    dateSelectionLabel->setVisible(false);
    findDateLabel->setVisible(false);
    replaceDateLabel->setVisible(false);

    birthdayCalendar->setVisible(false);
    calendarDateOperation->setVisible(false);
    calendarSwapToDate->setVisible(false);
}