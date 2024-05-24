#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Files and folders counter");

    connect(ui->chooseFile_button, SIGNAL(clicked()), this, SLOT(ChooseFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CountFilesAndFoldersHelper(const QDir &dir, int &fileCount, int &folderCount, int level)
{
    QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Hidden | QDir::Dirs | QDir::AllDirs | QDir::NoSymLinks | QDir::Files);

    for (const QFileInfo& entry : entries)
    {
        ui->output_listWidget->addItem(QString(static_cast<qsizetype>(level) * 2, ' ') + "|- " + entry.fileName());

        if (entry.isDir())
        {
            folderCount++;
            CountFilesAndFoldersHelper(QDir(entry.absoluteFilePath()), fileCount, folderCount, level + 1);
        } else {
            fileCount++;
        }
    }
}

void MainWindow::CountFilesAndFolders(const QDir &dir)
{
    int fileCount = 0;
    int folderCount = 0;

    CountFilesAndFoldersHelper(dir, fileCount, folderCount, 0);

    ui->output_listWidget->addItem("Total number of files: " + QString::number(fileCount));
    ui->output_listWidget->addItem("Total number of folders: " + QString::number(folderCount));
}
void MainWindow::ChooseFile()
{
    ui->output_listWidget->clear();
    filepath = QFileDialog::getExistingDirectory(this, tr("Choose a directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!filepath.isEmpty())
    {
        dir = QDir(filepath);
        CountFilesAndFolders(dir);
    }
}
