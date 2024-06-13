#ifndef LAB3_TASK3_MAINWINDOW_H_
#define LAB3_TASK3_MAINWINDOW_H_

#include <QDebug>
#include <QFileDialog>
#include <QFutureWatcher>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QtConcurrent/QtConcurrent>
#include "counter.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    QLabel* label;
    QFutureWatcher<Res>* future_watcher;
    QVBoxLayout* vbox;
    QPushButton* button;
    Ui::MainWindow* ui;
   private slots:
    void doTask();
    void final();
};


#endif  //LAB3_TASK3_MAINWINDOW_H_
