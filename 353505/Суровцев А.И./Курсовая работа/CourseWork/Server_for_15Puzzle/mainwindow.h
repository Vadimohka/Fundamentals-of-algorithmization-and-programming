#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include "tcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStartServer_clicked();

    void newClinetConnected();

    void clientDisconnected();

    void clientDataReceived(QString message);

private:
    Ui::MainWindow *ui;
    TcpServer *_server;
};
#endif // MAINWINDOW_H
