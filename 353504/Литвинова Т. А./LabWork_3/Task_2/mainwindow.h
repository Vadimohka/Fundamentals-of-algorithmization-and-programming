#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

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
    long long int ackermann(int m, int n);


private slots:
    //void calculateAckermann();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int m;
    int n;
    long long int result;
    QLineEdit *mInputM;
    QLineEdit *mInputN;
    QPushButton *mCalculateButton;
    QLineEdit *mResult;
};
#endif // MAINWINDOW_H
