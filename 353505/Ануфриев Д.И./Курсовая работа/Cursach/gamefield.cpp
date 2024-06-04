#include "gamefield.h"
#include "qlabel.h"

GameField::GameField(qreal qUnit)
{
    this->qUnit = qUnit;
    score = 0;
    record = 0;
    combo = 0;

    deletingPlayer = new QMediaPlayer();
    output = new QAudioOutput();
    deletingPlayer->setAudioOutput(output);
    deletingPlayer->setSource(QUrl::fromLocalFile("../../media/chpok-nays.wav"));
    output->setVolume(0.5);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfBackgroundSquares[i][j] = new QGraphicsRectItem(2 * qUnit + j * qUnit, qUnit + i * qUnit, qUnit, qUnit);
            arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor(156, 156, 156), 3));

            if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
                ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
                arrayOfBackgroundSquares[i][j]->setBrush(QColor(235, 235, 235));

            this->addToGroup(arrayOfBackgroundSquares[i][j]);
            arrayOfBackgroundSquares[i][j]->setZValue(0);
        }
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfFieldFullness[i][j] = '.';
            arrayOfSetCells[i][j] = nullptr;
        }
    }
}

GameField::GameField(const GameField &other)
{
    this->qUnit = other.qUnit;
    score = 0;
    record = 0;

    deletingPlayer = other.deletingPlayer;
    output = other.output;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfBackgroundSquares[i][j] = other.arrayOfBackgroundSquares[i][j];
            this->addToGroup(arrayOfBackgroundSquares[i][j]);
        }
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfFieldFullness[i][j] = other.arrayOfFieldFullness[i][j];
            arrayOfSetCells[i][j] = other.arrayOfSetCells[i][j];
        }
    }
}

QRectF GameField::boundingRect() const
{
    return scene()->sceneRect();
}

void GameField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GameField::clear()
{
    resetShadowsAndLight();

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfSetCells[i][j] != nullptr)
            {
                delete arrayOfSetCells[i][j];
                arrayOfSetCells[i][j] = nullptr;
            }
            arrayOfFieldFullness[i][j] = '.';
        }
    }
}

void GameField::setShadowForSquare(int j, int i)
{
    if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
        ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
        ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
        ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
    {
        arrayOfBackgroundSquares[i][j]->setBrush(QColor("#97C4FF"));
    }
    else
    {
        arrayOfBackgroundSquares[i][j]->setBrush(QColor("#B7D7FF"));
    }

    arrayOfFieldFullness[i][j] = 's';
    arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor("#519DFF"), 3));
}

void GameField::setShadowForFigure(QVector<std::pair<int, int>> coordinatesOfSquares, int x, int y)
{
    resetShadowsAndLight();

    if(!AreCellsFilled(coordinatesOfSquares, x, y))
    {
        for(int i = 0; i < coordinatesOfSquares.size(); i++)
        {
            setShadowForSquare(x + coordinatesOfSquares[i].first, y + coordinatesOfSquares[i].second);
        }
    }

    searchAndLightAllPotentialStrikes();
}

void GameField::resetShadowsAndLight()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor(156, 156, 156), 3));
            arrayOfBackgroundSquares[i][j]->setBrush(Qt::white);

            if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
                ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
            {
                arrayOfBackgroundSquares[i][j]->setBrush(QColor(235, 235, 235));
            }

            if(arrayOfFieldFullness[i][j] == 's')
            {
                arrayOfFieldFullness[i][j] = '.';
            }

            if(arrayOfFieldFullness[i][j] == 'l')
            {
                arrayOfSetCells[i][j]->setBrush(QColor("#4395FF"));
                arrayOfSetCells[i][j]->setPen(QPen(QColor("#0E77FF"), 3));

                arrayOfFieldFullness[i][j] = '1';
            }

        }
    }
}

bool GameField::AreCellsFilled(QVector<std::pair<int, int>> coordinatesOfSquares, int x, int y)
{
    for(int i = 0; i < coordinatesOfSquares.size(); i++)
    {
        if(arrayOfFieldFullness[y + coordinatesOfSquares[i].second][x + coordinatesOfSquares[i].first] != '.') return true;
    }

    return false;
}

