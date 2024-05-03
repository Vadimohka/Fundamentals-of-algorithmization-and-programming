#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

constexpr qint16 NumOfColumns = 6;
constexpr qint16 Mult = 1000;

enum Columns
{
    Zero = 0,
    First,
    Second,
    Third,
    Fourth,
    Fifth,
    Sixth,
};

enum PartsOfInput
{
    NumOfRoute = 1,
    Destination,
    FlightRange,
    TypeOfAirplane,
    DepartureTime,
    LandingTime
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Schedule");
    ui->schedule->setColumnCount(NumOfColumns);
    ui->schedule->setHorizontalHeaderLabels(QStringList() << "Number of route"
                                                             << "Destination"
                                                             << "Flight range (km)"
                                                             << "Type of airplane"
                                                             << "Departure time"
                                                             << "Landing time");

    ui->schedule->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->schedule->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    regex = QRegularExpression(R"(^(\d+),\s([A-Za-z\s]+),\s(\d+),\s([A-Za-z\s\d]+),\s(\d{2}:\d{2}),\s(\d{2}:\d{2})$)");

    connect(ui->add_button, SIGNAL(clicked()), this, SLOT(AddToFile()));
    connect(ui->choose_schedule_button, SIGNAL(clicked()), this, SLOT(ChooseFile()));
    connect(ui->find_button, SIGNAL(clicked()), this, SLOT(Search()));
    connect(ui->reset_button, SIGNAL(clicked()), this, SLOT(ResetSearch()));
    connect(ui->calc_fuel_consump_button, SIGNAL(clicked()), this, SLOT(CalculateFuelConsumption()));
    connect(ui->edit_button, SIGNAL(clicked()), this, SLOT(Edit()));
    connect(ui->delete_button, SIGNAL(clicked()), this, SLOT(Delete()));
}

MainWindow::~MainWindow()
{
    delete ui;
    schedLines.clear();
    schedLines.shrink_to_fit();

}

void MainWindow::on_open_manual_button_clicked()
{
    manual = new Manual();
    connect(manual, SIGNAL(FileHasBeenRead()), this, SLOT(FillTypesOfAirplane()));
    manual->show();
}

void MainWindow::ChooseFile()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Schedule"), "", tr("Text Files (*.txt)"));
    if (!filename.isEmpty())
    {
        ReadFromFile(filename);
    }
}

void MainWindow::ReadFromFile(const QString &filepath) {
    ui->schedule->model()->removeRows(0, ui->schedule->rowCount());

    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QRegularExpressionMatch match = regex.match(line);
        if (match.hasMatch())
        {
            QString numOfRoute = match.captured(PartsOfInput::NumOfRoute);
            QString destination = match.captured(PartsOfInput::Destination);
            QString flightRange = match.captured(PartsOfInput::FlightRange);
            QString typeOfAirplane = match.captured(PartsOfInput::TypeOfAirplane);
            QString departureTime = match.captured(PartsOfInput::DepartureTime);
            QString landingTime = match.captured(PartsOfInput::LandingTime);

            ScheduleTemplate tmp(numOfRoute, destination, flightRange, typeOfAirplane, departureTime, landingTime);
            if (tmp.IsValid())
            {
                ui->schedule->setRowCount(ui->schedule->rowCount() + 1);
                schedLines.push_back(tmp);
                ShowInTable(schedLines.last(), ui->schedule->rowCount());
            }
            else
            {
                QMessageBox::warning(this, tr("Error"), tr("Incorrect format of string in file!"));
            }
        }
    }
    file.close();
}

void MainWindow::FillRowComboBox()
{
    ui->rowToEdit_comboBox->clear();
    ui->rowToDelete_comboBox->clear();
    for (int i = 1; i <= ui->schedule->rowCount(); ++i)
    {
        ui->rowToEdit_comboBox->addItem(QString::number(i));
    }

    for (int i = 1; i <= ui->schedule->rowCount(); ++i)
    {
        ui->rowToDelete_comboBox->addItem(QString::number(i));
    }
}

