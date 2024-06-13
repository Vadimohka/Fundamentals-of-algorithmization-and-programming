#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->readFile, &QPushButton::clicked, this, &MainWindow::readFromFile);
    connect(ui->writeFile, &QPushButton::clicked, this, &MainWindow::wtriteToFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wtriteToFile()
{
    if(ui->radioButton->isChecked())
    {
        QString text = ui->textEdit->toPlainText();

        QFile file("LogovoyFile20.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << text;
            file.close();
            ui->textEdit->clear();
        }
    }

    else if(ui->radioButton_1->isChecked())
    {
        QString text = ui->textEdit->toPlainText();
        QStringList list = text.split('\n');

        array.clear();

        for (QString s : list){
            array.append(s.toLong());
        }

        QFile file("LogovoyFile20_0.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }

        QTextStream out(&file);
        for (long int i : array)
        {
            out << i << '~';
        }
    }

    else if(ui->radioButton_2->isChecked())
    {
        QString text = ui->textEdit->toPlainText();

        QFile file("Logovoy20_3.txt");
        if(file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out << text << "\n";
            file.close();
            ui->textEdit->clear();
        }
    }

    else if(ui->radioButton_3->isChecked())
    {
        QFile file("LogovoyFile20_1.txt");
        if(file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            for(const Airport &airport : airports)
            {
                out << airport.id << '|' << airport.altitude
                    << '|' << airport.isOpen << '|'
                    << airport.name << '|' << airport.flights << "\n";
            }
            file.close();
        }

        QFile binFile("LogovoyFile_2.bin");
        if(binFile.open(QIODevice::Append))
        {
            QDataStream out(&binFile);
            for(const Airport &airport : airports)
            {
                out << airport.id << airport.altitude << airport.isOpen << airport.name << airport.flights;
            }
            binFile.close();
        }
    }

    else if(ui->radioButton_4->isChecked())
    {
        QString text = ui->textEdit->toPlainText();

        QFile file("LogovoyFile_3.txt");
        if(file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out << text << "\n";
            file.close();
            ui->textEdit->clear();
        }
    }

    ui->textEdit->clear();
}


void MainWindow::readFromFile()
{
    if(ui->radioButton->isChecked())
    {
        QFile file("LogovoyFile20.txt");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
        ui->textBrowser->clear();
        QTextStream in(&file);
        QString readText = in.readAll();
        file.close();
        ui->textBrowser->setText(readText);

        }
    }

    else if(ui->radioButton_1->isChecked())
    {
        QFile file("LogovoyFile20_0.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        QTextStream in(&file);
        QString line = in.readLine();
        QStringList list = line.split('~');

        array.clear();
        for (QString s : list)
        {
            array.append(s.toLong());
        }

        QString output;
        for (long int i : array)
        {
            output += QString::number(i) + ' ';
        }
        ui->textBrowser->clear();
        ui->textBrowser->setText(output);
    }

    else if(ui->radioButton_2->isChecked())
    {
        QFile file("Logovoy20_3.txt");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->textBrowser->clear();
            QTextStream in(&file);
            while(!in.atEnd())
            {
                QString line = in.readLine();
                ui->textBrowser->append(line);
            }
            file.close();
        }
    }

    else if(ui->radioButton_3->isChecked())
    {
        QFile file("LogovoyFile20_1.txt");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->textBrowser->clear();
            QTextStream in(&file);
            while(!in.atEnd())
            {
                QString line = in.readLine();
                ui->textBrowser->append(line.replace('|', ' '));
            }
            file.close();
        }

        QFile binFile("LogovoyFile_2.bin");
        QDataStream in(&binFile);
        while(!in.atEnd())
        {
            Airport airport;
            in >> airport.id >> airport.altitude >> airport.isOpen;

            QByteArray nameArray;
            in >> nameArray;
            strncpy(airport.name, nameArray.data(), sizeof(airport.name));

            for(int i = 0; i < 10; i++)
            {
                in >> airport.flights[i];
            }

            ui->textBrowser->append(QString::number(airport.id) + " ; " + QString::number(airport.altitude) + " ; "
                                    + (airport.isOpen ? "Open" : "Closed") + " ; "
                                    + airport.name + " ; " + QString::number(airport.flights[0]));
        }

    }

    else if(ui->radioButton_4->isChecked())
    {
        QFile file("LogovoyFile_3.txt");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->textBrowser->clear();
            QTextStream in(&file);
            while(!in.atEnd())
            {
                QString line = in.readLine();
                ui->textBrowser->append(line);
            }
            file.close();
        }
    }
}
