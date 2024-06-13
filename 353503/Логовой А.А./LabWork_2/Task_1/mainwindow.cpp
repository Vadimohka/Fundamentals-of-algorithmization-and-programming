#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    button1(new QPushButton(this)),
    button2(new QPushButton(this)),
    button3(new QPushButton(this)),
    button4(new QPushButton(this)),
    button5(new QPushButton(this)),
    button6(new QPushButton(this)),
    add_label1(new QLabel(this)),
    label_bithday(new QLabel(this)),
    label_change(new QLabel(this)),
    bithday_line(new QLineEdit(this)),
    add_line(new QLineEdit(this)),
    change_line(new QLineEdit(this)),
    index_line(new QLineEdit(this)),
    validator (new QRegularExpressionValidator(this)),
    intValidator(new QIntValidator(this))

{

    setWindowTitle("DATE");
    resize(1005,700);

    table = new QTableWidget(0, 8, this);
    headers << "Date" << "Day of week" << "Next day" << "Previous day" << "Is leap" << "Week number" << "Duration" << "Next birthday";
    table->setHorizontalHeaderLabels(headers);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->resize(815,1080);

    fileName = "";

    QRegularExpression regExp("([0-2][0-9]|3[0-1])\\.(0[0-9]|1[0-2])\\.\\d{4}");
    validator->setRegularExpression(regExp);

    add_label1->setGeometry(830,0,150,40);
    add_label1->setText("Add Date: ");

    label_bithday->setGeometry(830,150,150,40);
    label_bithday->setText("Date of your bithday: ");

    label_change->setText("Enter Date to correct");
    label_change->setGeometry(830,300,150,40);

    change_line->setGeometry(830,390, 150,30);
    change_line->setPlaceholderText("dd.mm.yyyy");
    change_line->setValidator(validator);

    index_line->setGeometry(830,350,150,30);
    index_line->setPlaceholderText("0-100");
    index_line->setValidator(intValidator);

    add_line->setGeometry(830,40,150,30);
    add_line->setPlaceholderText("dd.mm.yyyy");
    add_line->setValidator(validator);

    bithday_line->setGeometry(830,190,150,30);
    bithday_line->setPlaceholderText("dd.mm.yyyy");
    bithday_line->setValidator(validator);

    button1->setText("Add Date");
    button1->setGeometry(830,100,150,30);
    connect(button1, &QPushButton::clicked, this, &MainWindow::inputInformation);

    button2->setText("Open file");
    button2->setGeometry(830,480,150,30);
    connect(button2, &QPushButton::clicked, this, &MainWindow::openFile);

    button3->setText("Create file");
    button3->setGeometry(830,530,150,30);
    connect(button3, &QPushButton::clicked, this, &MainWindow::createFile);

    button4->setText("Close file");
    button4->setGeometry(830, 580,150,30);
    connect(button4, &QPushButton::clicked, this, &MainWindow::closeFile);

    button5->setText("Bithday change");
    button5->setGeometry(830, 250, 150,30);
    connect(button5, &QPushButton::clicked, this, &MainWindow::changeBithday);

    button6->setText("Date change");
    button6->setGeometry(830, 430, 150, 30);
    connect(button6, &QPushButton::clicked, this, &MainWindow::changeDate);
}

MainWindow::~MainWindow(){

}

void MainWindow::inputInformation(){

    if(fileName != "" && !add_line->text().isEmpty()){
        Date newDate;

    QString text = add_line->text();
    QStringList date_parts = text.split(".");

    newDate.setDay(date_parts[0].toShort());
    newDate.setMonth(date_parts[1].toShort());
    newDate.setYear(date_parts[2].toShort());

    dates.push_back(newDate);
    addDateToTable(newDate);
    writeToFile();

    add_line->clear();
    QMessageBox::about(nullptr, "Success", "Date was successfully added");
    }
    else{
        if(add_line->text().isEmpty())
            QMessageBox::critical(nullptr, "Error", "Date is empty");
        else
        QMessageBox::critical(nullptr, "Error", "No open file");
    }

         add_line->clear();
}

void MainWindow::addDateToTable(Date newDate){
    short row = table->rowCount();
    insertDateToTable(newDate, row);
}

