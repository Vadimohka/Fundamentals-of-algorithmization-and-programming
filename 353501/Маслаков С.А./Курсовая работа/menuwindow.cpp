
#include "menuwindow.h"
#include "ui_MenuWindow.h"
#include <QShortcut>
#include <QMessageBox>
#include <QRegularExpression>
#include "mainwindow.h"
#include "leaderboardwindow.h"
#include <QGraphicsPixmapItem>
MenuWindow::MenuWindow(int col,QString n,QWidget *parent) : QWidget(parent), ui(new Ui::MenuWindow) {
    ui->setupUi(this);
    colorIndex = col;
    name = n;
    if(name.isEmpty()){
        ui->loginLineEdit->setPlaceholderText("Enter username");
    }else{
        ui->loginLineEdit->setText(name);
    }
    ui->comboBox->setCurrentIndex(colorIndex);
    QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    ui->skinFrame->hide();
    connect(shortcut, &QShortcut::activated, this, &MenuWindow::openMainWindow);
    connect(ui->startBut, &QPushButton::clicked, this, &MenuWindow::openMainWindow);
    connect(ui->skinbut,&QPushButton::clicked, this,&MenuWindow::showSkinFrame);
    connect(ui->acceptSkinBut,&QPushButton::clicked, this,&MenuWindow::getSkinColor);
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&MenuWindow::changedColorOnCombobox);
    connect(ui->leaderBoardBut,&QPushButton::clicked,this,&MenuWindow::openLeaderBoardWindow);
}
void MenuWindow::openLeaderBoardWindow() {
    name = ui->loginLineEdit->text();
    leaderBoardWindow = new LeaderBoardWindow(colorIndex,name);
    this->close();
    leaderBoardWindow->show();
}
void MenuWindow::openMainWindow() {
    QString login = ui->loginLineEdit->text();

    // Check if the login and password are empty
    if (login.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter login.");
        return;
    }

    // Check if the login contains only letters, numbers, and underscores
    QRegularExpression loginRegex("^[a-zA-Z0-9_]+$");
    QRegularExpressionMatch loginMatch = loginRegex.match(login);
    if (!loginMatch.hasMatch()) {
        QMessageBox::warning(this, "Error", "Invalid login format. Only letters, numbers, and underscores are allowed.");
        return;
    }
    mainwindow = new MainWindow(colorIndex,login);
    this->close();
    mainwindow->show();
}
void MenuWindow::showSkinFrame() {
    ui->skinFrame->show();
    imagePath = ":/images/snakeUnit" + QString::number(colorIndex + 1) + "Head.png";
    qDebug() << imagePath;
    QPixmap pixmap(imagePath);
    ui->label->setPixmap(pixmap.scaled(50,50));
}
void MenuWindow::changedColorOnCombobox(int ind) {
    imagePath = ":/images/snakeUnit" +  QString::number(ind + 1) + "Head.png";
    qDebug() << imagePath;
    QPixmap pixmap(imagePath);
    ui->label->setPixmap(pixmap.scaled(50,50));
}
void MenuWindow::getSkinColor() {
    ui->skinFrame->hide();
    colorIndex = ui->comboBox->currentIndex();
    //qDebug() << color;
}
MenuWindow::~MenuWindow() {
    delete ui;
}
