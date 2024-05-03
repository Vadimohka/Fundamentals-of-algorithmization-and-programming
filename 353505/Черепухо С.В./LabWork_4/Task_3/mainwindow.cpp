#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    _originalVector(new ArrayTable(this)),
    _medianVector(new ArrayTable(this)),
    _mainLayout(new QHBoxLayout(this))
{
    ui->setupUi(this);

    _mainLayout->addWidget(_originalVector);
    _mainLayout->addWidget(_medianVector);
    ui->centralwidget->setLayout(_mainLayout);
    _medianVector->setReadOnly(true);
    _medianVector->setTableOnly(true);

    connect(_originalVector, SIGNAL(vectorChanged()), SLOT(slotUpdateVector()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotUpdateVector()
{
    _medianVector->setVector(getMedianVector(_originalVector->vector()));
}
