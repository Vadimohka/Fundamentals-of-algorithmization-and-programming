#include "rangedialog.h"


RangeDialog::RangeDialog(QWidget *parent):QDialog(parent)
{
    setWindowTitle("Введите диапазон");
    resize(400,200);

    QLabel *minLabel = new QLabel("Минимальное значение:");
    QLabel *maxLabel = new QLabel("Максимальное значение:");

    minLineEdit = new QLineEdit;
    maxLineEdit = new QLineEdit;
    currBox = new QComboBox;

    currBox->addItem("USD");
    currBox->addItem("EUR");
    currBox->addItem("руб.");

    QPushButton *applyButton = new QPushButton("Применить");
    QPushButton *cancelButton = new QPushButton("Отменить");

    connect(applyButton, &QPushButton::clicked, this, &RangeDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &RangeDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(minLabel);
    mainLayout->addWidget(minLineEdit);
    mainLayout->addWidget(maxLabel);
    mainLayout->addWidget(maxLineEdit);
    mainLayout->addWidget(currBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(applyButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

double RangeDialog::getMinVal() const
{

    double minValue = minLineEdit->text().toDouble();
    return minValue;
}

double RangeDialog::getMaxVal() const
{
    double maxValue = maxLineEdit->text().toDouble();
    return maxValue;
}

QString RangeDialog::getCurr()
{
    return currBox->currentText();
}

