#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carrepairshop.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputStream(&textInput)
    , outputStream(&textOutput)
{
    ui->setupUi(this);
    checkFilesAvailable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainMenu()
{
    while (true) {
        QCoreApplication::processEvents();
        outputStream << menu;
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()) {
            QCoreApplication::processEvents();
        }
        int func;
        inputStream >> func;
        if (inputStream.status() != QTextStream::Ok) {
            textInput.clear();
            inputStream.resetStatus();
        } else {
            textInput.remove(0, inputStream.pos());
            outputStream << func << '\n';
        }
        inputStream.seek(0);
        ui->lineEdit->setText(textInput);

        QString fileName;
        switch (func) {
        case 1:
            fileName = "KrenLab6.txt";
            saveData(fileName);
            break;
        case 2:
            fileName = "KrenLab6.txt";
            streamFileData(fileName);
            break;
        case 3:
            fileName = "KrenLab6_0.txt";
            saveCharArray(fileName);
            break;
        case 4:
            fileName = "KrenLab6_0.txt";
            streamFileDataCharArray(fileName);
            break;
        case 5:
            fileName = "KrenLab6_1.txt";
            saveStructData(fileName);
            break;
        case 6:
            fileName = "KrenLab6_1.txt";
            streamFileDataStruct(fileName);
            break;
        case 7:
            fileName = "KrenLab6_2.bin";
            saveStructBin(fileName);
            break;
        case 8:
            fileName = "KrenLab6_2.bin";
            streamBinFileDataStruct(fileName);
            break;
        case 9:
            fileName = "KrenLab6_3.txt";
            textFile(fileName);
            break;
        case 10:
            fileName = "KrenLab6_3.txt";
            streamFileData(fileName);
            break;
        case 11:
            outputStream << "Выход из программы.\n";
            ui->textEdit->setText(textOutput);
            ui->textEdit->moveCursor(QTextCursor::End);
            close();
            break;
        default:
            outputStream << "Некорректный ввод. Пожалуйста, выберите пункт меню от 1 до 11.\n";
            ui->textEdit->setText(textOutput);
            ui->textEdit->moveCursor(QTextCursor::End);
        }
        outputStream << "\n";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(true);
    }
}

void MainWindow::checkFilesAvailable()
{
    QStringList filesToCreate = {"KrenLab6.txt", "KrenLab6_0.txt", "KrenLab6_1.txt", "KrenLab6_2.bin", "KrenLab6_3.txt"};
    for (const QString &fileName : filesToCreate) {
        QFile file(fileName);
        if (!file.exists()) {
            if (!file.open(QIODevice::WriteOnly)) {
                qDebug() << "\nНе удалось создать файл" << fileName;
            }
            file.close();
        }
    }
}

