#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    char a[House::MAX_CHAR_ARRAY_SIZE] = "somewhere";
    for (int i = 0; i < House::MAX_CHAR_ARRAY_SIZE; ++i) {
        House::districtAdministrationAddress[i] = a[i];
    }
    for (int i = 0; i < House::MAX_INT_ARRAY_SIZE; ++i) {
        House::floorTax[i] = i + 1;
        intArray += QString::number(House::floorTax[i]) + " ";
    }
    house1 = {2, 150.5, 'A', true};
    house2.floors = 5;
    house2.area = 1500.9;
    house2.letter = 'Q';
    house2.hasGarden = false;


    housePtr->floors = 100;
    housePtr->area = 150000.9;
    housePtr->letter = 'X';
    housePtr->hasGarden = false;

    houseRef.floors = 1;
    houseRef.area = 15;
    houseRef.letter = 'A';
    houseRef.hasGarden = true;
    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    intArray.clear();
    for (int i = 0; i < House::MAX_INT_ARRAY_SIZE; ++i) {
        House::floorTax[i] = i + 1;
        intArray += QString::number(House::floorTax[i]) + " ";
    }
    ui->textEdit_1->setText( QString::number(house1.floors) + " | " + QString::number(house1.area, 'g', 15) + " | " + house1.letter + " | "
                            + (house1.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                            intArray + '\n' +
                            QString::number(house2.floors) + " | " + QString::number(house2.area, 'g', 15) + " | " + house2.letter + " | "
                            + (house2.hasGarden ? "true" : "false") + '\n' + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                            intArray
                            );
    ui->textEdit_3->setText( QString::number(housePtr->floors) + " | " + QString::number(housePtr->area, 'g', 15) + " | " + housePtr->letter + " | "
                            + (housePtr->hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                            intArray
                            );
    ui->textEdit_4->setText( QString::number(houseRef.floors) + " | " + QString::number(houseRef.area, 'g', 15) + " | " + houseRef.letter + " | "
                            + (houseRef.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                            intArray);
    ui->lineEdit_output->setText("Input floors(int)");
    step = 0;
    stepArray = 0;
    houseKeyboard.area = 0;
    houseKeyboard.floors = 0;
    houseKeyboard.hasGarden = 0;
    houseKeyboard.letter = ' ';
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
            houseKeyboard.floors = text.toLong();
            ui->lineEdit_output->setText("Input area(double)");
            ++step;
            break;
        case 1:
            houseKeyboard.area =text.toDouble();
            ui->lineEdit_output->setText("Input hasGarden(bool)");
            ++step;
            break;
        case 2:
            ui->lineEdit_output->setText("Input letter(char)");
            houseKeyboard.hasGarden = text.toLong() != 0 ? true : false;
            ++step;
            break;
        case 3:
            ui->lineEdit_output->setText("Input static districtAdministrationAddress(char["+ QString::number(House::MAX_CHAR_ARRAY_SIZE)+"])");
            houseKeyboard.letter = text[0].toLatin1();
            ++step;
            break;
        case 4:
            ui->lineEdit_output->setText("Input static floorTax[" +QString::number(stepArray)+ "](int["+ QString::number(House::MAX_INT_ARRAY_SIZE)+"])");
            byteArray = text.toUtf8();
            ii = 0;
            for (; ii < 9 && ii < byteArray.size(); ++ii) {
                House::districtAdministrationAddress[ii] = byteArray[ii];
            }
            for (; ii < 10; ++ii) {
                House::districtAdministrationAddress[ii] = '\0';
            }
            ++step;
            ui->textEdit_1->setText( QString::number(house1.floors) + " | " + QString::number(house1.area, 'g', 15) + " | " + house1.letter + " | "
                                    + (house1.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                    intArray + '\n' +
                                    QString::number(house2.floors) + " | " + QString::number(house2.area, 'g', 15) + " | " + house2.letter + " | "
                                    + (house2.hasGarden ? "true" : "false") + '\n' + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                    intArray
                                    );
            ui->textEdit_3->setText( QString::number(housePtr->floors) + " | " + QString::number(housePtr->area, 'g', 15) + " | " + housePtr->letter + " | "
                                    + (housePtr->hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                    intArray
                                    );
            ui->textEdit_4->setText( QString::number(houseRef.floors) + " | " + QString::number(houseRef.area, 'g', 15) + " | " + houseRef.letter + " | "
                                    + (houseRef.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                    intArray);
            intArray.clear();
            break;

        case 5:
            ui->lineEdit_output->setText("Input static floorTax[" +QString::number(stepArray + 1)+ "](int["+ QString::number(House::MAX_INT_ARRAY_SIZE)+"])");
            House::floorTax[stepArray] = text.toLongLong();
            intArray += QString::number(House::floorTax[stepArray]) + " ";
            ++stepArray;
            if (stepArray == House::MAX_INT_ARRAY_SIZE) ++step;
            break;
        }
    }

    if (step == 6) {
        ui->lineEdit_input->setReadOnly(true);
        ui->textEdit_2->setText( QString::number(houseKeyboard.floors) + " | " + QString::number(houseKeyboard.area, 'g', 15) + " | " + houseKeyboard.letter + " | "
                                + (houseKeyboard.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                intArray);
        ui->textEdit_1->setText( QString::number(house1.floors) + " | " + QString::number(house1.area, 'g', 15) + " | " + house1.letter + " | "
                                + (house1.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                intArray + '\n' +
                                QString::number(house2.floors) + " | " + QString::number(house2.area, 'g', 15) + " | " + house2.letter + " | "
                                + (house2.hasGarden ? "true" : "false") + '\n' + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                intArray
                                );
        ui->textEdit_3->setText( QString::number(housePtr->floors) + " | " + QString::number(housePtr->area, 'g', 15) + " | " + housePtr->letter + " | "
                                + (housePtr->hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                intArray
                                );
        ui->textEdit_4->setText( QString::number(houseRef.floors) + " | " + QString::number(houseRef.area, 'g', 15) + " | " + houseRef.letter + " | "
                                + (houseRef.hasGarden ? "true" : "false") + " | " + QString::fromLatin1(House::districtAdministrationAddress, 10) + " | " +
                                intArray);
    }
}

