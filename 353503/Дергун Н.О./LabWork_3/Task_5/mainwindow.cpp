#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);
    ui->fileLineEdit->setReadOnly(true);
    ui->dirLineEdit->setReadOnly(true);
    ui->fileLineEdit->setText(QString::number(NULL));
    ui->dirLineEdit->setText(QString::number(NULL));
    connect(ui->dirPushButton, SIGNAL(clicked(bool)), SLOT(slotChooseDir()));
    connect(ui->filePushButton, SIGNAL(clicked(bool)), SLOT(slotOpenFile()));
}

void MainWindow::_updateFolder()
{
    ui->textEdit->setText(dirChecker_.dirPlan());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotChooseDir()
{
    QString dirName = QFileDialog::getExistingDirectory();
    dirChecker_.changeDirectory(dirName);
    _updateFolder();
    ui->fileLineEdit->setText(QString::number(dirChecker_.fileCnt()));
    ui->dirLineEdit->setText(QString::number(dirChecker_.dirCnt()));
}

void MainWindow::slotOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "");
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}
