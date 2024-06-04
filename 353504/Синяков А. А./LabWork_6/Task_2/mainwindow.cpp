#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <limits.h>
#include <float.h>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->switchBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::showMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu(int menuChoice) {
    switch (menuChoice) {
    case 1:
        writeTextToFile();
        break;
    case 2:
        readTextFromFile();
        break;
    case 3:
        writeArrayToFile();
        break;
    case 4:
        readArrayFromFile();
        break;
    case 5:
        writeContinentToFile();
        break;
    case 6:
        readStructuresFromFile();
        break;
    case 7:
        saveContinentToFile();
        break;
    case 8:
        readContinentFromFile();
        break;
    case 9:
        WriteAndSaveSentences();
        break;
    case 10:
        ReadSentences();
        break;
    case 11:
        exit(0);
        break;
    default:
        break;
    }
}
void MainWindow::writeTextToFile() {
    QString text = QInputDialog::getText(nullptr, "Text input", "Введите текст. Для завершения ввода нажмите клавишу Enter");
    QFile file("СиняковЛаб20.txt");
    QString currentPath = QDir::currentPath();
    qDebug() << "Current path:" << currentPath;
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < text.length(); ++i) {
            out << text.at(i);
        }
        file.close();
        ui->textEdit->append("Данные успешно сохранены"); // Используем append() для добавления нового текста
    } else {
        ui->textEdit->append("Не удалось открыть файл для записи."); // Используем append() для добавления нового текста
    }
    file.close(); // Закрытие файла
}

void MainWindow::readTextFromFile() {
    QString fileName = "СиняковЛаб20.txt";
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setPlainText(text);
        file.close();
        ui->textEdit->append("Данные успешно загружены"); // Используем append() для добавления нового текста
    } else {
        ui->textEdit->append("Не удалось открыть файл для чтения."); // Используем append() для добавления нового текста
    }
    file.close(); // Закрытие файла
}

void MainWindow::writeArrayToFile() {
    QString fileName = "СиняковЛаб20_0.txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        bool ok;
        int size = QInputDialog::getInt(this, "Введите размер массива", "Размер массива:", 0, 0, INT_MAX, 1, &ok);
        if (ok) {
            QStringList values;
            for (int i = 0; i < size; ++i) {
                double value = QInputDialog::getDouble(this, QString("Введите элемент массива %1").arg(i + 1), QString("Элемент %1:").arg(i + 1), 0.0, -DBL_MAX, DBL_MAX, 1, &ok);
                if (ok) {
                    values.append(QString::number(value));
                } else {
                    break;
                }
            }
            if (ok) {
                out << values.join("<");
                ui->textEdit->append("Данные массива успешно сохранены"); // Используем append() для добавления нового текста
            }
        }
        file.close();
    } else {
        ui->textEdit->append("Не удалось открыть файл для записи."); // Используем append() для добавления нового текста
    }
    file.close(); // Закрытие файла
}

void MainWindow::readArrayFromFile() {
    QString fileName = "СиняковЛаб20_0.txt";
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine(); // Считываем всю строку из файла
        QStringList values = line.split("<"); // Разделяем строку на элементы массива
        QString arrayStr = values.join(" "); // Объединяем элементы массива с пробелами
        ui->textEdit->append(arrayStr); // Добавляем новые данные к существующим
        file.close();
    } else {
        ui->textEdit->setText("Не удалось открыть файл для чтения.");
    }
    file.close(); // Закрытие файла
}

