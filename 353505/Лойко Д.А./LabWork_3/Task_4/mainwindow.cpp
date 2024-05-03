#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(slotUpdateResult()));
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(MAX_PARTS_NUM);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotUpdateResult()
{
    tower.hanoi(ui->spinBox->value(),
          'A', 'C', 'B',
          solution_);

    if (solution_.at(0) == '-')
    {
        QMessageBox::critical(nullptr, "Stack Overflow", "The stack is on the verge of overflowing with "
                                                             + QString::number(tower.maxRinningFunc())
                                                             + " functions already on it. The computation process has been halted to prevent overflow.");
        solution_.clear();
    }

    ui->textEdit->setText(solution_);
    solution_.clear();
}
