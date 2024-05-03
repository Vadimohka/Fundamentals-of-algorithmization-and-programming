#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <vector>

button::button(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::button)
{
    ui->setupUi(this);
}

button::~button()
{
    delete ui;
}


void button::on_pushButton_clicked()
{
    QFile file("D://untitled4//work.txt");
    checkFileForVoidStrings("D://untitled4//work.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream q(&file);
    QWidget *mainWidget1 = new QWidget;
    QVBoxLayout *mainLayout1 = new QVBoxLayout;
    QLabel *label1 = new QLabel;
    QString s;
    int exists = 0;
    q.seek(0);
    int t = 0;
    while (!q.atEnd())
    {
        s = q.readLine().toUtf8();
        if (s == ui->lineEdit->text())
        {
            ++exists;
            label1->setText("-----------------------------------------\n" + s + '\n');
            s = q.readLine();
            label1->setText(label1->text() + s + '\n');
            s = q.readLine();
            label1->setText(label1->text() + s + '\n');
            s = q.readLine();
            label1->setText(label1->text() + s + '\n');
            s = q.readLine();
            label1->setText(label1->text() + s + '\n');
            s = q.readLine();
            label1->setText(label1->text() + s + "\n-----------------------------------------\n\n");
        }
    }
    if (exists == 0)
    {
        label1->setText("Информация о студентах с заданными ФИО не найдена!\n"
                        "Добавьте информацию или введите другое ФИО");
    }
    mainLayout1->addWidget(label1);
    mainWidget1->setLayout(mainLayout1);
    mainWidget1->show();
}
