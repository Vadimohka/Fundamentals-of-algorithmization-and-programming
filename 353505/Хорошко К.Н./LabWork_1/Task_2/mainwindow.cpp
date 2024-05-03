#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    this->setMinimumSize(1100, 500);
    this->setAcceptDrops(false);
    ui->setupUi(this);


    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::resizeTimer);
    timer->setInterval(100);

    timer1 = new QTimer();
    connect(timer1, &QTimer::timeout, this, &MainWindow::labelResize);
    timer1->setInterval(1);
    timer1->start();

    graphicsView = new QGraphicsView();
    graphicsView->setParent(this);

    graphicsScene = new PaintScene();
    graphicsScene->setBackgroundBrush(Qt::white);


    graphicsView->setScene(graphicsScene);
    graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали
    graphicsView->setAcceptDrops(false);
    graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
    graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    CircleButton = new QRadioButton("Круг", this);
    CircleButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    CircleButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    CircleButton->setStyleSheet("QRadioButton::checked{color: red; }");
    ElipsButton = new QRadioButton("Елипс", this);
    ElipsButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    ElipsButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    ElipsButton->setStyleSheet("QRadioButton::checked { color: red; }");
    HexagonButton = new QRadioButton("Шестиугольник", this);
    HexagonButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    HexagonButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    HexagonButton->setStyleSheet("QRadioButton::checked { color: red; }");
    RectangleButton = new QRadioButton("Прямоугольник", this);
    RectangleButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    RectangleButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    RectangleButton->setStyleSheet("QRadioButton::checked { color: red; }");
    RombButton = new QRadioButton("Ромб", this);
    RombButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    RombButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    RombButton->setStyleSheet("QRadioButton::checked { color: red; }");
    SquareButton = new QRadioButton("Квадрат", this);
    SquareButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    SquareButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    SquareButton->setStyleSheet("QRadioButton::checked {color: red; }");
    Star_fiveButton = new QRadioButton("Пятиконечная звезда", this);
    Star_fiveButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    Star_fiveButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    Star_fiveButton->setStyleSheet("QRadioButton::checked { color: red; }");
    Star_sixButton = new QRadioButton("Шестиконечная звезда", this);
    Star_sixButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    Star_sixButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    Star_sixButton->setStyleSheet("QRadioButton::checked { color: red; }");
    Star_eightButton = new QRadioButton("Восьмиконечная звезда", this);
    Star_eightButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    Star_eightButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    Star_eightButton->setStyleSheet("QRadioButton::checked { color: red; }");
    TriangleButton = new QRadioButton("Треугольник", this);
    TriangleButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    TriangleButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    TriangleButton->setStyleSheet("QRadioButton::checked { color: red; }");
    DrawButton = new QRadioButton("Рисование", this);
    DrawButton->setStyleSheet("QRadioButton::indicator { width: 20px; height: 20px; }");
    DrawButton->setStyleSheet("QRadioButton { font-size: 16px; }");
    DrawButton->setStyleSheet("QRadioButton::checked { color: red; }");

    graphicsView->setMouseTracking(true);

    connect(CircleButton, &QRadioButton::toggled, this, &MainWindow::button_circle);
    connect(ElipsButton, &QRadioButton::toggled, this, &MainWindow::button_elips);
    connect(HexagonButton, &QRadioButton::toggled, this, &MainWindow::button_hexagon);
    connect(RectangleButton, &QRadioButton::toggled, this, &MainWindow::button_rectangle);
    connect(RombButton, &QRadioButton::toggled, this, &MainWindow::button_romb);
    connect(SquareButton, &QRadioButton::toggled, this, &MainWindow::button_square);
    connect(Star_fiveButton, &QRadioButton::toggled, this, &MainWindow::button_star_five);
    connect(Star_sixButton, &QRadioButton::toggled, this, &MainWindow::button_star_six);
    connect(Star_eightButton, &QRadioButton::toggled, this, &MainWindow::button_star_eight);
    connect(TriangleButton, &QRadioButton::toggled, this, &MainWindow::button_triangle);
    connect(DrawButton, &QRadioButton::toggled, this, &MainWindow::button_draw);

    CircleButton->setChecked(true);

    Label1 = new QLabel("P:", this);
    Label2 = new QLabel("S:", this);
    Label3 = new QLabel("(X, Y):", this);
    Label1_1= new QLabel("", this);
    Label2_1 = new QLabel("", this);
    Label3_1 = new QLabel("", this);

    Label1->setAlignment(Qt::AlignCenter);
    Label2->setAlignment(Qt::AlignCenter);
    Label3->setAlignment(Qt::AlignCenter);

    Clear = new QPushButton("Очистить", this);
    Clear->setObjectName("Clear");
    QString style = "\
        QPushButton#Clear {\
        background-color: #e67e22; /* Оранжевый цвет */ \
        color: #ecf0f1; \
        border: 1px solid #d35400; /* Цвет границы */ \
        border-radius: 5px; \
        padding: 5px 10px; /* Больший внутренний отступ */ \
        font-size: 18px; /* Размер шрифта */ \
        font-weight: bold; /* Жирный текст */ \
        font-family: 'Arial', sans-serif; /* Название шрифта */ \
    } \
        QPushButton#Clear:hover {\
            background-color: #f39c12; /* Светло-оранжевый цвет при наведении */ \
    } \
        QPushButton#Clear:pressed {\
            background-color: #d35400; /* Цвет при нажатии */ \
    }";

    Clear->setStyleSheet(style);

    connect(Clear, &QPushButton::clicked, this, &MainWindow::clearScene);

}

