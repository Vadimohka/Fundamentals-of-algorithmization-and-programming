//
// Created by zgdarya on 6/1/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "Widget.h"
#include "ui_Widget.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    hashTable = new HashTable(10);
    QVBoxLayout *layout = new QVBoxLayout(this);

    display = new QTextEdit(this);
    display->setReadOnly(true);

    keyInput = new QLineEdit(this);
    valueInput = new QLineEdit(this);

    QPushButton *insertButton = new QPushButton("Insert", this);
    insertButton->setGeometry(10, 10, 100, 25);
    QPushButton *searchButton = new QPushButton("Search", this);
    searchButton->setGeometry(10, 45, 100, 25);
    QPushButton *removeButton = new QPushButton("Remove", this);
    removeButton->setGeometry(10, 80, 100, 25);
    QPushButton *clearButton = new QPushButton("Clear", this);
    clearButton->setGeometry(10, 115, 100, 25);
    QPushButton *printButton = new QPushButton("Print", this);
    printButton->setGeometry(10, 150, 100, 25);

    layout->addWidget(keyInput);
    keyInput->setGeometry(120, 10, 100, 25);
    layout->addWidget(valueInput);
    valueInput->setGeometry(120, 45, 100, 25);

    layout->addWidget(insertButton);
    layout->addWidget(searchButton);
    layout->addWidget(removeButton);
    layout->addWidget(clearButton);
    layout->addWidget(printButton);
    layout->addWidget(display);
    display->setGeometry(120, 80, 200, 200);

    connect(insertButton, &QPushButton::clicked, this, &Widget::insert);
    connect(searchButton, &QPushButton::clicked, this, &Widget::search);
    connect(removeButton, &QPushButton::clicked, this, &Widget::remove);
    connect(clearButton, &QPushButton::clicked, this, &Widget::clear);
    connect(printButton, &QPushButton::clicked, this, &Widget::print);
}

Widget::~Widget() {
    delete ui;
}

void Widget::insert() {
    QString key = keyInput->text();
    QString value = valueInput->text();
    hashTable->insert(key.toStdString(), value.toInt());
    display->append("Inserted (" + key + ", " + value + ")");
}

void Widget::search() {
    QString key = keyInput->text();
    int value = hashTable->searchValue(key.toStdString());
    display->append("Searched for key " + key + ": " + QString::number(value));
}

void Widget::remove() {
    QString key = keyInput->text();
    hashTable->deleteKey(key.toStdString());
    display->append("Removed key " + key);
}

void Widget::clear()  {
    hashTable->clear();
    display->append("Cleared hash table");
}

void Widget::print() {
    QString tableContent = hashTable->print();
    display->append("Hash table content:\n" + tableContent);
}
