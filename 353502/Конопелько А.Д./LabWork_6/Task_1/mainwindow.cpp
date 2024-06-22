#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    char a[AutoRepair::MAX_CHAR_ARRAY_SIZE] = "anywhere";
    for (int i = 0; i < AutoRepair::MAX_CHAR_ARRAY_SIZE; ++i) {
        AutoRepair::streetName[i] = a[i];
    }
    for (int i = 0; i < AutoRepair::MAX_INT_ARRAY_SIZE; ++i) {
        AutoRepair::addressNumbers[i] = i + 1;
        myArray += QString::number(AutoRepair::addressNumbers[i]) + " ";
    }
    repair1 = {2, 150.5, 'A', true};
    repair2.floors = 5;
    repair2.area = 1500.9;
    repair2.type = 'Q';
    repair2.hasVIP = false;


    repairPtr->floors = 100;
    repairPtr->area = 150000.9;
    repairPtr->type = 'X';
    repairPtr->hasVIP = false;

    repairRef.floors = 1;
    repairRef.area = 15;
    repairRef.type = 'A';
    repairRef.hasVIP = true;
    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    myArray.clear();
    for (int i = 0; i < AutoRepair::MAX_INT_ARRAY_SIZE; i++) {
        AutoRepair::addressNumbers[i] = i + 1;
        myArray += QString::number(AutoRepair::addressNumbers[i]) + " ";
    }
    ui->textEdit_1->setText( QString::number(repair1.floors) + " | " + QString::number(repair1.area, 'g', 5) + " | " + repair1.type + " | "
                            + (repair1.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                            myArray + '\n' +
                            QString::number(repair2.floors) + " | " + QString::number(repair2.area, 'g', 5) + " | " + repair2.type + " | "
                            + (repair2.hasVIP ? "true" : "false") + '\n' + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                            myArray
                            );
    ui->textEdit_3->setText( QString::number(repairPtr->floors) + " | " + QString::number(repairPtr->area, 'g', 5) + " | " + repairPtr->type + " | "
                            + (repairPtr->hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                            myArray
                            );
    ui->textEdit_4->setText( QString::number(repairRef.floors) + " | " + QString::number(repairRef.area, 'g', 5) + " | " + repairRef.type + " | "
                            + (repairRef.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                            myArray);
    ui->lineEdit_output->setText("Input floors(int)");
    step = 0;
    stepArray = 0;
    repairInst.area = 0;
    repairInst.floors = 0;
    repairInst.hasVIP = 0;
    repairInst.type = ' ';
    ui->lineEdit_input->setReadOnly(false);
    ui->textEdit_2->clear();
}


void MainWindow::on_pushButton_send_clicked()
{
    QByteArray byteArray;
    QString text = ui->lineEdit_input->text();;
    int j;
    if (!text.isEmpty()){
        switch (step) {
        case 0:
            repairInst.floors = text.toLong();
            ui->lineEdit_output->setText("Input area(double)");
            ++step;
            break;
        case 1:
            repairInst.area = text.toDouble();
            ui->lineEdit_output->setText("Input hasVIP(bool)");
            ++step;
            break;
        case 2:
            ui->lineEdit_output->setText("Input type(char)");
            repairInst.hasVIP = text.toLong() != 0 ? true : false;
            ++step;
            break;
        case 3:
            ui->lineEdit_output->setText("Input static streetName(char["+ QString::number(AutoRepair::MAX_CHAR_ARRAY_SIZE)+"])");
            repairInst.type = text[0].toLatin1();
            ++step;
            break;
        case 4:
            ui->lineEdit_output->setText("Input static addressNumbers[" +QString::number(stepArray)+ "](int["+ QString::number(AutoRepair::MAX_INT_ARRAY_SIZE)+"])");
            byteArray = text.toUtf8();
            j = 0;
            for (; j < 9 && j < byteArray.size(); j++) {
                AutoRepair::streetName[j] = byteArray[j];
            }
            for (; j < 10; j++) {
                AutoRepair::streetName[j] = '\0';
            }
            ++step;
            ui->textEdit_1->setText( QString::number(repair1.floors) + " | " + QString::number(repair1.area, 'g', 15) + " | " + repair1.type + " | "
                                    + (repair1.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                    myArray + '\n' +
                                    QString::number(repair2.floors) + " | " + QString::number(repair2.area, 'g', 15) + " | " + repair2.type + " | "
                                    + (repair2.hasVIP ? "true" : "false") + '\n' + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                    myArray
                                    );
            ui->textEdit_3->setText( QString::number(repairPtr->floors) + " | " + QString::number(repairPtr->area, 'g', 15) + " | " + repairPtr->type + " | "
                                    + (repairPtr->hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                    myArray
                                    );
            ui->textEdit_4->setText( QString::number(repairRef.floors) + " | " + QString::number(repairRef.area, 'g', 15) + " | " + repairRef.type + " | "
                                    + (repairRef.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                    myArray);
            myArray.clear();
            break;

        case 5:
            ui->lineEdit_output->setText("Input static addressNumbers[" +QString::number(stepArray + 1)+ "](int["+ QString::number(AutoRepair::MAX_INT_ARRAY_SIZE)+"])");
            AutoRepair::addressNumbers[stepArray] = text.toLongLong();
            myArray += QString::number(AutoRepair::addressNumbers[stepArray]) + " ";
            ++stepArray;
            if (stepArray == AutoRepair::MAX_INT_ARRAY_SIZE) ++step;
            break;
        }
    }

    if (step == 6) {
        ui->lineEdit_input->setReadOnly(true);
        ui->textEdit_2->setText( QString::number(repairInst.floors) + " | " + QString::number(repairInst.area, 'g', 15) + " | " + repairInst.type + " | "
                                + (repairInst.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                myArray);
        ui->textEdit_1->setText( QString::number(repair1.floors) + " | " + QString::number(repair1.area, 'g', 15) + " | " + repair1.type + " | "
                                + (repair1.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                myArray + '\n' +
                                QString::number(repair2.floors) + " | " + QString::number(repair2.area, 'g', 15) + " | " + repair2.type + " | "
                                + (repair2.hasVIP ? "true" : "false") + '\n' + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                myArray
                                );
        ui->textEdit_3->setText( QString::number(repairPtr->floors) + " | " + QString::number(repairPtr->area, 'g', 15) + " | " + repairPtr->type + " | "
                                + (repairPtr->hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                myArray
                                );
        ui->textEdit_4->setText( QString::number(repairRef.floors) + " | " + QString::number(repairRef.area, 'g', 15) + " | " + repairRef.type + " | "
                                + (repairRef.hasVIP ? "true" : "false") + " | " + QString::fromLatin1(AutoRepair::streetName, 10) + " | " +
                                myArray);
    }
}
