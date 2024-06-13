#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QLineEdit>

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
    QPlainTextEdit* textEdit;
    QDialog* dialog;
    QSpinBox* spinBox;
    QLineEdit* lineEdit;
private slots:
    void slot1();
private:
    void saveTextToFile(const QString& text);
    void saveArrayToFile();
    void onEnterPressed();
    void runMenu();
    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();
    void task8();
    void task9();
    void task10();
    int showMenu();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
