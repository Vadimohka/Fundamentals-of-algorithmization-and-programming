#include "mainwindow.h"
#include "Airport.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTextStream>
#include <QFile>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , StreamInput(&TextInput)
    , StreamingOutput(&TextOutput)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::funMenu);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly()) TextInput += ui->lineEdit->text();
}

void MainWindow::funMenu()
{
    while (true) {
        StreamingOutput << "Меню:\n1 --> Ввести один абзац текста (до нажатия Enter). Сохранить данный текст в текстовый файл с именем «ПетрожицкаяЛаб20.txt» посредством посимвольной записи.\n"
                      "2 --> Посимвольно считать из текстового файла с именем «ПетрожицкаяЛаб20.txt» текст и вывести его на экран.\n"
                      "3 --> Ввести размер массива и массив типа char, разделяющий символ ' '. Сохранить эти элементы массива в текстовый файл с именем «ПетрожицкаяЛаб20_0.txt» посредством потокового ввода.\n"
                      "4 --> Считать из текстового файла с именем «ПетрожицкаяЛаб20_0.txt» элементы массива посредством потокового вывода и вывести на экран считанный из файла массив, разделяя печатаемые значения символом «пробел».\n"
                      "5 --> Ввести содержимое полей объекта типа структуры House. Сохранить содержимое всех полей структуры в текстовый файл с именем «ПетрожицкаяЛаб20_1.txt».\n"
                      "6 --> Прочитать из текстового файла с именем «ПетрожицкаяЛаб20_1.txt» все записанные в нем структуры и распечатать содержимое их полей на экран, разделяя содержимое полей знаком '|'.\n"
                      "7 --> Запросить у пользователя ввести содержимое полей объекта типа вашей структуры. Сохранить содержимое всех полей структуры в бинарный файл с именем «ПетрожицкаяЛаб20_2.bin»\n"
                      "8 --> Прочитать из бинарного файла с именем «ПетрожицкаяЛаб20_2.bin» все записанные в нем структуры и распечатать содержимое их полей на экран, разделяя содержимое полей символами \" ; \".\n"
                      "9 --> Запросить у пользователя ввести предложение (до нажатия Enter) и дописать данное предложение в текстовый файл с именем «ПетрожицкаяЛаб20_3.txt» в виде отдельной строки.\n"
                      "10 --> Построчно считать из текстового файла с именем «ПетрожицкаяЛаб20_3.txt» все предложения и вывести их на экран.\n"
                      "11 --> Выход\n"
                      "Выберите пункт меню: \n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (TextInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int choice;
        StreamInput >> choice;
        if (StreamInput.status() != QTextStream::Ok) {
            TextInput.clear();
            StreamInput.resetStatus();
        } else {
            TextInput.remove(0, StreamInput.pos());
            StreamingOutput << choice << '\n';
        }
        StreamInput.seek(0);
        ui->lineEdit->setText(TextInput.toLatin1());
        processMenuChoice(choice);
    }
}

