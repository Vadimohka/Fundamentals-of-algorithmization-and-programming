#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>


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
    QString convertInteger(int num);
    QString convertFraction(double frac,int depth);
    QString translate(double num);
private slots:

    void on_lineEdit_decNum_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
