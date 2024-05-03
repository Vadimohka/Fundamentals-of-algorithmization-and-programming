#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    obgect = new hanoi;
    scene->addItem(obgect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Hanoi(int n, int i, int k) {
    if (n == 1) {
        ui->table->insertRow(kol_el_table);
        vect.resize(kol_el_table + 1);
        ui->table->setItem(kol_el_table, 0, new QTableWidgetItem(str.setNum(1)));
        vect[kol_el_table].namber_kol = 1;
        ui->table->setItem(kol_el_table, 1, new QTableWidgetItem(i == 1 ? "A" : (i == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_start = i;
        ui->table->setItem(kol_el_table, 2, new QTableWidgetItem(k == 1 ? "A" : (k == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_finish = k;
        kol_el_table++;
    }
    else {
        int tmp = 6 - i - k;
        Hanoi(n - 1, i, tmp);
        ui->table->insertRow(kol_el_table);
        vect.resize(kol_el_table + 1);
        ui->table->setItem(kol_el_table, 0, new QTableWidgetItem(str.setNum(n)));
        vect[kol_el_table].namber_kol = n;
        ui->table->setItem(kol_el_table, 1, new QTableWidgetItem(i == 1 ? "A" : (i == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_start = i;
        ui->table->setItem(kol_el_table, 2, new QTableWidgetItem(k == 1 ? "A" : (k == 2 ? "B" : "C")));
        vect[kol_el_table].namber_stolb_finish = k;
        kol_el_table++;
        Hanoi(n - 1, tmp, k);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::fun(){
    is_finish = obgect -> animate(kol_el_table - 1);
    ui->graphicsView->viewport()->update();
    if (is_finish){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(fun()));
        timer -> stop();
    }
}
void MainWindow::on_pushButton_clicked()
{
    if (n != 0)
    {
        obgect -> namber_vector = 0;
        Hanoi(n, 1, 2);
        obgect -> qvector_table(vect);
        connect(timer, SIGNAL(timeout()), this, SLOT(fun()));
        timer->start(10);
        ui -> stackedWidget -> setCurrentWidget(ui -> page_2);
    }
}

void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    QString str;
    n = ui -> spinBox -> value();
    if (n != 0){
        obgect -> otr_col(n);
    }
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    kol_el_table = 0;
    vect.clear();
    ui -> table -> clearContents();
    ui -> table -> setRowCount(0);
    ui -> stackedWidget -> setCurrentWidget(ui -> page);
    timer -> stop();
    obgect -> inis();
    obgect -> otr_col(n);
    ui->graphicsView->viewport()->update();
}

