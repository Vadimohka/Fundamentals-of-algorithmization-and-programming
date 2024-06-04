//
// Created by darina on 5/11/24.
//

#ifndef TASK4_MAINWINDOW_H
#define TASK4_MAINWINDOW_H

#include <QWidget>
#include "../Pair.h"
#include "../Vector.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    void SetStart();

    Vector<Pair< Vector<int>, Vector<Pair<int, double> > > > v;

    Ui::mainwindow *ui;
};


#endif //TASK4_MAINWINDOW_H
