#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setObjects();
    animationTimer = new QTimer;
    QObject::connect(animationTimer, &QTimer::timeout, [=](){
        update();
        enableDisableButtons();
    });
    animationTimer->start(40);
    resetTimer = new QTimer;
    wasreseted = false;
    ui->Hint->setVisible(false);
    QFont numbersfont = ui->Floor1Number->font();
    numbersfont.setPointSize(20);
    ui->Floor1Number->setFont(numbersfont);
    ui->Floor2Number->setFont(numbersfont);
    ui->Floor3Number->setFont(numbersfont);
    ui->Hint->setText("Приложение для управления лифтом. Выполнил Могилевец Денис студент группы 353505.\n"
                      "При выполнении анимации какого-либо объекта (лифта или человека) другая анимация\n"
                      "этого же объекта запущена не будет.\n"
                      "Для того, чтобы лифт поехал на соответствующий этаж необходимо нажать\n"
                      "кнопку с номером этого этажа.\n"
                      "Для того, чтобы двери лифта открылись, необходимо нажать кнопку Открыть двери лифта.\n"
                      "Для того, чтобы двери лифта закрылись необходимо нажать кнопку Закрыть двеери лифта.\n"
                      "Для того, чтобы пассажир пришёл на этаж необходимо нажать кнопку Пассажир приходит на этаж.\n"
                      "Для того, чтобы пассажир ушёл с этажа, необходимо нажать на кнопку Пассажир уходит с этажа.\n"
                      "Для того, чтобы пассажир сел в лифт необходимо нажать кнопку Пассажир заходит в лифт.\n"
                      "Для того, чтобы человек вышел из лифта необходимо нажать кнопку Пассажир выходит из лифта.\n"
                      "В начвльном состоянии пассажир находится на подходе к первому этажу, лифт находится на\n"
                      "первом этаже.\n"
                      "Лифт не ездит с открытыми дверями.\n"
                      "Пассажир не заходит в лифт с закрытыми дверями.\n"
                      "Пассажир не уходит с этажа, пока не выйдет из лифта.\n"
                      "Пассажир не заходит в лифт, пока не придёт на этаж.\n"
                      "Пассажир не выходит из лифта с закрытыми дверями.");
    this->setWindowTitle("Лифт");

    ui->inelevator->setStyleSheet("QPushButton {"
                                  "  background-color: #008631;"
                                  "  color: #83F28F;"
                                  "}"
                                  "QPushButton:disabled {"
                                  "  background-color: #CCCCCC;"
                                  "  color: #666666;"
                                  "}");

    ui->outelevator->setStyleSheet("QPushButton {"
                                   "  background-color: #008631;"
                                   "  color: #83F28F;"
                                   "}"
                                   "QPushButton:disabled {"
                                   "  background-color: #CCCCCC;"
                                   "  color: #666666;"
                                   "}");
    ui->onfloor->setStyleSheet("QPushButton {"
                               "  background-color: #008631;"
                               "  color: #83F28F;"
                               "}"
                               "QPushButton:disabled {"
                               "  background-color: #CCCCCC;"
                               "  color: #666666;"
                               "}");
    ui->outfloor->setStyleSheet("QPushButton {"
                                "  background-color: #008631;"
                                "  color: #83F28F;"
                                "}"
                                "QPushButton:disabled {"
                                "  background-color: #CCCCCC;"
                                "  color: #666666;"
                                "}");
    ui->Floor1Button->setStyleSheet("QPushButton {"
                                    "  background-color: #008631;"
                                    "  color: #83F28F;"
                                    "}"
                                    "QPushButton:disabled {"
                                    "  background-color: #CCCCCC;"
                                    "  color: #666666;"
                                    "}");
    ui->Floor2Button->setStyleSheet("QPushButton {"
                                    "  background-color: #008631;"
                                    "  color: #83F28F;"
                                    "}"
                                    "QPushButton:disabled {"
                                    "  background-color: #CCCCCC;"
                                    "  color: #666666;"
                                    "}");
    ui->Floor3Button->setStyleSheet("QPushButton {"
                                    "  background-color: #008631;"
                                    "  color: #83F28F;"
                                    "}"
                                    "QPushButton:disabled {"
                                    "  background-color: #CCCCCC;"
                                    "  color: #666666;"
                                    "}");
    ui->callElevator->setStyleSheet("QPushButton {"
                                    "  background-color: #008631;"
                                    "  color: #83F28F;"
                                    "}"
                                    "QPushButton:disabled {"
                                    "  background-color: #CCCCCC;"
                                    "  color: #666666;"
                                    "}");

}

