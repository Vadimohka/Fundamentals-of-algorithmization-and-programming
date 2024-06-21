#ifndef T4WIN_H
#define T4WIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QPropertyAnimation>

#include <towers.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class T4Win;
}
QT_END_NAMESPACE

class T4Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit T4Win(QWidget *parent = nullptr);
    ~T4Win() override;

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_horizontalSlider_valueChanged(int value);
    void on_lineEdit_textEdited(const QString &arg1);
    void on_solveButton_clicked();
    void on_previousStepButton_clicked();
    void on_nextStepButton_clicked();

private:
    Ui::T4Win *ui;
    QList<Towers> steps;
    QList<QPushButton*> tower1Buttons;
    QList<QPushButton*> tower2Buttons;
    QList<QPushButton*> tower3Buttons;
    QTimer* timer;
    QPropertyAnimation* animation;

    int step = 0;

    void hanoi(int, int, int, int);
    void visualize();
    void animate();
    void clearList(QList<QPushButton*> &);
};
#endif // T4WIN_H
