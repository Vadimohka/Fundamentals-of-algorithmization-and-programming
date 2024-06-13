#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    treeWidget = new QTreeWidget();
    insertKey = new QLineEdit();
    insertVal = new QLineEdit();
    eraseKey = new QLineEdit();
    keyI = new QLabel();
    keyI->setText("Ключ:       ");
    keyE = new QLabel();
    keyE->setText("Ключ:       ");
    val = new QLabel();
    val->setText("Значение: ");
    insert = new QPushButton();
    insert->setText("Добавить ключ-значение");
    erase = new QPushButton();
    erase->setText("Удалить ключ");

    QVBoxLayout *funcLayout = new QVBoxLayout();
    QHBoxLayout *keyIns = new QHBoxLayout();
    keyIns->addWidget(keyI);
    keyIns->addWidget(insertKey);
    QHBoxLayout *valIns = new QHBoxLayout();
    valIns->addWidget(val);
    valIns->addWidget(insertVal);
    QHBoxLayout *keyEr = new QHBoxLayout();
    keyEr->addWidget(keyE);
    keyEr->addWidget(eraseKey);
    funcLayout->addLayout(keyIns);
    funcLayout->addLayout(valIns);
    funcLayout->addWidget(insert);
    funcLayout->addLayout(keyEr);
    funcLayout->addWidget(erase);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(treeWidget);
    layout->addLayout(funcLayout);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    connect(insert, &QPushButton::clicked, this, &MainWindow::treeInsert);
    connect(erase, &QPushButton::clicked, this, &MainWindow::treeErase);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::treeInsert()
{
    bool ok;
    int key = insertKey->text().toInt(&ok);
    int val = insertVal->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(nullptr, "Ошибка", "Введены некорректные данные!");
        return;
    }
    treeWidget->clear();
    tree.insertValue(key, val);
    tree.print(treeWidget, nullptr);
}

void MainWindow::treeErase()
{
    bool ok;
    int key = eraseKey->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(nullptr, "Ошибка", "Введены некорректные данные!");
        return;
    }
    treeWidget->clear();
    tree.eraseValue(key);
    tree.print(treeWidget, nullptr);
}
