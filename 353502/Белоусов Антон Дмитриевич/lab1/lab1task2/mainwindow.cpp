#include "mainwindow.h"
#include "./ui_mainwindow.h"

const int SCENE_SIZE = 700;
const int NUMBER_OF_EDGES_IN_5STAR = 5;
const int NUMBER_OF_EDGES_IN_6STAR = 6;
const int NUMBER_OF_EDGES_IN_8STAR = 8;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , points(new std::queue<QPointF>)
    , mainScene(new paintScene)
    , figures(new std::vector<figure *>)
{
    ui->setupUi(this);

    mouse = new mouseCatcher(this->mainScene);

    ui->graphicsView->setScene(mainScene);
    mainScene->setSceneRect(0, 0, SCENE_SIZE, SCENE_SIZE);

    connect(mouse, &mouseCatcher::mouseClicked, this, &MainWindow::processMouseClick);
    connect(mouse, &mouseCatcher::mouseDragged, this, &MainWindow::processMouseDrag);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processMouseClick(int x, int y)
{
    if (current != currentType::editMode) {
        points->push(QPointF(x, y));
    }

    if (current == currentType::triangleMode && points->size() == 3)
    {
        triangle* newTriangle = new triangle;
        QPointF* arrPoints = new QPointF[3];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        arrPoints[2] = points->front();
        points->pop();
        newTriangle->setFigure(arrPoints);
        this->mainScene->addItem(newTriangle);

        figures->push_back(newTriangle);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::rhombusMode && points->size() == 3)
    {
        rhombus* newRhombus = new rhombus;
        QPointF* arrPoints = new QPointF[3];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        arrPoints[2] = points->front();
        points->pop();
        newRhombus->setFigure(arrPoints);
        this->mainScene->addItem(newRhombus);
        figures->push_back(newRhombus);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::ellipseMode && points->size() == 3)
    {
        ellipse* newEllipse = new ellipse;
        QPointF* arrPoints = new QPointF[3];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        arrPoints[2] = points->front();
        points->pop();
        newEllipse->setFigure(arrPoints);
        this->mainScene->addItem(newEllipse);

        figures->push_back(newEllipse);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::squareMode && points->size() == 2)
    {
        foursquare* newFigure = new foursquare;
        QPointF* arrPoints = new QPointF[2];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        newFigure->setFigure(arrPoints);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::star5Mode && points->size() == 2)
    {
        star* newFigure = new star;
        QPointF* arrPoints = new QPointF[2];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        newFigure->setFigure(arrPoints);
        newFigure->setNumberOfEdges(NUMBER_OF_EDGES_IN_5STAR);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::star6Mode && points->size() == 2)
    {
        star* newFigure = new star;
        QPointF* arrPoints = new QPointF[2];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        newFigure->setFigure(arrPoints);
        newFigure->setNumberOfEdges(NUMBER_OF_EDGES_IN_6STAR);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::star8Mode && points->size() == 2)
    {
        star* newFigure = new star;
        QPointF* arrPoints = new QPointF[2];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        newFigure->setFigure(arrPoints);
        newFigure->setNumberOfEdges(NUMBER_OF_EDGES_IN_8STAR);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::rectangleMode && points->size() == 3)
    {
        rectangle* newFigure = new rectangle;
        QPointF* arrPoints = new QPointF[3];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        arrPoints[2] = points->front();
        points->pop();
        newFigure->setFigure(arrPoints);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::hexagonMode && points->size() == 2)
    {
        hexagon* newFigure = new hexagon;
        QPointF* arrPoints = new QPointF[2];
        arrPoints[0] = points->front();
        points->pop();
        arrPoints[1] = points->front();
        points->pop();
        newFigure->setFigure(arrPoints);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }
    else if (current == currentType::circleMode && points->size() == 2)
    {
        ellipse* newFigure = new ellipse;
        QPointF* arrPoints = new QPointF[3];
        arrPoints[1] = points->front();
        points->pop();
        arrPoints[2] = points->front();
        points->pop();

        arrPoints[0].setX(arrPoints[1].x() - (arrPoints[2].y() - arrPoints[1].y()));
        arrPoints[0].setY(arrPoints[1].y() + (arrPoints[2].x() - arrPoints[1].x()));

        newFigure->setFigure(arrPoints);
        this->mainScene->addItem(newFigure);

        figures->push_back(newFigure);
        currentFigureIterator = figures->size() - 1;
        current = currentType::editMode;
    }

    this->mainScene->update();
}

void MainWindow::processMouseDrag(int x1, int y1, int x2, int y2)
{
    if (current == currentType::editMode)
    {
        if ((*this->figures)[this->currentFigureIterator]->isPointInside(QPoint(x1, y1)))
        {
            (*this->figures)[this->currentFigureIterator]->moveFigure(QPoint(x2 - x1, y2 - y1));
        }
        else
        {
            (*this->figures)[this->currentFigureIterator]->resizeFigureFromPointToPoint(QPoint(x1, y1), QPoint(x2, y2));
            (*this->figures)[this->currentFigureIterator]->rotateFigureFromPointToPoint(QPoint(x1, y1), QPoint(x2, y2));
        }
    }

    this->mainScene->update();
}

void MainWindow::on_pushButtonTriangle_clicked()
{
    current = currentType::triangleMode;
}

void MainWindow::keyPressEvent(QKeyEvent * event )
{
    if (event->key() == Qt::Key_Q)
    {
        if (currentFigureIterator > 0) {
            currentFigureIterator--;
        }
    }

    if (event->key() == Qt::Key_W)
    {
        if (currentFigureIterator < figures->size() - 1) {
            currentFigureIterator++;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    current = currentType::rhombusMode;
}

void MainWindow::on_pushButton_8_clicked()
{
    current = currentType::ellipseMode;
}

void MainWindow::on_pushButton_6_clicked()
{
    current = currentType::squareMode;
}

void MainWindow::on_pushButton_5_clicked()
{
    current = currentType::star6Mode;
}

void MainWindow::on_pushButton_7_clicked()
{
    current = currentType::star8Mode;
}

void MainWindow::on_pushButton_2_clicked()
{
    current = currentType::circleMode;
}

void MainWindow::on_pushButton_10_clicked()
{
    current = currentType::hexagonMode;
}

void MainWindow::on_pushButton_9_clicked()
{
    current = currentType::star5Mode;
}

void MainWindow::on_pushButton_4_clicked()
{
    current = currentType::rectangleMode;
}

void MainWindow::on_pushButton_clicked()
{
    while (!points->empty()) {
        points->pop();
    }
    current = currentType::editMode;
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->label->setText(QString::fromStdString(
        std::to_string(static_cast<int>(figures->at(currentFigureIterator)->getPerimeter()))));
    ui->label_2->setText(QString::fromStdString(
        std::to_string(static_cast<int>(figures->at(currentFigureIterator)->getSquare()))));
}

