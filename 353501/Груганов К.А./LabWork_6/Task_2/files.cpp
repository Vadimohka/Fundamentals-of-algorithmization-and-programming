#include "files.h"
#include <QDebug>
#include <QtWidgets>
#include "house.h"

Files::Files(QTextBrowser *browser)
    : outputStream(&outputText)
{
    output = browser;
}

void Files::CreateNonExistingFiles()
{
    for (auto fileName : files) {
        QFile file(fileName);
        if (!file.exists()) {
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::warning(nullptr,
                                     QMessageBox::tr("File Creation"),
                                     "Failed to create file: " + fileName,
                                     QMessageBox::Ok | QMessageBox::NoButton);
                return;
            }
            file.close();
        }
    }
}

void Files::SaveTextToFile(const QString &fileName)
{
    qDebug() << "Saving to file:" << fileName;
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        QString text = QInputDialog::getText(nullptr, QInputDialog::tr("Input"), "Enter text:");
        if (text.isEmpty()) {
            qDebug() << "No text entered";
            return;
        }
        for (int i = 0; i < text.length(); ++i) {
            fileStream << text[i];
        }
        file.close();
    }
}

void Files::LoadTextFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        while (!fileStream.atEnd()) {
            QChar c;
            fileStream >> c;
            outputStream << c;
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void Files::SaveArrayToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int size = QInputDialog::getInt(nullptr,
                                    QInputDialog::tr("Array creation"),
                                    "Enter number of array elements:");
    float f;

    for (int i = 0; i < size; ++i) {
        f = QInputDialog::getDouble(nullptr,
                                    QInputDialog::tr("Input"),
                                    "Enter element #" + QString::number(i) + ":");
        fileStream << f << ' ';
    }
    file.close();
}

void Files::LoadArrayFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        while (!fileStream.atEnd()) {
            QString data = fileStream.readAll();
            QStringList floats = data.split("_", Qt::SkipEmptyParts);
            for (auto f : floats) {
                outputStream << f << " ";
            }
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void Files::SaveStructToFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QTextStream out(&file);
    bool ok;
    int floors = QInputDialog::getInt(nullptr,
                                      QObject::tr("Введите количество этажей"),
                                      QObject::tr("Этажи:"),
                                      1,
                                      1,
                                      10,
                                      1,
                                      &ok);
    if (!ok) {
        QMessageBox::warning(nullptr,
                             QObject::tr("Ошибка"),
                             QObject::tr("Некорректный ввод количества этажей"));
        return;
    }

    double area = QInputDialog::getDouble(nullptr,
                                          QObject::tr("Введите площадь"),
                                          QObject::tr("Площадь:"),
                                          1.0,
                                          1.0,
                                          1000.0,
                                          2,
                                          &ok);
    if (!ok) {
        QMessageBox::warning(nullptr,
                             QObject::tr("Ошибка"),
                             QObject::tr("Некорректный ввод площади"));
        return;
    }

    char type = QInputDialog::getText(nullptr,
                                      QObject::tr("Введите тип дома"),
                                      QObject::tr("Тип:"),
                                      QLineEdit::Normal,
                                      "",
                                      &ok)[0]
                    .toLatin1();
    if (!ok) {
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr,
                                  QObject::tr("Есть гараж?"),
                                  QObject::tr("У дома есть гараж?"),
                                  QMessageBox::Yes | QMessageBox::No);
    bool hasGarage = (reply == QMessageBox::Yes);

    out << floors << '|' << area << '|' << type << '|' << (hasGarage ? "true" : "false") << '\n';

    file.close();
}

void Files::LoadStructsFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        while (!fileStream.atEnd()) {
            QString line = fileStream.readLine();
            QStringList parts = line.split('|');
            if (parts.size() == 4) {
                int floors = parts[0].toInt();
                double area = parts[1].toDouble();
                char type = parts[2].toLatin1()[0];
                bool hasGarage = (parts[3] == "true");

                outputStream << "Floors: " << floors << "\n";
                outputStream << "Area: " << area << "\n";
                outputStream << "Type: " << type << "\n";
                outputStream << "Has Garage: " << (hasGarage ? "Yes" : "No") << "\n";
                outputStream << "-------------------\n";
            }
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void Files::SaveStructToBinaryFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    House house;

    house.floors = 5;
    house.area = 350.5;
    house.type = 'A';
    house.hasGarage = true;

    file.write(reinterpret_cast<const char *>(&house), sizeof(house));

    file.close();
}

void Files::LoadStructsFromBinaryFile(const QString &fileName)
{
    QFile file(fileName);
    QDataStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        while (!fileStream.atEnd()) {
            House temp;
            fileStream.readRawData(reinterpret_cast<char *>(&temp), sizeof(temp));
            outputStream << temp.floors << "|" << temp.area << "|" << temp.type << "|"
                         << (temp.hasGarage ? "true" : "false") << "|";
        }
        file.close();
        output->setText(outputText);
        outputText.clear();
    }
}

void Files::SaveSentenceToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        QString text = QInputDialog::getText(nullptr, QInputDialog::tr("Input"), "Enter sentence:");
        ;
        fileStream << text << "\n";
        file.close();
    }
}

void Files::LoadSentencesFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("File Open"),
                              "Failed to open file: " + fileName,
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else {
        while (!fileStream.atEnd()) {
            QString s = fileStream.readLine();
            outputStream << s << "\n";
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

