#include "mainwindow.h"
#include "qgraphicsitem.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>

// Конструктор класса MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // Инициализация пользовательского интерфейса
{
    ui->setupUi(this); // Установка пользовательского интерфейса
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Устанавливаем растягивание столбцов таблицы
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Запрещаем редактирование содержимого таблицы
    if (!ui->graphicsView->scene()) // Если сцена QGraphicsView еще не установлена
        ui->graphicsView->setScene(new QGraphicsScene(this)); // Устанавливаем новую сцену QGraphicsScene

    // Подключаем сигнал нажатия кнопки "Start" к слоту startMoving()
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startMoving);
    // Подключаем сигнал нажатия кнопки "Push" к слоту refresh()
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::refresh);

    ui->spinBox->setMinimum(1); // Устанавливаем минимальное значение для спинбокса
    ui->spinBox->setMaximum(18); // Устанавливаем максимальное значение для спинбокса
}

// Деструктор класса MainWindow
MainWindow::~MainWindow()
{
    delete ui; // Удаляем пользовательский интерфейс
}

// Функция для добавления строки в таблицу
void MainWindow::addRow() {
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1); // Увеличиваем количество строк в таблице на 1
    for (int i = 0; i < 3; ++i) { // Перебираем столбцы таблицы
        QTableWidgetItem *pCell = ui->tableWidget->item(ui->tableWidget->rowCount() - 1, i); // Получаем ячейку таблицы
        if (!pCell) { // Если ячейка не существует
            pCell = new QTableWidgetItem; // Создаем новую ячейку
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, i, pCell); // Устанавливаем ячейку в таблицу
        }
        pCell->setText(QString::number(diskCount[i])); // Устанавливаем текст ячейки, содержащий количество дисков
    }

    if (diskStacks.empty()) { // Если вектор стеков дисков пуст
        QVector<QVector<int>> stack(3); // Создаем новый вектор стеков
        for (int i = 0; i < 3; ++i) { // Перебираем стеки
            QVector<int> disks; // Создаем новый стек дисков
            if (i == 0) { // Если это первый стек
                for (int j = 1; j <= ui->spinBox->value(); ++j) { // Перебираем количество дисков из спинбокса
                    disks.push_back(j); // Добавляем диск в стек
                }
            }
            stack[i] = disks; // Устанавливаем стек в вектор стеков
        }
        diskStacks.push_back(stack); // Добавляем вектор стеков в вектор стеков
    }
}

// Функция для решения задачи Ханой
void MainWindow::hanoi(int n, int from, int to, int aux) {
    if (n == 0) return; // Если количество дисков равно 0, завершаем функцию

    if (n == 1) { // Если количество дисков равно 1
        --diskCount[from]; // Уменьшаем количество дисков на стартовой башне
        ++diskCount[to]; // Увеличиваем количество дисков на целевой башне
        if (!diskStacks.empty()) { // Если вектор стеков не пуст
            QVector<QVector<int>> stack(3); // Создаем новый вектор стеков
            QVector<int> disks = diskStacks.back()[from]; // Получаем стек дисков на стартовой башне
            disks.pop_back(); // Удаляем верхний диск из стека
            stack[from] = disks; // Устанавливаем обновленный стек дисков на стартовой башне
            disks = diskStacks.back()[to]; // Получаем стек дисков на целевой башне
            disks.push_back(diskStacks.back()[from].back()); // Добавляем верхний диск из стартовой башни на целевую башню
            stack[to] = disks; // Устанавливаем обновленный стек дисков на целевой башне
            stack[aux] = diskStacks.back()[aux]; // Устанавливаем стек дисков на вспомогательной башне
            diskStacks.push_back(stack); // Добавляем вектор стеков в вектор стеков
        }
        addRow(); // Добавляем новую строку в таблицу
        return; // Завершаем функцию
    }

    hanoi(n - 1, from, aux, to); // Рекурсивно перемещаем n-1 дисков с стартовой башни на вспомогательную башню
    --diskCount[from]; // Уменьшаем количество дисков на стартовой башне
    ++diskCount[to]; // Увеличиваем количество дисков на целевой башне
    if (!diskStacks.empty()) { // Если вектор стеков не пуст
        QVector<QVector<int>> stack(3); // Создаем новый вектор стеков
        QVector<int> disks = diskStacks.back()[from]; // Получаем стек дисков на стартовой башне
        disks.pop_back(); // Удаляем верхний диск из стека
        stack[from] = disks; // Устанавливаем обновленный стек дисков на стартовой башне
        disks = diskStacks.back()[to]; // Получаем стек дисков на целевой башне
        disks.push_back(diskStacks.back()[from].back()); // Добавляем верхний диск из стартовой башни на целевую башню
        stack[to] = disks; // Устанавливаем обновленный стек дисков на целевой башне
        stack[aux] = diskStacks.back()[aux]; // Устанавливаем стек дисков на вспомогательной башне
        diskStacks.push_back(stack); // Добавляем вектор стеков в вектор стеков
    }
    addRow(); // Добавляем новую строку в таблицу
    hanoi(n - 1, aux, to, from); // Рекурсивно перемещаем n-1 дисков с вспомогательной башни на целевую башню
}

