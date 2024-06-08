#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include "deck.h"
#include <QGraphicsView>
#include <QMainWindow>
#include <QRectF>
#include <QKeyEvent>
#include <QMessageBox>

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
    Deck* cardDeck=new Deck;
    QGraphicsScene* scene;
    int turnNumber=1;
    int n=0;
    int currentCard=0;
    QRectF* leftRect;
    QGraphicsRectItem* rightRect;
    QGraphicsRectItem* topRect;
    QGraphicsRectItem* bottomRect;
    QGraphicsRectItem* leftCastle;
    QGraphicsRectItem* rightCastle;
    QGraphicsRectItem* topCastle;
    QGraphicsRectItem* bottomCastle;
    int exit=1;
    void MoveRect(QPointF angle);
private:
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent* event) override;
public slots:
    void Start();
    void PaintRect();
    void PlaceRect();
    void on_pushButton_clicked();
    void on_ClearButton_clicked();
    void on_enterButton_clicked();
    void on_upButton_clicked();
    void on_bottomButton_clicked();
    void on_rightButton_clicked();
    void on_leftButton_clicked();
    void ColorBoard();

signals:
    void StartGame();
    void StartPaint();
    void RectPainted();
    void RectChosen();
    void RectMoved();

};
#endif // MAINWINDOW_H
