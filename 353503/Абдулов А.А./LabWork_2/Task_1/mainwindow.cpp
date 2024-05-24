#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression>
#include <QFileDialog>
#include <QMessageBox>

constexpr qint16 sizeOfDateStr = 11;

enum Columns
{
    Zero = 0,
    First,
    Second,
    Third,
    Fourth,
    Fifth
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->show();
    regex = QRegularExpression(R"((\d{2})\.(\d{2})\.(\d{4}))");

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->choose_file_button, SIGNAL(clicked()), this, SLOT(ChooseFile()));
    // connect(ui->ok_birthday_button, SIGNAL(clicked()), this, SLOT(AddBirthdayToTable()));
    connect(ui->add_date_button, SIGNAL(clicked()), this, SLOT(AddToFile()));
    connect(ui->ok_date_button, SIGNAL(clicked()), this, SLOT(EditFile()));
    connect(ui->delete_button, SIGNAL(clicked()), this, SLOT(Delete()));
}

MainWindow::~MainWindow() {
    delete ui;
    dates.clear();
    dates.shrink_to_fit();
}

void MainWindow::ChooseFile() {
    filepath = QFileDialog::getOpenFileName(this, "Open file", "", "Text files (*.txt)");
    if (!filepath.isEmpty()) {
        readFromFile(filepath);
    }
}

void MainWindow::readFromFile(const QString &filepath) {
    ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());

    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QRegularExpressionMatch match = regex.match(line);
        if (match.hasMatch()) {
            int day = match.captured(1).toInt();
            int month = match.captured(2).toInt();
            int year = match.captured(3).toInt();

            if (Date::IsValidDate(day, month, year)) {
                Date date(day, month, year);
                dates.push_back(date);
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                ShowInTable(dates.last(), ui->tableWidget->rowCount());
            } else {
                auto str = Date(day, month, year).ToString();
                QMessageBox::warning(this, "Warning", "Invalid date " + str + " format in file!");
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Invalid date format in file!");
        }
    }
    file.close();
}

void MainWindow::FillRowComboBox()
{
    ui->rowToEdit_comboBox->clear();
    ui->rowToDel_comboBox->clear();
    for (int i = 1; i <= ui->tableWidget->rowCount(); ++i)
    {
        ui->rowToEdit_comboBox->addItem(QString::number(i));
    }

    for (int i = 1; i <= ui->tableWidget->rowCount(); ++i)
    {
        ui->rowToDel_comboBox->addItem(QString::number(i));
    }
}

void MainWindow::ShowInTable(Date date, int rowNum) {

    auto *dateItem = new QTableWidgetItem(date.ToString());
    dateItem->setTextAlignment(Qt::AlignRight);
    dateItem->setFlags(dateItem->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(rowNum - 1, Columns::Zero, dateItem);

    auto *nextDayItem = new QTableWidgetItem(date.NextDay().ToString());
    nextDayItem->setTextAlignment(Qt::AlignRight);
    nextDayItem->setFlags(nextDayItem->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(rowNum - 1, Columns::First, nextDayItem);

    auto *previousDayItem = new QTableWidgetItem(date.PreviousDay().ToString());
    previousDayItem->setTextAlignment(Qt::AlignRight);
    previousDayItem->setFlags(previousDayItem->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(rowNum - 1, Columns::Second, previousDayItem);

    auto *weekNumberItem = new QTableWidgetItem(QString::number(date.WeekNumber()));
    weekNumberItem->setTextAlignment(Qt::AlignRight);
    weekNumberItem->setFlags(weekNumberItem->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(rowNum - 1, Columns::Third, weekNumberItem);

    auto *durationItem = new QTableWidgetItem(QString::number(Date::Duration(date)));
    durationItem->setTextAlignment(Qt::AlignRight);
    durationItem->setFlags(durationItem->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(rowNum - 1, Columns::Fourth, durationItem);

    auto *birthdayItem = new QTableWidgetItem(QString::number(Date::DaysTillYourBirthday(date)));
    birthdayItem->setTextAlignment(Qt::AlignRight);
    birthdayItem->setFlags(durationItem->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(rowNum - 1, Columns::Fifth, birthdayItem);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    FillRowComboBox();
}

void MainWindow::AddToFile() {
    if (ui->add_date_edit->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Fill in field!");
        return;
    }

    if (!filepath.isEmpty()) {
        QRegularExpressionMatch match = regex.match(ui->add_date_edit->text());

        QFile file(filepath);
        if (!file.open(QIODevice::Text | QIODevice::Append)) {
            return;
        }

        if (match.hasMatch()) {
            int day = match.captured(1).toInt();
            int month = match.captured(2).toInt();
            int year = match.captured(3).toInt();

            if (Date::IsValidDate(day, month, year)) {
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                Date tmp(day, month, year);
                dates.push_back(tmp);
                ShowInTable(tmp, ui->tableWidget->rowCount());

                QTextStream out(&file);
                out << ui->add_date_edit->text();

            } else {
                QMessageBox::warning(this, "Warning", "This date doesn't exist");
            }

            ui->add_date_edit->clear();
        } else {
            ui->add_date_edit->clear();
            QMessageBox::warning(this, "Warning", "Incorrect date format");
        }

        file.close();
    } else {
        ui->add_date_edit->clear();
        QMessageBox::warning(this, "Warning", "File isn't selected");
    }
}

void MainWindow::Delete()
{
    int row = ui->rowToDel_comboBox->currentText().toInt();
    if (!filepath.isEmpty()) {
        QFile file(filepath);
        if (!file.open(QIODevice::Text | QIODevice::ReadWrite)) {
            return;
        }

        QTextStream in(&file);
        QStringList lines;
        while (!in.atEnd())
        {
            lines.append(in.readLine());
        }

        lines.removeAt(row - 1);

        file.resize(0);

        QTextStream out(&file);
        for (const QString &line : lines)
        {
            out << line << "\n";
        }
        file.close();

        dates.removeAt(row - 1);

        readFromFile(filepath);

        file.close();
    } else {
        QMessageBox::warning(this, "Warning", "File isn't selected");
    }

}


void MainWindow::EditFile() {

    qint16 row = ui->rowToEdit_comboBox->currentText().toInt();

    if (!filepath.isEmpty()) {
        QRegularExpressionMatch match = regex.match(ui->newDate_edit->text());

        QFile file(filepath);
        if (!file.open(QIODevice::Text | QIODevice::ReadWrite)) {
            return;
        }

        if (match.hasMatch()) {
            int day = match.captured(1).toInt();
            int month = match.captured(2).toInt();
            int year = match.captured(3).toInt();

            if (Date::IsValidDate(day, month, year)) {
                file.seek(((row - 1) * static_cast<size_t>(sizeOfDateStr) * sizeof(char)));
                QTextStream out(&file);
                out << ui->newDate_edit->text();

                dates[row - 1].setDay(day);
                dates[row - 1].setMonth(month);
                dates[row - 1].setYear(year);

                ShowInTable(dates[row - 1], row);
            } else {
                QMessageBox::warning(this, "Warning", "This date doesn't exist");
            }
        } else {
            QMessageBox::warning(this, "Warning", "Incorrect data format");
        }

        ui->newDate_edit->clear();
        file.close();
    } else {
        ui->newDate_edit->clear();
        QMessageBox::warning(this, "Warning", "File isn't selected");
    }

}

void MainWindow::changeEvent(QEvent * e) {
    if(e->type() == QEvent::ActivationChange && this->isActiveWindow()) {
        if(filepath != ""){
            readFromFile(filepath);
        }
    }
}
