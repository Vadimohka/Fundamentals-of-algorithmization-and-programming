#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include "stepdialog.h"
#include <random>
#include <QDebug>
#include <QElapsedTimer>
#include <QThread>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::default_random_engine generator;

    for (int i = 0; i < 10; ++i) {
        // генерируем случайное целое число от 0 до 99
        int randomNumber = std::uniform_int_distribution<>(1, 100)(generator);

        vector.push_back(randomNumber);
    }
    update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update()
{
    ui->listWidget->clear();
    foreach (int i, vector) {
        ui->listWidget->addItem(QString::number(i));
    }

}
int Widget::interpolationSearch(const QVector<int>& sortedArray, int toFind) {
    int mid;
    // Возвращает индекс элемента со значением toFind или -1, если такого элемента не существует
    int low = 0;
    int high = sortedArray.size() - 1;

    while (sortedArray[low] < toFind && sortedArray[high] > toFind) {
        if (sortedArray[high] == sortedArray[low]) // Защита от деления на 0
            break;
        mid = low + ((toFind - sortedArray[low]) * (high - low)) / (sortedArray[high] - sortedArray[low]);

        if (sortedArray[mid] < toFind)
            low = mid + 1;
        else if (sortedArray[mid] > toFind)
            high = mid - 1;
        else
            return mid;
    }

    if (sortedArray[low] == toFind)
        return low;
    if (sortedArray[high] == toFind)
        return high;

    return -1; // Not found
}



QVector<QVector<int>> Widget::interpolationSort(QVector<int> &vec)
{
    int size = vec.size();
    QVector<QVector<int>> steps;

    // Вычисляем среднее приращение для каждого ключа
    double gap = (double)(size - 1) / (size - 1);

    for (int i = 1; i < size; i++) {
        int temp = vec[i];
        int j = i;

        // Находим место для вставки ключа vec[i]
        while (j >= 1 && vec[j - 1] > temp) {
            vec[j] = vec[j - 1];
            j -= gap;
        }

        vec[j] = temp;
        steps.append(vec);
        update();
    }
    return steps;
}


void Widget::on_clearPushButton_clicked()
{
    vector.clear();
    update();
}


void Widget::on_addPushButton_clicked()
{
    Dialog dialog1;
    dialog1.setWindowTitle("Enter count");
    if(!dialog1.exec())
        return;
    int max = dialog1.getInt();
    Dialog dialog2;
    dialog2.setWindowTitle("Enter minimum");
    if(!dialog2.exec())
        return;
    int left = dialog2.getInt();
    Dialog dialog3;
    dialog3.setWindowTitle("Enter maximum");
    if(!dialog3.exec())
        return;
    int right = dialog3.getInt();
    vector.reserve(max); // резервируем память для 100 элементов

    // создаём генератор случайных чисел
    std::default_random_engine generator;

    for (int i = 0; i < max; ++i) {
        // генерируем случайное целое число от 0 до 99
        int randomNumber = std::uniform_int_distribution<>(left, right)(generator);

        vector.push_back(randomNumber);
    }
    update();
}

void Widget::shuffle(QVector<int> &vector)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < vector.size(); ++i) {
        std::uniform_int_distribution<> dist(0, i);
        int j = dist(gen);
        if (i != j) {
            std::swap(vector[i], vector[j]);
        }
    }
}

unsigned long long Widget::binpow(unsigned long long a, unsigned long long n, unsigned long long m)
{
    if (n == 0) return 1;
    else if (n % 2 == 0) {
        unsigned long long b = binpow(a, n / 2, m);
        return (b * b) % m;
    } else {
        return ((binpow(a, n - 1, m) * a) % m);
    }
}



void Widget::on_pushButton_clicked()
{
    QElapsedTimer timer;
    timer.start();
    QVector<QVector<int>> result = interpolationSort(vector);

    QString execTime = QString::number(timer.elapsed());
    update();
    ui->timeLabel->setText(execTime);
    foreach(QVector<int> step, result){
        StepDialog dialog;
        dialog.set(step);
        if(!dialog.exec())
            return;
    }
}


void Widget::on_shufflePushButton_clicked()
{
    shuffle(vector);
    update();
}


void Widget::on_searchButton_clicked()
{
    Dialog dialog1;
    dialog1.setWindowTitle("Enter number to search");
    if(!dialog1.exec())
        return;
    int search = dialog1.getInt();
    int result = interpolationSearch(vector, search);
    ui->searchLabel->setText(QString::number(result));
    if(result == -1){
        index = 0;
    }
    else{
        index = result;
    }
}


void Widget::on_pushButton_2_clicked()
{
    Dialog dialog1;
    dialog1.setWindowTitle("Enter mod");
    if(!dialog1.exec())
        return;
    int mod = dialog1.getInt();
    unsigned long long calc = binpow(index, vector.size(), mod);
    ui->resultLabel->setText(QString::number(calc));
}

