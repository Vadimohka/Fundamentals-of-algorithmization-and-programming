#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    figures[0]=triangle;
    figures[1]=circle;
    figures[2]=rectangle;
    figures[3]=romb;
    figures[4]=s5;
    figures[5]=s6;
    figures[6]=s7;
    figures[7]=s8;
    figures[8]=hex;
    figures[9]=poly;
    square->make_sq();
    figures[10]=square;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TriangleButton_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    qDebug()<<"Triangle";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=0;
    }

}


void MainWindow::on_CircleButton_toggled(bool checked)
{
    qDebug()<<"Circle";
    figures[FigureID]->reset(sp);
    sp_status();
    qDebug()<<"Circle showpoint"<<figures[FigureID]->showpoint;
    update();
    qDebug()<<"Circle showpoint!"<<figures[FigureID]->showpoint;
    if(checked)
    {
        FigureID=1;
        ui->checkBox->setEnabled(true);
    }
    else
    ui->checkBox->setEnabled(false);

}


void MainWindow::on_RhombusButton_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    qDebug()<<"Rhombus";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=3;
    }
}


void MainWindow::on_RectangleButton_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    qDebug()<<"Rectangle";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=2;
    }
}


void MainWindow::on_Star5Button_toggled(bool checked)
{
    qDebug()<<"Star5";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=4;
    }
}


void MainWindow::on_Star6Button_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    qDebug()<<"Star6";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=5;
    }
}


void MainWindow::on_Star7Button_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    qDebug()<<"Star7";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=6;
    }
}


void MainWindow::on_Star8Button_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    qDebug()<<"Star8";
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=7;
    }
}


void MainWindow::on_HexagonButton_toggled(bool checked)
{
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=8;
    }
}


void MainWindow::on_PolylineButton_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=9;
    }
}


void MainWindow::on_SqauerButton_toggled(bool checked)
{
    ui->checkBox->setEnabled(false);
    figures[FigureID]->reset(sp);
    update();
    if(checked)
    {
        FigureID=10;
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(ui->DrawButton->isChecked())//Draw mode
    {
        figures[FigureID]->act=0;
        qDebug()<<"id: "<<FigureID;

        if(FigureID==0||FigureID==9)//triangle/polyline
        {
            figures[FigureID]->MouseMoving(event);
            update();
        }
        else figures[FigureID]->MousePressing(event);

    }
    else //Move mode (Fixed)
    {
        figures[FigureID]->act=1;
        qDebug()<<"MouseMovePressing";
        figures[FigureID]->MouseMovePressing(event);

    }
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(ui->DrawButton->isChecked()&&FigureID)
    {
        figures[FigureID]->MouseMoving(event);

    }
    else if(ui->MoveButton->isChecked())
    {
        qDebug()<<"MouseMoveMoving";
        figures[FigureID]->MouseMoveMoving(event);

    }
       update();

    GetInfo();
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    //qDebug()<<"paintEvent";
    QPainter painter(this);
    figures[FigureID]->draw(&painter);
    GetInfo();
}

void MainWindow::GetInfo()
{
    QPointF c=figures[FigureID]->center;
    double Sq=figures[FigureID]->S,Per=figures[FigureID]->P;

    ui->label_5->setText("x: " + QString::number(c.x(),'g',6) + " y:" + QString::number(c.y(),'g',3));
    ui->label_6->setText(QString::number(Sq,'g',10));
    ui->label_7->setText(QString::number(Per,'g',10));
}


void MainWindow::RotateLeft()
{
    figures[FigureID]->SetAngle(-1);
    figures[FigureID]->act=2;
    update();
    //GetInfo();
}


void MainWindow::RotateRight()
{
    figures[FigureID]->SetAngle(+1);
    figures[FigureID]->act=2;
    update();
    //GetInfo();
}


void MainWindow::on_LeftRotateButton_pressed()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(RotateLeft()));
    timer->start(5);
}


void MainWindow::on_LeftRotateButton_released()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(RotateLeft()));
    timer->stop();
}


void MainWindow::on_RightRotateButton_pressed()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(RotateRight()));
    timer->start(5);
}


void MainWindow::on_RightRotateButton_released()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(RotateRight()));
    timer->stop();
}


void MainWindow::SizeUp()
{
    figures[FigureID]->SizeEdit(false);
    figures[FigureID]->act=3;
    update();
    GetInfo();
}

void MainWindow::SizeDown()
{
    figures[FigureID]->SizeEdit(true);
    figures[FigureID]->act=3;
    update();
    GetInfo();
}


void MainWindow::on_PlusButton_pressed()
{
    qDebug()<<"PlusPressed";
    connect(timer,SIGNAL(timeout()),this,SLOT(SizeUp()));
    timer->start(5);
}

void MainWindow::on_PlusButton_released()
{
    qDebug()<<"PlusReleassed";
    disconnect(timer,SIGNAL(timeout()),this,SLOT(SizeUp()));
    timer->stop();
}

void MainWindow::on_MinusButton_pressed()
{
    qDebug()<<"MinusPressed";
    connect(timer,SIGNAL(timeout()),this,SLOT(SizeDown()));
    timer->start(5);
}

void MainWindow::on_MinusButton_released()
{
    qDebug()<<"MinusReleassed";
    disconnect(timer,SIGNAL(timeout()),this,SLOT(SizeDown()));
    timer->stop();
}


void MainWindow::on_ClearButton_clicked()
{
    figures[FigureID]->reset(sp);
    update();
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
        sp_status();
        update();
        qDebug()<<figures[FigureID]->showpoint<<" - showpoint_checkbox";
}

void MainWindow::sp_status()
{
    int arg1=ui->checkBox->checkState();
    if(arg1==2)figures[FigureID]->showpoint=sp=true,update();
    else
        figures[FigureID]->showpoint=sp=false,update();
}


