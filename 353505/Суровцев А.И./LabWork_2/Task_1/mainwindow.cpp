#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1250, 550);
    //setFixedWidth(1250);
    setFixedSize(1250,550);
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < 8; ++i) {
        ui->tableWidget->setColumnWidth(i, 131);
    }
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        startButtonsSetup();
    });
    timer->start(25);
    ui->tableWidget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

bool MainWindow::isColumnEmpty(int column)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (ui->tableWidget->item(row, column))
            return false;
    }
    return true;
}

void MainWindow::startButtonsSetup()
{
    if (isColumnEmpty(0)) {
        ui->bntToRT->setEnabled(false);
        ui->bntToRT->setStyleSheet("background-color: red;");
        ui->bntIsLeepYear->setEnabled(false);
        ui->bntIsLeepYear->setStyleSheet("background-color: red;");
        ui->bntprev->setEnabled(false);
        ui->bntprev->setStyleSheet("background-color: red;");
        ui->bntnext->setEnabled(false);
        ui->bntnext->setStyleSheet("background-color: red;");
        ui->bntMoveHB->setEnabled(false);
        ui->bntMoveHB->setStyleSheet("background-color: red;");
        ui->bntWeekibYear->setEnabled(false);
        ui->bntWeekibYear->setStyleSheet("background-color: red;");
        ui->bntGetnextday->setEnabled(false);
        ui->bntGetnextday->setStyleSheet("background-color: red;");
        ui->lineEdit->clear();
        ui->lineEdit->setReadOnly(true);
        ui->bntAddDate->setEnabled(false);
        ui->bntAddDate->setStyleSheet("background-color: red;");
        ui->bntHB->setEnabled(false);
        ui->bntHB->setStyleSheet("background-color: red;");
        ui->pushButton->setEnabled(false);
        ui->pushButton->setStyleSheet("background-color: red;");
        ui->bnt_zamena->setEnabled(false);
        ui->bnt_zamena->setStyleSheet("background-color: red;");
        //ui->bntdatetoTable->setEnabled(false);
        //ui->bntdatetoTable->setStyleSheet("background-color: red;");
    }
    else {
        ui->bntToRT->setEnabled(true);
        ui->bntToRT->setStyleSheet("background-color: white;");
        ui->bntIsLeepYear->setEnabled(true);
        ui->bntIsLeepYear->setStyleSheet("background-color: white;");
        ui->bntprev->setEnabled(true);
        ui->bntprev->setStyleSheet("background-color: white;");
        ui->bntnext->setEnabled(true);
        ui->bntnext->setStyleSheet("background-color: white;");
        ui->bntMoveHB->setEnabled(true);
        ui->bntMoveHB->setStyleSheet("background-color: white;");
        ui->bntWeekibYear->setEnabled(true);
        ui->bntWeekibYear->setStyleSheet("background-color: white;");
        ui->bntGetnextday->setEnabled(true);
        ui->bntGetnextday->setStyleSheet("background-color: white;");
        ui->lineEdit->setReadOnly(false);
        ui->bntAddDate->setEnabled(true);
        ui->bntAddDate->setStyleSheet("background-color: white;");
        ui->bntHB->setEnabled(true);
        ui->bntHB->setStyleSheet("background-color: white;");
        ui->pushButton->setEnabled(true);
        ui->pushButton->setStyleSheet("background-color: white;");
        //ui->bntdatetoTable->setEnabled(true);
        //ui->bntdatetoTable->setStyleSheet("background-color: white;");
        if (!isColumnEmpty(1)) {
            ui->bntToRT->setEnabled(false);
            ui->bntToRT->setStyleSheet("background-color: red;");
        }
        if (!isColumnEmpty(2)) {
            ui->bntIsLeepYear->setEnabled(false);
            ui->bntIsLeepYear->setStyleSheet("background-color: red;");
        }
        if (!isColumnEmpty(3)) {
            ui->bntprev->setEnabled(false);
            ui->bntprev->setStyleSheet("background-color: red;");
        }
        if (!isColumnEmpty(4)) {
            ui->bntnext->setEnabled(false);
            ui->bntnext->setStyleSheet("background-color: red;");
        }
        if (cnt_list_of_hb) {
            ui->bntMoveHB->setEnabled(false);
            ui->bntMoveHB->setStyleSheet("background-color: red;");
        }
        if (!isColumnEmpty(6)) {
            ui->bntWeekibYear->setEnabled(false);
            ui->bntWeekibYear->setStyleSheet("background-color: red;");
        }
        if (!isColumnEmpty(7)) {
            ui->bntGetnextday->setEnabled(false);
            ui->bntGetnextday->setStyleSheet("background-color: red;");
        }
        if ((bithdaydate.getDay() == 124 || bithdaydate.getDay() == 0) && bithdaydate.getMonth() == 0 && bithdaydate.getYear()==0) {
            ui->bntMoveHB->setEnabled(false);
            ui->bntMoveHB->setStyleSheet("background-color: red;");
        }
        if (ui->lineEdit->property("state").toString() == "0" || ui->lineEdit->property("state").toString() == "2") {
            ui->bntAddDate->setEnabled(false);
            ui->bntAddDate->setStyleSheet("background-color: red;");
            ui->bntHB->setEnabled(false);
            ui->bntHB->setStyleSheet("background-color: red;");
            ui->pushButton->setEnabled(false);
            ui->pushButton->setStyleSheet("background-color: red;");
            //ui->bnt_zamena->setEnabled(false);
            //ui->bnt_zamena->setStyleSheet("background-color: red;");
        }
        else if (ui->lineEdit->property("state").toString() == "1") {
            ui->bntAddDate->setEnabled(true);
            ui->bntAddDate->setStyleSheet("background-color: white;");
            ui->bntHB->setEnabled(true);
            ui->bntHB->setStyleSheet("background-color: white;");
            ui->pushButton->setEnabled(true);
            ui->pushButton->setStyleSheet("background-color: white;");
            //ui->bnt_zamena->setEnabled(false);
            //ui->bnt_zamena->setStyleSheet("background-color: red;");
        }
        My_Date test;
        QString test_str = ui->lineEdit->text();
        test.setDate(test_str);
        if (bithdaydate.getDay() == test.getDay() && bithdaydate.getMonth() == test.getMonth() && bithdaydate.getYear() == test.getYear() && bithdaydate.getDay() != 0 && bithdaydate.getMonth() != 0 && bithdaydate.getYear() != 0) {
            ui->bntHB->setEnabled(false);
            ui->bntHB->setStyleSheet("background-color: red;");
            ui->errorLabel->setText("Вы только что ввели эту дату!!!");
        }
        if (lastDate.getDay() == test.getDay() && lastDate.getMonth() == test.getMonth() && lastDate.getYear() == test.getYear()) {
            ui->bntAddDate->setEnabled(false);
            ui->bntAddDate->setStyleSheet("background-color: red;");
            ui->errorLabel->setText("Вы только что ввели эту дату!!!");
        }
        if (swap) {
            ButtonsSetup();
        }
    }
}