void MainWindow::resizeTimer()
{
    timer->stop();
    graphicsView->setGeometry(0, 0, this->width()*4/5, this->height());
    graphicsScene->setSceneRect(0, 0, this->width()*4/5-10, this->height()-10);
    graphicsScene->maxW = this->width()*4/5-10;
    graphicsScene->maxH = this->height()-10;
    CircleButton->setGeometry(this->width()*4/5, 0, this->width()/5, this->height()/10);
    ElipsButton->setGeometry(this->width()*4/5, this->height()/15, this->width()/5, this->height()/10);
    HexagonButton->setGeometry(this->width()*4/5, this->height()*2/15, this->width()/5, this->height()/10);
    RectangleButton->setGeometry(this->width()*4/5, this->height()*3/15, this->width()/5, this->height()/10);
    RombButton->setGeometry(this->width()*4/5, this->height()*4/15, this->width()/5, this->height()/10);
    SquareButton->setGeometry(this->width()*4/5, this->height()*5/15, this->width()/5, this->height()/10);
    Star_fiveButton->setGeometry(this->width()*4/5, this->height()*6/15, this->width()/5, this->height()/10);
    Star_sixButton->setGeometry(this->width()*4/5, this->height()*7/15, this->width()/5, this->height()/10);
    Star_eightButton->setGeometry(this->width()*4/5, this->height()*8/15, this->width()/5, this->height()/10);
    TriangleButton->setGeometry(this->width()*4/5, this->height()*9/15, this->width()/5, this->height()/10);
    DrawButton->setGeometry(this->width()*4/5, this->height()*10/15, this->width()/5, this->height()/10);
    Label1->setGeometry(this->width()*8/10, this->height()*11/15, this->width()/10, this->height()/10);
    Label1_1->setGeometry(this->width()*9/10, this->height()*11/15, this->width()/10, this->height()/10);
    Label2->setGeometry(this->width()*8/10, this->height()*12/15, this->width()/10, this->height()/10);
    Label2_1->setGeometry(this->width()*9/10, this->height()*12/15, this->width()/10, this->height()/10);
    Label3->setGeometry(this->width()*8/10, this->height()*13/15, this->width()/10, this->height()/10);
    Label3_1->setGeometry(this->width()*9/10, this->height()*13/15, this->width()/10, this->height()/10);
    Clear->setGeometry(this->width()*4/5, this->height()*14/15+10, this->width()/5, this->height()/20);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    event->ignore();
}


void MainWindow::labelResize(){
    timer1->stop();
    Label1_1->setText(graphicsScene->p);
    Label2_1->setText(graphicsScene->s);
    Label3_1->setText(graphicsScene->xy);
    timer1->start();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start();
    QMainWindow::resizeEvent(event);
}

void MainWindow::button_circle()
{
    graphicsScene->setTypeFigure(PaintScene::CircleType);
}

void MainWindow::button_elips()
{
    graphicsScene->setTypeFigure(PaintScene::ElipsType);
}

void MainWindow::button_hexagon()
{
    graphicsScene->setTypeFigure(PaintScene::HexagonType);
}

void MainWindow::button_rectangle()
{
    graphicsScene->setTypeFigure(PaintScene::RectangleType);
}

void MainWindow::button_romb()
{
    graphicsScene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::button_square()
{
    graphicsScene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::button_star_five()
{
    graphicsScene->setTypeFigure(PaintScene::Star_FiveType);
}

void MainWindow::button_star_six()
{
    graphicsScene->setTypeFigure(PaintScene::Star_SixType);
}

void MainWindow::button_star_eight()
{
    graphicsScene->setTypeFigure(PaintScene::Star_EightType);
}

void MainWindow::button_triangle()
{
    graphicsScene->setTypeFigure(PaintScene::TriangleType);
}

void MainWindow::button_draw()
{
    graphicsScene->setTypeFigure(PaintScene::DrawType);
}

void MainWindow::clearScene(){
    graphicsScene->clear();
    graphicsScene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


