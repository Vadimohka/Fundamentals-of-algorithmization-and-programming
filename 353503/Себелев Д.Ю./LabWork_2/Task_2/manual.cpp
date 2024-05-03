#include "manual.h"
#include "ui_manual.h"

#include <QFileDialog>
#include <QMessageBox>

Manual::Manual(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Manual)
{
    ui->setupUi(this);

    setWindowTitle("Manual");
    regex = QRegularExpression("(.*?),(\\d+),(\\d+)");

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->show();

    connect(ui->choose_manual_button, SIGNAL(clicked()), this, SLOT(ChooseManual()));
}

Manual::~Manual()
{
    delete ui;
}

int Manual::GetFuelConsumption(QString typeOfAirplane)
{
    for (auto &tmp : info)
    {
        if (tmp.GetTypeOfAirplane() == typeOfAirplane)
        {
            return tmp.GetFuelConsumption().toInt();
        }
    }
    return -1;
}

QStringList Manual::GetTypesOfAirplanes()
{
    QStringList typesOfAirplanes;
    for (auto &tmp : info)
    {
        typesOfAirplanes.push_back(tmp.GetTypeOfAirplane());
    }
    return typesOfAirplanes;
}

void Manual::ChooseManual()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Manual"), "", tr("Text Files (*.txt)"));
    ReadFromManual(filename);
}

void Manual::ReadFromManual(QString fileName)
{
    ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("File not opened"));
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QRegularExpressionMatch match = regex.match(line);
        if (match.hasMatch())
        {
            QString typeOfAirplane = match.captured(1);
            QString yearOfProduction = match.captured(2);
            QString fuelConsumption = match.captured(3);

            ManualTemplate temp(typeOfAirplane, yearOfProduction, fuelConsumption);
            if (temp.IsValid())
            {
                info.push_back(temp);
                ShowInTable(info.last());
            }
            else
            {
                QMessageBox::warning(this, tr("Error"), tr("Invalid line format in the file!"));
            }
        }
        else
        {
            QMessageBox::warning(this, tr("Error"), tr("Invalid line format in the file!"));
        }
    }
    file.close();

    emit FileHasBeenRead();
}

void Manual::ShowInTable(ManualTemplate tmp)
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

    auto *typeOfAirplane = new QTableWidgetItem(tmp.GetTypeOfAirplane());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, typeOfAirplane);

    auto *yearOfProd = new QTableWidgetItem(tmp.GetYearOfProduction());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, yearOfProd);

    auto *fuelConsumption = new QTableWidgetItem(tmp.GetFuelConsumption());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, fuelConsumption);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->show();
}
