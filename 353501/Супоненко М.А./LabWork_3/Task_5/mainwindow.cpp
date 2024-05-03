#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openFolderButton, &QPushButton::clicked, this, &MainWindow::openFolder);
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::countFilesAndFolders);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFolder()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::homePath());
    ui->folderPathLineEdit->setText(directory);
}

void MainWindow::countFilesAndFolders()
{
    QString directory = ui->folderPathLineEdit->text();
    if(directory == '/') {
        ui->folderCountLabel->setText(QString("Folders: -"));
        ui->fileCountLabel->setText(QString("Files: -"));
    }
    else {
    int folderCount = fileCounter.countFolders(directory);
    int fileCount = fileCounter.countFiles(directory);
    ui->folderCountLabel->setText(QString("Folders: %1").arg(folderCount));
    ui->fileCountLabel->setText(QString("Files: %1").arg(fileCount));
    }
}
