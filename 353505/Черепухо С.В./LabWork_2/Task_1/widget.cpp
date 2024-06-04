#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    IsFileOpened = false;

    ui->label->setText("");

    str = QFileDialog::getOpenFileName(0, "Открыть", "", "*.txt");

    QFile file(str);

    if (!file.open(QIODeviceBase::ReadWrite))
    {
        ui->label->setText("Ошибка при попытке открытия файла");
    }
    else
    {
        QByteArray block = file.readAll();

        QString text = QString(block);
        text[text.size() - 1] = ' ';

        text.simplified();

        text[text.size() - 1] = ' ';

        if(text.size() % 11 != 0)
        {
            ui->label->setText("Ошибка при попытке чтения файла " + QString::number(text.size()));
            return;
        }

        QString temp = "";

        for(int i = 0; i < text.size(); i++)
        {
            if((i % 11 == 0 || i % 11 == 1 || i % 11 == 3 || i % 11 == 4 || i % 11 == 6 || i % 11 == 7 || i % 11 == 8 || i % 11 == 9) && (text[i] < '0' || text[i] > '9'))
            {
                ui->label->setText("Ошибка в тексте файла");
                return;
            }
            else if((i % 11 == 2 || i % 11 == 5) && text[i] != '.')
            {
                ui->label->setText("Ошибка в тексте файла");
                return;
            }
            else if(i % 11 == 10 && text[i] != ' ')
            {
                ui->label->setText("Ошибка в тексте файла");
                return;
            }

            temp = temp + text[i];

            if (temp.size() == 11)
            {
                if(arr_size == 0)
                {
                    arr[0].setDay((QString(temp[0]).toInt()) * 10 + (QString(temp[1]).toInt()));
                    arr[0].setMonth((QString(temp[3]).toInt()) * 10 + (QString(temp[4]).toInt()));
                    arr[0].setYear((QString(temp[6]).toInt()) * 1000 + (QString(temp[7]).toInt()) * 100 + (QString(temp[8]).toInt()) * 10 + (QString(temp[9]).toInt()));
                    arr_size = 1;
                }
                else
                {
                    Date* temp_arr = new Date[arr_size + 1];

                    for(int i = 0; i < arr_size + 1; i++)
                    {
                        temp_arr[i] = arr[i];
                    }

                    delete[] arr;

                    arr = temp_arr;

                    arr[arr_size].setDay((QString(temp[0]).toInt()) * 10 + (QString(temp[1]).toInt()));
                    arr[arr_size].setMonth((QString(temp[3]).toInt()) * 10 + (QString(temp[4]).toInt()));
                    arr[arr_size].setYear((QString(temp[6]).toInt()) * 1000 + (QString(temp[7]).toInt()) * 100 + (QString(temp[8]).toInt()) * 10 + (QString(temp[9]).toInt()));

                    arr_size++;
                }

                temp = "";
            }
        }

        for(int i = 0; i < arr_size; i++)
        {
            if(arr[i].checkDate() == false)
            {
                ui->label->setText("Неверный формат даты " + arr[i].getString());
                delete[] arr;
                arr_size = 0;
                return;
            }
        }

        for(int i = 0; i < arr_size; i++)
        {
            model->setItem(i, 0, new QStandardItem(arr[i].getString()));
            model->setItem(i, 1, new QStandardItem(arr[i].NextDay().getString()));

            if(i != arr_size - 1)
            {
                model->setItem(i, 2, new QStandardItem(QString::number(arr[i].Duration(arr[i+1]))));
            }
        }

        model->setHeaderData(0, Qt::Horizontal, "Дата");
        model->setHeaderData(1, Qt::Horizontal, "Следующий день");
        model->setHeaderData(2, Qt::Horizontal, "Дней до следующей даты");
        model->setHeaderData(3, Qt::Horizontal, "");

        ui->tableView->setModel(model);

        ui->tableView->resizeColumnsToContents();

        IsFileOpened = true;

        beginWidth = ui->tableView->width();
    }
}


void Widget::on_pushButton_2_clicked() //Предыдущие дни
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    model->setHeaderData(3, Qt::Horizontal, "Предыдущий день");

    for(int i = 0; i < arr_size; i++)
    {
        model->setItem(i, 3, new QStandardItem(arr[i].PreviousDay().getString()));
    }

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setFixedWidth(beginWidth + ui->tableView->columnWidth(3));
}


void Widget::on_pushButton_3_clicked() //Номера недели
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    model->setHeaderData(3, Qt::Horizontal, "Номер недели");

    for(int i = 0; i < arr_size; i++)
    {
        model->setItem(i, 3, new QStandardItem(QString::number(arr[i].WeekNumber())));
    }

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setFixedWidth(beginWidth + ui->tableView->columnWidth(3));
}


