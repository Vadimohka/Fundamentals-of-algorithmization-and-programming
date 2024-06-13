#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firmwindow.h"
#include "workerwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addWorkerButton_clicked()
{
    addWorker.show();
}


void MainWindow::on_addVacancyButton_clicked()
{
    addFirm.show();
}


void MainWindow::on_acceptedVacancyButton_clicked()
{
    QVector<QStringList> vacancyList = addFirm.getVacancyList();
    QVector<QStringList> workersList = addWorker.getWorkersList();
    int numberOfVacancy = vacancyList.length();
    int numberOfWorkers = workersList.length();
    for(int i = 0; i < numberOfVacancy; i++)
    {
        for(int j = 0; j < numberOfWorkers; j++)
        {
            qDebug() << i << j << Qt::endl;
            qDebug() << vacancyList[i][1] << workersList[j][5] << Qt::endl;
            qDebug() << vacancyList[i][3] << workersList[j][4] << Qt::endl;
            qDebug() << vacancyList[i][1] << workersList[j][5] << Qt::endl;
            qDebug() << vacancyList[i][2] << workersList[j][6] << Qt::endl;
            qDebug() << vacancyList[i][7] << workersList[j][8] << Qt::endl;
            int i = addWorker.getAge(j);

            if(vacancyList[i][1] == workersList[j][5] && vacancyList[i][3] == workersList[j][4] && workersList[j][6] <= vacancyList[i][2] && vacancyList[i][7] <= workersList[j][8])
            {
                qDebug() << "is ok";
                QList<QStandardItem*> rowItems;
                qDebug() << "is ok1";
                QStandardItem* item = new QStandardItem(vacancyList[i][0]);
                qDebug() << "is ok2";
                rowItems.append(item);
                qDebug() << "is ok3";
                item = new QStandardItem(workersList[j][0]);
                qDebug() << "is ok4";
                rowItems.append(item);
                qDebug() << "is ok5";
                item = new QStandardItem(workersList[j][1]);
                qDebug() << "is ok6";
                rowItems.append(item);
                qDebug() << "is ok7";
                item = new QStandardItem(workersList[j][2]);
                qDebug() << "is ok8";
                rowItems.append(item);
                qDebug() << "is ok9";
                item = new QStandardItem(vacancyList[i][1]);
                qDebug() << "is ok10";
                rowItems.append(item);
                qDebug() << "is ok11";
                model->appendRow(rowItems);
                qDebug() << "is ok12";
                ui->tableView->setModel(model);
                qDebug() << "is ok13";
                vacancyList[i][8] = "true";
                workersList[j][9] = "true";
            }
        }
    }
}


void MainWindow::on_deficitVacancyButton_clicked()
{

}


void MainWindow::on_deficitWorkerButton_clicked()
{

}

