#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include "figures/typesoffigures.h"
#include <QEventLoop>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsDropShadowEffect>


class GameField : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    GameField(qreal qUnit);
    GameField(const GameField &other);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void clear();

    void resetShadowsAndLight();


    void setShadowForSquare(int j, int i);
    void setShadowForFigure(QVector<std::pair<int, int>> coordinatesOfSquares, int x, int y);

    bool AreCellsFilled(QVector<std::pair<int, int>> coordinatesOfSquares, int x, int y);
    bool isAboveAnFigure();
    void fillCellsByNewFigure();


    void searchMarkAndDeleteAllStrikes();
    bool isStrikeInTheRow(int row);
    bool isStrikeInTheColumn(int column);
    bool isStrikeInTheSquareWithVertices(int x, int y);


    void searchAndLightAllPotentialStrikes();
    void markPotentialStrikedRow(int row);
    void markPotentialStrikedColumn(int column);
    void markPotentialStrikedSquareWithVertices(int x, int y);


    void deleteAllStrikes();
    void lightAllPotentialStrikes();


    void markStrikedRow(int row);
    void markStrikedColumn(int column);
    void markStrikedSquareWithVertices(int x, int y);


    //for saving
    int getScore();
    void setScore(int score);
    int getRecord();
    void setRecord(int record);
    void showTextVisual(QString text);

    QVector <QString> getArrayOfFieldFullness();
    void setFieldFullness(QVector<QString> stringsOfField);


private:
    QChar arrayOfFieldFullness[9][9];
    QGraphicsRectItem* arrayOfBackgroundSquares[9][9], *arrayOfSetCells[9][9];

    qreal qUnit;

    QMediaPlayer* deletingPlayer;
    QAudioOutput* output;

    int score, record;
    int combo;

signals:
    void scoreChanged();
    void recordChanged();
};

#endif // GAMEFIELD_H
