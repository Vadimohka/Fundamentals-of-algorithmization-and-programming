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

bool MainWindow::emptyCheck()
{
    if (s1.empty() || s2.empty()) {
        QMessageBox::information(this, "Warning", "There is an empty string! Operation cancelled");
        return true;
    }
    return false;
}

void MainWindow::update()
{
    ui->lineEdit->setText(QString(s1.data()));
    ui->lineEdit_2->setText(QString(s2.data()));
}

void MainWindow::on_pushButton_memcpy_clicked()
{
    stringFunctions::memcpy(s1.data(), s2.data(), stringFunctions::strlen(s1.data()));
    update();
}

void MainWindow::on_pushButton_memmove_clicked()
{
    stringFunctions::memmove(s1.data(), s2.data(), stringFunctions::strlen(s1.data()));
    update();
}

void MainWindow::on_pushButton_strcpy_clicked()
{
    stringFunctions::strcpy(s1.data(), s2.data());
    update();
}

void MainWindow::on_pushButton_strncpy_clicked()
{
    stringFunctions::strncpy(s1.data(), s2.data(), stringFunctions::strlen(s1.data()));
    update();
}

void MainWindow::on_pushButton_strcat_clicked()
{
    stringFunctions::strcat(s1.data(), s2.data());
    update();
}

void MainWindow::on_pushButton_strncmp_clicked()
{
    size_t i = stringFunctions::strncmp(s1.data(), s2.data(), stringFunctions::strlen(s1.data()));
    if (i == -1) {
        QMessageBox::information(this, "Result", "S1<S2");
    }
    if (i == 1) {
        QMessageBox::information(this, "Result", "S1>S2");
    }
    if (i == 0) {
        QMessageBox::information(this, "Result", "S1=S2");
    }
    update();
}

void MainWindow::on_pushButton_strncat_clicked()
{
    stringFunctions::strncat(s1.data(), s2.data(), stringFunctions::strlen(s1.data()));
    update();
}

void MainWindow::on_pushButton_memcmp_clicked()
{
    size_t i = stringFunctions::memcmp(s1.data(), s2.data(), stringFunctions::strlen(s1.data()) - 3);
    if (i == -1) {
        QMessageBox::information(this, "Result", "S1<S2");
    }
    if (i == 1) {
        QMessageBox::information(this, "Result", "S1>S2");
    }
    if (i == 0) {
        QMessageBox::information(this, "Result", "S1=S2");
    }
    update();
}

void MainWindow::on_pushButton_strtok_clicked()
{
    char *token = stringFunctions::strtok(s1.data(), s2.data());
    QString res;
    while (token != NULL) {
        res += QString(token) + QString('\n');
        token = stringFunctions::strtok(NULL, s2.data());
    }

    QMessageBox messageBox;
    messageBox.information(0, "Result", res);
}

void MainWindow::on_pushButton_memset_clicked()
{
    int t = ui->lineEdit_2->text().toInt();
    memset(s1.data(), t, s1.size());
    update();
}

void MainWindow::on_pushButton_strlen_clicked()
{
    QMessageBox::information(this,
                             "Result",
                             "s1: " + QString::number(stringFunctions::strlen(s1.data())) + "\n"
                                 + "s2: " + QString::number(stringFunctions::strlen(s2.data())));
}

void MainWindow::on_pushButton_strcmp_clicked()
{
    size_t i = stringFunctions::strcmp(s1.data(), s2.data());
    if (i == -1) {
        QMessageBox::information(this, "Result", "S1<S2");
    }
    if (i == 1) {
        QMessageBox::information(this, "Result", "S1>S2");
    }
    if (i == 0) {
        QMessageBox::information(this, "Result", "S1=S2");
    }
    update();
}

void MainWindow::on_pushButton_strerror_clicked()
{
    int t = ui->lineEdit->text().toInt();
    QMessageBox::information(this, "strerror", QString(stringFunctions::strerror(t)));
}

void MainWindow::on_pushButton_set1_clicked()
{
    s1 = ui->lineEdit_3->text().toStdString().c_str();
    update();
}

void MainWindow::on_pushButton_set2_clicked()
{
    s2 = ui->lineEdit_4->text().toStdString().c_str();
    update();
}

void MainWindow::on_pushButton_strcoll_clicked()
{
    size_t i = stringFunctions::strcoll(s1.data(), s2.data());
    if (i == -1) {
        QMessageBox::information(this, "Result", "S1<S2");
    }
    if (i == 1) {
        QMessageBox::information(this, "Result", "S1>S2");
    }
    if (i == 0) {
        QMessageBox::information(this, "Result", "S1=S2");
    }
    update();
}

void MainWindow::on_pushButton_strxfrm_clicked()
{
    int res = stringFunctions::mystrxfrm(s1.data(), s2.data(), stringFunctions::strlen(s1.data()));
    update();
    QMessageBox::information(this, "Result", QString::number(res));
}
