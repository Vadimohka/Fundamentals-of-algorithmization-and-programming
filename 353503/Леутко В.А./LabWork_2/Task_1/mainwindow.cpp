#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openBtn,&QPushButton::clicked,this,&MainWindow::openFile);
    connect(ui->closeBtn,&QPushButton::clicked,this,&MainWindow::closeFile);
    connect(ui->calendarBD,&QDateEdit::dateChanged,this,&MainWindow::updateBirthdayDays);
    connect(ui->addBtn,&QPushButton::clicked,this,&MainWindow::dateAddButton_clicked);
    connect(ui->changeBtn,&QPushButton::clicked,this,&MainWindow::dateEditButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    filePath = QFileDialog::getOpenFileName(this, "Open .txt", projectDirectory + "/..", tr("Text File (*.txt)"));
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "No one file selected.");
        return;
    }

    file.setFileName(filePath);
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
        int row=ui->datesTable->rowCount();
        ui->datesTable->insertRow(row);
        QDate dateGiven=dateGiven.fromString(s,"dd.MM.yyyy");
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

void MainWindow::closeFile()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Q", "Exit", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes){
        file.close();
        close();
    }
}

void MainWindow::dateAddButton_clicked()
{
    int row=ui->datesTable->rowCount();
    ui->datesTable->insertRow(row);
    QDate dateGiven=ui->calendarAdd->date();
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
    int row=ui->lineEdit->text().toInt()-1;
    if(row<0||row>=ui->datesTable->rowCount())
    {
        QMessageBox::critical(0,tr("Error"),tr("Incorrect input."),QMessageBox::Ok|QMessageBox::NoButton);
    }
    QDate dateGiven=ui->calendarChange->date();
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
