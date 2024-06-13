//
// Created by acryoz on 27.2.24.
//

#ifndef UNTITLED5_MAINWINDOW_H
#define UNTITLED5_MAINWINDOW_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include "QTableViewModel.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include "files.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QVector<int> selectedRows();
    ~MainWindow() override;
public slots:
    void onAddPush();
    void onDelPush();
    void onRedactPush();
    void onBdayPush();
    void getDatePopup(const Date&);
    void save();
private:
    QVBoxLayout* arbitrary_vbox;
    QPushButton* save_button;
    QLabel* day_label;
    QLabel* month_label;
    QLabel* year_label;
    QLineEdit* day_line;
    QLineEdit* month_line;
    QLineEdit* year_line;
    QIntValidator* validator;
    QGridLayout* grid2;
    QLabel* errorLabel;
    bool date_inputed;
    Date pdate;
    QGridLayout* grid;
    QPushButton* add_button;
    QPushButton* delete_button;
    QPushButton* redact_button;
    QPushButton* bday_button;
    QVector<Date>* values;
    QHBoxLayout* hbox;
    QVBoxLayout* vbox;
    QTableViewModel* model;
    QTableView* tableView;
    QFile* file;
    Ui::MainWindow *ui;
};


#endif //UNTITLED5_MAINWINDOW_H
