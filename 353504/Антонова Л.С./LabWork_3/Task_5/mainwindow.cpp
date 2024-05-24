#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::Count(QString path, long &directoriesAmount, long long &filesAmount)
{
    QDir directory(path);
    if (!directory.exists()) {
        qDebug() << "Directory does not exist!";
        return;
    }

    QStringList folderNames;
    directory.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &info : directory.entryInfoList()) {
        folderNames.append(info.fileName());
        directoriesAmount++;
    }

    directory.setFilter(QDir::Files);
    filesAmount += directory.entryList().count();
    for (auto suffix : folderNames) {
        Count(path + '/' + suffix, directoriesAmount, filesAmount);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filePath = "/home/vediz/LabsOAiP";
    direct = 0;
    files = 0;
    Count(filePath, direct, files);

    ui->label_fold->setText("Folders: " + QString::number(direct));
    ui->label_files->setText("Files: " + QString::number(files));

    model = new QFileSystemModel(this);
    model->setRootPath(filePath);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(filePath));
    ui->treeView->setHeaderHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString newpath = QFileDialog::getExistingDirectory(this, "Выберите папку", QDir::homePath());

    if (newpath.isEmpty())
        return;

    filePath = newpath;

    direct = 0;
    files = 0;
    Count(filePath, direct, files);

    ui->label_fold->setText("Folders: " + QString::number(direct));
    ui->label_files->setText("Files: " + QString::number(files));

    model->setRootPath(filePath);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(filePath));
    ui->treeView->setHeaderHidden(true);
}
