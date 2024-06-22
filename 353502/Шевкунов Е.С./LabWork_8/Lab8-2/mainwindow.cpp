#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), useArray(true) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    classSelector = new QComboBox(this);
    classSelector->addItem("BinaryHeapArray");
    classSelector->addItem("BinaryHeapList");
    connect(classSelector, &QComboBox::currentTextChanged, this, &MainWindow::onComboBoxChanged);

    valueInput = new QLineEdit(this);
    valueInput->setPlaceholderText("Enter value");

    insertButton = new QPushButton("Insert", this);
    extractMaxButton = new QPushButton("Extract Max", this);
    getMaxButton = new QPushButton("Get Max", this);

    connect(insertButton, &QPushButton::clicked, this, &MainWindow::onInsertButtonClicked);
    connect(extractMaxButton, &QPushButton::clicked, this, &MainWindow::onExtractMaxButtonClicked);
    connect(getMaxButton, &QPushButton::clicked, this, &MainWindow::onGetMaxButtonClicked);

    output = new QTextEdit(this);
    output->setReadOnly(true);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(new QLabel("Class:", this));
    inputLayout->addWidget(classSelector);
    inputLayout->addWidget(new QLabel("Value:", this));
    inputLayout->addWidget(valueInput);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(insertButton);
    buttonLayout->addWidget(extractMaxButton);
    buttonLayout->addWidget(getMaxButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(output);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::onInsertButtonClicked() {
    bool ok;
    int value = valueInput->text().toInt(&ok);
    if (!ok) {
        output->append("Invalid value");
        return;
    }
    if (useArray) {
        heapArray.insert(value);
    } else {
        heapList.insert(value);
    }
    updateOutput();
}

void MainWindow::onExtractMaxButtonClicked() {
    try {
        int maxValue;
        if (useArray) {
            maxValue = heapArray.extractMax();
        } else {
            maxValue = heapList.extractMax();
        }
        output->append("Extracted Max: " + QString::number(maxValue));
    } catch (const std::runtime_error &e) {
        output->append(e.what());
    }
    updateOutput();
}

void MainWindow::onGetMaxButtonClicked() {
    try {
        int maxValue;
        if (useArray) {
            maxValue = heapArray.getMax();
        } else {
            maxValue = heapList.getMax();
        }
        output->append("Max: " + QString::number(maxValue));
    } catch (const std::runtime_error &e) {
        output->append(e.what());
    }
}

void MainWindow::onComboBoxChanged(const QString &text) {
    if (text == "BinaryHeapArray") {
        useArray = true;
    } else {
        useArray = false;
    }
    updateOutput();
}

void MainWindow::updateOutput() {
    output->append(useArray ? "Using BinaryHeapArray" : "Using BinaryHeapList");
    output->append("Heap state: ");
    if (useArray) {
        for (int i = 0; i < heapArray.size(); ++i) {
            output->append(QString::number(heapArray.at(i)) + " ");
        }
    } else {
        for (int i = 0; i < heapList.size(); ++i) {
            output->append(QString::number(heapList.at(i)) + " ");
        }
    }
    output->append("\n");
}
