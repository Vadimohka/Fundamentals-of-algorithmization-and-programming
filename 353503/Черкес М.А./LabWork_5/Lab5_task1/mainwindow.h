#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

signals:

private slots:
    void keyPressEvent(QKeyEvent *event);

    //void on_pushButton_clicked();

    void on_pushButton_clicked();
    void ComparisonText(QString, QString);

    void messageFunction();
    void updateTimer();
    void startTimer();
    void stopTimer();
private:


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QString enteredText;
    QString fileContent; // Добавить переменную для хранения текста из файла
    int counter = 0;
    int wrong = 0;
};
#endif // MAINWINDOW_H
