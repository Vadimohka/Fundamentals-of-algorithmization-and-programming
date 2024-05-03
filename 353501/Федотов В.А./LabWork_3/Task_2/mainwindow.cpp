#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdint>
#include <exception>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qpushbutton.h>
#include <stdexcept>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(220, 210);

    ui->resFrame->setStyleSheet("");
    connect(ui->calculateButton, &QPushButton::pressed, this, &MainWindow::calculateRes);
}

void MainWindow::calculateRes() {
    
    int m_Int = ui->m_SpinBox->value();
    int n_Int = ui->n_SpinBox->value();

    try {
        ui->resLabel->setText(QString::number(Ackermann::calculate(m_Int, n_Int)));
    } catch (...) {
        ui->resLabel->setText("Error");
        qDebug() << "out of range";
    }
}