void GameField::searchMarkAndDeleteAllStrikes()
{
    bool areStrikesFound = false;

    for(int i = 0; i < 9; i++)
    {
        if(isStrikeInTheRow(i))
        {
            markStrikedRow(i);
            areStrikesFound = true;
        }

        if(isStrikeInTheColumn(i))
        {
            markStrikedColumn(i);
            areStrikesFound = true;
        }
    }

    for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 9; j += 3)
        {
            if(isStrikeInTheSquareWithVertices(j, i))
            {
                markStrikedSquareWithVertices(j, i);
                areStrikesFound = true;
            }
        }
    }

    if(areStrikesFound)
    {
        combo++;

        if(combo > 1) showTextVisual("COMBO x" + QString::number(combo) + "!");
        else
        {
            int variant = rand() % 5;
            switch(variant)
            {
                case 0:
                {
                    showTextVisual("WOW!");
                    break;
                }
                case 1:
                {
                    showTextVisual("GREAT!");
                    break;
                }
                case 2:
                {
                    showTextVisual("PERFECT!");
                    break;
                }
                case 3:
                {
                    showTextVisual("NICE!");
                    break;
                }
                case 4:
                {
                    showTextVisual("YOU'RE PRO!");
                    break;
                }
            }
        }
        deleteAllStrikes();
    }
    else
    {
        combo = 0;
    }
}

bool GameField::isStrikeInTheRow(int row)
{
    for(int j = 0; j < 9; j++)
    {
        if(arrayOfFieldFullness[row][j] == '.') return false;
    }

    return true;
}

bool GameField::isStrikeInTheColumn(int column)
{
    for(int i = 0; i < 9; i++)
    {
        if(arrayOfFieldFullness[i][column] == '.') return false;
    }

    return true;
}

bool GameField::isStrikeInTheSquareWithVertices(int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            if(arrayOfFieldFullness[i][j] == '.') return false;
        }
    }

    return true;
}

void GameField::searchAndLightAllPotentialStrikes()
{
    bool arePotentialStrikesFound = false;

    for(int i = 0; i < 9; i++)
    {
        if(isStrikeInTheRow(i))
        {
            markPotentialStrikedRow(i);
            arePotentialStrikesFound = true;
        }

        if(isStrikeInTheColumn(i))
        {
            markPotentialStrikedColumn(i);
            arePotentialStrikesFound = true;
        }
    }

    for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 9; j += 3)
        {
            if(isStrikeInTheSquareWithVertices(j, i))
            {
                markPotentialStrikedSquareWithVertices(j, i);
                arePotentialStrikesFound = true;
            }
        }
    }

    if(arePotentialStrikesFound) lightAllPotentialStrikes();
}

void GameField::deleteAllStrikes()
{
    QTimer* deleting = new QTimer();

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfFieldFullness[i][j] == '-')
            {
                connect(deleting, &QTimer::timeout, [=](){
                    arrayOfSetCells[i][j]->setScale(arrayOfSetCells[i][j]->scale() - 0.1);
                    arrayOfSetCells[i][j]->setRotation(arrayOfSetCells[i][j]->rotation() + 5);

                    if(arrayOfSetCells[i][j]->scale() < 0.1)
                    {
                        deleting->stop();
                        removeFromGroup(arrayOfSetCells[i][j]);
                        delete arrayOfSetCells[i][j];
                        arrayOfSetCells[i][j] = nullptr;
                    }
                });

                score += combo * 1;

                qDebug() << score << "deleted one sqaure";

                setScore(score);

                if(score > record) setRecord(score);

                arrayOfFieldFullness[i][j] = '.';
                resetShadowsAndLight();
            }
        }
    }

    deleting->start(20);
    deletingPlayer->play();

}

void GameField::lightAllPotentialStrikes()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfFieldFullness[i][j] == 'l')
            {

                arrayOfSetCells[i][j]->setBrush(QColor("#69ABFF"));
                //arrayOfSetCells[i][j]->setPen(QPen(QColor("#3A90FF"), 3));
            }
        }
    }
}

void GameField::markStrikedRow(int row)
{
    for(int j = 0; j < 9; j++)
    {
        arrayOfFieldFullness[row][j] = '-';
    }
}

void GameField::markStrikedColumn(int column)
{
    for(int i = 0; i < 9; i++)
    {
        arrayOfFieldFullness[i][column] = '-';
    }
}

void GameField::markStrikedSquareWithVertices(int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            arrayOfFieldFullness[i][j] = '-';
        }
    }
}

int GameField::getScore()
{
    return score;
}

void GameField::setScore(int score)
{
    this->score = score;
    emit scoreChanged();
}

int GameField::getRecord()
{
    return record;
}

void GameField::setRecord(int record)
{
    this->record = record;
    emit recordChanged();
}

