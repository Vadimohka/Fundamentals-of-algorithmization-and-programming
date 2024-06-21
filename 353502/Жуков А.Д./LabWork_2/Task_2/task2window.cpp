#include "task2window.h"
#include "ui_task2window.h"

#include <QDebug>

Task2Window::Task2Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task2Window)
{
    ui->setupUi(this);

    if (!QFile(DEFAULT_PATH + "Зелёный слоник.txt").exists())
    {
        CreateFile("Фильм", "Зелёный Слоник", "Светлана Баскова", "15", "Отличный фильм для просмотра всей семьёй!");
    }
    if (!QFile(DEFAULT_PATH + "Whole lotta red.txt").exists())
    {
        CreateFile("Музыкальный альбом", "Whole lotta red", "Playboy Carti", "30", "Позер");
    }

    QDir dir(DEFAULT_PATH);
    allFiles = dir.entryList(QDir::Files);

    for (const QString& name : allFiles)
    {
        FileToList(name);
    }
}

Task2Window::~Task2Window()
{
    delete ui;
}

void Task2Window::FileToList(QString filePath)
{
    QFile file = QFile(DEFAULT_PATH + filePath);
    QTextStream stream(&file);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        DiskInfo newDisk;
        newDisk.setType(stream.readLine());
        newDisk.setName(stream.readLine());
        newDisk.setAuthor(stream.readLine());
        newDisk.setPrice(stream.readLine());
        newDisk.setNote(stream.readLine());

        infoList << DiskInfo(newDisk.getType(), newDisk.getName(), newDisk.getAuthor(), newDisk.getPrice(), newDisk.getNote());
        ui->ObjectList->addItem(newDisk.getName());
    }
    file.close();

    //qDebug() << infoList.first().getType() << infoList.first().getName() << infoList.first().getAuthor() << infoList.first().getPrice() << infoList.first().getNote();
}

void Task2Window::CreateFile(QString type, QString name, QString author, QString price, QString note)
{
    QFile *file = new QFile(DEFAULT_PATH + name + ".txt");
    QTextStream stream(file);

    if (file->open(QIODevice::Append | QIODevice::ReadWrite))
    {
        if (file->size() == 0)
        {
            stream << type << "\n";
            stream << name << "\n";
            stream << author << "\n";
            stream << price << "\n";
            stream << note << "\n";
        }
    }
    file->close();
}

void Task2Window::on_button_open_clicked()
{
    ui->infoList->clear();
    if (ui->ObjectList->currentItem()->isSelected())
    {   
        for (DiskInfo disk : infoList)
        {
            if (ui->ObjectList->currentItem()->text() == disk.getName())
            {
                ui->infoList->setText("Тип: " + disk.getType() + "\n"
                                      + "Название: " + disk.getName() + "\n"
                                      + "Автор: " + disk.getAuthor() + "\n"
                                      + "Цена: " + disk.getPrice() + "\n"
                                      + "Примечание: " + disk.getNote());
                ui->typeEdit->setText(disk.getType());
                ui->nameEdit->setText(disk.getName());
                ui->authorEdit->setText(disk.getAuthor());
                ui->priceEdit->setText(disk.getPrice());
                ui->noteEdit->setText(disk.getNote());
                break;
            }
        }
    }
}


void Task2Window::on_button_delete_clicked()
{
    if (ui->ObjectList->currentItem()->isSelected())
    {
        ui->infoList->clear();
        ui->typeEdit->setText("");
        ui->nameEdit->setText("");
        ui->authorEdit->setText("");
        ui->priceEdit->setText("");
        ui->noteEdit->setText("");

        QString currentName = ui->ObjectList->currentItem()->text();
        QFile file(DEFAULT_PATH + currentName + ".txt");
        file.remove();
        ui->ObjectList->takeItem(ui->ObjectList->currentRow());
        for (int i = 0; i < infoList.size(); ++i)
        {
            if (infoList[i].getName() == currentName)
            {
                infoList.removeAt(i);
            }
        }
    }
}


void Task2Window::on_button_add_clicked()
{
    if (QFile(DEFAULT_PATH + ui->nameEdit->text() + ".txt").exists())
    {
        QMessageBox mess;
        mess.setWindowTitle("ОШИБКА");
        mess.setText("Такой товар уже существует");
        mess.exec();
        return;
    }

    //if (QString::isui->priceEdit->text())
    //ТУТ ПРОВЕРКИ СДЕЛАТЬ

    CreateFile(ui->typeEdit->text(), ui->nameEdit->text(), ui->authorEdit->text(), ui->priceEdit->text(), ui->noteEdit->toPlainText());
    FileToList(ui->nameEdit->text() + ".txt");
}


void Task2Window::on_button_save_clicked()
{
    if (!QFile(DEFAULT_PATH + ui->nameEdit->text() + ".txt").exists())
    {
        QMessageBox mess;
        mess.setWindowTitle("ОШИБКА");
        mess.setText("Такого товара не существует");
        mess.exec();
        return;
    }

    if (ui->nameEdit->text() == "" ||
        ui->typeEdit->text() == "" ||
        ui->authorEdit->text() == "" ||
        ui->noteEdit->toPlainText() == "" ||
        ui->priceEdit->text() == "")
    {
        QMessageBox mess;
        mess.setWindowTitle("ОШИБКА");
        mess.setText("Поля не могут быть пустыми");
        mess.exec();
        return;
    }

    QFile(DEFAULT_PATH + ui->nameEdit->text() + ".txt").remove();
    CreateFile(ui->typeEdit->text(), ui->nameEdit->text(), ui->authorEdit->text(), ui->priceEdit->text(), ui->noteEdit->toPlainText());
    FileToList(ui->nameEdit->text() + ".txt");
}


void Task2Window::on_sortComboBox_currentTextChanged(const QString &arg1)
{
    ui->ObjectList->clear();

    if (arg1 == "Названию")
    {
        QDir dir(DEFAULT_PATH);
        allFiles = dir.entryList(QDir::Files);

        for (const QString& name : allFiles)
        {
            ui->ObjectList->addItem(name.left(name.length() - 4));
        }
    }
    else
    {
        qint16 ind = 0;
        while (ind != infoList.size())
        {
            if (ind != infoList.size() - 1 && QString::compare(infoList[ind].getAuthor(), infoList[ind+1].getAuthor(), Qt::CaseInsensitive) > 0)
            {
                infoList.swapItemsAt(ind, ind + 1);
                ind = -1;
            }
            ind++;
        }

        for (auto & list : infoList)
        {
            ui->ObjectList->addItem(list.getName());
        }
    }
}

void Task2Window::on_button_search_clicked()
{
    ui->ObjectList->clear();
    for (DiskInfo disk : infoList)
    {
        if (disk.searchDisk(ui->searchEdit->text()))
        {
            ui->ObjectList->addItem(disk.getName());
        }
    }
}

