#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyStruct.h"
#include "myvalidator.h"

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
    watch w  {false, '1', 4, 7.5, "Rolex", {1,2,3,4,5}};

    void setInformation();
private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_ProtectionClassspinBox_2_textChanged(const QString &arg1);

    void on_NameEdit_textChanged(const QString &arg1);

    void on_PricespinBox_2_valueChanged(int arg1);

    void on_NumbspinBox_2_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
