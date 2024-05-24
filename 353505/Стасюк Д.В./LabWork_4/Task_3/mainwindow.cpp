#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::fillVectorWithRandom(QVector<long long> &vec, int count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    vec.clear();
    vec.reserve(count);

    for (int i = 0; i < count; ++i) {
        vec.push_back(dis(gen));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_random_clicked() {
    int count = ui->count_of_elements->value();
    fillVectorWithRandom(start_vector, count);
    std::string s = "";
    for(int i = 0; i < start_vector.size(); i++) {
        s += std::to_string(start_vector[i]);
        if(i != start_vector.size() - 1) {
            s += ", ";
        }

    }
    ui->label_random->setText(QString::fromStdString(s));
}


void MainWindow::on_get_new_array_clicked() {
    median_treaples *mt = new median_treaples();
    QVector<long long> sorted_vector = mt->get_median_triples(start_vector);
    std::string s = "";
    for(int i = 0; i < sorted_vector.size(); i++) {
        s += std::to_string(sorted_vector[i]);
        if(i != sorted_vector.size() - 1) {
            s += ", ";
        }
    ui->label_answer->setText(QString::fromStdString(s));
}
}

