#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
struct Airport {
    int yearOpened;
    double averageDelay;
    char iataCode;
    bool operates24Hours;
    static char name[50];
    static int numberOfTerminals[5];
};
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
    void on_newAirportButton_clicked();

private:
    Ui::MainWindow *ui;
    void update(Airport&);
};
#endif // MAINWINDOW_H