MainWindow::~MainWindow()
{
    delete elevator;
    delete animationTimer;
    delete ui;
    delete passenger;
    delete resetTimer;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QColor(186, 255, 232));
    painter.drawRect(QRectF(QPoint(0, 0), this->size()));
    if (passenger->checkIsInsideElevator()) {
        elevator->drawCorp(painter);
        passenger->draw(painter);
        elevator->drawDoors(painter);
    }
    else {
        elevator->drawCorp(painter);
        elevator->drawDoors(painter);
        passenger->draw(painter);
    }
    painter.setPen(QPen(Qt::transparent));
    painter.setBrush(Qt::lightGray);
    painter.drawRect(QRectF(QPoint(1, 421), QSizeF(this->size().width(), 30)));
    painter.drawRect(QRectF(QPoint(1, 271), QSizeF(this->size().width(), 30)));
    painter.drawRect(QRectF(QPoint(1, 121), QSizeF(this->size().width(), 30)));
}


void MainWindow::on_Floor1Button_clicked()
{
    if (wasreseted) return;
    elevator->goToFloor(1);
    if (passenger->checkIsInsideElevator()) {
        passenger->goToFloor(1);
    }
}


void MainWindow::on_Floor2Button_clicked()
{
    if (wasreseted) return;
    elevator->goToFloor(2);
    if (passenger->checkIsInsideElevator()) {
        passenger->goToFloor(2);
    }
}


void MainWindow::on_Floor3Button_clicked()
{
    if (wasreseted) return;
    elevator->goToFloor(3);
    if (passenger->checkIsInsideElevator()) {
        passenger->goToFloor(3);
    }
}



void MainWindow::on_onfloor_clicked()
{
    if (wasreseted) return;
    passenger->comeOnFloor();
}


void MainWindow::on_outfloor_clicked()
{
    if (wasreseted) return;
    passenger->comeOutFloor();
}


void MainWindow::on_inelevator_clicked()
{
    if (wasreseted) return;
    if (elevator->checkDoors() && passenger->getCurrFloor() == elevator->getCurrFloor()) {
        passenger->goInElevator();
    }
}


void MainWindow::on_outelevator_clicked()
{
    if (wasreseted) return;
    if(elevator->checkDoors()) {
        passenger->goOutElevator();
    }
}


void MainWindow::setObjects()
{
    elevator = new Elevator(QPointF(100, 20), QSizeF(200, 100));
    passenger = new Passenger(QPointF(1060, 350), 1000, 5000, Qt::blue);
}

void MainWindow::enableDisableButtons()
{
    ui->onfloor->setDisabled(passenger->IsOnFloor() || passenger->CheckIsAnimating(0));
    ui->outfloor->setDisabled(!passenger->IsOnFloor() || passenger->CheckIsAnimating(0) ||
                              passenger->checkIsInsideElevator());
    ui->inelevator->setDisabled(passenger->checkIsInsideElevator() || !elevator->checkDoors() ||
                                passenger->CheckIsAnimating(0) || !passenger->IsOnFloor());
    ui->outelevator->setDisabled(!passenger->checkIsInsideElevator() || !elevator->checkDoors() ||
                                 passenger->CheckIsAnimating(0) || !passenger->IsOnFloor());

    ui->Floor1Button->setEnabled(passenger->checkIsInsideElevator() && elevator->getCurrFloor() != 1 &&
                                 !elevator->CheckIsAnimating(0));
    ui->Floor2Button->setEnabled(passenger->checkIsInsideElevator() && elevator->getCurrFloor() != 2 &&
                                 !elevator->CheckIsAnimating(0));
    ui->Floor3Button->setEnabled(passenger->checkIsInsideElevator() && elevator->getCurrFloor() != 3 &&
                                 !elevator->CheckIsAnimating(0));
    ui->callElevator->setEnabled(passenger->IsOnFloor() && !passenger->checkIsInsideElevator() &&
                                 elevator->getCurrFloor() != passenger->getCurrFloor());
}


void MainWindow::on_callElevator_clicked()
{
    elevator->goToFloor(passenger->getCurrFloor());
}

