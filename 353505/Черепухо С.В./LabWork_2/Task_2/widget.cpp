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

void Widget::on_pushButton_clicked() //Открыть
{
    IsFileOpened = false;

    ui->label_6->setText("");

    str = QFileDialog::getOpenFileName(0, "Открыть", "", "*.txt");

    QFile file(str);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        arrr.clear();

        while(!file.atEnd())
        {
            Student ab;
            QString info = file.readLine();
            QStringList infolist = info.split(" ");
            QString name = infolist[0] + " " + infolist[1] + " " + infolist[2];
            QString spec = infolist[3];
            QString math = infolist[4];
            QString physics = infolist[5];
            QString rus = infolist[6];
            ab.b1 = math.toInt();
            ab.b2 = physics.toInt();
            ab.b3 = rus.toInt();
            ab.fio = name;
            ab.spec = spec;

            ab.sr_ball = float(ab.b1 + ab.b2 + ab.b3) / 3;

            arrr.push_back(ab);
        }

        model->setHeaderData(0, Qt::Horizontal, "ФИО");
        model->setHeaderData(1, Qt::Horizontal, "Специальность");
        model->setHeaderData(2, Qt::Horizontal, "Математика");
        model->setHeaderData(3, Qt::Horizontal, "Физика");
        model->setHeaderData(4, Qt::Horizontal, "Русский язык");
        model->setHeaderData(5, Qt::Horizontal, "Средний балл");

        model->setRowCount(arrr.size());

        for(int i = 0; i < arrr.size(); i++)
        {
            model->setItem(i, 0, new QStandardItem(arrr[i].fio));
            model->setItem(i, 1, new QStandardItem(arrr[i].spec));
            model->setItem(i, 2, new QStandardItem(QString::number(arrr[i].b1)));
            model->setItem(i, 3, new QStandardItem(QString::number(arrr[i].b2)));
            model->setItem(i, 4, new QStandardItem(QString::number(arrr[i].b3)));
            model->setItem(i, 5, new QStandardItem(QString::number(arrr[i].sr_ball)));
        }

        ui->tableView->setModel(model);

        ui->tableView->resizeColumnsToContents();

        IsFileOpened = true;
    }
    else
    {
        ui->label_6->setText("Ошибка при попытке открытия файла");
    }
}


void Widget::on_pushButton_3_clicked() //Изменить
{
    ui->label_6->setText("");

    if(!IsFileOpened)
    {
        ui->label_6->setText("Файл не выбран");
        return;
    }

    QModelIndex chosed = ui->tableView->currentIndex();

    if(chosed.row() == -1)
    {
        ui->label_6->setText("Элемент таблицы не выбран");
        return;
    }

    arrr[chosed.row()].fio = ui->lineEdit->text();
    arrr[chosed.row()].spec = ui->lineEdit_2->text();
    arrr[chosed.row()].b1 = ui->spinBox->value();
    arrr[chosed.row()].b2 = ui->spinBox_2->value();
    arrr[chosed.row()].b3 = ui->spinBox_3->value();

    arrr[chosed.row()].sr_ball = float(arrr[chosed.row()].b1 + arrr[chosed.row()].b2 + arrr[chosed.row()].b3) / 3;

    model->setItem(chosed.row(), 0, new QStandardItem(arrr[chosed.row()].fio));
    model->setItem(chosed.row(), 1, new QStandardItem(arrr[chosed.row()].spec));
    model->setItem(chosed.row(), 2, new QStandardItem(QString::number(arrr[chosed.row()].b1)));
    model->setItem(chosed.row(), 3, new QStandardItem(QString::number(arrr[chosed.row()].b2)));
    model->setItem(chosed.row(), 4, new QStandardItem(QString::number(arrr[chosed.row()].b3)));
    model->setItem(chosed.row(), 5, new QStandardItem(QString::number(arrr[chosed.row()].sr_ball)));

    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}


void Widget::on_pushButton_5_clicked() //Удалить
{
    ui->label_6->setText("");

    if(!IsFileOpened)
    {
        ui->label_6->setText("Файл не выбран");
        return;
    }

    QModelIndex chosed = ui->tableView->currentIndex();

    if(chosed.row() == -1)
    {
        ui->label_6->setText("Элемент таблицы не выбран");
        return;
    }

    arrr.remove(chosed.row());

    model->setRowCount(arrr.size());

    for(int i = 0; i < arrr.size(); i++)
    {
        model->setItem(i, 0, new QStandardItem(arrr[i].fio));
        model->setItem(i, 1, new QStandardItem(arrr[i].spec));
        model->setItem(i, 2, new QStandardItem(QString::number(arrr[i].b1)));
        model->setItem(i, 3, new QStandardItem(QString::number(arrr[i].b2)));
        model->setItem(i, 4, new QStandardItem(QString::number(arrr[i].b3)));
        model->setItem(i, 5, new QStandardItem(QString::number(arrr[i].sr_ball)));
    }

    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}


