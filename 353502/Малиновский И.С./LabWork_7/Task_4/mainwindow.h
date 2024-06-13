#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <chrono>
#include <iostream>
#include <QLabel>

#include "openaddressinghashtable.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onSearchButtonClicked();

private:
    OpenAddressingHashTable table16{16};
    OpenAddressingHashTable table64{64};
    OpenAddressingHashTable table128{128};
    OpenAddressingHashTable table2048{2048};

    QLabel *label16;
    QLabel *label64;
    QLabel *label128;
    QLabel *label2048;
};

#endif // MAINWINDOW_H
