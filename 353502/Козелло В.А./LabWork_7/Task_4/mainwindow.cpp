#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<size_t> sizes = {16, 64, 128, 2048};
    QVector<QString> keys = {"apple",      "banana",     "grape",      "cherry",    "mango",
                             "lemon",      "peach",      "berry",      "plum",      "pear",
                             "melon",      "kiwi",       "fig",        "lime",      "date",
                             "olive",      "coconut",    "papaya",     "avocado",   "pomegranate",
                             "pineapple",  "tangerine",  "strawberry", "blueberry", "raspberry",
                             "blackberry", "watermelon", "cantaloupe", "honeydew",  "cranberry",
                             "currant",    "grapefruit"};

    for (size_t size : sizes) {
        qDebug() << "HashTable of size " << size << ":\n";
        HashTable ht(size);

        for (const auto &key : keys) {
            ht.insert(key);
        }

        ht.print();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