void MainWindow::saveData(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 1\nВведите абзац текста";
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    textInput.clear();
    ui->lineEdit->setReadOnly(false);
    while (textInput.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        for (int i = 0; i < textInput.length(); ++i) {
            fileStream << textInput.at(i);
        }
        textInput.clear();
        ui->lineEdit->setText(textInput);
        inputStream.readAll();
        outputStream << "\nТекст был добавлен в файл\n";
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamFileData(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт для отображения содержимого файла: " << fileName << "\n";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!fileStream.atEnd()) {
            QChar ch;
            fileStream >> ch;
            outputStream << ch;
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveCharArray(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 3\nВведите размер массива и массив типа int, разделяя элементы символом пробела\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        outputStream << "Введте размер массива";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int n;
        inputStream >> n;
        if (inputStream.status() != QTextStream::Ok || n < 0) {
            outputStream << "\nНеверный ввод размера массива\n";
            ui->textEdit->setText(textOutput);
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        }
        else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << n << '\n';
        }
        ui->lineEdit->setText(textInput);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int c;
            outputStream << "Введите " << i+1 << "-й из " << n << " элементов";
            ui->textEdit->setText(textOutput);
            ui->textEdit->moveCursor(QTextCursor::End);
            while (textInput.isEmpty()) {
                QCoreApplication::processEvents();
            }
            inputStream >> c;
            if (inputStream.status() != QTextStream::Ok) {
                outputStream << "\nНеверный ввод символа\n";
                inputStream.seek(0);
                inputStream.resetStatus();
                textInput.clear();
                ok = false;
                return;
            }
            else {
                textInput.remove(0, inputStream.pos());
                inputStream.seek(0);
                outputStream << c << '\n';
            }
            ui->lineEdit->setText(textInput);
            fileStream << c << ':';
        }
        file.close();
        if (ok) outputStream << "\nМассив записан в файл " << fileName << "\n";
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamFileDataCharArray(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 4\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!fileStream.atEnd()) {
            QString line = fileStream.readLine();
            QStringList charArray = line.split(":", Qt::SkipEmptyParts);
            for (const QString &ch : charArray) {
                outputStream << ch << " ";
            }
            outputStream << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveStructData(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 5\nВведите данные об животном: возраст, вес, тип диеты (один символ), является ли мужским (0 или 1)\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        CarRepairShop carShop;
        outputStream << "Введите количество работников(int)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> carShop.numberOfEmployees;
        if (inputStream.status() != QTextStream::Ok || carShop.numberOfEmployees < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << carShop.numberOfEmployees << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите среднюю почасовую оплату(double)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> carShop.averageHourlyRate;
        if (inputStream.status() != QTextStream::Ok || carShop.averageHourlyRate < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << carShop.averageHourlyRate << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите специализацию (Char)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> carShop.specialization;
        if (inputStream.status() != QTextStream::Ok ) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << carShop.specialization << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите наличие страховки (0 или 1)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int b;
        inputStream >> b;
        if (inputStream.status() != QTextStream::Ok || (b != 0 && b != 1)) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            carShop.hasInsurance = (b == 1);
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << (carShop.hasInsurance ? "Есть" : "Нет") << '\n';
        }
        ui->lineEdit->setText(textInput);
        fileStream << carShop.numberOfEmployees << " " << carShop.averageHourlyRate << " " << carShop.specialization << " " << (carShop.hasInsurance ? "1" : "0") << "\n";
        file.close();
    }
    outputStream << "\nДанные успешно записаны в файл " << fileName << "\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamFileDataStruct(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 6\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!fileStream.atEnd()) {
            QString line = fileStream.readLine();
            QStringList carShopData = line.split(" ", Qt::SkipEmptyParts);
            if (carShopData.size() != 4) {
                outputStream << "\nНеверный формат строки в файле.\n";
                continue;
            }
            CarRepairShop carShop;
            carShop.numberOfEmployees = carShopData[0].toInt();
            carShop.averageHourlyRate = carShopData[1].toDouble();
            carShop.specialization = carShopData[2][0].toLatin1();
            carShop.hasInsurance = (carShopData[3].toInt() != 0);

            outputStream << "Количество работников: " << carShop.numberOfEmployees << " ; ";
            outputStream << "Средняя почасовая оплата: " << carShop.averageHourlyRate << " ; ";
            outputStream << "Специализация: " << carShop.specialization << " ; ";
            outputStream << "Страховка: " << (carShop.hasInsurance ? "Есть" : "Нет") << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveStructBin(const QString &fileName)
{
    std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    outputStream << "Вы выбрали пункт 5\nВведите данные об животном: возраст, вес, тип диеты (один символ), является ли мужским (0 или 1)\n";
    ui->lineEdit->clear();
    if (!file.is_open()) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        CarRepairShop carShop;
        outputStream << "Введите количество работников(int)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> carShop.numberOfEmployees;
        if (inputStream.status() != QTextStream::Ok || carShop.numberOfEmployees < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << carShop.numberOfEmployees << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите среднюю почасовую оплату(double)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> carShop.averageHourlyRate;
        if (inputStream.status() != QTextStream::Ok || carShop.averageHourlyRate < 0) {
            outputStream << "Неверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << carShop.averageHourlyRate << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите специализацию (Char)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> carShop.specialization;
        if (inputStream.status() != QTextStream::Ok ) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << carShop.specialization << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Есть страховка?  (0 или 1)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int b;
        inputStream >> b;
        if (inputStream.status() != QTextStream::Ok || (b != 0 && b != 1)) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            carShop.hasInsurance = (b == 1);
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << (carShop.hasInsurance ? "Есть страховка" : "Нет Страховки") << '\n';
        }
        ui->lineEdit->setText(textInput);

        file.write(reinterpret_cast<const char*>(&carShop), sizeof(carShop));
        file.close();
    }
    ui->textEdit->setText(textOutput);
    outputStream << "Данные успешно записаны в бинарный файл " << fileName << "\n";
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamBinFileDataStruct(const QString &fileName)
{
    std::ifstream file(fileName.toStdString(), std::ios::binary);
    outputStream << "Вы выбрали пункт 8\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.is_open()) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        CarRepairShop carShop;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&carShop), sizeof(carShop));

            if (file.eof()) break;
            outputStream << "Количество работников: " << carShop.numberOfEmployees << " ; ";
            outputStream << "Средняя почасовая оплата: " << carShop.averageHourlyRate << " ; ";
            outputStream << "Специализация: " << carShop.specialization << " ; ";
            outputStream << "Страховка: " << (carShop.hasInsurance ? "Есть" : "Нет") << "\n";
        }
        file.close();
    }

    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::textFile   (const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 9\nВведите текст для добавления в файл " << fileName;
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    while (textInput.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        fileStream << textInput << "\n";
        file.close();
        textInput.clear();
        ui->lineEdit->setText(textInput);
        inputStream.readAll();
        outputStream << "Текст успешно добавлен в файл " << fileName << "\n";
    }

    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly()) {
        textInput += ui->lineEdit->text();
    }
}

