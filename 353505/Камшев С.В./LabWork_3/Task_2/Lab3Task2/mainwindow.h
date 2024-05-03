#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QTimer>

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
    QSpinBox* spinBoxN = new QSpinBox;
    QSpinBox* spinBoxM = new QSpinBox;
    QLineEdit* ansEdit = new QLineEdit;
    QLabel* mLabel = new QLabel;
    QLabel* nLabel = new QLabel;
    QTimer* timer = new QTimer;

    unsigned int AkkermanFunction(int n, int m);

private slots:
    void on_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
