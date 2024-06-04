//
// Created by u on 10.04.24.
//

#ifndef TASK1_MAIN_WINDOW_H
#define TASK1_MAIN_WINDOW_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include <vector>
#include <fstream>
#include <string>
#include "../student/student.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget
{
Q_OBJECT

private slots:
    void save();
    void load();
    void add();
    void change();
    void findStudent();
    void showBadStudent();
    void sortByGrade();
    void sortByGroup();
    void updateTable();

private:
    std::vector<student> students;
    std::vector<bool> showThisStudent;
    bool showBadStudents = true;
    QString studentFio;
    Ui::main_window *ui;


public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;
};


#endif //TASK1_MAIN_WINDOW_H
