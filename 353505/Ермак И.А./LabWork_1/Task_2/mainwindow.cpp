#include "mainwindow.h"
#include "ui_mainwindow.h"

QColor CIRCLE_PEN_COLOR;
QColor CIRCLE_BRUSH_COLOR;
int CIRCLE_POSITION_X = 0;
int CIRCLE_POSITION_Y = 0;
int CIRCLE_RADIUS = 10;
bool CIRCLE_PARAMETRS = false;

QColor RECTANGLE_PEN_COLOR;
QColor RECTANGLE_BRUSH_COLOR;
int RECTANGLE_POSITION_X = 0;
int RECTANGLE_POSITION_Y = 0;
int RECTANGLE_WIDTH;
int RECTANGLE_HEIGHT;
bool RECTANGLE_PARAMETRS = false;

QColor ELLIPSE_PEN_COLOR;
QColor ELLIPSE_BRUSH_COLOR;
int ELLIPSE_POSITION_X = 0;
int ELLIPSE_POSITION_Y = 0;
int ELLIPSE_WIDTH;
int ELLIPSE_HEIGHT;
bool ELLIPSE_PARAMETRS = false;

QColor SQUARE_PEN_COLOR;
QColor SQUARE_BRUSH_COLOR;
int SQUARE_POSITION_X = 0;
int SQUARE_POSITION_Y = 0;
int SQUARE_SIDE;
bool SQUARE_PARAMETRS = false;

QColor TRIANGLE_PEN_COLOR;
QColor TRIANGLE_BRUSH_COLOR;
int TRIANGLE_POSITION_X = 0;
int TRIANGLE_POSITION_Y = 0;
int TRIANGLE_BASE;
int TRIANGLE_SIDE;
bool TRIANGLE_PARAMETRS = false;

QColor STAR_PEN_COLOR;
QColor STAR_BRUSH_COLOR;
int STAR_POSITION_X = 0;
int STAR_POSITION_Y = 0;
int STAR_SIDE;
bool STAR_PARAMETRS = false;

QColor HEXAGONE_PEN_COLOR;
QColor HEXAGONE_BRUSH_COLOR;
int HEXAGONE_POSITION_X = 0;
int HEXAGONE_POSITION_Y = 0;
int HEXAGONE_SIDE;
bool HEXAGONE_PARAMETRS = false;

bool FIGURE_EXISTS = false;
int circle_count = 0;
int ellipse_count = 0;
int rectangle_count = 0;
int square_count = 0;
int triangle_count = 0;
int star_count = 0;
int hexagone_count = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->Scene->setScene(scene);
    scene->addLine(-2000, 0, 2000, 0);
    scene->addLine(0, -2000, 0, 2000);
    ui->Scene->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    cDialog = new DialogCircle;
    rDialog = new DialogRectangle;
    eDialog = new DialogEllipse;
    sqDialog = new DialogSquare;
    tDialog = new DialogTriangle;
    stDialog = new DialogStar;
    hDialog = new DialogHexagone;
    timer = new QTimer;
    rotatingTimer = new QTimer;
    canva = new Canva;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getCircleData(int positionX, int positionY, int radius, QColor BrushColor, QColor PenColor)
{
    CIRCLE_PEN_COLOR = PenColor;
    CIRCLE_BRUSH_COLOR = BrushColor;
    CIRCLE_POSITION_X = positionX;
    CIRCLE_POSITION_Y = positionY;
    CIRCLE_RADIUS = radius;
}

void MainWindow::getRectangleData(int positionX, int positionY, int width,int height, QColor BrushColor, QColor PenColor)
{
    RECTANGLE_PEN_COLOR = PenColor;
    RECTANGLE_BRUSH_COLOR = BrushColor;
    RECTANGLE_POSITION_X = positionX;
    RECTANGLE_POSITION_Y = positionY;
    RECTANGLE_WIDTH = width;
    RECTANGLE_HEIGHT = height;
}

