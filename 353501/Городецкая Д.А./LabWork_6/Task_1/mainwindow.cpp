#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Окно для просмотра данных");
    setFixedSize(650, 477);
    input = new Input();
    connect(input, &Input::buttonClicked, this, &MainWindow::handleButtonClicked);
    char speciesData[Animal::MAX_CHAR_ARRAY_SIZE] = "lion";
    for (int i = 0; i < Animal::MAX_CHAR_ARRAY_SIZE; ++i) {
        Animal::species[i] = speciesData[i];
    }

    for (int i = 0; i < Animal::MAX_INT_ARRAY_SIZE; ++i) {
        Animal::hoursOfSleep[i] = i + 1;
    }

    animal1 = {5, 200.0, 'C', true};
    animal2.age = 10;
    animal2.weight = 150.5;
    animal2.dietType = 'H';
    animal2.isMale = false;

    animalPtr->age = 3;
    animalPtr->weight = 100.0;
    animalPtr->dietType = 'O';
    animalPtr->isMale = true;

    animalRef.age = 8;
    animalRef.weight = 120.0;
    animalRef.dietType = 'C';
    animalRef.isMale = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bnt_printCurrRes_clicked()
{
    QString intArray;
    for (int i = 0; i < Animal::MAX_INT_ARRAY_SIZE; ++i) {
        animal1.hoursOfSleep[i] = i + 1;
        intArray += QString::number(Animal::hoursOfSleep[i]) + " ";
    }
    ui->ln_ans1->setText( QString::number(animal1.age) + " | " + QString::number(animal1.weight) + " | " +
                         animal1.dietType + " | " + (animal1.isMale ? "true" : "false") + " | " +
                         QString(reinterpret_cast<const QChar*>(Animal::species), Animal::MAX_CHAR_ARRAY_SIZE) + " | " +
                         intArray );

    ui->ln_ans3->setText( QString::number(animalPtr->age) + " | " + QString::number(animalPtr->weight) + " | " +
                         animalPtr->dietType + " | " + (animalPtr->isMale ? "true" : "false") + " | " +
                         QString(reinterpret_cast<const QChar*>(Animal::species), Animal::MAX_CHAR_ARRAY_SIZE) + " | " +
                         intArray );

    ui->ln_ans4->setText( QString::number(animalRef.age) + " | " + QString::number(animalRef.weight) + " | " +
                         animalRef.dietType + " | " + (animalRef.isMale ? "true" : "false") + " | " +
                         QString(reinterpret_cast<const QChar*>(Animal::species), Animal::MAX_CHAR_ARRAY_SIZE) + " | " +
                         intArray );
}


void MainWindow::on_bnt_input_clicked()
{
    input->setWindowModality(Qt::ApplicationModal);
    input->show();
}

void MainWindow::handleButtonClicked(Animal an)
{
    QString speciesString;
    for (int i = 0; i < Animal::MAX_CHAR_ARRAY_SIZE; ++i) {
        if (Animal::species[i] != ' ') {
            speciesString += Animal::species[i];
        }
    }

    QString hoursOfSleepString;
    for (int i = 0; i < Animal::MAX_INT_ARRAY_SIZE; ++i) {
        hoursOfSleepString += QString::number(Animal::hoursOfSleep[i]) + " ";
    }

    ui->ln_ans2->setText( QString::number(an.age) + " | " + QString::number(an.weight) + " | " +
                         QString(an.dietType) + " | " + (an.isMale ? "true" : "false") + " | " +
                         speciesString + " | " + hoursOfSleepString );
    ui->ln_ans1->setText( QString::number(animal1.age) + " | " + QString::number(animal1.weight) + " | " +
                         animal1.dietType + " | " + (animal1.isMale ? "true" : "false") + " | " +
                         QString(reinterpret_cast<const QChar*>(Animal::species), Animal::MAX_CHAR_ARRAY_SIZE) + " | " +
                         hoursOfSleepString );

    ui->ln_ans3->setText( QString::number(animalPtr->age) + " | " + QString::number(animalPtr->weight) + " | " +
                         animalPtr->dietType + " | " + (animalPtr->isMale ? "true" : "false") + " | " +
                         QString(reinterpret_cast<const QChar*>(Animal::species), Animal::MAX_CHAR_ARRAY_SIZE) + " | " +
                         hoursOfSleepString );

    ui->ln_ans4->setText( QString::number(animalRef.age) + " | " + QString::number(animalRef.weight) + " | " +
                         animalRef.dietType + " | " + (animalRef.isMale ? "true" : "false") + " | " +
                         QString(reinterpret_cast<const QChar*>(Animal::species), Animal::MAX_CHAR_ARRAY_SIZE) + " | " +
                         hoursOfSleepString );
}
