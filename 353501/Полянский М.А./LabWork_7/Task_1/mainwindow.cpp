#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  
  connect(ui->randBtn, &QPushButton::clicked, [this](){
    q.clear();
    for(int i = 0; i< 20; ++i){
      int sign = rand() % 2 == 0 ? 1 : -1;
      q.pushBack(rand()%500 * sign);
    }
    redraw();
  });

  connect(ui->popBack, &QPushButton::clicked, [this](){
    if(!q.isEmpty()){
      setElements(q.PopBack());
      redraw();
    }

  });
  connect(ui->popFront, &QPushButton::clicked, [this](){
    if(!q.isEmpty()){
      setElements(q.PopFront());
      redraw();
    }

  });
  connect(ui->clearBtn, &QPushButton::clicked, [this](){
    q.clear();
    redraw();
  });

  connect(ui->pushBack, &QPushButton::clicked, [this](){
    q.pushBack(ui->inp->value());
    redraw();
  });
  connect(ui->pushFront, &QPushButton::clicked, [this](){
    q.pushFront(ui->inp->value());
    redraw();
  });
  
  connect(ui->deleteneg, &QPushButton::clicked, [this](){
    for(auto el : q){
      if(el < 0){
        q.deleteN(el);
      }
    }
    redraw();
  });
}



void MainWindow::redraw() {
  ui->popBack->setEnabled(!q.isEmpty());
  ui->popFront->setEnabled(!q.isEmpty());

  ui->deqEls->clear();
  for (auto el : q) {
    ui->deqEls->addItem(QString::number(el));
  }
}
int MainWindow::getElements() { return ui->inp->value(); }
void MainWindow::setElements(int val) { ui->inp->setValue(val); }



