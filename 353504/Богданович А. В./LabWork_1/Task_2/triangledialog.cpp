#include "triangledialog.h"
#include "ui_triangledialog.h"
#include "Triangle.h"

TriangleDialog::TriangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TriangleDialog)
{
    ui->setupUi(this);
}

TriangleDialog::~TriangleDialog()
{
    delete ui;
}

void TriangleDialog::on_buttonBox_accepted()
{
    QString a = ui->lineEdit->text();
    bool isOk;
    int b = a.toInt(&isOk);


    if (!isOk || b > 750 || b < 1) {
        b = 0;
    }
    emit sendTriangleSignals(b);
}

