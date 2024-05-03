#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table->setColumnWidth(0, 150);
    ui->table->setColumnWidth(1, 150);

    ui->table->setColumnWidth(2, 150);
    ui->table->setColumnWidth(3, 150);

     ui->table->insertColumn(0);
      ui->table->insertColumn(1);
       ui->table->insertColumn(2);
        ui->table->insertColumn(3);

    ui->table->setColumnWidth(0, 150);
    ui->table->setColumnWidth(1, 150);

    ui->table->setColumnWidth(2, 150);
    ui->table->setColumnWidth(3, 150);

    QTableWidgetItem *header1= new QTableWidgetItem();
    header1->setText("Value");
    ui->table->setHorizontalHeaderItem(0,header1);

    QTableWidgetItem *header2= new QTableWidgetItem();
    header2->setText("Next day");
    ui->table->setHorizontalHeaderItem(1,header2);

    QTableWidgetItem *header3= new QTableWidgetItem();
    header3->setText("Diff with previous");
    ui->table->setHorizontalHeaderItem(2,header3);

    QTableWidgetItem *header4= new QTableWidgetItem();
    header4->setText("Result");
    ui->table->setHorizontalHeaderItem(3,header4);

    connect(ui->prevB, &QPushButton::pressed, this, &MainWindow::resPrev);
    connect(ui->addB, &QPushButton::pressed, this, &MainWindow::addButton);
    connect(ui->deleteB, &QPushButton::pressed, this, &MainWindow::deleteButton);
    connect(ui->changeB, &QPushButton::pressed, this, &MainWindow::changeButton);
    connect(ui->birthB, &QPushButton::pressed, this, &MainWindow::resDiff);
    connect(ui->leapB, &QPushButton::pressed, this, &MainWindow::resLeap);
    connect(ui->diffB, &QPushButton::pressed, this, &MainWindow::resDiff);
    connect(ui->openB, &QPushButton::pressed, this, &MainWindow::openFile);

    ui->deleteSpin->setMinimum(1);
    ui->changeSpin->setMinimum(1);


    QDate beg;
    beg.setDate(0001, 01, 01);

    QDate end;
    end.setDate(9999, 12, 31);

    ui->dateEdit->setDateRange(beg, end);

    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resPrev()
{
    for (int i = 0; i<ui->table->rowCount(); i++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem();
        newItem->setText(date.prevDate(i));
        ui->table->setItem(i,3, newItem);
    }
}

void MainWindow::setDiff(int ind)
{
   int difference =date.getDefWithPrev(ind);

    QTableWidgetItem *newItem = new QTableWidgetItem();
    newItem->setText(QString::number(difference));
    ui->table->setItem(ind,2, newItem);

}

void MainWindow::setNext(int ind)
{
    QTableWidgetItem *newItem = new QTableWidgetItem();
    newItem->setText(date.nextDate(ind));
    ui->table->setItem(ind,1, newItem);
}

void MainWindow::addButton()
{
    ui->table->insertRow(ui->table->rowCount());
    date.addDate(ui->dateEdit->date());

    if (!fromFile)
    {
    QTableWidgetItem *Item1 = new QTableWidgetItem();
    Item1->setText(ui->dateEdit->text());

    ui->table->setItem(ui->table->rowCount()-1, 0, Item1);

    setDiff(ui->table->rowCount()-1);
    setNext(ui->table->rowCount()-1);
    }

    else
    {
    addToFile(ui->dateEdit->date().toString("dd.MM.yyyy"));
        setDiff(ui->table->rowCount()-1);
        setNext(ui->table->rowCount()-1);
    putDataFromFileToTable();
    }

}

void MainWindow::addFromFile()
{
    ui->table->insertRow(ui->table->rowCount());

    QTableWidgetItem *Item = new QTableWidgetItem();
    Item->setText(currData.toString("dd.MM.yyyy"));
    date.addDate(currData);
    ui->table->setItem(ui->table->rowCount()-1, 0, Item);

    setDiff(ui->table->rowCount()-1);
    setNext(ui->table->rowCount()-1);
}

void MainWindow::deleteButton()
{
    int ind = ui->deleteSpin->value()-1;

    if (ind>ui->table->rowCount()-1) {QMessageBox::warning(this, "Error", "Index out of range"); return;}

    ui->table->removeRow(ind);

    if (fromFile)
    {
        deleteFromFile(ind);
    }
    date.deleteDate(ind);
}

