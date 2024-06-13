#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QFileDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {

struct factory
{
    int workers_amount;
    double salary;
    QChar first_letter;
    bool work;
    QString name;
    int workers_age[10];
};

class MainWindow;

} // namespace Ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::factory MyFactory;
    double arr[1000];
    int typeinput, n;
    QChar c;
    QString res = "", input, workers_age;
    int typeact;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
