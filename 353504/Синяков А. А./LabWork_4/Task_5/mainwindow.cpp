#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->textEdit->setAlignment(Qt::AlignCenter);
    for (int i = 1; i <= 7; ++i) {
        vec.push_back(i);
    }
    ui->textEdit->append("Данн вектор: ");
    QString vectorContent = "Содержимое вектора: ";
    for (size_t i = 0; i < vec.Size(); ++i) {
        vectorContent += QString::number(vec[i]) + " ";
    }
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append(vectorContent);
    ui->textEdit->append("");

    QString styleSheet = R"(


    QComboBox {
        background-color: black; /* Синий цвет */
    text-align: center;
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

    QComboBox:hover {
        background-color: #0056b3; /* Темно-синий цвет при наведении */
    }


)";
    this->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::displayMatrices()
{
    QString output;
    int matrixIndex = 1;
    for (auto& pair : vecOfPairs) {
        const auto& matrix1 = pair.first;
        const auto& matrix2 = pair.second;

        // Заголовок для первой матрицы
        output += "Matrix " + QString::number(matrixIndex) + " (Dvector<int>):\n";

        // Отображаем первую матрицу
        for (size_t i = 0; i < matrix1.Size(); ++i) {
            if (i < matrix1.Size()) {
                output += QString::number(matrix1[i]) + "\t";
            }
        }
        output += "\n";

        // Заголовок для второй матрицы
        output += "Matrix " + QString::number(matrixIndex) + " (Dvector<MyPair<int, double>>):\n";

        // Отображаем вторую матрицу
        for (size_t i = 0; i < matrix2.Size(); ++i) {
            if (i < matrix2.Size()) {
                output += QString::number(matrix2[i].first) + ", " + QString::number(matrix2[i].second) + "\t";
            }
        }
        output += "\n\n";

        matrixIndex++;
    }

    // Выводим матрицы в QTextEdit
    ui->textEdit->setText(output);
}



void MainWindow::createMatrices()
{
    // Очищаем контейнер и создаем новые матрицы для демонстрации
    vecOfPairs.clear();

    // Создаем новые матрицы для демонстрации
    Dvector<int> matrix5; // Матрица размером 3x1
    matrix5.emplace_back(7);
    matrix5.emplace_back(8);
    matrix5.emplace_back(9);

    Dvector<MyPair<int, double>> matrix6; // Матрица размером 2x1
    matrix6.emplace_back(MyPair<int, double>(5, 5.5));
    matrix6.emplace_back(MyPair<int, double>(6, 6.6));

    // Добавляем новые матрицы в контейнер
    vecOfPairs.push_back(MyPair<Dvector<int>, Dvector<MyPair<int, double>>>(matrix5, matrix6));

    Dvector<int> matrix7; // Матрица размером 3x1
    matrix7.emplace_back(10);
    matrix7.emplace_back(11);
    matrix7.emplace_back(12);

    Dvector<MyPair<int, double>> matrix8; // Матрица размером 2x1
    matrix8.emplace_back(MyPair<int, double>(7, 7.7));
    matrix8.emplace_back(MyPair<int, double>(8, 8.8));

    vecOfPairs.push_back(MyPair<Dvector<int>, Dvector<MyPair<int, double>>>(matrix7, matrix8));

    // Отображаем новые матрицы в окне
    displayMatrices();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == ui->comboBox->findText("Сhecking methods")) {
        // Вызываем функцию для создания матриц
        Сheckingmethods();
    }
    if (index == ui->comboBox->findText("Creatematrixs")) {
        // Вызываем функцию для создания матриц
        createMatrices();
    }
    if (index == ui->comboBox->findText("emplace")) {
        // Вызываем функцию для создания матриц
        create_emplace();
    }
    if (index == ui->comboBox->findText("assign")) {
        // Вызываем функцию для создания матриц
        createassign();
    }
    if (index == ui->comboBox->findText("back")) {
        // Вызываем функцию для создания матриц
        createback();
    }
    if (index == ui->comboBox->findText("emplace_back")) {
        // Вызываем функцию для создания матриц
        create_emplace_back();
    }
    if (index == ui->comboBox->findText("data")) {
        // Вызываем функцию для создания матриц
        createdata();
    }
    if (index == ui->comboBox->findText("front")) {
        // Вызываем функцию для создания матриц
        createfront();
    }
    if (index == ui->comboBox->findText("insert")) {
        // Вызываем функцию для создания матриц
        createinsert();
    }
    if (index == ui->comboBox->findText("clear")) {
        // Вызываем функцию для создания матриц
        createclear();
    }

}

