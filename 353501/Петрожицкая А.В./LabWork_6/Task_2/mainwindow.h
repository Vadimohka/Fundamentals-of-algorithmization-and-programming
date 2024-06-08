#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QString>
#include <QTimer>

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
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void funMenu();
    QTimer* timer = new QTimer(this);
    QString TextInput, TextOutput;
    void processMenuChoice(int choice);
    void funSwich();
    QTextStream StreamInput;
    QTextStream StreamingOutput;
};
#endif // MAINWINDOW_H
