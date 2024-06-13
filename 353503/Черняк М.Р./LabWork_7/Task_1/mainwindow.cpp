#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtablewidget.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->pushBack, &QPushButton::clicked, [this]() {
        q.pushBack(getEl());
        redraw();
    });

    connect(ui->pushFront, &QPushButton::clicked, [this]() {
        q.pushFront(getEl());
        redraw();
    });

    connect(ui->popBack, &QPushButton::clicked, [this]() {
        if (!q.isEmpty()) {
            setEl(q.popBack());
            redraw();
        }
    });

    connect(ui->popFront, &QPushButton::clicked, [this]() {
        if (!q.isEmpty()) {
            setEl(q.popFront());
            redraw();
        }
    });

    connect(ui->randBtn, &QPushButton::clicked, [this]() {
        q.clear();
        for (int i = 0; i < 50; i++) {
            q.pushBack(rand() % 1000);
        }
        redraw();
    });

    connect(ui->clearBtn, &QPushButton::clicked, [this]() {
        q.clear();
        redraw();
    });

    connect(ui->removeDuplicates, &QPushButton::clicked, [this]() {
        q.removeDuplicates();
        redraw();
    });

    redraw();
}

int MainWindow::getEl() { return ui->inp->value(); }
void MainWindow::setEl(int val) { return ui->inp->setValue(val); }

void MainWindow::redraw() {
    ui->popBack->setEnabled(!q.isEmpty());
    ui->popFront->setEnabled(!q.isEmpty());

    ui->deqEls->clear();
    for (int i = 0; i < q.getSize(); i++) {
        ui->deqEls->addItem(QString::number(q.at(i)));
    }
}