void Widget::on_pushButton_4_clicked() //Високосный ли год
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    model->setHeaderData(3, Qt::Horizontal, "Високосный");

    for(int i = 0; i < arr_size; i++)
    {
        if(arr[i].IsLeap())
            model->setItem(i, 3, new QStandardItem("Да"));
        else
            model->setItem(i, 3, new QStandardItem("Нет"));
    }

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setFixedWidth(beginWidth + ui->tableView->columnWidth(3));
}


void Widget::on_pushButton_5_clicked() //Кол-во дней до/после сегодня
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    model->setHeaderData(3, Qt::Horizontal, "Дней до/после сегодня");

    today.setDay(QDate::currentDate().day());
    today.setMonth(QDate::currentDate().month());
    today.setYear(QDate::currentDate().year());

    for(int i = 0; i < arr_size; i++)
    {
        model->setItem(i, 3, new QStandardItem(QString::number(arr[i].Duration(today))));
    }

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setFixedWidth(beginWidth + ui->tableView->columnWidth(3));
}


void Widget::on_pushButton_6_clicked() //Кол-во дней до др
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    if(ui->lineEdit->text().size() != 5)
    {
        ui->label->setText("Неверный формат даты");
        return;
    }

    today.setDay((QString(ui->lineEdit->text()[0]) + QString(ui->lineEdit->text()[1])).toInt());
    today.setMonth((QString(ui->lineEdit->text()[3]) + QString(ui->lineEdit->text()[4])).toInt());
    today.setYear(5000);

    if(!today.checkDate())
    {
        ui->label->setText("Неверный формат даты");
        return;
    }

    model->setHeaderData(3, Qt::Horizontal, "Дней до дня рождения");

    for(int i = 0; i < arr_size; i++)
    {
        model->setItem(i, 3, new QStandardItem(QString::number(arr[i].DaysTillYourBirthday(today))));
    }

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setFixedWidth(beginWidth + ui->tableView->columnWidth(3));
}


void Widget::on_pushButton_7_clicked() //Добавить дату
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    if(ui->lineEdit_2->text().size() != 10)
    {
        ui->label->setText("Неверный формат даты");
        return;
    }

    today.setDay((QString(ui->lineEdit_2->text()[0]) + QString(ui->lineEdit_2->text()[1])).toInt());
    today.setMonth((QString(ui->lineEdit_2->text()[3]) + QString(ui->lineEdit_2->text()[4])).toInt());
    today.setYear((QString(ui->lineEdit_2->text()[6]) + QString(ui->lineEdit_2->text()[7]) + QString(ui->lineEdit_2->text()[8]) + QString(ui->lineEdit_2->text()[9])).toInt());

    if(!today.checkDate())
    {
        ui->label->setText("Неверный формат даты");
        return;
    }

    Date* temp_arr = new Date[arr_size + 1];

    for(int i = 0; i < arr_size + 1; i++)
    {
        temp_arr[i] = arr[i];
    }

    delete[] arr;

    temp_arr[arr_size] = today;

    arr = temp_arr;

    arr_size++;

    model->setRowCount(arr_size);

    model->setItem(arr_size - 1, 0, new QStandardItem(arr[arr_size - 1].getString()));
    model->setItem(arr_size - 1, 1, new QStandardItem(arr[arr_size - 1].NextDay().getString()));
    model->setItem(arr_size - 2, 2, new QStandardItem(QString::number(arr[arr_size - 2].Duration(arr[arr_size - 1]))));

    QFile file(str);

    if(!file.open(QIODevice::ReadWrite))
    {
        ui->label->setText("Не удалось изменить файл");
        return;
    }

    file.remove();

    file.open(QIODevice::WriteOnly);

    QString lload = "";

    for(int i = 0; i < arr_size; i++)
    {
        lload = lload + arr[i].getString();

        if(i != arr_size - 1)
            lload = lload + " ";
    }

    QByteArray llload = lload.toUtf8();

    file.write(llload);

    file.close();
}


