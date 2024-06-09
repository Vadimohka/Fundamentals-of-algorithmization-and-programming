#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Map.h>
#include <Set.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_set_clicked();
    void on_get_clicked();
    void on_erase_clicked();
    void on_show_clicked();
    void on_clear_clicked();

private:
    Ui::MainWindow *ui;

    Map<int, int> _map;
};
#endif // MAINWINDOW_H
