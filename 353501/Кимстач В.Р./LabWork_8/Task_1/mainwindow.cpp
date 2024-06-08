

#include <stack>
#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    connect(ui->insertApushButton, SIGNAL(clicked()), this, SLOT(A_insert()));
    connect(ui->removeApushButton, SIGNAL(clicked(bool)), this, SLOT(A_remove()));
    connect(ui->findApushButton, SIGNAL(clicked(bool)), this, SLOT(A_find()));
    connect(ui->insertBpushButton, SIGNAL(clicked()), this, SLOT(B_insert()));
    connect(ui->removeBpushButton, SIGNAL(clicked(bool)), this, SLOT(B_remove()));
    connect(ui->findBpushButton, SIGNAL(clicked(bool)), this, SLOT(B_find()));

    connect(ui->traverse1pushButton, SIGNAL(clicked()), this, SLOT(traverse_1()));
    connect(ui->traverse2pushButton, SIGNAL(clicked()), this, SLOT(traverse_2()));
    connect(ui->traverse3pushButton, SIGNAL(clicked()), this, SLOT(traverse_3()));
    connect(ui->traverse4pushButton, SIGNAL(clicked()), this, SLOT(traverse_4()));
    connect(ui->traverse5pushButton, SIGNAL(clicked()), this, SLOT(traverse_5()));
    connect(ui->traverse6pushButton, SIGNAL(clicked()), this, SLOT(traverse_6()));

    connect(ui->subtreeApushButton, SIGNAL(clicked(bool)), this, SLOT(delete_subtree()));
    connect(ui->subtreeBpushButton, SIGNAL(clicked(bool)), this, SLOT(add_subtree()));
    connect(ui->ltreeApushButton, SIGNAL(clicked(bool)), this, SLOT(delete_ltree()));
    connect(ui->ltreeBpushButton, SIGNAL(clicked(bool)), this, SLOT(add_ltree()));
    connect(ui->rtreeApushButton, SIGNAL(clicked(bool)), this, SLOT(delete_rtree()));
    connect(ui->rtreeBpushButton, SIGNAL(clicked(bool)), this, SLOT(add_rtree()));

    connect(ui->lcapushButton, SIGNAL(clicked(bool)), this, SLOT(lca_clicked()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::A_insert() {
    auto t = ui->plainTextEdit->toPlainText().toInt();
    A.Insert(t, t);
    ui->plainTextEdit->clear();
    Display();
}

void mainwindow::A_remove() {
    auto t = ui->plainTextEdit->toPlainText().toInt();
    A.Delete(t);
    ui->plainTextEdit->clear();
    Display();
}

void mainwindow::A_find() {
    auto t = ui->plainTextEdit->toPlainText().toInt();
    auto k = A.Find(t);
    if(k == INT_MIN)
    {
        ui->plainTextEdit->setPlainText("не найдено");
    }
    else
    {
        ui->plainTextEdit->setPlainText("найдено " + QString::number(k));
    }
}

void mainwindow::B_insert() {
    auto t = ui->plainTextEdit_2->toPlainText().toInt();
    B.Insert(t, t);
    ui->plainTextEdit_2->clear();
    Display();
}

void mainwindow::B_remove() {
    auto t = ui->plainTextEdit_2->toPlainText().toInt();
    B.Delete(t);
    ui->plainTextEdit_2->clear();
    Display();
}

void mainwindow::B_find() {
    auto t = ui->plainTextEdit_2->toPlainText().toInt();
    auto k = B.Find(t);
    if(k == INT_MIN)
    {
        ui->plainTextEdit_2->setPlainText("не найдено");
    }
    else
    {
        ui->plainTextEdit_2->setPlainText("найдено " + QString::number(k));
    }
}

void mainwindow::traverse_1() {
    std::vector<std::pair<int, int> > v = A.GetInfo(1);
    ui->textEdit->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s += QString::number(v[i].first) + " ";
    }
    ui->textEdit->setPlainText(s);
}

void mainwindow::traverse_2() {
    std::vector<std::pair<int, int> > v = A.GetInfo(2);
    ui->textEdit->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s += QString::number(v[i].first) + " ";
    }
    ui->textEdit->setPlainText(s);
}

