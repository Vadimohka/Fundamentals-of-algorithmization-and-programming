#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString ans;

    String s1 = "qwerty";
    String s2 = "string";

    ans = "s1 = " + s1.toQString() + "\n" + "s2 = " + s2.toQString();
    ans += "\n";
    ans += "\n";
    ans += "s1.size() = ";
    ans += QString::number(s1.size());
    ans += "\n";
    ans += "s2.size() = ";
    ans += QString::number(s2.size());

    ui->demonstratingBrowser->setText(ans);
}

MainWindow::~MainWindow()
{
    delete ui;
}
