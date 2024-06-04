#include "mainwindow.h"
#include "BSTGui.h"
#include "ui_mainwindow.h"
#include <climits>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qnumeric.h>
#include <qstringliteral.h>
#include <QMessageBox>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  bstgui = new BSTGui;

  ui->keyBox->setRange(INT_MIN, INT_MAX);
  ui->textEdit->setMaxLength(20);
}

MainWindow::~MainWindow(){
  delete ui;
}

void MainWindow::on_initBtn_clicked(){
  bstgui->initRandomly();
  bstgui->setUpTreeWidget(ui->tree);
}


void MainWindow::on_balanceBtn_clicked(){
  bstgui->balance();
  bstgui->setUpTreeWidget(ui->tree);
}

void MainWindow::on_insertBtn_clicked(){
  auto key = ui->keyBox->value();
  auto txt = ui->textEdit->text();
  bstgui->insert(key, txt);

  bstgui->setUpTreeWidget(ui->tree);
}

void MainWindow::on_removeBtn_clicked(){
  auto key = ui->keyBox->value();
  if(bstgui->remove(key)){
    bstgui->setUpTreeWidget(ui->tree);
  } else {
    QMessageBox::warning(this, "Warning", "No item was removed with given key.");
  }
}

void MainWindow::on_findBtn_clicked(){
  auto key = ui->keyBox->value();

  auto found = bstgui->search(key);
  if(found.is_valid()){
    ui->textEdit->setText(*found);
  } else {
    QMessageBox::warning(this, "Warning", "No item was found with given key.");
  }
}

void MainWindow::fillList(const std::vector<BSTGui::node>& nodes){
  ui->traverseList->clear();
  const auto sz = nodes.size();
  for(int i = 0; i < sz; ++i){
    ui->traverseList->insertItem(i, QString("%1: %2").arg(nodes[i].key).arg(nodes[i].val));
  }
}

void MainWindow::on_inOrderBtn_clicked(){
  const auto vect = bstgui->in_order_traverse();
  fillList(vect);
}
  void MainWindow::on_preOrderBtn_clicked(){
    const auto vect = bstgui->pre_order_traverse();
  fillList(vect);

  }
  void MainWindow::on_postOrderBtn_clicked(){
    const auto vect = bstgui->post_order_traverse();
  fillList(vect);

  }

  void MainWindow::on_depthBtn_clicked(){
    auto depth = bstgui->depth();
    QMessageBox::information(this, "Depth info", QString("The depth of given tree is %1").arg(depth));
  }