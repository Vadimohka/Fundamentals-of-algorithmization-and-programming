#include "mainwindow.h"
#include "expression.h"
#include "binaryoperation.h"
#include "number.h"

#include <QVBoxLayout>
#include <QString>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      inputLineEdit(new QLineEdit(this)),
      evaluateButton(new QPushButton("Evaluate", this)),
      resultLabel(new QLabel(this)) {
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(inputLineEdit);
    layout->addWidget(evaluateButton);
    layout->addWidget(resultLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(evaluateButton, &QPushButton::clicked, this, &MainWindow::onEvaluateButtonClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::onEvaluateButtonClicked() {
    QString input = inputLineEdit->text();

    // Пример: простой разбор выражения, предполагая, что оно вида "число операция число"
    QRegularExpression regex("(-?\\d+(?:\\.\\d+)?)([\\+\\-\\*/])(-?\\d+(?:\\.\\d+)?)");
    QRegularExpressionMatch match = regex.match(input);

    if (match.hasMatch()) {
        QStringList parts = match.capturedTexts();
        double leftValue = parts[1].toDouble();
        QChar operation = parts[2][0];
        double rightValue = parts[3].toDouble();

        Expression *left = new Number(leftValue);
        Expression *right = new Number(rightValue);
        Expression *expr = new BinaryOperation(left, operation.toLatin1(), right);

        double result = expr->evaluate();
        resultLabel->setText("Result: " + QString::number(result));

        delete expr;
    } else {
        QMessageBox::warning(this, "Invalid input", "Please enter a valid expression like '3+4.5' or '10-2.5'");
    }
}
