#include "mainwindow.h"
#include "ui_mainwindow.h"
\
int MainWindow::Movie::ratings[NUM_ARRAY_SIZE] = {0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClick() {
    movie.id = ui->idLineEdit->text().toInt();
    movie.rating = ui->ratingLineEdit->text().toDouble();
    movie.genre = ui->genreLineEdit->text().toStdString()[0];
    movie.isAvailable = ui->isAvailableCheckBox->isChecked();
    strncpy(movie.title, ui->titleLineEdit->text().toStdString().c_str(), Movie::TITLE_SIZE);

    QString output = QString(movie.title) + "|" + QString::number(movie.id) + "|" + movie.genre + "|" + QString::number(movie.rating) +
                     "|" + (movie.isAvailable ? "Доступен" : "Не доступен") + "\n";

    intializate(output);
}


void MainWindow::printMovie(QString output) {

    ui->textEdit->setPlainText(output);
}


void MainWindow::intializate(QString output) {

    Movie movie1 = {1, 8.5, 'A', true, "Inception"};
    output += QString(movie1.title) + "|" + QString::number(movie1.id) + "|" + movie1.genre + "|" + QString::number(movie1.rating) +
                     "|" + (movie1.isAvailable ? "Доступен" : "Не доступен") + "\n";

    Movie movie2;
    movie2.id = 2;
    movie2.rating = 9.0;
    movie2.genre = 'B';
    movie2.isAvailable = false;
    strcpy(movie2.title, "The Dark Knight");
    output += QString(movie2.title) + "|" + QString::number(movie2.id) + "|" + movie2.genre + "|" + QString::number(movie2.rating) +
             "|" + (movie2.isAvailable ? "Доступен" : "Не доступен") + "\n";

    Movie movie3;
    Movie* pMovie3 = &movie3;
    pMovie3->id = 3;
    pMovie3->rating = 7.8;
    pMovie3->genre = 'C';
    pMovie3->isAvailable = true;
    strcpy(pMovie3->title, "Interstellar");
    output += QString(movie3.title) + "|" + QString::number(movie3.id) + "|" + movie3.genre + "|" + QString::number(movie3.rating) +
             "|" + (movie3.isAvailable ? "Доступен" : "Не доступен") + "\n";

    Movie movie4;
    Movie& refMovie4 = movie4;
    refMovie4.id = 4;
    refMovie4.rating = 8.7;
    refMovie4.genre = 'D';
    refMovie4.isAvailable = false;
    strcpy(refMovie4.title, "Dunkirk");
    output += QString(movie4.title) + "|" + QString::number(movie4.id) + "|" + movie4.genre + "|" + QString::number(movie4.rating) +
             "|" + (movie4.isAvailable ? "Доступен" : "Не доступен") + "\n";

    printMovie(output);
}
