#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QFile>
#include <QMessageBox>

#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->showMenu_btn, &QPushButton::clicked, this, &MainWindow::showMenuSlot);
    connect(ui->choosePoint_btn, &QPushButton::clicked, this, &MainWindow::choosePointSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu()
{
    ui->textEdit->append("1. Ввести абзац текста заканчивающийся нажатием enter\n"
                         "2. Посимвольно считать из текстового файла с именем СебелевЛаб20.txt текст и вывести на экран\n"
                         "3. Ввести размера массива и значения элементов массива и сохранить элементы массива в текстовый файл с именем СебелевЛаб20.txt посредством потокового ввода\n"
                         "4. Считать из текстового файла с именем СебелевЛаб20_0.txt элементы массива и вывести на экран\n"
                         "5. Вести содержимое полей объекта типа вашей структуры. Сохранить содержимое всех полей структуры в текстовый файл с именем СебелевЛаб20_1.txt\n"
                         "6. Прочитать из текстового файла с именем СебелевЛаб20_1.txt все записанные в нем структуры и распечатать содержимое их полей на экран, разделяя содержимое полей знаком ‘|’\n"
                         "7. Ввести содержимое полей объекта типа вашей структуры. Сохранить содержимое всех полей структуры в бинарный файл с именем СебелевЛаб20_2.bin\n"
                         "8. Прочитать из бинарного файла с именем СебелевЛаб20_2.bin все записанные в нем структуры\n"
                         "9. Ввести предложение (слова с пробелами, завершается нажатием Enter'a) и дописать данное предложение в текстовый файл с именем СебелевЛаб20_3.txt в виде отдельной строки.\n"
                         "10. Построчно считать из текстового файла с именем «ФамилияЛаб20_3.txt» все предложения и вывести их на экран\n"
                         "11. Выйти из программы\n");
}

void MainWindow::choice(int num)
{
    switch(num) {
    case 1: {
        bool ok;
        QString text = QInputDialog::getText(this, "Введите текст", "Введите текст", QLineEdit::Normal, "", &ok);
        if (ok) {
            QFile file(file1);
            // Write text to file for one symbol
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                for (int i = 0; i < text.size(); i++) {
                    stream << text.at(i);
                }
                file.close();
            }
        }
        break;
    }
    case 2: {
        ui->textEdit->append("Посимвольно считать из текстового файла с именем СебелевЛаб20.txt текст и вывести на экран");

        QFile file(file1);
        // Read text from file for one symbol
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                ui->textEdit->append(line);
            }
            file.close();
        }
        break;
    }
    case 3: {
        ui->textEdit->append("Введите размер массива и значения элементов массива:");

        bool ok;
        int size = QInputDialog::getInt(this, "Введите размер массива", "Введите размер массива", 0, 0, 1000000, 1, &ok);

        if (ok) {
            QFile file(file2);
            // Write array to file
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                for (int i = 0; i < size; i++) {
                    char value = QInputDialog::getText(this, "Введите элемент массива", "Введите элемент массива", QLineEdit::Normal, "", &ok).at(0).toLatin1();
                    if (ok) {
                        stream << value << "~";
                        array.push_back(value);
                    }
                }
                file.close();
            }
        }
        break;
    }
    case 4: {
        ui->textEdit->append("Считать из текстового файла с именем СебелевЛаб20_0.txt элементы массива и вывести на экран");

        QFile file(file2);
        // Read array from file and output with delim " "
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            QString line = stream.readLine();
            // Change delim on " "
            line.replace("~", " ");
            ui->textEdit->append(line);
            file.close();
        }
        break;
    }
    case 5: {
        ui->textEdit->append("Введите содержимое полей объекта типа вашей структуры.");

        Animal tempAnimal;
        bool ok;
        strcpy(tempAnimal.name, QInputDialog::getText(this, "Введите имя животного", "Введите имя животного", QLineEdit::Normal, "", &ok).toStdString().c_str());
        tempAnimal.age = QInputDialog::getInt(this, "Введите возраст животного", "Введите возраст животного", 0, 0, 1000000, 1, &ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "Возраст должен быть числом");
            tempAnimal.age = QInputDialog::getInt(this, "Введите возраст животного", "Введите возраст животного", 0, 0, 1000000, 1, &ok);
        }
        tempAnimal.gender = QInputDialog::getText(this, "Введите пол животного", "Введите пол животного", QLineEdit::Normal, "", &ok).at(0).toLatin1();

        if (tempAnimal.gender != 'M' || tempAnimal.gender != 'F') {
            QMessageBox::critical(this, "Ошибка", "Неверный пол");
            tempAnimal.gender = QInputDialog::getText(this, "Введите пол животного", "Введите пол животного", QLineEdit::Normal, "", &ok).at(0).toLatin1();
        }

        tempAnimal.isAlive = QInputDialog::getInt(this, "Введите живо ли животное", "Введите живо ли животное", 0, 0, 1, 1, &ok);

        tempAnimal.weight = QInputDialog::getInt(this, "Введите вес животного", "Введите вес животного", 0, 0, 1000000, 1, &ok);

        while (!ok) {
            QMessageBox::critical(this, "Ошибка", "Вес должен быть числом");
            tempAnimal.weight = QInputDialog::getInt(this, "Введите вес животного", "Введите вес животного", 0, 0, 1000000, 1, &ok);
        }

        tempAnimal.sizes[0] = QInputDialog::getInt(this, "Введите размер 1", "Введите размер 1", 0, 0, 1000000, 1, &ok);
        tempAnimal.sizes[1] = QInputDialog::getInt(this, "Введите размер 2", "Введите размер 2", 0, 0, 1000000, 1, &ok);
        tempAnimal.sizes[2] = QInputDialog::getInt(this, "Введите размер 3", "Введите размер 3", 0, 0, 1000000, 1, &ok);

        animals.push_back(tempAnimal);

        QFile file(file3);
        // Write animal to file
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << tempAnimal.name << "|" << tempAnimal.age << "|"
                   << tempAnimal.gender << "|" << (tempAnimal.isAlive ? "Alive" : "Not alive") << "|"
                   << tempAnimal.weight << "|" << tempAnimal.sizes[0] << "|"
                   << tempAnimal.sizes[1] << "|" << tempAnimal.sizes[2] << "|";
            file.close();
        }
        break;
    }
    case 6: {
        ui->textEdit->append("Прочитать из текстового файла с именем СебелевЛаб20_1.txt все записанные в нем структуры и распечатать содержимое их полей на экран, разделяя содержимое полей знаком ‘|’");

        QFile file(file3);
        // Read animals from file and output with delim "|"
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                ui->textEdit->append(line);
            }
            file.close();
        }
        break;
    }
    case 7: {
        ui->textEdit->append("Введите содержимое полей объекта типа вашей структуры.");

        Animal tempAnimal;
        bool ok;
        strcpy(tempAnimal.name, QInputDialog::getText(this, "Введите имя животного", "Введите имя животного", QLineEdit::Normal, "", &ok).toStdString().c_str());
        tempAnimal.age = QInputDialog::getInt(this, "Введите возраст животного", "Введите возраст животного", 0, 0, 1000000, 1, &ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "Возраст должен быть числом");
            tempAnimal.age = QInputDialog::getInt(this, "Введите возраст животного", "Введите возраст животного", 0, 0, 1000000, 1, &ok);
        }
        tempAnimal.gender = QInputDialog::getText(this, "Введите пол животного", "Введите пол животного", QLineEdit::Normal, "", &ok).at(0).toLatin1();

        if (tempAnimal.gender != 'M' || tempAnimal.gender != 'F') {
            QMessageBox::critical(this, "Ошибка", "Неверный пол");
            tempAnimal.gender = QInputDialog::getText(this, "Введите пол животного", "Введите пол животного", QLineEdit::Normal, "", &ok).at(0).toLatin1();
        }

        tempAnimal.isAlive = QInputDialog::getInt(this, "Введите живо ли животное", "Введите живо ли животное", 0, 0, 1, 1, &ok);

        tempAnimal.weight = QInputDialog::getInt(this, "Введите вес животного", "Введите вес животного", 0, 0, 1000000, 1, &ok);

        while (!ok) {
            QMessageBox::critical(this, "Ошибка", "Вес должен быть числом");
            tempAnimal.weight = QInputDialog::getInt(this, "Введите вес животного", "Введите вес животного", 0, 0, 1000000, 1, &ok);
        }

        tempAnimal.sizes[0] = QInputDialog::getInt(this, "Введите размер 1", "Введите размер 1", 0, 0, 1000000, 1, &ok);
        tempAnimal.sizes[1] = QInputDialog::getInt(this, "Введите размер 2", "Введите размер 2", 0, 0, 1000000, 1, &ok);
        tempAnimal.sizes[2] = QInputDialog::getInt(this, "Введите размер 3", "Введите размер 3", 0, 0, 1000000, 1, &ok);

        animals.push_back(tempAnimal);

        // Write animal to bin file
        std::ofstream out(file4.toStdString().c_str(), std::ios::binary);
        if (!out) {
            QMessageBox::critical(this, "Ошибка", "Ошибка открытия файла");
            return;
        }
        out.write(reinterpret_cast<char*>(&tempAnimal.name), sizeof(tempAnimal.name));
        out.write(reinterpret_cast<char*>(&tempAnimal.age), sizeof(tempAnimal.age));
        out.write(reinterpret_cast<char*>(&tempAnimal.gender), sizeof(tempAnimal.gender));
        out.write(reinterpret_cast<char*>(&tempAnimal.isAlive), sizeof(tempAnimal.isAlive));
        out.write(reinterpret_cast<char*>(&tempAnimal.weight), sizeof(tempAnimal.weight));
        out.write(reinterpret_cast<char*>(&tempAnimal.sizes), sizeof(tempAnimal.sizes));
        out.close();

        break;
    }
    case 8: {
        ui->textEdit->append("Прочитать из бинарного файла с именем СебелевЛаб20_2.bin все записанные в нем структуры");

        // Read animal from bin file
        std::ifstream in(file4.toStdString().c_str(), std::ios::binary);
        if (!in) {
            QMessageBox::critical(this, "Ошибка", "Ошибка открытия файла");
            return;
        }

        Animal tempAnimal;
        in.read(reinterpret_cast<char*>(&tempAnimal.name), sizeof(tempAnimal.name));
        in.read(reinterpret_cast<char*>(&tempAnimal.age), sizeof(tempAnimal.age));
        in.read(reinterpret_cast<char*>(&tempAnimal.gender), sizeof(tempAnimal.gender));
        in.read(reinterpret_cast<char*>(&tempAnimal.isAlive), sizeof(tempAnimal.isAlive));
        in.read(reinterpret_cast<char*>(&tempAnimal.weight), sizeof(tempAnimal.weight));
        in.read(reinterpret_cast<char*>(&tempAnimal.sizes), sizeof(tempAnimal.sizes));
        in.close();

        // display animal with delim ";"
        QString line = QString(tempAnimal.name) + ";"
                + QString::number(tempAnimal.age) + ";"
                + tempAnimal.gender + ";" + (tempAnimal.isAlive ? "Alive" : "Not alive") + ";"
                + QString::number(tempAnimal.weight) + ";" + QString::number(tempAnimal.sizes[0]) + ";"
                + QString::number(tempAnimal.sizes[1]) + ";" + QString::number(tempAnimal.sizes[2]) + ";";

        ui->textEdit->append(line);
        break;
    }
    case 9: {
        ui->textEdit->append("Введите предложение (слова с пробелами, завершается нажатием Enter'a)");

        bool ok;
        QString text = QInputDialog::getText(this, "Введите текст", "Введите текст", QLineEdit::Normal, "", &ok);
        if (ok) {
            QFile file(file5);
            // Write text to file for one symbol
            if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                QTextStream stream(&file);
                stream << text << "\n";
                file.close();
            }
        }
        break;
    }
    case 10: {
        ui->textEdit->append("Построчно считать из текстового файла с именем «ФамилияЛаб20_3.txt» все предложения и вывести их на экран");

        QFile file(file5);
        // Read text from file for one symbol
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                ui->textEdit->append(line);
            }
            file.close();
        }
        break;
    }
    case 11:
        QApplication::quit();
        break;
    default:
        ui->textEdit->append("Неверный ввод");
    }
}

void MainWindow::getInput()
{
    if (ui->lineEdit->text().isEmpty()) return;

    bool ok;
    choiceNum = ui->lineEdit->text().toInt(&ok);

    if (!ok) {
        ui->textEdit->append("Неверный ввод");
        return;
    }

    if (choiceNum < 1 || choiceNum > 10) {
        ui->textEdit->append("Введите число от 1 до 10");
        return;
    }

    choice(choiceNum);
}

void MainWindow::showMenuSlot()
{
    showMenu();
}


void MainWindow::choosePointSlot()
{
    choiceNum = QInputDialog::getInt(this, "Введите номер пункта", "Введите номер пункта", 0, 0, 11, 1);
    choice(choiceNum);
}

