#include "mainwindow.h"         //вар 8
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    solve = new Solve(ui);
    solve->solve_problem();

}
void MainWindow::fullfilltables(){



}
MainWindow::~MainWindow()
{
    delete ui;
}
