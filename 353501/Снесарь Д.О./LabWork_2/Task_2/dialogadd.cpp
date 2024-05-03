#include "dialogadd.h"
#include "ui_dialogadd.h"


DialogAdd::DialogAdd(QVector<Flight>& flights, QVector<Plane>& planes):
    QDialog(nullptr),
    ui(new Ui::DialogAdd),
    flightsHere(flights),
    planesHere(planes)
{
    ui->setupUi(this);
    ui->PlaneTypeBox->clear();
    for(int i = 0; i < planesHere.size(); i++){
        ui->PlaneTypeBox->addItem(planesHere[i].getTypeString());
    }
    setWindowTitle("Add");
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::on_OkButton_clicked()
{
    bool validInput = true;

    QString flightNumberStr = ui->flightLabel->text();
    bool flightNumberOk;
    int flightNumber = flightNumberStr.toInt(&flightNumberOk);
    if (!flightNumberOk) {

        validInput = false;
    }




    QString distanceStr = ui->distanceLabel->text();
    bool distanceOk;
    double distance = distanceStr.toDouble(&distanceOk);
    if (!distanceOk) {

        validInput = false;
    }


    QString type = ui->PlaneTypeBox->currentText();
    if (type.isEmpty()) {

        validInput = false;
    }

    QString arriveTimeString = ui->ArriveTimeLabel->text();
    QDateTime arriveTime = QDateTime::fromString(arriveTimeString, "hh:mm");
    if (!arriveTime.isValid()) {

        validInput = false;
    }

    QString departureTimeString = ui->DepartureTimeLabel->text();
    QDateTime departureTime = QDateTime::fromString(departureTimeString, "hh:mm");
    if (!departureTime.isValid()) {

        validInput = false;
    }

    if (validInput) {
        QString destination = ui->destinationLabel->text();
        Flight addFlight(flightNumber, destination, distance, type, arriveTime, departureTime);
        flightsHere.push_back(addFlight);
        close();
    }
    else
        QMessageBox::warning(this, "Error", "Invalid input");
}


void DialogAdd::on_pushButton_2_clicked()
{
    close();
}

