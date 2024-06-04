#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QTimer>
#include "qpushbutton.h"
#include "ui_mainwindow.h"

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

private slots:
    void Timer_slot();
    void Light_slot();
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QMessageBox msgbox;
    bool flag = false, flag2 = true, light_flag = false;
    int sec = 0, right = 0, all = 0, alphabet_index = 0, curr_button = 0;
    QTimer *Timer, *Light;
    QMap<int, int> k;
    QMap<int, QPushButton *> m;
    Ui::MainWindow *ui;
    QString alphabet[6] = {"ё1234567890-=йцукенгшўзх'фывапролджэячсмітьбю. ",
                           "^1234567890ß´qwertzuiopü+asdfghjklöäyxcvbnm,.- ",
                           "~éêề'(-è_çà-=azertyuiop^$qsdfghjklmùwxcvbn,;:. ",
                           "ز123456789.-ذضصثقفغعهخحجدشسيبأاتنمكطئءؤرلاىةوظ ",
                           ";1234567890-=/'קראטוןםפ][שדגכעיחלךף,זסבהנמצתץ. ",
                           "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./ "};
    QString Text[6] = {
        "ружы чырвоныя фіялеткі сінія цукер салодкі і так сама ты.",
        "rosen sind rot, veilchen sind blau. zucker ist licht. und das bist du auch.",
        "les roses sont rouges les violettes sont bleues le sucre est léger et vous l'ềtes aussi.",
        "الورد أحمر والبنفسج أزرق والسكر خفيف وأنت كذلك. ",
        "ורדים הם אדומים סיגליות הם כחולים סוכר הוא קל וכך אתה.",
        "mei gui shi hong se de zi luo lan shi lan se de tang shi tian de ni ye shi."};
    QString right_text, other_text;
    QTextCharFormat fmt;
};
#endif // MAINWINDOW_H
