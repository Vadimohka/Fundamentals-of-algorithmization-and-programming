#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.cpp"
#include "student.h"
#include "student.cpp"
#include "merge.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
List students;
QString path;
bool check(QString name)
{
    ll x = 0;
    for(ll i = 0; i < name.length(); i++)
    {
        if(name[i] == ' ')
            x++;
    }
    if(x == 2)
        return 1;
    else
        return 0;
}
void MainWindow::on_pushButton_12_clicked()
{
    student ab;
    ui->listWidget->clear();
    QString name = ui->lineEdit_6->text();
    ll physics = ui->lineEdit->text().toLongLong();
    ll math = ui->lineEdit_2->text().toLongLong();
    ll rus = ui->lineEdit_3->text().toLongLong();
    if(!rus or !physics or !math or !check(name))
       QMessageBox::critical(this, "Ошибка", "Ввод");
    else
    {
    ab.set_math(math);
    ab.set_physics(physics);
    ab.set_rus(rus);
    ab.set_name(name.toStdString());
    students.push_back(ab);
    }
    for(ll i = 0; i < students.size(); i++)
    {
        QString math = QString::number(students[i].get_math());
        QString physics = QString::number(students[i].get_physics());
        QString rus = QString::number(students[i].get_rus());
        ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if (ui->listWidget->currentRow() >= 0)
   students.erase(ui->listWidget->currentRow());
    else
        QMessageBox::critical(this, "Ошибка", "Удаление не выбранной строки");
     ui->listWidget->clear();
     for(ll i = 0; i < students.size(); i++)
     {
         QString math = QString::number(students[i].get_math());
         QString physics = QString::number(students[i].get_physics());
         QString rus = QString::number(students[i].get_rus());
         ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
     }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(students.size() > 0)
    students.clear();
    ui->listWidget->clear();
    path = QFileDialog::getOpenFileName(this, "выберите файл", "C:/Users/kira1/OneDrive/Рабочий стол/файлы", "*.txt");
    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
        while(!file.atEnd())
        {
          student ab;
          QString info = file.readLine();
          QStringList infolist = info.split(" ");
          QString name = infolist[0] + " " + infolist[1] + " " + infolist[2];
          QString math = infolist[3];
          QString physics = infolist[4];
          QString rus = infolist[5];
          ab.set_math(math.toLongLong());
          ab.set_physics(physics.toLongLong());
          ab.set_rus(rus.toLongLong());
          ab.set_name(name.toStdString());
          students.push_back(ab);
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
    }
    file.close();
    for(ll i = 0; i < students.size(); i++)
    {
        QString math = QString::number(students[i].get_math());
        QString physics = QString::number(students[i].get_physics());
        QString rus = QString::number(students[i].get_rus());
        ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    path = QFileDialog::getSaveFileName(this, "выберите файл", "C:/Users/kira1/OneDrive/Рабочий стол/файлы", "*.txt");
    QFile file(path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        for(ll i = 0; i < ui->listWidget->count();i++)
        {
            QListWidgetItem *item = ui->listWidget->item(i);
            QTextStream out(&file);
            out << item->text();
        }
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    if(students.size() > 1)
    {
    ui->listWidget->clear();
    ll average = 0;
    for(ll i = 0; i < students.size(); i++)
    {
        average += students[i].get_math();
        average += students[i].get_physics();
        average += students[i].get_rus();
    }
    average /= (students.size()* 3);
    for(ll i = 0; i < students.size(); i++)
    {
        if((students[i].get_math() + students[i].get_physics() + students[i].get_rus())/3 > average)
        {
        QString math = QString::number(students[i].get_math());
        QString physics = QString::number(students[i].get_physics());
        QString rus = QString::number(students[i].get_rus());
        ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
        }
    }
}
}
void MainWindow::on_pushButton_13_clicked()
{
    ui->listWidget->clear();
QString key = ui->lineEdit_11->text();
for(ll i = 0; i < students.size();i++)
{
    if(QString::fromStdString(students[i].get_name()) == key or QString::number(students[i].get_math()) == key or QString::number(students[i].get_physics()) == key or QString::number(students[i].get_math()) == key)
    {
        QString math = QString::number(students[i].get_math());
        QString physics = QString::number(students[i].get_physics());
        QString rus = QString::number(students[i].get_rus());
        ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
    }
}
}

void MainWindow::on_pushButton_10_clicked()
{

}
bool cmpName(const student& ab1, const student& ab2) {
    QString str1 = QString::fromStdString(ab1.get_name());
    QString str2 = QString::fromStdString(ab2.get_name());
    for (int i = 0; i < ab1.get_name().length() and i < ab2.get_name().length(); i++)
    {
        if (str1[i].toLower() < str2[i].toLower())
            return true;
        if (str1[i].toLower() > str2[i].toLower())
            return false;
    }
    return false;
}
void MainWindow::on_pushButton_5_clicked()
{
    auto arr = new student[students.size()];
        for (ll i = 0; i < students.size(); i++)
        {
            arr[i] = students[i];
        }
        merge_sort(arr, students.size(), cmpName);
        ui->listWidget->clear();
        for(ll i = 0; i < students.size(); i++)
        {
            students[i] = arr[i];
            QString math = QString::number(students[i].get_math());
            QString physics = QString::number(students[i].get_physics());
            QString rus = QString::number(students[i].get_rus());
            ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
        }
}
void MainWindow::on_pushButton_6_clicked()
{
    ui->listWidget->clear();
    for(ll i = 0; i < students.size(); i++)
    {
        QString math = QString::number(students[i].get_math());
        QString physics = QString::number(students[i].get_physics());
        QString rus = QString::number(students[i].get_rus());
        ui->listWidget->addItem(QString::fromStdString(students[i].get_name()) + " " + math + " " + physics + " " + rus);
    }
}
void MainWindow::on_pushButton_8_clicked()
{

}

