#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void extracted(QFileInfoList &list);
    int countDirs(QDir);
    int countFiles(QDir, QString);

private slots:
    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    QString sourseDir;
};
#endif // MAINWINDOW_H
