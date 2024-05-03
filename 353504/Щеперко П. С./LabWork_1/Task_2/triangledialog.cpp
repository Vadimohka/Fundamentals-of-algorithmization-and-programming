#include "triangledialog.h"
#include "ui_triangledialog.h"

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
    bool isCorrect;
    int b = a.toInt(&isCorrect);


    if (!isCorrect || b > 700 || b < 1) {
        b = 0;
    }
    emit sendTriangleSignals(b);
}

