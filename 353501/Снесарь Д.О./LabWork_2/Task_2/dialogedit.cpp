#include "dialogedit.h"
#include "ui_dialogedit.h"



DialogEdit::DialogEdit(QVector<Flight> &flights, QVector<Plane> &planes, int num):
    QDialog(nullptr),
    ui(new Ui::DialogEdit),
    flightsHere(flights),
    planesHere(planes)
{
    index = num;
    ui->setupUi(this);
    ui->PlaneType->clear();
    for(int i = 0; i < planesHere.size(); i++){
        ui->PlaneType->addItem(planesHere[i].getTypeString());
    }
    setWindowTitle("Edit");
    ui->numberL->setText(QString::number(flightsHere[num].getFlightNumber()));
    ui->depTimeL->setText(flightsHere[num].getDepartureTime().toString("hh:mm"));
    ui->arrTimeL->setText(flightsHere[num].getArriveTime().toString("hh:mm"));
    ui->distL->setText(QString::number(flightsHere[num].getDistance(), 'f' , 2));
    ui->destL->setText(flightsHere[num].getDestination());
}


DialogEdit::~DialogEdit()
{
    delete ui;
}

void DialogEdit::on_OkButton_2_clicked()
{
    bool validInput = true;

    QString flightNumberStr = ui->numberL->text();
    bool flightNumberOk;
    int flightNumber = flightNumberStr.toInt(&flightNumberOk);
    if (!flightNumberOk) {
        validInput = false;
    }

    QString destination = ui->destL->text();

    QString distanceStr = ui->distL->text();
    bool distanceOk;
    double distance = distanceStr.toDouble(&distanceOk);
    if (!distanceOk) {
        validInput = false;
    }

    QString type = ui->PlaneType->currentText();
    if (type.isEmpty()) {
        validInput = false;
    }

    QString arriveTimeString = ui->arrTimeL->text();
    QDateTime arriveTime = QDateTime::fromString(arriveTimeString, "hh:mm");
    if (!arriveTime.isValid()) {
        validInput = false;
    }

    QString departureTimeString = ui->depTimeL->text();
    QDateTime departureTime = QDateTime::fromString(departureTimeString, "hh:mm");
    if (!departureTime.isValid()) {
        validInput = false;
    }

    if (validInput) {
        Flight addFlight(flightNumber, destination, distance, type, arriveTime, departureTime);
        flightsHere[index] = addFlight;
        close();
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод");
    }
}


void DialogEdit::on_CancelButton_clicked()
{
    close();
}

