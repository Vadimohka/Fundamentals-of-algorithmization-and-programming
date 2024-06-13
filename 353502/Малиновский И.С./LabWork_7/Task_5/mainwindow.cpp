#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QInputDialog>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем кнопки
    QPushButton *pushBackButton = new QPushButton("Push Back", this);
    QPushButton *pushFrontButton = new QPushButton("Push Front", this);
    QPushButton *popBackButton = new QPushButton("Pop Back", this);
    QPushButton *popFrontButton = new QPushButton("Pop Front", this);
    QPushButton *clearButton = new QPushButton("Clear", this);
    QPushButton *updateSizeButton = new QPushButton("Update Size", this);
    QPushButton *updateCapacityButton = new QPushButton("Update Capacity", this);

    // Подключаем сигналы clicked кнопок к соответствующим слотам
    connect(pushBackButton, &QPushButton::clicked, this, &MainWindow::on_pushBackButton_clicked);
    connect(pushFrontButton, &QPushButton::clicked, this, &MainWindow::on_pushFrontButton_clicked);
    connect(popBackButton, &QPushButton::clicked, this, &MainWindow::on_popBackButton_clicked);
    connect(popFrontButton, &QPushButton::clicked, this, &MainWindow::on_popFrontButton_clicked);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
    connect(updateSizeButton, &QPushButton::clicked, this, &MainWindow::on_updateSizeButton_clicked);
    connect(updateCapacityButton, &QPushButton::clicked, this, &MainWindow::on_updateCapacityButton_clicked);

    // Добавляем кнопки на форму
    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    layout->addWidget(pushBackButton);
    layout->addWidget(pushFrontButton);
    layout->addWidget(popBackButton);
    layout->addWidget(popFrontButton);
    layout->addWidget(clearButton);
    layout->addWidget(updateSizeButton);
    layout->addWidget(updateCapacityButton);

    // Создаем метку
    dequeInfoLabel = new QLabel("Deque Info", this);

    // Настройка метки (необязательно)
    dequeInfoLabel->setAlignment(Qt::AlignCenter);
    dequeInfoLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    layout->addWidget(dequeInfoLabel);

    // Инициализируем deque
    capacity = 16;
    size = 0;

    // Обновляем информацию о deque
    updateDequeInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBackButton_clicked()
{
    if (size < capacity) {
        deque[size] = size + 1;
        ++size;
        updateDequeInfo();
    }
}


void MainWindow::on_pushFrontButton_clicked()
{
    if (size < capacity) {
        for (int i = size; i > 0; --i) {
            deque[i] = deque[i - 1];
        }
        deque[0] = ++size;
        updateDequeInfo();
    }
}

void MainWindow::on_popBackButton_clicked()
{
    if (size > 0) {
        --size;
        updateDequeInfo();
    }
}

void MainWindow::on_popFrontButton_clicked()
{
    if (size > 0) {
        for (size_t i = 0; i < size - 1; ++i) {
            deque[i] = deque[i + 1];
        }
        --size;
        updateDequeInfo();
    }
}


void MainWindow::on_clearButton_clicked()
{
    size = 0;
    updateDequeInfo();
}

void MainWindow::on_updateSizeButton_clicked()
{
    bool ok;
    int newSize = QInputDialog::getInt(this, tr("Update Size"), tr("Enter new size:"), size, 0, capacity, 1, &ok);
    if (ok) {
        size = newSize;
        updateDequeInfo();
    }
}

void MainWindow::on_updateCapacityButton_clicked()
{
    bool ok;
    int newCapacity = QInputDialog::getInt(this, tr("Update Capacity"), tr("Enter new capacity:"), capacity, size, INT_MAX, 1, &ok);
    if (ok) {
        deque.resize(newCapacity);
        capacity = newCapacity;
        updateDequeInfo();
    }
}

void MainWindow::updateDequeInfo()
{
    // Clear previous content
    dequeInfoLabel->clear();

    // Set new content
    dequeInfoLabel->setText(QString("Size: %1\n").arg(size));
    dequeInfoLabel->setText(QString("Capacity: %1\n").arg(capacity));
    dequeInfoLabel->setText("Contents:\n");
    for (size_t i = 0; i < size; ++i) {
        dequeInfoLabel->setText(QString("%1: %2\n").arg(i).arg(deque[i]));
    }
}

