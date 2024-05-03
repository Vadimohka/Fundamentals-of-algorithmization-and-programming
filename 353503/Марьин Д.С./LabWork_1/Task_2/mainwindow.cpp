#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new CustomScene();
    scene->setSceneRect(ui->graphicsView->x(),ui->graphicsView->y(),ui->graphicsView->width(),ui->graphicsView->height());

    setWindowTitle("\"Danil Mariyn\"Lab_1_2");
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    connect(scene,&CustomScene::signalPressLeft,this,&MainWindow::mouse_Press_L_Event);
    connect(scene,&CustomScene::signalPressRight,this,&MainWindow::mouse_Press_R_Event);
    connect(scene,&CustomScene::signalMove,this,&MainWindow::mouse_Move_Event);
    connect(scene,&CustomScene::signalRelease,this,&MainWindow::mouse_Release_Event);
    connect(scene,&CustomScene::signalDelete,this,&MainWindow::slotDelete);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    QVector <Shape*> triangle,
        circle,///// all above it is a bad solution !
        rectangle,
        square,
        ellips,
        rhomb,
        star_5,
        star_6,
        star_8,
        hexagon;

    all_figures[0] = triangle; ///// all above it is a bad solution !
    all_figures[1] = circle,
    all_figures[2] = rectangle,
    all_figures[3] = square,
    all_figures[4] = ellips,
    all_figures[5] = rhomb,
    all_figures[6] = star_5,
    all_figures[7] = star_6,
    all_figures[8] = star_8;
    all_figures[9] = hexagon;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFigure()
{
    if (ui->comboBox_Shape->currentText() == "Triangle")
    {
        qDebug() << "Triangle Selected";
        FigureID = Currect_Shape::triangle;
    }
    if (ui->comboBox_Shape->currentText() == "Circle")
    {
        qDebug() << "Circle Selected";
        FigureID = Currect_Shape::circle;
    }
    if (ui->comboBox_Shape->currentText() == "Rectangle")
    {
        qDebug() << "Ractangle Selected";
        FigureID = Currect_Shape::rectangle;
    }
    if (ui->comboBox_Shape->currentText() == "Square")
    {
        qDebug() << "Square Selected";
        FigureID = Currect_Shape::square;
    }
    if (ui->comboBox_Shape->currentText() == "Ellipse")
    {
        qDebug() << "Ellipse Selected";
        FigureID = Currect_Shape::ellipse;
    }
    if (ui->comboBox_Shape->currentText() == "Rhomb")
    {
        qDebug() << "Rhomb Selected";
        FigureID = Currect_Shape::rhomb;
    }
    if (ui->comboBox_Shape->currentText() == "Star-5")
    {
        qDebug() << "Star-5 Selected";
        FigureID = Currect_Shape::star_5;
    }
    if (ui->comboBox_Shape->currentText() == "Star-6")
    {
        qDebug() << "Star-6 Selected";
        FigureID = Currect_Shape::star_6;
    }
    if (ui->comboBox_Shape->currentText() == "Star-8")
    {
        qDebug() << "Star-8 Selected";
        FigureID = Currect_Shape::star_8;
    }
    if (ui->comboBox_Shape->currentText() == "Hexagon")
    {
        qDebug() << "Hexagon Selected";
        FigureID = Currect_Shape::hexagon;
    }
}

