#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qline.h>
#include <qlineedit.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->lineEdit_1, &QLineEdit::textChanged, this, &MainWindow::updateLabels);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &MainWindow::updateLabels);
    updateLabels(ui->lineEdit_1->text());
    updateLabels(ui->lineEdit_2->text());
}

void MainWindow::updateLabels(QString qstring){
    s1 = ui->lineEdit_1->text().toLatin1().data();
    s2 = ui->lineEdit_2->text().toLatin1().data();

    ui->s1value->setText(s1.getData());
    ui->s2value->setText(s2.getData());
    ui->strlen1->setText(QString::number(s1.length()));
    ui->strlen2->setText(QString::number(s2.length()));
    ui->strcat1->setText(QString::fromUtf8((s1 + s2).getData()));
    ui->strcat2->setText(QString::fromUtf8((s2 + s1).getData()));
    ui->strcmp1->setText(QString::number(s1.compare(s2)));
    ui->strcmp2->setText(QString::number(s2.compare(s1)));
}
