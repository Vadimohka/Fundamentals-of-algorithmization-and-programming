#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void hanoi(int, int, int, int);
    void print(int, int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_all_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> vect;
    int pos = 0;
};
#endif // MAINWINDOW_H