void MainWindow::ButtonsSetup()
{
    ui->bntToRT->setEnabled(false);
    ui->bntToRT->setStyleSheet("background-color: red;");
    ui->bntIsLeepYear->setEnabled(false);
    ui->bntIsLeepYear->setStyleSheet("background-color: red;");
    ui->bntprev->setEnabled(false);
    ui->bntprev->setStyleSheet("background-color: red;");
    ui->bntnext->setEnabled(false);
    ui->bntnext->setStyleSheet("background-color: red;");
    ui->bntMoveHB->setEnabled(false);
    ui->bntMoveHB->setStyleSheet("background-color: red;");
    ui->bntWeekibYear->setEnabled(false);
    ui->bntWeekibYear->setStyleSheet("background-color: red;");
    ui->bntGetnextday->setEnabled(false);
    ui->bntGetnextday->setStyleSheet("background-color: red;");
    ui->bntAddDate->setEnabled(false);
    ui->bntAddDate->setStyleSheet("background-color: red;");
    ui->bntHB->setEnabled(false);
    ui->bntHB->setStyleSheet("background-color: red;");
    ui->pushButton->setEnabled(false);
    ui->pushButton->setStyleSheet("background-color: red;");
    ui->bnt_zamena->setEnabled(true);
    ui->bnt_zamena->setStyleSheet("background-color: white;");
}

