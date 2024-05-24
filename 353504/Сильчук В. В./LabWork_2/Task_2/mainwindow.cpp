#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->hide();
    ui->spinBox_balls->setRange(0, INT_MAX);
    ui->spinBox_ballsEdit->setRange(0, INT_MAX);
    ui->spinBox_points->setRange(0, INT_MAX);
    ui->spinBox_pointsEdit->setRange(0, INT_MAX);
    ui->spinBox_count->setRange(0, 0);
    ui->spinBox_delete->setRange(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    sourseFile = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    QFile file(sourseFile);
    if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {
        QString str = "";
        str = file.readLine();
        qDebug() << str;
        str.remove(str.size() - 1, 1);
        count = str.toInt();
        qDebug() << count;
        if (count) {
            players = new Player[count];
            ui->tableWidget->setRowCount(count);
            ui->spinBox_count->setRange(1, count);
            ui->spinBox_delete->setRange(1, count);

            for (int i = 0; i < count; i++) {
                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setSurname(str);

                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setName(str);

                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setName2(str);

                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setClub(str);

                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setAmplua(str);

                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setBalls(str.toInt());

                str = file.readLine();
                str.remove(str.size() - 1, 1);
                players[i].setPoints(str.toInt());

                ui->tableWidget->setItem(i,
                                         0,
                                         new QTableWidgetItem(players[i].getSurname() + ' '
                                                              + players[i].getName() + ' '
                                                              + players[i].getName2()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem(players[i].getClub()));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem(players[i].getAmplua()));
                ui->tableWidget
                    ->setItem(i, 3, new QTableWidgetItem(QString::number(players[i].getBalls())));
                ui->tableWidget
                    ->setItem(i, 4, new QTableWidgetItem(QString::number(players[i].getPoints())));
            }
            on_spinBox_count_valueChanged(ui->spinBox_count->value());
        } else {
            ui->spinBox_delete->setRange(1, 1);
        }

        ui->tableWidget->horizontalHeader()->show();

        file.close();
    } else {
        QMessageBox::critical(this, "Ошибка!", "Файл не открыт или не существует!");
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (!sourseFile.isEmpty()) {
        QFile file(sourseFile);
        if ((file.exists()) && (file.open(QIODevice::WriteOnly))) {
            file.write(QString::number(count).toStdString().c_str());
            file.write("\n");
            for (int i = 0; i < count; i++) {
                file.write(players[i].getSurname().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getName().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getName2().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getClub().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getAmplua().toStdString().c_str());
                file.write("\n");
                file.write(QString::number(players[i].getBalls()).toStdString().c_str());
                file.write("\n");
                file.write(QString::number(players[i].getPoints()).toStdString().c_str());
                file.write("\n");
            }
            file.close();
        }
    } else {
        QMessageBox::critical(this, "Ошибка!", "Вы не можете сохранить файл без открытия");
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    sourseFile = QFileDialog::getSaveFileName(this, "Save Dialog", "", "*.txt");
    if (!sourseFile.isEmpty()) {
        QFile file(sourseFile);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(QString::number(count).toStdString().c_str());
            file.write("\n");
            for (int i = 0; i < count; i++) {
                file.write(players[i].getSurname().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getName().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getName2().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getClub().toStdString().c_str());
                file.write("\n");
                file.write(players[i].getAmplua().toStdString().c_str());
                file.write("\n");
                file.write(QString::number(players[i].getBalls()).toStdString().c_str());
                file.write("\n");
                file.write(QString::number(players[i].getPoints()).toStdString().c_str());
                file.write("\n");
            }
            file.close();
        }
    } else {
        QMessageBox::critical(this, "Ошибка!", "Вы не можете сохранить файл без открытия");
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    qDebug() << sourseFile;
    if (sourseFile != "") {
        Player *temp = new Player[count + 1];
        if (count) {
            for (int i = 0; i < count; i++) {
                temp[i] = players[i];
            }
            delete[] players;
        }
        qDebug() << 1;
        temp[count].setSurname(ui->lineEdit_surname->text());
        temp[count].setName(ui->lineEdit_name->text());
        temp[count].setName2(ui->lineEdit_name2->text());
        temp[count].setClub(ui->lineEdit_club->text());
        temp[count].setAmplua(ui->lineEdit_amplua->text());
        temp[count].setBalls(ui->spinBox_balls->value());
        temp[count].setPoints(ui->spinBox_points->value());
        qDebug() << 2;

        count++;
        players = temp;
        temp = nullptr;
        qDebug() << 3;

        ui->tableWidget->setRowCount(count);
        showTable();
        ui->spinBox_delete->setMaximum(count);
        ui->spinBox_count->setMaximum(count);
        ui->lineEdit_name->clear();
        ui->lineEdit_surname->clear();
        ui->lineEdit_name2->clear();
        ui->lineEdit_club->clear();
        ui->lineEdit_amplua->clear();
        qDebug() << 4;
        on_spinBox_count_valueChanged(ui->spinBox_delete->value());

    } else {
        QMessageBox::critical(this, "Ошибка!", "Сперва откройте файл");
    }
}

void MainWindow::on_spinBox_count_valueChanged(int number)
{
    ui->lineEdit_nameEdit->setText(players[number - 1].getName());
    ui->lineEdit_surnameEdit->setText(players[number - 1].getSurname());
    ui->lineEdit_name2Edit->setText(players[number - 1].getName2());
    ui->lineEdit_clubEdit->setText(players[number - 1].getClub());
    ui->lineEdit_ampluaEdit->setText(players[number - 1].getAmplua());
    ui->spinBox_ballsEdit->setValue(players[number - 1].getBalls());
    ui->spinBox_pointsEdit->setValue(players[number - 1].getPoints());
}

void MainWindow::on_pushButton_edit_clicked()
{
    if (sourseFile != "" && count) {
        int curr = ui->spinBox_count->value() - 1;
        players[curr].setName(ui->lineEdit_nameEdit->text());
        players[curr].setSurname(ui->lineEdit_surnameEdit->text());
        players[curr].setName2(ui->lineEdit_name2Edit->text());
        players[curr].setClub(ui->lineEdit_clubEdit->text());
        players[curr].setAmplua(ui->lineEdit_ampluaEdit->text());
        players[curr].setBalls(ui->spinBox_ballsEdit->value());
        players[curr].setPoints(ui->spinBox_pointsEdit->value());
        showTable();

    } else {
        if (sourseFile == "") {
            QMessageBox::critical(this, "Ошибка!", "Сперва откройте файл");
        } else {
            QMessageBox::critical(this, "Ошибка!", "Вы не можете изменить несуществующий элемент!");
        }
    }
}

void MainWindow::on_pushButton_delete_clicked()
{
    if (count) {
        int num = ui->spinBox_delete->value() - 1;
        for (int i = num; i < count - 1; i++) {
            players[i] = players[i + 1];
        }

        count--;
        if (count) {
            Player *temp = new Player[count];
            for (int i = 0; i < count; i++) {
                temp[i] = players[i];
            }

            delete[] players;
            players = temp;
            temp = nullptr;
            ui->spinBox_delete->setMaximum(count);
            ui->spinBox_count->setMaximum(count);
            on_spinBox_count_valueChanged(ui->spinBox_delete->value());
        } else {
            ui->lineEdit_nameEdit->clear();
            ui->lineEdit_surnameEdit->clear();
            ui->lineEdit_name2Edit->clear();
            ui->lineEdit_clubEdit->clear();
            ui->lineEdit_ampluaEdit->clear();
            ui->spinBox_ballsEdit->clear();
            ui->spinBox_pointsEdit->clear();
        }

        ui->tableWidget->setRowCount(count);
        showTable();

    } else {
        QMessageBox::critical(this, "Ошибка!", "Вы не можете удалить несуществующий элемент!");
    }
}

void MainWindow::on_pushButto_task1_clicked()
{
    if (count) {
        int *arr = new int[count];
        bool *flag = new bool[count];
        for (int i = 0; i < count; i++) {
            arr[i] = players[i].getBalls() - players[i].getPoints();
            flag[i] = false;
        }

        if (count > TOP) {
            ui->tableWidget->setRowCount(TOP);
        }

        int maxEl = 0, maxElPos = 0, minEl = 0, minElPos = 0;
        for (int i = 0; i < count; i++) {
            maxEl = minEl;
            maxElPos = minElPos;
            for (int j = 0; j < count; j++) {
                if (arr[j] >= maxEl && !flag[j]) {
                    maxEl = arr[j];
                    maxElPos = j;
                }
                if (arr[j] <= minEl) {
                    minEl = arr[j];
                    minElPos = j;
                }
            }
            flag[maxElPos] = true;

            ui->tableWidget->setItem(i,
                                     0,
                                     new QTableWidgetItem(players[maxElPos].getSurname() + ' '
                                                          + players[maxElPos].getName() + ' '
                                                          + players[maxElPos].getName2()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(players[maxElPos].getClub()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(players[maxElPos].getAmplua()));
            ui->tableWidget->setItem(i,
                                     3,
                                     new QTableWidgetItem(
                                         QString::number(players[maxElPos].getBalls())));
            ui->tableWidget->setItem(i,
                                     4,
                                     new QTableWidgetItem(
                                         QString::number(players[maxElPos].getPoints())));

            if (i == TOP - 1) {
                break;
            }
        }

        delete[] flag;
        flag = nullptr;
        delete[] arr;
        arr = nullptr;
    } else {
        QMessageBox::critical(this, "Ошибка!", "Нет ни одного элемента!");
    }
}

void MainWindow::on_pushButton_task2_clicked()
{
    if (count) {
        bool *flag = new bool[count];
        for (int i = 0; i < count; i++) {
            flag[i] = false;
        }

        if (count > TOP) {
            ui->tableWidget->setRowCount(TOP);
        }

        int maxEl = 0, maxElPos = 0, minEl = 0, minElPos = 0;
        for (int i = 0; i < count; i++) {
            maxEl = minEl;
            maxElPos = minElPos;
            for (int j = 0; j < count; j++) {
                if (players[j].getPoints() >= maxEl && !flag[j]) {
                    maxEl = players[j].getPoints();
                    maxElPos = j;
                }
                if (players[j].getPoints() <= minEl) {
                    minEl = players[j].getPoints();
                    minElPos = j;
                }
            }
            flag[maxElPos] = true;

            ui->tableWidget->setItem(i,
                                     0,
                                     new QTableWidgetItem(players[maxElPos].getSurname() + ' '
                                                          + players[maxElPos].getName() + ' '
                                                          + players[maxElPos].getName2()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(players[maxElPos].getClub()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(players[maxElPos].getAmplua()));
            ui->tableWidget->setItem(i,
                                     3,
                                     new QTableWidgetItem(
                                         QString::number(players[maxElPos].getBalls())));
            ui->tableWidget->setItem(i,
                                     4,
                                     new QTableWidgetItem(
                                         QString::number(players[maxElPos].getPoints())));

            if (i == TOP - 1) {
                break;
            }
        }

        delete[] flag;
        flag = nullptr;
    } else {
        QMessageBox::critical(this, "Ошибка!", "Нет ни одного элемента!");
    }
}

void MainWindow::on_pushButton_task3_clicked()
{
    if (count) {
        Player::sortBalls(players, count);
        showTable();
    } else {
        QMessageBox::critical(this, "Ошибка!", "Нет ни одного элемента!");
    }
}

void MainWindow::on_pushButton_show_clicked()
{
    showTable();
}

void MainWindow::showTable()
{
    ui->tableWidget->setRowCount(count);
    for (int i = 0; i < count; i++) {
        ui->tableWidget->setItem(i,
                                 0,
                                 new QTableWidgetItem(players[i].getSurname() + ' '
                                                      + players[i].getName() + ' '
                                                      + players[i].getName2()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(players[i].getClub()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(players[i].getAmplua()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(players[i].getBalls())));
        ui->tableWidget->setItem(i,
                                 4,
                                 new QTableWidgetItem(QString::number(players[i].getPoints())));
    }
}
