#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->deleteButton->setEnabled(false);
    connect(ui->createButton, &QPushButton::clicked, this, &MainWindow::createQueue);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteElements);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createQueue()
{
    answer = "";
    int temp = 0;
    int min, max;
    queue->clear();
    srand(time(nullptr));
    for (int i = 0; i < DEFAULT_QUEUE_SIZE; ++i)
    {
        temp = 1 + rand() % 50;
        if (i == 0)
        {
            min = temp;
            max = temp;
        }
        else
        {
            if (temp < min)
            {
                min = temp;
                indMin = i + 1;
            }
            if (temp >= max)
            {
                max = temp;
                indMax = i + 1;
            }
        }
        queue->addInEnd(temp);
    }
    answer = queue->toString();
    ui->demonstratingBrowser->setText(answer);
    ui->deleteButton->setEnabled(true);
}

void MainWindow::deleteElements()
{
    Queue* temp = new Queue();
    int ind1 = std::min(indMin, indMax);
    int ind2 = std::max(indMin, indMax);
    for (int i = 1; i <= ind1; ++i)
    {
        temp->addInEnd(queue->peekInBegin());
        queue->delFromBegin();
    }
    for (int i = ind1 + 1; i < ind2; ++i)
    {
        queue->delFromBegin();
    }

    answer += "\n";
    answer += "\n";
    answer += "temp queue: ";
    answer += temp->toString();
    answer += "      queue: ";
    answer += queue->toString();

    int tempSZ = temp->size();
    for (int i = 0; i < tempSZ; ++i)
    {
        queue->addInBegin(temp->peekInEnd());
        temp->delFromEnd();
    }
    qDebug() << temp->size();

    answer += "\n";
    answer += "\n";
    answer += "answer: ";
    answer += queue->toString();

    ui->demonstratingBrowser->setText(answer);
    ui->deleteButton->setEnabled(false);
}