void MainWindow::Сheckingmethods()
{
    ui->textEdit->clear();

}

void MainWindow::create_emplace()
{
    ui->textEdit->append("Вызван метод create_emplace(): ");
    // Пример использования метода emplace
    vec.emplace_back(3);  // Вставляем элемент в конец вектора
    // Выводим значение добавленного элемента в textEdit
    ui->textEdit->append("Добавленный элемент: " + QString::number(vec.back()));
    // Собираем содержимое вектора в одну строку
    QString vectorContent = "Содержимое вектора: ";
    for (size_t i = 0; i < vec.Size(); ++i) {
        vectorContent += QString::number(vec[i]) + " ";
    }
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append(vectorContent);
    ui->textEdit->append("");
}

void MainWindow::createassign()
{
    ui->textEdit->append("Вызван метод createassign(): ");
    // Пример использования метода assign
    vec.assign(5, 10);  // Заполняем вектор 5 элементами со значением 10
    // Выводим значения элементов вектора в textEdit
    ui->textEdit->append("Присвоенные элементы:");
    for (int i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    ui->textEdit->append("");
}

void MainWindow::createback()
{
    ui->textEdit->append("Вызван метод createback(): ");
    // Пример использования метода back
    vec.push_back(10);
    int lastElement = vec.back();  // Получаем последний элемент вектора
    // Выводим значение последнего элемента в textEdit
    ui->textEdit->append("Последний элемент: " + QString::number(lastElement));
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append("Содержимое вектора:");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    ui->textEdit->append("");
}

void MainWindow::create_emplace_back()
{

    ui->textEdit->append("Вызван метод create_emplace_back(): ");
    // Пример использования метода emplace_back
    vec.emplace_back(10);  // Вставляем элемент в конец вектора
    // Выводим значение добавленного элемента в textEdit
    ui->textEdit->append("Добавленный элемент: " + QString::number(vec.back()));
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append("Содержимое вектора:");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    ui->textEdit->append("");
}

void MainWindow::createdata()
{
    // Пример использования метода data
    ui->textEdit->append("Вызван метод createdata(): ");
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append("Содержимое вектора: ");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    vec.push_back(10);
    int *pData = vec.data();  // Получаем указатель на данные вектора
    // Выводим значения элементов вектора в textEdit, используя указатель pData
    ui->textEdit->append("Элементы через data:");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(pData[i]));
    }
    ui->textEdit->append("");
}

void MainWindow::createfront()
{
    ui->textEdit->append("Вызван метод createfront(): ");
    // Пример использования метода front
    vec.push_back(10);
    int firstElement = vec.front();  // Получаем первый элемент вектора
    // Выводим значение первого элемента в textEdit
    ui->textEdit->append("Первый элемент: " + QString::number(firstElement));
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append("Содержимое вектора:");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    ui->textEdit->append("");
}

void MainWindow::createclear()
{
    // Пример использования метода clear
    ui->textEdit->append("Вызван метод createclear(): ");
    // Выводим содержимое вектора в textEdit
    ui->textEdit->append("Содержимое вектора:");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    vec.push_back(10);
    vec.clear();  // Очищаем вектор
    // Выводим информацию о том, что вектор очищен, в textEdit
    ui->textEdit->append("Вектор очищен");
    ui->textEdit->append("");
}

void MainWindow::createinsert()
{
    ui->textEdit->append("Вызван метод createinsert(): ");
    // Пример использования метода insert
    vec.insert(0, 5);  // Вставляем элемент со значением 5 на позицию 0
    // Выводим значения элементов вектора в textEdit
    ui->textEdit->append("Вектор после вставки:");
    for (size_t i = 0; i < vec.Size(); ++i) {
        ui->textEdit->append(QString::number(vec[i]));
    }
    ui->textEdit->append("");
}














