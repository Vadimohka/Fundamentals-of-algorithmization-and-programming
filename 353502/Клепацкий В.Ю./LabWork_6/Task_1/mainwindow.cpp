#include "mainwindow.h"
#include "Kinoserial.h"
#include "ui_mainwindow.h"

QString printKinoserial(Kinoserial Kinoserial)
{
    QString res = "";
    res += QString::number(Kinoserial.actors) + " | " + QString::number(Kinoserial.dengi) + " | "
           + Kinoserial.glavnu + " | " + (Kinoserial.end ? "true" : "false") + " | "
           + Kinoserial.name + " | " + QString::number(Kinoserial.medals[0]) + ","
           + QString::number(Kinoserial.medals[1]) + "," + QString::number(Kinoserial.medals[2]);

    return res;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Kinoserial Kinoserial{24, 75, 'm', false, "Стражи", {3, 1, 2}};

    ui->textEdit->setText(ui->textEdit->toPlainText() + "через инициализирующую строку:\n"
                          + printKinoserial(Kinoserial));

    Kinoserial Kinoserial2;
    Kinoserial2.actors = 34;
    Kinoserial2.dengi = 80;
    Kinoserial2.glavnu = 'm';
    Kinoserial2.end = true;
    strcpy(Kinoserial2.name, "Морские котики 9");
    Kinoserial2.medals[0] = 25;
    Kinoserial2.medals[1] = 45;
    Kinoserial2.medals[2] = 13;

    ui->textEdit->setText(ui->textEdit->toPlainText()
                          + "\nчерез инициализацию полей по отдельности:\n"
                          + printKinoserial(Kinoserial2));

    Kinoserial Kinoserial3;
    Kinoserial *KinoserialPointer = &Kinoserial3;
    KinoserialPointer->actors = 18;
    KinoserialPointer->dengi = 67;
    KinoserialPointer->glavnu = 'f';
    KinoserialPointer->end = false;
    strcpy(KinoserialPointer->name, "Король Артур");
    KinoserialPointer->medals[0] = 12;
    KinoserialPointer->medals[1] = 7;
    KinoserialPointer->medals[2] = 2;

    ui->textEdit->setText(ui->textEdit->toPlainText()
                          + "\nчерез инициализацию полей через указатель (->) по отдельности:\n"
                          + printKinoserial(*KinoserialPointer));

    Kinoserial Kinoserial4;

    (&Kinoserial4)->actors = 79;
    (&Kinoserial4)->dengi = 61;
    (&Kinoserial4)->glavnu = 'f';
    (&Kinoserial4)->end = false;
    strcpy((&Kinoserial4)->name, "Это сосна");
    (&Kinoserial4)->medals[0] = 203;
    (&Kinoserial4)->medals[1] = 145;
    (&Kinoserial4)->medals[2] = 103;

    ui->textEdit->setText(ui->textEdit->toPlainText()
                          + "\nчерез инициализацию полей через ссылку (->) по отдельности:\n"
                          + printKinoserial(*(&Kinoserial4)));

    connect(&dialog, &DialogInputData::accepted, this, &MainWindow::printInfoAboutNew);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    dialog.exec();
}

void MainWindow::printInfoAboutNew()
{
    Kinoserial Kinoserial = dialog.getKinoserial();

    ui->textEdit->setText(ui->textEdit->toPlainText()
                          + ((!ui->textEdit->toPlainText().isEmpty()) ? "\n" : "")
                          + printKinoserial(Kinoserial));
}
