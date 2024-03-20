#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    fgr = new ffTriangle;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ticks()));
    timer->start(10);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ticks()
{
    if(fgr != nullptr)
    {
        ui->label_10->setText("Центр масс : " + QString::number(fgr->massCenter.rx()) + ", " + QString::number(fgr->massCenter.ry()));

        ui->label->setText("Площадь : " + QString::number(fgr->area));
        ui->label_2->setText("Периметр : " + QString::number(fgr->perimetr));

        if(msPressed == true)
        {
            if(ui->comboBox_2->currentIndex() == 0)
            {
                msNow = QCursor::pos();
                fgr->setPoints(msBeg, msNow);

                fgr->findArea();
                fgr->findPerimetr();
            }

            if(ui->comboBox_2->currentIndex() == 1)
            {
                msmNow = QCursor::pos();

                QPoint delta = msmNow - msmBeg;

                fgr->move(delta);

                msmBeg = msmNow;
            }
        }

        if((ui->comboBox_2->currentIndex() == 2) && (gradBeg != gradNow))
        {
            if(gradBeg < gradNow)
            {
                fgr->rotatePoint(rotatePoint, 1);
                gradBeg += 1;
            }
            else
            {
                fgr->rotatePoint(rotatePoint, -1);
                gradBeg -= 1;
            }
        }

        if(scaleChange != 0)
        {
            if(scaleChange > 0)
            {
                fgr->scalingPoint(1);
                scaleChange--;
            }
            else if(fgr->area > 1000)
            {
                fgr->scalingPoint(-1);
                scaleChange++;
            }
            else
            {
                scaleChange = 0;
            }

            fgr->findArea();
            fgr->findPerimetr();
        }
    }
    update();
}

void Widget::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);

    QPainter painter(this);

    if(fgr != nullptr)
    {
        if(ui->comboBox_2->currentIndex() == 2)
            painter.drawEllipse(rotatePoint, 3, 3);

        painter.setBrush(Qt::red);
        painter.drawEllipse(fgr->massCenter, 3, 3);
        painter.setBrush(Qt::NoBrush);

        fgr->draw(&painter);
    }
}

void Widget::mousePressEvent(QMouseEvent *me)
{
    Q_UNUSED(me);

    if(ui->comboBox_2->currentIndex() == 0)
    {
        msBeg = QCursor::pos();
    }
    if(ui->comboBox_2->currentIndex() == 1)
    {
        msmBeg = QCursor::pos();
    }
    if(ui->comboBox_2->currentIndex() == 2)
    {
        rotatePoint = QCursor::pos();
    }
    msPressed = true;
}

void Widget::mouseReleaseEvent(QMouseEvent *me)
{
    Q_UNUSED(me);

    msPressed = false;
}

void Widget::on_pushButton_clicked()
{
    gradNow = ui->spinBox->value();
}


void Widget::on_comboBox_currentIndexChanged(int index)
{
    if(fgr != nullptr)
    {
        delete fgr;

        fgr = nullptr;
    }

    if(index == 0)
        fgr = new ffTriangle;
    if(index == 1)
        fgr = new ffCircle;
    if(index == 2)
        fgr = new ffRomb;
    if(index == 3)
        fgr = new ffSquare;
    if(index == 4)
        fgr = new ffRect;
    if(index == 5)
        fgr = new ffStar(5);
    if(index == 6)
        fgr = new ffStar(6);
    if(index == 7)
        fgr = new ffStar(8);
    if(index == 8)
        fgr = new ffNanglyy(6);
    if(index == 9)
        fgr = new ffNanglyy(8);

}


void Widget::on_pushButton_2_clicked()
{
    scaleChange = ui->spinBox_2->value();
}