void MainWindow::mouse_Press_L_Event(QPointF point)
{
    if(ui->btn_Create->isChecked())
    {
        ui->lbl_perim->setText("");
        ui->lbl_square->setText("");
        ui->lbl_center->setText("");
        p.push_back(point);

            if (FigureID == Currect_Shape::triangle)
            {
                count++;
                if (p.size() == 3)
                {
                    triangle = new Triangle;
                    all_figures[FigureID].push_back(triangle);
                    all_figures[FigureID].last()->setPoints(p);
                    scene->addItem((QGraphicsObject*)all_figures[FigureID].last());
                    all_figures[FigureID].last()->setFlags(QGraphicsItem::ItemIsMovable);
                    setInfo(all_figures[FigureID].last());
                    all_figures[FigureID].last()->setSelected(false);
                    all_figures[FigureID].last()->set_Center(p);
                    ui->dbl_spn_box_second_param->show();
                    scene->update();
                    count = 0;
                    p.clear();
                }
            }
            else
            {
                count++;
                if (p.size() == 2)
                {
                    switch(FigureID)
                    {
                    case Currect_Shape::circle:
                        circle = new Circle;
                        all_figures[FigureID].push_back(circle);
                        ui->dbl_spn_box_second_param->close();
                        break;
                    case Currect_Shape::rectangle:
                        rectangle = new Rectangle;
                        all_figures[FigureID].push_back(rectangle);
                        ui->dbl_spn_box_second_param->show();
                        break;
                    case Currect_Shape::square:
                        square = new Square;
                        all_figures[FigureID].push_back(square);
                        ui->dbl_spn_box_second_param->close();
                        break;
                    case Currect_Shape::ellipse:
                        ellips = new Ellips;
                        all_figures[FigureID].push_back(ellips);
                        ui->dbl_spn_box_second_param->show();
                        break;
                    case Currect_Shape::rhomb:
                        rhomb = new Rhomb;
                         all_figures[FigureID].push_back(rhomb);
                         ui->dbl_spn_box_second_param->show();
                        break;
                    case Currect_Shape::star_5:
                        star_5 = new Star_5;
                        all_figures[FigureID].push_back(star_5);
                        ui->dbl_spn_box_second_param->close();
                        break;
                    case Currect_Shape::star_6:
                        star_6 = new Star_6;
                        all_figures[FigureID].push_back(star_6);
                        ui->dbl_spn_box_second_param->close();
                        break;
                    case Currect_Shape::star_8:
                        star_8 = new Star_8;
                        all_figures[FigureID].push_back(star_8);
                        ui->dbl_spn_box_second_param->close();
                        break;
                    case Currect_Shape::hexagon:
                        hexagon = new Hexagon;
                        all_figures[FigureID].push_back(hexagon);
                        ui->dbl_spn_box_second_param->close();
                        break;
                    }

                    all_figures[FigureID].last()->setPoints(p);
                    scene->addItem((QGraphicsObject*)all_figures[FigureID].last());
                    all_figures[FigureID].last()->setFlag(Shape::ItemIsMovable,true);
                    setInfo(all_figures[FigureID].last());
                    all_figures[FigureID].last()->set_Center(p);
                    scene->update();
                    count = 0;
                    p.clear();
                }
            }
    }
    else if(ui->btn_move->isChecked())
    {
        isClck_L = true;
        item = (Shape*)scene->itemAt(point,{});
        if(item)
       {
           timer->start(10);
           setInfo(item);
           item->setCursor(Qt::ClosedHandCursor);
           start = point;
       }
    }
    else if(ui->btn_delete->isChecked() || ui->btn_scale->isChecked() || ui->btn_rotate->isChecked())
    {
        item = (Shape*)scene->itemAt(point,{});
        if(item)
        {
            item->setCursor(Qt::ClosedHandCursor);
            targetPoint = point;
        }
    }
}

void MainWindow::mouse_Press_R_Event(QPointF p)
{
    if(ui->btn_scale->isChecked())
    {
        isClck_R = true;
        if(item)
        {
            item->setCursor(Qt::DragCopyCursor);
            start = p;
        }
    }
    if(ui->btn_delete->isChecked() || ui->btn_rotate->isChecked())
    {
        isClck_R = true;
        if(item)
            start = p;
    }
}

void MainWindow::selectColor()
{
    color =  QColorDialog::getColor(Qt::white,this,tr("Slelect color"));
    all_figures[FigureID].last()->setColor(color);
}

