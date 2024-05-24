#include "mainmenu.h"
#include "dialogs/dialogaboutgame.h"
#include "qtimer.h"
#include "ui_mainmenu.h"


MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    setStyleSheet("MainMenu {background-color: "
                  "qradialgradient(cx: 0.5, cy: 0.5, radius: 1, "
                  "fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(97, 166, 255, 255), stop: 1 rgba(34, 128, 255, 255)); "
                  "color:white;}"


                  "QPushButton { "
                  "background: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(67, 149, 255, 255), stop: 1 rgba(14, 119, 255, 255)); "
                  "border: 1px solid #0E77FF; "
                  "color: white; "
                  "padding: 10px 20px; "
                  "border-radius: 8px; "
                  "} "

                  "QPushButton:hover { "
                  "background: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(88, 163, 255, 255), stop: 1 rgba(45, 137, 255, 255)); "
                  "} "

                  "QPushButton:pressed { "
                  "background: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(67, 149, 255, 255), stop: 1 rgba(14, 119, 255, 255)); "
                  "}"

                  );

    myShow();

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::myShow()
{
    QTimer::singleShot(10, this, SLOT(showMaximized()));
}

void MainMenu::on_playButton_clicked()
{
    emit play();
}


void MainMenu::on_aboutButton_clicked()
{
    DialogAboutGame dialog;
    dialog.setModal(true);
    dialog.exec();
}


void MainMenu::on_exitButton_clicked()
{
    close();
}