void MainWindow::editDateInTable(Date newDate, short index){
    if(index >= 0 && index < table->rowCount()){
        insertDateToTable(newDate, index);
    }
}

void MainWindow::insertDateToTable(Date newDate, short row){
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(newDate.dateToString()));
    table->setItem(row, 1, new QTableWidgetItem((newDate.dayOfWeeks())));
    table->setItem(row, 2, new QTableWidgetItem(newDate.NextDay().dateToString()));
    table->setItem(row, 3, new QTableWidgetItem(newDate.PreviousDay().dateToString()));
    table->setItem(row, 4, new QTableWidgetItem(newDate.isLeap()? "Yes" : "No"));
    table->setItem(row, 5, new QTableWidgetItem(QString::number(newDate.WeekNumber())));
    table->setItem(row, 6, new QTableWidgetItem(QString::number(newDate.Duration(Date(01,01,0001)))));
    table->setItem(row, 7, new QTableWidgetItem(QString::number(newDate.DaysTillYourBithday(Date(01,01,0001)))));
}


void MainWindow::openFile(){

    fileName = QFileDialog::getOpenFileName(nullptr, "blaugranas/oaip/laba2", "", "text files(*.txt);;All files(*)");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Not open the file");
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList dateParts = line.split(".");
        if (dateParts.size() == 3) {
            short day = dateParts[0].toShort();
            short month = dateParts[1].toShort();
            short year = dateParts[2].toShort();
            dates.push_back(Date(day, month, year));
        }
    }

    for(auto i : dates)
        addDateToTable(i);

    file.close();
    QMessageBox::about(nullptr, "Success" , "File was successfully open");
}

void MainWindow::createFile(){

    fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QTextStream out(&file);
      QMessageBox::about(nullptr, "Success", "File was successfully create");

    }
}

void MainWindow::closeFile() {

    if (fileName != "") {
        fileName ="";
        table->clear();
        table->setRowCount(0);
        dates.clear();
        table->setHorizontalHeaderLabels(headers);
        QMessageBox::information(this, "Success", "File was successfullyy close");
    }
    else
        QMessageBox::critical(this, "Error" , "No open file");

}

void MainWindow::writeToFile(){

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << dates.back().dateToString() << "\n";
            file.close();
            fileName = "";
        }
    }
}

void MainWindow::changeBithday(){

    if(!bithday_line->text().isEmpty()){
    Date newBithday;
    QString text = bithday_line->text();
    QStringList date_parts = text.split(".");

    newBithday.setDay(date_parts[0].toShort());
    newBithday.setMonth(date_parts[1].toShort());
    newBithday.setYear(date_parts[2].toShort());

    for(int row = 0; row < table->rowCount(); ++row) {
        Date currentDate = dates[row];
        table->setItem(row, 7, new QTableWidgetItem(QString::number(currentDate.DaysTillYourBithday(newBithday))));
    }

    table->update();
    QMessageBox::about(nullptr, "Success", "New bithday was created");
    }
    else
        QMessageBox::critical(nullptr, "Error", "Date is empty" );
    bithday_line->clear();
}

void MainWindow::changeDate(){
    Date newDate;

    QString text = change_line->text();
    QString qindex = index_line->text();
    short index = qindex.toShort();
    QStringList date_parts = text.split(".");
    if((index<0 || index >= dates.size()) || date_parts.isEmpty())
        QMessageBox::critical(nullptr, "Error", "Index is out of the rage");

    else{

        short day = date_parts[0].toShort();
        short month = date_parts[1].toShort();
        short year = date_parts[2].toShort();
        Date newDate(day, month, year);
        dates[index] = newDate;
        table->removeRow(index);
        editDateInTable(newDate, index);
        rewriteFile();
        table->update();
    }
    index_line->clear();
    change_line->clear();
}

void MainWindow::rewriteFile(){

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Cannot open the file");
        return;
    }

    QTextStream out(&file);

    for(auto i : dates)
        out << i.dateToString() << "\n";

    file.close();
    QMessageBox::about(nullptr, "Success", "File was successfully updated");
}



