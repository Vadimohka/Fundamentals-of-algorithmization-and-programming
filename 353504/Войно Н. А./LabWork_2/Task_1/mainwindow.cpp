#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    pathFile = QFileDialog::getOpenFileName(0, "Открыть файл","/home/skibidi-dop", "*txt");

    getInformation();
}

void MainWindow::getInformation()
{
    moidates = "";
    QFile file(pathFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Не удалось открыть файл для чтения, сосите");
        return;
    }
    QTextStream in(&file);

    while(!in.atEnd())
    {
        moidates += in.readLine();
        moidates += '\n';
    }

    //moidates.;
    file.close();
    makeTable();
}

void MainWindow::makeTable()
{
    model->clear();
    QString temp = "";
    bool chyslo = true;
    kolvo = 0;

    for(int i = 0; i < moidates.length(); i++)
    {
        if(i != 0 && ((moidates[i] == ' ' && moidates[i - 1] != ' ') || (moidates[i] == '\n' && (moidates[i - 1] != ' ' || moidates[i] != '\n'))))
        {
            kolvo ++;
            //temp += ' ';
        }
        else if(moidates[i] == ' ')
        {
            continue;
        }
        if(i == moidates.length() - 2 && moidates[i] == ' ' && moidates[i + 1] == '\n')
        {
            continue;
        }

        temp += moidates[i];
    }

    moyaDate = new mydata*[kolvo];
    for(long i = 0; i < kolvo; i++)
    {
        moyaDate[i] = new mydata();
    }

    int j = 0;
    QString string;


    bool ok;
    for(int i =0; i < temp.length(); i++)
    {
        if(!chyslo && temp[i - 1] != ' ')
        {
            continue;
        }
        if(temp[i] != ' ' && ((temp[i] >= 48 && temp[i] <= 57) || temp[i] == '.' || temp[i] == ',' || temp[i] == '/' || temp[i] == '-'))
        {
            string += temp[i];
            chyslo = true;

        }
        else if((temp[i] == ' ' || temp[i] == '\n') && j < kolvo)
        {
            ok = proverka(string);
            if(ok)
            {
                moyaDate[j]->get(string);
                j++;
                string = "";
            }
            else
            {
                string = "";
                kolvo--;
            }

        }
        else
        {
            string = "";
            kolvo--;
            chyslo = false;
        }
    }

    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setRowCount(kolvo);
    model->setColumnCount(8);
    ui->tableView->horizontalHeader()->model()->setHeaderData(0, Qt::Horizontal, "Дата");
    ui->tableView->horizontalHeader()->model()->setHeaderData(1, Qt::Horizontal, "След. день");
    ui->tableView->horizontalHeader()->model()->setHeaderData(2, Qt::Horizontal, "Дата - След. дата");
    ui->tableView->horizontalHeader()->model()->setHeaderData(3, Qt::Horizontal, "Пред. день");
    ui->tableView->horizontalHeader()->model()->setHeaderData(4, Qt::Horizontal, "Тип года");
    ui->tableView->horizontalHeader()->model()->setHeaderData(5, Qt::Horizontal, "День недели");
    ui->tableView->horizontalHeader()->model()->setHeaderData(6, Qt::Horizontal, "Дата - д.р.");
    ui->tableView->horizontalHeader()->model()->setHeaderData(7, Qt::Horizontal, "Тек. дата - данной");

    for(int i = 0; i < kolvo; i++)
    {
        QModelIndex index = model->index(i, 0);

        moyaDate[i]->set(model, index);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    mydata temp;
    for(int i = 0; i < kolvo; i++)
    {
        QModelIndex index = model->index(i, 1);
        temp = moyaDate[i]->NextDay();
        temp.set(model, index);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    mydata temp;
    for(int i = 0; i < kolvo; i++)
    {
        QModelIndex index = model->index(i, 3);
        temp = moyaDate[i]->PreviousDay();
        temp.set(model, index);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QDate date = QDate::currentDate();
    QString currDate = date.toString("dd.MM.yyyy");

    mydata temp;
    temp.get(currDate);
    for(int i = 0; i < kolvo; i++)
    {
        QModelIndex index = model->index(i, 7);
        int x = moyaDate[i]->Duration(temp);
        QString xString = QString::number(x);
        xString +=" дней";
        model->setData(index, xString);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    mydata temp;
    for(int i = 0; i < kolvo; i++)
    {
        if(i + 1 != kolvo)
        {
            temp.get(moyaDate[i + 1]->ret());
            QModelIndex index = model->index(i, 2);
            int x = moyaDate[i]->Duration(temp);
            QString xString = QString::number(x);
            xString +=" дней";
            model->setData(index, xString);
        }
        else
        {
            QModelIndex index = model->index(i, 2);
            model->setData(index, "0 дней");
        }
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    for(int i = 0; i < kolvo; i++)
    {
        bool ok = moyaDate[i]->leaf();
        if(ok)
        {
            QModelIndex index = model->index(i, 4);
            model->setData(index, "Високосный");
        }
        else
        {
            QModelIndex index = model->index(i, 4);
            model->setData(index, "Обычный");
        }
    }
}



void MainWindow::on_pushButton_7_clicked()
{
    for(int i = 0; i < kolvo; i++)
    {
        short x = moyaDate[i]->WeekNumber();
        if(x == 0)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Суббота");
        }
        else if(x == 1)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Воскресенье");
        }
        else if(x == 2)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Понедельник");
        }
        else if(x == 3)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Вторник");
        }
        else if(x == 4)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Среда");
        }
        else if(x == 5)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Четверг");
        }
        else if(x == 6)
        {
            QModelIndex index = model->index(i, 5);
            model->setData(index, "Пятница");
        }
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    bool st;
    bool ok;
    mydata bithdaydate;
    QString text = QInputDialog::getText(nullptr, "Введите дату рождения",
                                        "Дата рождения:", QLineEdit::Normal,
                                        "dd.MM.yyyy", &ok);
    if (ok)
    {
        st = proverka(text);
        if(!st)
        {
            QMessageBox::critical(nullptr, "Ошибка", "Неправильный формат даты!");
        }
        else
        {
            bithdaydate.get(text);


            for(int i = 0; i < kolvo; i++)
            {
                QString xString = "";
                QModelIndex index = model->index(i, 6);
                int x = moyaDate[i]->DaysTillYourBithday(bithdaydate);
                if(x < 0)
                {
                    xString ="Прошло ";
                    x *= (-1);
                }
                xString += QString::number(x);
                xString +=" дней";
                model->setData(index, xString);
            }
        }
    }
}

