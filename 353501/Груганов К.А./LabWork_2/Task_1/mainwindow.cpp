#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widget = new QWidget();
    setCentralWidget(widget);
    layout = new QHBoxLayout(widget);
    buttons = new QVBoxLayout();
    buttons->setAlignment(Qt::AlignLeft);
    buttons->setContentsMargins(100, 20, 0, 0);
    buttons->setSpacing(10);

    label = new QLabel("Enter date:");
    label->setFixedSize(150,20);
    buttons->addWidget(label);

    dateInput = new QLineEdit();
    dateInput->setPlaceholderText("dd.MM.yyyy");
    dateInput->setFixedSize(150,40);
    buttons->addWidget(dateInput);

    currTime =  new QPushButton("Current TIme");
    currTime->setFixedSize(150,20);
    connect(currTime,&QPushButton::clicked,this,&MainWindow::currTimeClicked);
    buttons->addWidget(currTime);

    daysTillBirthday = new QPushButton("Days till birthday");
    daysTillBirthday->setFixedSize(150,40);
    connect(daysTillBirthday,&QPushButton::clicked,this,&MainWindow::daysTillBirthdayClicked);
    buttons->addWidget(daysTillBirthday);

    isLeap = new QPushButton("is Leap?");
    isLeap->setFixedSize(150,50);
    connect(isLeap,&QPushButton::clicked,this,&MainWindow::isLeapClicked);
    buttons->addWidget(isLeap);

    previous = new QPushButton("Previous day");
    previous->setFixedSize(150,50);
    connect(previous,&QPushButton::clicked,this,&MainWindow::previousClicked);
    buttons->addWidget(previous);

    week = new QPushButton("Week Number");
    week->setFixedSize(150,50);
    connect(week,&QPushButton::clicked, this,&MainWindow::weekNumberClicked);
    buttons->addWidget(week);

    duration = new QPushButton("Duration");
    duration->setFixedSize(150,50);
    connect(duration,&QPushButton::clicked,this,&MainWindow::durationClicked);
    buttons->addWidget(duration);

    open = new QPushButton("Open .txt");
    connect(open,&QPushButton::clicked, this,&MainWindow::openButtonClicked);
    open->setFixedSize(150,40);
    buttons->addWidget(open);

    hlayout = new QHBoxLayout();

    add = new QPushButton("Add");
    add->setFixedSize(75, 40);
    connect(add,&QPushButton::clicked,this,&MainWindow::addClicked);
    hlayout->addWidget(add);

    remove = new QPushButton("Remove");
    remove->setFixedSize(65, 40);
    connect(remove,&QPushButton::clicked,this,&MainWindow::removeClicked);
    hlayout->addWidget(remove);
    buttons->addLayout(hlayout);

    change = new QPushButton("Change");
    change->setFixedSize(150,40);
    connect(change,&QPushButton::clicked,this,&MainWindow::changeClicked);
    buttons->addWidget(change);

    clearFields = new QPushButton("Clear File");
    clearFields->setFixedSize(150, 40);
    connect(clearFields, &QPushButton::clicked, this, &MainWindow::clearFieldsClicked);
    buttons->addWidget(clearFields);



    layout->addLayout(buttons);

    table = new QTableWidget();
    layout->addWidget(table);
    setupTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupTable()
{
    layout->setAlignment(Qt::AlignRight);
    table->resizeColumnsToContents();
    table->setColumnCount(4);
    table->setRowCount(4);
    table->setHorizontalHeaderLabels({"Date", "Next Day", "Difference(in Days)", "Result"});
    table->setFixedWidth(600);

    for(int i=0;i<table->columnCount();i++){
        table->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
    }

    table->setShowGrid(1);

    QStringList rowHeaders;
    for(int i=0;i<table->rowCount();i++){
        rowHeaders <<QString::number(i+1);
    }
    table->setVerticalHeaderLabels(rowHeaders);

    openButtonClicked();
}

