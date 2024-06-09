#include "mainwindow.h"
#include "Heap.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qtreewidget.h>

std::unique_ptr<Heap> createArrHeap();

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), bst(nullptr), lib("./libTask_2_TreeHeap.so") {
  ui->setupUi(this);
  lib.load();

  bst = createArrHeap();
  randomize();

  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randomize);
  connect(ui->clearBtn, &QPushButton::clicked, [this]() {
    bst->clear();
    update();
  });

  connect(ui->popBtn, &QPushButton::clicked, [this]() {
    ui->elem->setValue(bst->pop());
    update();
  });

  connect(ui->pushBtn, &QPushButton::clicked, [this]() {
    bst->push(ui->elem->value());
    update();
  });

  connect(ui->treeBtn, &QPushButton::clicked, [this]() {
    bst = createArrHeap();
    randomize();
  });

  connect(ui->arrBtn, &QPushButton::clicked, [this]() {
    bst = createArrHeap();
    randomize();
  });

  connect(ui->treeBtn, &QPushButton::clicked, [this]() {
    std::unique_ptr<Heap> (*createTreeHeap)() =
        reinterpret_cast<std::unique_ptr<Heap> (*)()>(
            lib.resolve("createTreeHeap"));
    bst = createTreeHeap();
    randomize();
  });

  update();
}

class QTreeHeapInspector : public HeapInspector {
private:
  QTreeWidgetItem *item;

public:
  QTreeHeapInspector(QTreeWidgetItem *item) : item(item) {
    item->setText(0, "Node");
  }
  ~QTreeHeapInspector() {}

  virtual void setVal(int val) { item->setText(1, QString::number(val)); };

  virtual void setPos(int val) { item->setText(0, QString::number(val)); };

  virtual HeapInspector *createChild() {
    return new QTreeHeapInspector(new QTreeWidgetItem(item));
  };
};

void MainWindow::update() {
  ui->popBtn->setEnabled(!bst->empty());

  QTreeWidgetItem *rootItem = new QTreeWidgetItem();
  bst->inspect(new QTreeHeapInspector(rootItem));
  rootItem->setText(0, "Heap");
  ui->tree->clear();
  ui->tree->addTopLevelItem(rootItem);
  ui->tree->setColumnWidth(0, 400);
  ui->tree->expandAll();
}

void MainWindow::randomize() {
  for (int i = 0; i < 32; i++) {
    bst->push(rand() % 100);
  }
  update();
}