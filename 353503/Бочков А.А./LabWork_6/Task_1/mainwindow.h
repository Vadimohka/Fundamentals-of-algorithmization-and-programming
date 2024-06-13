#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void print();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QMessageBox msgbox;
    bool ok = true;
    int typeact = 0, typeinput = 0;
    QString workers_age, input;
    Ui::factory MyFactory;
    Ui::factory *ptr = &MyFactory;
    Ui::factory &ref = MyFactory;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
