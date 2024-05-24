#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVector>
#include <algorithm>

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

    QString vectorToString(const QVector<int> &arr);
    QVector<int> calculateMedians(QVector<int> &arr);

private slots:
    void on_mediansButton_clicked();

private:
    QVector<int> arr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
