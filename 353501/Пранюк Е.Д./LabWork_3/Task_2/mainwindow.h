#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    ~MainWindow() override;
    int AckermannFunc(int m, int n);
private slots:
    void on_lineEdit_m_returnPressed();

    void on_lineEdit_n_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool isN = false, isM = false;
    int _m , _n;
};
#endif // MAINWINDOW_H
