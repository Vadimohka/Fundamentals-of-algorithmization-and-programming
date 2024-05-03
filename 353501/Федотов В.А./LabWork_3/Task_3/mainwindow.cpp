#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <qlineedit.h>
#include <qregularexpression.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // setFixedSize(200, 85);

    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[1-9]{0,19}"), this);
    ui->inputLineEdit->setValidator(validator);
    connect(ui->calculateButton, &QPushButton::clicked, this,&MainWindow::reverseInput);
}

void MainWindow::reverseInput() {
    unsigned long long value = ui->inputLineEdit->text().toULongLong();
    unsigned long long output = Reverser::reverse(value);
    ui->resLineEdit->setText(QString::number(output));
}
