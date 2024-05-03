#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "decimaltobinary.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем экземпляр класса DecimalToBinary
    converter = new DecimalToBinary(this);

    // Подключаем сигнал binaryResult к слоту onBinaryResult
    connect(converter, &DecimalToBinary::binaryResult, this, &MainWindow::onBinaryResult);

    // Подключаем сигнал нажатия кнопки к слоту для выполнения преобразования
    connect(ui->calculation, &QPushButton::clicked, this, &MainWindow::performConversion);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBinaryResult(const QString& binary)
{
    // Обновляем метку в пользовательском интерфейсе с преобразованным результатом
    ui->answer->setText(binary);
}

void MainWindow::performConversion()
{
    // Получаем значение из поля ввода
    QString decimalNumber = ui->lineEdit->text();

    // Выполняем преобразование
    QString binaryRepresentation = converter->convert(decimalNumber);

    // Отправляем преобразованный результат
    emit converter->binaryResult(binaryRepresentation);
}
