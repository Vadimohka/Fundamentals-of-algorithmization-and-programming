
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->dateAddButton,    &QPushButton::clicked, this, &MainWindow::dateAddButton_clicked);
    connect(ui->dateEditButton,  &QPushButton::clicked, this, &MainWindow::dateEditButton_clicked);
    connect(ui->fileOpen_2,  &QPushButton::clicked, this, &MainWindow::fileOpen_2_clicked);
    connect(ui->fileSave_2,  &QPushButton::clicked, this, &MainWindow::fileSave_2_clicked);
    connect(ui->dateBirthdayField, &QDateEdit::dateChanged, this, &MainWindow::updateBirthdayDays);
    //onnect(this, &MainWindow::windowActivated, this, &MainWindow::doSomething);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent * e) {
    if(e->type() == QEvent::ActivationChange && this->isActiveWindow()) {
        if(fileName != "")
        {
            qDebug() << "Window activated";
            update();
        }
    }
}
Date tempPointer=*new Date;

void MainWindow::dateAddButton_clicked()
{
    int row=ui->datesTable->rowCount();
    ui->datesTable->insertRow(row);
    QDate dateGiven=ui->dateAddField->date();
    tempPointer = Date(dateGiven.year(),dateGiven.month(),dateGiven.day());
    QTableWidgetItem *itemDate=new QTableWidgetItem(dateGiven.toString("dd.MM.yyyy"));
    ui->datesTable->setItem(row,0,itemDate);
    QTableWidgetItem *itemNextDay=new QTableWidgetItem(tempPointer.NextDay().str());
    ui->datesTable->setItem(row,1,itemNextDay);
    QTableWidgetItem *itemPreviousDay=new QTableWidgetItem(tempPointer.PreviousDay().str());
    ui->datesTable->setItem(row,2,itemPreviousDay);
    QTableWidgetItem *itemIsLeap=new QTableWidgetItem(tempPointer.boolToString(tempPointer.IsLeap()));
    ui->datesTable->setItem(row,3,itemIsLeap);
    QTableWidgetItem *itemWeekNumber=new QTableWidgetItem(tempPointer.qint16ToString(tempPointer.WeekNumber()));
    ui->datesTable->setItem(row,4,itemWeekNumber);
    QTableWidgetItem *itemDuration=new QTableWidgetItem(tempPointer.intToString(tempPointer.Duration(tempPointer)));
    ui->datesTable->setItem(row,5,itemDuration);
    QFile file("save.txt");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        return;
    }
    QTextStream out(&file);
    out<<itemDate->text()<<'\n';
    ui->datesTable->update();
}


void MainWindow::dateEditButton_clicked()
{
    int row=ui->dateEditNumber->text().toInt()-1;
    if(row<0||row>=ui->datesTable->rowCount())
    {
        QMessageBox::critical(0,tr("Error"),tr("Incorrect input."),QMessageBox::Ok|QMessageBox::NoButton);
    }
    QDate dateGiven=ui->dateEditField->date();
    tempPointer=Date(dateGiven.year(),dateGiven.month(),dateGiven.day());
    QTableWidgetItem *itemDate=new QTableWidgetItem(dateGiven.toString("dd.MM.yyyy"));
    ui->datesTable->setItem(row,0,itemDate);
    QTableWidgetItem *itemNextDay=new QTableWidgetItem(tempPointer.NextDay().str());
    ui->datesTable->setItem(row,1,itemNextDay);
    QTableWidgetItem *itemPreviousDay=new QTableWidgetItem(tempPointer.PreviousDay().str());
    ui->datesTable->setItem(row,2,itemPreviousDay);
    QTableWidgetItem *itemIsLeap=new QTableWidgetItem(tempPointer.boolToString(tempPointer.IsLeap()));
    ui->datesTable->setItem(row,3,itemIsLeap);
    QTableWidgetItem *itemWeekNumber=new QTableWidgetItem(tempPointer.qint16ToString(tempPointer.WeekNumber()));
    ui->datesTable->setItem(row,4,itemWeekNumber);
    QTableWidgetItem *itemDuration=new QTableWidgetItem(tempPointer.intToString(tempPointer.Duration(tempPointer)));
    ui->datesTable->setItem(row,5,itemDuration);
    QFile file("open.txt");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        return;
    }
    QTextStream out(&file);
    out<<itemDate->text()<<'\n';
    ui->datesTable->update();
}


void MainWindow::updateBirthdayDays(const QDate &date)
{
    Date birthdaydate = Date(date.year(), date.month(), date.day());
    QDate dateCurrentValue = QDate::currentDate();
    Date dateCurrent = Date(dateCurrentValue.year(), dateCurrentValue.month(), dateCurrentValue.day());
    QString daysTillBirthday = QString::number(dateCurrent.DaysTillYourBirthday(birthdaydate));
    ui->birthdayDaysCounterLabel->setText(daysTillBirthday);
}

