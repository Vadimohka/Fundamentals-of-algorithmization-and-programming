#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent, QScreen *screen0)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_screen0(screen0)
{
    ui->setupUi(this);

    QCursor cursorRed = QCursor(QPixmap(":Curs"), 0, 0);
    this->setCursor(cursorRed);
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    m_balloon.Draw(&painter);
    painter.end();
    //connect(0, SIGNAL(clicked()), this, SLOT(Hit()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(MoveBalloon()));
    m_timer->start(10);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    float xl = this->mapFromGlobal(QCursor::pos()).x() - 387;
    float yl = this->mapFromGlobal(QCursor::pos()).y() - 255;
    float length = std::sqrt(xl* xl + yl * yl);
    if(length < 90){
        m_isHited = true;
    }
}

void MainWindow::MoveBalloon(){
    if(m_isHited){
        if(abs(m_balloon.m_posX) < 600 && abs(m_balloon.m_posY) < 600)
        {
            m_balloon.Move();
            update();
        }
    }
}
