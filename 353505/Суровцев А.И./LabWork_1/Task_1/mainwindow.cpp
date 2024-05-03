#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    resize(780, 570);
    setFixedSize(780, 570);
    head = new hum_move(QPointF(25, 0), QSizeF(20, 20));
    hum = new hum_move(QPointF(20, 20), QSizeF(30, 60));
    rect = new movement(QPointF(25, 0), QSizeF(20, 20));
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        bool l = true;
        for (int i = 0; i< 7; ++i) {
            if (arr[i] == true) l = false;
        }
        if (!l) {
            ui->bntStart->setEnabled(false);
            ui->bntDown->setEnabled(false);
            ui->bntRight->setEnabled(false);
            ui->bntHandUp->setEnabled(false);
            ui->bntHonor->setEnabled(false);
            ui->bntHpS->setEnabled(false);
            ui->bntRect->setEnabled(false);
            ui->bntStart->setStyleSheet("background-color: red;");
            ui->bntDown->setStyleSheet("background-color: red;");
            ui->bntRight->setStyleSheet("background-color: red;");
            ui->bntHandUp->setStyleSheet("background-color: red;");
            ui->bntHonor->setStyleSheet("background-color: red;");
            ui->bntHpS->setStyleSheet("background-color: red;");
            ui->bntRect->setStyleSheet("background-color: red;");
        }
        else {
            ui->bntStart->setEnabled(true);
            ui->bntDown->setEnabled(true);
            ui->bntRight->setEnabled(true);
            ui->bntHandUp->setEnabled(true);
            ui->bntHonor->setEnabled(true);
            ui->bntHpS->setEnabled(true);
            ui->bntRect->setEnabled(true);
            ui->bntStart->setStyleSheet("background-color: green;");
            ui->bntDown->setStyleSheet("background-color: green;");
            ui->bntRight->setStyleSheet("background-color: green;");
            ui->bntHandUp->setStyleSheet("background-color: green;");
            ui->bntHonor->setStyleSheet("background-color: green;");
            ui->bntHpS->setStyleSheet("background-color: green;");
            ui->bntRect->setStyleSheet("background-color: green;");
        }
    });
    timer->start(25);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(music_path2));
    audioOutput->setVolume(50);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete hum;
    delete head;
    delete rect;
    delete audioOutput;
    delete player;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if (b2) {
        QPainter painter(this);
        painter.setBrush(Qt::darkBlue);
        painter.setPen(Qt::red);
        painter.drawRect(hum->getR());
        painter.drawRect(head->getR());
        painter.drawLine(hum->GetleftL());
        painter.drawLine(hum->GetleftH());
        painter.drawLine(hum->GetrightL());
        painter.drawLine(hum->GetrightH1());
        painter.drawLine(hum->GetrightH2());
    }
    else if (!b1) {
        QPainter painter(this);
        painter.setBrush(Qt::darkBlue);
        painter.setPen(Qt::red);
        painter.drawRect(hum->getR());
        painter.drawRect(head->getR());
        painter.drawLine(hum->GetleftL());
        painter.drawLine(hum->GetleftH());
        painter.drawLine(hum->GetrightL());
        painter.drawLine(hum->GetrightH());
    }
    else {
        QPainter painter(this);
        painter.setBrush(Qt::darkBlue);
        painter.setPen(Qt::red);
        painter.drawRect(rect->getR());
    }
}

void MainWindow::changeTrack(const QString &filePath)
{
    if (player && audioOutput) {
        player->stop();
        player->setSource(QUrl::fromLocalFile(filePath));
        player->play();
    }
}


