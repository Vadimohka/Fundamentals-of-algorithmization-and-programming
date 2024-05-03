#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    long long binpow(int digit, int powder, int mod);
    void interpolationSort(std::vector<int>& arr);
    void printArray(std::vector<int> &vec);

private slots:
    void on_lineEdit_Elements_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
