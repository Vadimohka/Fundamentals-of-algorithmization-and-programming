#include "mainwindow.h"
#include "address.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFontMetrics>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QGraphicsTextItem>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
    ui->setupUi(this);

    {
        QStringList sizesList;
        for (int i = 0; i < std::size(Address::HOUSE); ++i) {
            sizesList.push_back(QString::number(Address::HOUSE[i], 'g', 3));
        }
        ui->euSizeBox->addItems(sizesList);
    }

    {
        QStringList typesList;
        for (int i = 0; i < std::size(Address::WAS); ++i) {
            typesList.push_back(QString(Address::WAS[i]));
        }
        ui->genderBox->addItems(typesList);
    }

    initializeDefaultAddress();
}

MainWindow::~MainWindow() {
    if (homeAddress) {
        delete homeAddress;
    }
    delete ui;
}

void MainWindow::initializeDefaultAddress() {
    Address defaultAddress{};
    defaultAddress.vOrC = 'c';
    defaultAddress.address = 78;
    defaultAddress.wasOrNot = false;
    defaultAddress.name = "Something street";
    ui->addressData->setText(QString::fromStdString(defaultAddress.to_string()));
}

void MainWindow::on_initializeButton_clicked() {
    auto initializerString = ui->initializerEdit->text();
    Address *newAddress;
    try {
        newAddress = new Address(initializerString.toStdString());
    } catch (const std::invalid_argument &ex) {
        QString errorMessage = ex.what();
        if (errorMessage == "stoi") {
            errorMessage = "Bad initializer string";
        }
        QMessageBox::warning(this, "Warning", "No Address was initialized: " + errorMessage +
                             "\nAlso make sure to remove extra spaces and characters.");
        return;
    }
    resetAddress(newAddress);
}

void MainWindow::on_initializeValuesButton_clicked() {
    uchar way = std::rand() % 2;
    Address *newAddress = new Address();
    bool ok = true;
    if (way) {
        newAddress->name = ui->nameEdit->text().toStdString();
        double euSize = ui->euSizeBox->currentText().toDouble();
        newAddress->eu_size = euSize;
        char gender = ui->genderBox->currentText()[0].toLatin1();
        newAddress->gender = gender;
        bool isChild = ui->isChildBox->checkState();
        newAddress->is_child = isChild;
    } else {
        Address &refNewAddress = *newAddress;
        refNewAddress.name = ui->nameEdit->text().toStdString();
        double euSize = ui->euSizeBox->currentText().toDouble();
        refNewAddress.eu_size = euSize;
        char gender = ui->genderBox->currentText()[0].toLatin1();
        refNewAddress.gender = gender;
        bool isChild = ui->isChildBox->checkState();
        refNewAddress.is_child = isChild;
    }
    resetAddress(newAddress);
}

void MainWindow::resetAddress(Address *newAddress) {
    if (homeAddress) {
        delete homeAddress;
        homeAddress = nullptr;
    }
    homeAddress = newAddress;
    ui->addressData->setText(QString::fromStdString(homeAddress->to_string()));
}

void MainWindow::on_printButton_clicked() {
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer);
    if (dialog->exec() != QPrintDialog::Accepted) {
        return;
    }

    const QString &sourceText = ui->addressData->text();

    QFont outputFont("Monospace", 15);
    QFontMetrics fontMetrics(outputFont);
    QRect textRect = fontMetrics.boundingRect(sourceText);
    QRect pageRect = printer.pageRect(QPrinter::DevicePixel);
    QRect outputRect = {static_cast<int>(pageRect.x()), static_cast<int>(pageRect.y()), static_cast<int>(pageRect.width()), textRect.height()};

    QPainter painter;
    painter.begin(&printer);
    painter.setFont(outputFont);
    painter.drawText(outputRect, Qt::AlignTop | Qt::AlignHCenter, ui->addressData->text());
    painter.end();
}