void MainWindow::updateTable()
{
        QVector<Date> dates = Date::readDatesFromFile(fileName);
        table->setRowCount(dates.size());

        int currRows = table->rowCount();
        if(currRows < dates.size()){

            QStringList rowHeaders;
            for(int i=0;i<table->rowCount();i++){
                rowHeaders << QString::number(i+1);
            }
            table->setVerticalHeaderLabels(rowHeaders);
        }
        for(int i = 0; i < dates.size(); ++i) {
            Date date = dates[i];
            QString dateStr = date.formatDate(date);
            table->setItem(i,0, new QTableWidgetItem(dateStr));
            Date nextDay = date.NextDay();
            QString nextDayStr = date.formatDate(nextDay);
            table->setItem(i, 1, new QTableWidgetItem(nextDayStr));

            if (i < dates.size() - 1) {
                Date nextDate = dates[i + 1];
                int diff = abs(date.Duration(nextDate,date));
                table->setItem(i, 2, new QTableWidgetItem(QString::number(diff)));
            }
        }
}

Date MainWindow::readDateFromLine()
{
    QString qdateStr = dateInput->text();
    QStringList parts = qdateStr.split(".");
    if (parts.size() != 3) {
        QMessageBox::critical(this, "Error", "Invalid date format");
        return Date{0, 0, 0};
    }
    bool dayOk, monthOk, yearOk;
    int day = parts[0].toInt(&dayOk);
    int month = parts[1].toInt(&monthOk);
    int year = parts[2].toInt(&yearOk);
    Date date(day, month, year);
    try {
        if (!date.isValidDate(day, month, year) || !dayOk || !monthOk || !yearOk || day < 1 || month < 1 || year < 1) {
            throw std::runtime_error("Invalid date");
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
        return Date{0, 0, 0};
    }
    return date;
}


void MainWindow::openButtonClicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Open File", path, "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        table->clearContents();
        QVector<Date> dates = Date::readDatesFromFile(fileName);
        table->setRowCount(dates.size());

        int currRows = table->rowCount();
        if(currRows < dates.size()){

            QStringList rowHeaders;
            for(int i=0;i<table->rowCount();i++){
                rowHeaders <<QString::number(i+1);
            }
            table->setVerticalHeaderLabels(rowHeaders);
        }
        for(int i = 0; i < dates.size(); ++i) {
            Date date = dates[i];
            QString dateStr = date.formatDate(date);
            table->setItem(i,0, new QTableWidgetItem(dateStr));
            Date nextDay = date.NextDay();
            QString nextDayStr = date.formatDate(nextDay);
            table->setItem(i, 1, new QTableWidgetItem(nextDayStr));

            if (i < dates.size() - 1) {
                Date nextDate = dates[i + 1];
                int diff = abs(date.Duration(nextDate,date));
                table->setItem(i, 2, new QTableWidgetItem(QString::number(diff)));
            }
        }
    }
}

void MainWindow::clearFieldsClicked()
{
    Date::clearFile(fileName);
    table->setRowCount(1);
    updateTable();
}

void MainWindow::daysTillBirthdayClicked()
{
    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or can't open");
        return;
    }

    if(!dateInput->text().isEmpty()){
        Date inputDate = readDateFromLine();
    if (!inputDate.isValidDate(inputDate.getDay(), inputDate.getMonth(), inputDate.getYear())) {
        return;
    }

    for(int i = 0; i < table->rowCount(); ++i) {
        QString dateStr = table->item(i, 0)->text();
        QStringList parts = dateStr.split(".");
        Date date(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());

        int daysTillBirthday = date.DaysTillYourBirthday(inputDate);

        table->setItem(i, 3, new QTableWidgetItem(QString::number(daysTillBirthday)));
    }}else{
    QMessageBox::information(this,"No input","Need to enter date");
    return;
    }
}

void MainWindow::currTimeClicked()
{
    Date currentTime = Date::getCurrentTime();
    QString currTImeStr = currentTime.formatDate(currentTime);
    dateInput->setText(currTImeStr);
}

