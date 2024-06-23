#include "level.h"
#include <QDebug>
#include "randomlevel.h"

Level::Level()
    : m_levelData(new QVector<LevelData>())
{

}

Level::~Level()
{
    delete m_levelData;
}

//генерируем уровни
void Level::loadLevel(int i)
{
    m_levelData->clear();
    LevelData levelData;
    int colorValue;
    int x;
    int y;
    QPoint position;
    //кол-во блоков
    int numberOfBlocks;

    //int numberOfBlocks = Random::get(20, 40);
    if(i == 1) {

        // ОТЛАДКА
        //numberOfBlocks = Random::get(1, 2);
        // ОТЛАДКА

        numberOfBlocks = Random::get(10, 15);
    }
    else if(i == 2) {
        numberOfBlocks = Random::get(20, 35);
    }
    else if(i == 3) {
        numberOfBlocks = Random::get(45, 75);
    }
    else {
        numberOfBlocks = Random::get(20, 75);
    }

    for (int i = 0; i < numberOfBlocks; ++i)
    {
        //qDebug() << i;
        colorValue = Random::get(0, 4);
        levelData.colorValue = colorValue;

        // Генерируем случайное число от 0 до 10 и умножаем на 48
        x = Random::get(0, 10) * 48;
        y = Random::get(5, 20) * 16;

        position = QPoint(x,y);
        levelData.position = position;
        levelData.isDeleted = false;
        m_levelData->push_back(levelData);
    }
}
