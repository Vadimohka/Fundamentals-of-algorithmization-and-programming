#include "mainwindow.h"
#include "expression.h"
#include "number.h"
#include "binaryoperation.h"
#include <QVBoxLayout>
#include <QString>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      inputLineEdit1(new QLineEdit(this)),
      inputLineEdit2(new QLineEdit(this)),
      evaluateButton(new QPushButton("Check Equals", this)),
      resultLabel(new QLabel(this)) {
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("Expression 1:", this));
    layout->addWidget(inputLineEdit1);
    layout->addWidget(new QLabel("Expression 2:", this));
    layout->addWidget(inputLineEdit2);
    layout->addWidget(evaluateButton);
    layout->addWidget(resultLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(evaluateButton, &QPushButton::clicked, this, &MainWindow::onEvaluateButtonClicked);
}

MainWindow::~MainWindow() {}

Expression* parseExpression(const QString& input) {
    QRegularExpression regex("(-?\\d+(?:\\.\\d+)?)([\\+\\-\\*/])(-?\\d+(?:\\.\\d+)?)");
    QRegularExpressionMatch match = regex.match(input);

    if (match.hasMatch()) {
        QStringList parts = match.capturedTexts();
        double leftValue = parts[1].toDouble();
        QChar operation = parts[2][0];
        double rightValue = parts[3].toDouble();

        Expression* left = new Number(leftValue);
        Expression* right = new Number(rightValue);
        return new BinaryOperation(left, operation.toLatin1(), right);
    }

    bool ok;
    double value = input.toDouble(&ok);
    if (ok) {
        return new Number(value);
    }

    return nullptr;
}

void MainWindow::onEvaluateButtonClicked() {
    QString input1 = inputLineEdit1->text();
    QString input2 = inputLineEdit2->text();

    Expression* expr1 = parseExpression(input1);
    Expression* expr2 = parseExpression(input2);

    if (expr1 && expr2) {
        bool areEqual = check_equals(expr1, expr2);
        resultLabel->setText(QString("Are equal: %1").arg(areEqual ? "true" : "false"));
    } else {
        QMessageBox::warning(this, "Invalid input", "Please enter valid expressions.");
    }

    delete expr1;
    delete expr2;
}