void MainWindow::getEllipseData(int positionX, int positionY, int horisontalRadius, int verticalRadius, QColor BrushColor, QColor PenColor)
{
    ELLIPSE_POSITION_X = positionX;
    ELLIPSE_POSITION_Y = positionY;
    ELLIPSE_WIDTH = horisontalRadius;
    ELLIPSE_HEIGHT = verticalRadius;
    ELLIPSE_BRUSH_COLOR = BrushColor;
    ELLIPSE_PEN_COLOR = PenColor;
}

void MainWindow::getSquareData(int positionX, int positionY, int side, QColor BrushColor, QColor PenColor)
{
    SQUARE_POSITION_X = positionX;
    SQUARE_POSITION_Y = positionY;
    SQUARE_SIDE = side;
    SQUARE_BRUSH_COLOR = BrushColor;
    SQUARE_PEN_COLOR = PenColor;
}

void MainWindow::getTriangleData(int positionX, int positionY, int base, int side, QColor BrushColor, QColor PenColor)
{
    TRIANGLE_POSITION_X = positionX;
    TRIANGLE_POSITION_Y = positionY;
    TRIANGLE_BASE = base;
    TRIANGLE_SIDE = side;
    TRIANGLE_BRUSH_COLOR = BrushColor;
    TRIANGLE_PEN_COLOR = PenColor;
}

void MainWindow::getStarData(int positionX, int positionY, int radius, QColor BrushColor, QColor PenColor)
{
    STAR_POSITION_X = positionX;
    STAR_POSITION_Y = positionY;
    STAR_SIDE = radius;
    STAR_BRUSH_COLOR = BrushColor;
    STAR_PEN_COLOR = PenColor;
}

void MainWindow::getHexagoneData(int positionX, int positionY, int side, QColor BrushColor, QColor PenColor)
{
    HEXAGONE_POSITION_X = positionX;
    HEXAGONE_POSITION_Y = positionY;
    HEXAGONE_SIDE = side;
    HEXAGONE_BRUSH_COLOR = BrushColor;
    HEXAGONE_PEN_COLOR = PenColor;
}

void MainWindow::on_setParametrs_clicked() //check
{
    if(ui->Figure->currentText() == "Круг")
    {
        cDialog->setModal(true);
        cDialog->show();
        connect(cDialog,SIGNAL(sendData(int,int,int,QColor,QColor)),this,SLOT(getCircleData(int,int,int,QColor,QColor)));
    }
    else if(ui->Figure->currentText() == "Прямоугольник")
    {
        rDialog->setModal(true);
        rDialog->show();
        connect(rDialog,SIGNAL(sendData(int,int,int,int,QColor,QColor)),this,SLOT(getRectangleData(int,int,int,int,QColor,QColor)));
    }
    else if(ui->Figure->currentText() == "Эллипс")
    {
        eDialog->setModal(true);
        eDialog->show();
        connect(eDialog,SIGNAL(sendData(int,int,int,int,QColor,QColor)),this,SLOT(getEllipseData(int,int,int,int,QColor,QColor)));
    }
    else if(ui->Figure->currentText() == "Квадрат")
    {
        sqDialog->setModal(true);
        sqDialog->show();
        connect(sqDialog,SIGNAL(sendData(int,int,int,QColor,QColor)),this,SLOT(getSquareData(int,int,int,QColor,QColor)));
    }
    else if(ui->Figure->currentText() == "Треугольник")
    {
        tDialog->setModal(true);
        tDialog->show();
        connect(tDialog,SIGNAL(sendData(int,int,int,int,QColor,QColor)),this,SLOT(getTriangleData(int,int,int,int,QColor,QColor)));
    }
    else if(ui->Figure->currentText() == "Звезда")
    {
        stDialog->setModal(true);
        stDialog->show();
        connect(stDialog,SIGNAL(sendData(int,int,int,QColor,QColor)),this,SLOT(getStarData(int,int,int,QColor,QColor)));
    }
    else if(ui->Figure->currentText() == "Шестиугольник")
    {
        hDialog->setModal(true);
        hDialog->show();
        connect(hDialog,SIGNAL(sendData(int,int,int,QColor,QColor)),this,SLOT(getHexagoneData(int,int,int,QColor,QColor)));
    }
}

