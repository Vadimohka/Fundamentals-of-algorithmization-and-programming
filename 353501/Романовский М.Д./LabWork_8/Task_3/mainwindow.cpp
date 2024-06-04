#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>


const QString alpha =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

QString randString() {
  QString str;
  int lim = rand() % 10 + 2;
  for (int i = 0; i < lim; i++) {
    if (i % 4 == 3)
      str += '_';
    else
      str += alpha[rand() % alpha.size()];
  }
  return str;
}

MainWindow::MainWindow() : ui(new Ui::MainWindow), map() {
  ui->setupUi(this);

  connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearClicked);
  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randClicked);
  connect(ui->getBtn, &QPushButton::clicked, this, &MainWindow::getClicked);
  connect(ui->setBtn, &QPushButton::clicked, this, &MainWindow::setClicked);
  connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delClicked);
  
  map[123] = "sdfsdfs";
  map[33123] = "ssfdsfd";
  
  randClicked();
}

class QTreeInspector : public RBTree<int, QString>::Inspector {
private:
  QTreeWidgetItem *item;

public:
  QTreeInspector(QTreeWidgetItem *item) : item(item) {
    item->setText(0, "Node");
  }
  ~QTreeInspector() {}

  virtual void setVal(const QString& val) { item->setText(2, val); };

  virtual void setKey(const int& val) { item->setText(1, QString::number(val)); };

  virtual void setMode(int val) { 
    if(val == -1) {
      item->setText(0, "No node");
    }
    if(val == 0)
    {
      item->setText(0, "Black"); 
    }
    if(val == 1)
    {
      item->setText(0, "Red"); 
    }
  };

  virtual void setNone() {
  }

  virtual RBTree<int, QString>::Inspector *createChild() {
    return new QTreeInspector(new QTreeWidgetItem(item));
  };
};


void MainWindow::update() {
  QTreeWidgetItem *rootItem = new QTreeWidgetItem();
  map.inspect(new QTreeInspector(rootItem));
  rootItem->setText(0, "RB Tree");
  ui->tree->clear();
  ui->tree->addTopLevelItem(rootItem);
  ui->tree->setColumnWidth(0, 400);
  ui->tree->expandAll();
  // solver->fillEnties(ui->tree);
}

void MainWindow::clearClicked() {
  map.clear();
  update();
}

void MainWindow::randClicked() {
  map.clear();
  for (int i = 0; i < 64; i++) {
    map.insert(rand() % 1024, randString());
  }
  update();
}

void MainWindow::getClicked() {
  int key = ui->key->value();
  QString val = "NOT_FOUND";
  if (map.contains(key))
    val = map.get(key);
  ui->value->setText(val);
}

void MainWindow::setClicked() {
  int key = ui->key->value();
  QString val = ui->value->text();
  map.insert(key, val);
  update();
}

void MainWindow::delClicked() {
  int key = ui->key->value();
  QString val = "NOT_FOUND";
  if (map.contains(key))
    val = map.get(key);
  ui->value->setText(val);
  map.erase(key);
  update();
}

void MainWindow::balanceClicked() {
  // solver->balance();
  // update();
}