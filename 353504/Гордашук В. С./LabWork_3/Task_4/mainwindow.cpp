#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9]"),this));
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->label->setWordWrap(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_move_clicked()
{
    ui->set->setEnabled(false);
    ui->move->setEnabled(false);
    for (int i = 0; i < steps; ++i)
    {
        ui->tableWidget->selectRow(i);
        int from = hanoiTower->from[i];
        int to = hanoiTower->to[i];
        if (from == 1)
        {
            if (to == 2)
            {
                rings.at(tower1.back())->moveTo2(tower2.size());
                tower2.push_back(tower1.back());
                }
                else if (to == 3)
                {
                    rings.at(tower1.back())->moveTo3(tower3.size());
                    tower3.push_back(tower1.back());
                }
                tower1.pop_back();
            }
            else if (from == 2)
            {
                if (to == 1)
                {
                    rings.at(tower2.back())->moveTo1(tower1.size());
                    tower1.push_back(tower2.back());
                }
                else if (to == 3)
                {
                    rings.at(tower2.back())->moveTo3(tower3.size());
                    tower3.push_back(tower2.back());
                }
                tower2.pop_back();
            }
            else if (from == 3)
            {
                if (to == 1)
                {
                    rings.at(tower3.back())->moveTo1(tower1.size());
                    tower1.push_back(tower3.back());
                }
                else if (to == 2)
                {
                    rings.at(tower3.back())->moveTo2(tower2.size());
                    tower2.push_back(tower3.back());
                }
            tower3.pop_back();
            }
        QEventLoop loop;
        QTimer::singleShot(2000, &loop, SLOT(quit()));
        loop.exec();
    }
    ui->set->setEnabled(true);

}


void MainWindow::on_set_clicked()
{

    if (ui->input->text().isEmpty())
    {
        ui->label->setText("Неверный ввод");
    }
    else
    {
        ui->move->setEnabled(true);
        rings.clear();
        tower1.clear();
        tower2.clear();
        tower3.clear();
        ui->label->clear();
        scene->clear();
        n = ui->input->text().toInt();
        if (hanoiTower != nullptr)
        {
            hanoiTower = nullptr;
        }
        hanoiTower = new HanoiTower(n);
        hanoiTower->hanoi(n, 1, 2, 3);
        scene->addItem(hanoiTower);
        steps = pow(2, n) - 1;
        ui->tableWidget->setRowCount(steps);
        for (int i = 0; i < steps; ++i)
        {
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(hanoiTower->to[i])));
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(hanoiTower->from[i])));
        }
        for (int i = 0; i < n; ++i)
        {
            rings.push_back(new Ring(-210 + 5 * i, 180 - 20 * i, 140 - 10 * i, 20, i));
            scene->addItem(rings[i]);
            tower1.push_back(i);
        }
    }
}
