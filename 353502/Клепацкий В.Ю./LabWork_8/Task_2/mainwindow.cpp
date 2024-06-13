#include "mainwindow.h"
#include "Heap.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qtreewidget.h>

std::unique_ptr<Heap> createArrHeap();

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
    , solver(nullptr)
    , lib("./libTask_2_TreeHeap.so")
{
    ui->setupUi(this);
    lib.load();

    solver = createArrHeap();
    randomize();

    connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randomize);
    connect(ui->clearBtn, &QPushButton::clicked, [this]() {
        solver->clear();
        update();
    });

    connect(ui->popBtn, &QPushButton::clicked, [this]() {
        ui->elem->setValue(solver->pop());
        update();
    });

    connect(ui->pushBtn, &QPushButton::clicked, [this]() {
        solver->push(ui->elem->value());
        update();
    });

    connect(ui->treeBtn, &QPushButton::clicked, [this]() {
        solver = createArrHeap();
        randomize();
    });

    connect(ui->arrBtn, &QPushButton::clicked, [this]() {
        solver = createArrHeap();
        randomize();
    });

    connect(ui->treeBtn, &QPushButton::clicked, [this]() {
        solver = createArrHeap();
        randomize();
    });

    update();
}

class QTreeHeapInspector : public HeapInspector
{
private:
    QTreeWidgetItem *item;

public:
    QTreeHeapInspector(QTreeWidgetItem *item)
        : item(item)
    {
        item->setText(0, "Node");
    }
    ~QTreeHeapInspector() {}

    virtual void setVal(int val) { item->setText(1, QString::number(val)); };

    virtual void setPos(int val) { item->setText(0, QString::number(val)); };

    virtual HeapInspector *createChild()
    {
        return new QTreeHeapInspector(new QTreeWidgetItem(item));
    };
};

void MainWindow::update()
{
    ui->popBtn->setEnabled(!solver->empty());

    QTreeWidgetItem *rootItem = new QTreeWidgetItem();
    solver->inspect(new QTreeHeapInspector(rootItem));
    rootItem->setText(0, "Heap");
    ui->tree->clear();
    ui->tree->addTopLevelItem(rootItem);
    ui->tree->setColumnWidth(0, 400);
    ui->tree->expandAll();
}

void MainWindow::randomize()
{
    for (int i = 0; i < 32; i++) {
        solver->push(rand() % 1024);
    }
    update();
}
