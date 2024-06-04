//
// Created by acryoz on 4/16/24.
//
#pragma once
#ifndef COURSEWORK_LIB_MOVE_H_
#define COURSEWORK_LIB_MOVE_H_

#include <QDebug>
#include "Pieces.h"
#include "Squares.h"

using uint8_t = unsigned char;

enum Directions : int8_t {
    North = 0,  //-9
    South = 1,  //9
    East = 2,   //-1
    West = 3,   //1
    NW = 4,     //-8
    NE = 5,     //-10
    SW = 6,     //10
    SE = 7,     //8
};

static const int DIRECTION_OFFSET[8]{ -9, 9, -1, 1, -8, -10, 10, 8 };

enum MoveType : uint8_t {
    Regular,
    Capture,
    Placement,
    Promotion,
};

class Move {
   public:
    Move();
    Move(uint8_t square, uint8_t destination, uint8_t piece, uint8_t type);
    void print();
    uint8_t startSq() const;
    uint8_t destSq() const;
    uint8_t pieceType() const;
    uint8_t moveType() const;
    bool operator==(const Move& lhs) const;
    bool operator!=(const Move& lhs) const;
    bool operator<(const Move& other) const;
    int getScore();
    void setScore(int);
    bool ambiguous(const Move& other) const;

   private:
    int score = 0;
    uint8_t type;
    uint8_t start;
    uint8_t destination;
    uint8_t piece;
};


#endif  //COURSEWORK_LIB_MOVE_H_