void mainwindow::traverse_3() {
    std::vector<std::pair<int, int> > v = A.GetInfo(3);
    ui->textEdit->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s += QString::number(v[i].first) + " ";
    }
    ui->textEdit->setPlainText(s);
}

void mainwindow::traverse_4() {
    std::vector<std::pair<int, int> > v = B.GetInfo(1);
    ui->textEdit_2->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s += QString::number(v[i].first) + " ";
    }
    ui->textEdit_2->setPlainText(s);
}

void mainwindow::traverse_5() {
    std::vector<std::pair<int, int> > v = B.GetInfo(2);
    ui->textEdit_2->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s += QString::number(v[i].first) + " ";
    }
    ui->textEdit_2->setPlainText(s);
}

void mainwindow::traverse_6() {
    std::vector<std::pair<int, int> > v = B.GetInfo(3);
    ui->textEdit_2->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s += QString::number(v[i].first) + " ";
    }
    ui->textEdit_2->setPlainText(s);
}

void mainwindow::delete_subtree() {
    auto t = ui->plainTextEdit_3->toPlainText().toInt();
    A.DeleteSubtree(t);
    ui->plainTextEdit_3->clear();
    Display();
}

void mainwindow::delete_ltree() {
    auto t = ui->plainTextEdit_3->toPlainText().toInt();
    A.DeleteLeftSon(t);
    ui->plainTextEdit_3->clear();
    Display();
}

void mainwindow::delete_rtree() {
    auto t = ui->plainTextEdit_3->toPlainText().toInt();
    A.DeleteRightSon(t);
    ui->plainTextEdit_3->clear();
    Display();
}

void mainwindow::Display() {
    ui->treeWidget->clear();
    ui->treeWidget_2->clear();
    std::vector<std::pair<int, int> > v = A.getTree();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);

    if(v.size() != 0) {
        rootItem->setText(0, QString::number(v[0].second));
        std::stack<std::pair<QTreeWidgetItem *, int> > hierarchy;
        hierarchy.push({rootItem, v[0].second});
        for (int i = 1; i < v.size(); i++) {
            while (v[i].first != hierarchy.top().second) {
                hierarchy.pop();
            }
            QTreeWidgetItem *newItem = new QTreeWidgetItem(hierarchy.top().first);
            newItem->setText(0, QString::number(v[i].second));
            hierarchy.push({newItem, v[i].second});
        }
        ui->treeWidget->expandAll();
    }
    v = B.getTree();
    rootItem = new QTreeWidgetItem(ui->treeWidget_2);
    if(v.size() != 0) {
        std::stack<std::pair<QTreeWidgetItem *, int> > hierarchy;
        rootItem->setText(0, QString::number(v[0].second));
        hierarchy.push({rootItem, v[0].second});
        for (int i = 1; i < v.size(); i++) {
            while (v[i].first != hierarchy.top().second) {
                hierarchy.pop();
            }
            QTreeWidgetItem *newItem = new QTreeWidgetItem(hierarchy.top().first);
            newItem->setText(0, QString::number(v[i].second));
            hierarchy.push({newItem, v[i].second});
        }
    }
    ui->treeWidget->expandAll();
    ui->treeWidget_2->expandAll();
}

void mainwindow::add_subtree() {
    auto t = ui->plainTextEdit_4->toPlainText().toInt();
    auto node = B.GetNode(t);
    A.AddSubtree(node);
    Display();
}

void mainwindow::add_ltree() {
    auto t = ui->plainTextEdit_4->toPlainText().toInt();
    auto node = B.GetNode(t);
    A.AddLeftSon(node);
    Display();
}

void mainwindow::add_rtree() {
    auto t = ui->plainTextEdit_4->toPlainText().toInt();
    auto node = B.GetNode(t);
    A.AddRightSon(node);
    Display();
}

void mainwindow::lca_clicked() {
    int x = ui->xplainTextEdit->toPlainText().toInt();
    int y = ui->yplainTextEdit->toPlainText().toInt();

    int lca = B.lca(x, y);
    if(lca == -1)
    {
        ui->plainTextEdit_5->setPlainText("Элементы не найдены");
    }
    else
        ui->plainTextEdit_5->setPlainText(QString::number(lca));
}
