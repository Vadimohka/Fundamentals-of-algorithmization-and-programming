#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLabel>

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
    void on_spinBox_valueChanged( int arg1);

    void on_label_linkActivated(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSpinBox *spinBox;
     int val,res;
    QLabel *label;
    QString QSval;

    int reverse(int num, int res);
};
#endif // MAINWINDOW_H
