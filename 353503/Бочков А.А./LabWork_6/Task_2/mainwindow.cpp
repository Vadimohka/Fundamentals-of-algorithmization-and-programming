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

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("Введите абзац");
    typeact = 1;
    ui->textEdit_2->clear();
    ui->pushButton_7->setEnabled(true);
    ui->textEdit->setEnabled(true);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText("Введите количество элементов");
    typeact = 2;
    typeinput = 1;
    ui->textEdit_2->clear();
    ui->pushButton_7->setEnabled(true);
    ui->textEdit->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("Введите количество работников");
    typeact = 3;
    typeinput = 0;
    ui->textEdit_2->clear();
    ui->textEdit->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText("Введите количество работников");
    typeact = 4;
    typeinput = 0;
    ui->textEdit_2->clear();
    ui->textEdit->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("Введите предложение");
    typeact = 5;
    ui->textEdit_2->clear();
    ui->textEdit->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_7_clicked()
{
    switch (typeact) {
    case 1: {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Text"),
                                                        "",
                                                        tr("Text Files (*.txt)"));
        QFile file(fileName);
        file.open(QFile::WriteOnly);
        for (QChar c : ui->textEdit->toPlainText()) {
            file.write((const char *) &c, sizeof(QChar));
        }
        file.close();

        ui->textEdit->clear();

        //fileName = QFileDialog::getOpenFileName(this, tr("Save Text"), "", tr("Text Files (*.txt)"));
        //QFile file1(fileName);
        file.open(QFile::ReadOnly);

        res = "";
        while (!file.atEnd()) {
            file.read((char *) &c, sizeof(QChar));
            res += c;
        }

        ui->textEdit_2->setText(res);
        ui->lineEdit->clear();
        ui->textEdit->setEnabled(false);
        file.close();
        break;
    }
    case 2: {
        if (typeinput == 1) {
            n = ui->textEdit->toPlainText().toInt();
            ui->textEdit->clear();
            ui->lineEdit->setText("Введите следующий элемент");
            typeinput++;
        } else {
            arr[typeinput - 2] = ui->textEdit->toPlainText().toDouble();
            ui->textEdit->clear();
            typeinput++;
            if (typeinput == n + 2) {
                QString fileName = QFileDialog::getSaveFileName(this,
                                                                tr("Save Text"),
                                                                "",
                                                                tr("Text Files (*.txt)"));
                QFile file(fileName);
                file.open(QFile::WriteOnly);

                QTextStream out(&file);

                for (int i = 0; i < n; i++) {
                    //QSpinBox *spinbox = (QSpinBox *)ui->mainTable->cellWidget(i, 0);
                    if (i != 0)
                        out << "#";
                    //qDebug() << arr[i];
                    out << arr[i];
                }
                file.close();
                //fileName = QFileDialog::getOpenFileName(this,
                //                                      tr("Save Text"),
                //                                    "",
                //                                 tr("Text Files (*.txt)"));
                //QFile file1(fileName);
                file.open(QFile::ReadOnly);

                res = "";
                QTextStream inp(&file);
                while (!inp.atEnd()) {
                    double inNum;
                    inp >> inNum;
                    res += QString::number(inNum) + " ";
                    QChar sep;
                    inp >> sep;
                }
                ui->lineEdit->clear();
                file.close();
                ui->textEdit_2->setText(res);
                ui->textEdit->setEnabled(false);
            }
        }
        break;
    }
    case 3: {
        //qDebug() << typeinput;
        switch (typeinput) {
        case 0: {
            MyFactory.workers_amount = ui->textEdit->toPlainText().toInt();
            typeinput = 1;
            //qDebug() << MyFactory.workers_amount;
            ui->lineEdit->setText("Введите зарплату");
            ui->textEdit->clear();
            break;
        }
        case 1: {
            //qDebug() << typeinput;
            MyFactory.salary = ui->textEdit->toPlainText().toDouble();
            typeinput = 2;
            ui->lineEdit->setText("Введите заглавный символ предприятия");
            ui->textEdit->clear();
            break;
        }
        case 2: {
            MyFactory.first_letter = ui->textEdit->toPlainText()[0];
            typeinput = 3;
            ui->lineEdit->setText("Введите, работает ли завод(да или нет)");
            ui->textEdit->clear();
            break;
        }
        case 3: {
            input = ui->textEdit->toPlainText();
            if (input == "да") {
                MyFactory.work = true;
            } else {
                MyFactory.work = false;
            }
            typeinput = 4;
            ui->lineEdit->setText("Введите название завода");
            ui->textEdit->clear();
            break;
        }
        case 4: {
            MyFactory.name = ui->textEdit->toPlainText();
            typeinput = 5;
            ui->lineEdit->setText("Введите возраст следующего работника");
            ui->textEdit->clear();
            break;
        }
        default: {
            MyFactory.workers_age[typeinput - 5] = ui->textEdit->toPlainText().toInt();
            typeinput++;
            if (typeinput - 5 == MyFactory.workers_amount) {
                ui->lineEdit->clear();
                QString fileName = QFileDialog::getSaveFileName(this,
                                                                tr("Save Text"),
                                                                "",
                                                                tr("Text Files (*.txt)"));
                QFile file(fileName);
                file.open(QFile::Append);

                QTextStream out(&file);
                out << MyFactory.workers_amount << "\n";
                out << MyFactory.salary << "\n";
                out << MyFactory.first_letter << "\n";
                out << (MyFactory.work ? "yes" : "no") << "\n";
                out << MyFactory.name << "\n";
                for (int i = 0; i < MyFactory.workers_amount; i++) {
                    out << MyFactory.workers_age[i] << "\n";
                }
                out << "\n";

                file.close();

                //fileName = QFileDialog::getOpenFileName(this, tr("Open Text"), "",
                //                                              tr("Text Files (*.txt)"));
                //file(fileName);
                file.open(QFile::ReadOnly);

                QTextStream inp(&file);
                while (!inp.atEnd()) {
                    QString name;
                    //int amount;
                    inp >> MyFactory.workers_amount;
                    qDebug() << MyFactory.workers_amount;
                    //double salary;
                    inp >> MyFactory.salary;
                    qDebug() << MyFactory.salary;
                    QChar ch;
                    // READ TWICE TO SKIP NEWLINE
                    inp >> ch >> MyFactory.first_letter;
                    qDebug() << MyFactory.first_letter;
                    //long long evilN = 0;
                    name = inp.readLine();
                    name = inp.readLine();
                    qDebug() << name;
                    if (name == "yes") {
                        MyFactory.work = true;
                    } else {
                        MyFactory.work = false;
                    }

                    MyFactory.name = inp.readLine();
                    qDebug() << MyFactory.name;
                    //bool evil = evilN == 0;
                    workers_age = "\nВозраста всех раюотников: ";
                    for (int i = 0; i < MyFactory.workers_amount; i++) {
                        inp >> MyFactory.workers_age[i];
                        workers_age += QString::number(MyFactory.workers_age[i]) + " ";
                    }
                    qDebug() << "\n" << workers_age;
                    QChar skip;
                    inp >> skip >> skip;
                    //qDebug() << MyFactory.workers_amount << MyFactory.name;
                    ui->textEdit_2->append(
                        "Количество работников: " + QString::number(MyFactory.workers_amount)
                        + "\nИх зарплата: " + QString::number(MyFactory.salary)
                        + "\nЗаглавный символ предприятия: " + MyFactory.first_letter
                        + "\nПравда ли, что сейчас завод работает: "
                        + (MyFactory.work ? "Да" : "Нет")
                        + "\nНазвание предприятия: " + MyFactory.name + workers_age + "\n");
                }

                file.close();
                ui->lineEdit->clear();
                //ui->textEdit_2->setText(res);
                ui->textEdit->setEnabled(false);
            }
            ui->textEdit->clear();
            break;
        }
        }
        break;
    }
    case 4: {
        //qDebug() << typeinput;
        switch (typeinput) {
        case 0: {
            MyFactory.workers_amount = ui->textEdit->toPlainText().toInt();
            typeinput = 1;
            ui->lineEdit->setText("Введите зарплату");
            ui->textEdit->clear();
            break;
        }
        case 1: {
            qDebug() << typeinput;
            MyFactory.salary = ui->textEdit->toPlainText().toDouble();
            typeinput = 2;
            ui->lineEdit->setText("Введите заглавный символ предприятия");
            ui->textEdit->clear();
            break;
        }
        case 2: {
            MyFactory.first_letter = ui->textEdit->toPlainText()[0];
            typeinput = 3;
            ui->lineEdit->setText("Введите, работает ли завод(да или нет)");
            ui->textEdit->clear();
            break;
        }
        case 3: {
            input = ui->textEdit->toPlainText();
            if (input == "да") {
                MyFactory.work = true;
            } else {
                MyFactory.work = false;
            }
            typeinput = 4;
            ui->lineEdit->setText("Введите название завода");
            ui->textEdit->clear();
            break;
        }
        case 4: {
            MyFactory.name = ui->textEdit->toPlainText();
            typeinput = 5;
            ui->lineEdit->setText("Введите возраст следующего работника");
            ui->textEdit->clear();
            break;
        }
        default: {
            MyFactory.workers_age[typeinput - 5] = ui->textEdit->toPlainText().toInt();
            typeinput++;
            if (typeinput - 5 == MyFactory.workers_amount) {
                ui->lineEdit->clear();
                QString fileName = QFileDialog::getSaveFileName(this,
                                                                tr("Binary Data"),
                                                                "",
                                                                tr("Binary Data (*.bin)"));
                QFile file(fileName);
                file.open(QFile::Append);

                QTextStream out(&file);
                out << MyFactory.workers_amount << "\n";
                out << MyFactory.salary << "\n";
                out << MyFactory.first_letter << "\n";
                out << (MyFactory.work ? "yes" : "no") << "\n";
                out << MyFactory.name << "\n";
                for (int i = 0; i < MyFactory.workers_amount; i++) {
                    out << MyFactory.workers_age[i] << "\n";
                }
                out << "\n";

                file.close();

                file.open(QFile::ReadOnly);

                QTextStream inp(&file);
                while (!inp.atEnd()) {
                    QString name;
                    //int amount;
                    inp >> MyFactory.workers_amount;
                    qDebug() << MyFactory.workers_amount;
                    //double salary;
                    inp >> MyFactory.salary;
                    qDebug() << MyFactory.salary;
                    QChar ch;
                    // READ TWICE TO SKIP NEWLINE
                    inp >> ch >> MyFactory.first_letter;
                    qDebug() << MyFactory.first_letter;
                    //long long evilN = 0;
                    name = inp.readLine();
                    name = inp.readLine();
                    qDebug() << name;
                    if (name == "yes") {
                        MyFactory.work = true;
                    } else {
                        MyFactory.work = false;
                    }

                    MyFactory.name = inp.readLine();
                    qDebug() << MyFactory.name;
                    //bool evil = evilN == 0;
                    workers_age = "\nВозраста всех раюотников: ";
                    for (int i = 0; i < MyFactory.workers_amount; i++) {
                        inp >> MyFactory.workers_age[i];
                        workers_age += QString::number(MyFactory.workers_age[i]) + " ";
                    }
                    qDebug() << "\n" << workers_age;
                    QChar skip;
                    inp >> skip >> skip;
                    //qDebug() << MyFactory.workers_amount << MyFactory.name;
                    ui->textEdit_2->append(
                        "Количество работников: " + QString::number(MyFactory.workers_amount)
                        + "\nИх зарплата: " + QString::number(MyFactory.salary)
                        + "\nЗаглавный символ предприятия: " + MyFactory.first_letter
                        + "\nПравда ли, что сейчас завод работает: "
                        + (MyFactory.work ? "Да" : "Нет")
                        + "\nНазвание предприятия: " + MyFactory.name + workers_age + "\n");
                }

                file.close();
                ui->lineEdit->clear();
                //ui->textEdit_2->setText(res);
                ui->textEdit->setEnabled(false);
            }
            ui->textEdit->clear();
            break;
        }
        }
        break;
    }
    default: {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Text"),
                                                        "",
                                                        tr("Text Files (*.txt)"));
        QFile file(fileName);
        file.open(QFile::Append);
        /*c = '\n';
        file.write((const char *) &c, sizeof(QChar));*/
        QString name = "";
        name += ui->textEdit->toPlainText() + "\n";
        for (QChar c : name) {
            file.write((const char *) &c, sizeof(QChar));
        }
        file.close();

        ui->textEdit->clear();

        //fileName = QFileDialog::getOpenFileName(this, tr("Save Text"), "", tr("Text Files (*.txt)"));
        //QFile file1(fileName);
        file.open(QFile::ReadOnly);

        res = "";
        while (!file.atEnd()) {
            file.read(reinterpret_cast<char *>(&c), sizeof(QChar));
            res += c;
        }

        ui->textEdit_2->setText(res);
        ui->lineEdit->clear();
        ui->textEdit->setEnabled(false);
        file.close();
        break;
    }
    }
}