int MainWindow::compareStringInFile(const QString &targetString)
{
    QFile file(my_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return -1;
    }
    QTextStream in(&file);
    int lineNumber = 1;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line == targetString) {
            file.close();
            return lineNumber;
        }
        ++lineNumber;
    }
    file.close();
    return -1;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString state = "0";
    QString expectedMask = "\\d{2}\\.\\d{2}\\.\\d{4}"; // Маска для даты в формате 00.00.0000
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->lineEdit->text()=="..") {
        state = "2";
    }
    else if (match.hasMatch()) {
        state = "1";
    }
    else {
        state = "0";
    }
    ui->lineEdit->setProperty("state", state);
    style()->polish(ui->lineEdit);
}

void MainWindow::on_bntAddDate_clicked()
{
    QString textToAppend = ui->lineEdit->text();
    My_Date test;
    QFile file(my_path);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        if (test.setDate(textToAppend)) {
            lastDate.setDate(textToAppend);
            out << textToAppend << '\n';
            ui->errorLabel->setText("Текст успешно добавлен в файл!");
        }
        else ui->errorLabel->setText("Некорректная дата!!!");
        file.close();
    } else {
        ui->errorLabel->setText("Ошибка: не удалось открыть файл для записи!");
    }
}

void MainWindow::on_bntHB_clicked()
{
    bithdaydate.setDate(ui->lineEdit->text());
    if (bithdaydate.getDay() == 0 && bithdaydate.getMonth() == 0 && bithdaydate.getYear() == 0) ui->errorLabel->setText("Неверная дата HB");
    else {
        HB = true;
        cnt_list_of_hb = 0;
        ui->bntMoveHB->setEnabled(true);
        ui->bntMoveHB->setStyleSheet("background-color: white;");
    }
}

void MainWindow::on_bntOpenDialog_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "Выбрать файл", my_path);
    /*QString openedFilePath = QFileDialog::getOpenFileName(nullptr, "Выберите .txt файл", QDir::homePath(), "Текстовые файлы (*.txt)");
    if (!openedFilePath.isEmpty())
    {
        my_path = openedFilePath;
        QDesktopServices::openUrl(QUrl::fromLocalFile(openedFilePath));
    } else
    {
        ui->errorLabel->setText("Это не txt!!!");
    }*/
}

void MainWindow::on_bntdatetoTable_clicked()
{
    QFile file(my_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();
    mw.list_of_dates.clear();
    while (!in.atEnd()) {
        My_Date test;
        My_Date test2;
        test2.setDate("00.00.0000");
        QString line = in.readLine();
        if (test.setDate(line)) {
            mw.add_new_Date(test);
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            QTableWidgetItem *item = new QTableWidgetItem(line);
            ui->tableWidget->setItem(row, 0, item);
        }
        //else mw.add_new_Date(test2);
        //int row = ui->tableWidget->rowCount();
        //ui->tableWidget->insertRow(row);
        //QTableWidgetItem *item = new QTableWidgetItem(line);
        //ui->tableWidget->setItem(row, 0, item);
    }
    file.close();
}

void MainWindow::on_bntToRT_clicked()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    My_Date Reel_Date(year, month, day);
    int f_i = ui->tableWidget->rowCount();
    for (int i = 0; i < f_i; ++i) {
        QTableWidgetItem *item;
        int cnt = mw.daysTo(Reel_Date, mw.list_of_dates[i]);
        if (cnt < 0) item = new QTableWidgetItem("Еще " + QString::number(-cnt));
        else item = new QTableWidgetItem(QString::number(cnt));
        ui->tableWidget->setItem(i, 1, item);
    }
}