void MainWindow::isLeapClicked()
{
    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or can't open");
        return;
    }

    for(int i=0;i<table->rowCount();i++){
        QString dateStr = table->item(i, 0)->text();
        QStringList parts = dateStr.split(".");
        Date date(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());

        bool isLeap = date.IsLeap();
        QString isLeapStr = isLeap ? "Is leap" : "isn't leap";

        table->setItem(i,3,new QTableWidgetItem(isLeapStr));
    }
}

void MainWindow::previousClicked()
{
    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or can't open");
        return;
    }

    for(int i=0;i<table->rowCount();i++){
        QString dateStr = table->item(i, 0)->text();
        QStringList parts = dateStr.split(".");
        Date date(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());

        table->setItem(i,3, new QTableWidgetItem(QString(date.formatDate(date.PreviousDate()))));
    }

}

void MainWindow::weekNumberClicked()
{
    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or can't open");
        return;
    }

    for(int i=0;i<table->rowCount();i++){
        QString dateStr = table->item(i, 0)->text();
        QStringList parts = dateStr.split(".");
        Date date(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());

        table->setItem(i,3,new QTableWidgetItem(QString::number(date.WeekNumber())));
    }
}

void MainWindow::durationClicked()
{
    if(dateInput->text().isEmpty()){
        QMessageBox::information(this, "No input", "No date entered.");
        return;
    }
    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or cant't  open");
        return;
    }

    Date inputDate = readDateFromLine();

    if (!inputDate.isValidDate(inputDate.getDay(), inputDate.getMonth(), inputDate.getYear())) {
        return;
    }


    for(int i=0;i<table->rowCount();i++){
        QString dateStr = table->item(i, 0)->text();
        QStringList parts = dateStr.split(".");
        Date date(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());

        int duration = date.Duration(inputDate,date);

        table->setItem(i,3,new QTableWidgetItem(QString::number(duration)));
    }

}

void MainWindow::addClicked()
{
    if(!dateInput->text().isEmpty()){
    Date inputDate = readDateFromLine();

    if (!inputDate.isValidDate(inputDate.getDay(), inputDate.getMonth(), inputDate.getYear())) {
        return;
    }

    inputDate.addDateToFile(fileName,inputDate);
    }
    else{
    QMessageBox::information(this,"No input","Need to enter date");
    }
    updateTable();
}

void MainWindow::removeClicked()
{
    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or can't open");
        return;
    }

    Date::removeDateFromFile(fileName);

    updateTable();
}


void MainWindow::changeClicked()
{

    if(table->item(0,0) == nullptr || table->item(0,0)->text().isEmpty()){
        QMessageBox::critical(this,"Error","File is empty or can't open");
        return;
    }
    bool ok;

    QInputDialog input(this);
    input.setMinimumSize(100,100);
    int row = input.getInt(this, "Select", "Enter the date number:", 1, 1, table->rowCount(), 1, &ok);
    if (!ok) {
        QMessageBox::information(this, "No Changes", "No changes were made.");
        return;
    }
    input.setMinimumSize(400,200);
    QString newDateStr = input.getText(this, "Date", "Enter the new date:", QLineEdit::Normal, "", &ok);

    if (!ok) {
        QMessageBox::information(this, "No Changes", "No changes were made.");
        return;
    }

    QStringList newParts = newDateStr.split(".");
    if (newParts.size() != 3) {
        QMessageBox::warning(this, "Invalid Date", "Invalid date format. Please enter date in dd.MM.yyyy format.");
        return;
    }

    Date newDate(newParts[0].toInt(), newParts[1].toInt(), newParts[2].toInt());
    if (!newDate.isValidDate(newDate.getDay(), newDate.getMonth(), newDate.getYear())) {
        QMessageBox::warning(this, "Invalid Date", "Invalid date. Please enter a valid date.");
        return;
    }

    table->setItem(row - 1, 0, new QTableWidgetItem(newDate.formatDate(newDate)));

    newDate.writeDateToFile(fileName, newDate,row-1 );

    QMessageBox::information(this, "Success", "Date has been changed successfully.");

    updateTable();

}
