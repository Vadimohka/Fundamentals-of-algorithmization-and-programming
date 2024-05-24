#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pair.h"
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist_i(0, 100);
    for (int i = 0; i < 10; ++i) {
        vec.push_back(dist_i(gen));
    }
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::vectToStr(Vector<int> vec){
    QString aa;
    for (auto i : vec) {
        aa += QString::number(i) + " ";
    }
    return aa;
}

void MainWindow::on_pushButton_clicked()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist_i(0, 100);
    std::uniform_real_distribution<double> dist_d(0.0, 10.0);
    int n = ui->spinBox_n->value();
    int m = ui->spinBox_m->value();
    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vec;
    Vector<int> l;
    Vector<Pair<int, double>> r;
    for (int i = 0; i < n; ++i) {
        l.clear();
        r.clear();
        for (int j = 0; j < m; ++j) {
            l.push_back(dist_i(gen));
            r.push_back(Pair<int, double>(dist_i(gen), dist_d(gen)));
        }
        vec.push_back(Pair<Vector<int>, Vector<Pair<int, double>>>(l, r));
    }
    ui->textEdit_1->clear();
    ui->textEdit_2->clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ui->textEdit_1->setText(ui->textEdit_1->toPlainText() + QString::number(vec.at(i).first.at(j)) + " ");
        }
        ui->textEdit_1->setText(ui->textEdit_1->toPlainText() + ";\n");
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ui->textEdit_2->setText(ui->textEdit_2->toPlainText() + QString::number(vec.at(i).second.at(j).first) + "," + QString::number(vec.at(i).second.at(j).second) + " ");
        }
        ui->textEdit_2->setText(ui->textEdit_2->toPlainText() + ";\n");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    vec.assign(ui->spinBox->value(), ui->spinBox_2->value());
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
    ui->label_ans->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_ans->setText(QString::number(vec.at(ui->spinBox_3->value())));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->label_ans->setText(QString::number(vec.back()));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label_ans->setText(vec.begin().toString());
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->label_ans->setText(QString::number(vec.capacity()));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_7_clicked()
{
    vec.clear();
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->label_ans->setText(QString::number(std::uintptr_t(vec.data())));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->label_ans->setText(vec.emplace(vec.begin() + ui->spinBox_4->value(), ui->spinBox_5->value()).toString());
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_10_clicked()
{
    vec.emplace_back(ui->spinBox_6->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->label_ans->setText(vec.empty() ? "true" : "false");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->label_ans->setText(vec.end().toString());
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_12_clicked()
{
    vec.erase(vec.begin() + ui->spinBox_7->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_13_clicked()
{
    vec.erase(vec.begin() + ui->spinBox_9->value(), vec.begin() + ui->spinBox_8->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->label_ans->setText(QString::number(vec.front()));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_15_clicked()
{
    vec.insert(vec.begin() + ui->spinBox_10->value(), ui->spinBox_11->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_16_clicked()
{
    vec.insert(vec.begin() + ui->spinBox_13->value(), ui->spinBox_12->value(), ui->spinBox_14->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->label_ans->setText(QString::number(vec.max_size()));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}


void MainWindow::on_pushButton_18_clicked()
{
    vec.pop_back();
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}


void MainWindow::on_pushButton_19_clicked()
{
    vec.push_back(ui->spinBox_15->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}


void MainWindow::on_pushButton_20_clicked()
{
    ui->label_ans->setText(vec.rbegin().toString());
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->label_ans->setText(vec.rend().toString());
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_23_clicked()
{
    vec.resize(ui->spinBox_16->value());
    ui->label_ans->setText("");
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->label_ans->setText(QString::number(vec.size()));
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->label_ans->setText(vec.begin().toString());;
    ui->textEdit_arr->setText("Your vector: " + vectToStr(vec));
}