void MainWindow::on_bntIsLeepYear_clicked()
{
    int f_i = ui->tableWidget->rowCount();
    for (int i = 0; i < f_i; ++i) {
        bool qw = mw.isLY(i);
        QTableWidgetItem *item = new QTableWidgetItem((qw) ? "ДА" : "НЕТ");
        ui->tableWidget->setItem(i, 2, item);
    }
}


void MainWindow::on_bntprev_clicked()
{
    int f_i = ui->tableWidget->rowCount();
    for (int i = 0; i < f_i; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(mw.get_prev_Date(i));
        ui->tableWidget->setItem(i, 3, item);
    }
    ui->tableWidget->resizeColumnToContents(3);
}


void MainWindow::on_bntnext_clicked()
{
    int f_i = ui->tableWidget->rowCount();
    for (int i = 0; i < f_i; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(mw.get_next_Date(i));
        ui->tableWidget->setItem(i, 4, item);
    }
}


void MainWindow::on_bntMoveHB_clicked()
{
    if (HB) {
        int f_i = ui->tableWidget->rowCount();
        cnt_list_of_hb++;
        for (int i = 0; i < f_i; ++i) {
            QTableWidgetItem *item;
            bool q = 0;
            int cnt = mw.DaysTillYourBithday(bithdaydate, i, q);
            if (cnt == 0) item = new QTableWidgetItem("С днем рождения!!!");
            else if (q) item = new QTableWidgetItem("Рано, до рождения " + QString::number(cnt));
            else item = new QTableWidgetItem(QString::number(cnt));
            ui->tableWidget->setItem(i, 5, item);
        }
        ui->tableWidget->resizeColumnToContents(5);
    }
    else ui->errorLabel->setText("Введите другую дату ДР");
}


void MainWindow::on_bntWeekibYear_clicked()
{
    int f_i = ui->tableWidget->rowCount();
    for (int i = 0; i < f_i; ++i) {
        int cnt = mw.list_of_dates[i].WeekNumber();
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(cnt));
        ui->tableWidget->setItem(i, 6, item);
    }
}


void MainWindow::on_bntGetnextday_clicked()
{
    int f_i = ui->tableWidget->rowCount();
    for (int i = 0; i < f_i - 1; ++i) {
        QTableWidgetItem *item;
        int cnt = mw.daysTo(mw.list_of_dates[i + 1], mw.list_of_dates[i]);
        if (cnt < 0) item = new QTableWidgetItem("Прошло " + QString::number(-cnt));
        else item = new QTableWidgetItem(QString::number(cnt));
        ui->tableWidget->setItem(i, 7, item);
    }
    QTableWidgetItem *item = new QTableWidgetItem("Нет next date");
    ui->tableWidget->setItem(f_i - 1, 7, item);
    ui->tableWidget->resizeColumnToContents(7);
}


void MainWindow::on_pushButton_clicked()
{
    QString textToAppend = ui->lineEdit->text();
    if (compareStringInFile(textToAppend) != -1) {
        ui->errorLabel->setText("Введите заменяющую дату");
        replacement_date = compareStringInFile(textToAppend);
        swap = true;
    }
    else {
        ui->errorLabel->setText("Такой даты нет!");
    }
}


void MainWindow::on_bnt_zamena_clicked()
{
    swap = false;
    ui->bnt_zamena->setEnabled(false);
    ui->bnt_zamena->setStyleSheet("background-color: red;");
    QString textToAppend = ui->lineEdit->text();
    My_Date test;
    if (test.setDate(textToAppend)) {
        ui->errorLabel->setText("Текст успешно изменен!");
        QFile file(my_path);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            return;
        }
        QTextStream in(&file);
        for (int i = 1; i < replacement_date; ++i)
        {
            in.readLine();
            if (in.atEnd())
            {
                return;
            }
        }
        qint64 position = in.pos();
        in.seek(position);
        in << textToAppend + "\n";
        file.close();
    }
    else ui->errorLabel->setText("Некорректная дата!!!");
}

