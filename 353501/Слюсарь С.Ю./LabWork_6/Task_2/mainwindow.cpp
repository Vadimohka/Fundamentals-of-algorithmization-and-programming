#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputStream(&textInput)
    , outputStream(&textOutput)
{
    ui->setupUi(this);
    setFixedSize(871, 612);
    createFilesIfNotExist();
    ui->textEdit->setReadOnly(true);
    ui->lineEdit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu()
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
        int choice;
        inputStream >> choice;
        if (inputStream.status() != QTextStream::Ok) {
            textInput.clear();
            inputStream.resetStatus();
        } else {
            textInput.remove(0, inputStream.pos());
            outputStream << choice << '\n';
        }
        inputStream.seek(0);
        ui->lineEdit->setText(textInput);
        printMenu(choice);
    }
}

void MainWindow::printMenu(int choice)
{
    QString fileName;
    switch (choice) {
    case 1:
        fileName = "SlusarLab6.txt";
        saveTextToFile(fileName);
        break;
    case 2:
        fileName = "SlusarLab6.txt";
        displayFileContents(fileName);
        break;
    case 3:
        fileName = "SlusarLab6_0.txt";
        saveCharArrayToFile(fileName);
        break;
    case 4:
        fileName = "SlusarLab6_0.txt";
        displayCharArrayFromFile(fileName);
        break;
    case 5:
        fileName = "SlusarLab6_1.txt";
        saveAnimalDataToFile(fileName);
        break;
    case 6:
        fileName = "SlusarLab6_1.txt";
        displayAnimalDataFromFile(fileName);
        break;
    case 7:
        fileName = "SlusarLab6_2.bin";
        saveAnimalDataToBinaryFile(fileName);
        break;
    case 8:
        fileName = "SlusarLab6_2.bin";
        displayAnimalDataFromBinaryFile(fileName);
        break;
    case 9:
        fileName = "SlusarLab6_3.txt";
        appendTextToFile(fileName);
        break;
    case 10:
        fileName = "SlusarLab6_3.txt";
        displayFileContents(fileName);
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

void MainWindow::createFilesIfNotExist()
{
    QStringList filesToCreate = {"SlusarLab6.txt", "SlusarLab6_0.txt", "SlusarLab6_1.txt", "SlusarLab6_2.bin", "SlusarLab6_3.txt"};
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

void MainWindow::saveTextToFile(const QString &fileName)
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

void MainWindow::displayFileContents(const QString &fileName)
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

void MainWindow::saveCharArrayToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 3\nВведите размер массива и массив типа char, разделяя элементы символом пробела\n";
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
            char c;
            outputStream << "Введите " << i+1 << "-й из " << n << " символ желаемого слова!!!";
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
            fileStream << c << '~';
        }
        file.close();
        if (ok) outputStream << "\nМассив записан в файл " << fileName << "\n";
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::displayCharArrayFromFile(const QString &fileName)
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
            QStringList charArray = line.split("~", Qt::SkipEmptyParts);
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

void MainWindow::saveAnimalDataToFile(const QString &fileName)
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
        Animal animal;
        outputStream << "Введте возраст(int)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> animal.age;
        if (inputStream.status() != QTextStream::Ok || animal.age < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << animal.age << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте вес(double)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> animal.weight;
        if (inputStream.status() != QTextStream::Ok || animal.weight < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << animal.weight << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте тип диеты (один символ)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> animal.dietType;
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
            outputStream << animal.dietType << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте является ли мужским (0 или 1)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int isMale;
        inputStream >> isMale;
        if (inputStream.status() != QTextStream::Ok || (isMale != 0 && isMale != 1)) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            animal.isMale = (isMale == 1);
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << (animal.isMale ? "Мужской" : "Женский") << '\n';
        }
        ui->lineEdit->setText(textInput);
        fileStream << animal.age << " " << animal.weight << " " << animal.dietType << " " << (animal.isMale ? "1" : "0") << "\n";
        file.close();
    }
    outputStream << "\nДанные о животном успешно записаны в файл " << fileName << "\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::displayAnimalDataFromFile(const QString &fileName)
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
            QStringList animalData = line.split(" ", Qt::SkipEmptyParts);
            if (animalData.size() != 4) {
                outputStream << "\nНеверный формат строки в файле.\n";
                continue;
            }
            Animal animal;
            animal.age = animalData[0].toInt();
            animal.weight = animalData[1].toDouble();
            animal.dietType = animalData[2][0].toLatin1();
            animal.isMale = (animalData[3].toInt() != 0);

            outputStream << "Возраст: " << animal.age << " ; ";
            outputStream << "Вес: " << animal.weight << " ; ";
            outputStream << "Тип диеты: " << animal.dietType << " ; ";
            outputStream << "Мужской: " << (animal.isMale ? "Да" : "Нет") << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveAnimalDataToBinaryFile(const QString &fileName)
{
    std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    outputStream << "Вы выбрали пункт 5\nВведите данные об животном: возраст, вес, тип диеты (один символ), является ли мужским (0 или 1)\n";
    ui->lineEdit->clear();
    if (!file.is_open()) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        Animal animal;
        outputStream << "Введте возраст(int)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> animal.age;
        if (inputStream.status() != QTextStream::Ok || animal.age < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << animal.age << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте вес(double)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> animal.weight;
        if (inputStream.status() != QTextStream::Ok || animal.weight < 0) {
            outputStream << "Неверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << animal.weight << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте тип диеты (один символ)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> animal.dietType;
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
            outputStream << animal.dietType << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте является ли мужским (0 или 1)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int isMale;
        inputStream >> isMale;
        if (inputStream.status() != QTextStream::Ok || (isMale != 0 && isMale != 1)) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            animal.isMale = (isMale == 1);
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << (animal.isMale ? "Мужской" : "Женский") << '\n';
        }
        ui->lineEdit->setText(textInput);

        file.write(reinterpret_cast<const char*>(&animal), sizeof(animal));
        file.close();
    }
    ui->textEdit->setText(textOutput);
    outputStream << "Данные о животном успешно записаны в бинарный файл " << fileName << "\n";
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::displayAnimalDataFromBinaryFile(const QString &fileName)
{
    std::ifstream file(fileName.toStdString(), std::ios::binary);
    outputStream << "Вы выбрали пункт 8\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.is_open()) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        Animal animal;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&animal), sizeof(animal));
            if (file.eof()) break;
            outputStream << "Возраст: " << animal.age << " ; ";
            outputStream << "Вес: " << animal.weight << " ; ";
            outputStream << "Тип питания: " << animal.dietType << " ; ";
            outputStream << "Пол: " << (animal.isMale ? "Мужской" : "Женский") << "\n";
        }
        file.close();
    }

    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::appendTextToFile(const QString &fileName)
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

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setEnabled(true);
    showMenu();
}

