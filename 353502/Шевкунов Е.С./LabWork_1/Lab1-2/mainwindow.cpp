#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector <Figure*> triangle,
        circle,
        rhombus,
        square,
        rectangle,
        star_5,
        star_6,
        star_8;
    all_figures[0] = triangle;
    all_figures[1] = circle,
        all_figures[2] = rhombus,
        all_figures[3] = square,
        all_figures[4] = rectangle,
        all_figures[5] = star_8,
        all_figures[6] = star_6,
        all_figures[7] = star_5;

    ui->figuresBox->addItems(
        {
            "Triangle",
            "Circle",
            "Rhombus",
            "Square",
            "Rectangle",
            "Eight pointed star (premium only)",
            "Six pointed star (premium only)",
            "Five pointed star"
        });

    selected_figure = {-1, -1};
    has_points_now = 0;
    selected_type = SelectedType::triangle;
    selected_action = createA;

    QGridLayout* main_layout = new QGridLayout (this);
    main_layout->addWidget(ui->graphicsView, 0, 0, 4, 4);
    main_layout->addWidget(ui->figuresBox, 4, 0, 1, 1);
    main_layout->addWidget(ui->formLayoutWidget, 1, 4, 1, 1);
    main_layout->addWidget(ui->horizontalLayoutWidget, 4, 1, 1, 2);
    main_layout->addWidget(ui->colorsBox, 6, 0, 1, 1);

    ui->createButton->setText("Create");
    ui->moveButton->setText("Move");
    ui->rotateButton->setText("Rotate");
    ui->scaleButton->setText("Scale");

    ui->createButton->setChecked(true);

    connect(ui->figuresBox, SIGNAL(currentIndexChanged(int)), SLOT(slotFigureChanged()));
    connect(ui->createButton, SIGNAL(clicked(bool)), SLOT(slotActionChanged()));
    connect(ui->moveButton, SIGNAL(clicked(bool)), SLOT(slotActionChanged()));
    connect(ui->rotateButton, SIGNAL(clicked(bool)), SLOT(slotActionChanged()));
    connect(ui->scaleButton, SIGNAL(clicked(bool)), SLOT(slotActionChanged()));

    connect(ui->colorsBox, SIGNAL(currentIndexChanged(int)), SLOT(slotColorChanged()));

    scene = new Scene(0, 0, 1400, 700, this);
    connect(scene, SIGNAL(signalMousePressEvent(QGraphicsSceneMouseEvent*)), SLOT(slotMousePress(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(signalMouseReleaseEvent(QGraphicsSceneMouseEvent*)), SLOT(slotMouseRelease(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(signalMouseMoveEvent(QGraphicsSceneMouseEvent*)), SLOT(slotMouseMove(QGraphicsSceneMouseEvent*)));
    connect(scene, SIGNAL(signalKeyPressEvent(QKeyEvent*)), SLOT(slotKeyPress(QKeyEvent*)));
    ui->graphicsView->setScene(scene);

    validator = new QIntValidator(-999, 999, this);

    ui->topEdit->setValidator(validator);
    ui->bottomEdit->setValidator(validator);
    main_layout->addWidget(ui->formLayoutWidget_2, 2, 4, 1, 1);
    ui->centralwidget->setLayout(main_layout);

    ui->bottomEdit->hide();
    ui->bottomLbl->hide();

    connect(ui->bottomEdit, SIGNAL(textEdited(const QString &)), SLOT(slotChangeParameter(const QString &)));
    connect(ui->topEdit, SIGNAL(textEdited(const QString &)), SLOT(slotChangeParameter(const QString &)));

    brush = Qt::gray;

    updateParameters();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotMousePress(QGraphicsSceneMouseEvent* mouse_event)
{
    Figure *item = (Figure*) scene->itemAt(mouse_event->scenePos(), {});

    if (mouse_event->button() == Qt::LeftButton)
    {
        ++has_points_now;
        points_for_creation.append(mouse_event->scenePos().toPoint());

        if (selected_action == createA)
        {
            if (selected_type == none_type)
            {
                has_points_now = 0;
                points_for_creation.clear();
            }
            else
            {
                if (has_points_now > 1)
                {
                    drawing_lines[has_points_now - 2] = new QGraphicsLineItem
                        (
                            points_for_creation[has_points_now - 1].x(), points_for_creation[has_points_now - 1].y(),
                            points_for_creation[has_points_now - 2].x(), points_for_creation[has_points_now - 2].y()
                            );
                    scene->addItem(drawing_lines[has_points_now - 2]);
                }


                if (has_points_now >= require_to_create[(int)selected_type])
                {
                    for (short i = 0; i < has_points_now - 1; ++i)
                    {
                        scene->removeItem(drawing_lines[i]);
                    }


                    createFigure();

                    has_points_now = 0;
                    points_for_creation.clear();
                }
            }
        }
    }
    else if (mouse_event->button() == Qt::RightButton && item)
    {
        emit signalNotSelected();
        disconnect(this, SIGNAL(signalIsSelected()), item, SLOT(slotIsSelected()));

        if (item->getID() != selected_figure)
        {
            connect(this, SIGNAL(signalIsSelected()), item, SLOT(slotIsSelected()));
            emit signalIsSelected();
        }
        else
        {
            selected_figure = {-1, -1};
            updateInfo();
            updateParameters();
        }

        scene->update();
    }
}

void MainWindow::slotMouseRelease(QGraphicsSceneMouseEvent* mouse_event)
{
    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        all_figures[selected_figure.first][selected_figure.second]->updateParameters();
    }

    if (selected_action != createA)
    {
        has_points_now = 0;
        points_for_creation.clear();
    }
}

void MainWindow::slotMouseMove(QGraphicsSceneMouseEvent* mouse_event)
{
    if  (
        selected_action != none_action &&
        selected_action != createA &&
        has_points_now >= 1 &&
        QPair<short, short>{-1, -1} != selected_figure
        )
    {
        QPoint t = mouse_event->scenePos().toPoint();

        switch (selected_action)
        {
        case moveA:
            all_figures[selected_figure.first][selected_figure.second]->move(t - points_for_creation[0]);
            break;
        case rotateA:
            all_figures[selected_figure.first][selected_figure.second]->rotate(t - points_for_creation[0]);
            break;
        case scaleA:
            all_figures[selected_figure.first][selected_figure.second]->scale(t - points_for_creation[0]);
            break;
        }

        updateInfo();
        updateParameters();
    }
}

void MainWindow::slotKeyPress(QKeyEvent* event)
{
    if (QPair<short, short>{-1, -1} != selected_figure && event->key() == Qt::Key_Delete)
    {
        scene->removeItem(all_figures[selected_figure.first][selected_figure.second]);
        delete all_figures[selected_figure.first][selected_figure.second];

        selected_figure = QPair<short, short>{-1, -1};

        updateInfo();
        updateParameters();
    }
}


//**********************************************


void MainWindow::setSelectedFigure(QPair<short,short> ID)
{
    emit signalNotSelected();
    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        disconnect(this, SIGNAL(signalNotSelected()), all_figures[selected_figure.first][selected_figure.second], SLOT(slotNotSelected()));
    }
    connect(this, SIGNAL(signalNotSelected()), all_figures[ID.first][ID.second], SLOT(slotNotSelected()));////////////////
    selected_figure = ID;

    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        all_figures[selected_figure.first][selected_figure.second]->setPreviousParameters();
    }

    updateInfo();
    updateParameters();
    scene->update();

    if (selected_figure.first == 0 ||
        selected_figure.first == 2 ||
        selected_figure.first == 4 ||
        selected_figure.first == 6)
    {
        ui->bottomEdit->show();
        ui->bottomLbl->show();
        ui->topLbl->setText("The first parameter: ");
        ui->bottomLbl->setText("The second parameter: ");
    }
    else
    {
        ui->bottomEdit->hide();
        ui->bottomLbl->hide();
        ui->topLbl->setText("The parameter: ");
        ui->bottomEdit->setText("9");
    }
}

void MainWindow::slotFigureChanged()
{
    selected_type = (SelectedType) ui->figuresBox->currentIndex();

    for (short i = 0; i < has_points_now - 1; ++i)
    {
        scene->removeItem(drawing_lines[i]);
    }
    has_points_now = 0;
    points_for_creation.clear();

    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        all_figures[selected_figure.first][selected_figure.second]->setPreviousParameters();
    }

    ui->createButton->setChecked(true);
    slotActionChanged();

    updateParameters();
}

