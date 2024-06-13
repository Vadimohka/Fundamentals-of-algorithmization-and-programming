#include "customtextedit.h"

CustomTextEdit::CustomTextEdit(QWidget* parent) : QTextEdit(parent)
{

}

void CustomTextEdit::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Return)
    {
        if(action == "Ввести абзац текста")
        {
            QString text = this->toPlainText();

            QFile file("/home/kbadpat/OAiP/Lab6/Task2/text.txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                file.resize(0);
                stream << text;
                file.close();
            }
            this->clear();
        }
        if(action == "Ввести массив float")
        {
            saveArrayToFile(n);
            this->clear();
        }
    }
    else
    {
        qDebug() << event->key();
        QTextEdit::keyPressEvent(event);
    }
}

void CustomTextEdit::getTextFromFile(QString filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString text = stream.readAll();
        file.close();

        this->setPlainText(text);
    }
}

void CustomTextEdit::saveArrayToFile(int n) {
    QString text = toPlainText();
    QStringList numbers = text.split(" ");
    //qDebug() << numbers;
    QFile file("/home/kbadpat/OAiP/Lab6/Task2/array.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        int count = qMin(n, numbers.size());
        bool firstNumber = true;
        for (int i = 0; i < count; ++i) {
            bool ok;
            qDebug() << numbers[i];
            float number = numbers[i].toFloat(&ok);  // Преобразовать строку в число типа float

            if (ok) {
                if (!firstNumber) {
                    stream << "; ";  // Записать запятую перед числом
                }
                stream << number;  // Записать число в файл
                firstNumber = false;
            }

        }
        file.close();
    }
}

void CustomTextEdit::setAction(QString newAction)
{
    action = newAction;
}

void CustomTextEdit::setN(int a)
{
    n = a;
}

void CustomTextEdit::loadFloatArrayFromFile() {
    QFile file("/home/kbadpat/OAiP/Lab6/Task2/array.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString content = file.readAll();  // Прочитать содержимое файла
        file.close();

        content.replace(";", " ");  // Заменить все точки с запятой на пробелы

        // Очистить текущий текст в QTextEdit

        // Добавить обработанную строку с числами в QTextEdit
        this->setPlainText(content);
    }
}

void CustomTextEdit::loadTextFromBinaryFile(QString filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        Plant plant;
        stream.readRawData(reinterpret_cast<char*>(&plant), sizeof(Plant));

        QString plantData = QString("Age: %1, Height: %2, Category: %3, Is Healthy: %4, Name: %5, Humidity: ")
                .arg(plant.age)
                .arg(plant.height)
                .arg(plant.category)
                .arg(plant.isHealthy ? "true" : "false")
                .arg(plant.name);

        int humidityCount = (file.size() - sizeof(Plant)) / sizeof(int);
        for (int i = 0; i < humidityCount; ++i) {
            int humidity;
            stream.readRawData(reinterpret_cast<char*>(&humidity), sizeof(int));
            plantData.append(QString::number(humidity));
            if (i < humidityCount - 1)
                plantData.append(",");
        }

        this->setText(plantData);
        file.close();
    }
}
