#include "FileInputOutput.h"

#include <QFile>
#include <QTextStream>

void FileInputOutput::writeToFile(const QString &fileName, const QString &text)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text << "\n";
        file.close();
    }
}

QString FileInputOutput::readFromFile(const QString &fileName)
{
    QFile file(fileName);
    QString result;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        result = in.readAll();
        file.close();
    }
    return result;
}

void FileInputOutput::writeArrayToFile(const QString &fileName, const QVector<float> &arr)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const auto &el : arr) {
            out << el << ";";
        }
        out << "\n";
        file.close();
    }
}

QString FileInputOutput::readArrayFromFile(const QString &fileName)
{
    QFile file(fileName);
    QString result;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();
        QStringList list = line.split(";");
        for (const auto &el : list) {
            result += QString::number(el.toFloat()) + " ";
        }
        file.close();
    }
    return result.trimmed();
}

void FileInputOutput::writeStructToTxtFile(const QString &fileName, const Plant &plant)
{
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << plant.age << " " << plant.height << " " << plant.vitamin << " " << plant.isFlowering
            << "\n";
        file.close();
    }
}

QVector<Plant> FileInputOutput::readStructFromTxtFile(const QString &fileName)
{
    QFile file(fileName);
    QVector<Plant> result;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            Plant plant;
            QString line = in.readLine();
            QStringList list = line.split(" ");
            if (list.size() == 4) {
                plant.age = list[0].toInt();
                plant.height = list[1].toFloat();
                plant.vitamin = list[2].toLatin1().at(0);
                plant.isFlowering = list[3].toInt();
                result.push_back(plant);
            }
        }
        file.close();
    }
    return result;
}

void FileInputOutput::writeStructToBinFile(const QString &fileName, const Plant &plant)
{
    QFile file(fileName);
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        out << plant.age << plant.height << plant.vitamin << plant.isFlowering;
        file.close();
    }
}

QVector<Plant> FileInputOutput::readStructFromBinFile(const QString &fileName)
{
    QFile file(fileName);
    QVector<Plant> result;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        while (!in.atEnd()) {
            Plant plant;
            in >> plant.age >> plant.height >> plant.vitamin >> plant.isFlowering;
            result.push_back(plant);
        }
        file.close();
    }
    return result;
}

void FileInputOutput::appendSentenceToFile(const QString &fileName, const QString &text)
{
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << text << "\n";
        file.close();
    }
}
