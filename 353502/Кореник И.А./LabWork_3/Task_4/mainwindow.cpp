#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    n = -1;
    current = 0;
    setUpTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpTable()
{
    ui->tableWidget->setColumnCount(2); // Указываем число колонок
   // ui->tableWidget->setRowCount(3);
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
   // ui->tableWidget->setHorizontalHeaderLabels(headers);
    // Растягиваем последнюю колонку на всё доступное пространство
  //  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
    ui->tableWidget->hideColumn(0);
}

void MainWindow::Move(QString* move)
{
    int i = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(i);
    QString str = *move;
    str.insert(1, " -> ");
    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str));
}

void MainWindow::on_accept_clicked()
{
    if (check){
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        n = ui->NValue->text().toInt();
        solve = new Hanoi(n);
    }
    check = false;
}


void MainWindow::on_All_clicked()
{
    if (!check)
        for (int i = current; i < solve->movements.size(); i++){
          Move(solve->movements[i]);
        }
    check = true;
}


void MainWindow::on_One_clicked()
{
    if (!check){

        Move(solve->movements[current]);
        current++;
       }
    if (current + 1 == 1 << n)
    check = true;
}

