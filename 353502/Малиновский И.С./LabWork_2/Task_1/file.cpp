#include "file.h"

void File::convertFromFile(QWidget *parent, QVector<Date> &dates)
{
    QString pathToFile = QFileDialog::getOpenFileName(parent, "Выберите файл", "", "Текстовый файл (*.txt)");
    QFile projFile(pathToFile);

    if (!projFile.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    dates.clear();
    QTextStream in(&projFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
        Date date;
        date.ConvertToDate(line);
        dates.push_back(date);
    }
    projFile.close();
}

void File::convertToFile(QWidget *parent, QVector<Date> &dates)
{
    QString pathToFile = QFileDialog::getOpenFileName(parent, "Выберите файл для сохранения", "", "Текстовый файл (*.txt)");
    QFile file(pathToFile);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        return;
    }
    qDebug() << "OK";
    QTextStream out(&file);
    for (auto date:dates)
    {
        out << date.ConvertToString();
        out << "\n";
    }
    file.close();
}