void Widget::on_pushButton_8_clicked() //Изменить дату
{
    if(!IsFileOpened)
    {
        ui->label->setText("Не выбран файл");
        return;
    }

    if(ui->lineEdit_3->text().size() != 10)
    {
        ui->label->setText("Неверный формат даты");
        return;
    }

    today.setDay((QString(ui->lineEdit_3->text()[0]) + QString(ui->lineEdit_3->text()[1])).toInt());
    today.setMonth((QString(ui->lineEdit_3->text()[3]) + QString(ui->lineEdit_3->text()[4])).toInt());
    today.setYear((QString(ui->lineEdit_3->text()[6]) + QString(ui->lineEdit_3->text()[7]) + QString(ui->lineEdit_3->text()[8]) + QString(ui->lineEdit_3->text()[9])).toInt());

    if(!today.checkDate())
    {
        ui->label->setText("Неверный формат даты");
        return;
    }

    QModelIndex chosed = ui->tableView->currentIndex();

    if(chosed.row() != -1)
    {
        arr[chosed.row()] = today;

        model->setItem(chosed.row(), 0, new QStandardItem(arr[chosed.row()].getString()));
        model->setItem(chosed.row(), 1, new QStandardItem(arr[chosed.row()].NextDay().getString()));

        if(chosed.row() != arr_size - 1)
            model->setItem(chosed.row(), 2, new QStandardItem(QString::number(arr[chosed.row()].Duration(arr[chosed.row() + 1]))));

        if(chosed.row() != 0)
            model->setItem(chosed.row() - 1, 2, new QStandardItem(QString::number(arr[chosed.row() - 1].Duration(arr[chosed.row()]))));
    }
    else
    {
        ui->label->setText("Не выбран элемент таблицы");
        return;
    }

    QFile file(str);

    if(!file.open(QIODevice::ReadWrite))
    {
        ui->label->setText("Не удалось изменить файл");
        return;
    }

    file.remove();

    file.open(QIODevice::WriteOnly);

    QString lload = "";

    for(int i = 0; i < arr_size; i++)
    {
        lload = lload + arr[i].getString();

        if(i != arr_size - 1)
            lload = lload + " ";
    }

    QByteArray llload = lload.toUtf8();

    file.write(llload);

    file.close();
}


void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.size() > 0 && (arg1[0] < '0' || arg1[0] > '9'))
        ui->lineEdit->setText("");
    if(arg1.size() > 1 && (arg1[1] < '0' || arg1[1] > '9'))
        ui->lineEdit->setText(QString(arg1[0]));
    if(arg1.size() > 2 && arg1[2] != '.')
        ui->lineEdit->setText(QString(arg1[0]) + QString(arg1[1]));
    if(arg1.size() > 3 && (arg1[3] < '0' || arg1[3] > '9'))
        ui->lineEdit->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]));
    if(arg1.size() > 4 && (arg1[4] < '0' || arg1[4] > '9'))
        ui->lineEdit->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
    if(arg1.size() > 5)
        ui->lineEdit->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]));
}


void Widget::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(arg1.size() > 0 && (arg1[0] < '0' || arg1[0] > '9'))
        ui->lineEdit_2->setText("");
    if(arg1.size() > 1 && (arg1[1] < '0' || arg1[1] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]));
    if(arg1.size() > 2 && arg1[2] != '.')
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]));
    if(arg1.size() > 3 && (arg1[3] < '0' || arg1[3] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]));
    if(arg1.size() > 4 && (arg1[4] < '0' || arg1[4] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
    if(arg1.size() > 5 && arg1[5] != '.')
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]));
    if(arg1.size() > 6 && (arg1[6] < '0' || arg1[6] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]));
    if(arg1.size() > 7 && (arg1[7] < '0' || arg1[7] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]));
    if(arg1.size() > 8 && (arg1[8] < '0' || arg1[8] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]) + QString(arg1[7]));
    if(arg1.size() > 9 && (arg1[9] < '0' || arg1[9] > '9'))
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]) + QString(arg1[7]) + QString(arg1[8]));

    if(arg1.size() > 10)
        ui->lineEdit_2->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]) + QString(arg1[7]) + QString(arg1[8]) + QString(arg1[9]));
}


void Widget::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(arg1.size() > 0 && (arg1[0] < '0' || arg1[0] > '9'))
        ui->lineEdit_3->setText("");
    if(arg1.size() > 1 && (arg1[1] < '0' || arg1[1] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]));
    if(arg1.size() > 2 && arg1[2] != '.')
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]));
    if(arg1.size() > 3 && (arg1[3] < '0' || arg1[3] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]));
    if(arg1.size() > 4 && (arg1[4] < '0' || arg1[4] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
    if(arg1.size() > 5 && arg1[5] != '.')
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]));
    if(arg1.size() > 6 && (arg1[6] < '0' || arg1[6] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]));
    if(arg1.size() > 7 && (arg1[7] < '0' || arg1[7] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]));
    if(arg1.size() > 8 && (arg1[8] < '0' || arg1[8] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]) + QString(arg1[7]));
    if(arg1.size() > 9 && (arg1[9] < '0' || arg1[9] > '9'))
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]) + QString(arg1[7]) + QString(arg1[8]));

    if(arg1.size() > 10)
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]) + QString(arg1[4]) + QString(arg1[5]) + QString(arg1[6]) + QString(arg1[7]) + QString(arg1[8]) + QString(arg1[9]));
}

