#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *searchButton = new QPushButton("Run Search", this);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    layout->addWidget(searchButton);

    label16 = new QLabel("Search time for table size 16: ", this);
    layout->addWidget(label16);

    label64 = new QLabel("Search time for table size 64: ", this);
    layout->addWidget(label64);

    label128 = new QLabel("Search time for table size 128: ", this);
    layout->addWidget(label128);

    label2048 = new QLabel("Search time for table size 2048: ", this);
    layout->addWidget(label2048);

    setCentralWidget(centralWidget);
}

void MainWindow::onSearchButtonClicked() {
    std::string value;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        table16.search(i, value);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    label16->setText(QString("Search time for table size 16: %1 microseconds").arg(duration.count()));

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        table64.search(i, value);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    label64->setText(QString("Search time for table size 64: %1 microseconds").arg(duration.count()));

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        table128.search(i, value);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    label128->setText(QString("Search time for table size 128: %1 microseconds").arg(duration.count()));

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        table2048.search(i, value);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    label2048->setText(QString("Search time for table size 2048: %1 microseconds").arg(duration.count()));
}
