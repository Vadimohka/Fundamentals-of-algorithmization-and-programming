#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleSheet = R"(

)";
    this->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findMedians(const std::vector<int> &a)
{
    std::vector<int> b;

    // Размер вектора a
    int size = a.size();

    // Проходимся по вектору a с шагом 3
    for (int i = 0; i < size; i += 3) {
        // Создаем временный вектор для хранения текущей тройки элементов
        std::vector<int> temp;

        // Добавляем элементы текущей тройки во временный вектор
        for (int j = i; j < std::min(size, i + 3); ++j) {
            temp.push_back(a[j]);
        }

        // Сортируем временный вектор
        std::sort(temp.begin(), temp.end());

        // Выбираем медианный элемент или вычисляем среднее значение для неполных троек
        if (temp.size() == 3) {
            b.push_back(temp[1]); // Медианный элемент
        } else {
            // Вычисляем среднее значение
            int average = (temp[0] + temp[1]) / 2;
            b.push_back(average);
        }
    }
    QString arrayStr = "Массив: ";
    for (int num : b) {
        arrayStr += QString::number(num) + " ";
    }
    ui->textEdit->append(arrayStr);
}




void MainWindow::on_Sort_Medians_clicked()
{

    ui->textEdit->clear();
    QString text = ui->lineEdit->text();
    QStringList numbers = text.split(' ', Qt::SkipEmptyParts);

    // Проверка и преобразование строк в целые числа
    std::vector<int> array;
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
    findMedians(array);

}
