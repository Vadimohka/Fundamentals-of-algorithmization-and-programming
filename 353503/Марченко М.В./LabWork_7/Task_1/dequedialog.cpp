#include "dequedialog.h"

DequeDialog::DequeDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle("Создать двухсвязную очередь из случайных целых чисел\n. Удалить элементы, находящиеся между max и min.");
    setMinimumSize(860, 600);

    QPushButton* generateButton = new QPushButton("Generate");
    connect(generateButton, &QPushButton::clicked, this, &DequeDialog::generateQueue);

    QPushButton* removeButton = new QPushButton("Remove");
    connect(removeButton, &QPushButton::clicked, this, &DequeDialog::removeElements);

    maxLabel = new QLabel("MAX");
    minLabel = new QLabel("MIN");


    listWidget = new QListWidget(this);

    listWidget->setMinimumWidth(500);

    QVBoxLayout* labelsLayout = new QVBoxLayout;
    labelsLayout->addWidget(minLabel);
    labelsLayout->addWidget(maxLabel);

    QVBoxLayout* buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(generateButton);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addLayout(labelsLayout);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(listWidget);
    setLayout(mainLayout);
}

void DequeDialog::generateQueue()
{

    listWidget->clear();
    queue.clear();

    for (int i = 0; i < 20; ++i) {
        int randomNumber = QRandomGenerator::global()->bounded(100);
        queue.push_back(randomNumber);
        listWidget->addItem(QString::number(randomNumber));
    }
    int maxValue = *std::max_element(queue.begin(), queue.end());
    int minValue = *std::min_element(queue.begin(), queue.end());
    maxLabel->setText("MAX " + QString::number(maxValue));
    minLabel->setText("MIN " + QString::number(minValue));
}

void DequeDialog::removeElements()
{
    if (queue.empty()) {
        return;
    }

    int maxValue = *std::max_element(queue.begin(), queue.end());
    int minValue = *std::min_element(queue.begin(), queue.end());

    auto itMax = std::find(queue.begin(), queue.end(), maxValue);
    auto itMin = std::find(queue.begin(), queue.end(), minValue);
    if (itMax < itMin) {
        queue.erase(itMax + 1, itMin);
    } else {
        queue.erase(itMin + 1, itMax);
    }

    listWidget->clear();
    for (int value : queue) {
        listWidget->addItem(QString::number(value));
    }
}



