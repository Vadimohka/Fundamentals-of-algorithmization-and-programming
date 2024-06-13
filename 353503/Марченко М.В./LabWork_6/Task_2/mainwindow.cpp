#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QFile>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QLineEdit>
#include "Shoes.h"
#include <fstream>
#include <QRegularExpressionValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::slot1);
}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::slot1(){

    runMenu();
}

int MainWindow::showMenu()
{
    bool ok;
    QString Task = "1 Записать абзац в файл\n"
                   "2 Считать абзац с файла\n"
                   "3 Записать массив в файл\n"
                   "4 Считать массив с файла\n"
                   "5 Записать структуру в файл\n"
                   "6 Считать структуры с файла\n"
                   "7 Записать структуру в бинарный файл\n"
                   "8 Считать структуры с бинарного файла\n"
                   "9 Записать предложение в файл\n"
                   "10 Считать предложения с файла\n";
    int choice = QInputDialog::getInt(this, "Главное меню", Task, 0, 1, 10, 1, &ok);
    if (ok)
        return choice;
    else
        return -1;
}

void MainWindow::runMenu()
{
    while (true)
    {
        int choice = showMenu();
        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case -1:
            QApplication::quit();
            return;
        default:
            QMessageBox::warning(this, "Ошибка", "Неверный выбор");
            break;
        }
    }
}

void MainWindow::task1()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Введите абзац");
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    textEdit = new QPlainTextEdit;
    textEdit->setMinimumSize(QSize(300, 300));
    layout->addWidget(textEdit);
    connect(textEdit, &QPlainTextEdit::textChanged, this, &MainWindow::onEnterPressed);
    dialog->exec();
}

void MainWindow::onEnterPressed(){
    QString allText = textEdit->toPlainText();
    if (allText.contains("\n")) {
        allText.remove(QChar('\n'));
        qDebug()<<allText;
        saveTextToFile(allText);
        textEdit->clear();
        dialog->accept();
    }
}

void MainWindow::saveTextToFile(const QString& text)
{
    QFile file("/home/masha/OAiP/Lab6/untitled/MarchenkoLab6.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        for(int i = 0; i < text.size(); ++i){
            wchar_t wch = text[i].unicode();
            file.write((const char*)&wch, sizeof(wchar_t));
        }
        file.close();
        QMessageBox::information(this, "Save", "Текст сохранен в файл MarchenkoLab6.txt");
    } else {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
    }
}

void MainWindow::task2()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Содержимое файла с абзацем");
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QTextEdit* textEdit = new QTextEdit;
    textEdit->setMinimumSize(QSize(300, 300));
    layout->addWidget(textEdit);
    QFile file("/home/masha/OAiP/Lab6/untitled/MarchenkoLab6.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QDataStream ds (&file);
        QString text;
        while(!ds.atEnd()){
            wchar_t wch;
            ds.readRawData((char*)&wch, sizeof(wchar_t));
            text += QChar(wch);
        }
        textEdit->setText(text);
        file.close();
        qDebug() << text;
    } else {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
    }
    dialog->exec();
}

void MainWindow::task3()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Вариант 18 – double, разделитель '='");
    QLabel* label1 = new QLabel("Размер массива:");
    spinBox= new QSpinBox;
    spinBox->setMinimum(1);
    spinBox->setMaximum(100);

    QLabel* label2 = new QLabel("Введите элементы массива через =:");
    lineEdit = new QLineEdit;

    QPushButton* saveButton = new QPushButton("Сохранить");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(spinBox);
    layout->addWidget(label2);
    layout->addWidget(lineEdit);
    layout->addWidget(saveButton);

    dialog->setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveArrayToFile);
    dialog->exec();
}

void MainWindow::saveArrayToFile() {
    int size = spinBox->value();
    QVector<double> array(size);

    QStringList elements = lineEdit->text().trimmed().split('=');
    if (elements.size() != size) {
        QMessageBox::critical(this, "Ошибка", "Количество элементов не соответствует размеру массива.");
        return;
    }

    for (int i = 0; i < size; ++i) {
        bool ok;
        double element = elements[i].toDouble(&ok);
        if (ok) {
            array[i] = element;
        } else {
            QMessageBox::critical(this, "Ошибка", "Введено некорректное значение.");
            return;
        }
    }

    QFile file("/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_0.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (int i = 0; i < size - 1; ++i) {
            out << array[i] << "=";
        }
        out << array[size - 1];

        file.close();
        QMessageBox::information(this, "Save", "Массив сохранен в файл MarchenkoLab6_0.txt.");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
    }
    dialog->accept();
}

void MainWindow::task4()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Содержимое файла с массивами");
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QTextEdit* textEdit = new QTextEdit;
    textEdit->setMinimumSize(QSize(300, 300));
    layout->addWidget(textEdit);
    QFile file("/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_0.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString text;
        QString line;
        while (!in.atEnd()) {
            in >> line;
            QStringList values = line.split('=');
            for (const QString& str : values) {
                bool ok;
                double value = str.toDouble(&ok);
                if (ok) {
                    text += QString::number(value) + " ";
                }
            }
        }
        textEdit->setText(text);
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
    }
    dialog->exec();
}