void GameField::showTextVisual(QString text)
{
    QGraphicsTextItem *comboText = new QGraphicsTextItem;
    comboText->setPlainText(text);
    comboText->setFont(QFont("Noto Kufi Arabic", 100));
    comboText->setDefaultTextColor(QColor("#FFEF00"));

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(10);
    shadowEffect->setColor(QColor("#DFA400"));
    shadowEffect->setOffset(3, 3);
    comboText->setGraphicsEffect(shadowEffect);

    scene()->addItem(comboText);
    comboText->setPos(6.5 * qUnit - comboText->boundingRect().width() / 2,
                      5.5 * qUnit - comboText->boundingRect().height() / 2);
    comboText->setTransformOriginPoint(comboText->boundingRect().width() / 2, comboText->boundingRect().height() / 2);

    comboText->setScale(0.1);

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, [comboText, timer, this](){
        if(comboText->scale() < 1)
        {
            comboText->setScale(comboText->scale() + 0.012);
        }
        else
        {
            timer->stop();
            scene()->removeItem(comboText);
            delete comboText;
            delete timer;
        }

    });
    timer->start(60/1000.0);
}

QVector<QString> GameField::getArrayOfFieldFullness()
{
    QVector<QString> stringsOfArray;
    for(int i = 0; i < 9; i++)
    {
        QString stringOfArray = "";

        for(int j = 0; j < 9; j++)
        {
            stringOfArray += arrayOfFieldFullness[i][j];
        }

        stringsOfArray.push_back(stringOfArray);
    }

    return stringsOfArray;
}

void GameField::setFieldFullness(QVector<QString> stringsOfField)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfFieldFullness[i][j] = stringsOfField[i][j];

            if(arrayOfSetCells[i][j] != nullptr)
            {
                delete arrayOfSetCells[i][j];
                arrayOfSetCells[i][j] = nullptr;
            }

            if(stringsOfField[i][j] == '1')
            {
                arrayOfSetCells[i][j] = new QGraphicsRectItem(0, 0, qUnit, qUnit);
                arrayOfSetCells[i][j]->setPos(2 * qUnit + j * qUnit, qUnit + i * qUnit);

                arrayOfSetCells[i][j]->setTransformOriginPoint(qUnit / 2.0, qUnit / 2.0);
                arrayOfSetCells[i][j]->setBrush(QColor("#4395FF"));
                arrayOfSetCells[i][j]->setPen(QPen(QColor("#0E77FF"), 3));

                addToGroup(arrayOfSetCells[i][j]);
                arrayOfSetCells[i][j]->setZValue(0);

                resetShadowsAndLight();
            }
        }
    }
}


void GameField::markPotentialStrikedRow(int row)
{
    for(int j = 0; j < 9; j++)
    {
        if(arrayOfFieldFullness[row][j] == '1')
        arrayOfFieldFullness[row][j] = 'l';
    }
}

void GameField::markPotentialStrikedColumn(int column)
{
    for(int i = 0; i < 9; i++)
    {
        if(arrayOfFieldFullness[i][column] == '1')
        arrayOfFieldFullness[i][column] = 'l';
    }
}

void GameField::markPotentialStrikedSquareWithVertices(int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            if(arrayOfFieldFullness[i][j] == '1')
            arrayOfFieldFullness[i][j] = 'l';
        }
    }
}

bool GameField::isAboveAnFigure()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfFieldFullness[i][j] == 's') return true;
        }
    }

    return false;
}

void GameField::fillCellsByNewFigure()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //if(arrayOfBackgroundSquares[i][j]->brush().color() == "#97C4FF" || arrayOfBackgroundSquares[i][j]->brush().color() == "#B7D7FF")
            if(arrayOfFieldFullness[i][j] == 's')
            {
                arrayOfFieldFullness[i][j] = '1';
                // arrayOfSetCells[i][j] = new QGraphicsRectItem(2 * qUnit + j * qUnit, qUnit + i * qUnit, qUnit, qUnit);
                arrayOfSetCells[i][j] = new QGraphicsRectItem(0, 0, qUnit, qUnit);
                arrayOfSetCells[i][j]->setPos(2 * qUnit + j * qUnit, qUnit + i * qUnit);

                arrayOfSetCells[i][j]->setTransformOriginPoint(qUnit / 2.0, qUnit / 2.0);
                arrayOfSetCells[i][j]->setBrush(QColor("#4395FF"));
                arrayOfSetCells[i][j]->setPen(QPen(QColor("#0E77FF"), 3));


                addToGroup(arrayOfSetCells[i][j]);
                arrayOfSetCells[i][j]->setZValue(0);

                //начисление очков
                setScore(++score);
                if(score > record) setRecord(score);

                qDebug() << score << "placed one square";
            }
        }
    }

    resetShadowsAndLight();

    searchMarkAndDeleteAllStrikes();
}
