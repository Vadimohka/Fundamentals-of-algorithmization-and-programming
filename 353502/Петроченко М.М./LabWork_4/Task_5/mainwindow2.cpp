//
// Created by acryoz on 4/26/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow2.h" resolved

#include "../headers/mainwindow2.h"
#include <QTextStream>
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow2) {
    ui->setupUi(this);
    Vector<int> vec1;
    for (int i = 0; i < 10; ++i) {
        vec1.push_back(i);
    }
    Vector<Pair<int, double>> vec2;
    for (int i = 0; i < 10; ++i) {
        vec2.push_back(Pair(i, i + 0.3));
    }
    this->pair_.first = vec1;
    this->pair_.second = vec2;

    this->first_matrix = new QLabel;
    this->second_matrix = new QLabel;
    QString first;
    QString second;
    QTextStream first_text_stream(&first);
    QTextStream second_text_stream(&second);
    for (int item : vec1) {
        first_text_stream << item << ' ';
    }
    this->first_matrix->setText(first);
    for (const auto& item : vec2) {
        second_text_stream << item.first << '\t' << item.second << '\n';
    }
    this->second_matrix->setText(second);
    this->hbox = new QHBoxLayout;
    this->hbox->addWidget(this->first_matrix);
    this->hbox->addWidget(this->second_matrix);
    this->setLayout(this->hbox);
}

MainWindow2::~MainWindow2() {
    delete ui;
}
