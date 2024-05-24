#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set title of the window
    setWindowTitle("Decimal to Binary Converter");

    ui->binary_edit->setReadOnly(true);
    connect(ui->decimal_edit, SIGNAL(textChanged(const QString &)), this, SLOT(ShowBinaryNum(const QString &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowBinaryNum(QString input)
{
    if (input.isEmpty())
    {
        ui->binary_edit->clear();
        return;
    }

    bool flag = false;
    double decimNumber = input.toDouble(&flag);

    if (flag && !(input[0] == '0' && input.size() > 1) && input[0] != '-')
    {
        int integerPart = static_cast<int>(decimNumber);
        QString integerBinary = ConvertIntegerPart(integerPart);

        double fractionalPart = decimNumber - integerPart;
        QString fractionalBinary = ConvertFractionalPart(fractionalPart);

        if (fractionalBinary.isEmpty())
        {
            ui->binary_edit->setText(integerBinary);
        } else {
            ui->binary_edit->setText(integerBinary + "." + fractionalBinary);
        }

    } else {
        ui->binary_edit->setText("Incorrect input!");
    }
}

QString MainWindow::ConvertIntegerPart(long long decimNumber)
{
    if (decimNumber == 0)
    {
        return "";
    } else {
        return ConvertIntegerPart(decimNumber / 2) + QString::number(decimNumber % 2);
    }
}

QString MainWindow::ConvertFractionalPart(double fracPart)
{
    if (fracPart >= 1.0 || fracPart == 0.0)
    {
        return "";
    } else {
        double fractionalPart = fracPart * 2;
        int integerPart = static_cast<int>(fractionalPart);
        return QString::number(integerPart) + ConvertFractionalPart(fractionalPart - integerPart);
    }
}


