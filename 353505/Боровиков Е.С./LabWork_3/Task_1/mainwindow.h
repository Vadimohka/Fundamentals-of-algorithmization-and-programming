#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

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
    QPushButton* button = new QPushButton;
    QLineEdit* informationEdit = new QLineEdit;
    QLineEdit* ansEdit = new QLineEdit;
    QPushButton * my_close;

    myValidator* val = new myValidator;

    QString intToBinary(QString numb);
    QString DoubleToBinary(QString numb, int Discharge);


    bool comparison(QString numb1, QString numb2);

    QString stringDivisions(QString str);
    QString stringMultiplication(QString numb);


private slots:
    void on_button_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
