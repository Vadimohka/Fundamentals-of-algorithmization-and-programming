#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dateeditdialog.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Date currentDate(1, 1, 0);
    dialog = new DateEditDialog(currentDate, this);
    connect(dialog, &DateEditDialog::dateEdited, this, &MainWindow::handleDateEdited);
    //connect(ui->tableWidget, &QTableWidget::itemChanged, this, &MainWindow::on_tableWidget_itemChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextDayButton_clicked()
{
    ui->tableWidget-> update();
    for (int i = 0; i < dates.size(); i++) {
        Date nextDay = dates[i].NextDay();
        QTableWidgetItem *item = new QTableWidgetItem(nextDay.toString());
        ui->tableWidget->setItem(i, 3, item);
    }
}
void MainWindow::on_previousDayButton_clicked()
{
    ui->tableWidget-> update();
    for (int i = 0; i < dates.size(); i++) {
        Date previousDay = dates[i].PreviousDay();
        QTableWidgetItem *item = new QTableWidgetItem(previousDay.toString());
        ui->tableWidget->setItem(i, 3, item);
    }
}

void MainWindow::on_weekNumberButton_clicked()
{
    ui->tableWidget-> update();
    for (int i = 0; i < dates.size(); i++) {
        int weekNumber = dates[i].WeekNumber();
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(weekNumber));
        ui->tableWidget->setItem(i, 3, item);
    }
}

void MainWindow::on_durationButton_clicked()
{
    ui->tableWidget-> update();
    for (int i = 0; i < dates.size() - 1; i++) {
        int duration = dates[i].Duration(dates[i + 1]);
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(duration));
        ui->tableWidget->setItem(i, 3, item);
    }
}

void MainWindow::on_leapYearButton_clicked()
{
    for (int i = 0; i < dates.size(); i++) {
        bool isLeap = dates[i].IsLeap();
        QString result = isLeap ? "Да" : "Нет";
        QTableWidgetItem *item = new QTableWidgetItem(result);
        ui->tableWidget->setItem(i, 3, item);
    }
}

void MainWindow::on_birthdayButton_clicked()
{
    QDate birthdayDate = QDate::fromString(ui->birthdayLineEdit->text(), "dd.MM.yyyy");
    if (!birthdayDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректная дата рождения!");
        return;
    }

    QDate currentDate = QDate::currentDate();
    int daysTillBirthday = currentDate.daysTo(birthdayDate);
    ui->daysTillBirthdayLabel->setText(QString::number(daysTillBirthday));
}

void MainWindow::on_openFileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Текстовые файлы (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    dates.clear();
    ui->tableWidget->setRowCount(0);

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    QStringList dateStrings = line.split(" ");
    for (int i = 0; i < dateStrings.size(); i++) {
        QString dateString = dateStrings[i];
        QStringList dateParts = dateString.split(".");
        if (dateParts.size() != 3) {
            continue;                   // пропуск неправильных дат
        }
        int day = dateParts[0].toInt();
        int month = dateParts[1].toInt();
        int year = dateParts[2].toInt();

        Date date(day, month, year);
        dates.append(date);     //добавляем новую дату в коллекцию

        ui->tableWidget->insertRow(i);
        QTableWidgetItem *dayItem = new QTableWidgetItem(QString::number(day));
        QTableWidgetItem *monthItem = new QTableWidgetItem(QString::number(month));
        QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(year));

        ui->tableWidget->setItem(i, 0, dayItem);
        ui->tableWidget->setItem(i, 1, monthItem);
        ui->tableWidget->setItem(i, 2, yearItem);
    }

    file.close();
}


void MainWindow::on_editDateButton_clicked()
{
    try
    {
        int selectedRow = ui->tableWidget->currentRow();
        if (selectedRow >= 0 && selectedRow < dates.size())
        {
            dialog->setEditedDate(dates[selectedRow]);
            dialog->exec();
        }
        else
        {
            throw std::out_of_range("Invalid selected row");
        }
    }
    catch (const std::exception& e)
    {
        qDebug() << "Exception occurred: " << e.what();
    }
}
void MainWindow::on_addDateButton_clicked()
{
    int day = ui->daySpinBox->value();
    int month = ui->monthSpinBox->value();
    int year = ui->yearSpinBox->value();

    if (!QDate::isValid(year, month, day))
    {
        QMessageBox::warning(this, "Error", "Invalid date.");
        return;
    }

    if (QDate::isLeapYear(year))
    {
        QMessageBox::information(this, "Leap Year", "The entered year is a leap year.");
    }

    Date date(day, month, year);
    dates.append(date);

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *dayItem = new QTableWidgetItem(QString::number(day));
    QTableWidgetItem *monthItem = new QTableWidgetItem(QString::number(month));
    QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(year));

    ui->tableWidget->setItem(row, 0, dayItem);
    ui->tableWidget->setItem(row, 1, monthItem);
    ui->tableWidget->setItem(row, 2, yearItem);
}
/*void MainWindow::on_addDateButton_clicked()
{
    int day = ui->daySpinBox->value();
    int month = ui->monthSpinBox->value();
    int year = ui->yearSpinBox->value();

    Date date(day, month, year);
    dates.append(date);

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *dayItem = new QTableWidgetItem(QString::number(day));
    QTableWidgetItem *monthItem = new QTableWidgetItem(QString::number(month));
    QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(year));

    ui->tableWidget->setItem(row, 0, dayItem);
    ui->tableWidget->setItem(row, 1, monthItem);
    ui->tableWidget->setItem(row, 2, yearItem);
}*/

void MainWindow::on_saveFileButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Текстовые файлы (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    // сохранение данных в файл
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл!");
        return;
    }

    QTextStream out(&file);
    for (const Date& date : dates) {
        QString dateStr = QString("%1 %2 %3\n").arg(date.getDay()).arg(date.getMonth()).arg(date.getYear());
        QByteArray byteArray = dateStr.toUtf8();
        out.device()->write(byteArray.constData(), byteArray.length());
    }

    file.close();
}

void MainWindow::displayDates()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(dates.size());

    // отображение дат в таблице
    for (int i = 0; i < dates.size(); i++) {
        QTableWidgetItem *dayItem = new QTableWidgetItem(QString::number(dates[i].getDay()));
        QTableWidgetItem *monthItem = new QTableWidgetItem(QString::number(dates[i].getMonth()));
        QTableWidgetItem *yearItem = new QTableWidgetItem(QString::number(dates[i].getYear()));

        ui->tableWidget->setItem(i, 0, dayItem);
        ui->tableWidget->setItem(i, 1, monthItem);
        ui->tableWidget->setItem(i, 2, yearItem);
    }
}
void MainWindow::handleDateEdited(const Date& editedDate)
{
    QTableWidgetItem* selectedItem = ui->tableWidget->currentItem();

    if (selectedItem != nullptr)
    {
        int row = ui->tableWidget->row(selectedItem);
        int column = ui->tableWidget->column(selectedItem);

        ui->tableWidget->setItem(row, column, new QTableWidgetItem(editedDate.toString()));
    }
}
