#include "PlayerMenu.hpp"
#include "ui_PlayerMenu.h"

PlayerMenu::PlayerMenu(QString player1Name, QString player2Name, QColor player1Color, QColor player2Color, QWidget *parent)
    :QDialog(parent),
    ui(new Ui::PlayerMenu)
{
    ui->setupUi(this);

    ui->player1Label->setText("Player 1");
    ui->player1NameLabel->setText("Name:");
    ui->player1Name->setText(player1Name);
    ui->player1ColorLabel->setText("Color:");
    player1Pixmap_ = QPixmap(PLAYER_COLOR_LABEL_WIDTH, PLAYER_COLOR_LABEL_HEIGHT);
    player1Pixmap_.fill(QColor(player1Color));
    player1Color_ = player1Color;
    ui->player1Color->setPixmap(player1Pixmap_);

    ui->player2Label->setText("Player 2");
    ui->player2NameLabel->setText("Name:");
    ui->player2Name->setText(player2Name);
    ui->player2ColorLabel->setText("Color:");
    player2Pixmap_ = QPixmap(PLAYER_COLOR_LABEL_WIDTH, PLAYER_COLOR_LABEL_HEIGHT);
    player2Pixmap_.fill(player2Color);
    player2Color_ = player2Color;
    ui->player2Color->setPixmap(player2Pixmap_);


    QObject::connect( ui->player1Name, &QLineEdit::textChanged, this, &PlayerMenu::on_textChanged);
    QObject::connect( ui->player2Name, &QLineEdit::textChanged, this, &PlayerMenu::on_textChanged);
}

QColor PlayerMenu::getPlayer1Color(){
    return player1Color_;
}

QColor PlayerMenu::getPlayer2Color(){
    return player2Color_;
}

QString PlayerMenu::getPlayer1Name(){
    return ui->player1Name->text();
}

QString PlayerMenu::getPlayer2Name(){
    return ui->player2Name->text() ;
}


PlayerMenu::~PlayerMenu(){
    delete ui;
}

void PlayerMenu::on_player2Color_clicked(){
    QColorDialog qColorDialog_;
    qColorDialog_.setModal(true);
    qColorDialog_.exec();

    if(qColorDialog_.result() == QDialog::Accepted){
        QColor selectedColor = qColorDialog_.selectedColor();

        if(selectedColor != player1Color_ && selectedColor != QColor("blue") && selectedColor != QColor("lightGray")){
                player2Color_ = selectedColor;
                player2Pixmap_.fill(player2Color_);
                ui->player2Color->setPixmap(player2Pixmap_);
        }
    }
}

void PlayerMenu::on_player1Color_clicked(){
    QColorDialog qColorDialog_;
    qColorDialog_.setModal(true);
    qColorDialog_.exec();

    if(qColorDialog_.result() == QDialog::Accepted){
        QColor selectedColor = qColorDialog_.selectedColor();

        if(selectedColor != player2Color_ && selectedColor != QColor("blue") && selectedColor != QColor("lightGray")){
            player1Color_ = selectedColor;
            player1Pixmap_.fill(player1Color_);
            ui->player1Color->setPixmap(player1Pixmap_);
        }
    }
}

void PlayerMenu::on_textChanged(){
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!ui->player1Name->text().isEmpty() | !ui->player2Name->text().isEmpty());
}
