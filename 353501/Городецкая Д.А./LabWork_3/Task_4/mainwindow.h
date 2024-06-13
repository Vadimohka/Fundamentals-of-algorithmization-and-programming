#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QPushButton>
#include <QSpinBox>
#include <QTableWidget>
#include <QPainter>
#include <QTimer>
#include <QVector>
#include <QRectF>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void centerObjects();
    void hanoi(int n, int firstPost, int secondPost, QVector<QVector<int>>& vec);
    void moveUp(int index);
    void renul();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_nextPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QCheckBox *updCheckBox;
    QCheckBox *mainUpdCheckBox;
    QPushButton *nextPushButton;
    QSpinBox *spinBox;
    QTableWidget *tableWidget;
    QTimer *timer;
    QVector<QVector<int>> vec;
    QVector<QRectF*> circleFigure;
    QVector<QColor> colorVec;
    int index = 0;
    int size = 0;
    int numberOnFirstColumn = 0;
    int numberOnSecondColumn = 0;
    int numberOnThirdColumn = 0;
    bool *upd = new bool(false);
};

#endif // MAINWINDOW_H