bool overlapNames(QString verifiableFigure, QString figure)
{
    int size = figure.size();
    for(int i = 0; i < size; i++)
    {
        if(verifiableFigure.at(i) != figure.at(i)) {
            return false;
        }
    }
    return true;
}

void MainWindow::on_getFigure_clicked()
{
    if(ui->Figure->currentText() == "Круг")
    {
        if(!CIRCLE_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","Выберите параметры фигуры!");
            return;
        }
        circle = new Circle(CIRCLE_POSITION_X, CIRCLE_POSITION_Y, CIRCLE_RADIUS, CIRCLE_BRUSH_COLOR, CIRCLE_PEN_COLOR);
        scene->addItem(circle);
        circles.append(circle);
        QString string = "Круг" + QString::number(circle_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
    else if(ui->Figure->currentText() == "Прямоугольник")
    {
        if(!RECTANGLE_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","Выберите параметры фигуры!");
            return;
        }
        rectangle = new Rectangle(RECTANGLE_POSITION_X, RECTANGLE_POSITION_Y, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, RECTANGLE_BRUSH_COLOR, RECTANGLE_PEN_COLOR);
        scene->addItem(rectangle);
        rectangles.append(rectangle);
        QString string = "Прямоугольник" + QString::number(rectangle_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
    else if(ui->Figure->currentText() == "Эллипс")
    {
        if(!ELLIPSE_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","Выберите параметры фигуры!");
            return;
        }
        ellipse = new Ellipse(ELLIPSE_POSITION_X, ELLIPSE_POSITION_Y, ELLIPSE_WIDTH, ELLIPSE_HEIGHT, ELLIPSE_BRUSH_COLOR, ELLIPSE_PEN_COLOR);
        scene->addItem(ellipse);
        ellipses.append(ellipse);
        QString string = "Эллипс" + QString::number(ellipse_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
    else if(ui->Figure->currentText() == "Квадрат")
    {
        if(!SQUARE_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","Выберите параметры фигуры!");
            return;
        }
        square = new Square(SQUARE_POSITION_X, SQUARE_POSITION_Y, SQUARE_SIDE, SQUARE_BRUSH_COLOR, SQUARE_PEN_COLOR);
        scene->addItem(square);
        squares.append(square);
        QString string = "Квадрат" + QString::number(square_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
    else if(ui->Figure->currentText() == "Треугольник")
    {
        if(!TRIANGLE_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","Выберите параметры фигуры!");
            return;
        }
        triangle = new Triangle(TRIANGLE_POSITION_X, TRIANGLE_POSITION_Y, TRIANGLE_BASE, TRIANGLE_SIDE, TRIANGLE_BRUSH_COLOR, TRIANGLE_PEN_COLOR);
        scene->addItem(triangle);
        triangles.append(triangle);
        QString string = "Треугольник" + QString::number(triangle_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
    else if(ui->Figure->currentText() == "Звезда")
    {
        if(!STAR_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","Выберите параметры фигуры!");
            return;
        }
        star = new Star(STAR_POSITION_X, STAR_POSITION_Y, STAR_SIDE, STAR_BRUSH_COLOR, STAR_PEN_COLOR);
        scene->addItem(star);
        stars.append(star);
        QString string = "Звезда" + QString::number(star_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
    else if(ui->Figure->currentText() == "Шестиугольник")
    {
        if(!HEXAGONE_PARAMETRS)
        {
            QMessageBox::warning(this,"ОШИБКА!","ВЫберите параметры фигуры!");
            return;
        }
        hexagone = new Hexagone(HEXAGONE_POSITION_X, HEXAGONE_POSITION_Y, HEXAGONE_SIDE, HEXAGONE_BRUSH_COLOR, HEXAGONE_PEN_COLOR);
        scene->addItem(hexagone);
        hexagons.append(hexagone);
        QString string = "Шестиугольник" + QString::number(hexagone_count++);
        ui->listFigure->addItem(string);
        FIGURE_EXISTS = true;
    }
}

void MainWindow::on_pushButton_RIGHT_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveRight()));
        timer->start(3);
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveRight()));
        timer->start(3);
    }
}

void MainWindow::on_pushButton_LEFT_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!", "На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!", "Выберите выделите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveLeft()));
        timer->start(3);
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveLeft()));
        timer->start(3);
    }
}

