//
// Created by acryoz on 22.05.24.
//

#ifndef LAB7_SRC_MAINWINDOW_H_
#define LAB7_SRC_MAINWINDOW_H_

#include <QDebug>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QRandomGenerator>
#include <QSize>
#include <QStringList>
#include <QVBoxLayout>
#include <QWidget>
#include "queue.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

static const QSize LIST_MIN_SIZE = QSize(200, 100);
static const QSize BUTTON_MIN_SIZE = QSize(200, 30);
static const int QUEUE_LEN = 10;

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   public slots:
    void doTask();

   private:
    QListWidget* list_widget1;
    QListWidget* list_widget2;
    QListWidget* list_widget3;
    Queue<uint32_t> queue1;
    Queue<uint32_t> queue2;
    Queue<uint32_t> queue3;
    QHBoxLayout* upper_hbox;
    QHBoxLayout* lower_hbox;
    QVBoxLayout* vbox;
    QPushButton* task_button;
    Ui::MainWindow* ui;
    void buildLists();
    QVector<uint32_t> qtovec(Queue<uint32_t>&);
};


#endif  //LAB7_SRC_MAINWINDOW_H_
