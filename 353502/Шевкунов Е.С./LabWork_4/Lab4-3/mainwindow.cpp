#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);

    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    mainLayout->addWidget(textEdit);

    spinBox = new QSpinBox(this);
    spinBox->setMinimum(1);
    mainLayout->addWidget(spinBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    mainLayout->addLayout(buttonLayout);

    restartButton = new QPushButton("Restart", this);
    buttonLayout->addWidget(restartButton);
    connect(restartButton, &QPushButton::clicked, this, &MainWindow::restartClicked);

    enterButton = new QPushButton("Enter", this);
    buttonLayout->addWidget(enterButton);
    connect(enterButton, &QPushButton::clicked, this, &MainWindow::enterClicked);

    label_n = new QLabel("n:", this);
    mainLayout->addWidget(label_n);

    messageLabel = new QLabel("Enter n:", this);
    mainLayout->addWidget(messageLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterClicked()
{
    if (messageLabel->text() == "Enter n:") {
        n = spinBox->value();
        arr.resize(n);
        spinBox->setMinimum(-2147483647);
        messageLabel->setText("Enter element № " + QString::number(enterI + 1) + ":");
        label_n->setText("n: " + QString::number(n));
    } else {
        arr[enterI] = spinBox->value();
        if (enterI == 0) {
            textEdit->setVisible(true);
            textEdit->setText("arr: " + QString::number(arr[0]));
        } else {
            textEdit->setText(textEdit->toPlainText() + " " + QString::number(arr[enterI]));
        }
        ++enterI;

        if (enterI != n) {
            messageLabel->setText("Enter element № " + QString::number(enterI + 1) + ":");
        } else {
            messageLabel->setText("Input ended");
            spinBox->setEnabled(false);
            enterButton->setEnabled(false);

            QVector<long long> medians;

            for (int i = 0; i < arr.size(); i += 3) {
                QVector<long long> triplet;
                triplet.push_back(arr[i]);

                if (i + 1 < arr.size()) {
                    triplet.push_back(arr[i + 1]);
                }
                if (i + 2 < arr.size()) {
                    triplet.push_back(arr[i + 2]);
                }

                std::sort(triplet.begin(), triplet.end());

                if (triplet.size() == 1) {
                    medians.push_back(triplet[0]);
                } else if (triplet.size() == 2) {
                    medians.push_back((triplet[0] + triplet[1]) / 2);
                } else {
                    medians.push_back(triplet[1]);
                }
            }

            QString mediansText = "Medians: ";
            for (int median : medians) {
                mediansText += QString::number(median) + " ";
            }
            textEdit->append(mediansText);
        }
    }
}



void MainWindow::restartClicked()
{
    spinBox->setEnabled(true);
    enterButton->setEnabled(true);
    spinBox->setMinimum(1);
    arr.clear();
    enterI = 0;
    n = 0;
    textEdit->clear();
    label_n->setText("");
    messageLabel->setText("Enter n:");
}

