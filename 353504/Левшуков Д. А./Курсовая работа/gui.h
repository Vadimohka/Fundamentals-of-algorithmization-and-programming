#ifndef GUI_H
#define GUI_H
#include <string>
#include <QGraphicsTextItem>

#pragma once

void ShowBlockInfo(std::string info, QGraphicsTextItem* t);
void HideBlockInfo(QGraphicsTextItem* t);

void UpdateTurnInfo(QGraphicsTextItem* t);

void ShowResourceInfo(std::string info,QGraphicsTextItem* t);

#endif // GUI_H
