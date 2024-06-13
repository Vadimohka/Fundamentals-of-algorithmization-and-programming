#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <string>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    d = Date(ltm->tm_mday, 1+ltm->tm_mon, 1900+ltm->tm_year);

    char* dt = ctime(&now);

    ui->line_main_date->setText(QString::fromStdString(d.to_str()));

    std::vector<Date> date_list;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this, "Select file", "/Users/daryastasiuk/Documents/BSUIR/OOP", "All Files (*.txt)");
    LAST_INDEX = 0;

    date_list.clear();
    current_date_list.clear();


    std::ifstream infile(file_name.toStdString());
    std::string line;
    while (std::getline(infile, line))
    {
        Date d = parse_date_from_str(line);
        d.SetN(LAST_INDEX + 1);
        LAST_INDEX += 1;
        date_list.push_back(d);
    }
    show_vector_in_table(date_list);
    current_date_list = date_list;

}

void MainWindow::show_vector_in_table(std::vector<Date> v) {
    ui->tableWidget->setRowCount(v.size());
    for (int i = 0; i < v.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(QString::fromStdString(v[i].to_str()))));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(QString::fromStdString(v[i].NextDay().to_str()))));
        if (i != v.size() - 1) {
            int diff = abs(v[i] - v[i+1]);
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(diff))));
        }
    }
}


void MainWindow::on_pushButton_set_date_clicked() {
    d = parse_date_from_str(ui->line_main_date->text().toStdString());
    ui->label_next_date->setText(QString::fromStdString(d.NextDay().to_str()));
    ui->label_prev_date->setText(QString::fromStdString(d.PreviousDay().to_str()));
    if (d.IsLeap()) {
        ui->label_leap_date->setText(QString("True"));
    } else {
        ui->label_leap_date->setText(QString("False"));
    }

    ui->label_week_date->setText(QString::fromStdString(std::to_string(d.WeekNumber())));

}


void MainWindow::on_on_buttonCreateSave_clicked_clicked()
{
    int n = stoi(ui->line_create_n->text().toStdString());
    int d_day = stoi(ui->line_create_day->text().toStdString());
    int d_month = stoi(ui->line_create_month->text().toStdString());
    int d_year = stoi(ui->line_create_year->text().toStdString());

    Date d = Date(d_day, d_month, d_year);
    d.SetN(n);

    for (int i = 0; i<date_list.size(); i++) {
        if (date_list[i].GetN() == d.GetN()) {
            date_list[i] = d;
        }
    }

    show_vector_in_table(date_list);
    current_date_list = date_list;

}


void MainWindow::on_tableWidget_itemSelectionChanged()
{
    int row_index = ui->tableWidget->currentRow();
    Date d = current_date_list[row_index];
    ui->line_create_n->setText(QString(QString::fromStdString(std::to_string(d.GetN()))));
    ui->line_create_day->setText(QString(QString::fromStdString(std::to_string(d.GetDay()))));
    ui->line_create_month->setText(QString(QString::fromStdString(std::to_string(d.GetMonth()))));
    ui->line_create_year->setText(QString(QString::fromStdString(std::to_string(d.GetYear()))));
}


void MainWindow::on_on_buttonCreateAdd_clicked_clicked()
{

    int d_day = stoi(ui->line_create_day->text().toStdString());
    int d_month = stoi(ui->line_create_month->text().toStdString());
    int d_year = stoi(ui->line_create_year->text().toStdString());


    Date d = Date(d_day, d_month, d_year);
    d.SetN(LAST_INDEX+1);
    LAST_INDEX+=1;
    date_list.push_back(d);

    show_vector_in_table(date_list);
    current_date_list = date_list;
}


void MainWindow::on_pushButton_Save_to_File_clicked()
{


    std::string file_name;
    file_name = QFileDialog::getOpenFileName(this, "Select file", "/Users/daryastasiuk/Documents/BSUIR/OOP", "All Files (*.txt)").toStdString();
    std::fstream f;
    f.open(file_name, std::ios::out);
    for (int i =0; i<date_list.size(); i++) {
        f << date_list[i].to_str() << "\n";
    }
    f.close();

    ui->label_SaveFileMessage->setText("File saved succesfully!");

}

