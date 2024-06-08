#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include <QMessageBox>
#include <QThread>

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

    bool check(std::string s);
    void delar();
    void add(int ch);
    void paintEvent(QPaintEvent *event);
    void sort(std::vector<int>& arr );
    void printArray();
    long long binpow (int digit, int powder, int mod);
    int binfind(int el);
    bool check_el(std::string s);
    bool check_anc(std::vector<int>q, std::vector<int>w);
public slots:
    void on_findButton_clicked();
private slots:
    void on_sortButton_clicked();

    void on_PrevStep_clicked();

    void on_NextStep_clicked();

private:
    int partition(int a[],int l,int r);
    Ui::MainWindow *ui;
    std::vector<int>a,c;
    std::vector<std::vector<int>>ancestors;
    Graph g;
    std::string last_sort_array;
    int step=0;
};
#endif // MAINWINDOW_H
