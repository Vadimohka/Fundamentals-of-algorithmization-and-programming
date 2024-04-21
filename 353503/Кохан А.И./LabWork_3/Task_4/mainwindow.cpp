#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

constexpr short GOOD_NUMBER = 20;
const short FIRST_NUMBER_COLUMN = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(FIRST_NUMBER_COLUMN, QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::towerOfHanoi(int count, char fromPiramid, char toPiramid, char auxPiramid)
{
    if(count == 0)
    {
        return;
    }

    towerOfHanoi(count - 1, fromPiramid, auxPiramid, toPiramid);
    auto *newItem = new QTableWidgetItem("Move ring " + QString::number(count) + " from " + QString::fromLatin1(&fromPiramid, 1)
                                         + " to piramid "+ QString::fromLatin1(&toPiramid, 1));
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, newItem);
    towerOfHanoi(count - 1, auxPiramid, toPiramid, fromPiramid);
}

void MainWindow::on_answerButton_clicked()
{
    if(ui->countRingsSpinBox->value() > GOOD_NUMBER)
    {
        auto answerMessange = QMessageBox::question(this, "Внимание!", "Вы действительно хотите выбрать это число? Расчёты будут проводиться долго и вы"
                                                                      " вероятно не дождётесь ожидаемого результата.", "Да", "Нет");

        if(answerMessange == 0)
        {
            ui->tableWidget->setRowCount(0);
            towerOfHanoi(ui->countRingsSpinBox->value(), 'A', 'C', 'B');
        }
    }

    else
    {
        ui->tableWidget->setRowCount(0);
        towerOfHanoi(ui->countRingsSpinBox->value(), 'A', 'C', 'B');
    }
}

