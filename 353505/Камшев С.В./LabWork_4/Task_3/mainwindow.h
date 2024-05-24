#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QTimer>
#include <QTextEdit>

#include "myvalidator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector <int> vec;
    QVector <int> ansVec;

    QPushButton* getAnsButton = new QPushButton;

    QLineEdit* ansLineEdit = new QLineEdit;
    QLineEdit* arrLineEdit = new QLineEdit;


    MyValidator* val = new MyValidator;

    void makeAns();
    void showAns();
    void makeArr();


private slots:
    void on_getAnsButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
