#include "mainwindow.h"
#include "ui_mainwindow.h"


char Airport::name[50] = "Unknown Airport";
int Airport::numberOfTerminals[5] = {0};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->classBox->addItems({"A", "B", "C"});



        // Initialization with a string
        Airport airport1 = {2005, 15.3, 'M', true};

        // Initialization of individual fields
        Airport airport2;
        airport2.yearOpened = 1980;
        airport2.averageDelay = 5.8;
        airport2.iataCode = 'S';
        airport2.operates24Hours = false;

        // Outputting values


        // User input
        Airport airport3;


        // Working with a pointer
        Airport airport4;
        Airport* ptrAirport = &airport4;
        ptrAirport->yearOpened = 1995;
        ptrAirport->averageDelay = 10.2;
        ptrAirport->iataCode = 'K';
        ptrAirport->operates24Hours = true;



        // Working with a reference
        Airport airport5;
        Airport& refAirport = airport5;
        refAirport.yearOpened = 2010;
        refAirport.averageDelay = 7.5;
        refAirport.iataCode = 'D';
        refAirport.operates24Hours = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newAirportButton_clicked()
{
    QString name = ui->airportEdit->text();
    if (name.size() > 0 && name.size() < 30){
        //Airport::name[50] = name.toLocal8Bit().data();
        std::copy(name.toStdString().begin(),name.toStdString().end(),Airport::name);
        Airport* airport = new Airport{ui->yaerBox->text().toInt(), ui->DelayBox->text().toDouble(), ui->iataBox->text().toStdString()[0] ,ui->workRadio->isCheckable()};
        update(*airport);
    }
}

void MainWindow::update(Airport& current)
{
    ui->airportName->setText(QString::fromUtf16(reinterpret_cast<const ushort*>(Airport::name)));
    ui->airportYear->setText(QString::number(current.yearOpened));
}

