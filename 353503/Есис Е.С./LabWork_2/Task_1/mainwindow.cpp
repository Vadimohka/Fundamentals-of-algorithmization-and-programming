#include "mainwindow.h"
#include "ui_mainwindow.h"

QDate previousDate;

void MainWindow::showPopup()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Предупреждение");
    msgBox.setText("Некорректно введена дата");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

bool MainWindow::IsValid(const QString& dateString)
{
    QDate date = QDate::fromString(dateString, "dd.MM.yyyy");
    return date.isValid();
}

void MainWindow::openFile()
{
    QString filename = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.txt)");
   //filename = QFileInfo(filename).absoluteFilePath();
    QFile file(filename); // Открываем файл для чтения
    if (file.open(QIODevice::ReadOnly)) {
        //QString fileContent = QString::fromUtf8(file.readAll());

    QVector<QDate> dates;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QDate date = QDate::fromString(line, "dd.MM.yyyy");
        if (date.isValid()) {
            dates.append(date);
        }
    }

    for (int i = 0; i < dates.size() - 1; ++i) {
        int difference = dates[i].daysTo(dates[i+1]);
        //ui->plainTextEdit->setPlainText(fileContent);
        ui->plainTextEdit->appendPlainText("Дата: " + dates[i].toString("dd.MM.yyyy") + "\nРазница: " + QString::number(qAbs(difference)) + " дней");}
    if (!dates.isEmpty()) {
        QDate lastDate = dates.last();
        ui->plainTextEdit->appendPlainText("Дата: " + lastDate.toString("dd.MM.yyyy"));}
    if(dates.size())
    previousDate = dates.back();

    }

    file.close();
}

void MainWindow::writeInFile()
{

    QString newData = ui->lineEdit->text();

    if (IsValid(newData)) {
        QFile file("dates.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream out(&file);
            out << newData << "\n"; // Записываем текст в файл
            file.close();
            ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" + newData); // Обновляем содержимое plainTextEdit

        } else {
            qDebug() << "Ошибка при открытии файла:" << file.errorString();
        }
    } else {
        showPopup();
        qDebug() << "Некорректная дата. Введите дату в формате dd.MM.yyyy";
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
   // QPushButton *AddDate = new QPushButton("Add Date", this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Addate_clicked()
{
    QString dateString = ui->lineEdit->text(); // Получаем дату из lineEdit

    QDate currentDate = QDate::fromString(dateString, "dd.MM.yyyy");
    if (currentDate.isValid()) {
        int difference = calculateDateDifference(currentDate);
        writeDifferenceToFile(difference);

        // Отображаем разницу в plainTextEdit
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\nРазница: " + QString::number(qAbs(difference)) + " дней");

        // Обновляем предыдущую дату
        previousDate = currentDate;}
    writeInFile();
    }

void MainWindow::writeDifferenceToFile(int difference)
{
    QFile file("dates_difference.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);
        out << "Разница: " << difference << " дней\n";
        file.close();
    }
}

void MainWindow::readDatesAndCalculateDifferences()
{
    QFile file("dates.txt"); // Замените на имя вашего файла
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


}


void MainWindow::on_openFile_clicked()
{
    openFile();
}

int MainWindow::calculateDateDifference(const QDate& currentDate)
{
    return previousDate.daysTo(currentDate);
}

void MainWindow::on_informationButton_clicked()
{
    QString dateString = ui->lineEdit->text(); // Получаем дату из lineEdit
if (IsValid(dateString)) {
    QDate currentDate = QDate::fromString(dateString, "dd.MM.yyyy");

    showNextDay(currentDate);
    showPreviousDay(currentDate);
    LeapYear(currentDate);
    NumberOfWeek(currentDate);
    UntilToday(currentDate);
}
else {
    showPopup();}
}

void MainWindow::showPreviousDay(QDate date) {

    // Вычисляем предыдущий день
    QDate previous = date.addDays(-1);

    // Выводим предыдущий день на QLabel
    ui->previousDay->setPlainText(previous.toString("dd.MM.yyyy"));
}

void MainWindow::showNextDay(QDate date) {
    QDate dateNext = date.addDays(1);

    // Выводим предыдущий день на QLabel
    ui->showNextDay->setPlainText(dateNext.toString("dd.MM.yyyy"));
}

void MainWindow::LeapYear(QDate date){
    int year = date.year();
    QString leapYearText;
    if(QDate::isLeapYear(year)) {
        leapYearText = QString::number(year) + " год является високосным.\n";
    } else {
        leapYearText = QString::number(year) + " год не является високосным.\n";
    }
    ui->YesOrNotLeap->setPlainText(leapYearText);
}

void MainWindow::NumberOfWeek(QDate date){

    int weekNumber = date.weekNumber(); // Получаем номер недели

    // Выводим номер недели на QLabel
    ui->numberOfWeek->setPlainText("Номер недели: " + QString::number(weekNumber));
}

void MainWindow::UntilToday(QDate date){
    QDate currentDate = QDate::currentDate(); // Получаем текущую дату

    int daysDifference = qAbs(currentDate.daysTo(date)); // Вычисляем разницу в днях

    // Выводим разницу в днях на QLabel
    ui->untilToday->setPlainText("Разница в днях: " + QString::number(daysDifference));
}

void MainWindow::on_differenceBD_clicked()
{
    QString dateString1 = ui->bDay->text();
    QString dateString2 = ui->someDate->text();
    if (IsValid(dateString1) && IsValid(dateString2)) {
        QDate currentDate1 = QDate::fromString(dateString1, "dd.MM.yyyy");
        QDate currentDate2 = QDate::fromString(dateString2, "dd.MM.yyyy");
        int daysDifference = qAbs(currentDate1.daysTo(currentDate2)); // Вычисляем модуль разницы в днях
        ui->resultBD->setPlainText("Разница в днях: " + QString::number(daysDifference));
    }
    else {
        showPopup();}
}

