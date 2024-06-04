#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCursor>
#include <QDebug>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTimer>
#include "keyboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_OpenButton_clicked();
    void slotSecondsUpdate();

private:
    Ui::MainWindow *ui;
    Keyboard *keyboard;
    QString currText;
    QString mask;
    QTimer timer;
    double seconds = 0;
    int words = 0;
    int mistakes = 0;
    bool isProcess;
    int currIndex;

    QTextCharFormat format;
    QTextCursor cursor;

    void printText();
};
#endif // MAINWINDOW_H
