#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QGridLayout>
#include <QPropertyAnimation>
#include "tile.h"
#include "puzzle15.h"
#include "datainput.h"
#include "client_part.h"

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
    void on_bnt_select15_clicked();

    void on_bnt_select8_clicked();

    void on_bnt_select24_clicked();

    void on_bnt_select35_clicked();

    void on_bnt_connect_to_server_clicked();

    void on_bnt_closeApp_clicked();

private:
    Ui::MainWindow *ui;
    Puzzle15 *puzzleWidget;
    DataInput *dataInput;
    Client_Part *client;
    QString _nickname;
};
#endif // MAINWINDOW_H
