#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <algorithm>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем сцену для отображения графика
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    QString styleSheet = R"(


    QPushButton {
        background-color: #9ACD32;
        border: none;


    }

    QPushButton:hover {
        background-color: #0056b3;
    }



)";
    this->setStyleSheet(styleSheet);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Quick_sort_clicked()
{
    scene->clear();
    // Очищаем содержимое textEdit перед добавлением новых данных
    ui->textEdit->clear();

    // Очищаем массив array перед добавлением новых данных
    array.clear();


    QString text = ui->lineEdit->text();
    QStringList numbers = text.split(' ', Qt::SkipEmptyParts);

    // Проверка и преобразование строк в целые числа
    for (const QString& number : numbers) {
        int value;
        bool ok;
        value = number.toInt(&ok);
        if (ok) {
            array.push_back(value);
        } else {
            QMessageBox::warning(this, "Ошибка", "Введите только целые числа!");
            return;
        }
    }

    // Старт таймера
    QElapsedTimer timer;
    timer.start();

    // Сортировка
    sorter.quickSort(array, 0, array.size() - 1);

    // Очищаем содержимое textEdit перед добавлением новых данных
    ui->textEdit->clear();

    // Вывод отсортированного массива в textEdit
    QString sortedArrayText;
    for (int i = 0; i < array.size(); ++i) {
        sortedArrayText += QString::number(array[i]) + " ";
    }
    ui->textEdit->setText(sortedArrayText);

    // Отображение времени выполнения сортировки
    qint64 elapsed = timer.nsecsElapsed() / 1000; // Переводим наносекунды в микросекунды
    ui->textEdit_2->setText("Время сортировки: " + QString::number(elapsed) + " мкс");

    // Рассчитываем скорость сортировки
    double speed = static_cast<double>(array.size()) / elapsed;

    // Выводим скорость сортировки
    QString speedText = "Скорость сортировки: " + QString::number(speed, 'f', 2) + " элементов/мкс";
    ui->textEdit_2->append(speedText);

    // Отрисовка графика
    drawSort(array.size(), elapsed);
}

void MainWindow::on_Heap_sort_clicked()
{

    // Очищаем содержимое textEdit перед добавлением новых данных
    ui->textEdit->clear();

    // Очищаем массив array перед добавлением новых данных
    array.clear();

    // Аналогично обработке кнопки Quick_sort
    QString text = ui->lineEdit->text();
    QStringList numbers = text.split(' ', Qt::SkipEmptyParts);

    for (const QString& number : numbers) {
        bool ok;
        int value = number.toInt(&ok);
        if (ok) {
            array.push_back(value);
        } else {
            QMessageBox::warning(this, "Ошибка", "Введите только целые числа!");
            return;
        }
    }
    QElapsedTimer timer;
    timer.start();
    sorter.heapSort(array);

    ui->textEdit->clear();
    QString sortedArrayText;
    for (int i = 0; i < array.size(); ++i) {
        sortedArrayText += QString::number(array[i]) + " ";
    }
    ui->textEdit->setText(sortedArrayText);

    qint64 elapsed = timer.nsecsElapsed() / 1000;
    ui->textEdit_2->setText("Время сортировки: " + QString::number(elapsed) + " мкс");

    double speed = static_cast<double>(array.size()) / elapsed;
    QString speedText = "Скорость сортировки: " + QString::number(speed, 'f', 2) + " элементов/мкс";
    ui->textEdit_2->append(speedText);

    drawSort(array.size(), elapsed);
}

void MainWindow::on_Merge_sort_clicked()
{


    // Очищаем содержимое textEdit перед добавлением новых данных
    ui->textEdit->clear();

    // Очищаем массив array перед добавлением новых данных
    array.clear();

    // Аналогично обработке кнопки Quick_sort
    QString text = ui->lineEdit->text();
    QStringList numbers = text.split(' ', Qt::SkipEmptyParts);

    for (const QString& number : numbers) {
        bool ok;
        int value = number.toInt(&ok);
        if (ok) {
            array.push_back(value);
        } else {
            QMessageBox::warning(this, "Ошибка", "Введите только целые числа!");
            return;
        }
    }
    QElapsedTimer timer;
    timer.start();
    sorter.mergeSort(array, 0, array.size() - 1);

    ui->textEdit->clear();
    QString sortedArrayText;
    for (int i = 0; i < array.size(); ++i) {
        sortedArrayText += QString::number(array[i]) + " ";
    }
    ui->textEdit->setText(sortedArrayText);

    qint64 elapsed = timer.nsecsElapsed() / 1000;
    ui->textEdit_2->setText("Время сортировки: " + QString::number(elapsed) + " мкс");

    double speed = static_cast<double>(array.size()) / elapsed;
    QString speedText = "Скорость сортировки: " + QString::number(speed, 'f', 2) + " элементов/мкс";
    ui->textEdit_2->append(speedText);

    drawSort(array.size(), elapsed);
}

void MainWindow::drawSort(int arraySize, qint64 elapsedTime)
{
    // Очищаем существующую сцену
    scene->clear();

    // Определяем размеры области отображения графика
    int plotWidth = ui->graphicsView->width();
    int plotHeight = ui->graphicsView->height();

    // Определяем максимальные значения по осям X и Y для графика
    int maxX = arraySize;
    qint64 maxY = elapsedTime;

    // Определяем максимальное количество точек, которые мы можем отобразить на графике
    int maxPoints = std::min(arraySize, plotWidth);

    // Рассчитываем шаг по оси X
    qreal stepX = plotWidth / maxPoints;

    // Отрисовываем график
    qreal xPrev = 0;
    qreal yPrev = plotHeight;
    for (int i = 1; i <= maxPoints; ++i) {
        qreal x = i * stepX;
        qreal y = plotHeight - (elapsedTime * plotHeight / maxY);
        QPen pen(Qt::blue);
        pen.setWidth(6);
        scene->addLine(xPrev, yPrev, x, y, pen);
        xPrev = x;
        yPrev = y;
    }
}

void MainWindow::on_Input_clicked()
{

    // Получаем число из lineEdit_2
    QString text = ui->lineEdit_2->text();
    int digit = text.toInt();

    // Ищем число в массиве
    int index = sorter.binarySearch(array, digit);

    // Выводим результат в textEdit_2
    if (index != -1)
        ui->textEdit_2->append("Число " + QString::number(digit) + " найдено в массиве по индексу " + QString::number(index));
    else
        ui->textEdit_2->append("Число " + QString::number(digit) + " не найдено в массиве");

     ui->lineEdit_2->clear();
}
