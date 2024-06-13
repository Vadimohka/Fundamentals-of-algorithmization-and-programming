#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString direct = QFileDialog::getExistingDirectory(nullptr, ("Open Directory"),
                                                       "/home",
                                                       QFileDialog::ShowDirsOnly
                                                           | QFileDialog::DontResolveSymlinks);
    if (direct.isEmpty()) {
        QMessageBox::critical(nullptr, "Error", "You don't chose the directory.");
    }
    else {
        int files{}, directories{};
        QStringList dirList, fileList;
        countFilesAndFolders(direct,files, directories, dirList, fileList);
        ui->textBrowser_2->setText(QString::number(directories));
        ui->textBrowser_3->setText(QString::number(files));
        ui->textBrowser->setText(dirList.join("\n"));
        ui->textBrowser_4->setText(fileList.join("\n"));
    }
}





