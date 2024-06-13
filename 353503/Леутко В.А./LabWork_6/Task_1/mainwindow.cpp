#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QButtonGroup* abcdGroup = new QButtonGroup(this);
    abcdGroup->addButton(ui->checkBox_A, 0);
    abcdGroup->addButton(ui->checkBox_B, 1);
    abcdGroup->addButton(ui->checkBox_C, 2);
    abcdGroup->addButton(ui->checkBox_D, 3);
    abcdGroup->setExclusive(true);

    QButtonGroup* yesNoGroup = new QButtonGroup(this);
    yesNoGroup->addButton(ui->checkBox_yes, 0);
    yesNoGroup->addButton(ui->checkBox_no, 1);
    yesNoGroup->setExclusive(true);

    connect(ui->initMethodComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::handleInitMethodChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::printInfo(const AutoRepairShop &shop)
{
    QString info = QString("Age: %1\n"
                           "Repair Bill: %2\n"
                           "Category: %3\n"
                           "Is Certificated: %4\n"
                           "Auto Name: %5\n"
                           "Breakdowns:\n")
                       .arg(shop.age)
                       .arg(shop.repairBill)
                       .arg(shop.category)
                       .arg(shop.isCertificated ? "Yes" : "No")
                       .arg(QString::fromLocal8Bit(shop.autoName.data(), MAX_NAME));
    for (int i = 0; i < MAX_BREAKDOWNS; ++i)
    {
        if (shop.breakdowns[i] != 0)
        {
            info += QString("%1\n").arg(shop.breakdowns[i]);
        }
    }
    ui->textEdit->clear();
    ui->textEdit->append(info);
    return info;
}

void MainWindow::handleInitMethodChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(1);
    switch (index) {
    case 0:
        explicitInitialization();
        break;
    case 1:
        ui->stackedWidget->setCurrentIndex(0);
        initializeFromTheKeyboard();
        break;
    case 2:
        initializeWithPointer();
        break;
    case 3:
        initializeWithReference();
        break;
    default:
        break;
    }
}

void MainWindow::explicitInitialization()
{
    shop1.age = 20;
    shop1.repairBill = 2500.75;
    shop1.category = 'B';
    shop1.isCertificated = false;
    strncpy(shop1.autoName.data(), "Porsche Cuper CAR/0", shop1.autoName.size() - 1);
    shop1.autoName[shop1.autoName.size() - 1] = '0';
    for (int i = 0; i < MAX_BREAKDOWNS; i++) {
        shop1.breakdowns[i] = i + 1;
    }
    printInfo(shop1);
}

void MainWindow::initializeWithPointer()
{
    AutoRepairShop* pShop = &shop2;
    pShop->age = 30;
    pShop->repairBill = 3750.99;
    pShop->category = 'C';
    pShop->isCertificated = true;
    strncpy(pShop->autoName.data(), "agera", pShop->autoName.size() - 1);
    pShop->autoName[pShop->autoName.size() - 1] = '\0';
    for (int i = 0; i < MAX_BREAKDOWNS; i++) {
        pShop->breakdowns[i] = i * 2 + 1;
    }
    printInfo(*pShop);
}

void MainWindow::initializeWithReference()
{
    AutoRepairShop& refShop = shop3;
    refShop.age = 25;
    refShop.repairBill = 1999.99;
    refShop.category = 'B';
    refShop.isCertificated = false;
    strncpy(refShop.autoName.data(), "mustang", refShop.autoName.size() - 1);
    refShop.autoName[refShop.autoName.size() - 1] = '\0';
    for (int i = 0; i < MAX_BREAKDOWNS; i++) {
        refShop.breakdowns[i] = i * 3 + 1;
    }
    printInfo(refShop);
}

void MainWindow::initializeFromTheKeyboard()
{
    shop4.age = ui->spinBox_age->value();
    shop4.repairBill = ui->spinBox_repairBill->value();

    if (ui->checkBox_yes->isChecked()) {
        shop4.isCertificated = true;
        ui->checkBox_no->setChecked(false);
    } else if (ui->checkBox_no->isChecked()) {
        shop4.isCertificated = false;
        ui->checkBox_yes->setChecked(false);
    }

    if (ui->checkBox_A->isChecked()) {
        shop4.category = 'A';
        ui->checkBox_B->setChecked(false);
        ui->checkBox_C->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_B->isChecked()) {
        shop4.category = 'B';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_C->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_C->isChecked()) {
        shop4.category = 'C';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_B->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_D->isChecked()) {
        shop4.category = 'D';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_B->setChecked(false);
        ui->checkBox_C->setChecked(false);
    } else {
        shop4.category = '\0'; // Нет выбранной категории
    }

    QString autoNameQString = ui->lineEdit->text();
    strncpy(shop4.autoName.data(), autoNameQString.toLocal8Bit().constData(), shop4.autoName.size() - 1);
    shop4.autoName[shop4.autoName.size() - 1] = '\0';

    for (int i = 0; i < MAX_BREAKDOWNS; i++) {
        shop4.breakdowns[i] = ui->spinBox_breakdowns->value();
    }

    printInfo(shop4);
}
