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
    process1.start("bash", QStringList() << "-c" << "find " + mainDir + " -type d | wc -l");
    process1.waitForFinished(-1);

    QString output1(process1.readAllStandardOutput());
    int subFoldersCount = output1.trimmed().toInt();

    QProcess process2;
    process2.start("bash", QStringList() << "-c" << "find " + mainDir + " -type f | wc -l");
    process2.waitForFinished(-1);

    QString output2(process2.readAllStandardOutput());
    int filesCount = output2.trimmed().toInt();

    ui -> label -> setText("Количество подпапок: " + QString::number(subFoldersCount));
    ui -> label_3 -> setText("Общее количество файлов: " + QString::number(filesCount));
}