bool MainWindow::proverka(QString vot)
{
    bool answ;

    QString day = "";
    int d;
    QString month = "";
    int m;
    QString year = "";
    int y;
    bool chyslo;

    for(int i = 0; i < vot.length(); i++)
    {
        if ((i == 2 || i == 5) && (vot[i] == '.' || vot[i] == ',' || vot[i] == '/'))
        {
            continue;
        }
        else if((i == 2 || i == 5) && !(vot[i] == '.' || vot[i] == ',' || vot[i] == '/'))
        {
            chyslo = false;
            break;
        }
        if(vot[i] >= 48 && vot[i] <= 57)
        {
            chyslo = true;
        }
        else
        {
            chyslo = false;
            break;
        }
    }
    if(!chyslo)
    {
        return answ = false;
    }

    for(int i = 0;  i < vot.length(); i++)
    {
        if(i <= 1)
        {
            day += vot[i];
        }
        else if(i > 2 && i <= 4)
        {
            month += vot[i];
        }
        else if(i > 5)
        {
            year += vot[i];
        }
    }
    d = day.toInt();
    m = month.toInt();
    y = year.toInt();

    bool isLeaf;
    if(y % 4 == 0 && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0)))
    {
        isLeaf = true;
    }
    else
    {
        isLeaf = false;
    }

    if(m > 12 || m <= 0)
    {
        return answ = false;
    }


    if((m == 1 || m == 3 || m == 5 || m ==7 || m == 8 || m == 10 || m == 12) && (d > 31 || d <=0))
    {
        answ = false;
    }
    else if((m == 1 || m == 3 || m == 5 || m ==7 || m == 8 || m == 10 || m == 12) && (d <= 31 && d >= 1))
    {
        answ = true;
    }
    else if(m == 2 && isLeaf && (d > 29 || d <= 0))
    {
        answ = false;
    }
    else if(m == 2 && isLeaf && (d <= 29 && d >= 1))
    {
        answ = true;
    }
    else if(m  == 2 && !isLeaf && (d > 28 || d <= 0))
    {
        answ = false;
    }
    else if(m == 2 && !isLeaf && (d <= 28 && d >= 1))
    {
        answ = true;
    }
    else if((m != 1 || m != 2 || m != 3 || m != 5 || m !=7 || m != 8 || m != 10 || m != 12) && (d > 30 || d <= 0))
    {
        answ = false;
    }
    else if((m != 1 || m != 2 || m != 3 || m != 5 || m !=7 || m != 8 || m != 10 || m != 12) && (d <= 30 || d >= 1))
    {
        answ = true;
    }
    return answ;
}


void MainWindow::on_pushButton_9_clicked()
{
    bool st;
    bool ok;

    QString text = QInputDialog::getText(nullptr, "Введите дату",
                                         "Новая дата:", QLineEdit::Normal,
                                         "dd.MM.yyyy", &ok);
    if(ok)
    {
        st = proverka(text);
        if(!st)
        {
            QMessageBox::critical(nullptr, "Ошибка", "Неправильный формат даты!");
        }
        else
        {
            QFile file(pathFile);
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                out << text << "\n";
                file.close();
            }
            file.close();
            kolvo++;
            model->setRowCount(kolvo);

            moyaDate[kolvo - 1]->get(text);
            QModelIndex index = model->index(kolvo - 1 , 0);
            moyaDate[kolvo - 1]->set(model, index);

            //getInformation();
        }
    }
}

