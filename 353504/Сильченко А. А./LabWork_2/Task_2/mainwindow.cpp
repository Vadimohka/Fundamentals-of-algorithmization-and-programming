#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(248, 179, 220));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);

    std::vector<Deputy> book_list;
    ui->pushAlarm->setStyleSheet("background-color:red");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this, "Select file", "/Users/daryastasiuk/Documents/BSUIR/OOP", "All Files (*.txt)");
    LAST_INDEX = 0;

    book_list.clear();
    current_book_list.clear();

    std::vector<std::string> companies;

    std::ifstream infile(file_name.toStdString());
    std::string line;
    while (std::getline(infile, line))
    {
        Deputy b = parse_book_from_str(line);
        b.SetId(LAST_INDEX + 1);
        LAST_INDEX += 1;
        book_list.push_back(b);

        companies.push_back(b.GetBookCompany());
    }

    for(int i = 0;i < companies.size();i++)
    {
        int counter = 0;
        for(int j = i;j < companies.size() && counter < 2;j++)
        {
            if(companies[i] == companies[j])
                counter++;
        }
        if(counter == 1) {
            ui->comboBox_Company->addItem(QString::fromStdString(companies[i]));
        }
    }

    show_vector_in_table(book_list);
    current_book_list = book_list;
}

void MainWindow::show_vector_in_table(std::vector<Deputy> v) {
    ui->tableWidget->setRowCount(v.size());
    for (int i = 0; i < v.size(); i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(v[i].GetAuthor())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(v[i].GetBookName())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(v[i].GetBookCompany())));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(std::to_string(v[i].GetBookYear()))));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::fromStdString(std::to_string(v[i].GetPageQuantity()))));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::fromStdString(std::to_string(v[i].GetNumber()))));
    }
}


void MainWindow::on_search_button_clicked()
{
    std::string query = ui->line_search->text().toStdString();
    std::vector<Deputy> search_result;
    for (int i = 0; i<book_list.size(); i++) {
        if ((book_list[i].GetBookName().find(query) != std::string::npos) || (book_list[i].GetAuthor().find(query) != std::string::npos)) {
            search_result.push_back(book_list[i]);
        }
    }

    show_vector_in_table(search_result);
    current_book_list = search_result;
}


void MainWindow::on_sort_year_clicked()
{
    std::vector<Deputy> bl_copy = book_list;
    for (int i = 0; i <= bl_copy.size(); i++) {
        for (int j = 0; j < bl_copy.size() - 1; j++)
        {
            if (bl_copy[j].GetBookYear() > bl_copy[j + 1].GetBookYear()) {
                Deputy temp = bl_copy[j];
                bl_copy[j] = bl_copy[j + 1];
                bl_copy[j + 1] = temp;
            }
        }
    }


    show_vector_in_table(bl_copy);
    current_book_list = bl_copy;
}


void MainWindow::on_comboBox_Company_currentIndexChanged(int index)
{
    std::string query = ui->comboBox_Company->currentText().toStdString();

    std::vector<Deputy> search_result;
    for (int i = 0; i<book_list.size(); i++) {
        if (book_list[i].GetBookCompany().find(query) != std::string::npos) {
            search_result.push_back(book_list[i]);
        }
    }

    show_vector_in_table(search_result);
    current_book_list = search_result;
}


void MainWindow::on_pushButton_Save_clicked()
{

    std::string file_name;
    file_name = QFileDialog::getOpenFileName(this, "Select file", "/Users/daryastasiuk/Documents/BSUIR/OOP", "All Files (*.txt)").toStdString();
    std::fstream f;
    f.open(file_name, std::ios::out);
    for (int i =0; i<book_list.size(); i++) {
        f << book_list[i].to_str() << "\n";
    }
    f.close();

    ui->label_SaveFileMessage->setText("File saved succesfully!");
}


void MainWindow::on_tableWidget_itemSelectionChanged()
{
    int row_index = ui->tableWidget->currentRow();
    Deputy b = current_book_list[row_index];
    //ui->line_create_id->setText(QString::fromStdString(std::to_string(b.GetId())));
    ui->line_create_author->setText(QString::fromStdString(b.GetAuthor()));
    ui->line_create_bookName->setText(QString::fromStdString(b.GetBookName()));
    ui->line_create_bookYear->setText(QString::fromStdString(std::to_string(b.GetBookYear())));
    ui->line_create_companyName->setText(QString::fromStdString(b.GetBookCompany()));
    ui->line_create_pageQuantity->setText(QString::fromStdString(std::to_string(b.GetPageQuantity())));
    ui->line_create_pageQuantity_2->setText(QString::fromStdString(std::to_string(b.GetNumber())));
}


void MainWindow::on_buttonCreateSave_clicked()
{
    //int id = stoi(ui->line_create_id->text().toStdString());
    std::string b_author = ui->line_create_author->text().toStdString();
    std::string b_name = ui->line_create_bookName->text().toStdString();
    int b_year = stoi(ui->line_create_bookYear->text().toStdString());
    std::string b_comp_name = ui->line_create_companyName->text().toStdString();
    int b_page_quantity = stoi(ui->line_create_pageQuantity->text().toStdString());
    int num = stoi(ui->line_create_pageQuantity_2->text().toStdString());

    Deputy b = Deputy(b_author, b_name, b_comp_name, b_year, b_page_quantity, num);
    //b.SetId(id);

    for (int i = 0; i<book_list.size(); i++) {
        if (book_list[i].GetId() == b.GetId()) {
            book_list[i] = b;
        }
    }

    show_vector_in_table(book_list);
    current_book_list = book_list;
}


void MainWindow::on_buttonCreateAdd_clicked()
{
    std::string b_author = ui->line_create_author->text().toStdString();
    std::string b_name = ui->line_create_bookName->text().toStdString();
    int b_year = stoi(ui->line_create_bookYear->text().toStdString());
    std::string b_comp_name = ui->line_create_companyName->text().toStdString();
    int b_page_quantity = stoi(ui->line_create_pageQuantity->text().toStdString());
    int num = stoi(ui->line_create_pageQuantity_2->text().toStdString());

    Deputy b = Deputy(b_author, b_name, b_comp_name, b_year, b_page_quantity, num);
    b.SetId(LAST_INDEX+1);
    LAST_INDEX+=1;
    book_list.push_back(b);

    show_vector_in_table(book_list);
    current_book_list = book_list;
}

void MainWindow::on_pushAlarm_clicked()
{
    if(!bimage)
    {
        ui->pushAlarm->setStyleSheet("background-color:green");
        QPixmap pix("/home/oblachko/Projects/LabWork_2/task_2/cat.jpg");
        ui->label_8->setPixmap(pix);
        ui->label_9->setText("Пашкадуйце, калi ласка");
        ui->pushAlarm->setText("Всё хорошо");
    }
    else
    {
        ui->pushAlarm->setStyleSheet("background-color:red");
        ui->label_9->setText(" ");
        ui->label_8->setText(" ");
        ui->pushAlarm->setText("Нажать, когда всё плохо");
    }

    bimage=!bimage;
}
