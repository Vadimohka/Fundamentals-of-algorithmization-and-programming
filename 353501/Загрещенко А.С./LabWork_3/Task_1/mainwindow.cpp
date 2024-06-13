#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  
 
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::OnConvertButtonClicked);
  connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::OnConvertButtonClicked);
}


void MainWindow::OnConvertButtonClicked() {
    
    QString a = ui->lineEdit->text();
    bool ok;
    long double val = static_cast<long double>(a.toDouble(&ok));
    if(!ok){
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    ui->label->setText(Converter::ToIEEE(val));
}
