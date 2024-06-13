#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    company = readFile(fileName);
    //this->createUI(QStringList() << ("Название") << ("Задание") << ("Сотрудник") << ("Руководитель")
    //                             << ("Дата начала") << ("Дата сдачи") << ("Срок выполнения"));
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << ("Название") << ("Задание") << ("Сотрудник") << ("Руководитель")
                      << ("Дата начала") << ("Дата сдачи") << ("Срок выполнения"));
    createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createUI()
{
    /*ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
*/

    int n = company.size();
    ui->tableWidget->setRowCount(n);

    for (int i = 0; i < n; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(company[i]->nameProject));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(company[i]->zadanie));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(company[i]->sotrydnikFIO));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(company[i]->rykovoditelFIO));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(company[i]->dateOfBegin));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(company[i]->dateOfDone));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(company[i]->deadLine)));
    }
}

QVector<Work *> MainWindow::readFile(QString fileName)
{
    QFile file(fileName);
    QVector<Work *> company;
    //QList<Work*>*company = new QList<Work*>;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        QString in;
        while (!stream.atEnd()) {
            in = stream.readLine();
            Work *firma = new Work(in);

            company.push_back(firma);
            //in = stream.readLine();
        }
        file.close();
    }
    return company;
}

void MainWindow::sortByRykovoditel(QString nameRykovoditel)
{
    //nameRykovoditel = ui->lineEdit->text();
    for (int i = 0; i < company.size(); ++i) {
        if (company[i]->rykovoditelFIO != nameRykovoditel) {
            ui->tableWidget->setRowHidden(i, true);
        }
        if (company[i]->rykovoditelFIO == nameRykovoditel) {
            ui->tableWidget->setRowHidden(i, false);
            ui->tableWidget->setColumnHidden(0, false);
            ui->tableWidget->setColumnHidden(1, true);
            ui->tableWidget->setColumnHidden(2, false);
            ui->tableWidget->setColumnHidden(3, true);
            ui->tableWidget->setColumnHidden(4, true);
            ui->tableWidget->setColumnHidden(5, true);
            ui->tableWidget->setColumnHidden(6, true);
        }
    }
}

void MainWindow::sortBySotrydnik(QString nameSotrydnik)
{
    for (int i = 0; i < company.size(); ++i) {
        if (company[i]->sotrydnikFIO != nameSotrydnik)
            ui->tableWidget->setRowHidden(i, true);
        if (company[i]->sotrydnikFIO == nameSotrydnik) {
            ui->tableWidget->setRowHidden(i, false);
            ui->tableWidget->setColumnHidden(0, true);
            ui->tableWidget->setColumnHidden(1, false);
            ui->tableWidget->setColumnHidden(2, false);
            ui->tableWidget->setColumnHidden(3, true);
            ui->tableWidget->setColumnHidden(4, true);
            ui->tableWidget->setColumnHidden(5, true);
            ui->tableWidget->setColumnHidden(6, true);
        }
    }
}

void MainWindow::sortByproject(QString nameOfproject)
{
    for (int i = 0; i < company.size(); ++i) {
        if (company[i]->nameProject != nameOfproject)
            ui->tableWidget->setRowHidden(i, true);
        if (company[i]->nameProject == nameOfproject) {
            ui->tableWidget->setRowHidden(i, false);
            ui->tableWidget->setColumnHidden(0, false);
            ui->tableWidget->setColumnHidden(1, true);
            ui->tableWidget->setColumnHidden(2, false);
            ui->tableWidget->setColumnHidden(3, true);
            ui->tableWidget->setColumnHidden(4, true);
            ui->tableWidget->setColumnHidden(5, true);
            ui->tableWidget->setColumnHidden(6, true);
        }
    }
}

void MainWindow::sortBySrok()
{
    for (int i = 0; i < company.size(); ++i) {
        int dateBeginDay = company[i]->dateOfBegin.mid(0, 2).toInt();
        int dateBeginMonth = company[i]->dateOfBegin.mid(3, 2).toInt();
        int dateBeginYear = company[i]->dateOfBegin.mid(5, 4).toInt();
        int dateEndDay = company[i]->dateOfDone.mid(0, 2).toInt();
        int dateEndMonth = company[i]->dateOfDone.mid(3, 2).toInt();
        int dateEndYear = company[i]->dateOfDone.mid(5, 4).toInt();
        int srok = company[i]->deadLine;
        for (int j = 0; j < dateEndMonth; ++j) {
            if (dateEndMonth == 1 || dateEndMonth == 3 || dateEndMonth == 5 || dateEndMonth == 7
                || dateEndMonth == 8 || dateEndMonth == 10 || dateEndMonth == 12)
                dateEndDay += 31;
            else if (dateEndMonth == 4 || dateEndMonth == 6 || dateEndMonth == 9
                     || dateEndMonth == 11)
                dateEndDay += 30;
            else {
                if (dateEndYear % 4 == 0 || dateEndYear % 400 == 0) {
                    dateEndDay += 29;
                } else
                    dateEndDay += 28;
            }
        }
        for (int k = 0; k < dateBeginMonth; ++k) {
            if (dateBeginMonth == 1 || dateBeginMonth == 3 || dateBeginMonth == 5
                || dateBeginMonth == 7 || dateBeginMonth == 8 || dateBeginMonth == 10
                || dateBeginMonth == 12)
                dateBeginDay += 31;
            else if (dateBeginMonth == 4 || dateBeginMonth == 6 || dateBeginMonth == 9
                     || dateBeginMonth == 11)
                dateBeginDay += 30;
            else {
                if (dateBeginYear % 4 == 0 || dateBeginYear % 400 == 0) {
                    dateBeginDay += 29;
                } else
                    dateBeginDay += 28;
            }
        }
        if (dateEndYear < dateBeginYear)
            company.remove(i, 1);
        if (dateEndYear > dateBeginYear) {
            dateEndDay = 365 * (dateEndYear - dateBeginYear);
        }
        srok = dateEndDay - (dateBeginDay + srok);
        if (srok >= 0) {
            ui->tableWidget->setRowHidden(i, false);
            ui->tableWidget->setColumnHidden(0, true);
            ui->tableWidget->setColumnHidden(1, true);
            ui->tableWidget->setColumnHidden(2, false);
            ui->tableWidget->setColumnHidden(3, true);
            ui->tableWidget->setColumnHidden(4, false);
            ui->tableWidget->setColumnHidden(5, false);
            ui->tableWidget->setColumnHidden(6, false);
        } else
            ui->tableWidget->setRowHidden(i, true);
    }
}

void MainWindow::on_pushButton_clicked()
{
    sortByRykovoditel(ui->lineEdit->text());
}

void MainWindow::on_otmenaButton_clicked()
{
    for (int i = 0; i < company.size(); ++i) {
        ui->tableWidget->setRowHidden(i, false);
    }
    ui->tableWidget->setColumnHidden(0, false);
    ui->tableWidget->setColumnHidden(1, false);
    ui->tableWidget->setColumnHidden(2, false);
    ui->tableWidget->setColumnHidden(3, false);
    ui->tableWidget->setColumnHidden(4, false);
    ui->tableWidget->setColumnHidden(5, false);
    ui->tableWidget->setColumnHidden(6, false);
}

void MainWindow::on_zadanieButton_clicked()
{
    sortBySotrydnik(ui->lineEdit->text());
}

void MainWindow::on_projectButton_clicked()
{
    sortByproject(ui->lineEdit->text());
}

void MainWindow::on_srokButton_clicked()
{
    sortBySrok();
}