void MainWindow::CalculateFuelConsumption()
{
    TotalFuelConsumption = 0;
    if (!filename.isEmpty())
    {
        if (manual != nullptr && !manual->GetFileName().isEmpty())
        {
            for (auto &tmp : schedLines)
            {
                int FuelConsumptionPer1000Km = manual->GetFuelConsumption(tmp.GetTypeOfAirplane());

                if (FuelConsumptionPer1000Km != -1)
                {
                    double flightRange = tmp.GetFlightRange().toDouble();
                    double fuelConsumption = flightRange * FuelConsumptionPer1000Km / Mult;
                    TotalFuelConsumption += fuelConsumption;
                }
                else
                {
                    QMessageBox::warning(this, tr("Error"), tr("The total fuel consumption could not be calculated."
                                                                "\nThe type of airplane is not listed in the manual!"));
                }
            }

            QMessageBox::information(this, tr("Information"), tr("Total fuel consumption: %1 kg").arg(TotalFuelConsumption));
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("First, select the manual file!"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Error"), tr("First, select the schedule file!"));
    }
}

void MainWindow::Edit()
{
    int row = ui->rowToEdit_comboBox->currentText().toInt();

    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::Text | QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, tr("Error"), tr("File is not open!"));
            return;
        }

        if (!(ui->departure_time_edit->text().isEmpty()
              && ui->landing_time_edit->text().isEmpty()
              && ui->destination_edit->text().isEmpty()
              && ui->flight_range_edit->text().isEmpty()
              && ui->route_num_edit->text().isEmpty()))
        {
            QString numOfRoute = ui->route_num_edit->text();
            QString destination = ui->destination_edit->text();
            QString flightRange = ui->flight_range_edit->text();
            QString typeOfAirplane = ui->types_of_airplane_comboBox->currentText();
            QString departureTime = ui->departure_time_edit->text();
            QString landingTime = ui->landing_time_edit->text();

            ScheduleTemplate tmp(numOfRoute, destination, flightRange, typeOfAirplane, departureTime, landingTime);

            if (tmp.IsValid())
            {
                QFile file(filename);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QMessageBox::warning(this, tr("Error"), tr("File is not open!"));
                    return;
                }

                QTextStream in(&file);
                QStringList lines;
                while (!in.atEnd())
                {
                    lines.append(in.readLine());
                }
                file.close();

                if (row < lines.size())
                {
                    lines[row - 1] = QString("%1, %2, %3, %4, %5, %6")
                                     .arg(tmp.GetNumOfRoute(),
                                          tmp.GetDestination(),
                                          tmp.GetFlightRange(),
                                          tmp.GetTypeOfAirplane(),
                                          tmp.GetDepartureTime(),
                                          tmp.GetLandingTime());

                    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
                    {
                        QTextStream out(&file);
                        for (const QString &line : lines)
                        {
                            out << line << "\n";
                        }
                    }
                }
                schedLines[row - 1] = tmp;

                ShowInTable(schedLines[row - 1], row);
            }
            else
            {
                QMessageBox::warning(this, tr("Error"), tr("Incorrect input!"));
            }

            ui->route_num_edit->clear();
            ui->destination_edit->clear();
            ui->flight_range_edit->clear();
            ui->departure_time_edit->clear();
            ui->landing_time_edit->clear();

            file.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("Fill in all the fields above!"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Error"), tr("First, select the schedule file!"));
    }
}

void MainWindow::Delete()
{
    int row = ui->rowToDelete_comboBox->currentText().toInt();

    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::Text | QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, tr("Error"), tr("File is not open!"));
            return;
        }

        QTextStream in(&file);
        QStringList lines;
        while (!in.atEnd())
        {
            lines.append(in.readLine());
        }

        lines.removeAt(row - 1);

        file.resize(0);

        QTextStream out(&file);
        for (const QString &line : lines)
        {
            out << line << "\n";
        }
        file.close();

        ReadFromFile(filename);
    }
    else
    {
        QMessageBox::warning(this, tr("Error"), tr("First, select the schedule file!"));
    }
}

void MainWindow::FillTypesOfAirplane()
{
    QStringList listOfAirplanes = manual->GetTypesOfAirplanes();
    ui->types_of_airplane_comboBox->addItems(listOfAirplanes);
}

