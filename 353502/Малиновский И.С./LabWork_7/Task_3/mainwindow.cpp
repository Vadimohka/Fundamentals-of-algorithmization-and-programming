#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(nullptr));
    hashtable = CustomHashTable(20);

    // Создаем компоненты визуального интерфейса
    plainTextEdit = new QPlainTextEdit(this);
    generateButton = new QPushButton("Generate", this);
    removeNegativeKeysButton = new QPushButton("Remove Negative Keys", this);

    // Добавляем компоненты в макет
    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    layout->addWidget(plainTextEdit);
    layout->addWidget(generateButton);
    layout->addWidget(removeNegativeKeysButton);

    // Соединяем сигналы и слоты
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::on_generateButton_clicked);
    connect(removeNegativeKeysButton, &QPushButton::clicked, this, &MainWindow::on_removeNegativeKeysButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    hashtable.clear();

    for (int i = 0; i < 30; ++i) {
        int key = rand() % 21 - 10;
        std::string value = "Value" + std::to_string(i);
        hashtable.insert(key, value);
    }

    updatePlainTextEdit();
}

void MainWindow::on_removeNegativeKeysButton_clicked()
{
    hashtable.removeNegativeKeys();
    updatePlainTextEdit();
}

void MainWindow::updatePlainTextEdit()
{
    plainTextEdit->clear();
    std::string text;
    for (size_t i = 0; i < hashtable.table.size(); ++i) {
        text += "Bucket " + std::to_string(i) + ": ";
        std::stack<std::string> temp = hashtable.table[i];
        while (!temp.empty()) {
            text += temp.top() + " ";
            temp.pop();
        }
        text += "\n";
    }
    plainTextEdit->setPlainText(QString::fromStdString(text));
}
