#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(nCol);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "дата"
                                                             << "следующий день"
                                                             << "предыдущий день"
                                                             << "разница между текущей датой и заданной"
                                                             << "разница между твоим днем рождения и заданной датой"
                                                             << "номер недели");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    //ui->tableWidget->hideColumn(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    path = QFileDialog::getOpenFileName(nullptr, "Выберите .txt файл", QDir::homePath(), "Текстовые файлы (*.txt)");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    //QString strn = file.read(1);
    //int oldN = n;
    //n+=strn.toInt();
    int i=0;
    while (true) {
            //qDebug() << 1;
            str = file.read(dateSize);
            if (str == "-1.-1.-111") {
                break;
        }
        ui->tableWidget->insertRow(i);
        currDate = Date(str);
        //qDebug() << currDate.date;
        arr.push_back(currDate);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(currDate.date));
        //ui->tableWidget->setItem(i, 1, new QTableWidgetItem(currDate.NextDay().date));
            //ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(currDate.Duration(today))));
        i++;
        //qDebug() << today.date << currDate.NextDay().date << currDate.Duration(today);
    }
    n=i;
    file.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    currRow = ui->tableWidget->currentRow();
    if (currRow!=-1) {
        currDate = arr[currRow];
        ui->tableWidget->setItem(currRow, 1, new QTableWidgetItem(currDate.NextDay().date));
        //ui->tableWidget->removeRow(currRow);
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    currRow = ui->tableWidget->currentRow();
    if (currRow!=-1) {
        currDate = arr[currRow];
        ui->tableWidget->setItem(currRow, 2, new QTableWidgetItem(currDate.PreviousDay().date));
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    currRow = ui->tableWidget->currentRow();
    if (currRow!=-1) {
        currDate = arr[currRow];
        ui->tableWidget->setItem(currRow, 3, new QTableWidgetItem(QString::number(currDate.Duration(today))));
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    currRow = ui->tableWidget->currentRow();
    if (currRow!=-1) {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setText("Введите дату др");
        typeAct = 1;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    currRow = ui->tableWidget->currentRow();
    if (currRow!=-1) {
        currDate = arr[currRow];
        ui->tableWidget->setItem(currRow,
                                 five,
                                 new QTableWidgetItem(QString::number(currDate.WeekNumber())));
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    currRow = ui->tableWidget->currentRow();
    if (currRow!=-1) {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setText("Введите дату");
        typeAct = 2;
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    //currRow = ui->tableWidget->currentRow();
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setText("Введите дату");
    typeAct = 3;
}


void MainWindow::on_pushButton_9_clicked()
{
    if (typeAct==1) {
        birthday = Date(ui->lineEdit->text());
        if (birthday.error) {
            form.show();
        } else {
            currDate = arr[currRow];
            ui->tableWidget->setItem(currRow, 4, new QTableWidgetItem(QString::number(currDate.DaysTillYourBirthday(birthday))));
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }
    }
    if (typeAct==2) {
        currDate = Date(ui->lineEdit->text());
        if (currDate.error) {
            form.show();
        } else {
            QFile file(path);
            file.open(QIODevice::WriteOnly);
            arr[currRow] = currDate;
            qDebug() << currDate.date;
            ui->tableWidget->setItem(currRow, 0, new QTableWidgetItem(currDate.date));
            ui->tableWidget->setItem(currRow, 1, new QTableWidgetItem(""));
            ui->tableWidget->setItem(currRow, 2, new QTableWidgetItem(""));
            ui->tableWidget->setItem(currRow, 3, new QTableWidgetItem(""));
            ui->tableWidget->setItem(currRow, 4, new QTableWidgetItem(""));
            ui->tableWidget->setItem(currRow, five, new QTableWidgetItem(""));
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            //qDebug() << c;
            //01.01.000124.04.200029.02.200031.12.2021-1.-1.-111

            for (int i=0;i<n;i++) {
                for (auto &j: arr[i].date) {
                    //char *c = new char[1];
                    c[0] = j.unicode()-zero.unicode()+'0';
                    //qDebug() << c;
                    file.write(c,1);
                }
            }
            str = "-1.-1.-111";
            for (auto &j: str) {
                c[0] = j.unicode()-zero.unicode()+'0';
                file.write(c,1);
            }
            file.close();
        }
    }
    if (typeAct==3) {
        currDate = Date(ui->lineEdit->text());
        if (currDate.error) {
            form.show();
        } else {
            QFile file(path);
            file.open(QIODevice::WriteOnly);
            //arr[currRow] = currDate;
            n++;currRow=n-1;
            qDebug() << currRow;
            arr.push_back(currDate);
            ui->tableWidget->insertRow(n-1);
            ui->tableWidget->setItem(currRow, 0, new QTableWidgetItem(currDate.date));
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            for (int i=0;i<n;i++) {
                for (auto &j: arr[i].date) {
                    //char *c = new char[1];
                    c[0] = j.unicode()-zero.unicode()+'0';
                    //qDebug() << c;
                    file.write(c,1);
                }
            }
            str = "-1.-1.-111";
            for (auto &j: str) {
                c[0] = j.unicode()-zero.unicode()+'0';
                file.write(c,1);
            }
            file.close();
        }
    }
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setText("");
    ui->lineEdit->setText("");
    typeAct = 0;
}

