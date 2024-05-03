#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "number.h"
#include "binaryoperation.h"

    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(calculateExpression()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateExpression()
{

    double leftOperand = ui->leftOperandLineEdit->text().toDouble();
    double rightOperand = ui->rightOperandLineEdit->text().toDouble();
    char operation = ui->operationComboBox->currentText().toStdString()[0];

    Expression* leftExpr = new Number(leftOperand);
    Expression* rightExpr = new Number(rightOperand);
    Expression* expr = new BinaryOperation(leftExpr, operation, rightExpr);

    double result = expr->evaluate();
    ui->resultLabel->setText(QString::number(result));

    delete expr;
}
