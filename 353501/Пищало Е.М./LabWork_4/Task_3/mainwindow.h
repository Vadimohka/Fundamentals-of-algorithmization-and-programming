#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
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
    void on_generateVector_clicked();

    void on_addButton_clicked();

    void on_resultButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<int> calcMedians(std::vector<int> &a);
    std::vector<int> generateRandomVector();
    void quickSort(std::vector<int> &arr, int low, int high);
    int partition(std::vector<int> &arr, int low, int high);
};
#endif // MAINWINDOW_H
