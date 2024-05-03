#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "dirchecker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    DirChecker dirChecker_;

    void _updateFolder();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void slotChooseDir();
    void slotOpenFile();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
