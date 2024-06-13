#ifndef DEQUEDIALOG_H
#define DEQUEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <vector>
#include <algorithm>
#include <deque>
#include "deque.h"

class DequeDialog : public QDialog {
    Q_OBJECT

public:
    DequeDialog(QWidget* parent = nullptr);
    void generateQueue();
    void removeElements();

private:
    QListWidget* listWidget;
    std::deque <int> queue;
    QLabel* maxLabel;
    QLabel* minLabel;
};

#endif // DEQUEDIALOG_H
