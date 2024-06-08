#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    stackedWidget = new QStackedWidget(centralWidget);

    widget1 = new widget(centralWidget);
    widget2 = new widget(centralWidget);
    widget3 = new widget(centralWidget);
    widget4 = new widget(centralWidget);
    widget5 = new widget(centralWidget);

    widget1->setFileName("/home/andrey/Qt_labs/Lab2/Task_2/Task2/F1.txt");
    widget2->setFileName("/home/andrey/Qt_labs/Lab2/Task_2/Task2/F2.txt");
    widget3->setFileName("/home/andrey/Qt_labs/Lab2/Task_2/Task2/F3.txt");
    widget4->setFileName("/home/andrey/Qt_labs/Lab2/Task_2/Task2/F4.txt");
    widget5->setFileName("/home/andrey/Qt_labs/Lab2/Task_2/Task2/F5.txt");
    widget1->parce();
    widget2->parce();
    widget3->parce();
    widget4->parce();
    widget5->parce();

    stackedWidget->addWidget(widget1);
    stackedWidget->addWidget(widget2);
    stackedWidget->addWidget(widget3);
    stackedWidget->addWidget(widget4);
    stackedWidget->addWidget(widget5);


    navToolBar = new QToolBar(this);
    QActionGroup *actionGroup = new QActionGroup(centralWidget);
    actionGroup->setExclusive(true);

    action1 = new QAction();
    action2 = new QAction();
    action3 = new QAction();
    action4 = new QAction();
    action5 = new QAction();

    action1 = navToolBar->addAction("Специальность1");
    action1->setCheckable(true);
    action1->setActionGroup(actionGroup);
    action2 = navToolBar->addAction("Специальность2");
    action2->setCheckable(true);
    action2->setActionGroup(actionGroup);
    action3 = navToolBar->addAction("Специальность3");
    action3->setCheckable(true);
    action3->setActionGroup(actionGroup);
    action4 = navToolBar->addAction("Специальность4");
    action4->setCheckable(true);
    action4->setActionGroup(actionGroup);
    action5 = navToolBar->addAction("Специальность5");
    action5->setCheckable(true);
    action5->setActionGroup(actionGroup);

    connect(action1, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(0);
    });
    connect(action2, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(1);
    });
    connect(action3, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(2);
    });
    connect(action4, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(3);
    });
    connect(action5, &QAction::triggered, [=]() {
        stackedWidget->setCurrentIndex(4);
    });

    action1->setChecked(true);

    QString style = "QToolBar QToolButton:checked { border: 2px solid white; }";
    navToolBar->setStyleSheet(style);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setMenuBar(navToolBar);
    mainLayout->addWidget(stackedWidget);


    for (int i = 0; i < widget1->stud.size(); i++){
        widget1->addComboBox(widget1->stud[i].fio());
    }

    for (int i = 0; i < widget2->stud.size(); i++){
        widget2->addComboBox(widget2->stud[i].fio());
    }

    for (int i = 0; i < widget3->stud.size(); i++){
        widget3->addComboBox(widget3->stud[i].fio());
    }

    for (int i = 0; i < widget4->stud.size(); i++){
        widget4->addComboBox(widget4->stud[i].fio());
    }

    for (int i = 0; i < widget5->stud.size(); i++){
        widget5->addComboBox(widget5->stud[i].fio());
    }

    widget1->studTable();
    widget2->studTable();
    widget3->studTable();
    widget4->studTable();
    widget5->studTable();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