void MainWindow::slotChangeParameter(const QString &)
{
    if (QPair<short, short>{-1, -1} == selected_figure)
    {
        return;
    }

    if (selected_type != triangle)
    {
        if (ui->bottomEdit->text().toInt() < 9)
        {
            ui->bottomEdit->setText("9");
        }
        if (ui->topEdit->text().toInt() < 9)
        {
            ui->topEdit->setText("9");
        }
    }


    all_figures[selected_figure.first][selected_figure.second]->setParameter(QPair<int, int>(ui->topEdit->text().toInt(),
                                                                                             ui->bottomEdit->text().toInt()));
    all_figures[selected_figure.first][selected_figure.second]->updateParameters();

    updateInfo();
    scene->update();
}


void MainWindow::slotActionChanged()
{
    if (ui->createButton->isChecked())
    {
        selected_action = createA;
    }
    else if (ui->moveButton->isChecked())
    {
        selected_action = moveA;
    }
    else if (ui->rotateButton->isChecked())
    {
        selected_action = rotateA;
    }
    else if (ui->scaleButton->isChecked())
    {
        selected_action = scaleA;
    }
    else
    {
        selected_action = none_action;
    }

    for (short i = 0; i < has_points_now - 1; ++i)
    {
        scene->removeItem(drawing_lines[i]);
    }
    has_points_now = 0;
    points_for_creation.clear();

    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        all_figures[selected_figure.first][selected_figure.second]->setPreviousParameters();
    }
}


