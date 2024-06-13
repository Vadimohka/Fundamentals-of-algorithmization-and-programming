// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sortInterpolationButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int> array;
    QLineEdit *arrayInput;
    QLabel *arrayDisplay;

    void updateArrayDisplay();
    void interpolationSort(QVector<int>& arr);
    int binpow(int digit, int power, int mod);
};

#endif // MAINWINDOW_H
