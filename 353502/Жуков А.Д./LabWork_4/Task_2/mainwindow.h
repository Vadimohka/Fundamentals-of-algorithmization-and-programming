#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

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

private slots:
    void on_pushButton_clicked();

    void on_calculateButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<int> list;

    void interpolationSort(std::vector<int> &arr);
    void listOutput(std::vector<int> &);
    long long binpow(long long a, long long b, long long mod);
    int binSeacrh(std::vector<int> & array, const int target);
};
#endif // MAINWINDOW_H