void MainWindow::slotColorChanged()
{
    switch (ui->colorsBox->currentIndex())
    {
    case 0:
        brush = Qt::gray;
        break;
    case 1:
        brush = Qt::red;
        break;
    case 2:
        brush = Qt::blue;
        break;
    case 3:
        brush = Qt::green;
        break;
    case 4:
        brush = Qt::yellow;
        break;
    }

    for (short i = 0; i < has_points_now - 1; ++i)
    {
        scene->removeItem(drawing_lines[i]);
    }
    has_points_now = 0;
    points_for_creation.clear();

    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        all_figures[selected_figure.first][selected_figure.second]->setPreviousParameters();
    }
}


//**********************************************


void MainWindow::createFigure()
{
    if (selected_type != triangle)
    {
        temp.first.rx() = (points_for_creation.at(0).x() >= points_for_creation.at(1).x() ? points_for_creation.at(1).x() :
                               points_for_creation.at(0).x());
        temp.second.rx() = (points_for_creation.at(0).x() < points_for_creation.at(1).x() ? points_for_creation.at(1).x() :
                                points_for_creation.at(0).x());

        temp.first.ry() = (points_for_creation.at(0).y() >= points_for_creation.at(1).y() ? points_for_creation.at(1).y() :
                               points_for_creation.at(0).y());
        temp.second.ry() = (points_for_creation.at(0).y() < points_for_creation.at(1).y() ? points_for_creation.at(1).y() :
                                points_for_creation.at(0).y());

        points_for_creation[0] = temp.first;
        points_for_creation[1] = temp.second;
    }

    switch (selected_type)
    {
    case triangle:
        all_figures[0].append(new Triangle (points_for_creation,
                                           QPair<short, short> (0, (short) all_figures[0].size()),
                                           brush,
                                           this));
        scene->addItem(all_figures[0][all_figures[0].size() - 1]);
        break;

    case circle:
        all_figures[1].append(new Circle (points_for_creation,
                                         QPair<short, short> (1, (short) all_figures[1].size()),
                                         brush,
                                         this));
        scene->addItem(all_figures[1][all_figures[1].size() - 1]);
        break;

    case rhombus:
        all_figures[2].append(new Rhombus (points_for_creation,
                                          QPair<short, short> (2, (short) all_figures[2].size()),
                                          brush,
                                          this));
        scene->addItem(all_figures[2][all_figures[2].size() - 1]);
        break;

    case square:
        all_figures[3].append(new Square (points_for_creation,
                                         QPair<short, short> (3, (short) all_figures[3].size()),
                                         brush,
                                         this));
        scene->addItem(all_figures[3][all_figures[3].size() - 1]);
        break;

    case rectangle:
        all_figures[4].append(new Rectangle (points_for_creation,
                                            QPair<short, short> (4, (short) all_figures[4].size()),
                                            brush,
                                            this));
        scene->addItem(all_figures[4][all_figures[4].size() - 1]);
        break;

    case star_5:
        all_figures[7].append(new Star (points_for_creation,
                                       5,
                                       QPair<short, short> (7, (short) all_figures[7].size()),
                                       brush,
                                       this));
        scene->addItem(all_figures[7][all_figures[7].size() - 1]);
        break;

    case star_6:
        all_figures[8].append(new Star (points_for_creation,
                                       6,
                                       QPair<short, short> (8, (short) all_figures[8].size()),
                                       brush,
                                       this));
        scene->addItem(all_figures[8][all_figures[8].size() - 1]);
        break;

    case star_8:
        all_figures[9].append(new Star (points_for_creation,
                                       8,
                                       QPair<short, short> (9, (short) all_figures[9].size()),
                                       brush,
                                       this));
        scene->addItem(all_figures[9][all_figures[9].size() - 1]);
        break;

    default:
        break;
    }
    //для остальных классов фигур
}

