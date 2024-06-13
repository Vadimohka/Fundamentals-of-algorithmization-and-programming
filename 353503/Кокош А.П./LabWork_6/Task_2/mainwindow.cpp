#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);

    QTimer::singleShot(50, [&]{
        printMenu();
    });

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(ui->label);

    ui->gridLayout->removeWidget(ui->label);
    ui->gridLayout->addWidget(scrollArea, 0, 0);

    Qt::WindowFlags flags = Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::CustomizeWindowHint;
    setWindowFlags(flags);

    setFixedSize(size());
    setWindowTitle("Lab6 task2");
}

MainWindow::~MainWindow()
{
    delete ui;
    QApplication::quit();
}

QString MainWindow::input()
{
    loop.exec();
    QString ret = ui->lineEdit->text();
    ui->lineEdit->clear();
    ui->label->setText(ui->label->text() + "\n");
    return ret;
}

void MainWindow::print(QString newStr)
{
    ui->label->setText(ui->label->text() + newStr);
}

struct HandWatch
{
    int HandWatchId;
    double HandWatchQuality;
    char HandWatchType;
    bool isWork;
    static const int maxNameLength = 20;
    std::string HandWatchName;
    static const int maxSerialNumber = 100;
    int serialNumber;
};

void MainWindow::printMenu()
{
    bool isRunning = true;
    while (isRunning) {
        print("\nМеню:\n"
              "1. Записать параграф в файл\n"
              "2. Прочитать и распечатать параграф из файла\n"
              "3. Записать массив в файл\n"
              "4. Прочитать и распечатать массив из файла\n"
              "5. Записать структуру в файл\n"
              "6. Прочитать и распечатать структуры из файла\n"
              "7. Записать предложение в файл\n"
              "8. Прочитать и распечатать предложения из файла\n"
              "9. Записать структуру в бинарный файл\n"
              "10. Прочитать и распечатать структуры из бинарного файла\n"
              "11. Выход\n"
              "Введите ваш выбор:\n");
        switch (input().toInt()) {
        case 1:
            writeParagraphToFile(paragraphFile);
            break;
        case 2:
            readAndPrintParagraphFromFile(paragraphFile);
            break;
        case 3:
            writeArrayToFile(arrayFile, '}');
            break;
        case 4:
            readAndPrintArrayFromFile(arrayFile, '}');
            break;
        case 5:
            writeStructToFile(structFile);
            break;
        case 6:
            readAndPrintStructsFromFile(structFile);
            break;
        case 7:
            writeSentenceToFile(sentenceFile);
            break;
        case 8:
            readAndPrintSentencesFromFile(sentenceFile);
            break;
        case 11:
            print("Завершение программы...\n");
            isRunning = false;
            break;
        case 9:
            saveWatchToBinaryFile(binaryFile);
            break;
        case 10:
            printShipsFromBinaryFile(binaryFile);
            break;
        default:
            print("Неверный выбор. Пожалуйста, введите число от 1 до 9.\n");
        }
    }
    QApplication::quit();
}

void MainWindow::writeParagraphToFile(const std::string &filename)
{
    std::wofstream file(filename, std::ios::out);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    print("Введите параграф (нажмите Enter для завершения):\n");
    QString paragraph = input();
    file << paragraph.toStdWString();
    print("Параграф введён!\n");
    file.close();
}

void MainWindow::readAndPrintParagraphFromFile(const std::string &filename)
{
    std::wifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    QString fileName(filename.c_str());
    print(QString("Параграф из файла " + fileName + ":" + "\n"));
    wchar_t ch;
    while (file.get(ch)) {
        print(QString(QChar(ch)));
    }
    file.close();
}

void MainWindow::writeArrayToFile(const std::string &filename, char delimiter)
{
    int size;
    print("Введите размер массива:\n");
    size = input().toInt();

    std::ofstream file(filename, std::ios::out);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    print("Введите элементы массива, разделенные '" + QString(delimiter) + "': ");
    QString inp = input();
    for (int i = 0; i < size; ++i) {
        char value;
        value = inp[2 * i].toLatin1();
        file << value;
        if (i != size - 1) {
            file << delimiter;
        }
    }

    file.close();

    print("Массив введён!");
}

