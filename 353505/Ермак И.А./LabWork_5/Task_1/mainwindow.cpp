#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setSettings();
    SetStyleSheet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetStyleSheet() {
    this->setStyleSheet("background-color: #FADADD;"
                        "color: #EB5284;"
                        "font: 600 19px Times New Roman;"
                        );
    ui->bnt_0->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_1->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_2->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_3->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_4->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_5->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_6->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_7->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_8->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );

    ui->bnt_9->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_10->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_11->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_10->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_12->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_13->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_14->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_15->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_16->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_17->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_19->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_18->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );

    ui->bnt_20->setStyleSheet("QPushButton {"
                             "border-color: #C08081;"
                             "background-color: #F19CBB;"
                             "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                             "color: #EB5284;"
                             "}"
                             );

    ui->bnt_21->setStyleSheet("QPushButton {"
                             "border-color: #C08081;"
                             "background-color: #F19CBB;"
                             "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                             "color: #EB5284;"
                             "}"
                             );
    ui->bnt_22->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_23->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_24->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_25->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_26->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_27->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_28->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_29->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_30->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_31->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_10->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_32->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_33->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_34->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_35->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_36->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_37->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_38->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_39->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_40->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_41->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_42->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_43->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_44->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_45->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_46->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_47->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_48->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->bnt_49->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    ui->space->setStyleSheet("QPushButton {"
                              "border-color: #C08081;"
                              "background-color: #F19CBB;"
                              "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                              "color: #EB5284;"
                              "}"
                              );
    auto palette = ui->value_accur->palette();
    palette.setColor(palette.WindowText, Qt::blue);
    palette.setColor(palette.Light, QColor(255, 0, 0));
    palette.setColor(palette.Dark, QColor(0, 255, 0));
    ui->value_accur->setPalette(palette);
    ui->value_simb->setPalette(palette);
    ui->value_timer->setPalette(palette);
}



void MainWindow::setSettings() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLCD);
    startTime = QDateTime::currentMSecsSinceEpoch();
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->end, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeKeyboard(int)));
    setNewKeyboard();
}

void MainWindow::startTimer() {
    ui->value_timer->display(QString::number(0));
    ui->value_simb->display(QString::number(0));
    ui->value_accur->display(QString::number(0));
    timer->start(100);
    timerOn = true;
    startTime = QDateTime::currentMSecsSinceEpoch();
}

void MainWindow::stopTimer() {
    timerOn = false;
    timer->stop();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Результат");
    msgBox.setText("Время: " + QString::number(ui->value_timer->value()) + "\n"
                                                                          "Символы в минуту: "+ QString::number(ui->value_simb->value()) + "\n"
                                                                          "Точность: "+ QString::number(ui->value_accur->value()));
    msgBox.exec();
}

void MainWindow::updateLCD() {
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsedTime = currentTime - startTime;
    ui->value_timer->display(QString::number(elapsedTime / 1000.0));
    int simbol = 0;
    ui->value_simb->display(QString::number(simbol));
    int acc = 0;
    ui->value_accur->display(QString::number(acc));
}

void MainWindow::changeKeyboard(int index) {
    indexOfLanguage = index;
    setNewKeyboard();
}


QVector<QVector<QString>> MainWindow::getBelarusianKeyboard() {
    QVector<QVector<QString>> belarusianKeyboard = {

        {"ё", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "`", "\\",
            "caps", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э",
            "shift", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ".", "shift",
            "space"
        },

        {"Ё", "!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+",
            "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "`", "|",
            "caps", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э",
            "shift", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ":", "shift",
            "space"
        },

        {"Ё", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "`", "\\",
            "caps", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э",
            "shift", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift",
            "space"
        }
    };

    return belarusianKeyboard;
}

QVector<QVector<QString>> MainWindow::getGermanKeyboard() {
    QVector<QVector<QString>> germanKeyboard = {

        {"^", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+",
            "caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "#",
            "shift", "<", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "shift",
            "space"
        },

        {"°", "!", "\"", "§", "$", "%", "&", "/", "(", ")", "=", "?", "`",
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "*",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "'",
            "shift", ">", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "shift",
            "space"
        },

        {"^", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "+",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "#",
            "shift", "<", "Y", "X", "C", "V", "B", "N", "M", ",", ".", "-", "shift",
            "space"
        }
    };

    return germanKeyboard;
}

