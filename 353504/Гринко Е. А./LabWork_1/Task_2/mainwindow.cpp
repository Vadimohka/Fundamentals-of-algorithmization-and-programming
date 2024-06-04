#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer();
    timer2 = new QTimer();
    timer3 = new QTimer();

    connect(timer2, SIGNAL(timeout()), this, SLOT(sizeD()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(sizeD()));
    connect(timer1, SIGNAL(timeout()), this, SLOT(sizeU()));
    connect(timer1, SIGNAL(timeout()), this, SLOT(sizeU()));

    arr[0] = triangle = new Triangle(100,100,100);
    arr[1] = rhomb = new Rhomb(200,100);
    arr[2] = circle = new Circle(100);
    arr[3] = square = new Square(100);
    arr[4] = rect = new Rectangle(200,100);
    arr[5] = hex = new Hexagon(100);
    arr[6] = parall = new Parallelogramm(250,150,30);
    arr[7] = star = new Star(5,100,50);
    arr[8] = custom = new Custom();

    widget = new QWidget(this);
    setCentralWidget(widget);
    widget->setFixedSize(1200,900);

    infoLayout = new QVBoxLayout();

    widget->setLayout(infoLayout);
    widget->setFocus();
    figure = new QGroupBox();
    figureLayout = new QVBoxLayout();
    figure->setLayout(figureLayout);
    figure->setFixedSize(200,130);

    Figure = new QLabel("Figure:");

    figures=new QComboBox();
    figures->setFixedSize(150,40);

    figures->addItem("Triangle");
    figures->addItem("Rhomb");
    figures->addItem("Circle");
    figures->addItem("Square");
    figures->addItem("Rectangle");
    figures->addItem("Hexagon");
    figures->addItem("Parallelogramm");
    figures->addItem("Star");
    figures->addItem("Custom");

    connect(figures, &QComboBox::activated, this, &MainWindow::selectFigure);

    figureLayout->addWidget(Figure);
    figureLayout->addSpacing(10);
    figureLayout->addWidget(figures);

    infoLayout->addWidget(figure);

    option = new QGroupBox();
    optionsLayout = new QVBoxLayout();
    option->setLayout(optionsLayout);
    option->setFixedSize(300,150);

    options = new QLabel("Figure options: ");

    info = new QGridLayout();

    massCenter = new QLabel("MassCenter: ");
    text1 = new QLabel();
    area = new QLabel("Area: ");
    text2 = new QLabel();
    perimetr = new QLabel("Perimeter: ");
    text3 = new QLabel();

    Center=new QLabel("Anchor point: X:");

    spinX=new QSpinBox();
    spinY=new QSpinBox();
    yLabel = new QLabel("Y:");

    connect(spinX,&QSpinBox::valueChanged,this,&MainWindow::anchorPoint);
    connect(spinY,&QSpinBox::valueChanged,this,&MainWindow::anchorPoint);

    spinX->setRange(0,600);
    spinY->setRange(0,600);

    spinX->setSingleStep(10);
    spinY->setSingleStep(10);

    spinX->setValue(0);
    spinY->setValue(0);

    spinX->setFixedSize(50,25);
    spinY->setFixedSize(50,25);

    resetCenter=new QPushButton("Reset Center");
    connect(resetCenter, &QPushButton::clicked, this, &MainWindow::ResetCenter);
    resetCenter->setFixedSize(100,20);

    info->addWidget(massCenter,0,0);
    info->addWidget(text1,0,1,1,2);
    info->addWidget(area,1,0);
    info->addWidget(text2,1,1,1,1);
    info->addWidget(perimetr,2,0);
    info->addWidget(text3,2,1);
    info->addWidget(Center, 3,0,1,1);
    info->addWidget(spinX, 3, 1);
    info->setAlignment(spinX, Qt::AlignRight);
    info->addWidget(yLabel, 3, 2,1,1);
    info->setAlignment(yLabel, Qt::AlignRight);
    info->addWidget(spinY, 3, 3,1,2);
    info->setAlignment(spinY, Qt::AlignRight);

    optionsLayout->addWidget(options);
    optionsLayout->addSpacing(1);
    optionsLayout->addLayout(info);

    infoLayout->addWidget(option);

    closeBtn = new QPushButton("Close");

    connect(closeBtn, &QPushButton::clicked, this, &MainWindow::closeButton);

    transform = new QLabel("Transform:");

    sizeUp=new QPushButton("Size +");
    if(arr[ID]->ptsCount!=0){
        connect(sizeUp,SIGNAL(pressed()), SLOT(sizeUp_on()));
        connect(sizeUp,SIGNAL(released()), SLOT(sizeUp_of()));
    }

    sizeDown= new QPushButton("Size -");
    if(arr[ID]->ptsCount!=0){
        connect(sizeDown,SIGNAL(pressed()), SLOT(sizeDown_on()));
        connect(sizeDown,SIGNAL(released()), SLOT(sizeDown_of()));
    }

    scale = new QLabel("Scale: ");
    text4 =new QLabel();
    scaleShow = new QHBoxLayout;
    scaleShow->addWidget(scale);
    scaleShow->addWidget(text4);

    sizeUp->setFixedSize(100,20);
    sizeDown->setFixedSize(100,20);

    transf = new QGroupBox();
    transformLayout= new QVBoxLayout();
    transf->setLayout(transformLayout);
    transf->setFixedSize(150,120);

    transformLayout->addWidget(transform);
    transformLayout->addWidget(sizeUp);
    transformLayout->addWidget(sizeDown);
    transformLayout->addLayout(scaleShow);

    infoLayout->addWidget(transf);

    rotate = new QLabel("Rotate:");

    rotateL = new QPushButton("Rotate Left");
    rotateR = new QPushButton("Rotate Right");

    rotateL->setFixedSize(100,20);
    rotateR->setFixedSize(100,20);

    connect(rotateL, SIGNAL(pressed()), SLOT(rotateLeft_on()));
    connect(rotateL, SIGNAL(released()), SLOT(rotateLeft_of()));
    connect(rotateR, SIGNAL(pressed()), SLOT(rotateRight_on()));
    connect(rotateR, SIGNAL(released()), SLOT(rotateRight_of()));

    rotat = new QGroupBox();
    rotateLayout = new QVBoxLayout();
    rotat->setLayout(rotateLayout);
    rotat->setFixedSize(150,90);

    rotateLayout->addWidget(rotate);
    rotateLayout->addWidget(rotateL);
    rotateLayout->addWidget(rotateR);

    infoLayout->addWidget(rotat);
    infoLayout->addWidget(resetCenter);

    closeBtn->setFixedSize(100,40);

    infoLayout->setSpacing(4);

    clear = new QPushButton("Clear");

    clear->setFixedSize(100,20);

    connect(clear,&QPushButton::clicked,this,&MainWindow::clearPts);


    sideA = new QLabel("side A: ");
    sideB = new QLabel("side B: ");
    sideC = new QLabel("side C:");
    diagonal1 = new QLabel("Diagonal 1:");
    diagonal2 = new QLabel("Diagonal 2:");
    radius = new QLabel("Radius:");
    R1 = new QLabel("Outer Radius:");
    R2 = new QLabel("Inner Radius:");
    PTS = new QLabel("Points: ");

    A = new QSpinBox();
    B = new QSpinBox();
    C = new QSpinBox();
    D = new QSpinBox();
    E = new QSpinBox();
    F = new QSpinBox();
    G = new QSpinBox();
    H = new QSpinBox();
    I = new QSpinBox();
    J = new QSpinBox();
    K = new QSpinBox();
    L = new QSpinBox();
    outerR = new QSpinBox();
    innerR = new QSpinBox();
    points = new QSpinBox();

    pen = new QComboBox();
    pen->addItem("White");
    pen->addItem("Black");
    pen->addItem("Green");
    pen->addItem("Blue");
    pen->addItem("Red");
    pen->addItem("Yellow");
    pen->addItem("Dark yellow");
    pen->addItem("Purple");
    pen->addItem("Pink");
    pen->setFixedSize(120,20);
    color = new QLabel("Pen color: ");
    color->setFixedSize(100,20);

    connect(pen, SIGNAL(currentIndexChanged(int)), this, SLOT(penColor()));

    penWidth = new QLabel("Pen Width: ");
    width = new QSpinBox();

    mode = new QLabel("Mode: ");
    mode->setFixedSize(100,20);

    drawMode = new QComboBox();
    drawMode->setFixedSize(100,20);
    drawMode->addItem("Points");
    drawMode->addItem("Lines");

    connect(drawMode,SIGNAL(currentIndexChanged(int)),this,SLOT(setDrawMode()));

    connect(width,&QSpinBox::valueChanged,this,&MainWindow::PenWidth);

    connect(A, &QSpinBox::valueChanged, this,&MainWindow::SideA);
    connect(B, &QSpinBox::valueChanged, this,&MainWindow::SideB);
    connect(C, &QSpinBox::valueChanged, this,&MainWindow::SideC);

    connect(D, &QSpinBox::valueChanged, this,&MainWindow::diag1);
    connect(E, &QSpinBox::valueChanged, this,&MainWindow::diag2);

    connect(F, &QSpinBox::valueChanged, this,&MainWindow::circleRadius);

    connect(G, &QSpinBox::valueChanged, this,&MainWindow::squareSide);

    connect(H, &QSpinBox::valueChanged, this,&MainWindow::rectWidth);
    connect(I, &QSpinBox::valueChanged, this,&MainWindow::rectHeight);

    connect(J, &QSpinBox::valueChanged, this,&MainWindow::hexRadius);

    connect(K,&QSpinBox::valueChanged,this,&MainWindow::parallsideA);
    connect(L,&QSpinBox::valueChanged,this,&MainWindow::parallsideB);

    connect(outerR,&QSpinBox::valueChanged,this,&MainWindow::starOuterR);
    connect(innerR,&QSpinBox::valueChanged,this,&MainWindow::starInnerR);

    connect(points,&QSpinBox::valueChanged,this,&MainWindow::changeStarPts);

    A->setFixedSize(100,25);
    B->setFixedSize(100,25);
    C->setFixedSize(100,25);
    D->setFixedSize(100,25);
    E->setFixedSize(100,25);
    F->setFixedSize(100,25);
    G->setFixedSize(100,25);
    H->setFixedSize(100,25);
    I->setFixedSize(100,25);
    J->setFixedSize(100,25);
    K->setFixedSize(100,25);
    L->setFixedSize(100,25);
    outerR->setFixedSize(100,25);
    innerR->setFixedSize(100,25);
    points->setFixedSize(100,25);
    width->setFixedSize(100,25);

    width->setSingleStep(1);
    A->setSingleStep(10);
    B->setSingleStep(10);
    C->setSingleStep(10);
    D->setSingleStep(10);
    E->setSingleStep(10);
    F->setSingleStep(10);
    G->setSingleStep(10);
    H->setSingleStep(10);
    I->setSingleStep(10);
    J->setSingleStep(10);
    K->setSingleStep(10);
    L->setSingleStep(10);
    outerR->setSingleStep(10);
    innerR->setSingleStep(10);
    points->setSingleStep(1);

    width->setRange(1,100);
    width->setValue(3);
    A->setRange(1,1000);
    B->setRange(1,1000);
    C->setRange(1,1000);
    D->setRange(1,1000);
    E->setRange(1,1000);
    F->setRange(1,1000);
    G->setRange(1,1000);
    H->setRange(1,1000);
    I->setRange(1,1000);
    J->setRange(1,1000);
    K->setRange(1,1000);
    L->setRange(1,1000);
    outerR->setRange(1,1000);
    innerR->setRange(1,1000);
    points->setRange(1,1000);


    infoLayout->addWidget(sideA);
    infoLayout->addWidget(A);
    infoLayout->addWidget(H);
    infoLayout->addWidget(K);
    infoLayout->addWidget(diagonal1);
    infoLayout->addWidget(D);
    infoLayout->addWidget(radius);
    infoLayout->addWidget(F);
    infoLayout->addWidget(J);
    infoLayout->addWidget(sideB);
    infoLayout->addWidget(B);
    infoLayout->addWidget(I);
    infoLayout->addWidget(L);
    infoLayout->addWidget(diagonal2);
    infoLayout->addWidget(E);
    infoLayout->addWidget(sideC);
    infoLayout->addWidget(C);
    infoLayout->addWidget(G);
    infoLayout->addWidget(R1);
    infoLayout->addWidget(outerR);
    infoLayout->addWidget(R2);
    infoLayout->addWidget(innerR);
    infoLayout->addWidget(PTS);
    infoLayout->addWidget(points);
    infoLayout->addWidget(clear);
    infoLayout->addWidget(color);
    infoLayout->addWidget(pen);
    infoLayout->addWidget(penWidth);
    infoLayout->addWidget(width);
    infoLayout->addWidget(mode);
    infoLayout->addWidget(drawMode);
    infoLayout->addStretch();

    A->setValue(100);
    B->setValue(100);
    C->setValue(100);
    D->setValue(200);
    E->setValue(100);
    F->setValue(100);
    G->setValue(100);
    H->setValue(100);
    I->setValue(200);
    J->setValue(100);
    K->setValue(200);
    L->setValue(150);
    innerR->setValue(50);
    outerR->setValue(100);
    points->setMinimum(5);

    diagonal1->hide();
    diagonal2->hide();
    radius->hide();
    R1->hide();
    R2->hide();
    PTS->hide();
    pen->hide();

    D->hide();
    E->hide();
    F->hide();
    G->hide();
    H->hide();
    I->hide();
    J->hide();
    K->hide();
    L->hide();
    outerR->hide();
    innerR->hide();
    points->hide();
    clear->hide();
    color->hide();
    width->hide();
    penWidth->hide();
    mode->hide();
    drawMode->hide();

    static bool flag=false;
    if(!flag){
        infoLayout->addWidget(closeBtn);
        flag=true;
    }

    Info();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rectWidth()
{
    double width =  H->value();
    rect->updateWidth(width);
    update();
}

void MainWindow::rectHeight()
{
    double height = I->value();
    rect->updateHeight(height);
    update();

}

void MainWindow::squareSide()
{
    double a=G->value();
    square->updateSquare(a);
    update();
}
void MainWindow::SideA()
{
    double a=A->value();
    triangle->updateSideA(a);
    update();
}

void MainWindow::SideB()
{
    double b=B->value();
    triangle->updateSideB(b);
    update();
}

void MainWindow::SideC()
{
    double c=C->value();
    triangle->updateSideC(c);
    update();
}


void MainWindow::diag1()
{
    double h1=D->value();
    rhomb->updateH1(h1);
    update();
}

void MainWindow::diag2()
{
    double h2=E->value();
    rhomb->updateH2(h2);
    update();
}

void MainWindow::circleRadius()
{
    double R=F->value();
    circle->updateCircle(R);
    update();
}

void MainWindow::hexRadius()
{
    double R=J->value();
    hex->updateHexagon(R);
    update();
}

void MainWindow::parallsideA()
{
    double k=K->value();
    parall->updateSideA(k);
    update();
}

void MainWindow::parallsideB()
{
    double l=L->value();
    parall->updateSideB(l);
    update();
}

void MainWindow::changeStarPts()
{
    double pts=points->value();
    star->updatePts(pts);
    update();
}

void MainWindow::starOuterR()
{
    double R=outerR->value();
    star->updateOuterR(R);
    update();
}

void MainWindow::starInnerR()
{
    double R = innerR->value();
    star->updateInnerR(R);
    update();
}

void MainWindow::clearPts()
{
    custom->clearPoints();
    update();
}

void MainWindow::penColor()
{
    QString colorText = pen->currentText();
    if (colorText == "White") {
        custom->color = Qt::white;
    }else if(colorText == "Black"){
        custom->color = Qt::black;
    } else if (colorText == "Green") {
        custom->color = Qt::green;
    } else if (colorText == "Blue") {
        custom->color = Qt::blue;
    } else if (colorText == "Red") {
        custom->color = Qt::red;
    } else if (colorText == "Yellow") {
        custom->color = Qt::yellow;
    } else if (colorText == "Dark yellow") {
        custom->color = Qt::darkYellow;
    } else if (colorText == "Purple") {
        custom->color = Qt::darkMagenta;
    } else if (colorText == "Pink") {
        custom->color = Qt::magenta;
    }
    update();
}

void MainWindow::PenWidth()
{
    int w=width->value();
    custom->penWidth=w;
    update();
}

void MainWindow::setDrawMode()
{
    if(drawMode->currentText() == "Points"){
        custom->drawMode = 1;
        update();
    }else if(drawMode->currentText() == "Lines"){
        custom->drawMode = 2;
        update();
    }
}

void MainWindow::selectFigure(int index)
{
    A->hide();
    B->hide();
    C->hide();
    D->hide();
    E->hide();
    F->hide();
    G->hide();
    H->hide();
    I->hide();
    J->hide();
    K->hide();
    L->hide();
    outerR->hide();
    innerR->hide();
    points->hide();
    clear->hide();
    pen->hide();
    color->hide();

    sideA->hide();
    sideB->hide();
    sideC->hide();
    diagonal1->hide();
    diagonal2->hide();
    radius->hide();
    R1->hide();
    R2->hide();
    PTS->hide();
    width->hide();
    penWidth->hide();
    mode->hide();
    drawMode->hide();

    if(figures->itemText(index) == "Triangle" ){
        ID = 0;
        sideA->show();
        A->show();
        sideB->show();
        B->show();
        sideC->show();
        C->show();
    }else if(figures->itemText(index) == "Rhomb"){
        ID = 1;
        diagonal1->show();
        D->show();
        diagonal2->show();
        E->show();
    }else if(figures->itemText(index) == "Circle"){
        ID = 2;
        radius->show();
        F->show();
    }else if(figures->itemText(index) == "Square"){
        ID = 3;
        sideA->show();
        G->show();
    }else if(figures->itemText(index) == "Rectangle"){
        ID = 4;
        sideA->show();
        H->show();
        sideB->show();
        I->show();
    }else if(figures->itemText(index) == "Hexagon"){
        ID = 5;
        radius->show();
        J->show();
    }else if(figures->itemText(index) == "Parallelogramm"){
        ID = 6;
        sideA->show();
        K->show();
        sideB->show();
        L->show();
    }else if(figures->itemText(index)=="Star"){
        ID = 7;
        R1->show();
        outerR->show();
        R2->show();
        innerR->show();
        PTS->show();
        points->show();
    }else if(figures->itemText(index)=="Custom"){
        ID = 8;
        pen->show();
        color->show();
        clear->show();
        penWidth->show();
        width->show();
        mode->show();
        drawMode->show();
    }

    infoLayout->addWidget(closeBtn);
    update();
    Info();
}
void MainWindow::ResetCenter()
{
    if(arr[ID]->ptsCount!=0){
        arr[ID]->Center();
        if(ID==5){
            hex->resetVertices();
        }
        update();
    }
}

QPointF MainWindow::anchorPoint()
{
    QPointF anchor;
    double dx = spinX->value();
    double dy = spinY->value();
    if(dx == 0 && dy == 0){
        anchor = {0,0};
    }
    anchor={dx,dy};
    return anchor;
}

void MainWindow::closeButton()
{
    close();
}

void MainWindow::sizeUp_on()
{
    timer1->start(10);
}

void MainWindow::sizeUp_of()
{
    timer1->stop();
}

void MainWindow::sizeU()
{
    if(arr[ID]->ptsCount!=0){
        arr[ID]->MassCenter();
        arr[ID]->upScale();
        update();
        Info();
    }
}

void MainWindow::sizeDown_on()
{
    timer2->start(10);
}

void MainWindow::sizeDown_of()
{
    timer2->stop();
}

void MainWindow::sizeD()
{
    if(arr[ID]->ptsCount!=0){
        arr[ID]->MassCenter();
        arr[ID]->downScale();
        update();
        Info();
    }
}

void MainWindow::rotateLeft_on()
{
    if(arr[ID]->ptsCount!=0){
        connect(timer3, SIGNAL(timeout()), this, SLOT(rotateLeft()));
        timer3->start(10);
    }
}

void MainWindow::rotateLeft_of()
{
    if(arr[ID]->ptsCount!=0){
        disconnect(timer3, SIGNAL(timeout()), this, SLOT(rotateLeft()));
        timer3->stop();
    }
}

void MainWindow::rotateLeft()
{
    if(arr[ID]->ptsCount!=0){
        arr[ID]->MassCenter();
        arr[ID]->rotateL(anchorPoint());
        update();
        Info();
    }
}

void MainWindow::rotateRight_on()
{
    if(arr[ID]->ptsCount!=0){
        connect(timer3, SIGNAL(timeout()), this, SLOT(rotateRight()));
        timer3->start(10);
    }
}

void MainWindow::rotateRight()
{
    if(arr[ID]->ptsCount!=0){
        arr[ID]->MassCenter();
        arr[ID]->rotateR(anchorPoint());
        update();
        Info();
    }
}

void MainWindow::rotateRight_of()
{
    if(arr[ID]->ptsCount!=0){
        disconnect(timer3, SIGNAL(timeout()), this, SLOT(rotateRight()));
        timer3->stop();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    arr[ID]->paint(&p);
    p.end();
    Info();
}

void MainWindow::mouseMoveEvent(QMouseEvent *p)
{
    if (p->buttons() == Qt::RightButton && ID==5 ) {
        int vertex = hex->nearestVertex(p->pos());
        hex->moveVertex(vertex, p->pos());
        update();
    }else{
        arr[ID]->mouseMoving(p);}
    update();
}



void MainWindow::Info()
{
    QPointF center=arr[ID]->MassCenter();
    text1->setText("X:"+QString::number(center.x(),'d',1)+" "+
                   "Y:" + QString::number(center.y(),'d',1));
    double areas=arr[ID]->area;
    text2->setText(QString::number(areas,'d',2));
    double perimeter = arr[ID]->perimetr;
    text3->setText(QString::number(perimeter,'d',2));
    double scale = arr[ID]->currScale;
    text4->setText(QString::number(scale,'d',2));
    if(ID==8){
        double areas=arr[ID]->area=0;
        text2->setText(QString::number(areas,'d',2));
        double perimeter = arr[ID]->perimetr=0;
        text3->setText(QString::number(perimeter,'d',2));
    }
}
