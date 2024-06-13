#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileWorker = new FileWorker(ui->textBrowser);
    ui->label_3->hide();
    ui->textBrowser->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_menu_clicked()
{
    ui->label_3->hide();
    ui->textBrowser->hide();

    int menuChoice = QInputDialog::getInt(this, tr("Menu"), "Enter:\n1 - Save text to file\n2 - Load text from file"
                                                            "\n3 - Save array to file\n4 - Load array from file\n5 - Save struct to file"
                                                            "\n6 - Load structs from file\n7 - Save struct to binary file"
                                                            "\n8 - Load struct from binary file\n9 - Save sentence to file\n10 - Load sentence from file");

    fileWorker->CreateNonExistingFiles();
    switch (menuChoice)
    {
    case 1:
        fileWorker->SaveTextToFile(fileWorker->files[0]);
        break;
    case 2:
        fileWorker->LoadTextFromFile(fileWorker->files[0]);
        ui->label_3->setText(fileWorker->files[0] + " Output");
        break;
    case 3:
        fileWorker->SaveArrayToFile(fileWorker->files[1]);
        break;
    case 4:
        fileWorker->LoadArrayFromFile(fileWorker->files[1]);
        ui->label_3->setText(fileWorker->files[1] + " Output");
        break;
    case 5:
        fileWorker->SaveStructToFile(fileWorker->files[2]);
        break;
    case 6:
        fileWorker->LoadStructsFromFile(fileWorker->files[2]);
        ui->label_3->setText(fileWorker->files[2] + " Output");
        break;
    case 7:
        fileWorker->SaveStructToBinaryFile(fileWorker->files[3]);
        break;
    case 8:
        fileWorker->LoadStructsFromBinaryFile(fileWorker->files[3]);
        ui->label_3->setText(fileWorker->files[3] + " Output");
        break;
    case 9:
        fileWorker->SaveSentenceToFile(fileWorker->files[4]);
        break;
    case 10:
        fileWorker->LoadSentencesFromFile(fileWorker->files[4]);
        ui->label_3->setText(fileWorker->files[4] + " Output");
        break;
    default:
        break;
    }
    if (menuChoice > 0 && menuChoice < 11 && menuChoice % 2 == 0)
    {
        ui->label_3->show();
        ui->textBrowser->show();
    }
}