void MainWindow::on_bntStart_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l = true;
    }
    if (!l) {
        arr[0] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[0] = false;
            t->stop();
            delete t;
        });

        t->start(5000);
        b2 = false;
        b1 = false;
        head->SetParams(QPointF(25, 0), QSizeF(20, 20));
        hum->SetParams(QPointF(20, 20), QSizeF(30, 60));
        hum->my_animation(QPointF(100, 300), 5000);
        head->my_animation(QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetleftH(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetleftL(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetrightL(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetrightH(), QPointF(100, 300), 5000);
        hum->circular_animation(&hum->GetrightH(), 5000, -15*M_PI);
    }
}


void MainWindow::on_bntDown_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l =true;
    }
    if (!l) {
        arr[1] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[1] = false;
            t->stop();
            delete t;
        });
        t->start(5000);
        b2 = false;
        b1 = false;
        head->SetParams(QPointF(25, 0), QSizeF(20, 20));
        hum->SetParams(QPointF(20, 20), QSizeF(30, 60));
        hum->my_animation(QPointF(0, 300), 5000);
        head->my_animation(QPointF(0, 300), 5000);
        hum->animation_line(&hum->GetleftH(), QPointF(0, 300), 5000);
        hum->animation_line(&hum->GetleftL(), QPointF(0, 300), 5000);
        hum->animation_line(&hum->GetrightL(), QPointF(0, 300), 5000);
        hum->animation_line(&hum->GetrightH(), QPointF(0, 300), 5000);
    }
}


void MainWindow::on_bntRight_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l =true;
    }
    if (!l) {
        arr[2] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[2] = false;
            t->stop();
            delete t;
        });
        t->start(5000);
        b2 = false;
        b1 = false;
        head->SetParams(QPointF(25, 0), QSizeF(20, 20));
        hum->SetParams(QPointF(20, 20), QSizeF(30, 60));
        hum->my_animation(QPointF(300, 0), 5000);
        head->my_animation(QPointF(300, 0), 5000);
        hum->animation_line(&hum->GetleftH(), QPointF(300, 0), 5000);
        hum->animation_line(&hum->GetleftL(), QPointF(300, 0), 5000);
        hum->animation_line(&hum->GetrightL(), QPointF(300, 0), 5000);
        hum->animation_line(&hum->GetrightH(), QPointF(300, 0), 5000);
    }
}


void MainWindow::on_bntHandUp_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l =true;
    }
    if (!l) {
        arr[3] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[3] = false;
            t->stop();
            delete t;
        });
        t->start(5000);
        b2 = false;
        b1 = false;
        head->SetParams(QPointF(25, 0), QSizeF(20, 20));
        hum->SetParams(QPointF(20, 20), QSizeF(30, 60));
        hum->circular_animation(&hum->GetrightH(), 5000, -15*M_PI);
    }
}


void MainWindow::on_bntHonor_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l =true;
    }
    if (!l) {
        arr[4] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[4] = false;
            t->stop();
            delete t;
        });
        t->start(5000);
        b2 = true;
        b1 = false;
        head->SetParams(QPointF(25, 0), QSizeF(20, 20));
        hum->SetParams(QPointF(20, 20), QSizeF(30, 60));
        hum->circular_animation(&hum->GetrightH2(), 5000, -11*M_PI);
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}


void MainWindow::on_bntHpS_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l =true;
    }
    if (!l) {
        arr[5] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[5] = false;
            t->stop();
            delete t;
        });
        t->start(5000);
        b2 = true;
        b1 = false;
        head->SetParams(QPointF(25, 0), QSizeF(20, 20));
        hum->SetParams(QPointF(20, 20), QSizeF(30, 60));
        hum->my_animation(QPointF(100, 300), 5000);
        head->my_animation(QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetleftH(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetleftL(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetrightL(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetrightH1(), QPointF(100, 300), 5000);
        hum->animation_line(&hum->GetrightH2(), QPointF(100, 300), 5000);
        hum->circular_animation(&hum->GetrightH2(), 5000, -11*M_PI);
    }
}


void MainWindow::on_bntRect_clicked()
{
    bool l = false;
    for (int i = 0; i< 7; ++i) {
        if (arr[i] == true) l = true;
    }
    if (!l) {
        arr[6] = true;
        QTimer *t = new QTimer();
        QObject::connect(t, &QTimer::timeout, [=](){
            arr[6] = false;
            t->stop();
            delete t;
        });
        t->start(5000);
        b1 = true;
        b2 = false;
        rect->setR(QRectF(QPointF(25, 0), QSizeF(20, 20)));
        rect->my_animation(QPointF(0, 350), 5000);
    }
}

void MainWindow::on_bnt_prikol_clicked()
{
    cnt_mus++;
    if (cnt_mus%2) changeTrack(music_path1);
    else changeTrack(music_path2);
}

