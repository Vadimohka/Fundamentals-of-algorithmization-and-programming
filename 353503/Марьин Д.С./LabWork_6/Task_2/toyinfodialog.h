#ifndef TOYINFODIALOG_H
#define TOYINFODIALOG_H

#include "QtWidgets/qpushbutton.h"
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QMainWindow>
#include "toy.h"

class ToyInfoDialog : public QDialog
{
    Q_OBJECT

public:
    ToyInfoDialog(const Toy& toy, QWidget *parent = nullptr) : QDialog(parent)
    {
        setWindowTitle("Toy Information");

        auto *layout = new QFormLayout(this);

        layout->addRow("Age: ", new QLabel(QString::number(toy._age), this));
        layout->addRow("Price: ", new QLabel(QString::number(toy._price), this));
        layout->addRow("Name: ", new QLabel(toy._name.c_str(), this));
        layout->addRow("Is for children?: ", new QLabel(toy._isForChildern ? "Yes" : "No", this));

        auto *okButton = new QPushButton("OK", this);
        connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
        layout->addRow(okButton);
    }
};

#endif // TOYINFODIALOG_H