void MainWindow::processMenuChoice(int choice) {
    auto& in = *ui->lineEdit;
    switch (choice) {
    case 1:
    {
        QString fileName = "ПетрожицкаяЛаб20.txt";
        QFile file(fileName);
        QTextStream fileStream(&file);
        StreamingOutput << "Введте абзац текста\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        TextInput.clear();
        in.setReadOnly(false);
        while (TextInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) StreamingOutput << "Не удалось открыть файл" << fileName << "для записи\n";
        else {
            for (int i = 0; i < TextInput.length(); ++i) fileStream << TextInput.at(i);
            file.close();
            TextInput.clear();
            in.setText(TextInput);
            StreamInput.readAll();
            StreamingOutput << "Текст записан в файл\n";
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 2:
    {
        QString fileName = "ПетрожицкаяЛаб20.txt";
        QFile file(fileName);
        QTextStream fileStream(&file);
        StreamingOutput << "Содержимое файла:\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) StreamingOutput << "Не удалось открыть файл" << fileName << "для чтения\n";
        else {
            while (!fileStream.atEnd()) {
                QChar ch;
                fileStream >> ch;
                StreamingOutput << ch;
            }
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 3:
    {
        QString fileName = "ПетрожицкаяЛаб20_0.txt";
        QFile file(fileName);
        QTextStream fileStream(&file);
        StreamingOutput << "Вы выбрали пункт 3\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) StreamingOutput << "Не удалось открыть файл" << fileName << "для запси\n";
        else {
            StreamingOutput << "Введте размер массива\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            int n;
            StreamInput >> n;
            if (n < 0) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << n << '\n';
            }
            in.setText(TextInput);
            char ch;
            bool isOk = true;
            for (int i = 0; i < n; ++i) {
                StreamingOutput << "Введте символ (" << i + 1 << "/" << n << ")\n";
                ui->textEdit->setText(TextOutput.toLatin1());
                ui->textEdit->moveCursor(QTextCursor::End);
                while (TextInput.isEmpty()){
                    QCoreApplication::processEvents();
                }
                StreamInput >> ch;
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << ch << '\n';
                in.setText(TextInput);
                fileStream << ch << ' ';
            }

            file.close();
            if (isOk) StreamingOutput << "Текст записан в файл\n";
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 4:
    {
        StreamingOutput << "Содержимое файла:\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        QString fileName = "ПетрожицкаяЛаб20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            while (!file_stream.atEnd()) {
                QChar ch;
                file_stream >> ch;
                if (ch != ' ')
                    StreamingOutput << ch << ' ';
            }
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 5:
    {
        QString fileName = "ПетрожицкаяЛаб20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (file.open(QIODevice::WriteOnly)) {
            file.close();
        }
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для запси\n";
        } else {
            Airport airport;
            StreamingOutput << "Введите количество терминалов\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            ui->textEdit->setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            StreamInput >> airport.terminals;
            if (StreamInput.status() != QTextStream::Ok || airport.terminals < 0) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.terminals << '\n';
            }
            in.setText(TextInput);

            StreamingOutput << "Введте площадь\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            StreamInput >> airport.area;
            if (StreamInput.status() != QTextStream::Ok || airport.area < 0) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.area << '\n';
            }
            in.setText(TextInput);
            StreamingOutput << "Введте налчие парковки\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            int t;
            StreamInput >> t;
            if (StreamInput.status() != QTextStream::Ok) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                airport.hasParking = t;
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.hasParking << '\n';
            }
            in.setText(TextInput);

            StreamingOutput << "Введте символ кода аэропорта\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            StreamInput >> airport.code;
            if (StreamInput.status() != QTextStream::Ok ) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.code << '\n';
            }
            in.setText(TextInput);
            file_stream << airport.terminals << '\n' << airport.area << '\n' << airport.hasParking << '\n' << airport.code << '\n';
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 6:
    {
        StreamingOutput << "Содержимое файла:\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        QString fileName = "ПетрожицкаяЛаб20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            int i = 0;
            QString line;
            QVector<QString> vec(4);
            while (!file_stream.atEnd()) {
                line = file_stream.readLine();
                vec[i] = line;
                ++i;
                if (i == 4) {
                    for (int j = 0; j < i; ++j){
                        if (j != 0) StreamingOutput << " | ";
                        StreamingOutput << vec[j];
                    }
                    StreamingOutput << '\n';
                    i = 0;
                }
            }
            for (int j = 0; j < i; ++j){
                if (j != 0) StreamingOutput << " | ";
                StreamingOutput << vec[j];
            }
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 7:
    {
        StreamingOutput << "Вы выбрали пункт 7\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        QString fileName = "ПетрожицкаяЛаб20_2.bin";
        std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
        if (!file.is_open()) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для запси\n";
        } else {
            Airport airport;
            StreamingOutput << "Введте колчество терминалов\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            StreamInput >> airport.terminals;
            if (StreamInput.status() != QTextStream::Ok || airport.terminals < 0) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.terminals << '\n';
            }
            in.setText(TextInput);

            StreamingOutput << "Введте площадь\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            StreamInput >> airport.area;
            if (StreamInput.status() != QTextStream::Ok || airport.area < 0) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.area << '\n';
            }
            in.setText(TextInput);

            StreamingOutput << "Введте налчие парковки\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            int t;
            StreamInput >> t;
            if (StreamInput.status() != QTextStream::Ok) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                airport.hasParking = t;
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.hasParking << '\n';
            }
            in.setText(TextInput);

            StreamingOutput << "Введте символ кода аэропорта\n";
            ui->textEdit->setText(TextOutput.toLatin1());
            ui->textEdit->moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (TextInput.isEmpty()){
                QCoreApplication::processEvents();
            }
            StreamInput >> airport.code;
            if (StreamInput.status() != QTextStream::Ok ) {
                StreamingOutput << "Неверный ввод\n";
                StreamInput.resetStatus();
                TextInput.clear();
                file.close();
                StreamInput.seek(0);
                break;
            } else {
                TextInput.remove(0, StreamInput.pos());
                StreamInput.seek(0);
                StreamingOutput << airport.code << '\n';
            }
            in.setText(TextInput);
            file.write(reinterpret_cast<const char*>(&airport), sizeof(airport));
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 8:
    {
        StreamingOutput << "Вы выбрали пункт 8\nСодержимое файла:\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        QString fileName = "ПетрожицкаяЛаб20_2.bin";
        std::ifstream file(fileName.toStdString(), std::ios::binary);
        if (!file.is_open()) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            Airport airport;
            while (!file.eof()) {
                file.read(reinterpret_cast<char*>(&airport), sizeof(airport));
                if (file.eof()) break;
                StreamingOutput << "Количество терминалов: " << airport.terminals << " ; ";
                StreamingOutput << "Площадь: " << airport.area << " ; ";
                StreamingOutput << "Код: " << airport.code << " ; ";
                StreamingOutput << "Есть ли парковка: " << (airport.hasParking ? "Да" : "Нет") << '\n';
            }
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 9:
    {
        QString fileName = "ПетрожицкаяЛаб20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        StreamingOutput << "Вы выбрали пункт 9\nВведте абзац текста\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        TextInput.clear();
        in.setReadOnly(false);
        while (TextInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для записи\n";
        } else {
            file_stream << TextInput << '\n';
            file.close();
            TextInput.clear();
            in.setText(TextInput);
            StreamInput.readAll();
            StreamingOutput << "Текст успешно записан в файл\n";
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 10:
    {
        StreamingOutput << "Содержимое файла:\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        QString fileName = "ПетрожицкаяЛаб20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            StreamingOutput << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            QString line;
            while (!file_stream.atEnd()) {
                line = file_stream.readLine();
                StreamingOutput << line << '\n';
            }
            file.close();
        }
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
        break;
    }
    case 11:
        exit(0);
        break;
    default:
        StreamingOutput << "Некорректный ввод (от 1 до 11)!\n";
        ui->textEdit->setText(TextOutput.toLatin1());
        ui->textEdit->moveCursor(QTextCursor::End);
    }
    StreamingOutput << "\n";
    ui->textEdit->setText(TextOutput.toLatin1());
    ui->textEdit->moveCursor(QTextCursor::End);
    in.setReadOnly(true);
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

