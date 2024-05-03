#include "fileservice.h"

FileService::FileService() = default;

std::vector<Date> FileService::ReadQFileDialogForDatesByLines(QWidget* parentWindow)
{
    QString fileName = QFileDialog::getOpenFileName(parentWindow, "Open Text file", "Text file (*.txt)");
    QFile fileToOpen(fileName);

    std::vector<Date> answer;

    if (!fileToOpen.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return {};
    }

    QTextStream in(&fileToOpen);
    while (!in.atEnd())
    {
        QString line = in.readLine();

        Date newInstance;
        newInstance.SetInstanceFromQString(line);
        answer.push_back(newInstance);
    }

    return answer;
}

void FileService::WriteInQFileDialogDatesByLines(QWidget* parentWindow, std::vector<Date> toWrite)
{
    QString fileName = QFileDialog::getOpenFileName(parentWindow, "Select Text file to overwrite", "Text file (*.txt)");
    QFile fileToOpen(fileName);

    if (!fileToOpen.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&fileToOpen);
    for (Date instance : toWrite)
    {
        out << instance.ToQString() << '\n';
    }
}
