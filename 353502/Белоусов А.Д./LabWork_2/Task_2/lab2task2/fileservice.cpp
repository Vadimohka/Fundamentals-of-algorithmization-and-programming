#include "fileservice.h"

FileService::FileService() = default;

void FileService::GetDataFromTheQFileDialog(QWidget *parent, ConvertibleInstance &instance)
{
    QString path = QFileDialog::getOpenFileName(parent, "Open csv file", "", "Data files (*.csv)");
    QFile fileToGetData(path);

    if (!fileToGetData.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&fileToGetData);
    QString data = out.readAll();

    instance.FromQStringToInstance(&data);

    fileToGetData.close();
}

void FileService::SaveDataIntoTheQFileDialog(QWidget *parent, ConvertibleInstance &instance)
{
    QString path = QFileDialog::getSaveFileName(parent, "Save csv file", "", "Data files (*.csv)");
    QFile fileToGetData(path);

    if (!fileToGetData.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        return;
    }

    QTextStream in(&fileToGetData);

    in << *instance.ToQString();

    fileToGetData.close();
}