void MainWindow::ShowInTable(ScheduleTemplate tmp, int row)
{
    auto *NumOfRouteItem = new QTableWidgetItem(tmp.GetNumOfRoute());
    NumOfRouteItem->setFlags(NumOfRouteItem->flags() & ~Qt::ItemIsEditable);
    ui->schedule->setItem(row - 1, Columns::Zero, NumOfRouteItem);

    auto *DestinationItem = new QTableWidgetItem(tmp.GetDestination());
    DestinationItem->setFlags(DestinationItem->flags() & ~Qt::ItemIsEditable);
    ui->schedule->setItem(row - 1, Columns::First, DestinationItem);

    auto *FlightRangeItem = new QTableWidgetItem(tmp.GetFlightRange());
    FlightRangeItem->setFlags(FlightRangeItem->flags() & ~Qt::ItemIsEditable);
    ui->schedule->setItem(row - 1, Columns::Second, FlightRangeItem);

    auto *TypeOfAirplaneItem = new QTableWidgetItem(tmp.GetTypeOfAirplane());
    TypeOfAirplaneItem->setFlags(TypeOfAirplaneItem->flags() & ~Qt::ItemIsEditable);
    ui->schedule->setItem(row - 1, Columns::Third, TypeOfAirplaneItem);

    auto *DepartureTimeItem = new QTableWidgetItem(tmp.GetDepartureTime());
    DepartureTimeItem->setFlags(DepartureTimeItem->flags() & ~Qt::ItemIsEditable);
    ui->schedule->setItem(row - 1, Columns::Fourth, DepartureTimeItem);

    auto *LandingTimeItem = new QTableWidgetItem(tmp.GetLandingTime());
    LandingTimeItem->setFlags(LandingTimeItem->flags() & ~Qt::ItemIsEditable);
    ui->schedule->setItem(row - 1, Columns::Fifth, LandingTimeItem);

    FillRowComboBox();
}

void MainWindow::AddToFile()
{
    if (!(ui->departure_time_edit->text().isEmpty()
       && ui->landing_time_edit->text().isEmpty()
       && ui->destination_edit->text().isEmpty()
       && ui->flight_range_edit->text().isEmpty()
          && ui->route_num_edit->text().isEmpty()))
    {
        if (!filename.isEmpty())
        {
            QFile file(filename);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            {
                QMessageBox::warning(this, tr("Error"), tr("File not opened"));
                return;
            }

            QTextStream out(&file);

            QString numOfRoute = ui->route_num_edit->text();
            QString destination = ui->destination_edit->text();
            QString flightRange = ui->flight_range_edit->text();
            QString typeOfAirplane = ui->types_of_airplane_comboBox->currentText();
            QString departureTime = ui->departure_time_edit->text();
            QString landingTime = ui->landing_time_edit->text();

            ScheduleTemplate tmp(numOfRoute, destination, flightRange, typeOfAirplane, departureTime, landingTime);

            if (tmp.IsValid())
            {
                out << tmp.GetNumOfRoute() << ", " << tmp.GetDestination() << ", " << tmp.GetFlightRange() << ", "
                    << tmp.GetTypeOfAirplane() << ", " << tmp.GetDepartureTime() << ", " << tmp.GetLandingTime() << "\n";

                ui->schedule->setRowCount(ui->schedule->rowCount() + 1);
                ShowInTable(tmp, ui->schedule->rowCount());
            }
            else
            {
                QMessageBox::warning(this, tr("Error"), tr("Incorrect input!"));
            }
            file.close();

            ui->route_num_edit->clear();
            ui->destination_edit->clear();
            ui->flight_range_edit->clear();
            ui->departure_time_edit->clear();
            ui->landing_time_edit->clear();
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("First, select the schedule file!"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Error"), tr("Fill in all the fields!"));
    }
}

void MainWindow::Search()
{
    bool IsFind = false;

    if (!filename.isEmpty())
    {
        if (!ui->destin_to_find_edit->text().isEmpty())
        {
            QString destination = ui->destin_to_find_edit->text();

            for (int i = ui->schedule->rowCount() - 1; i >= 0; --i)
            {
                if (ui->schedule->item(i, 1)->text() != destination)
                {
                    ui->schedule->removeRow(i);
                }
                else
                {
                    IsFind = true;
                }
            }

            if (!IsFind)
            {
                QMessageBox::information(this, tr("Information"), tr("Destination not found!"));
                ResetSearch();
            }
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("Enter the destination!"));
            return;
        }
    }
    else
    {
        ui->destin_to_find_edit->clear();
        QMessageBox::warning(this, tr("Error"), tr("First, select the schedule file!"));
    }
}

void MainWindow::ResetSearch()
{
    if (!filename.isEmpty())
    {
        ui->destin_to_find_edit->clear();

        for (int i = ui->schedule->rowCount() - 1; i >= 0; --i)
        {
            ui->schedule->removeRow(i);
        }

        ReadFromFile(filename);
    }
    else
    {
        ui->destin_to_find_edit->clear();
        QMessageBox::warning(this, tr("Error"), tr("First, select the schedule file!"));
    }
}