void MainWindow::changeButton()
{
    int ind = ui->changeSpin->value()-1;

    QDate newDate = ui->dateEdit->date();

    if (ind>ui->table->rowCount()-1) {QMessageBox::warning(this, "Error", "Index out of range"); return;}

    QTableWidgetItem *Item = new QTableWidgetItem();

    Item->setText(date.fromDateToString(newDate));


    if (fromFile)
    {
        changeFromFile(ind);
    }

    ui->table->setItem(ind, 0, Item);

    date.changeDate(ind, newDate);

    setDiff(ind);
    setNext(ind);

}

void MainWindow::resLeap()
{
    for (int i = 0; i<ui->table->rowCount(); i++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem();
        bool check = date.isLeap(i);
        check ? newItem->setText("Is leap") : newItem->setText("Isn't leap");
        ui->table->setItem(i,3, newItem);
    }
}

void MainWindow::resDiff()
{
    for (int i = 0; i<ui->table->rowCount(); i++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem();
        if (sender()==ui->diffB ) newItem->setText(QString::number(date.getDiff(i, ui->dateEdit->date())));
        else if (sender()==ui->birthB) newItem->setText(QString::number(date.getDiff(i, ui->birthEdit->date())));
        ui->table->setItem(i,3, newItem);
    }
}

void MainWindow::openFile() {
    //hideAll();
    pathToFile = QFileDialog::getOpenFileName(this, tr("Choose file"), {}, tr("*.txt"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected.");
        return;
    }

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    QString s;
    while (!fileStream.atEnd()) {
        s = fileStream.readLine().trimmed();
        QRegularExpression rx("\\b(0[1-9]|[12][0-9]|3[01])\\.(0[1-9]|1[0-2])\\.\\d{4}\\b");
        QRegularExpressionMatch match = rx.match(s);

        QDate tryDate = QDate::fromString(s, "dd.MM.yyyy");
        if (!tryDate.isValid()) {
            QMessageBox::warning(this, "Error", "Incorrect file format");
            return;
        }

        if (!match.hasMatch())
        {
            QMessageBox::warning(this, "Error", "Incorrect file format");
            return;
        }

        QDate dat = QDate::fromString(s, "dd.MM.yyyy");
        if (dat.isNull()) {
            QMessageBox::warning(this, "Error", "Error to read information from file / Wrong Format.");
            file.close();
            return;
        }
    }

    file.close();

    putDataFromFileToTable();


}

void MainWindow::putDataFromFileToTable() {
    if (pathToFile.isEmpty()) return;
    qDebug()<<"successfull";
    date.clear();
    ui->table->setRowCount(0);
    fromFile = true;

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString s;
    do {
        fileStream >> s;
        if (!s.isEmpty()) {
            currData = QDate::fromString(s, "dd.MM.yyyy");
            addFromFile();
        }
    } while (!fileStream.atEnd());
    //fromFile = false;
    file.close();
    ui->openB->setDown(false);
    qDebug()<<ui->table->rowCount();
  // showAll();
}

void MainWindow::addToFile(QString date)
{
    QFile nfile(pathToFile);
    if (!nfile.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug()<<"Fail to open";
        return;
    }
        QTextStream out(&nfile);
        out<<date<<"\n";
        putDataFromFileToTable();

}

void MainWindow::deleteFromFile(int i)
{
    QFile nfile(pathToFile);
    if (!nfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for reading";
        return;
    }

    QTextStream in(&nfile);
    QStringList lines;
    while (!in.atEnd())
    {
        lines.append(in.readLine());
    }
    nfile.close();

    if (i < lines.size())
    {
        lines.removeAt(i);
    }
    else {QMessageBox::warning(this, "Error", "Index out of range"); return;}

    if (!nfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream out(&nfile);
    for (const QString &line : lines)
    {
        out << line << "\n";
    }
}

void MainWindow::changeFromFile(int ind)
{
    QString newValue = ui->dateEdit->text();
    QFile nfile(pathToFile);
    nfile.open(QIODevice::ReadWrite);

    QTextStream stream(&nfile);

    nfile.seek(11*ind*sizeof(char));
    stream << newValue;

    nfile.close();

}

