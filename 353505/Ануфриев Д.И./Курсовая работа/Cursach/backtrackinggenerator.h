#ifndef BACKTRACKINGGENERATOR_H
#define BACKTRACKINGGENERATOR_H

#include "figureitem.h"
#include "gamefield.h"

class BacktrackingGenerator : public QObject
{
    Q_OBJECT
public:
    BacktrackingGenerator(GameField* field);

    void generateThreeFigures(GameField* field);
    void generateFigureWithType(GameField* field, int numberOfType, int rotation, int posX);


    void searchMarkAndDeleteAllStrikes(QVector<QString> &fieldFulness);
    bool isStrikeInTheRow(QVector<QString> &fieldFulness, int row);
    bool isStrikeInTheColumn(QVector<QString> &fieldFulness, int column);
    bool isStrikeInTheSquareWithVertices(QVector<QString> &fieldFulness, int x, int y);


    void markStrikedRow(QVector<QString> &fieldFulness, int row);
    void markStrikedColumn(QVector<QString> &fieldFulness, int column);
    void markStrikedSquareWithVertices(QVector<QString> &fieldFulness, int x, int y);
    void deleteAllStrikes(QVector<QString> &fieldFulness);


    void run(GameField* field, QVector <FigureItem*> &figures);
    bool isCanBeTripleFigures(FigureItem *figure, QVector<QString> fieldFulness, int numberOfFigure);
    bool CanFigureBePlacedOnFieldArray(FigureItem* figure, QVector<QString> fieldFulness, int x, int y);
    void markFigureOnFieldArray(FigureItem* figure, QVector<QString> &fieldFulness, int x, int y);
    void findAndDeleteStrikes(QVector<QString> &fieldFulness);

private:
    qreal qUnit;
    GameField* field;
    QVector <FigureItem*> figures;

signals:
    void placedFigureToWindow();

public slots:
    void oneOfFiguresWasPlaced();
};

#endif // BACKTRACKINGGENERATOR_H
