#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

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

private:
    void count(const QString, unsigned long long &, unsigned long long &, QStandardItem *);
    Ui::MainWindow *ui;
    QStandardItemModel * model;
    QString directoryPath;
};
#endif // MAINWINDOW_H
