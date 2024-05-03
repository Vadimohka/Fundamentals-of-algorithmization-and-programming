#include "mainwindow.h"
#include <QLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* verticalLayout = new QVBoxLayout(centralWidget);

    leftOperandLineEdit = new QLineEdit(centralWidget);
    verticalLayout->addWidget(leftOperandLineEdit);

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    operationComboBox = new QComboBox(centralWidget);
    operationComboBox->addItem("+");
    operationComboBox->addItem("-");
    operationComboBox->addItem("*");
    operationComboBox->addItem("/");
    horizontalLayout->addWidget(operationComboBox);

    rightOperandLineEdit = new QLineEdit(centralWidget);
    horizontalLayout->addWidget(rightOperandLineEdit);

    verticalLayout->addLayout(horizontalLayout);

    calculateButton = new QPushButton("Calculate", centralWidget);
    verticalLayout->addWidget(calculateButton);

    resultLabel = new QLabel("Result: ", centralWidget);
    verticalLayout->addWidget(resultLabel);

    setCentralWidget(centralWidget);
}

void MainWindow::calculate()
{
    QString leftOperandStr = leftOperandLineEdit->text();
    QString rightOperandStr = rightOperandLineEdit->text();
    QString operation = operationComboBox->currentText();

    bool leftOperandConversionOk, rightOperandConversionOk;
    double leftOperand = leftOperandStr.toDouble(&leftOperandConversionOk);
    double rightOperand = rightOperandStr.toDouble(&rightOperandConversionOk);

    if (!leftOperandConversionOk || !rightOperandConversionOk)
    {
        resultLabel->setText("Invalid input");
        return;
    }

    double result;
    if (operation == "+")
    {
        result = leftOperand + rightOperand;
    }
    else if (operation == "-")
    {
        result = leftOperand - rightOperand;
    }
    else if (operation == "*")
    {
        result = leftOperand * rightOperand;
    }
    else if (operation == "/")
    {
        if (rightOperand == 0)
        {
            resultLabel->setText("Division by zero");
            return;
        }
        result = leftOperand / rightOperand;
    }
    else
    {
        resultLabel->setText("Invalid operation");
        return;
    }

    resultLabel->setText("Result: " + QString::number(result));
}
