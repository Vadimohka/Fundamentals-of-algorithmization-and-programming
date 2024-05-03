#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>
#include <ctime>
#include <random>
#include <QTimer>
#include <QTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

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

    //Virtual keyboard methods
    QPushButton* getButton(int ind);
    void clearKeyboard();
    int key_to_ind(int key);
    void setKeyboard(int delta);

    //Text
    void genText();
    void setTaskText();
    void change(QChar& q);

    void Finish();

    void GiveResult();

    //Languages
    void setBelarussian();
    void setDeutsch();
    void setHebrew();
    void setArabic();
    void setChinese();
    void setFrench();

    //File check
    void correct_file(QString &file);

private slots:
    //Physic keyboard methods
    virtual void keyReleaseEvent(QKeyEvent *ke) override;
    virtual void keyPressEvent(QKeyEvent *ke) override;

    void on_comboBox_currentIndexChanged(int index);//Change language
    void on_checkBox_stateChanged(int arg1);//Hide useless button
    void on_StartButton_clicked();//Start button

    void update_gui();
    void on_OpenFileButton_clicked();

private:
    Ui::MainWindow *ui;

    //Stylsheets
    const QString default_button="background-color: rgb(143, 240, 164);color: rgb(0, 0, 0);";
    const QString pressed_button="background-color: rgb(246, 97, 81);color: rgb(0, 0, 0);";
    const QString CapsOn="background-color: rgb(248, 228, 92);color: rgb(0, 0, 0);";
    const QString Wrong="color: rgb(255, 0, 0);";
    const QString Correct="color:rgb(0,255,0);";
    const QString Just="color:rgb(255,255,255);";
    //Alphabet
    QString alphabet;
    const short int delta=46;//Upper+46==lower
    QChar c;

    //Button
    bool Shift_on,Caps_on;

    //Text
    QString text;
    void check(int key);
    int er,cor;
    short size;

    //Time
    QTimer * timer;
    int ms;

    //Chars per second
    int chars=0;

};
#endif // MAINWINDOW_H
