#include <QApplication>
#include <QDebug>
#include "QDir"
#include <QFile>
#include <QInputDialog>
#include "QMainWindow"
#include "QTextEdit"
#include "QTranslator"
#include <QPushButton>
#include "SportTeam/SportTeam.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFile stylesFile("/home/shosh/CourseProject/Course project/Styles/styles.qss");
    stylesFile.open(QIODevice::ReadWrite);
    QString style(stylesFile.readAll());
    a.setStyleSheet(style);
    auto *Main = new QMainWindow;
    SportTeam team1(style.toStdString());
    auto *TextScreen = new QTextEdit;
    Main->setCentralWidget(TextScreen);
    TextScreen->setReadOnly(true);
    TextScreen->setText(QString::number(team1.count_of_players) + "|" + QString(team1.isDinamoPinsk) + "|" + QString(team1.name) + "|" + QString::number(team1.coef_of_winning)+"|");
    for (int i : team1.count_of_GOOOOOOLS) {
        TextScreen->insertPlainText(QString::number(i));
    }
    SportTeam team2;
    team2.name[0] = 's';
    team2.name[1] = 'h';
    team2.name[2] = 'i';
    team2.name[3] = 'z';
    team2.name[4] = 'u';
    team2.name[5] = 'h';
    team2.name[6] = 'a';
    team2.name[7] = 'a';
    team2.name[8] = 'a';
    team2.name[9] = '\0';

    team2.coef_of_winning = 100;
    team2.isDinamoPinsk = false;
    team2.count_of_players = 56060;
    for (int i = 0; i < 10; i++) {
        team2.count_of_GOOOOOOLS[i] = i;
    }
    TextScreen->insertPlainText("\r" + (QString::number(team2.count_of_players) + "|" + QString(team2.isDinamoPinsk) + "|" + QString(team2.name) + "|" + QString::number(team2.coef_of_winning)+"|"));
    for (int i : team2.count_of_GOOOOOOLS) {
        TextScreen->insertPlainText(QString::number(i));
    }
    TextScreen->insertPlainText("\r");
    Main->show();
    auto *team3 = new SportTeam;
    team3->name[0] = 'n';
    team3->name[1] = 'e';
    team3->name[2] = 's';
    team3->name[3] = 'e';
    team3->name[4] = 'r';
    team3->name[5] = 'i';
    team3->name[6] = 'o';
    team3->name[7] = 'z';
    team3->name[8] = 'n';
    team3->name[9] = '\0';
    TextScreen->insertPlainText("\r" + (QString::number(team3->count_of_players) + "|" + QString(team3->isDinamoPinsk) + "|" + QString(team3->name) + "|" + QString::number(team3->coef_of_winning)+"|"));
    for (int i : team3->count_of_GOOOOOOLS) {
        TextScreen->insertPlainText(QString::number(i));
    }
    TextScreen->insertPlainText("\r");
    SportTeam team4;
    SportTeam &team4Address = team4;
    team4Address.name[0] = 'd';
    team4Address.name[1] = 'a';
    team4Address.name[2] = 'z';
    team4Address.name[3] = 'a';
    team4Address.name[4] = 'c';
    team4Address.name[5] = 'h';
    team4Address.name[6] = 't';
    team4Address.name[7] = 'o';
    team4Address.name[8] = 'a';
    team4Address.name[9] = '\0';
    team4Address.count_of_players = 0;
    team4Address.isDinamoPinsk = true;
    for (int i = 0; i < 10; i++) {
        team4Address.count_of_GOOOOOOLS[i] = i + 1000;
    }
    TextScreen->insertPlainText("\r" + (QString::number(team4Address.count_of_players) + "|" + QString(team4Address.isDinamoPinsk) + "|" + QString(team4Address.name) + "|" + QString::number(team4.coef_of_winning)+"|"));
    for (int i : team3->count_of_GOOOOOOLS) {
        TextScreen->insertPlainText(QString::number(i));
    }
    TextScreen->insertPlainText("\r");
    SportTeam team5;
    bool ok;
    int num = QInputDialog::getInt(Main, QObject::tr("Enter count of players rplssssss"), QObject::tr("Count of players"), QLineEdit::Normal);
    team5.count_of_players = num;
    bool isDinamoPinsk = QInputDialog::getInt(Main, QObject::tr("Enter if the given team is Dinamo Pinsk"), QObject::tr("Enter is your team Dinamo Pinsk. 1 stands for true"), QLineEdit::Normal, 2);
    isDinamoPinsk = false;
    team5.isDinamoPinsk = isDinamoPinsk;
    QString name = QInputDialog::getText(Main, QObject::tr("Enter name"), QObject::tr("Enter the name of team. No larger than 9 symbols"), QLineEdit::Normal);
    if (name.size() >= 9) {
    for (int i = 0; i < 9; i++) {
        team5.name[i] = name.at(i).toLatin1();
        }
    }
    else {
        for (int i = 0; i < name.size(); i++) {
            team5.name[i] = name.at(i).toLatin1();
        }
        for (int i = name.size(); i < 10; i++) {
            team5.name[i] = '\t';
        }
    }
    double coef_of_winning = QInputDialog::getDouble(Main, QObject::tr("biba"), QObject::tr("Enter the chance of your team winning"), QLineEdit::Normal, 0, 0);
    team5.name[9] = '\0';
    team5.coef_of_winning = coef_of_winning;
    for (int i = 0; i < 10; i++) {
        int GOOOOOL = QInputDialog::getInt(Main, QObject::tr("GOOOOOOOOOL"), QObject::tr("Count of GOOOOOOOOLS"), QLineEdit::Normal, -100, 0);
        team5.count_of_GOOOOOOLS[i] = GOOOOOL;
        qDebug() << GOOOOOL;
    }
    TextScreen->append("\r" + (QString::number(team5.count_of_players) + "|" + QString::number(team5.isDinamoPinsk) + "|" + QString(team5.name) + "|" + QString::number(team5.coef_of_winning)+"|"));
    for (int i : team5.count_of_GOOOOOOLS) {
        TextScreen->append(QString::number(i));
    }
    TextScreen->append("\r");
    return QApplication::exec();
}