#include "mainwindow.h"
#include "HanoiScene.h"
#include "ui_mainwindow.h"
#include <qmainwindow.h>
#include <qpushbutton.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().size());
  scene = new HanoiScene(ui->hanoiView->geometry());
  ui->hanoiView->setScene(scene);
  ui->hanoiView->scale(1, -1);

  ui->hanoiActions->setColumnCount(2);
  ui->hanoiActions->setHorizontalHeaderItem(0, new QTableWidgetItem("From"));
  ui->hanoiActions->setHorizontalHeaderItem(1, new QTableWidgetItem("To"));
  ui->hanoiActions->setEditTriggers(QTableWidget::NoEditTriggers);
  ui->hanoiActions->setSelectionBehavior(QTableWidget::SelectRows);
  ui->hanoiActions->setSelectionMode(QTableWidget::SingleSelection);


  reset();
  changeSpeed();

  connect(scene, &HanoiScene::animationFinished,
  this, &MainWindow::nextAction);

  connect(ui->playBtn, &QPushButton::clicked,
  this, &MainWindow::start);
  connect(ui->stopBtn, &QPushButton::clicked,
    this, &MainWindow::reset);
  connect(ui->pauseBtn, &QPushButton::clicked,
  this, &MainWindow::pause);

  connect(ui->speedSpinBox, &QSpinBox::valueChanged,
  this, &MainWindow::changeSpeed);

  connect(ui->hanoiActions, &QTableWidget::itemSelectionChanged,
  this, &MainWindow::prohibitItemSelection);
}


MainWindow::~MainWindow() {
  delete ui;
  delete scene;
}

void MainWindow::prohibitItemSelection(){
  ui->hanoiActions->selectRow(cur >= actions.size() ? actions.size()-1 : cur);
}

void MainWindow::refreshTable(){
  ui->hanoiActions->setRowCount(actions.size());
  for(int i = 0; i < actions.size(); ++i){
    auto curAction = actions[i];
    auto fromItem = new QTableWidgetItem(QString::number(curAction.first+1));
    ui->hanoiActions->setItem(i, 0,  fromItem);

    auto toItem = new QTableWidgetItem(QString::number(curAction.second+1));
    ui->hanoiActions->setItem(i, 1,  toItem);
  }
  ui->hanoiActions->selectRow(cur);
}


void MainWindow::changeSpeed(){
  scene->setSpeed(ui->speedSpinBox->value());
}


void MainWindow::reset(){
  pause();
  auto numRings  = ui->ringsSpinBox->value();
  scene->resetRings(numRings);
  HanoiLogic logic;
  actions = logic.Hanoi(numRings);
  cur = 0;
  refreshTable();
}

void MainWindow::pause(){
  paused = true;
}

void MainWindow::start() {
  if(cur >= actions.size()){
    return;
  }
  auto action = actions[cur];
  paused = false;
  scene->startRingMove(action.first, action.second);
}

void MainWindow::nextAction(){
  cur++;
  ui->hanoiActions->selectRow(cur);
  if(cur == actions.size() || paused){
    return;
  }

  auto action = actions[cur];
  scene->startRingMove(action.first, action.second);
}
