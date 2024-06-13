//
// Created by acryoz on 7.3.24.
//

#ifndef UNTITLED5_MAINWINDOW_H
#define UNTITLED5_MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QString>
#include <QtAlgorithms>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "Party.h"
#include "files.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void clearLines();
    int count();
    ~MainWindow() override;
public slots:
    void formBulletin();
    void findCandidates();
    void sort();
    void showall();
    void add();
    void del();
    void select();
    void save();
    void edit();
private:
    //labels
    QLabel* name_label;
    QLabel* party_label;
    QLabel* income_label;
    QLabel* region_label;
    QLabel* occupation_label;
    QLabel* age_label;
    //lines
    QLineEdit* name_line;
    QLineEdit* party_line;
    QLineEdit* income_line;
    QLineEdit* region_line;
    QLineEdit* occupation_line;
    QLineEdit* age_line;
    //buttons
    QPushButton* form_button;
    QPushButton* find_button;
    QPushButton* sort_button;
    QPushButton* show_button;
    QPushButton* add_button;
    QPushButton* del_button;
    QPushButton* select_button;
    QPushButton* edit_button;
    QPushButton* save_button;
    //layouts
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;
    QGridLayout* buttons_grid;
    QGridLayout* input_grid;
    //textedit
    QPlainTextEdit* textEdit;

    QFile* file;
    QMap<QString, Party>* parties;

    bool selected = false;
    QString selected_party;
    int selected_index;

    Ui::MainWindow *ui;
};


#endif //UNTITLED5_MAINWINDOW_H