QVector<QVector<QString>> MainWindow::getFrenchKeyboard() {
    QVector<QVector<QString>> frenchKeyboard = {

        {"²", "&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")", "=",
            "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$",
            "caps", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "*",
            "shift", "<", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "shift",
            "space"
        },

        {"É", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+",
            "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "¨", "£",
            "caps", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "%", "µ",
            "shift", ">", "W", "X", "C", "V", "B", "N", "?", ".", "/", "§", "shift",
            "space"
        },

        {"²", "&", "É", "\"", "'", "(", "-", "È", "_", "Ç", "À", ")", "=",
            "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "^", "$",
            "caps", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "Ù", "*",
            "shift", "<", "W", "X", "C", "V", "B", "N", ",", ";", ":", "!", "shift",
            "space"
        }
    };

    return frenchKeyboard;
}

QVector<QVector<QString>> MainWindow::getEnglishKeyboard() {
    QVector<QVector<QString>> englishKeyboard = {

        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\",
            "caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'",
            "shift", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift",
            "space"
        },

        {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"",
            "shift", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift",
            "space"
        },

        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'",
            "shift", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift",
            "space"
        }
    };

    return englishKeyboard;
}

QVector<QVector<QString>> MainWindow::getChinesseKeyboard() {
    QVector<QVector<QString>> chinesseKeyboard = {

        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\",
            "caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'",
            "shift", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift",
            "space"
        },

        {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"",
            "shift", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift",
            "space"
        },

        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'",
            "shift", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift",
            "space"
        }
    };

    return chinesseKeyboard;
}

QVector<QVector<QString>> MainWindow::getArabicKeyboard() {
    QVector<QVector<QString>> arabicKeyboard = {

        {"ذ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "\\",
            "caps", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط",
            "shift", "ئ", "ء", "ؤ", "ر", "ى", "ة", "و", "ز", "ظ", ".", "shift",
            "space"
        },

        {"ّ", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "َ", "ً", "ُ", "ٌ", "لإ", "إ", "‘", "÷", "×", "؛", "<", ">", "|",
            "caps", "ِ", "ٍ", "]", "[", "لأ", "أ", "ـ", "،", "/", ":", "\"",
            "shift", "~", "ْ", "}", "{", "؟", ".", ",", "،", "؛", "٠", "shift",
            "space"
        },

        {"ذ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "\\",
            "caps", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط",
            "shift", "ئ", "ء", "ؤ", "ر", "ى", "ة", "و", "ز", "ظ", ".", "shift",
            "space"
        }
    };

    return arabicKeyboard;
}

QVector<QVector<QString>> MainWindow::getHebrewKeyboard() {
    QVector<QVector<QString>> hebrewKeyboard = {

        {";", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "ש", "ד", "ג", "כ", "\\",
            "caps", "ע", "י", "ח", "ל", "ך", "ף", ",", "ז", "ס", "ב", "ה",
            "shift", "נ", "מ", "צ", "ת", "ץ", ".", "ז", "ס", "ב", "ה", "shift",
            "space"
        },

        {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "ש", "ד", "ג", "כ", "|",
            "caps", "ע", "י", "ח", "ל", "ך", "ף", ",", "ז", "ס", "ב", "ה",
            "shift", "נ", "מ", "צ", "ת", "ץ", ".", "ז", "ס", "ב", "ה", "shift",
            "space"
        },

        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "ש", "ד", "ג", "כ", "\\",
            "caps", "ע", "י", "ח", "ל", "ך", "ף", ",", "ז", "ס", "ב", "ה",
            "shift", "נ", "מ", "צ", "ת", "ץ", ".", "ז", "ס", "ב", "ה", "shift",
            "space"
        }
    };

    return hebrewKeyboard;
}

void MainWindow::setNewKeyboard() {
    if (indexOfLanguage == 0) {
        currKeyboard = getBelarusianKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 1) {
        currKeyboard = getGermanKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 2) {
        currKeyboard = getFrenchKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 3) {
        currKeyboard = getEnglishKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    }
    else if (indexOfLanguage == 6) {
        currKeyboard = getHebrewKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    }
    else if (indexOfLanguage == 5) {
        currKeyboard = getArabicKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    }
    else if (indexOfLanguage == 4) {
        currKeyboard = getChinesseKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    }
    setNewBoard();
    ui->forText->clear();
    timer->stop();
    setFocus();
}

