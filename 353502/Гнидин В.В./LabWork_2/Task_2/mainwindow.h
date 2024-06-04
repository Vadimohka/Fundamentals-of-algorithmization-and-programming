//
// Created by volodya-petarda on 4/25/24.
//

#ifndef LAB2_2_MAINWINDOW_H
#define LAB2_2_MAINWINDOW_H

#include "Person.h"
#include <QTimer>
#include <QWidget>
#include <vector>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Person *selectedPerson = nullptr;
    std::vector<Person*> persons;
    Ui::mainwindow *ui;
private slots:
    void makePair();
    void showLists();
    void showMatchedLists();
    void showAddPerson();
    void hideAddPerson();
    void addPerson();
    void onManClicked(QListWidgetItem *man);
    void onWomanClicked(QListWidgetItem *woman);
};


#endif //LAB2_2_MAINWINDOW_H
