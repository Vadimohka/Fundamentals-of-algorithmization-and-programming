#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "watches.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    bool isEnglish(const QString &str)
    {
        QRegExp rx("[a-zA-Z]+");
        return str.contains(rx);
    }

private slots:
    void on_task_currentIndexChanged(int index);

    void on_submit_clicked();

private:
    Ui::MainWindow *ui;
    Watches rollex;
    Watches luch;
    Watches apple;
    Watches casio;
};
#endif // MAINWINDOW_H
