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

    widget1->setFileName("/home/kirill/Qt/lb2/T2/Iitp.txt");
    widget2->setFileName("/home/kirill/Qt/lb2/T2/Poit.txt");
    widget3->setFileName("/home/kirill/Qt/lb2/T2/Ki.txt");
    widget4->setFileName("/home/kirill/Qt/lb2/T2/Ii.txt");
    widget5->setFileName("/home/kirill/Qt/lb2/T2/Sui.txt");

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

    for (int i = 0; i < widget1->stud.size(); i++){
        qDebug() << widget1->stud[i].fio()<< " " << widget1->stud[i].mat() << " "
                 << widget1->stud[i].phys() << " " << widget1->stud[i].rus() << " "
                 << widget1->stud[i].at() << " " << widget1->stud[i].avarage();
    }

    for (int i = 0; i < widget2->stud.size(); i++){
        qDebug() << widget2->stud[i].fio()<< " " << widget2->stud[i].mat() << " "
                 << widget2->stud[i].phys() << " " << widget2->stud[i].rus() << " "
                 << widget2->stud[i].at() << " " << widget2->stud[i].avarage();
    }

    for (int i = 0; i < widget3->stud.size(); i++){
        qDebug() << widget3->stud[i].fio()<< " " << widget3->stud[i].mat() << " "
                 << widget3->stud[i].phys() << " " << widget3->stud[i].rus() << " "
                 << widget3->stud[i].at() << " " << widget3->stud[i].avarage();
    }


    for (int i = 0; i < widget4->stud.size(); i++){
        qDebug() << widget4->stud[i].fio()<< " " << widget4->stud[i].mat() << " "
                 << widget4->stud[i].phys() << " " << widget4->stud[i].rus() << " "
                 << widget4->stud[i].at() << " " << widget4->stud[i].avarage();
    }

    for (int i = 0; i < widget5->stud.size(); i++){
        qDebug() << widget5->stud[i].fio()<< " " << widget5->stud[i].mat() << " "
                 << widget5->stud[i].phys() << " " << widget5->stud[i].rus() << " "
                 << widget5->stud[i].at() << " " << widget5->stud[i].avarage();
    }

    navToolBar = new QToolBar(this);
    QActionGroup *actionGroup = new QActionGroup(centralWidget);
    actionGroup->setExclusive(true);

    action1 = new QAction();
    action2 = new QAction();
    action3 = new QAction();
    action4 = new QAction();
    action5 = new QAction();

    action1 = navToolBar->addAction("ИиТП");
    action1->setCheckable(true);
    action1->setActionGroup(actionGroup);
    action2 = navToolBar->addAction("ПОИТ");
    action2->setCheckable(true);
    action2->setActionGroup(actionGroup);
    action3 = navToolBar->addAction("КИ");
    action3->setCheckable(true);
    action3->setActionGroup(actionGroup);
    action4 = navToolBar->addAction("ИИ");
    action4->setCheckable(true);
    action4->setActionGroup(actionGroup);
    action5 = navToolBar->addAction("СУИ");
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