void MainWindow::readAndPrintArrayFromFile(const std::string &filename, char delimiter)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    QString fileName(filename.c_str());
    print(QString("Массив из файла " + fileName + ":" + "\n"));
    char value;
    while (file.get(value)) {
        if (value != delimiter) {
            print(QString(value) + " ");
        }
    }

    file.close();
}

void MainWindow::writeStructToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    HandWatch obj;
    print("Введите идентификатор наручных часов: ");
    obj.HandWatchId = input().toInt();
    print("Введите качество часов (Пример 45.98): ");
    obj.HandWatchQuality = input().toDouble();
    print("Введите тип часов: ");
    obj.HandWatchType = input()[0].toLatin1();
    print("Работают ли часы (1 - да, 0 - нет): ");
    obj.isWork = input().toInt();
    print("Введите название часов (не более " + QString::number(HandWatch::maxNameLength)
          + " символов): ");
    obj.HandWatchName = input().toStdString();
    print("Введите серийный номер: ");
    obj.serialNumber = input().toInt();

    file << obj.HandWatchId << " | " << obj.HandWatchQuality << " | " << obj.HandWatchType << " | "
         << obj.isWork << " | " << obj.HandWatchName << " | " << obj.serialNumber << std::endl;

    file.close();
}

void MainWindow::readAndPrintStructsFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    QString fileName(filename.c_str());
    print("Структуры из файла " + fileName + ":" + "\n");
    HandWatch ship;
    char delimiter;
    while (file >> ship.HandWatchId >> delimiter && delimiter == '|'
           && file >> ship.HandWatchQuality >> delimiter && delimiter == '|'
           && file >> ship.HandWatchType >> delimiter && delimiter == '|'
           && file >> ship.isWork >> delimiter && delimiter == '|'
           && file >> ship.HandWatchName >> delimiter && delimiter == '|'
           && file >> ship.serialNumber) {
        print(QString::number(ship.HandWatchId) + "|" + QString::number(ship.HandWatchQuality) + "|"
              + ship.HandWatchType + "|" + QString::number(ship.isWork) + "|"
              + QString::fromUtf8(ship.HandWatchName) + "|" + QString::number(ship.serialNumber)
              + " ;\n");
    }

    file.close();
}

void MainWindow::writeSentenceToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    QString sentence;
    print("Введите предложение: ");
    sentence = input();

    file << sentence.toStdString() << '\n';

    file.close();

    print("Предложение записано!\n");
}

void MainWindow::readAndPrintSentencesFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    QString fileName(filename.c_str());
    print("Предложения из файла " + fileName + ":" + "\n");
    std::string sentence;
    while (getline(file, sentence)) {
        print(QString(sentence.c_str()) +"\n");
    }

    file.close();
}

void MainWindow::saveWatchToBinaryFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app | std::ios::binary);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    HandWatch obj;
    print("Введите идентификатор наручных часов: ");
    obj.HandWatchId = input().toInt();
    print("Введите качество часов (Пример 93.45): ");
    obj.HandWatchQuality = input().toDouble();
    print("Введите тип часов: ");
    obj.HandWatchType = input()[0].toLatin1();
    print("Работают ли часы (1 - да, 0 - нет): ");
    obj.isWork = input().toInt();
    print("Введите название часов (не более " + QString::number(HandWatch::maxNameLength)
          + " символов): ");
    wchar_t name[20];
    input().toWCharArray(name);
    for (int i = 0; i < 20; ++i)
        obj.HandWatchName[i] = name[i];
    print("Введите серийный номер: ");
    obj.serialNumber = input().toInt();

    file.write(reinterpret_cast<const char *>(&obj), sizeof(HandWatch));

    file.close();
}

void MainWindow::printShipsFromBinaryFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    HandWatch handWatch;
    while (file.read(reinterpret_cast<char *>(&handWatch), sizeof(HandWatch))) {
        print(QString::number(handWatch.HandWatchId) + "|"
              + QString::number(handWatch.HandWatchQuality) + "|" + handWatch.HandWatchType + "|"
              + QString::number(handWatch.isWork) + "|" + QString::fromUtf8(handWatch.HandWatchName)
              + "|" + QString::number(handWatch.serialNumber) + " ;\n");
    }

    //file.close();
}
