#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setItem(int row)
{
    QTableWidgetItem *Date = new QTableWidgetItem(dates[row].toString());
    QTableWidgetItem *Next = new QTableWidgetItem(dates[row].nextDay().toString());
    QTableWidgetItem *Previous = new QTableWidgetItem(dates[row].previousDay().toString());
    QTableWidgetItem *Leap = new QTableWidgetItem(Date::boolToString(dates[row].isLeap()));
    QTableWidgetItem *Week = new QTableWidgetItem(Date::intToString(dates[row].weekNumber()));
    QTableWidgetItem *Duration = new QTableWidgetItem(Date::intToString(dates[row].duration()));

    ui->tableWidget->setItem(row, 0, Date);
    ui->tableWidget->setItem(row, 1, Next);
    ui->tableWidget->setItem(row, 2, Previous);
    ui->tableWidget->setItem(row, 3, Leap);
    ui->tableWidget->setItem(row, 4, Week);
    ui->tableWidget->setItem(row, 5, Duration);
}

void MainWindow::on_pushButton_addDate_clicked()
{
    if (file.fileName().isEmpty())
    {
        QMessageBox::warning(nullptr, tr("Warning"), tr("Open a file first!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to write"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QString str = input();
    try
    {
        dates.push_back(*new Date(Date::fromString(str)));
    }
    catch (std::exception &e)
    {
        QMessageBox::critical(0,tr("Error"),tr(e.what()),QMessageBox::Ok|QMessageBox::NoButton);
        ui->tableWidget->update();
        file.close();
        return;
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    setItem(row);
    QTextStream out(&file);
    QTableWidgetItem *Date = new QTableWidgetItem(ui->tableWidget->item(row, 0)->text());
    out << Date->text() << "\n";
    file.close();
}

void MainWindow::on_pushButton_changeDate_clicked()
{
    if (file.fileName().isEmpty())
    {
        QMessageBox::warning(nullptr, tr("Warning"), tr("Open a file first!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    if (ui->tableWidget->selectedItems().empty())
    {
        QMessageBox::information(nullptr, tr("Info"), tr("Select any date!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    QString str = input();
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to write"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int row = ui->tableWidget->selectedItems().first()->row();
    try
    {
        Date date = Date(Date::fromString(str));
        dates.replace(row, date);
    }
    catch (std::exception &e)
    {
        QMessageBox::critical(0,tr("Error"),tr(e.what()),QMessageBox::Ok|QMessageBox::NoButton);
        ui->tableWidget->update();
        file.close();
        return;
    }

    setItem(row);
    QTextStream fileStream(&file);
    fileStream.seek(row * 11 * sizeof(char));
    QTableWidgetItem *Date = new QTableWidgetItem(ui->tableWidget->item(row, 0)->text());
    fileStream << Date->text() << "\n";
    file.close();
}

void MainWindow::on_pushButton_saveFile_clicked()
{
    QString name = QFileDialog::getSaveFileName(this, tr("Save"), "//", tr("Text Documents (*.txt)"));
    name += ".txt";
    QFile saveFile(name);
    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream fileStream(&saveFile);
    int row = ui->tableWidget->rowCount();
    for (int i = 0; i < row; i++)
    {
        QTableWidgetItem *Date = new QTableWidgetItem(ui->tableWidget->item(i, 0)->text());
        fileStream << Date->text() << "\n";
    }
    saveFile.close();
    file.setFileName(saveFile.fileName());
}

void MainWindow::on_pushButton_openFile_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, tr("Open"), "//", tr("Text Documents (*.txt)"));
    if (name.isEmpty())
    {
        return;
    }
    file.setFileName(name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to read"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    ui->tableWidget->setRowCount(0);
    dates.clear();
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString str = in.readLine();
        int row = ui->tableWidget->rowCount();
        try
        {
            dates.push_back(*new Date(Date::fromString(str)));
        }
        catch (std::exception &e)
        {
            QMessageBox::critical(0,tr("Error"),tr("Importing interrupted: ") + e.what(),QMessageBox::Ok|QMessageBox::NoButton);
            ui->tableWidget->update();
            file.close();
            return;
        }
        ui->tableWidget->insertRow(row);
        setItem(row);
    }
    ui->tableWidget->update();
    file.close();
}

QString MainWindow::input()
{
    QString day = ui->spinBox_day->text().size() == 1 ? '0' + ui->spinBox_day->text() : ui->spinBox_day->text();
    QString month = ui->spinBox_month->text().size() == 1 ? '0' + ui->spinBox_month->text() : ui->spinBox_month->text();
    QString year = ui->spinBox_year->text().size() == 1 ? "000" + ui->spinBox_year->text(): (ui->spinBox_year->text().size() == 2 ? "00" + ui->spinBox_year->text() : (ui->spinBox_year->text().size() == 3 ? '0' + ui->spinBox_year->text() : ui->spinBox_year->text()));
    QString str = day + '.' + month + '.' + year;

    return str;
}

QString MainWindow::birthday()
{
    QString day = ui->spinBox_dayB->text().size() == 1 ? '0' + ui->spinBox_dayB->text() : ui->spinBox_dayB->text();
    QString month = ui->spinBox_monthB->text().size() == 1 ? '0' + ui->spinBox_monthB->text() : ui->spinBox_monthB->text();
    QString year = ui->spinBox_yearB->text().size() == 1 ? "000" + ui->spinBox_yearB->text(): (ui->spinBox_yearB->text().size() == 2 ? "00" + ui->spinBox_yearB->text() : (ui->spinBox_yearB->text().size() == 3 ? '0' + ui->spinBox_yearB->text() : ui->spinBox_yearB->text()));
    QString str = day + '.' + month + '.' + year;

    return str;
}

void MainWindow::updateBirthday()
{
    QString str = birthday();
    Date birthdayDate;
    try
    {
        birthdayDate = Date::fromString(str);
    }
    catch (std::exception &e)
    {
        QMessageBox::critical(0,tr("Error"),tr(e.what()),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    Date current = Date::fromString(input());
    ui->lcdNumber_birthdayLeft->display(current.daysBeforeYourBithday(birthdayDate));
}

void MainWindow::on_spinBox_day_valueChanged(int)
{
    updateBirthday();
}

void MainWindow::on_spinBox_month_valueChanged(int month)
{
    ui->spinBox_day->setMaximum(Date::getDaysInMonth(month, ui->spinBox_year->value()));

    if (ui->spinBox_day->value() > Date::getDaysInMonth(month, ui->spinBox_year->value()))
    {
        ui->spinBox_day->setValue(Date::getDaysInMonth(month, ui->spinBox_year->value()));
    }
    updateBirthday();
}

void MainWindow::on_spinBox_year_valueChanged(int year)
{
    ui->spinBox_day->setMaximum(Date::getDaysInMonth(ui->spinBox_month->value(), year));

    if (ui->spinBox_day->value() > Date::getDaysInMonth(ui->spinBox_month->value(), year))
    {
        ui->spinBox_day->setValue(Date::getDaysInMonth(ui->spinBox_month->value(), year));
    }
    updateBirthday();
}

void MainWindow::on_spinBox_dayB_valueChanged(int)
{
    updateBirthday();
}

void MainWindow::on_spinBox_monthB_valueChanged(int month)
{
    ui->spinBox_dayB->setMaximum(Date::getDaysInMonth(month, ui->spinBox_yearB->value()));

    if (ui->spinBox_dayB->value() > Date::getDaysInMonth(month, ui->spinBox_yearB->value()))
    {
        ui->spinBox_dayB->setValue(Date::getDaysInMonth(month, ui->spinBox_yearB->value()));
    }
    updateBirthday();
}

void MainWindow::on_spinBox_yearB_valueChanged(int year)
{
    ui->spinBox_dayB->setMaximum(Date::getDaysInMonth(ui->spinBox_monthB->value(), year));

    if (ui->spinBox_dayB->value() > Date::getDaysInMonth(ui->spinBox_monthB->value(), year))
    {
        ui->spinBox_dayB->setValue(Date::getDaysInMonth(ui->spinBox_monthB->value(), year));
    }
    updateBirthday();
}

