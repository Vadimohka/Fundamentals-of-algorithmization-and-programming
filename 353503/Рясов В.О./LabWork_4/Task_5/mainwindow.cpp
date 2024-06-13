#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ConstComboBox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_comboBoxActivated);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_comboBox_2Activated);
    timer->start(SPEED_TIMER);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        && ui->spinBox->hasFocus()) {
        myVector.push_back(ui->spinBox->value());
        ui->vectorEdit->setText("");
        for (int i : myVector) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
    }

    else if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
             && ui->spinBox_2->hasFocus()) {
        myVector2.push_back(ui->spinBox_2->value());
        ui->vectorEdit_2->setText("");
        for (int i : myVector2) {
            ui->vectorEdit_2->setText(ui->vectorEdit_2->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_addButton_clicked()
{
    myVector.push_back(ui->spinBox->value());
    ui->vectorEdit->setText("");
    for (int i : myVector) {
        ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if (!myVector.empty()) {
        myVector.pop_back();
        ui->vectorEdit->setText("");
        for (int i : myVector) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_deleteAllButton_clicked()
{
    if (!myVector.empty()) {
        myVector.clear();
        ui->vectorEdit->setText("");
    }
}

void MainWindow::on_comboBoxActivated()
{
    if (ui->comboBox->currentIndex() == BACK_METHOD && !myVector.empty()) {
        ui->outputLabel->setText(QString::number(myVector.back()));
    }

    else if (ui->comboBox->currentIndex() == CAPACITY_METHOD) {
        ui->outputLabel->setText(QString::number(myVector.capacity()));
    }

    else if (ui->comboBox->currentIndex() == DATA_METHOD && !myVector.empty()) {
        ui->outputLabel->setText(
            QString::number(reinterpret_cast<quintptr>(myVector.data()), SYSTEM_16));
    }

    else if (ui->comboBox->currentIndex() == EMPTY_METHOD) {
        ui->outputLabel->setText((myVector.empty()) ? "True" : "False");
    }

    else if (ui->comboBox->currentIndex() == FRONT_METHOD && !myVector.empty()) {
        ui->outputLabel->setText(QString::number(myVector.front()));
    }

    else if (ui->comboBox->currentIndex() == MAX_SIZE_METHOD) {
        ui->outputLabel->setText(QString::number(myVector.max_size()));
    }

    else if (ui->comboBox->currentIndex() == SIZE_METHOD) {
        ui->outputLabel->setText(QString::number(myVector.size()));
    }
}

void MainWindow::on_comboBox_2Activated()
{
    if (ui->comboBox_2->currentIndex() == BACK_METHOD && !myVector2.empty()) {
        ui->outputLabel_2->setText(QString::number(myVector2.back()));
    }

    else if (ui->comboBox_2->currentIndex() == CAPACITY_METHOD) {
        ui->outputLabel_2->setText(QString::number(myVector2.capacity()));
    }

    else if (ui->comboBox_2->currentIndex() == DATA_METHOD && !myVector2.empty()) {
        ui->outputLabel_2->setText(
            QString::number(reinterpret_cast<quintptr>(myVector2.data()), SYSTEM_16));
    }

    else if (ui->comboBox_2->currentIndex() == EMPTY_METHOD) {
        ui->outputLabel_2->setText((myVector2.empty()) ? "True" : "False");
    }

    else if (ui->comboBox_2->currentIndex() == FRONT_METHOD && !myVector2.empty()) {
        ui->outputLabel_2->setText(QString::number(myVector2.front()));
    }

    else if (ui->comboBox_2->currentIndex() == MAX_SIZE_METHOD) {
        ui->outputLabel_2->setText(QString::number(myVector2.max_size()));
    }

    else if (ui->comboBox_2->currentIndex() == SIZE_METHOD) {
        ui->outputLabel_2->setText(QString::number(myVector2.size()));
    }
}

void MainWindow::on_addButton_2_clicked()
{
    myVector2.push_back(ui->spinBox_2->value());
    ui->vectorEdit_2->setText("");
    for (int i : myVector2) {
        ui->vectorEdit_2->setText(ui->vectorEdit_2->text() + QString::number(i) + " ");
    }
}

void MainWindow::on_deleteButton_2_clicked()
{
    if (!myVector.empty()) {
        myVector.pop_back();
        ui->vectorEdit->setText("");
        for (int i : myVector) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_deleteAllButton_2_clicked()
{
    if (!myVector2.empty()) {
        myVector2.clear();
        ui->vectorEdit_2->setText("");
    }
}

void MainWindow::on_comboBox_activated(int index)
{
    if (index == AT_METHOD) {
        ui->helpLabel->setText("Введите индекс в первый spinBox для получения значения");
    }

    if (index == EMPLACE_METHOD) {
        ui->helpLabel->setText("Введите в первый spinBox число для вставки и во второй spinBox "
                               "индекс на место которого будет вставлен элемент");
    }

    if (index == EMPLACE_BACK_METHOD) {
        ui->helpLabel->setText("Введите число в первый spinBox для вставки в конец вектора");
    }

    if (index == ERACE_METHOD) {
        ui->helpLabel->setText("Укажите диапазон индексов для удаления элементов из вектора");
    }

    if (index == INSERT_METHOD) {
        ui->helpLabel->setText("Введите в первый spinBox число для вставки и во второй spinBox "
                               "индекс на место которого будет вставлен элемент");
    }

    if (index == RESERVE_METHOD) {
        ui->helpLabel->setText("Введите в первый spinBox число для резервирования памяти");
    }

    if (index == RESIZE_METHOD) {
        ui->helpLabel->setText(
            "Введите в первый spinBox число для определения нового размера вектора");
    }

    if (index == SWAP_METHOD) {
        myVector.swap(myVector2);
        ui->vectorEdit->setText("");
        ui->vectorEdit_2->setText("");
        for (int i : myVector) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
        for (int i : myVector2) {
            ui->vectorEdit_2->setText(ui->vectorEdit_2->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_comboBox_2_activated(int index)
{
    if (index == AT_METHOD) {
        ui->helpLabel->setText("Введите индекс в первый spinBox для получения значения");
    }

    if (index == EMPLACE_METHOD) {
        ui->helpLabel->setText("Введите в первый spinBox число для вставки и во второй spinBox "
                               "индекс на место которого будет вставлен элемент");
    }

    if (index == EMPLACE_BACK_METHOD) {
        ui->helpLabel->setText("Введите число в первый spinBox для вставки в конец вектора");
    }

    if (index == ERACE_METHOD) {
        ui->helpLabel->setText("Укажите диапазон индексов для удаления элементов из вектора");
    }

    if (index == INSERT_METHOD) {
        ui->helpLabel->setText("Введите в первый spinBox число для вставки и во второй spinBox "
                               "индекс на место которого будет вставлен элемент");
    }

    if (index == RESERVE_METHOD) {
        ui->helpLabel->setText("Введите в первый spinBox число для резервирования памяти");
    }

    if (index == RESIZE_METHOD) {
        ui->helpLabel->setText(
            "Введите в первый spinBox число для определения нового размера вектора");
    }

    if (index == SWAP_METHOD) {
        myVector.swap(myVector2);
        ui->vectorEdit->setText("");
        ui->vectorEdit_2->setText("");
        for (int i : myVector) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
        for (int i : myVector2) {
            ui->vectorEdit_2->setText(ui->vectorEdit_2->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_helpButton_clicked()
{
    if (ui->comboBox->currentIndex() == AT_METHOD && ui->helpSpinBox->value() >= 0
        && ui->helpSpinBox->value() < static_cast<int>(myVector.size())) {
        ui->outputLabel->setText(QString::number(myVector.at(ui->helpSpinBox->value())));
    }

    if (ui->comboBox->currentIndex() == EMPLACE_METHOD && ui->helpSpinBox_2->value() >= 0
        && ui->helpSpinBox_2->value() <= static_cast<int>(myVector.size())) {
        myVector.insert(ui->helpSpinBox_2->value(), ui->helpSpinBox->value());
    }

    if (ui->comboBox->currentIndex() == EMPLACE_BACK_METHOD) {
        myVector.insert(myVector.size(), ui->helpSpinBox->value());
    }

    if (ui->comboBox->currentIndex() == ERACE_METHOD && ui->helpSpinBox_2->value() >= 0
        && ui->helpSpinBox_2->value() < static_cast<int>(myVector.size())
        && ui->helpSpinBox->value() >= 0
        && ui->helpSpinBox->value() <= static_cast<int>(myVector.size())
        && ui->helpSpinBox->value() <= ui->helpSpinBox_2->value() && !myVector.empty()) {
        myVector.erase(myVector.begin() + ui->helpSpinBox->value(),
                       myVector.begin() + ui->helpSpinBox_2->value() + 1);
    }

    if (ui->comboBox->currentIndex() == INSERT_METHOD && ui->helpSpinBox_2->value() >= 0
        && ui->helpSpinBox_2->value() <= static_cast<int>(myVector.size())) {
        myVector.insert(ui->helpSpinBox_2->value(), ui->helpSpinBox->value());
    }

    if (ui->comboBox->currentIndex() == RESERVE_METHOD && ui->helpSpinBox->value() >= 0) {
        myVector.reserve(ui->helpSpinBox->value());
    }

    if (ui->comboBox->currentIndex() == RESIZE_METHOD && ui->helpSpinBox->value() >= 0) {
        myVector.resize(ui->helpSpinBox->value());
    }

    ui->vectorEdit->setText("");
    for (int i : myVector) {
        ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
    }
}

void MainWindow::on_helpButton_2_clicked()
{
    if (ui->comboBox_2->currentIndex() == AT_METHOD && ui->helpSpinBox->value() >= 0
        && ui->helpSpinBox->value() < static_cast<int>(myVector2.size())) {
        ui->outputLabel_2->setText(QString::number(myVector2.at(ui->helpSpinBox->value())));
    }

    if (ui->comboBox_2->currentIndex() == EMPLACE_METHOD && ui->helpSpinBox_2->value() >= 0
        && ui->helpSpinBox_2->value() <= static_cast<int>(myVector2.size())) {
        myVector2.insert(ui->helpSpinBox_2->value(), ui->helpSpinBox->value());
    }

    if (ui->comboBox_2->currentIndex() == EMPLACE_BACK_METHOD) {
        myVector2.insert(myVector2.size(), ui->helpSpinBox->value());
    }

    if (ui->comboBox_2->currentIndex() == ERACE_METHOD && ui->helpSpinBox_2->value() >= 0
        && ui->helpSpinBox_2->value() < static_cast<int>(myVector2.size())
        && ui->helpSpinBox->value() >= 0
        && ui->helpSpinBox->value() <= static_cast<int>(myVector2.size())
        && ui->helpSpinBox->value() <= ui->helpSpinBox_2->value() && !myVector2.empty()) {
        myVector2.erase(myVector2.begin() + ui->helpSpinBox->value(),
                        myVector2.begin() + ui->helpSpinBox_2->value() + 1);
    }

    if (ui->comboBox_2->currentIndex() == INSERT_METHOD && ui->helpSpinBox_2->value() >= 0
        && ui->helpSpinBox_2->value() <= static_cast<int>(myVector2.size())) {
        myVector2.insert(ui->helpSpinBox_2->value(), ui->helpSpinBox->value());
    }

    if (ui->comboBox_2->currentIndex() == RESERVE_METHOD && ui->helpSpinBox->value() >= 0) {
        myVector2.reserve(ui->helpSpinBox->value());
    }

    if (ui->comboBox_2->currentIndex() == RESIZE_METHOD && ui->helpSpinBox->value() >= 0) {
        myVector2.resize(ui->helpSpinBox->value());
    }

    ui->vectorEdit_2->setText("");
    for (int i : myVector2) {
        ui->vectorEdit_2->setText(ui->vectorEdit_2->text() + QString::number(i) + " ");
    }
}
