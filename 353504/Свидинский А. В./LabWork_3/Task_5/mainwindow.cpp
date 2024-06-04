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
    QString mainDir = QFileDialog::getExistingDirectory(this, "Открыть", "../../");
    QProcess process1;
    process1.start("ls -lR " + mainDir + " | grep \"^d\"");
    process1.waitForFinished(-1);

    QString output1(process1.readAllStandardOutput());
    QStringList lines1 = output1.split("\n");
    int subFoldersCount = lines1.size() - 1;

    QProcess process2;
    process2.start("ls -lR " + mainDir + " | grep \"^-\"");
    process2.waitForFinished(-1);

    QString output2(process2.readAllStandardOutput());
    QStringList lines2 = output2.split("\n");
    int filesCount = lines2.size() - 1;

    ui -> label -> setText("Количество подпапок: " + QString::number(subFoldersCount));
    ui -> label_2 -> setText("Общее количество файлов: " + QString::number(filesCount));
}