// Функция для начала анимации решения задачи Ханой
void MainWindow::startMoving()
{
    diskCount[0] = ui->spinBox->value(); // Устанавливаем количество дисков на стартовой башне из спинбокса
    diskCount[1] = 0; // Устанавливаем количество дисков на вспомогательной башне в 0
    diskCount[2] = 0; // Устанавливаем количество дисков на целевой башне в 0
    ui->tableWidget->setRowCount(0); // Устанавливаем количество строк в таблице в 0
    diskStacks.clear(); // Очищаем вектор стеков дисков
    addRow(); // Добавляем новую строку в таблицу
    hanoi(ui->spinBox->value(), 0, 2, 1); // Вызываем функцию решения задачи Ханой
    stackHeight = diskStacks.size(); // Устанавливаем высоту стека равной размеру вектора стеков

    currentIndex = stackHeight - 1; // Устанавливаем текущий индекс равным высоте стека минус 1

    timer = new QTimer(this); // Создаем новый таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::moveNextStep); // Подключаем сигнал таймера к слоту moveNextStep()
    timer->start(1); // Запускаем таймер с интервалом в 3 миллисекунды
}

// Функция для отображения следующего шага решения задачи Ханой
void MainWindow::moveNextStep()
{
    if (currentIndex >= 0) { // Если текущий индекс неотрицателен
        showStep(diskStacks[currentIndex--]); // Отображаем текущий шаг решения задачи Ханой
    } else { // Иначе
        timer->stop(); // Останавливаем таймер
    }
}

// Функция для отображения шага решения задачи Ханой
void MainWindow::showStep(QVector<QVector<int>> stack)
{
    ui->graphicsView->scene()->clear(); // Очищаем сцену QGraphicsView
    for (int i = 0; i < 3; ++i) { // Перебираем башни
        for (int j = 0; j < stack[i].size(); ++j) { // Перебираем диски на текущей башне
            int towerWidth = 200; // Ширина башни
            int diskHeight = 20; // Высота диска
            int diskWidth = 10 * (ui->spinBox->value() - stack[i][j] + 1); // Ширина диска
            int gap = 5; // Расстояние между дисками
            int x = (i + 1) * towerWidth - diskWidth / 2; // Координата x верхнего левого угла прямоугольника
            int y = ui->graphicsView->height() - (j + 1) * (diskHeight + gap); // Координата y верхнего левого угла прямоугольника
            int width = diskWidth; // Ширина прямоугольника
            int height = diskHeight; // Высота прямоугольника

            // Генерация случайного цвета
            int red = QRandomGenerator::global()->bounded(256); // Красный компонент цвета
            int green = QRandomGenerator::global()->bounded(256); // Зеленый компонент цвета
            int blue = QRandomGenerator::global()->bounded(256); // Синий компонент цвета
            QColor color(red, green, blue); // Создаем случайный цвет

            // Создание прямоугольника с случайным цветом
            QGraphicsRectItem *rectangle = new QGraphicsRectItem(x, y, width, height); // Создаем прямоугольник
            rectangle->setBrush(QBrush(color)); // Устанавливаем цвет заливки прямоугольника

            // Добавление прямоугольника на сцену
            ui->graphicsView->scene()->addItem(rectangle); // Добавляем прямоугольник на сцену
        }
    }
}

// Функция для обновления интерфейса
void MainWindow::refresh()
{
    // Очищаем значения в QSpinBox
    ui->spinBox->clear();

    // Очищаем содержимое QTextEdit
    ui->tableWidget->clear();

    // Очищаем содержимое QTableWidget
    ui->tableWidget->clear();

    // Очищаем сцену QGraphicsView
    ui->graphicsView->scene()->clear();

    // Сбрасываем вектор стеков дисков
    diskStacks.clear();

    // Сбрасываем текущий индекс
    currentIndex = 0;

    // Останавливаем таймер, если он запущен
    if (timer && timer->isActive()) {
        timer->stop();
    }
}
