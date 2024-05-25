#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QVector>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLineEdit input;
    QLabel out;


    void perevod(long long x, QString& ans);
    bool proverka(QString wwod);
    void def(QString& integer, QString& ostatok, QString wvod, int position, bool buf);
    void integ(QVector<int>& bool_int_number, QVector<int>& int_number);
    void ostat(QVector<int>& bool_ost_number, QVector<int>& ost_number, int num);
    void reverse(QVector<int>& bool_int_number);
    void answer(QVector<int> bool_int_number, QVector<int> bool_ost_number, QString& ans, bool znak);
};
#endif // MAINWINDOW_H