bool MainWindow::fileCheck(QString date)
{
    QString tempDay="",tempMonth="",tempYear="";
    qint16 tempDayValue=0,tempMonthValue=0,tempYearValue=0;
    if(date[2]!='.'||date[5]!='.'||date.length()!=10){
        return false;
    }
    for (auto c : date) {
        if ((c > '9' || c < '0') && c != '.') {
            return false;
        }
    }
    for(int i=0;i<date.length();i++)
    {
        if(i>=0&&i<2){
            tempDay+=date[i];
        }
        if(i>2&&i<5){
            tempMonth+=date[i];
        }
        if(i>5){
            tempYear+=date[i];
        }
    }
    tempDayValue=tempDay.toInt();
    tempMonthValue=tempMonth.toInt();
    tempYearValue=tempYear.toInt();
    Date tempPointer(tempYearValue,tempMonthValue,tempDayValue);
    //if(tempYearValue>9999||tempYearValue<0||tempMonthValue>12||tempMonthValue<0||tempDayValue>31||tempDayValue<0) return false;
    if(!tempPointer.IsLeap()&&tempMonthValue==2&&tempDayValue>28){
        return false;
    }
    if(tempPointer.IsLeap()&&tempMonthValue==2&&tempDayValue>29) {
        return false;
    }
    if((tempMonthValue==4||tempMonthValue==6||tempMonthValue==9||tempMonthValue==11)&&tempDayValue>30){
        return false;
    }
    return true;
}

void MainWindow:: fileOpen_2_clicked()
{
    fileName=QFileDialog::getOpenFileName(this,tr("Open"),"//",tr("Text doc-s (*.txt)"));
    file.setFileName(fileName);
    pass = fileName;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        if(!fileCheck(line))
        {
           // QMessageBox::critical(0,tr("Error"),tr("Incorrect data format."),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        int row=ui->datesTable->rowCount();
        ui->datesTable->insertRow(row);
        QDate dateGiven=dateGiven.fromString(line,"dd.MM.yyyy");
        tempPointer=Date(dateGiven.year(),dateGiven.month(),dateGiven.day());
        QTableWidgetItem *itemDate=new QTableWidgetItem(dateGiven.toString("dd.MM.yyyy"));
        ui->datesTable->setItem(row,0,itemDate);
        QTableWidgetItem *itemNextDay=new QTableWidgetItem(tempPointer.NextDay().str());
        ui->datesTable->setItem(row,1,itemNextDay);
        QTableWidgetItem *itemPreviousDay=new QTableWidgetItem(tempPointer.PreviousDay().str());
        ui->datesTable->setItem(row,2,itemPreviousDay);
        QTableWidgetItem *itemIsLeap=new QTableWidgetItem(tempPointer.boolToString(tempPointer.IsLeap()));
        ui->datesTable->setItem(row,3,itemIsLeap);
        QTableWidgetItem *itemWeekNumber=new QTableWidgetItem(tempPointer.qint16ToString(tempPointer.WeekNumber()));
        ui->datesTable->setItem(row,4,itemWeekNumber);
        QTableWidgetItem *itemDuration=new QTableWidgetItem(tempPointer.intToString(tempPointer.Duration(tempPointer)));
        ui->datesTable->setItem(row,5,itemDuration);
        ui->datesTable->update();
    }
    file.close();
}


void MainWindow::fileSave_2_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Save"),"//",tr("Text doc-s (*.txt)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        return;
    }
    QTextStream out(&file);
    int row=ui->datesTable->rowCount();
    for(int i=0;i<row;i++)
    {
        QTableWidgetItem *itemDate=new QTableWidgetItem(ui->datesTable->item(i,0)->text());
        out<<itemDate->text()<<'\n';
    }
    file.close();
}

void MainWindow::update()
{
    ui->datesTable->setRowCount(0);
    file.setFileName(pass);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        if(!fileCheck(line))
        {
            // QMessageBox::critical(0,tr("Error"),tr("Incorrect data format."),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        int row=ui->datesTable->rowCount();
        ui->datesTable->insertRow(row);
        QDate dateGiven=dateGiven.fromString(line,"dd.MM.yyyy");
        tempPointer=Date(dateGiven.year(),dateGiven.month(),dateGiven.day());
        QTableWidgetItem *itemDate=new QTableWidgetItem(dateGiven.toString("dd.MM.yyyy"));
        ui->datesTable->setItem(row,0,itemDate);
        QTableWidgetItem *itemNextDay=new QTableWidgetItem(tempPointer.NextDay().str());
        ui->datesTable->setItem(row,1,itemNextDay);
        QTableWidgetItem *itemPreviousDay=new QTableWidgetItem(tempPointer.PreviousDay().str());
        ui->datesTable->setItem(row,2,itemPreviousDay);
        QTableWidgetItem *itemIsLeap=new QTableWidgetItem(tempPointer.boolToString(tempPointer.IsLeap()));
        ui->datesTable->setItem(row,3,itemIsLeap);
        QTableWidgetItem *itemWeekNumber=new QTableWidgetItem(tempPointer.qint16ToString(tempPointer.WeekNumber()));
        ui->datesTable->setItem(row,4,itemWeekNumber);
        QTableWidgetItem *itemDuration=new QTableWidgetItem(tempPointer.intToString(tempPointer.Duration(tempPointer)));
        ui->datesTable->setItem(row,5,itemDuration);
        ui->datesTable->update();
    }
    file.close();
}

