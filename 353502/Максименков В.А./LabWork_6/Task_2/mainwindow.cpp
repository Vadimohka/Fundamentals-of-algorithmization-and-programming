#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->firstConfirmButton, &QPushButton::clicked, this, &MainWindow::writeTextInFile);
    connect(ui->secondConfirmButton, &QPushButton::clicked, this, &MainWindow::writeMassiveInFile);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::writeTextInFile()
{
    QString s = ui->firstEdit->toPlainText();
    QFile file ("/home/vlad/QTprojects/Lab_6__Task_2/MaksimenkovLab20.txt");
    QTextStream fout (&file);

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    fout << s;
    file.close();

    readTextFromFile();
}


void MainWindow::readTextFromFile()
{
    QString ans;
    QFile file ("/home/vlad/QTprojects/Lab_6__Task_2/MaksimenkovLab20.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    ans = file.readLine();
    file.close();

    ui->firstBrowser->setText(ans);
}


void MainWindow::writeMassiveInFile()
{
    QFile file ("/home/vlad/QTprojects/Lab_6__Task_2/MaksimenkovLab20_0.txt");
    int sz = ui->massiveSpinBox->value();
    QString ans = ui->secondEdit->toPlainText();
    QTextStream fout (&file);

    int cnt = 1;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i] == '\n')
        {
            ans[i] = '=';
            ++cnt;
        }
    }

    if (cnt != sz)
    {
        ui->secondBrowser->setText("EROOR!!!");
        return;
    }
    else
    {
        ui->secondBrowser->setText("");
    }

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    fout << ans;
    file.close();

    readMassiveFromFile();
}


void MainWindow::readMassiveFromFile()
{
    QFile file ("/home/vlad/QTprojects/Lab_6__Task_2/MaksimenkovLab20_0.txt");
    QString ans = "";

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    ans = file.readLine();
    file.close();

    ui->secondBrowser->setText(ans);
}
