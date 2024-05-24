#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleSheet = R"(


    QPushButton {
        background-color: #007BFF; /* Синий цвет */
        border: none;
        color: #FFFFFF;

    }
QTextEdit {
    background-color: #2E2E4F;

}
QListWidget {
    background-color: #0D1B2A; /* Темно-синий цвет, напоминающий глубины космоса */

}

/* Стиль для главного окна */
MainWindow {
    background-color: #040F1A; /* Еще более темный оттенок синего, похожий на бесконечную глубину космоса */
}
QLineEdit {
    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,
                                 stop: 0 #0D1B2A, stop: 1 #050A30); /* Градиент от #0D1B2A до #050A30 */
    border: 1px solid #2E2E4F; /* Фиолетовая рамка */
    color: white; /* Белый текст для контраста */
}

    QPushButton:hover {
        background-color: #0056b3; /* Темно-синий цвет при наведении */
    }


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

