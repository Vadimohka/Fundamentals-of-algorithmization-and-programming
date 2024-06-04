//
// Created by acryoz on 4/30/24.
//

#ifndef COURSEWORK_INCLUDE_SQUAREVALUES_H_
#define COURSEWORK_INCLUDE_SQUAREVALUES_H_

#include <array>
#include "Board.h"

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_SAFETY_TABLE = {
    // clang-format off
    0, 3, 5, 2, 2, 2, 5, 3, 0,
    1, 6, 4, 3, 3, 3, 4, 6, 1,
    2, 3, 5, 5, 5, 5, 4, 3, 2,
    3, 4, 5, 6, 7, 6, 5, 4, 3,
    3, 4, 5, 6, 6, 6, 5, 4, 3,
    2, 3, 6, 5, 5, 5, 6, 3, 2,
    2, 5, 6, 6, 2, 2, 6, 2, 2,
    6, 8, 8, 8, 7, 8, 8, 10, 3,
    3, 7, 7, 6, 3, 6, 8, 6, 2,
};
// clang-format on
static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_SAFETY_TABLE = {
    // clang-format off
    2, 6, 8, 6, 3, 6, 7, 7, 3,
    3, 10, 8, 8, 7, 8, 8, 8, 6,
    2, 2, 6, 2, 2, 6, 6, 5, 2,
    2, 3, 6, 5, 5, 5, 6, 3, 2,
    3, 4, 5, 6, 6, 6, 5, 4, 3,
    3, 4, 5, 6, 7, 6, 5, 4, 3,
    2, 3, 4, 5, 5, 5, 5, 3, 2,
    1, 6, 4, 3, 3, 3, 4, 6, 1,
    0, 3, 5, 2, 2, 2, 5, 3, 0,
};
// clang-format on
static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_PAWN_VALUES_MAP{
    // clang-format off
    8, 7, 6, 6, 6, 6, 6, 8, 7,
    9, 11, 9, 10, 11, 10, 9, 8, 9,
    6, 12, 9, 9, 12, 9, 9, 3, 6,
    8, 11, 9, 9, 11, 9, 9, 3, 8,
    8, 11, 9, 9, 10, 9, 9, 4, 8,
    3, 11, 8, 9, 10, 9, 11, 3, 3,
    9, 11, 8, 8, 9, 9, 8, 11, 9,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0
};
// clang-format on
static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_PAWN_VALUES_MAP{
    // clang-format off
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    9, 11, 8, 9, 9, 8, 8, 11, 9,
    3, 5, 11, 9, 10, 9, 8, 11, 3,
    8, 4, 9, 9, 10, 9, 9, 11, 8,
    8, 3, 9, 9, 11, 9, 9, 11, 8,
    6, 3, 9, 9, 12, 9, 9, 12, 6,
    9, 8, 9, 10, 11, 10, 9, 11, 9,
    7, 8, 6, 6, 6, 6, 6, 7, 8
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_LANCE_VALUES_MAP{
    // clang-format off
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 9, 9, 9, 9, 9, 9, 9, 7,
    9, 9, 9, 9, 9, 9, 9, 9, 9,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_LANCE_VALUES_MAP{
    // clang-format off
    9, 9, 9, 9, 9, 9, 9, 9, 9,
    7, 9, 9, 9, 9, 9, 9, 9, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7,
    6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_KNIGHT_VALUES_MAP{
    // clang-format off
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 4, 2, 2,
    2, 2, 2, 3, 3, 3, 8, 2, 2,
    2, 5, 3, 5, 3, 5, 3, 7, 2,
    3, 2, 2, 3, 3, 3, 3, 3, 3,
    4, 2, 7, 2, 2, 2, 7, 2, 4,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    1, 5, 3, 3, 3, 3, 3, 5, 1,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_KNIGHT_VALUES_MAP{
    // clang-format off
    1, 5, 3, 3, 3, 3, 3, 5, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    4, 2, 7, 2, 2, 2, 7, 2, 4,
    3, 3, 3, 3, 3, 3, 2, 2, 3,
    2, 7, 3, 5, 3, 5, 3, 5, 2,
    2, 2, 8, 3, 3, 3, 2, 2, 2,
    2, 2, 4, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_SILVER_VALUES_MAP{
    // clang-format off
    0, 2, 5, 6, 0, 6, 7, 2, 0,
    0, 7, 5, 5, 1, 5, 5, 7, 0,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 3, 3, 2, 3, 3, 3, 2,
    7, 5, 3, 3, 7, 3, 3, 3, 3,
    2, 8, 5, 6, 3, 6, 3, 7, 2,
    4, 4, 8, 3, 8, 3, 8, 4, 4,
    3, 3, 8, 7, 4, 7, 9, 4, 3,
    1, 2, 4, 2, 1, 2, 4, 2, 1,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_SILVER_VALUES_MAP{
    // clang-format off
    1, 2, 4, 2, 1, 2, 4, 2, 1,
    3, 4, 8, 7, 4, 7, 8, 3, 3,
    4, 4, 9, 3, 8, 3, 8, 4, 4,
    2, 7, 3, 6, 3, 6, 5, 8, 2,
    3, 3, 3, 3, 7, 3, 3, 5, 7,
    2, 3, 3, 3, 2, 3, 3, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2,
    0, 7, 5, 5, 1, 5, 5, 7, 0,
    0, 2, 7, 6, 0, 6, 5, 2, 0,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_GOLD_VALUES_MAP{
    // clang-format off
    2, 7, 6, 2, 2, 2, 6, 7, 2,
    2, 7, 6, 4, 3, 4, 6, 7, 2,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 2, 2, 2, 2, 2, 2, 2, 0,
    0, 2, 2, 2, 2, 2, 2, 2, 0,
    0, 3, 3, 3, 3, 8, 3, 3, 2,
    0, 4, 7, 7, 9, 7, 9, 4, 0,
    0, 1, 5, 2, 2, 2, 5, 1, 0,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_GOLD_VALUES_MAP{
    // clang-format off
    0, 1, 5, 2, 2, 2, 5, 1, 0,
    0, 4, 9, 7, 9, 7, 7, 4, 0,
    0, 3, 3, 8, 3, 3, 3, 3, 2,
    0, 2, 2, 2, 2, 2, 2, 2, 0,
    0, 2, 2, 2, 2, 2, 2, 2, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    2, 7, 6, 4, 3, 4, 6, 7, 2,
    2, 7, 6, 2, 2, 2, 6, 7, 2,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_BISHOP_VALUES_MAP{
    // clang-format off
    7, 4, 8, 6, 3, 6, 8, 4, 7,
    2, 8, 5, 5, 5, 5, 5, 7, 2,
    2, 1, 5, 5, 5, 5, 5, 1, 2,
    2, 3, 6, 5, 5, 5, 6, 3, 2,
    2, 3, 3, 4, 8, 4, 3, 3, 2,
    4, 3, 3, 6, 3, 7, 3, 3, 2,
    3, 2, 4, 2, 6, 2, 9, 3, 7,
    2, 3, 3, 5, 2, 5, 3, 8, 2,
    4, 2, 2, 2, 2, 2, 6, 2, 5,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_BISHOP_VALUES_MAP{
    // clang-format off
    5, 2, 6, 2, 2, 2, 2, 2, 4,
    2, 8, 3, 5, 2, 5, 3, 3, 2,
    7, 3, 9, 2, 6, 2, 4, 2, 3,
    2, 3, 3, 7, 3, 6, 3, 3, 4,
    2, 3, 3, 4, 8, 4, 3, 3, 2,
    2, 3, 6, 5, 5, 5, 6, 3, 2,
    2, 1, 5, 5, 5, 5, 5, 1, 2,
    2, 7, 5, 5, 5, 5, 5, 8, 2,
    7, 4, 8, 6, 2, 6, 8, 4, 7,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_ROOK_VALUES_MAP{
    // clang-format off
    3, 8, 7, 7, 7, 7, 7, 8, 3,
    3, 7, 7, 7, 7, 7, 7, 8, 3,
    3, 4, 4, 4, 4, 4, 4, 4, 3,
    3, 7, 7, 7, 7, 7, 7, 7, 3,
    3, 6, 5, 5, 5, 5, 5, 5, 5,
    3, 6, 5, 5, 5, 5, 5, 5, 5,
    3, 3, 3, 3, 3, 3, 3, 3, 3,
    6, 2, 4, 3, 7, 7, 8, 6, 6,
    5, 3, 3, 3, 6, 6, 6, 5, 5,
};
// clang-format on

static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_ROOK_VALUES_MAP{
    // clang-format off
    5, 5, 6, 6, 6, 3, 3, 3, 5,
    6, 6, 8, 7, 7, 3, 4, 2, 6,
    3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 6, 5, 5, 5, 5, 5, 5, 5,
    3, 6, 5, 5, 5, 5, 5, 5, 5,
    3, 7, 7, 7, 7, 7, 7, 7, 3,
    3, 4, 4, 4, 4, 4, 4, 4, 3,
    3, 8, 7, 7, 7, 7, 7, 7, 3,
    3, 8, 7, 7, 7, 7, 7, 8, 3,
};
// clang-format on
#endif  //COURSEWORK_INCLUDE_SQUAREVALUES_H_