void MainWindow::writeContinentToFile() {
    // Диалоговые окна для ввода данных
    bool ok;
    int area = QInputDialog::getInt(this, "Введите площадь", "Площадь континента:", 0, 0, INT_MAX, 1, &ok);
    if (!ok) return; // Пользователь отменил ввод
    double averageHeight = QInputDialog::getDouble(this, "Введите среднюю высоту", "Средняя высота континента:", 0.0, -DBL_MAX, DBL_MAX, 1, &ok);
    if (!ok) return;
    QString firstLetter = QInputDialog::getText(this, "Введите первую букву", "Первая буква названия континента:", QLineEdit::Normal, "", &ok);
    if (!ok || firstLetter.isEmpty() || firstLetter.length() > 1) return;
    int hasOceanCoastInt = QInputDialog::getInt(this, "Наличие океанского побережья", "Континент имеет океанское побережье? (Введите 1 для Да, 0 для Нет):", 0, 0, 1, 1, &ok);
    if (!ok) return;
    bool hasOceanCoast = (hasOceanCoastInt == 1);
    QString name = QInputDialog::getText(this, "Введите название", "Название континента:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;
    QStringList climateDataInput = QInputDialog::getText(this, "Введите климатические данные", "Климатические данные (разделите значения запятой):", QLineEdit::Normal, "", &ok).split(",");
    if (!ok || climateDataInput.size() != Continent::climateDataSize) return;

    // Запись данных в объект continent
    continent.area = area;
    continent.averageHeight = averageHeight;
    continent.firstLetter = firstLetter.at(0).toLatin1();
    continent.hasOceanCoast = hasOceanCoast;
    strncpy(continent.name, name.toUtf8().constData(), Continent::stringLength);
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        continent.climateData[i] = climateDataInput[i].toInt(&ok);
        if (!ok) return;
    }

    // Запись данных в файл
    QString fileName = "СиняковЛаб20_1.txt";
    QFile file(fileName);
    QString currentPath = QDir::currentPath();
    qDebug() << "Current path:" << currentPath;
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Area: " << continent.area << "\n";
        out << "Average Height: " << continent.averageHeight << "\n";
        out << "First Letter: " << continent.firstLetter << "\n";
        out << "Has Ocean Coast: " << (continent.hasOceanCoast ? "true" : "false") << "\n";
        out << "Name: " << continent.name << "\n";
        out << "Climate Data: ";
        for (int i = 0; i < Continent::climateDataSize; ++i) {
            out << continent.climateData[i];
            if (i < Continent::climateDataSize - 1) out << ", ";
        }
        out << "\n\n";

        file.close();
        ui->textEdit->append("Данные о континенте успешно сохранены");
    } else {
        ui->textEdit->setText("Не удалось открыть файл для записи.");
    }
    file.close();
}
void MainWindow::readStructuresFromFile() {
    QFile file("СиняковЛаб20_1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textEdit->append("Не удалось открыть файл для чтения.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << "Line:" << line; // Добавляем вывод строки для отладки
        QStringList fields = line.split(" | ", Qt::SkipEmptyParts); // Изменяем разделитель на " | "
        if (!fields.isEmpty()) { // Проверяем, что список полей не пустой
            QString output = fields.join(" | "); // Просто объединяем поля снова через разделитель
            ui->textEdit->append(output);
        }
    }
    file.close();
    ui->textEdit->append("Чтение структур из файла завершено");
}

