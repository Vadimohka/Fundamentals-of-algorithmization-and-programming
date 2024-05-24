#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydateclass.h"

struct Date {
    int day;
    int month;
    int year;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{

    int day1 = ui->spinBox->value();
    int month1 = ui->spinBox_2->value();
    int year1 = ui->spinBox_3->value();

    int day2 = ui->spinBox_4->value();
    int month2 = ui->spinBox_5->value();
    int year2 = ui->spinBox_6->value();

    QString selectedFunction = ui->comboBox->currentText();

    MyDateClass dateClass;

    if (selectedFunction == "Duration") {
        int duration = dateClass.Duration(day1,month1,year1,day2,month2,year2);
        ui->textBrowser->setText(QString("Duration: %1 days").arg(duration));
    } else if (selectedFunction == "Next day") {
        QString nextDay = dateClass.NextDay(day1, month1, year1);
        ui->textBrowser->setText(QString("Next day is: %1").arg(nextDay));
    } else if (selectedFunction == "Previous Day") {
        QString previousDay = dateClass.PreviousDay(day1, month1, year1);
        ui->textBrowser->setText(QString("Previous day is: %1").arg(previousDay));

    } else if (selectedFunction == "How many dayes till your birthday") {
        int daysTillBirthday = dateClass.DaysTillYourBirthday(day1, month1, year1, day2, month2, year2);
        ui->textBrowser->setText(QString("Days till your birthday: %1").arg(daysTillBirthday));
    } else if (selectedFunction == "The number of the week") {
        short weekNumber = dateClass.WeekNumber(day1, month1, year1);
        ui->textBrowser->setText(QString("Week number: %1").arg(weekNumber));                                                                                                                                                                                // voprosiki nachalo i konec goda
    }
    else if (selectedFunction == "Is leap") {
        int isLeap = dateClass.IsLeap(year1);
        QString leapMessage = isLeap == 1 ? "true" : "false";
        ui->textBrowser->setText(QString("It is leap: ").append(leapMessage));
    }
    else {
        ui->textBrowser->setText("Invalid function selected");
    }
}


