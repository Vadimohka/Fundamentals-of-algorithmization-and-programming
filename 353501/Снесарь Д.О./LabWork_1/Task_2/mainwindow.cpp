#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lastMousePoint = QPointF(0, 0);
    ui->spinBox->setMinimum(5);
    ui->spinBox->setMaximum(8);
    timer = new QTimer;
    ui->squareLabel->setText(QString(" S = "));
    ui->perimetrLabel->setText(QString(" P = "));
    ui->xPointLabel->setText(QString(" X = "));
    ui->yPointLabel->setText(QString(" Y = "));

}


void MainWindow::paintEvent(QPaintEvent *pe){
    QPainter painter(this);
    if(mFigure != nullptr)
    {
        mFigure -> draw(&painter);
        ui->squareLabel->setText(QString(" S = ") + QString::number(mFigure->getS(), 'd', 2));
        ui->perimetrLabel->setText(QString(" P = ") + QString::number(mFigure->getP(), 'd', 2));
        ui->xPointLabel->setText(QString(" X = ") + QString::number(mFigure->getCordCenterX(), 'd', 2));
        ui->yPointLabel->setText(QString(" Y = ") + QString::number(mFigure->getCordCenterY(), 'd', 2));

    }


   /*for (Figure* figure : figures) {
        if(figure != nullptr)
        {
            figure -> draw(&painter);
        ui->squareLabel->setText(QString(" S = ") + QString::number(mFigure->getS(), 'd', 2));
        ui->perimetrLabel->setText(QString(" P = ") + QString::number(mFigure->getP(), 'd', 2));
        ui->xPointLabel->setText(QString(" X = ") + QString::number(mFigure->getCordCenterX(), 'd', 2));
        ui->yPointLabel->setText(QString(" Y = ") + QString::number(mFigure->getCordCenterY(), 'd', 2));
            qDebug() << "h";
        }

    }

*/
}

void MainWindow::mousePressEvent(QMouseEvent *mpe){

    pntr = new QPainter(this);
    QPointF curPoint = mpe->pos();
    if(ui->BNew->isChecked()){
        if(mFigure != nullptr)
        {
          //  delete mFigure;
           // mFigure = nullptr;
        }

        if(ui->BRectangle->isChecked()){
            mFigure = new Rectangle(curPoint, QPointF(0, 0));
        }
        if(ui->BSquare->isChecked()){
            mFigure = new Rectangle(curPoint, QPointF(0, 0));
        }
        if(ui->BRhombus->isChecked()){
            mFigure = new Rhombus(curPoint, QPointF(0, 0));
        }
        if(ui->BTriangle->isChecked()){
            mFigure = new Triangle(curPoint, QPointF(0, 0));
        }
        if(ui->BHexagon->isChecked()){
            mFigure = new Hexagon(curPoint, QPointF(0, 0));
        }
        if(ui->BCircle->isChecked()){
            mFigure = new Circle(curPoint, QPointF(0, 0));
        }
        if(ui->BStar->isChecked()){
            mFigure = new Star(curPoint, QPointF(0, 0), ui->spinBox->value());
        }
        if(ui->BEllipse->isChecked()){
            mFigure = new Ellipse(curPoint, QPointF(0, 0));
        }
        if(ui->BLine->isChecked()){
            mFigure = new Line(curPoint, QPointF(0, 0));
        }
        if (mFigure != nullptr) {
            figures.push_back(mFigure);
        }
    }
    else if(ui->BMove1->isChecked())
        {
            lastMousePoint = mpe->pos();
        }
    else if(ui->BEdit->isChecked())
    {
            if(mFigure != nullptr)
            {
            if(mFigure->getId() == 1){
                int i = 0;
                QVector<QPointF> mPoints = mFigure->getPointsVector();
                for(; i < mPoints.size(); i++)
                {
                    if((mPoints[i].x() + 7 > mpe->pos().x() && mPoints[i].x() - 7 < mpe->pos().x()) && (mPoints[i].y() + 7 > mpe->pos().y() && mPoints[i].y() - 7 < mpe->pos().y()))
                    {
                        customFlagNum = i;
                        changedPoint = mPoints[i];
                        break;
                    }
                }
                if(i == mPoints.size())
                    customFlagNum = -1;
            }
            if(mFigure->getId() == 2)
                customFlagNum = -1;

            lastMousePoint = mpe->pos();

            }
    }


    update();
}


void MainWindow::mouseMoveEvent(QMouseEvent *mme){
    if(mFigure != nullptr)
    {
        if(ui->BNew->isChecked())
        {
            if(ui->BSquare->isChecked()){
                mFigure->setSize(QPointF((mme->pos() - mFigure->getCenter()).x(),(mme->pos() - mFigure->getCenter()).x()));
            }
            else if(ui->BLine->isChecked()){
                mFigure->setSize(QPointF((mme->pos())));
            }
            else mFigure->setSize(mme->pos() - mFigure->getCenter());
        }
            else if(ui->BMove1->isChecked())
            {
                mFigure->move(mFigure->getCenter() + (mme->pos() - lastMousePoint));
                lastMousePoint = mme->pos();
            }
        else if(ui->BEdit->isChecked())
        {
                if(mFigure != nullptr && customFlagNum != -1)
                {
                    mFigure->setCenterEdit(mme->pos(), customFlagNum);
                }
                else if(mFigure != nullptr && mFigure->getId() == 2)
                {
                    mFigure->setSize(mFigure->getRadSize() + mme->pos() - lastMousePoint);
                    qDebug() << "doing";
                    lastMousePoint = mme->pos();

                }
        }

    }
    update();
}



MainWindow::~MainWindow()
{
    delete ui;
    delete mFigure;
    delete pntr;
    delete timer;
}


void MainWindow::on_BRotateL_pressed()
{
    if(mFigure != nullptr)
        QObject::connect(timer, &QTimer::timeout, mFigure, &Figure::rotateL);
        connect(timer, &QTimer::timeout, [this]() {
            update();
        });

    timer->start(35);

}


void MainWindow::on_BRotateL_released()
{
    timer->disconnect();
    timer->stop();
}


void MainWindow::on_BRotateR_pressed()
{
    if(mFigure != nullptr)
        QObject::connect(timer, &QTimer::timeout, mFigure, &Figure::rotateR);
    connect(timer, &QTimer::timeout, [this]() {
        update();
    });

    timer->start(35);
}


void MainWindow::on_BRotateR_released()
{
     timer->disconnect();
     timer->stop();
}


void MainWindow::on_BMSize_pressed()
{
     if(mFigure != nullptr)
        QObject::connect(timer, &QTimer::timeout, mFigure, &Figure::downScale);
        connect(timer, &QTimer::timeout, [this]() {
         update();
    });

     timer->start(35);
}


void MainWindow::on_BMSize_released()
{
    timer->disconnect();
    timer->stop();
}




void MainWindow::on_BPSize_pressed()
{

     if(mFigure != nullptr)
        QObject::connect(timer, &QTimer::timeout, mFigure, &Figure::upScale);
     connect(timer, &QTimer::timeout, [this]() {
         update();
     });
     timer->start(35);
}


void MainWindow::on_BPSize_released()
{
    timer->disconnect();
    timer->stop();
}