void Widget::on_pushButton_6_clicked() //Сортировать
{
    ui->label_6->setText("");

    if(!IsFileOpened)
    {
        ui->label_6->setText("Файл не выбран");
        return;
    }

    for (int i = 0; i < arrr.size() - 1; i++)
    {
        for (int j = 0; j < arrr.size() - i - 1; j++)
        {
            if (arrr[j].sr_ball < arrr[j+1].sr_ball)
            {
                Student temp = arrr[j];
                arrr[j] = arrr[j+1];
                arrr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < arrr.size(); i++)
    {
        model->setItem(i, 0, new QStandardItem(arrr[i].fio));
        model->setItem(i, 1, new QStandardItem(arrr[i].spec));
        model->setItem(i, 2, new QStandardItem(QString::number(arrr[i].b1)));
        model->setItem(i, 3, new QStandardItem(QString::number(arrr[i].b2)));
        model->setItem(i, 4, new QStandardItem(QString::number(arrr[i].b3)));
        model->setItem(i, 5, new QStandardItem(QString::number(arrr[i].sr_ball)));
    }

    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}


void Widget::on_pushButton_2_clicked() //Добавить
{
    ui->label_6->setText("");

    if(!IsFileOpened)
    {
        ui->label_6->setText("Файл не выбран");
        return;
    }

    Student temp;

    temp.fio = ui->lineEdit->text();
    temp.spec = ui->lineEdit_2->text();
    temp.b1 = ui->spinBox->value();
    temp.b2 = ui->spinBox_2->value();
    temp.b3 = ui->spinBox_3->value();

    temp.sr_ball = float(temp.b1 + temp.b2 + temp.b3) / 3;

    arrr.push_back(temp);

    model->setRowCount(arrr.size());

    model->setItem(arrr.size() - 1, 0, new QStandardItem(arrr[arrr.size() - 1].fio));
    model->setItem(arrr.size() - 1, 1, new QStandardItem(arrr[arrr.size() - 1].spec));
    model->setItem(arrr.size() - 1, 2, new QStandardItem(QString::number(arrr[arrr.size() - 1].b1)));
    model->setItem(arrr.size() - 1, 3, new QStandardItem(QString::number(arrr[arrr.size() - 1].b2)));
    model->setItem(arrr.size() - 1, 4, new QStandardItem(QString::number(arrr[arrr.size() - 1].b3)));
    model->setItem(arrr.size() - 1, 5, new QStandardItem(QString::number(arrr[arrr.size() - 1].sr_ball)));

    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}


void Widget::on_lineEdit_textChanged(const QString &arg1) //ФИО
{
    short k = 0;

    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] == ' ')
        {
            k++;
        }

        if(k > 2)
        {
            ui->lineEdit->setText("N F O");
            return;
        }
    }
}


void Widget::on_lineEdit_2_textChanged(const QString &arg1) //Специальность
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] == ' ')
        {
            ui->lineEdit_2->setText("C");
            return;
        }
    }
}


void Widget::on_pushButton_7_clicked() //Сохранить
{
    ui->label_6->setText("");

    if(!IsFileOpened)
    {
        ui->label_6->setText("Файл не выбран");
        return;
    }

    str = QFileDialog::getSaveFileName(this, "выберите файл", "C:/Users/kira1/OneDrive/Рабочий стол/файлы", "*.txt");
    QFile file(str);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        for(int i = 0; i < arrr.size(); i++)
        {
            QString strm = arrr[i].fio + " " + arrr[i].spec + " " + QString::number(arrr[i].b1) + " " + QString::number(arrr[i].b2) + " " + QString::number(arrr[i].b3) + "\n";
            QTextStream out(&file);
            out << strm;
        }
    }
}


void Widget::on_lineEdit_editingFinished()
{
    int spaces = 0;

    for(int i = 0; i < ui->lineEdit->text().size(); i++)
    {
        if(ui->lineEdit->text()[i] == ' ')
            spaces++;
    }

    if(spaces != 2)
        ui->lineEdit->setText("N F O");
}


void Widget::on_lineEdit_2_editingFinished()
{
    int spaces = 0;

    for(int i = 0; i < ui->lineEdit_2->text().size(); i++)
    {
        if(ui->lineEdit_2->text()[i] == ' ')
            spaces++;
    }

    if(spaces != 0)
        ui->lineEdit_2->setText("C");
}


void Widget::on_pushButton_8_clicked() //Поиск
{
    ui->tableView->selectRow(-1);

    ui->label_6->setText("");

    if(!IsFileOpened)
    {
        ui->label_6->setText("Файл не выбран");
        return;
    }

    QString search = ui->lineEdit->text();

    for(int i = 0; i < arrr.size(); i++)
    {
        if(arrr[i].fio == search)
        {
            ui->tableView->selectRow(i);
            return;
        }
    }

    ui->label_6->setText("Студент не был найден");
}