void MainWindow::saveContinentToFile() {
    // Диалоговые окна для ввода данных
    bool ok;
    int area = QInputDialog::getInt(this, "Введите площадь", "Площадь континента:", 0, 0, INT_MAX, 1, &ok);
    if (!ok) return; // Пользователь отменил ввод
    double averageHeight = QInputDialog::getDouble(this, "Введите среднюю высоту", "Средняя высота континента:", 0.0, -DBL_MAX, DBL_MAX, 1, &ok);
    if (!ok) return;
    QString firstLetter = QInputDialog::getText(this, "Введите первую букву", "Первая буква названия континента:", QLineEdit::Normal, "", &ok);
    if (!ok || firstLetter.isEmpty() || firstLetter.length() > 1) return;
    int hasOceanCoastInt = QInputDialog::getInt(this, "Наличие океанского побережья", "Континент имеет океанское побережье? (Введите 1 для Да, 0 для Нет):", 0, 0, 1, 1, &ok);
    if (!ok) return;
    bool hasOceanCoast = (hasOceanCoastInt == 1);
    QString name = QInputDialog::getText(this, "Введите название", "Название континента:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;
    QStringList climateDataInput = QInputDialog::getText(this, "Введите климатические данные", "Климатические данные (разделите значения запятой):", QLineEdit::Normal, "", &ok).split(",");
    if (!ok || climateDataInput.size() != Continent::climateDataSize) return;

    // Создаем объект континента и заполняем его данными
    Continent continent;
    continent.area = area;
    continent.averageHeight = averageHeight;
    continent.firstLetter = firstLetter.at(0).toLatin1();
    continent.hasOceanCoast = hasOceanCoast;
    strncpy(continent.name, name.toUtf8().constData(), Continent::stringLength);
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        continent.climateData[i] = climateDataInput[i].toInt(&ok);
        if (!ok) return;
    }

    // Открываем файл для записи в режиме Append (дозаписи)
    QFile file("СиняковЛаб20_2.bin");
    if (!file.open(QIODevice::Append)) {
        ui->textEdit->append("Не удалось открыть файл для записи.");
        return;
    }

    // Создаем поток для записи в файл в бинарном формате
    QDataStream out(&file);

    // Записываем данные структуры в файл
    out << continent;

    // Закрываем файл
    file.close();

    ui->textEdit->append("Данные о континенте успешно сохранены");
}

void MainWindow::readContinentFromFile() {
    // Открываем файл для чтения
    QFile file("СиняковЛаб20_2.bin");
    if (!file.open(QIODevice::ReadOnly)) {
        ui->textEdit->append("Не удалось открыть файл для чтения.");
        return;
    }

    // Создаем поток для чтения из файла в бинарном формате
    QDataStream in(&file);

    // Читаем данные из файла до конца
    while (!in.atEnd()) {
        Continent continent;

        // Читаем данные структуры из файла
        in >> continent;

        // Выводим содержимое полей структуры на экран
        QString output = QString("Area: %1 ; Average Height: %2 ; First Letter: %3 ; Has Ocean Coast: %4 ; Name: %5 ; Climate Data: %6")
                             .arg(continent.area)
                             .arg(continent.averageHeight)
                             .arg(continent.firstLetter)
                             .arg(continent.hasOceanCoast ? "true" : "false")
                             .arg(continent.name)
                             .arg(continent.climateData[0]);
        for (int i = 1; i < Continent::climateDataSize; ++i) {
            output += QString(", %1").arg(continent.climateData[i]);
        }
        ui->textEdit->append(output);
    }

    // Закрываем файл
    file.close();

    ui->textEdit->append("Чтение структур из файла завершено");
}

void MainWindow::WriteAndSaveSentences()
{
    // Запрос у пользователя ввода предложения
    QString sentence = QInputDialog::getText(nullptr, "Введите предложение", "Введите предложение:");

    // Открытие файла для добавления предложения
    QFile file("СиняковЛаб20_3.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл для записи");
        return;
    }

    // Запись предложения в файл
    QTextStream out(&file);
    out << sentence << '\n';

    // Закрытие файла
    file.close();

    // Сообщение об успешном сохранении
    QMessageBox::information(this, "Файл сохранен", "Предложение успешно сохранено");
}

void MainWindow::ReadSentences()
{
    // Открытие файла для чтения
    QFile file("СиняковЛаб20_3.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл для чтения");
        return;
    }

    // Чтение содержимого файла
    QTextStream in(&file);
    QString text;
    while (!in.atEnd()) {
        QString line = in.readLine();
        text += line + '\n'; // Добавляем новую строку после каждого предложения
    }

    // Закрытие файла
    file.close();

    // Вывод содержимого файла в QTextEdit
    ui->textEdit->append(text);
}
