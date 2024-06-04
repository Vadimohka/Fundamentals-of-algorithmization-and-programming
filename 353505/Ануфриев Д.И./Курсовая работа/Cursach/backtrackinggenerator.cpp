#include "backtrackinggenerator.h"
#include "figures/bigltypefigure.h"
#include "figures/diagonalstick2figure.h"
#include "figures/inverseltypefigure.h"
#include "figures/inversestypefigure.h"
#include "figures/ltypefigure.h"
#include "figures/miniltypefigure.h"
#include "figures/square2typefigure.h"
#include "figures/stick4typefigure.h"
#include "figures/stypefigure.h"
#include "figures/ttypefigure.h"

BacktrackingGenerator::BacktrackingGenerator(GameField* field)
{
    this->field = field;
    qUnit = field->scene()->height() / 15.0;
}

void BacktrackingGenerator::run(GameField* field, QVector<FigureItem *> &figures)
{
    this->field = field;

    QVector<QString> fieldVector = field->getArrayOfFieldFullness();

    for(int c = 0; c < 500; c++)
    {
        generateThreeFigures(field);

        if(isCanBeTripleFigures(this->figures[0], fieldVector, 1))
        {
            qDebug() << "ok";
            figures = this->figures;
            return;
        }
    }

    figures = this->figures;
    return;
}

void BacktrackingGenerator::generateThreeFigures(GameField* field)
{
    for(int i = 0; i < figures.size(); i++)
    {
        field->scene()->removeItem(figures[i]);
    }
    figures.clear();

    for(int i = 0; i < 3; i++)
    {
        int numberOfType = rand() % 10;
        generateFigureWithType(field, numberOfType, ((rand() % 4) * 90), 1 * qUnit + i * 4 * qUnit);
    }
}

void BacktrackingGenerator::generateFigureWithType(GameField *field, int numberOfType, int rotation, int posX)
{
    if(numberOfType == 0)
    {
        figures.push_back(new LtypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 1)
    {
        figures.push_back(new TtypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 2)
    {
        figures.push_back(new Square2TypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 3)
    {
        figures.push_back(new MiniLTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 4)
    {
        figures.push_back(new InverseLTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 5)
    {
        figures.push_back(new STypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 6)
    {
        figures.push_back(new InverseSTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 7)
    {
        figures.push_back(new Stick4TypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 8)
    {
        figures.push_back(new BigLTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 9)
    {
        figures.push_back(new DiagonalStick2Figure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }


    field->scene()->addItem(figures.back());
    connect(figures.back(), &FigureItem::isPlaced, this, &BacktrackingGenerator::oneOfFiguresWasPlaced);

    figures.back()->setRotation(rotation);
    figures.back()->UpdateCoordinatesOfSquares();

    qDebug() << "added" << numberOfType << rotation << posX;

}


bool BacktrackingGenerator::isCanBeTripleFigures(FigureItem *figure, QVector<QString> fieldFulness, int numberOfFigure)
{

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            for(int r = 0; r < 360; r += 90)
            {
                figure->setRotation(r);
                figure->UpdateCoordinatesOfSquares();


                if(CanFigureBePlacedOnFieldArray(figure, fieldFulness, j, i))
                {
                    if(numberOfFigure == 3) return true;
                    else
                    {
                        markFigureOnFieldArray(figure, fieldFulness, j, i);
                        if(isCanBeTripleFigures(figures[numberOfFigure], fieldFulness, numberOfFigure + 1)) return true;
                    }
                }
            }
        }
    }

    return false;
}

bool BacktrackingGenerator::CanFigureBePlacedOnFieldArray(FigureItem *figure, QVector<QString> fieldFulness, int x, int y)
{
    for(int i = 0; i < figure->getLeftTopPointsOfSquares().size(); i++)
    {
        if(y + figure->getLeftTopPointsOfSquares()[i].first >= 9 || x + figure->getLeftTopPointsOfSquares()[i].second >= 9 ||
            fieldFulness[y + figure->getLeftTopPointsOfSquares()[i].first][x + figure->getLeftTopPointsOfSquares()[i].second] != '.')
        {
            return false;
        }
    }

    return true;
}

void BacktrackingGenerator::markFigureOnFieldArray(FigureItem *figure, QVector<QString> &fieldFulness, int x, int y)
{
    for(int i = 0; i < figure->getLeftTopPointsOfSquares().size(); i++)
    {
        fieldFulness[y + figure->getLeftTopPointsOfSquares()[i].first][x + figure->getLeftTopPointsOfSquares()[i].second] = '#';
        searchMarkAndDeleteAllStrikes(fieldFulness);
    }
}

void BacktrackingGenerator::oneOfFiguresWasPlaced()
{
    emit placedFigureToWindow();
}


void BacktrackingGenerator::searchMarkAndDeleteAllStrikes(QVector<QString> &fieldFulness)
{
    bool areStrikesFound = false;
    
    for(int i = 0; i < 9; i++)
    {
        if(isStrikeInTheRow(fieldFulness, i))
        {
            markStrikedRow(fieldFulness, i);
            areStrikesFound = true;
        }
        
        if(isStrikeInTheColumn(fieldFulness, i))
        {
            markStrikedColumn(fieldFulness, i);
            areStrikesFound = true;
        }
    }
    
    for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 9; j += 3)
        {
            if(isStrikeInTheSquareWithVertices(fieldFulness, j, i))
            {
                markStrikedSquareWithVertices(fieldFulness, j, i);
                areStrikesFound = true;
            }
        }
    }
    
    if(areStrikesFound) deleteAllStrikes(fieldFulness);
}

bool BacktrackingGenerator::isStrikeInTheRow(QVector<QString> &fieldFulness, int row)
{
    for(int j = 0; j < 9; j++)
    {
        if(fieldFulness[row][j] == '.') return false;
    }
    
    return true;
}

bool BacktrackingGenerator::isStrikeInTheColumn(QVector<QString> &fieldFulness, int column)
{
    for(int i = 0; i < 9; i++)
    {
        if(fieldFulness[i][column] == '.') return false;
    }
    
    return true;
}

bool BacktrackingGenerator::isStrikeInTheSquareWithVertices(QVector<QString> &fieldFulness, int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            if(fieldFulness[i][j] == '.') return false;
        }
    }
    
    return true;
}
void BacktrackingGenerator::markStrikedRow(QVector<QString> &fieldFulness, int row)
{
    for(int j = 0; j < 9; j++)
    {
        fieldFulness[row][j] = '-';
    }
}

void BacktrackingGenerator::markStrikedColumn(QVector<QString> &fieldFulness, int column)
{
    for(int i = 0; i < 9; i++)
    {
        fieldFulness[i][column] = '-';
    }
}

void BacktrackingGenerator::markStrikedSquareWithVertices(QVector<QString> &fieldFulness, int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            fieldFulness[i][j] = '-';
        }
    }
}

void BacktrackingGenerator::deleteAllStrikes(QVector<QString> &fieldFulness)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(fieldFulness[i][j] == '-')
            {
                fieldFulness[i][j] = '.';
            }
        }
    }
    
}
