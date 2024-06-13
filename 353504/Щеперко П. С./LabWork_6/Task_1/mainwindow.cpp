#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SportTeam Liverpool = {3, 20.3, 'A', true, "LIV", {67, 76, 9, 83, 53, 42, 1, 45, 84, 66, 4}};
    SportTeam BayernMunchen{};
    BayernMunchen.ratingPos = 2;
    BayernMunchen.winPercentage = 54.2;
    BayernMunchen.division = 'A';
    BayernMunchen.passedToChampionsLeague = true;
    BayernMunchen.nameAbbreviation[0] = 'B';
    BayernMunchen.nameAbbreviation[1] = 'A';
    BayernMunchen.nameAbbreviation[2] = 'Y';
    BayernMunchen.nameAbbreviation[3] = '\0';
    BayernMunchen.playersNumbers[0] = 9;
    BayernMunchen.playersNumbers[1] = 13;
    BayernMunchen.playersNumbers[2] = 7;
    BayernMunchen.playersNumbers[3] = 38;
    BayernMunchen.playersNumbers[4] = 27;
    BayernMunchen.playersNumbers[5] = 25;
    BayernMunchen.playersNumbers[6] = 10;
    BayernMunchen.playersNumbers[7] = 6;
    BayernMunchen.playersNumbers[8] = 41;
    BayernMunchen.playersNumbers[9] = 43;
    BayernMunchen.playersNumbers[10] = 26;
    PrintTeamInfo(BayernMunchen, ui->firstTeamLabel);
    SportTeam *ManchesterCity = new SportTeam{};
    ManchesterCity->ratingPos = 1;
    ManchesterCity->winPercentage = 99.0;
    ManchesterCity->division = 'A';
    ManchesterCity->passedToChampionsLeague = true;
    ManchesterCity->nameAbbreviation[0] = 'M';
    ManchesterCity->nameAbbreviation[1] = 'C';
    ManchesterCity->nameAbbreviation[2] = 'I';
    ManchesterCity->nameAbbreviation[3] = '\0';
    ManchesterCity->playersNumbers[0] = 9;
    ManchesterCity->playersNumbers[1] = 19;
    ManchesterCity->playersNumbers[2] = 47;
    ManchesterCity->playersNumbers[3] = 27;
    ManchesterCity->playersNumbers[4] = 17;
    ManchesterCity->playersNumbers[5] = 11;
    ManchesterCity->playersNumbers[6] = 3;
    ManchesterCity->playersNumbers[7] = 68;
    ManchesterCity->playersNumbers[8] = 5;
    ManchesterCity->playersNumbers[9] = 88;
    ManchesterCity->playersNumbers[10] = 33;
    PrintTeamInfo(*ManchesterCity, ui->secondTeamLabel);
    delete ManchesterCity;
    ManchesterCity = nullptr;
    SportTeam ParisSaintGermain{};
    SportTeam &ParisSaintGermainRef = ParisSaintGermain;
    ParisSaintGermainRef.ratingPos = 4;
    ParisSaintGermainRef.winPercentage = 67.7;
    ParisSaintGermainRef.division = 'A';
    ParisSaintGermainRef.passedToChampionsLeague = true;
    ParisSaintGermainRef.nameAbbreviation[0] = 'P';
    ParisSaintGermainRef.nameAbbreviation[1] = 'S';
    ParisSaintGermainRef.nameAbbreviation[2] = 'G';
    ParisSaintGermainRef.nameAbbreviation[3] = '\0';
    ParisSaintGermainRef.playersNumbers[0] = 30;
    ParisSaintGermainRef.playersNumbers[1] = 99;
    ParisSaintGermainRef.playersNumbers[2] = 1;
    ParisSaintGermainRef.playersNumbers[3] = 42;
    ParisSaintGermainRef.playersNumbers[4] = 5;
    ParisSaintGermainRef.playersNumbers[5] = 25;
    ParisSaintGermainRef.playersNumbers[6] = 3;
    ParisSaintGermainRef.playersNumbers[7] = 8;
    ParisSaintGermainRef.playersNumbers[8] = 9;
    ParisSaintGermainRef.playersNumbers[9] = 23;
    ParisSaintGermainRef.playersNumbers[10] = 17;

    PrintTeamInfo(ParisSaintGermainRef, ui->thirdTeamLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrintTeamInfo(SportTeam team, QLabel *label)
{
    QString teamInfo = "Rating position: " + QString::number(team.ratingPos) + '\n'
                       + "Win percentage: " + QString::number(team.winPercentage) + "%\n"
                       + "Division" + team.division + '\n'
                       + "Name abbreviation: " + team.nameAbbreviation + '\n' + "Players numbers:";
    for (qsizetype i = 0; i < TEAM_SIZE; ++i) {
        teamInfo += " " + QString::number(team.playersNumbers[i]);
    }
    teamInfo += '\n';
    label->setText(teamInfo);
}