void MainWindow::task5()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Введите структуру");
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* amountLabel = new QLabel("Количество:");
    QLineEdit* amountLineEdit = new QLineEdit;
    QLabel* priceLabel = new QLabel("Цена:");
    QLineEdit* priceLineEdit = new QLineEdit;
    QLabel* genderLabel = new QLabel("Пол (f/m):");
    QLineEdit* genderLineEdit = new QLineEdit;
    QLabel* inStockLabel = new QLabel("В наличии (yes/no):");
    QLineEdit* inStockLineEdit = new QLineEdit;

    layout->addWidget(amountLabel);
    layout->addWidget(amountLineEdit);
    layout->addWidget(priceLabel);
    layout->addWidget(priceLineEdit);
    layout->addWidget(genderLabel);
    layout->addWidget(genderLineEdit);
    layout->addWidget(inStockLabel);
    layout->addWidget(inStockLineEdit);
    QPushButton* saveButton = new QPushButton("Сохранить");
    QPushButton* closeButton = new QPushButton("Закрыть");
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(closeButton);
    layout->addLayout(buttonLayout);

    Shoes shoe;

    connect(saveButton, &QPushButton::clicked, [this, &shoe, amountLineEdit, priceLineEdit, genderLineEdit, inStockLineEdit]() {
        bool ok;
        int amount = amountLineEdit->text().toInt(&ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'Количество'.");
            return;
        }
        shoe.amount = amount;

        double price = priceLineEdit->text().toDouble(&ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'Цена'.");
            return;
        }
        shoe.price = price;

        QString genderText = genderLineEdit->text().toLower();
        if (genderText == "f") {
            shoe.gender = 'f';
        } else if (genderText == "m") {
            shoe.gender = 'm';
        } else {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'Пол'.");
            return;
        }

        QString inStockText = inStockLineEdit->text().toLower();
        if (inStockText == "yes") {
            shoe.inStock = true;
        } else if (inStockText == "no") {
            shoe.inStock = false;
        } else {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'В наличии'.");
            return;
        }

        QString filename = "/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_1.txt";
        std::ofstream file(filename.toStdString(), std::ios::app);
        if (file.is_open()) {
            file << shoe.amount << "\n";
            file << std::fixed << std::setprecision(2) << shoe.price << "\n";
            file << shoe.gender << "\n";
            file << (shoe.inStock ? "Да" : "Нет") << "\n";
            file << Shoes::getMaterialsString().toStdString() << "\n";
            file << Shoes::getSizesString().toStdString() << "\n";
            file.close();
            QMessageBox::information(this, "Сохранено", "Данные о обуви сохранены в файл.");
             dialog->accept();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
        }
    });

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);

    dialog->exec();
}

void MainWindow::task6()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Содержимое файла");
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QString filename = "/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_1.txt";
    std::ifstream file(filename.toStdString());

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            Shoes shoe;
            shoe.amount = std::stoi(line);
            std::getline(file, line);
            shoe.price = std::stod(line);
            std::getline(file, line);
            shoe.gender = line[0];
            std::getline(file, line);
            shoe.inStock = (line == "Да");
            std::getline(file, line);
            std::string materials = line;
            std::getline(file, line);
            std::string sizes = line;


            QString output = QString("%1 | %2 | %3 | %4 | %5 | %6")
                                 .arg(QString::number(shoe.amount))
                                 .arg(QString::number(shoe.price, 'f', 2))
                                 .arg(shoe.gender)
                                 .arg(shoe.inStock ? "в наличии" : "не в наличии")
                                 .arg(QString::fromStdString(materials))
                                 .arg(QString::fromStdString(sizes));


            QLabel* label = new QLabel(output);
            layout->addWidget(label);
        }

        file.close();
        dialog->accept();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
    }

    QPushButton* closeButton = new QPushButton("Закрыть");
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);
    layout->addWidget(closeButton);

    dialog->exec();
}

