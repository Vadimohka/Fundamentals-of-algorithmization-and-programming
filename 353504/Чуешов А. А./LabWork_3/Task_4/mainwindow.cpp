#include "mainwindow.h"
#include "Hanoi.h"
#include "Vis.h"
#include "ui_mainwindow.h"
#include <QStack>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpolygon.h>
#include <qspinbox.h>
#include <qtablewidget.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow), vis(new Vis()) {
    ui->setupUi(this);

    ui->graphicsView->setScene(vis->scene);
    ui->graphicsView->setSceneRect(-350, -320, 700, 640);

    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::onUpdate);
    connect(ui->table, &QTableWidget::itemSelectionChanged, this,
            &MainWindow::updateSelected);

    onUpdate(ui->spinBox->value());
}

const QString letters[] = {"A", "B", "C"};

void MainWindow::onUpdate(int val) {
    solution = Hanoi::Solve(val);

    ui->table->setRowCount(solution.count());
    for (int i = 0; i < solution.count(); i++) {
        ui->table->setItem(i, 0, new QTableWidgetItem(letters[solution[i].first]));
        ui->table->setItem(i, 1, new QTableWidgetItem(letters[solution[i].second]));
    }

    ui->table->clearSelection();
    vis->resetVis(val, &solution);
}

void MainWindow::updateSelected() {
    auto selected = ui->table->selectedItems();
    if (selected.count() > 0)
        vis->setSelection(selected[0]->row());
    else
        vis->setSelection(-1);
}
