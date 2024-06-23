#ifndef LEVEL_H
#define LEVEL_H

#pragma once

#include <QVector>
#include <QPoint>

struct LevelData
{
    int colorValue;
    QPoint position;
    bool isDeleted;
};

class Level
{
public:
    Level();
    ~Level();
    void loadLevel(int i);
    QList<LevelData>* m_levelData;
};


#endif // LEVEL_H
