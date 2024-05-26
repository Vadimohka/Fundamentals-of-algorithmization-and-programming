#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>
#include <qlistwidget.h>
#include <qnamespace.h>

#include "sub1/SubFirst.h"
#include "sub2/SubSecond.h"
#include "sub3/SubThird.h"
#include "sub4/SubFour.h"
#include "sub5/SubFive.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  currentSubtask = ui->defaultSubtask;
  connect(ui->selector, &QListWidget::itemSelectionChanged, this,
          &MainWindow::onSubtaskSelect);
}

void MainWindow::onSubtaskSelect() {
  if (currentSubtask) {
    currentSubtask->hide();
    if (currentSubtask != ui->defaultSubtask) {
      currentSubtask->deleteLater();
    }
  }

  int selectedIndex = -1;
  auto selected = ui->selector->selectionModel()->selectedIndexes();
  if (!selected.empty())
    selectedIndex = selected[0].row();

  switch (selectedIndex) {
  case 0:
    currentSubtask = new SubFirst(ui->root);
    break;

  case 1:
    currentSubtask = new SubSecond(ui->root);
    break;

  case 2:
    currentSubtask = new SubThird(ui->root);
    break;

  case 3:
    currentSubtask = new SubFour(ui->root);
    break;

  case 4:
    currentSubtask = new SubFive(ui->root);
    break;

  default:
    currentSubtask = ui->defaultSubtask;
    break;
  }

  ui->root->layout()->addWidget(currentSubtask);
  currentSubtask->show();
}