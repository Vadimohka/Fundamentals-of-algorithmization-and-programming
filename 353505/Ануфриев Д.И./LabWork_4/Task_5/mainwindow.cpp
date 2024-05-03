#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableIter->resizeColumnsToContents();
    ui->tableIter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->matrix->resizeColumnsToContents();
    ui->matrix->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //Mvector<pair<int, double>>>

    int size = rand() % 190 + 10;

    ui->matrix->setRowCount(size);

    for(int i = 0; i < size; i++)
    {
        headPair.second.push_back(pair(rand() % 1000 - 500, (rand() % 1000 - 500) / 2.34));
    }

    updateMatrix();


    for(int i = 0; i < rand() % 190 + 10; i++)
    {
        headPair.first.push_back(rand() % 1000 - 500);
    }

    updateListWidget();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateListWidget()
{
    ui->listWidget->clear();

    for(int i = 0; i < headPair.first.size(); i++)
    {
        ui->listWidget->addItem(QString::number(headPair.first[i]));
    }

    ui->lineCapacity->setText(QString::number(headPair.first.capacity()));
    ui->lineMaxSize->setText(QString::number(headPair.first.max_size()));
    ui->lineSize->setText(QString::number(headPair.first.size()));

    ui->tableIter->setItem(0, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(*headPair.first.begin()) : "Error"));
    ui->tableIter->setItem(1, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(*headPair.first.end()) : "Error"));
    ui->tableIter->setItem(2, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(*headPair.first.cbegin()) : "Error"));
    ui->tableIter->setItem(3, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(*headPair.first.cend()) : "Error"));
    ui->tableIter->setItem(4, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(*headPair.first.rbegin()) : "Error"));
    ui->tableIter->setItem(5, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(*headPair.first.rend()) : "Error"));
    ui->tableIter->setItem(6, 0, new QTableWidgetItem(headPair.first.empty() ? "True" : "False"));
    ui->tableIter->setItem(7, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(headPair.first.front()) : "Error"));
    ui->tableIter->setItem(8, 0, new QTableWidgetItem(!headPair.first.empty() ? QString::number(headPair.first.back()) : "Error"));
    ui->tableIter->setItem(9, 0, new QTableWidgetItem(QString("0x%1").arg(reinterpret_cast<quintptr>(headPair.first.data()), 0, 16)));

    ui->tableIter->resizeColumnsToContents();
}

void MainWindow::updateMatrix()
{
    ui->matrix->clear();
    ui->matrix->verticalHeader()->setVisible(false);

    ui->matrix->setHorizontalHeaderItem(0, new QTableWidgetItem("int"));
    ui->matrix->setHorizontalHeaderItem(1, new QTableWidgetItem("double"));

    for(int i = 0; i < ui->matrix->rowCount(); i++)
    {
        ui->matrix->setItem(i, 0, new QTableWidgetItem(QString::number(headPair.second[i].first)));
        ui->matrix->setItem(i, 1, new QTableWidgetItem(QString::number(headPair.second[i].second)));
    }

    ui->matrix->resizeColumnsToContents();
}

void MainWindow::on_buttonClear_clicked()
{
    headPair.first.clear();
    updateListWidget();
}


void MainWindow::on_buttonPopBack_clicked()
{
    if(headPair.first.empty()) QMessageBox::warning(this, "Ошибка", "Вектор пустой!");
    else
    {
        headPair.first.pop_back();
        updateListWidget();
    }
}

void MainWindow::on_buttonPushBack_clicked()
{
    DialogInputPushBack* dialog = new DialogInputPushBack();

    int value;

    connect(dialog, &DialogInputPushBack::accepted, [&value, dialog, this](){
        value = dialog->getValue();
        headPair.first.push_back(value);
        updateListWidget();
    });

    dialog->exec();
}


void MainWindow::on_buttonAt_clicked()
{
    DialogInputPushBack* dialog = new DialogInputPushBack();

    if(headPair.first.empty()) QMessageBox::warning(this, "Ошибка", "Вектор пустой!");

    else
    {
        dialog->setRange(0, headPair.first.size() - 1);

        int value;

        connect(dialog, &DialogInputPushBack::accepted, [&value, dialog, this](){
            value = dialog->getValue();
            QMessageBox::information(this, "Ссылка на элемент",
                                     "Значение элемента на\nданной позиции: " + QString::number(headPair.first.at(value)));
        });

        dialog->exec();
    }
}


void MainWindow::on_buttonReserve_clicked()
{
    DialogInputPushBack* dialog = new DialogInputPushBack();

        int value;

        dialog->setRange(0, 1000);

        connect(dialog, &DialogInputPushBack::accepted, [&value, dialog, this](){
            value = dialog->getValue();

            headPair.first.reserve(value);

            updateListWidget();
        });

        dialog->setValue(headPair.first.capacity());

        dialog->exec();
}


void MainWindow::on_buttonResize_clicked()
{
    DialogInputPushBack* dialog = new DialogInputPushBack();
        int value;

        dialog->setRange(0, 1000);

        connect(dialog, &DialogInputPushBack::accepted, [&value, dialog, this](){
            value = dialog->getValue();

            headPair.first.resize(value);

            updateListWidget();
        });

        dialog->setValue(headPair.first.size());

        dialog->exec();
}

