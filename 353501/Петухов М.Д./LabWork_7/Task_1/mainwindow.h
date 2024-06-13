#pragma once

#include <QMainWindow>
#include "queue.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
  Queue<QString> queue;

  QVector<QString> selectedElems;

public:
  MainWindow();

  QString getElementByIndex(Queue<QString>& queue, size_t index); 
  void removeElementByIndex(Queue<QString>& deque, size_t index);
  void removeSelectedItemsFromQueue(Queue<QString>& deque);
  void updateWidget(Queue<QString>& deque);
  void makeListOfSelectedElems(Queue<QString>& deque);
  void printDeque(Queue<QString>& deque);
  void insertElementsBefore(Queue<QString>& deque, int index, QVector<QString>& elementsToInsert);
protected:
  Ui::MainWindow *ui;
private slots:
  void on_pushButton_clicked();
  void on_insertButton_clicked();
};