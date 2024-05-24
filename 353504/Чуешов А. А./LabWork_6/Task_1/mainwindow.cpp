#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    char a[Shop::MAX_CHAR_ARRAY_SIZE] = "somewhere";
    for (int i = 0; i < Shop::MAX_CHAR_ARRAY_SIZE; ++i) {
        Shop::districtAdministrationAddress[i] = a[i];
    }
    for (int i = 0; i < Shop::MAX_INT_ARRAY_SIZE; ++i) {
        Shop::employeeSalary[i] = i + 1;
        intArray += QString::number(Shop::employeeSalary[i]) + " ";
    }
    shop1 = {2, 150.5, 'A', true};
    shop2.numberOfEmployees = 5;
    shop2.area = 1500.9;
    shop2.shopType = 'Q';
    shop2.hasParking = false;


    shopPtr->numberOfEmployees = 100;
    shopPtr->area = 150000.9;
    shopPtr->shopType = 'X';
    shopPtr->hasParking = false;

    shopRef.numberOfEmployees = 1;
    shopRef.area = 15;
    shopRef.shopType = 'A';
    shopRef.hasParking = true;
    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    intArray.clear();
    for (int i = 0; i < Shop::MAX_INT_ARRAY_SIZE; ++i) {
        Shop::employeeSalary[i] = i + 1;
        intArray += QString::number(Shop::employeeSalary[i]) + " ";
    }
    ui->textEdit_1->setText( QString::number(shop1.numberOfEmployees) + " | " + QString::number(shop1.area, 'g', 15) + " | " + shop1.shopType + " | "
                            + (shop1.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                            intArray + '\n' +
                            QString::number(shop2.numberOfEmployees) + " | " + QString::number(shop2.area, 'g', 15) + " | " + shop2.shopType + " | "
                            + (shop2.hasParking ? "true" : "false") + '\n' + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                            intArray
                            );
    ui->textEdit_3->setText( QString::number(shopPtr->numberOfEmployees) + " | " + QString::number(shopPtr->area, 'g', 15) + " | " + shopPtr->shopType + " | "
                            + (shopPtr->hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                            intArray
                            );
    ui->textEdit_4->setText( QString::number(shopRef.numberOfEmployees) + " | " + QString::number(shopRef.area, 'g', 15) + " | " + shopRef.shopType + " | "
                            + (shopRef.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                            intArray);
    ui->lineEdit_output->setText("Input numberOfEmployees(int)");
    step = 0;
    stepArray = 0;
    shopKeyboard.area = 0;
    shopKeyboard.numberOfEmployees = 0;
    shopKeyboard.hasParking = 0;
    shopKeyboard.shopType = ' ';
    ui->lineEdit_input->setReadOnly(false);
    ui->textEdit_2->clear();
}


void MainWindow::on_pushButton_send_clicked()
{
    QByteArray byteArray;
    QString text = ui->lineEdit_input->text();;
    int ii;
    if (!text.isEmpty()){
        switch (step) {
        case 0:
            shopKeyboard.numberOfEmployees = text.toLong();
            ui->lineEdit_output->setText("Input area(double)");
            ++step;
            break;
        case 1:
            shopKeyboard.area =text.toDouble();
            ui->lineEdit_output->setText("Input hasParking(bool)");
            ++step;
            break;
        case 2:
            ui->lineEdit_output->setText("Input shopType(char)");
            shopKeyboard.hasParking = text.toLong() != 0 ? true : false;
            ++step;
            break;
        case 3:
            ui->lineEdit_output->setText("Input static districtAdministrationAddress(char["+ QString::number(Shop::MAX_CHAR_ARRAY_SIZE)+"])");
            shopKeyboard.shopType = text[0].toLatin1();
            ++step;
            break;
        case 4:
            ui->lineEdit_output->setText("Input static employeeSalary(int[" +QString::number(stepArray)+ "])");
            byteArray = text.toUtf8();
            ii = 0;
            for (; ii < 9 && ii < byteArray.size(); ++ii) {
                Shop::districtAdministrationAddress[ii] = byteArray[ii];
            }
            for (; ii < 10; ++ii) {
                Shop::districtAdministrationAddress[ii] = '\0';
            }
            ++step;
            ui->textEdit_1->setText( QString::number(shop1.numberOfEmployees) + " | " + QString::number(shop1.area, 'g', 15) + " | " + shop1.shopType + " | "
                                    + (shop1.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                    intArray + '\n' +
                                    QString::number(shop2.numberOfEmployees) + " | " + QString::number(shop2.area, 'g', 15) + " | " + shop2.shopType + " | "
                                    + (shop2.hasParking ? "true" : "false") + '\n' + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                    intArray
                                    );
            ui->textEdit_3->setText( QString::number(shopPtr->numberOfEmployees) + " | " + QString::number(shopPtr->area, 'g', 15) + " | " + shopPtr->shopType + " | "
                                    + (shopPtr->hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                    intArray
                                    );
            ui->textEdit_4->setText( QString::number(shopRef.numberOfEmployees) + " | " + QString::number(shopRef.area, 'g', 15) + " | " + shopRef.shopType + " | "
                                    + (shopRef.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                    intArray);
            intArray.clear();
            break;

        case 5:
            ui->lineEdit_output->setText("Input static employeeSalary" +QString::number(stepArray + 1)+ "])");
            Shop::employeeSalary[stepArray] = text.toLongLong();
            intArray += QString::number(Shop::employeeSalary[stepArray]) + " ";
            ++stepArray;
            if (stepArray == Shop::MAX_INT_ARRAY_SIZE) ++step;
            break;
        }
    }

    if (step == 6) {
        ui->lineEdit_input->setReadOnly(true);
        ui->textEdit_2->setText( QString::number(shopKeyboard.numberOfEmployees) + " | " + QString::number(shopKeyboard.area, 'g', 15) + " | " + shopKeyboard.shopType + " | "
                                + (shopKeyboard.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                intArray);
        ui->textEdit_1->setText( QString::number(shop1.numberOfEmployees) + " | " + QString::number(shop1.area, 'g', 15) + " | " + shop1.shopType + " | "
                                + (shop1.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                intArray + '\n' +
                                QString::number(shop2.numberOfEmployees) + " | " + QString::number(shop2.area, 'g', 15) + " | " + shop2.shopType + " | "
                                + (shop2.hasParking ? "true" : "false") + '\n' + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                intArray
                                );
        ui->textEdit_3->setText( QString::number(shopPtr->numberOfEmployees) + " | " + QString::number(shopPtr->area, 'g', 15) + " | " + shopPtr->shopType + " | "
                                + (shopPtr->hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                intArray
                                );
        ui->textEdit_4->setText( QString::number(shopRef.numberOfEmployees) + " | " + QString::number(shopRef.area, 'g', 15) + " | " + shopRef.shopType + " | "
                                + (shopRef.hasParking ? "true" : "false") + " | " + QString::fromLatin1(Shop::districtAdministrationAddress, 10) + " | " +
                                intArray);
    }
}
