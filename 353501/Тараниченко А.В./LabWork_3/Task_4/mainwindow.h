#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "bases.h"
#include "ring.h"
#include "rods.h"
#include <stack>
#include <vector>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *mainScene;
    QHBoxLayout *mainLayout;
    QTimer *timer;
    QList<QGraphicsRectItem *> bases;
    vector<stack<Ring *>> rodRings;
    vector<Rods *> rods;
    vector<Ring *> rings;
    QTextEdit *moves;
    QPushButton *start;
    QPushButton *stop;
    QPushButton *restart;
    QGraphicsItemAnimation *animation;
    QTimeLine *time;
    QLabel *ringsCountLabel;
    QSpinBox *ringCount;
    struct Action
    {
        int fromRod;
        int toRod;
    };
    bool finish = false;
    int progress = 0;
    int pause = false;
    QMap<Ring *, QPointF> ringStartPos; // Для хранения начальной позиции каждого кольца
    QMap<Ring *, int> ringStartTime; // Для хранения начального времени каждого кольца

    QColor ringColors[8]{Qt::red,
                         Qt::green,
                         Qt::blue,
                         Qt::cyan,
                         Qt::magenta,
                         Qt::yellow,
                         Qt::gray,
                         Qt::darkRed};

    char rodMoves[3]{'A', 'B', 'C'};
    QList<Action> actions;
    int currActionID = 0;
    void execAction();
    QPointF calcPos(int rodID, int ringCount, int ringW, int rodW);
    void generateActions(int n, int fromRod, int toRod, int auxRod);
private slots:

    void RestartHanoi();
    void moveRing(int fromRod, int toRod);
    void StartHanoi();
    void StopHanoi();
};
#endif // MAINWINDOW_H
