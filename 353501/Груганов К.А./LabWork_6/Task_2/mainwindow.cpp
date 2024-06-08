#include "mainwindow.h"
#include <QtWidgets>
#include "files.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->hide();
    file = new Files(ui->textBrowser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_menu_clicked()
{
    ui->textBrowser->hide();

    int menuChoice = QInputDialog::getInt(
        this,
        tr("Menu"),
        "Enter:\n1 - Save text to file\n2 - Load text from file"
        "\n3 - Save array to file\n4 - Load array from file\n5 - Save struct to file"
        "\n6 - Load structs from file\n7 - Save struct to binary file"
        "\n8 - Load struct from binary file\n9 - Save sentence to file\n10 - Load sentence from "
        "file");

    file->CreateNonExistingFiles();
    switch (menuChoice) {
    case 1:
        file->SaveTextToFile(file->files[0]);
        break;
    case 2:
        file->LoadTextFromFile(file->files[0]);
        ui->label->setText(file->files[0] + " Output");
        break;
    case 3:
        file->SaveArrayToFile(file->files[1]);
        break;
    case 4:
        file->LoadArrayFromFile(file->files[1]);
        ui->label->setText(file->files[1] + " Output");
        break;
    case 5:
        file->SaveStructToFile(file->files[2]);
        break;
    case 6:
        file->LoadStructsFromFile(file->files[2]);
        ui->label->setText(file->files[2] + " Output");
        break;
    case 7:
        file->SaveStructToBinaryFile(file->files[3]);
        break;
    case 8:
        file->LoadStructsFromBinaryFile(file->files[3]);
        ui->label->setText(file->files[3] + " Output");
        break;
    case 9:
        file->SaveSentenceToFile(file->files[4]);
        break;
    case 10:
        file->LoadSentencesFromFile(file->files[4]);
        ui->label->setText(file->files[4] + " Output");
        break;
    default:
        break;
    }
    if (menuChoice > 0 && menuChoice < 11 && menuChoice % 2 == 0) {
        ui->label->show();
        ui->textBrowser->show();
    }
}
