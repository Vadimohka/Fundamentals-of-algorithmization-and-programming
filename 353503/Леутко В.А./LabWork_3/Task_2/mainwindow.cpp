#include "mainwindow.h"
#include "ackermann.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Ackermann");
    setFixedSize(500, 250);

    QVBoxLayout *layout = new QVBoxLayout(this);

    mLabel = new QLabel("m:", this);
    mLineEdit = new QLineEdit(this);
    nLabel = new QLabel("n:", this);
    nLineEdit = new QLineEdit(this);
    calculateButton = new QPushButton("Вычислить", this);
    resultLabel = new QLabel("Результат:", this);
    resultValueLabel = new QLabel(this);

    layout->addWidget(mLabel);
    layout->addWidget(mLineEdit);
    layout->addWidget(nLabel);
    layout->addWidget(nLineEdit);
    layout->addWidget(calculateButton);
    layout->addWidget(resultLabel);
    layout->addWidget(resultValueLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculateClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::calculateClicked()
{
    int m = mLineEdit->text().toInt();
    int n = nLineEdit->text().toInt();
    int result = Ackermann::calculate(m, n);
    resultValueLabel->setText(QString::number(result));
}
