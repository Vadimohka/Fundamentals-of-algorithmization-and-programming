//
// Created by acryoz on 4/16/24.
//
#include "../include/Pieces.h"

bool isSliding(uint8_t piece) {
    uint8_t piece_type = piece & TYPE_MASK;
    if (piece_type == Pieces::Bishop || piece_type == Pieces::TurnedBishop ||
        piece_type == Pieces::Rook || piece_type == Pieces::TurnedRook) {
        return true;
    }
    return false;
}