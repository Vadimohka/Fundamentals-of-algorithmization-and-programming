#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include "shipFunctions.h"
#include "ship.h"
#include <fstream>
#include <QTextEdit>

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

    void WriteAndSaveText();
    void ReadText();

    void WriteAndSaveArray();
    void ReadArray();

    void WriteAndSaveStructTXT();
    void ReadStructTXT();

    void WriteAndSaveStructBIN();
    void ReadStructBIN();

    void WriteAndSaveSentences();
    void ReadSentences();
public slots:
    void menu();
private:
    Ui::MainWindow *ui;
    QTimer timer;
    const QChar separator='-';
    Ship ship;
};
#endif // MAINWINDOW_H
