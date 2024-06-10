//
// Created by zgdarya on 6/1/24.
//

#ifndef L7_T3_WIDGET_H
#define L7_T3_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "hashtable.h"
#include "HashTable.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private slots:
    void insert();

    void search();

    void remove();

    void clear();

    void print();

private:
    HashTable* hashTable;
    QTextEdit *display;
    QLineEdit *keyInput;
    QLineEdit *valueInput;

    Ui::Widget *ui;
};


#endif //L7_T3_WIDGET_H
