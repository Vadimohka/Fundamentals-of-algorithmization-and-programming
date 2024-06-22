#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "dialog.h"
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

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
    void startSlot(int ind);

private:
    Ui::MainWindow *ui;
    Dialog* myDialog;
    int indexLang = 0;
    QString texts[6] = {"feste muss man feiern können. es ist sehr wichtig lustig und interessant.",
                        "j'habite une belle ville dans le nord de la france. il y a un quartier très agréable.",
                        "مرحباً، اسمي محمد. أنا من القاهرة، مصر. أنا طالب في الجامعة أدرس الهندسة. أحب قراءة الك",
                        "jbsvbwubvwv wv wvbeth ehe ge ge rger  erh ger h erh e h eth  eh e h e hr erh",
                        "дзень канчаецца. заходзіць сонца. яно свеціць мне ў твар і я амаль нічога не бачу.",
                        "שבעה ימים באביב. בלוח השנה העברי הוא מתחילארוחה בערב החג מוזגים כוסות יין לכל האורחי ועושש"};
    QString currText = "";
    int indCursor = 0;
    QString keyBoard = "";
    QVector<QPushButton*> buttons;
    void addButtonsFromLayout(const QLayout* Layout);
    int find(QChar ch);
    bool firstLetter = true;
    QTimer* timer;
    QTime* timeCur;
    int secTime = 0;

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);

    // QWidget interface
protected:
    virtual void keyReleaseEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
