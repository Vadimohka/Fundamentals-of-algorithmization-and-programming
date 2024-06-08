#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <WristWatch.h>
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
    void on_printBut_clicked();

    void on_userInitBut_clicked();

    void on_acceptUserInput_clicked();

private:
    QString makeStringFromWatch(WristWatch);
    WristWatch stringInitWatch;
    void initWithString();
    WristWatch codeInitWatch;
    void initWithCode();
    WristWatch ptrInitWatch;
    WristWatch* ptr = &ptrInitWatch;
    void initWithPtr();
    WristWatch refInitWatch;
    WristWatch &ref = refInitWatch;
    void initWithRef();
    WristWatch userInitWatch;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
