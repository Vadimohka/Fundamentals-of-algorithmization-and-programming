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

void fun(QDir& dir, int& kol_file, int& kol_dir) {
    QFileInfoList file = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (QFileInfo& a : file) {
        if (a.isDir()) {
            kol_dir++;
            QDir dir_2(a.filePath());
            fun(dir_2, kol_file, kol_dir);
        }
        else if (a.isFile())  kol_file++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString gl_dir = QFileDialog::getExistingDirectory(this, "Открыть", "/home/vlad");
    QDir dir(gl_dir);
    int a = 0, b = 0;
    fun(dir, b, a);
    ui -> label -> setText("Количество подпапок: " + QString::number(a));
    ui -> label_2 -> setText("Количество файлов: " + QString::number(b));
}

