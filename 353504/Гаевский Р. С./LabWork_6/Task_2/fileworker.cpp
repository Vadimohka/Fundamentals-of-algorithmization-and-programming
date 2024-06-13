#include "fileworker.h"

FileWorker::FileWorker(QTextBrowser* browser)
    : outputStream(&outputText)
{
    output = browser;
    structDialog = new StructInputDialog(nullptr, &a);
}

void FileWorker::CreateNonExistingFiles()
{
    for (auto fileName : files)
    {
        QFile file(fileName);
        if (!file.exists())
        {
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(nullptr, QMessageBox::tr("File Creation"), "Failed to create file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
                return;
            }
            file.close();
        }
    }
}

void FileWorker::SaveTextToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        QString text = QInputDialog::getText(nullptr, QInputDialog::tr("Input"), "Enter text:");
        for (int i = 0; i < text.length(); ++i)
        {
            fileStream << text[i];
        }
        file.close();
    }
}

void FileWorker::LoadTextFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        while (!fileStream.atEnd())
        {
            QChar c;
            fileStream >> c;
            outputStream << c;
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void FileWorker::SaveArrayToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int size = QInputDialog::getInt(nullptr, QInputDialog::tr("Array creation"), "Enter number of array elements:");
    float f;

    for (int i = 0; i < size; ++i)
    {
        f = QInputDialog::getDouble(nullptr, QInputDialog::tr("Input"), "Enter element #" + QString::number(i) + ":");
        fileStream << f << '_';
    }
    file.close();
}

void FileWorker::LoadArrayFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        while (!fileStream.atEnd())
        {
            QString data = fileStream.readAll();
            QStringList floats = data.split("_", Qt::SkipEmptyParts);
            for (auto f : floats)
            {
                outputStream << f << " ";
            }
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void FileWorker::SaveSentenceToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        QString text = QInputDialog::getText(nullptr, QInputDialog::tr("Input"), "Enter sentence:");;
        fileStream << text << "\n";
        file.close();
    }
}

void FileWorker::LoadSentencesFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        while (!fileStream.atEnd())
        {
            QString s = fileStream.readLine();
            outputStream << s << "\n";
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void FileWorker::SaveStructToFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        structDialog->setModal(Qt::ApplicationModal);
        structDialog->show();

        while (structDialog->isVisible())
        {
            QCoreApplication::processEvents();
        }

        QString text = QString::number(a.year) + "\n" + QString::number(a.cost) + "\n" + QString(a.model) + "\n" + (a.isPassengerCar ? "true" : "false") + "\n" + QString(a.name) + "\n";
        for (int i = 0; i < a.MAX_WHEELS_SIZE; ++i)
        {
            text += QString(a.wheelsYear[i]) + "\n";
        }
        fileStream << text;
        file.close();
    }
}

void FileWorker::LoadStructsFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        while (!fileStream.atEnd())
        {
            QStringList data;
            for (int i = 0; i < 9; ++i)
            {
                data.append(fileStream.readLine());
            }

            Auto temp;
            temp.year = data[0].toInt();
            temp.cost = data[1].toDouble();
            temp.model = data[2][0].toLatin1();
            temp.isPassengerCar = data[3] == "true" ? true : false;
            for (int i = 0; i < temp.MAX_NAME_SIZE - 1; ++i)
            {
                temp.name[i] = data[4][i].toLatin1();
                temp.name[i + 1] = '\0';
            }
            for (int i = 0; i < temp.MAX_WHEELS_SIZE; ++i)
            {
                temp.wheelsYear[i] = data[i + 5].toInt();
            }

            outputStream << temp.year << "|" << temp.cost << "|" << QString(temp.model) << "|" << (temp.isPassengerCar ? "true" : "false") << "|" << QString(temp.name) << "|";
            for (int i = 0; i < temp.MAX_WHEELS_SIZE; ++i)
            {
                outputStream << temp.wheelsYear[i] << (i == temp.MAX_WHEELS_SIZE - 1 ? "\n" : "|");
            }
        }
        file.close();
    }
    output->setText(outputText);
    outputText.clear();
}

void FileWorker::SaveStructToBinaryFile(const QString &fileName)
{
    QFile file(fileName);
    QDataStream fileStream(&file);

    if (!file.open(QIODevice::Append))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        structDialog->setModal(Qt::ApplicationModal);
        structDialog->show();

        while (structDialog->isVisible())
        {
            QCoreApplication::processEvents();
        }

        fileStream.writeRawData(reinterpret_cast<const char*>(&a), sizeof(a));
        file.close();
    }
}

void FileWorker::LoadStructsFromBinaryFile(const QString &fileName)
{
    QFile file(fileName);
    QDataStream fileStream(&file);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    else
    {
        while (!fileStream.atEnd())
        {
            Auto temp;
            fileStream.readRawData(reinterpret_cast<char*>(&temp) ,sizeof(temp));
            outputStream << temp.year << "|" << temp.cost << "|" << QString(temp.model) << "|" << (temp.isPassengerCar ? "true" : "false") << "|" << QString(temp.name) << "|";
            for (int i = 0; i < temp.MAX_WHEELS_SIZE; ++i)
            {
                outputStream << temp.wheelsYear[i] << (i == temp.MAX_WHEELS_SIZE - 1 ? "\n" : "|");
            }
        }
        file.close();
        output->setText(outputText);
        outputText.clear();
    }
}
