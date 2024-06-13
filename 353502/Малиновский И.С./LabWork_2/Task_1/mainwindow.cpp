#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->bithdayLine->setPlaceholderText("Введите дату дня рождения");
    ui->difDateLine->setPlaceholderText("Введите дату для разницы");
    ui->addDateLine->setPlaceholderText("Введите дату для добавления");

    ui->tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
    QObject::connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::cellEdited);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable()
{
    ui->tableWidget->blockSignals(true);

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(dates.size());
    for (int i=0; i<dates.size(); i++)
    {
        qDebug() << dates[i].ConvertToString();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dates[i].ConvertToString()));
        ui->tableWidget->item(i, 0)->setFlags(ui->tableWidget->item(i, 0)->flags() | Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ConvertToString()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ConvertToString()));
        if (dates[i].isValid())
        {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(dates[i].IsLeap() ? "Да" : "Нет"));
        }
        else
        {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("-"));
        }
        if (dates[i].isValid())
        {
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(dates[i].WeekNumber())));
        }
        else
        {
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem("-"));
        }
        if (bithdayDate.isValid() && dates[i].isValid())
        {
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(dates[i].DaysTillYourBithday(bithdayDate))));
        }
        else
        {
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem("-"));
        }
        if (differenceDate.isValid() && dates[i].isValid())
        {
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(dates[i].Duration(differenceDate))));
        }
        else
        {
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem("-"));
        }

        for (int j=1; j<7; j++)
        {
            ui->tableWidget->item(i, j)->setFlags(ui->tableWidget->item(i, j)->flags() & ~Qt::ItemIsEditable);
        }
    }

    ui->tableWidget->blockSignals(false);

}

void MainWindow::on_loadFile_clicked()
{
    projFile.convertFromFile(this, dates);
    updateTable();
}


void MainWindow::on_saveFile_clicked()
{
    projFile.convertToFile(this, dates);
}


void MainWindow::on_updateDate_clicked()
{
    Date date;
    QString str = ui->bithdayLine->text();
    date.ConvertToDate(str);
    if (!date.isValid())
    {
        QMessageBox::warning(nullptr, "Дата дня рождения", "Дата введена неправильно");
        return;
    }
    bithdayDate.ConvertToDate(str);
    updateTable();
}


void MainWindow::on_updateDifDate_clicked()
{
    Date date;
    QString str = ui->difDateLine->text();
    date.ConvertToDate(str);
    if (!date.isValid())
    {
        QMessageBox::warning(nullptr, "Дата", "Дата введена неправильно");
    }
    differenceDate.ConvertToDate(str);
    updateTable();
}


void MainWindow::on_addDate_clicked()
{
    Date date;
    QString str = ui->addDateLine->text();
    date.ConvertToDate(str);
    if (!date.isValid())
    {
        QMessageBox::warning(nullptr, "Дата для добавления", "Дата введена неправильно");
    }
    dates.push_back(date);
    updateTable();
}

void MainWindow::cellEdited(int row, int column)
{
    QFlags <QAbstractItemView::EditTrigger> triggers = ui->tableWidget->editTriggers();

    if (triggers & QAbstractItemView::EditKeyPressed) {
        qDebug() << "OK";
        dates[row].ConvertToDate(ui->tableWidget->item(row, column)->text());
        updateTable();
    }
}

void MainWindow::on_deleteDate_clicked()
{
    if (ui->tableWidget->currentRow() == -1)
    {
        QMessageBox::warning(nullptr, "Удаление даты", "Строка не выбрана");
        return;
    }

    int ind = ui->tableWidget->currentRow();
    dates.erase(dates.begin() + ind);

    updateTable();
}