void MainWindow::on_pushButton_UP_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveUp()));
        timer->start(3);
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveUp()));
        timer->start(3);
    }
}

void MainWindow::on_pushButton_DOWN_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(MoveDown()));
        timer->start(3);
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(MoveDown()));
        timer->start(3);
    }
}

void MainWindow::on_squareFigure_clicked()
{
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите фигуру в списке!");
        return;
    }
    QString str = ui->listFigure->currentItem()->text();
    if(overlapNames(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        QMessageBox::information(this,"Площадь","Площадь круга: " + QString::number(circles[i]->square()));
    }
    else if(overlapNames(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Площадь","Площадь эллипса: " + QString::number(ellipses[i]->square()));
    }
    else if(overlapNames(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Площадь","Площадь прямоугольника: " + QString::number(rectangles[i]->square()));
    }
    else if(overlapNames(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        QMessageBox::information(this,"Площадь","Площадь квадрата: " + QString::number(squares[i]->square()));
    }
    else if(overlapNames(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        QMessageBox::information(this,"Площадь","Площадь треугольника: " +QString::number(triangles[i]->square()));
    }
    else if(overlapNames(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Площадь","Площадь звезды: " + QString::number(stars[i]->square()));
    }
    else if(overlapNames(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Площадь","Площадь фигуры: " + QString::number(hexagons[i]->square()));
    }
}


void MainWindow::on_perimetrFigure_clicked()
{
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listFigure->currentItem()->text();
    if(overlapNames(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        QMessageBox::information(this,"Периметр","Периметр круга: " + QString::number(circles[i]->perimetr()));
    }
    else if(overlapNames(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Периметр","Периметр эллипса: " + QString::number(ellipses[i]->perimetr()));
    }
    else if(overlapNames(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Периметр","Периметр прямоугольника: " + QString::number(rectangles[i]->perimetr()));
    }
    else if(overlapNames(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        QMessageBox::information(this,"Периметр","Периметр квадрата: " + QString::number(squares[i]->perimetr()));
    }
    else if(overlapNames(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        QMessageBox::information(this,"Периметр","Периметр треугольника: " +QString::number(triangles[i]->perimetr()));
    }
    else if(overlapNames(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        QMessageBox::information(this,"Периметр","Периметр звезды: " + QString::number(stars[i]->perimetr()));
    }
    else if(overlapNames(str,"Шестиугольник"))
    {
        int i = str.remove(0,13).toInt();
        QMessageBox::information(this,"Периметр","Периметр звезды: " + QString::number(hexagons[i]->perimetr()));
    }
}

void MainWindow::on_scale_clicked() //check
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        circles[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите радиус",0,1,500));
        connect(timer,SIGNAL(timeout()),circles[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        ellipses[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите большую полуось",0,1,500),
                              QInputDialog::getInt(this,"Введите параметры","Введите меньшую полуось",0,1,490));
        connect(timer,SIGNAL(timeout()),ellipses[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        rectangles[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите ширину",0,1,1000),
                                QInputDialog::getInt(this,"Введите параметры","Введите высоту",0,1,600));
        connect(timer,SIGNAL(timeout()),rectangles[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        squares[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите сторону",0,1,600));
        connect(timer,SIGNAL(timeout()),squares[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        triangles[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите основание",0,1,1000),QInputDialog::getInt(this,"Введите параметры","Введите боковую сторону",0,10,600));
        connect(timer,SIGNAL(timeout()),triangles[i],SLOT(Scale()), Qt::UniqueConnection);
        timer->start(10);
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        stars[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите радиус",0,1,500));
        connect(timer,SIGNAL(timeout()),stars[i],SLOT(Scale()),Qt::UniqueConnection);
        timer->start(10);
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        hexagons[i]->setScale(QInputDialog::getInt(this,"Введите параметры","Введите сторону",0,10,500));
        connect(timer,SIGNAL(timeout()),hexagons[i],SLOT(Scale()),Qt::UniqueConnection);
        timer->start(10);
    }
}

void MainWindow::rotateLeft()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        circles[i]->setRotation(circles[i]->angleDecreas());
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        ellipses[i]->setRotation(ellipses[i]->angleDecreas());
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleDecreas());
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        squares[i]->setRotation(squares[i]->angleDecreas());
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleDecreas());
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        stars[i]->setRotation(stars[i]->angleDecreas());
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        hexagons[i]->setRotation(hexagons[i]->angleDecreas());
    }
}

void MainWindow::rotateRight()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString string = ui->listFigure->currentItem()->text();
    if(overlapNames(string,"Круг"))
    {
        int i = string.remove(0,4).toInt();
        circles[i]->setRotation(circles[i]->angleIncreas());
    }
    else if(overlapNames(string,"Эллипс"))
    {
        int i = string.remove(0,6).toInt();
        ellipses[i]->setRotation(ellipses[i]->angleIncreas());
    }
    else if(overlapNames(string,"Прямоугольник"))
    {
        int i = string.remove(0,13).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleIncreas());
    }
    else if(overlapNames(string,"Квадрат"))
    {
        int i = string.remove(0,7).toInt();
        squares[i]->setRotation(squares[i]->angleIncreas());
    }
    else if(overlapNames(string,"Треугольник"))
    {
        int i = string.remove(0,11).toInt();
        rectangles[i]->setRotation(rectangles[i]->angleIncreas());
    }
    else if(overlapNames(string,"Звезда"))
    {
        int i = string.remove(0,6).toInt();
        stars[i]->setRotation(stars[i]->angleIncreas());
    }
    else if(overlapNames(string,"Шестиугольник"))
    {
        int i = string.remove(0,13).toInt();
        hexagons[i]->setRotation(hexagons[i]->angleIncreas());
    }
}


void MainWindow::on_rotateLeft_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    connect(rotatingTimer,SIGNAL(timeout()),this,SLOT(rotateLeft()));
    rotatingTimer->start(10);
}

void MainWindow::on_rotateRight_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    connect(rotatingTimer,SIGNAL(timeout()),this,SLOT(rotateRight()));
    rotatingTimer->start(10);
}

void MainWindow::on_rotate_clicked()
{
    if(!FIGURE_EXISTS)
    {
        QMessageBox::warning(this,"ОШИБКА!","На графической сцене нет фигур!");
        return;
    }
    if(ui->listFigure->currentItem() == NULL)
    {
        QMessageBox::warning(this,"ОШИБКА!","Выберите выделите фигуру в списке!");
        return;
    }
    QString str = ui->listFigure->currentItem()->text();
    if(overlapNames(str,"Круг"))
    {
        int i = str.remove(0,4).toInt();
        circles[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                            QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(overlapNames(str,"Эллипс"))
    {
        int i = str.remove(0,6).toInt();
        ellipses[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                             QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(overlapNames(str,"Прямоугольник"))
    {
        int i = str.remove(0,13).toInt();
        rectangles[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                               QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(overlapNames(str,"Квадрат"))
    {
        int i = str.remove(0,7).toInt();
        squares[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                            QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(overlapNames(str,"Треугольник"))
    {
        int i = str.remove(0,11).toInt();
        rectangles[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                               QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(overlapNames(str,"Звезда"))
    {
        int i = str.remove(0,6).toInt();
        stars[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                          QInputDialog::getInt(this,"Введите параметры","Введите dy",0,-1000,1000));
    }
    else if(overlapNames(str,"Шестиугольник"))
    {
        int i = str.remove(0,6).toInt();
        hexagons[i]->setTransformOriginPoint(QInputDialog::getInt(this,"Введите параметры","Введите dx",0,-1000,1000),
                                             QInputDialog::getInt(this,"Введите параметры", "Введите dy",0,-1000,1000));
    }
}

void MainWindow::on_Canva_clicked()
{
    canva->setModal(true);
    canva->show();
}




