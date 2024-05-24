#include "dialogaboutgame.h"
#include "ui_dialogaboutgame.h"

DialogAboutGame::DialogAboutGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAboutGame)
{
    ui->setupUi(this);

    setStyleSheet("DialogAboutGame {background-color: "
                  "qradialgradient(cx: 0.5, cy: 0.5, radius: 1, "
                  "fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(97, 166, 255, 255), stop: 1 rgba(34, 128, 255, 255)); }"

                  "QLabel {"
                  "color: white;"
                  "}"

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

}

DialogAboutGame::~DialogAboutGame()
{
    delete ui;
}