void MainWindow::updateInfo()
{
    if (QPair<short, short>{-1, -1} == selected_figure)
    {
        ui->CenterText->setText("-");
        ui->PerimeterText->setText("-");
        ui->SquareText->setText("-");
        return;
    }

    QPointF t = all_figures[selected_figure.first][selected_figure.second]->getCenter();
    ui->CenterText->setText(QString().setNum(t.x()) + ", " + QString().setNum(t.y()));
    ui->PerimeterText->setNum(all_figures[selected_figure.first][selected_figure.second]->getPerimeter());
    ui->SquareText->setNum(all_figures[selected_figure.first][selected_figure.second]->getSquare());
}

void MainWindow::updateParameters()
{
    int type = (selected_figure == QPair<short, short>(-1, -1) ? (int) selected_type : selected_figure.first);

    if (type == triangle || type == ellipse || type == rhombus || type == rectangle)
    {
        ui->bottomEdit->show();
        ui->bottomLbl->show();
        ui->topLbl->setText("The first parameter: ");
        ui->bottomLbl->setText("The second parameter: ");
    }
    else
    {
        ui->bottomEdit->hide();
        ui->bottomLbl->hide();
        ui->topLbl->setText("The parameter: ");
        ui->bottomEdit->setText("9");
    }

    if (QPair<short, short>{-1, -1} != selected_figure)
    {
        ui->topEdit->setText(QString::number(all_figures[selected_figure.first][selected_figure.second]->getParameter().first));
        ui->bottomEdit->setText(QString::number(all_figures[selected_figure.first][selected_figure.second]->getParameter().second));
    }
    else
    {
        ui->topEdit->setText("0");
        ui->bottomEdit->setText("0");
    }
}
