#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow {"
                        "background-image: url(:/new/prefix1/prefix1/FON_1.jpeg);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "}");
     setWindowTitle("Главное меню");
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_Exit_clicked()
{
    QApplication::exit();
}


void MainMenu::on_pushButton_Play_clicked()
{
    emit MainMenutoSaveMenuSignal();
    this->close();
}

void MainMenu::openMainMenu()
{
    this->showFullScreen();
}

