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

void MainWindow::on_action_triggered()
{
    sourseDir = QFileDialog::getExistingDirectory(this,
                                                  tr("Открыть директорию"),
                                                  "",
                                                  QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    QDir dir(sourseDir);
    if (dir.exists()) {
        ui->textBrowser->clear();
        ui->textBrowser->setText(dir.dirName());
        ui->label_Dirs->setText(QString::number(countDirs(dir)));
        ui->label_Files->setText(QString::number(countFiles(dir, "|- ")));
    } else {
        QMessageBox::critical(this, "Ошибка", "Такой директории не существует!");
    }
}

int MainWindow::countDirs(QDir dir)
{
    int counter = 0;
    dir.setFilter(QDir::AllDirs | QDir::Hidden);
    QFileInfoList list = dir.entryInfoList();
    counter += list.size() - 2;

    for (const auto &newDir : list) {
        if (newDir.fileName() != "." && newDir.fileName() != "..") {
            QDir tempDir(newDir.absoluteFilePath());
            counter += countDirs(tempDir); //Рекурсия
        }
    }

    return counter;
}

int MainWindow::countFiles(QDir dir, QString prefix)
{
    int counter = 0;
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::Hidden);
    QFileInfoList list = dir.entryInfoList();
    counter += list.size() - 2;

    for (const auto &newDir : list) {
        if (newDir.fileName() != "." && newDir.fileName() != "..") {
            ui->textBrowser->append(prefix + newDir.fileName());
            if (newDir.isDir()) {
                QDir tempDir(newDir.absoluteFilePath());
                counter += countFiles(tempDir, "    " + prefix); //Рекурсия
            } else {
                counter++;
            }
        }
    }

    return counter;
}
