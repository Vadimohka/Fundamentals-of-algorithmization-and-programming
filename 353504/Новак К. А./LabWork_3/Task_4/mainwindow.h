
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startMoving();
    void moveNextStep();
    void refresh();

private:
    void addRow();
    void hanoi(int n, int from, int to, int aux);
    void showStep(QVector<QVector<int>> stack);

    Ui::MainWindow *ui;
    QVector<int> diskCount = {0, 0, 0};
    QVector<QVector<QVector<int>>> diskStacks;
    int stackHeight = 0;
    int currentIndex = 0;
    QTimer *timer;
};

#endif // MAINWINDOW_H

