#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "bitset.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateBoxes();
    bool emptyCheck();

private slots:
    void on_setBitsetButton_clicked();

    void on_allButton_clicked();

    void on_anyButton_clicked();

    void on_noneButton_clicked();

    void on_countButton_clicked();

    void on_sizeButton_clicked();

    void on_toUllButton_clicked();

    void on_flipButton_clicked();

    void on_resetButton_clicked();

    void on_setButton_clicked();

    void on_flipIdButton_clicked();

    void on_resetIdButton_clicked();

    void on_setIdButton_clicked();

private:
    Ui::MainWindow *ui;
    BitSet *bitset;
    QMessageBox msgBox;
};
#endif // MAINWINDOW_H
