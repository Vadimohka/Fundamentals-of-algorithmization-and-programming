#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "QVector"
#include <QTextEdit>
#include <QDebug>
#include <QMessageBox>
#include "QString"
#include <QTimer>
#include <QFileDialog>

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
protected:
   // void keyPressEvent(QKeyEvent *event) override;
    //void keyReleaseEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
    int key = 0;
    QVector<QVector<QString>> words;
    QVector<QString> simvols;
    QVector<QString> SIMVOLS;
    QString str;
    QTimer *time = new QTimer(this);
    QVector<QPushButton*> button;
    QVector<bool> isPressbutton;
    short numLanguage = 0;
    int keyCode = 1;
    int numSimvol = 0;
    bool keyIsPressed = true;
    float time_t = 0;
    int kol_words = 0, correctPresses = 0, incorrectPresses = 0;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_4_clicked();

        void fun();

    void on_pushButton_39_clicked();

        void on_pushButton_40_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
