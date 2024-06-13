#include "searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) : QDialog(parent) {

    QLabel *type = new QLabel("Тип: ");
    typeEdit = new QLineEdit(this);

    QLabel *manufacturer = new QLabel("Изготовитель");
    manufacturerEdit = new QLineEdit(this);

    QLabel *model = new QLabel("Модель:");
    modelLineEdit = new QLineEdit(this);

    QPushButton *okButton = new QPushButton("ОК", this);
    QPushButton *cancelButton = new QPushButton("Отмена", this);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(type);
    layout->addWidget(typeEdit);
    layout->addWidget(manufacturer);
    layout->addWidget(manufacturerEdit);
    layout->addWidget(model);
    layout->addWidget(modelLineEdit);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);


    layout->addLayout(buttonsLayout);

    setLayout(layout);


    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString SearchDialog::getType() const
{
    return typeEdit->text();
}

QString SearchDialog::getManufacturer() const
{
    return manufacturerEdit->text();
}

QString SearchDialog::getModel() const
{
    return modelLineEdit->text();
}
