#include "mainwindow.h"
#include "ui_mainwindow.h"

QString printSportsman(Sportsman sportsman)
{
    QString res = "";
    res += QString::number(sportsman.age) + " | " +
           QString::number(sportsman.weight) + " | " +
           sportsman.sex + " | " +
           (sportsman.isJock ? "true" : "false") + " | " +
           sportsman.name + " | " +
           QString::number(sportsman.medals[0]) + "," + QString::number(sportsman.medals[1]) + "," + QString::number(sportsman.medals[2]);

    return res;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Sportsman sportsman{24, 75, 'm', false, "Dmitry", {3, 1, 2}};

    ui->textEdit->setText(ui->textEdit->toPlainText() + "через инициализирующую строку:\n" + printSportsman(sportsman));

    Sportsman sportsman2;
    sportsman2.age = 34;
    sportsman2.weight = 80;
    sportsman2.sex = 'm';
    sportsman2.isJock = true;
    strcpy(sportsman2.name, "Vyacheslav");
    sportsman2.medals[0] = 25;
    sportsman2.medals[1] = 45;
    sportsman2.medals[2] = 13;

    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nчерез инициализацию полей по отдельности:\n" + printSportsman(sportsman2));

    Sportsman sportsman3;
    Sportsman* sportsmanPointer = &sportsman3;
    sportsmanPointer->age = 18;
    sportsmanPointer->weight = 67;
    sportsmanPointer->sex = 'f';
    sportsmanPointer->isJock = false;
    strcpy(sportsmanPointer->name, "Elizaveta");
    sportsmanPointer->medals[0] = 12;
    sportsmanPointer->medals[1] = 7;
    sportsmanPointer->medals[2] = 2;

    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nчерез инициализацию полей через указатель (->) по отдельности:\n" + printSportsman(*sportsmanPointer));


    Sportsman sportsman4;

    (&sportsman4)->age = 79;
    (&sportsman4)->weight = 61;
    (&sportsman4)->sex = 'f';
    (&sportsman4)->isJock = false;
    strcpy((&sportsman4)->name, "Anna");
    (&sportsman4)->medals[0] = 203;
    (&sportsman4)->medals[1] = 145;
    (&sportsman4)->medals[2] = 103;

    ui->textEdit->setText(ui->textEdit->toPlainText() + "\nчерез инициализацию полей через ссылку (->) по отдельности:\n" + printSportsman(*(&sportsman4)));


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
    Sportsman sportsman = dialog.getSportsman();

    ui->textEdit->setText(ui->textEdit->toPlainText() + ((!ui->textEdit->toPlainText().isEmpty()) ? "\n" : "") + printSportsman(sportsman));
}

