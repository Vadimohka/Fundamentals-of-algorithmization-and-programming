#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskinfo.h"
#include "add_to_file.h"
#include "clear_file.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextEdit>
#include <QTextStream>
#include <QVBoxLayout>
#include <QFont>
#include <QLabel>
#include <QFont>
#include "search.h"
#include <iostream>
#include <fstream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <QDebug>
#include <QMessageBox>


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

int n = 0;

void checkFileForVoidStrings(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file" << filePath;
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.trimmed().isEmpty()) {
            QMessageBox::critical(nullptr, "Error", "File contains void strings!");
            return;
        }
    }

    file.close();
}



void MainWindow::on_action_triggered()
{
    ui -> statusbar -> showMessage("Создание нового файла:");
    QFile file("D://untitled4//work.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        file.close();
    Dialog1 a;
    a.setModal(true);
    a.exec();
}

void MainWindow::on_action_2_triggered()
{
    ui -> statusbar -> showMessage("Открытие файла:");
    QFile fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open Text file"), "", tr("Text Files (*.txt)"));
    if (fileName.open(QIODevice::ReadOnly)) {
        QFile file("D://untitled4//work.txt");
        file.open((QIODevice::WriteOnly | QIODevice::Append));
        QByteArray s = fileName.readAll();
        file.write(s);
        Dialog a;
        a.setModal(true);
        a.exec();
    }
}

void MainWindow::on_action_3_triggered()
{
    QApplication::quit();
}


void MainWindow::on_action_4_triggered()
{
    TaskInfo info;
    info.setModal(true);
    info.exec();
}

void MainWindow::on_pushButton_clicked()
{
    student *a = new student;
    a->name = ui -> lineEdit -> text();
    a->speciality = ui -> lineEdit_2 -> text();
    a->group = ui -> lineEdit_3 -> text();
    a->mark1 = ui -> lineEdit_4->text();
    a->mark2 = ui -> lineEdit_5->text();
    a->mark3 = ui -> lineEdit_6->text();
    QString data = a->name + '\n' + a->speciality + '\n' + a->group + '\n' +
                   a->mark1 + '\n' + a->mark2 + '\n' + a->mark3 + '\n';
    ui -> label_7 -> setText("ФИО: " + a->name + '\n' +
                         "Специальность: " + a->speciality + '\n' +
                         "Группа: " + a->group + '\n' +
                         "Отметка за экзамен 1: " + a->mark1 + '\n' +
                         "Отметка за экзамен 2: " + a->mark2 + '\n' +
                         "Отметка за экзамен 3: " + a->mark3 + '\n');
    QFile file("D://untitled4//work.txt");
    if (file.open(QIODevice::Append | QIODevice::ReadWrite)) {
        file.write(data.toUtf8());
    }
    ui -> lineEdit->clear();
    ui -> lineEdit_2->clear();
    ui -> lineEdit_3->clear();
    ui -> lineEdit_4->clear();
    ui -> lineEdit_5->clear();
    ui -> lineEdit_6->clear();
}

void *qs(student *a, int first, int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;
        QString middle = a[(left + right) / 2].name;
        do {
            while (a[left].name < middle)
                ++left;
            while (a[right].name > middle)
                --right;
            if (left <= right) {
                student temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                ++left;
                --right;
            }
        } while (left < right);
        qs(a, first, right);
        qs(a, left, last);
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QFile file("D://untitled4//work.txt");
    file.open(QIODevice::ReadWrite);
    n = 0;
    QString line;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        line = in.readLine();
        if (line != 0)
            n++;
    }
    n /= 6;
    QString s = QString::number(n);
    ui -> statusbar -> showMessage("Студентов в файле: " + s);
    student a[n];
    QTextStream q(&file);
    int i = 0;
    q.seek(0);
    while (!q.atEnd())
    {
        a[i].name = q.readLine().toUtf8();
        a[i].speciality = q.readLine().toUtf8();
        a[i].group = q.readLine().toUtf8();
        a[i].mark1 = q.readLine().toUtf8();
        a[i].mark2 = q.readLine().toUtf8();
        a[i].mark3 = q.readLine().toUtf8();
        ++i;
    }
    qs(a, 0, n - 1);
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QLabel *label = new QLabel;
    if (n != 0) {
        QString data;
        data.toUtf8();
        label->setText("Отсортированные данные по фио:\n");
        for (int i = 0; i < n; ++i) {
            label->setText(label->text() + "------------------------------------------\n"
                                           "Студент № " + QString::number(i + 1) + '\n');
            data = a[i].name + '\n';
            label->setText(label->text() + data.toUtf8());
            data = a[i].speciality + '\n';
            label->setText(label->text() + data.toUtf8());
            data = a[i].group + '\n';
            label->setText(label->text() + data.toUtf8());
            data = a[i].mark1 + '\n';
            label->setText(label->text() + data.toUtf8());
            data = a[i].mark2 + '\n';
            label->setText(label->text() + data.toUtf8());
            data = a[i].mark3 + '\n';
            label->setText(label->text() + data.toUtf8());
            data = "------------------------------------------\n\n";
            label->setText(label->text() + data.toUtf8());
        }
    }
    else
        label->setText("Информация о студентах не найдена!\n"
                       "Добавьте информацию");
    mainLayout->addWidget(label);
    mainWidget->setLayout(mainLayout);
    mainWidget->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui -> statusbar -> showMessage("Открытие файла:");
    QFile fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open Text file"), "", tr("Text Files (*.txt)"));
    if (fileName.open(QIODevice::ReadOnly)) {
        QFile file("D://untitled4//work.txt");
        file.open((QIODevice::WriteOnly | QIODevice::Append));
        QByteArray s = fileName.readAll();
        file.write(s);
        Dialog a;
        a.setModal(true);
        a.exec();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QFile file("D://untitled4//work.txt");
    checkFileForVoidStrings("D://untitled4//work.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream q(&file);
    if (file.pos() != 0)
    {
        button a;
        a.setModal(true);
        a.exec();
    }
    else
    {
        QWidget *mainWidget = new QWidget;
        QVBoxLayout *mainLayout = new QVBoxLayout;
        QLabel *label = new QLabel("Файл с информацией о студентах пуст!\n"
                                   "Добавьте информацию в файл");
        mainLayout->addWidget(label);
        mainWidget->setLayout(mainLayout);
        mainWidget->show();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    Task1 a;
    a.setModal(true);
    a.exec();
}


void MainWindow::on_pushButton_6_clicked()
{
    Task2 a;
    a.setModal(true);
    a.exec();
}


void MainWindow::on_pushButton_8_clicked()
{
    Task3 a;
    a.setModal(true);
    a.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}


void MainWindow::on_lineEdit_2_editingFinished()
{

}
