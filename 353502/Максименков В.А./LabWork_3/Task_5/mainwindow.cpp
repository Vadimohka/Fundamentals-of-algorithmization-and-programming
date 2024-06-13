#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openDirectory);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openDirectory()
{
    sourceDir = QFileDialog::getExistingDirectory(this, tr("Открыть директорий"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QDir dir(sourceDir);

    if (dir.exists()) // если всё в порядке
    {
        ui->textBrowser->clear();
        ui->textBrowser->setText(dir.dirName());
        ui->label->setText(QString::number(countDirectories(dir)));
        ui->label_2->setText(QString::number(countFiles(dir, "|- ")));
    }
    else
    {
        QMessageBox::critical(this, "ERROR","Не удалось открыть директорий!!!"); // сообщение об ошибке открытия директория
    }
}


int MainWindow::countDirectories(QDir dir)
{
    int counter = 0;

    dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    QFileInfoList list = dir.entryInfoList();
    counter += list.size();

    for (const auto& newDir : list) // проход по list
    {
        QDir tempDir(newDir.absoluteFilePath());
        counter += countDirectories(tempDir);
    }

    return counter;
}


int MainWindow::countFiles(QDir dir, QString prefix)
{
    int counter = 0;

    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();

    for (const auto& fileInfo : list) // непосредственный подсчёт файлов в директории
    {
        if (fileInfo.isFile())
        {
            ui->textBrowser->append(prefix + fileInfo.fileName());
            ++counter;
        }
    }

    dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);  // Фильтр (специальный) для всех папок
    QFileInfoList dirList = dir.entryInfoList();

    for (const auto& newDir : dirList) // добавление к общему количеству
    {
        ui->textBrowser->append(prefix + newDir.fileName() + "/");

        QDir tempDir(newDir.absoluteFilePath());
        counter += countFiles(tempDir, "      " + prefix);
    }

    return counter;
}
