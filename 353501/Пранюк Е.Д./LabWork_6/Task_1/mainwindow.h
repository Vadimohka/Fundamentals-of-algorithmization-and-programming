#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//struct Toy
struct Toy
{
    int _age = 0;
    double _price = 0;
    std::string _name = "";
    bool _isForChildern = true;
    static char _description[100];
    static int _sizes[4];
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void getInputForToy();
    void outputInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Toy toy;
    Toy* toy_p;
};
#endif // MAINWINDOW_H
