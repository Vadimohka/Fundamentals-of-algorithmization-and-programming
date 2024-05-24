#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

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
    QString printVector();
    QString printMedians();
public slots:
    void on_Button_clicked();
private:
    Ui::MainWindow *ui;
    QVector<int> vector;
    int countElements;
};
#endif // MAINWINDOW_H