void MainWindow::selectFilling()
{
    switch(ui->comboBox_Filling->currentIndex())
    {
    case 0:
        all_figures[FigureID].last()->setBrush(Qt::NoBrush);
        break;
    case 1:
         all_figures[FigureID].last()->setBrush(Qt::white);
        break;
    case 2:
         all_figures[FigureID].last()->setBrush(Qt::red);
        break;
    case 3:
        all_figures[FigureID].last()->setBrush(Qt::blue);
        break;
    case 4:
        all_figures[FigureID].last()->setBrush(Qt::green);
        break;
    case 5:
        all_figures[FigureID].last()->setBrush(Qt::yellow);
        break;
    }
}
void MainWindow::setInfo(Shape* figure)
{
    ui->lbl_perim->setText("");
    ui->lbl_square->setText("");
    ui->lbl_center->setText("");

    long double perim = fabs(figure->perimetr() * figure->get_Scale());
    long double square = fabs(figure->square() * figure->get_Scale() * figure->get_Scale());

    ui->lbl_perim->setNum((qreal)perim);
    ui->lbl_square->setNum((qreal)square);
    ui->lbl_center->setText(QString("X:%1 ; Y:%2").arg(roundf(figure->center.x())).arg(roundf(figure->center.y())));

    ui->dbl_spn_box_first_param->setValue(figure->getSpecificParam_1());
    ui->dbl_spn_box_second_param->setValue(figure->getSpecificParam_2());
}
void MainWindow::mouse_Move_Event(QPointF point)
{
    end = point;
    if(isClck_L && item && ui->btn_move->isChecked())
    {
        targetPoint = point;
        item->center = item->scenePos();
        setInfo(item);
    }
    else if(isClck_R && item && ui->btn_scale->isChecked())
    {
        item->setTransformOriginPoint(item->boundingRect().center());
        item->set_Scale(1 +(end.x()-start.x())/100);
        item->setScale(item->get_Scale());
        setInfo(item);
    }
    else if(isClck_R && item && ui->btn_rotate)
    {
        timer->start(10);
        item->setTransformOriginPoint(item->boundingRect().center());
    }
    scene->update();

}
void MainWindow::mouse_Release_Event(QPointF point)
{
    if(item && ui->btn_move->isChecked())
    {
        item->setCursor(QCursor(Qt::ArrowCursor));
        isClck_L = false;
        timer->stop();
    }
    if(item && ui->btn_scale->isChecked())
    {
        end = point;
        item->setCursor(QCursor(Qt::ArrowCursor));
        isClck_R = false;
    }
    if(item && ui->btn_rotate->isChecked())
    {
        end = point;
        timer->stop();
        isClck_R = false;
        isClck_L = false;
    }
}

void MainWindow::on_comboBox_Shape_currentIndexChanged(int index)
{
    FigureID = index;
    p.clear();
}
void MainWindow::on_comboBox_Filling_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    selectFilling();
}

void MainWindow::onTimerTimeout()
{
    if(isClck_L && item && ui->btn_move->isChecked())
    {
        item->setPos(targetPoint.x() - item->boundingRect().x() - item->boundingRect().width()/2 ,targetPoint.y() - item->boundingRect().y() - item->boundingRect().height()/2);
    }
    if(isClck_R && item && ui->btn_rotate->isChecked())
    {
        item->setRotation((end.y() - start.y()));
    }
}
void MainWindow::slotDelete()
{
    if(item)
    scene->removeItem(item);
    item = nullptr;
}

void MainWindow::on_btn_select_color_clicked()
{
    selectColor();
}


void MainWindow::on_dbl_spn_box_first_param_valueChanged(double arg1)
{
    if(arg1 != 0 && ui->btn_Create->isChecked())
    all_figures[FigureID].last()->setSpecificParam_1(arg1);
    setInfo(all_figures[FigureID].last());
    scene->update();
}


void MainWindow::on_dbl_spn_box_second_param_valueChanged(double arg1)
{
    if(arg1 != 0 && ui->btn_Create->isChecked())
    all_figures[FigureID].last()->setSpecificParam_2(arg1);
    setInfo(all_figures[FigureID].last());
    scene->update();
}

