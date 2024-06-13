#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    triangle = new Triangle();
    circle = new Circle();
    romb = new Romb();
    square = new Square();
    rect = new Rectangle();
    star5 = new FiveStar();
    star6 = new SixStar();
    star8 = new EightStar();
    hex = new Hexagon();
    regpol = new RegularPolygon(9);
    paint = new Paint();

    tabs = new QTabWidget();
    tabs->addTab(triangle, "Треугольник");
    tabs->addTab(circle, "Круг");
    tabs->addTab(romb, "Ромб");
    tabs->addTab(square, "Квадрат");
    tabs->addTab(rect, "Прямоугольник");
    tabs->addTab(star5, "Пятиугольная звезда");
    tabs->addTab(star6, "Шестиконечная звезда");
    tabs->addTab(star8, "Восьмиконечная звезда");
    tabs->addTab(hex, "Шестиугольник");
    tabs->addTab(regpol, "Правильный многоугольник");
    tabs->addTab(paint, "Рисовалка");
    setCentralWidget(tabs);
    this->setFixedSize(2500, 1300);
    this->setWindowTitle("Фигуры");
    connect(tabs, &QTabWidget::currentChanged, [=]{
        triangle->closeAllWindows();
        circle->closeAllWindows();
        romb->closeAllWindows();
        square->closeAllWindows();
        rect->closeAllWindows();
        star5->closeAllWindows();
        star6->closeAllWindows();
        star8->closeAllWindows();
        hex->closeAllWindows();
        regpol->closeAllWindows();
        paint->closeAllWindows();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
    triangle->closeAllWindows();
    circle->closeAllWindows();
    romb->closeAllWindows();
    square->closeAllWindows();
    rect->closeAllWindows();
    star5->closeAllWindows();
    star6->closeAllWindows();
    star8->closeAllWindows();
    hex->closeAllWindows();
    regpol->closeAllWindows();
    paint->closeAllWindows();
}

