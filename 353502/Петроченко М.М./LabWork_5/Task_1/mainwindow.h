//
// Created by acryoz on 5/10/24.
//

#ifndef LAB5_SRC_MAINWINDOW_H_
#define LAB5_SRC_MAINWINDOW_H_

#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <cmath>
#include "keyboard.h"
#include "textedit.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

static const int TIMER_INTERVAL_MSEC = 100;

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    bool started = false;
    bool opened_file = false;
    Keyboard* keyboard;
    QComboBox* menu;
    QTimer* timer;
    QTime* time;
    QLineEdit* time_edit;
    QLineEdit* acc_percent;
    TextEdit* text_edit;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QPushButton* flie_button;
    Ui::MainWindow* ui;
   public slots:
    void keyPressed(QString);
    void tick();
    void openFile();
    void updateAccuracy(double);
    void onEnd(int);
    void onMenuChange(int);
};


#endif  //LAB5_SRC_MAINWINDOW_H_