void MainWindow::setNewBoard() {
    int index;
    if (!onCaps && !onShift) index = 0;
    if (onShift) index = 1;
    if (onCaps) index = 2;

    QVector<QString> layout = currKeyboard[index];
    for (int i = 0; i < layout.size(); i++) {
        QString key = layout[i];
        QPushButton *button;
        if(i == layout.size() - 1){
            button = this->findChild<QPushButton *>("space");
            if (button) {
                button->setText(key);
            }
            break;
        }
        button = this->findChild<QPushButton *>("bnt_" + QString::number(i));
        if (button) {
            button->setText(key);
        }
    }
}


void MainWindow::on_openFile_clicked()
{
    ui->forText->clear();
    timer->stop();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), "//", tr("Text document (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error";
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    ui->forText->setText(text);
    string = text;
    setFocus();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        setPopularWords();
        generateText();
    }
    ui->forText->setFocus();
}

void MainWindow::setPopularWords()
{
    QStringList folderPaths = {":/popularwords/deutchWords.txt",
                               ":/popularwords/franceWords.txt",
                               ":/popularwords/arabianWords.txt",
                               ":/popularwords/englishWords.txt",
                               ":/popularwords/belarusianWords.txt",
                               ":/popularwords/herbewWords.txt",
                               ":/popularwords/chinasesWords.txt"};

    popularWords.resize(7);
    QString line;
    for (int i = 0; i < folderPaths.size(); ++i) {
        QFile file(folderPaths[i]);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Error" << folderPaths[i];
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            popularWords[i].push_back(line);
        }
        file.close();
    }
}

void MainWindow::generateText()
{
    QString randomText = "";
    int count_of_words = 50;
    if (indexOfLanguage == 2 || indexOfLanguage == 5 || indexOfLanguage == 6) {
        count_of_words = 13;
    }
    QRandomGenerator generator;
    for (int i = 0; i < count_of_words; ++i) {
        if (indexOfLanguage < popularWords.size()) {
            int wordIndex = generator.bounded(popularWords[indexOfLanguage].size());
            QString randomWord = popularWords[indexOfLanguage][wordIndex];
            randomText += randomWord;
            if (i < 99 && count_of_words != 13) {
                randomText += " ";
            }
        }
    }
    if (count_of_words == 13) {
        randomText += " ";
    }
    ui->forText->setText(randomText);
    string = randomText;
}

QPushButton *lastPressedButton = nullptr;


void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Tab)
    {
        return;
    }

    if (event->key() == Qt::Key_Shift) {
        onShift = true;
        setNewBoard();
        return;
    } else if (event->key() == Qt::Key_CapsLock) {
        onCaps = !onCaps;
        setNewBoard();
    } else if (event->key() == Qt::Key_Space) {
        onSpace = !onSpace;
        if (onSpace) {
        }
    } else {

        QString key = event->text();
        for (int i = 0; i < currKeyboard[0].size(); i++) {
            if (currKeyboard[0][i] == key || currKeyboard[1][i] == key || currKeyboard[2][i] == key) {
                QPushButton *button = this->findChild<QPushButton *>("bnt_" + QString::number(i));
                if (button) {
                    button->click();
                    ui->forText->setText(ui->forText->text() + button->text());
                }
                break;
            }
        }
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Shift) {
        onShift = false;
        setNewBoard();
    }
    if (event->key() == Qt::Key_Space) {
        onSpace = false;
    }

}

void MainWindow::changeColorOfText(const QColor &color)
{
    QPalette palette = ui->forText->palette();
    palette.setColor(QPalette::Text, color);
    ui->forText->setPalette(palette);
}

void MainWindow::checkIsCorrectSymbol(QString ch)
{
    if (indexOfText >= 30) {
        QString subStr = string.mid(30, string.size() - 30);
        string = subStr;
        indexOfText -= 30;
    }
    if (string[indexOfText] == ch[0]) {
        countCorrectSymbol++;
        changeColorOfText(Qt::green);
    }
    else {
        changeColorOfText(Qt::red);
    }
    countAllSymbol++;
    indexOfText++;
}