void MainWindow::task7()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Введите структуру");
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QLabel* amountLabel = new QLabel("Количество:");
    QLineEdit* amountLineEdit = new QLineEdit;
    QLabel* priceLabel = new QLabel("Цена:");
    QLineEdit* priceLineEdit = new QLineEdit;
    QLabel* genderLabel = new QLabel("Пол (f/m):");
    QLineEdit* genderLineEdit = new QLineEdit;
    QLabel* inStockLabel = new QLabel("В наличии (yes/no):");
    QLineEdit* inStockLineEdit = new QLineEdit;

    layout->addWidget(amountLabel);
    layout->addWidget(amountLineEdit);
    layout->addWidget(priceLabel);
    layout->addWidget(priceLineEdit);
    layout->addWidget(genderLabel);
    layout->addWidget(genderLineEdit);
    layout->addWidget(inStockLabel);
    layout->addWidget(inStockLineEdit);
    QPushButton* saveButton = new QPushButton("Сохранить");
    QPushButton* closeButton = new QPushButton("Закрыть");
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(closeButton);
    layout->addLayout(buttonLayout);
    Shoes shoe;

    connect(saveButton, &QPushButton::clicked, [this, &shoe, amountLineEdit, priceLineEdit, genderLineEdit, inStockLineEdit]() {
        bool ok;
        int amount = amountLineEdit->text().toInt(&ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'Количество'.");
            return;
        }
        shoe.amount = amount;

        double price = priceLineEdit->text().toDouble(&ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'Цена'.");
            return;
        }
        shoe.price = price;

        QString genderText = genderLineEdit->text().toLower();
        if (genderText == "f") {
            shoe.gender = 'f';
        } else if (genderText == "m") {
            shoe.gender = 'm';
        } else {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'Пол'.");
            return;
        }

        QString inStockText = inStockLineEdit->text().toLower();
        if (inStockText == "yes") {
            shoe.inStock = true;
        } else if (inStockText == "no") {
            shoe.inStock = false;
        } else {
            QMessageBox::critical(this, "Ошибка", "Некорректное значение в поле 'В наличии'.");
            return;
        }

        QString filename = "/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_2.bin";
        std::ofstream file(filename.toStdString(), std::ios::binary | std::ios::app);

        if (file.is_open()) {
            file.write(reinterpret_cast<char*>(&shoe.amount), sizeof(shoe.amount));
            file.write(reinterpret_cast<char*>(&shoe.price), sizeof(shoe.price));
            file.write(reinterpret_cast<char*>(&shoe.gender), sizeof(shoe.gender));
            file.write(reinterpret_cast<char*>(&shoe.inStock), sizeof(shoe.inStock));
            file.write(Shoes::getMaterialsString().toStdString().c_str(), Shoes::getMaterialsString().length());
            file.write(Shoes::getSizesString().toStdString().c_str(), Shoes::getSizesString().length());
            file.close();
            QMessageBox::information(this, "Сохранено", "Данные о обуви сохранены в файл.");
            dialog->accept();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
        }
    });

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);

    dialog->exec();
}

void MainWindow::task8()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Содержимое бинарного файла");
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QString filename = "/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_2.bin";
    std::ifstream file(filename.toStdString(), std::ios::binary);

    if (file.is_open())
    {
        Shoes shoe;
        while (file.read(reinterpret_cast<char*>(&shoe.amount), sizeof(shoe.amount)) &&
               file.read(reinterpret_cast<char*>(&shoe.price), sizeof(shoe.price)) &&
               file.read(reinterpret_cast<char*>(&shoe.gender), sizeof(shoe.gender)) &&
               file.read(reinterpret_cast<char*>(&shoe.inStock), sizeof(shoe.inStock)))
        {
            std::string materials(Shoes::getMaterialsString().length(), '\0');
            std::string sizes(Shoes::getSizesString().length(), '\0');
            file.read(&materials[0], materials.length());
            file.read(&sizes[0], sizes.length());

            QString output = QString("%1 ; %2 ; %3 ; %4 ; %5 ; %6")
                                 .arg(QString::number(shoe.amount))
                                 .arg(QString::number(shoe.price, 'f', 2))
                                 .arg(shoe.gender)
                                 .arg(shoe.inStock ? "в наличии" : "не в наличии")
                                 .arg(QString::fromStdString(materials))
                                 .arg(QString::fromStdString(sizes));

            QLabel* label = new QLabel(output);
            layout->addWidget(label);
        }

        file.close();
        dialog->accept();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
    }

    QPushButton* closeButton = new QPushButton("Закрыть");
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);
    layout->addWidget(closeButton);

    dialog->exec();
}

void MainWindow::task9()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Введите предложение");

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLineEdit* lineEdit = new QLineEdit;
    lineEdit->setMinimumSize(QSize(200, 30));
    layout->addWidget(lineEdit);
    QRegularExpression rx("[^\\.\\?!]*");
    QValidator* validator = new QRegularExpressionValidator(rx, this);
    lineEdit->setValidator(validator);

    connect(lineEdit, &QLineEdit::returnPressed, [this, lineEdit]()  {

        QString sentence = lineEdit->text();

        QString filename = "/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_3.txt";
        QFile file(filename);
        if (file.open(QIODevice::Append | QIODevice::Text)) {

            QTextStream out(&file);
            out << sentence << "\n";
            file.close();
            QMessageBox::information(this, "Save", "Предложение сохранено в файл MarchenkoLab6_3.txt");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
        }
        dialog->accept();
    });

    layout->addWidget(lineEdit);

    dialog->exec();
}

void MainWindow::task10()
{
    dialog = new QDialog(this);
    dialog->setWindowTitle("Содержимое файла с предложениями");
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QString filename = "/home/masha/OAiP/Lab6/untitled/MarchenkoLab6_3.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QLabel* label = new QLabel(line);
            layout->addWidget(label);
        }
        file.close();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
    }
    dialog->exec();
}
