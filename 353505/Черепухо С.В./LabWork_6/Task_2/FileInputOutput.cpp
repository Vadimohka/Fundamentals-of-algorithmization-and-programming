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
        for (int i = 0; i < arr.size() - 1; i++/*const auto &el : arr*/) {
            out << arr[i] << ">";
        }
        out << arr[arr.size() - 1];
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
        QStringList list = line.split(">");
        for (const auto &el : list) {
            result += QString::number(el.toFloat()) + " ";
        }
        file.close();
    }
    return result.trimmed();
}

void FileInputOutput::writeStructToTxtFile(const QString &fileName, Notebook &notebook)
{
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << notebook.tooString() << "\n";
        file.close();
    }
}

QVector<Notebook> FileInputOutput::readStructFromTxtFile(const QString &fileName)
{
    QFile file(fileName);
    QVector<Notebook> result;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            Notebook notebook;
            QString ntb = in.readLine();
            result.push_back(notebook.toSelf(ntb));
        }
        file.close();
    }
    return result;
}

void FileInputOutput::writeStructToBinFile(const QString &fileName, Notebook &notebook)
{
    QFile file(fileName);
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        out << notebook.tooString() + "\n";
        file.close();
    }
}

QVector<Notebook> FileInputOutput::readStructFromBinFile(const QString &fileName)
{
    QFile file(fileName);
    QVector<Notebook> result;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        while (!in.atEnd()) {
            Notebook notebook;
            QString ntb;
            in >> ntb;
            result.push_back(notebook.toSelf(ntb));
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

void FileInputOutput::clear(const QString &fileName)
{
    QFile file(fileName);
    file.remove();
}
