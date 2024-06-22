#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    hashTable = new ExtendedHashTable(10);
    outputTextEdit = new QTextEdit(this);
    setCentralWidget(outputTextEdit);

    insertRandomButton = new QPushButton("Insert Random Data", this);
    findMaxKeyButton = new QPushButton("Find Max Key", this);
    printTableButton = new QPushButton("Print Table", this);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(insertRandomButton);
    buttonLayout->addWidget(findMaxKeyButton);
    buttonLayout->addWidget(printTableButton);

    QWidget *buttonWidget = new QWidget(this);
    buttonWidget->setLayout(buttonLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(outputTextEdit);
    mainLayout->addWidget(buttonWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(insertRandomButton, &QPushButton::clicked, this, &MainWindow::onInsertRandomClicked);
    connect(findMaxKeyButton, &QPushButton::clicked, this, &MainWindow::onFindMaxKeyClicked);
    connect(printTableButton, &QPushButton::clicked, this, &MainWindow::onPrintTableClicked);
}

MainWindow::~MainWindow()
{
    delete hashTable;
}

void MainWindow::onInsertRandomClicked()
{
    hashTable->insertRandomData();
    outputTextEdit->append("Random data inserted into hashtable.");
}

void MainWindow::onFindMaxKeyClicked()
{
    int maxKey = hashTable->findMaxKey();
    outputTextEdit->append("Maximum key found: " + QString::number(maxKey));
}

void MainWindow::onPrintTableClicked()
{
    hashTable->printTable();
}

