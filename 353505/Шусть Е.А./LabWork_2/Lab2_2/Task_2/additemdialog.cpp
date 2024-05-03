#include "additemdialog.h"


AddItemDialog::AddItemDialog(QWidget *):QDialog()
{
    setWindowTitle("Добавить комплектующие");
    resize(400, 200);
    typeLineEdit = new QLineEdit();
    manufacturerLineEdit = new QLineEdit();
    modelLineEdit = new QLineEdit();
    parametersLineEdit = new QLineEdit();
    priceLineEdit = new QLineEdit();
    currBox = new QComboBox();
    availabilityBox = new QComboBox();

    currBox->addItem("USD");
    currBox->addItem("EUR");
    currBox->addItem("руб.");

    availabilityBox->addItem("В наличии");
    availabilityBox->addItem("Нет в наличии");
    form = new QFormLayout;
    form->addRow("Тип:", typeLineEdit);
    form->addRow("Изготовитель:", manufacturerLineEdit);
    form->addRow("Модель:", modelLineEdit);
    form->addRow("Параметры:", parametersLineEdit);
    form->addRow("Цена:", priceLineEdit);
    form->addRow("Валюта:", currBox);
    form->addRow("Наличие:", availabilityBox);

    QPushButton *okButton = new QPushButton("Добавить", this);
    connect(okButton, &QPushButton::clicked, this, &AddItemDialog::accept);

    QPushButton *cancelButton = new QPushButton("Отмена", this);
    connect(cancelButton, &QPushButton::clicked, this, &AddItemDialog::reject);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(form);
    main->addLayout(buttonLayout);

    setLayout(main);
}

QString AddItemDialog::getType() const
{
    return typeLineEdit->text();
}

QString AddItemDialog::getManufacturer() const
{
    return manufacturerLineEdit->text();
}

QString AddItemDialog::getModel() const
{
    return modelLineEdit->text();
}

QString AddItemDialog::getParameters() const
{
    return parametersLineEdit->text();
}

double AddItemDialog::getPrice() const
{
    return priceLineEdit->text().toDouble();
}


QString AddItemDialog::getCurrency() const
{
    return currBox->currentText();
}

QString AddItemDialog::getAvailability() const
{
    return availabilityBox->currentText();
}

void AddItemDialog::setType(const QString &s)
{
    typeLineEdit->setText(s);
}

void AddItemDialog::setMan(const QString &s)
{
    manufacturerLineEdit->setText(s);
}

void AddItemDialog::setModel(const QString &s)
{
    modelLineEdit->setText(s);
}

void AddItemDialog::setParameters(const QString &s)
{
    parametersLineEdit->setText(s);
}

void AddItemDialog::setPrice(double s)
{
    QString priceStr = QString::number(s);
    priceLineEdit->setText(priceStr);
}

void AddItemDialog::setCurr(int idx)
{
    currBox->setCurrentIndex(idx);
}

void AddItemDialog::setAvailable(int idx)
{
    availabilityBox->setCurrentIndex(idx);
}

