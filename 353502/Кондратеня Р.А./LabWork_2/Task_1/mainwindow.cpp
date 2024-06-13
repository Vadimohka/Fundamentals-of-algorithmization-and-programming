#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new QTableView;
    model = new QStandardItemModel(0, 4, this);

    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "File Value");
    model->setHeaderData(1, Qt::Horizontal, "Next Day");
    model->setHeaderData(2, Qt::Horizontal, "Difference");
    model->setHeaderData(3, Qt::Horizontal, "Function Result");

    ui->tableView->setColumnWidth(0, 160);
    ui->tableView->setColumnWidth(1, 160);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->spinBox->setMinimum(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_chooseFileButton_clicked()
{
    qDebug() << "Nice1";
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", projDir + "/..", tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "No one file selected.");
        return;
    }

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    QString s;
    //while (!fileStream.atEnd()) {
        //s = fileStream.readLine();
        //qDebug() << s;
        //QDate date = QDate::fromString(s, "dd.MM.yyyy");
            //if (date.isNull()) {
                //QMessageBox::warning(this, "Error", "Error to read information from file / Wrong Format.");
                //file.close();
                //return;
            //}

    //}

    file.close();
    qDebug() << "Nice2";
    getDataFromFile();
}

void MainWindow::getDataFromFile()
{
    if (pathToFile.isEmpty()) return;

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString s;
    do {
        fileStream >> s;
        if (!s.isEmpty()) {
            QDate date = QDate::fromString(s, "dd.MM.yyyy");
            if (!date.isNull()) {
                Date* data = new Date();
                data->setDate(date);
                dateList.append(data);
                qDebug() << "Nice3";
                if (!dateList[numberOfRow]->getDate().toString("dd.MM.yyyy").isEmpty()) {
                    qDebug() << "Nice4";
                    model->insertRow(numberOfRow);
                    qDebug() << "Nice";
                    fillRow(numberOfRow);
                    numberOfRow++;
                    ui->spinBox->setMaximum(numberOfRow);
                }
            }
        }
    } while (!fileStream.atEnd());
    file.close();
}

void MainWindow::fillRow(int numberOfRow)
{
    index = model->index(numberOfRow, 0);
    model->setData(index, dateList[numberOfRow]->getDate());

    index = model->index(numberOfRow, 1);
    model->setData(index, dateList[numberOfRow]->NextDay());

    index = model->index(numberOfRow, 2);
    if(numberOfRow != 0)
        model->setData(index, dateList[numberOfRow]->Duration(dateList[numberOfRow - 1]->getDate()));
    else
        model->setData(index, 0);
    for(int i = 0; i < numberOfRow; i++){
        qDebug() << dateList[i]->getDate();
    }

}

void MainWindow::on_isLeapButton_clicked()
{
    for(int i = 0; i < numberOfRow; i++)
    {
         index = model->index(i, 3);
         model->setData(index, dateList[i]->isLeap());
    }
}


void MainWindow::on_prevDayButton_clicked()
{
    for(int i = 0; i < numberOfRow; i++)
    {
         index = model->index(i, 3);
         model->setData(index, dateList[i]->PreviousDay());
    }
}


void MainWindow::on_weekNumberButton_clicked()
{
    for(int i = 0; i < numberOfRow; i++)
    {
         index = model->index(i, 3);
         model->setData(index, dateList[i]->WeekNumber());
    }
}


void MainWindow::on_addDateButton_clicked()
{
    QDate newDate = ui->newDateEdit->date();
    model->insertRow(numberOfRow);
    Date* date = new Date();
    date->setDate(newDate);
    dateList.append(date);
    fillRow(numberOfRow);
    numberOfRow++;
    ui->spinBox->setMaximum(numberOfRow);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString format = "dd.MM.yyyy";
    fileStream.seek((numberOfRow - 1) * 11 * sizeof(char));
    fileStream << newDate.toString(format) << "\n";
    file.close();
}


void MainWindow::on_changeDateButton_clicked()
{
    int row = ui->spinBox->value() - 1;
    QDate changeDate = ui->changeDateEdit->date();
    Date* date = new Date();
    date->setDate(changeDate);
    dateList[row] = date;
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    fileStream.seek(row * 11 * sizeof(char));
    for (int i = row; i < numberOfRow; i++) {
        fillRow(i);
        fileStream << dateList[i]->getDate().toString() << "\n";
    }
    file.close();
}


void MainWindow::on_countBirthdayButton_clicked()
{
    for(int i = 0; i < numberOfRow; i++)
    {
         index = model->index(i, 3);
         model->setData(index, dateList[i]->DaysTillYourBirthday());
    }
}

