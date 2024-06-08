#include "mainwindow.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include "house.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stringInit();
    separateInit();
    pointerinit();
    referenceInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

char House::address[100] = "Mayakovski street";
int House::rooms[10] = {2, 1, 2, 4, 3, 3, 2, 2, 4, 5};

void MainWindow::stringInit()
{
    House house1 = {3, 122.3, 'B', true};
    QString output = QString::number(house1.floors) + "|" + QString::number(house1.area) + "|"
                     + house1.type + "|" + (house1.hasGarage ? "true" : "false") + "|"
                     + House::address + "|";
    for (int i = 0; i < house1.floors; i++) {
        output += QString::number(house1.rooms[i]) + " ";
    }
    ui->initstringBrowser->setText(output);
}

void MainWindow::separateInit()
{
    House house2;
    strcpy(House::address, "New street");
    house2.floors = 4;
    house2.area = 200.5;
    house2.type = 'A';
    house2.hasGarage = false;
    for (int i = 0; i < house2.floors; i++) {
        house2.rooms[i] = i + 1;
    }
    QString output2 = QString::number(house2.floors) + "|" + QString::number(house2.area) + "|"
                      + house2.type + "|" + (house2.hasGarage ? "true" : "false") + "|"
                      + House::address + "|";
    for (int i = 0; i < house2.floors; i++) {
        output2 += QString::number(house2.rooms[i]) + " ";
    }
    ui->separateinitBrowser->setText(output2);
}

void MainWindow::pointerinit()
{
    House house4;
    House *ptr = &house4;
    ptr->floors = 5;
    ptr->area = 400.32;
    ptr->type = 'C';
    ptr->hasGarage = true;
    for (int i = 0; i < ptr->floors; i++) {
        ptr->rooms[i] = i + 2;
    }
    QString output4 = QString::number(ptr->floors) + "|" + QString::number(ptr->area) + "|"
                      + ptr->type + "|" + (ptr->hasGarage ? "true" : "false") + "|" + House::address
                      + "|";
    for (int i = 0; i < ptr->floors; i++) {
        output4 += QString::number(ptr->rooms[i]) + " ";
    }
    ui->pointerBrowser->setText(output4);
}

void MainWindow::referenceInit()
{
    House house5;
    House &ref = house5;
    ref.floors = 6;
    ref.area = 500.433;
    ref.type = 'D';
    strcpy(House::address, "Telegraph avenue");
    ref.hasGarage = true;
    for (int i = 0; i < ref.floors; i++) {
        ref.rooms[i] = i + 3;
    }
    QString output5 = QString::number(ref.floors) + "|" + QString::number(ref.area) + "|" + ref.type
                      + "|" + (ref.hasGarage ? "true" : "false") + "|" + House::address + "|";
    for (int i = 0; i < ref.floors; i++) {
        output5 += QString::number(ref.rooms[i]) + " ";
    }
    ui->referenceBrowser->setText(output5);
}

void MainWindow::on_initButton_clicked()
{
    House house3;

    bool ok;
    house3.floors = QInputDialog::getInt(this,
                                         tr("Введите количество этажей"),
                                         tr("Этажи:"),
                                         1,
                                         1,
                                         10,
                                         1,
                                         &ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод количества этажей");
        return;
    }

    house3.area = QInputDialog::getDouble(this,
                                          tr("Введите площадь"),
                                          tr("Площадь:"),
                                          1.0,
                                          1.0,
                                          1000.0,
                                          2,
                                          &ok);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод площади");
        return;
    }

    house3.type = QInputDialog::getText(this,
                                        tr("Введите тип дома"),
                                        tr("Тип:"),
                                        QLineEdit::Normal,
                                        "",
                                        &ok)[0]
                      .toLatin1();
    if (!ok)
        return;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Есть гараж?",
                                  "У дома есть гараж?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        house3.hasGarage = true;
    } else {
        house3.hasGarage = false;
    }

    for (int i = 0; i < house3.floors; i++) {
        house3.rooms[i] = QInputDialog::getInt(this,
                                               tr("Введите количество комнат на этаже"),
                                               tr("Комнаты на этаже ") + QString::number(i + 1)
                                                   + ":",
                                               1,
                                               1,
                                               10,
                                               1,
                                               &ok);
        if (!ok) {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод количества комнат на этаже");
            return;
        }
    }

    QString address = QInputDialog::getText(this,
                                            tr("Введите адрес"),
                                            tr("Адрес:"),
                                            QLineEdit::Normal,
                                            "",
                                            &ok);
    if (!ok)
        return;
    strncpy(House::address, address.toStdString().c_str(), sizeof(House::address) - 1);

    QString output3 = QString::number(house3.floors) + "|" + QString::number(house3.area) + "|"
                      + house3.type + "|" + (house3.hasGarage ? "true" : "false") + "|"
                      + House::address + "|";
    for (int i = 0; i < house3.floors; i++) {
        output3 += QString::number(house3.rooms[i]) + " ";
    }
    ui->initBrowser->setText(output3);
}

void MainWindow::on_printButton_clicked()
{
    QString selectedBrowser = ui->comboBox->currentText();
    QString text;
    House houseToPrint;
    if (selectedBrowser == "initstring") {
        text = ui->initstringBrowser->toPlainText();
        QStringList lines = text.split("|");
        houseToPrint.floors = lines[0].toInt();
        houseToPrint.area = lines[1].toDouble();
        houseToPrint.type = lines[2][0].toLatin1();
        houseToPrint.hasGarage = lines[3] == "true" ? true : false;
    } else if (selectedBrowser == "separateinitBrowser") {
        text = ui->separateinitBrowser->toPlainText();
        QStringList lines = text.split("|");
        houseToPrint.floors = lines[0].toInt();
        houseToPrint.area = lines[1].toDouble();
        houseToPrint.type = lines[2][0].toLatin1();
        houseToPrint.hasGarage = lines[3] == "true" ? true : false;
    } else if (selectedBrowser == "pointerBrowser") {
        text = ui->pointerBrowser->toPlainText();
        QStringList lines = text.split("|");
        houseToPrint.floors = lines[0].toInt();
        houseToPrint.area = lines[1].toDouble();
        houseToPrint.type = lines[2][0].toLatin1();
        houseToPrint.hasGarage = lines[3] == "true" ? true : false;
    } else if (selectedBrowser == "referenceBrowser") {
        text = ui->referenceBrowser->toPlainText();
        QStringList lines = text.split("|");
        houseToPrint.floors = lines[0].toInt();
        houseToPrint.area = lines[1].toDouble();
        houseToPrint.type = lines[2][0].toLatin1();
        houseToPrint.hasGarage = lines[3] == "true" ? true : false;
    } else if (selectedBrowser == "initBrowser") {
        text = ui->initBrowser->toPlainText();
        QStringList lines = text.split("|");
        houseToPrint.floors = lines[0].toInt();
        houseToPrint.area = lines[1].toDouble();
        houseToPrint.type = lines[2][0].toLatin1();
        houseToPrint.hasGarage = lines[3] == "true" ? true : false;
    }
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QTextDocument doc;
        doc.setHtml(text);
        doc.print(&printer);
    }
}
