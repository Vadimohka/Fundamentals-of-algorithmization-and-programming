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

        QString text = QString(a.name) + " | " + QString::number(a.year) + " | " + QString(a.model) +" | " + QString::number(a.mileage) + "km | " + (a.isPassengerCar ? "is passenger" : "is not passenger") + " | ";

        for(int i = 0 ; i < 4; i++){
            QString tp = QString::number(a.tirePressures[i]) + " ";
            text += tp ;
        }

        text += '\n';

        fileStream << text;
        file.close();
    }
}

void FileWorker::LoadStructsFromFile(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    QString outputText;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("File Open"), "Failed to open file: " + fileName, QMessageBox::Ok | QMessageBox::NoButton);
        return;
    } else{
        while (!fileStream.atEnd()){
            for (int i = 0; i < 9; ++i){
                outputText += fileStream.readLine() + "\n";
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
            Car temp;
            fileStream.readRawData(reinterpret_cast<char*>(&temp) ,sizeof(temp));
            outputStream << temp.year << " | " << temp.mileage << " | " << QString(temp.model) << " | " << (temp.isPassengerCar ? "is passenger" : "is not passenger") << " | " << QString(temp.name) << " | ";
            for (int i = 0; i < temp.COUNT_OF_WHEELS; ++i)
            {
                outputStream << temp.tirePressures[i];
            }
        }

        file.close();
        output->setText(outputText);
        outputText.clear();
    }
}

void FileWorker::ClearAllFiles(){
    for(auto a : files){
        QFile file(a);
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QTextStream out(&file);
        out << "";
        file.close();
    }
}
