#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->numberSpinBox, SIGNAL(valueChanged(double)), SLOT(slotShowResult()));
    connect(ui->precisionSpinBox, SIGNAL(valueChanged(int)), SLOT(slotShowResult()));

    ui->numberSpinBox->setMaximum(MAX_DEC);
    ui->numberSpinBox->setMinimum(-1 * MAX_DEC);
    ui->precisionSpinBox->setMaximum(MAX_PRE);

    slotShowResult();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShowResult()
{
    ui->resultLabel->setText(Translator::TranslateFDecTBin(
        ui->numberSpinBox->value(),
        ui->precisionSpinBox->value()));
}
