//
// Created by acryoz on 4/16/24.
//

#include "../include/Move.h"

Move::Move() {
    this->start = 0;
    this->destination = 0;
    this->piece = 0;
    this->type = 0;
}

Move::Move(uint8_t square, uint8_t destination, uint8_t piece, uint8_t type) {
    this->start = square;
    this->destination = destination;
    this->piece = piece;
    this->type = type;
}

uint8_t Move::startSq() const {
    return this->start;
}

uint8_t Move::destSq() const {
    return this->destination;
}

uint8_t Move::pieceType() const {
    return this->piece;
}

bool Move::operator==(const Move& lhs) const {
    return (this->start == lhs.startSq()) &&
           (this->destination == lhs.destSq()) &&
           (this->piece == lhs.pieceType()) && (this->type == lhs.type);
}

bool Move::operator!=(const Move& lhs) const {
    return !(*this == lhs);
}

int Move::getScore() {
    return this->score;
}

void Move::setScore(int new_score) {
    this->score = new_score;
}

bool Move::operator<(const Move& other) const {
    return this->score > other.score;
}

uint8_t Move::moveType() const {
    return this->type;
}

bool Move::ambiguous(const Move& other) const {
    return (this->destination == other.destination &&
            this->start != other.start && this->type == other.type &&
            this->piece == other.piece);
}

void Move::print() {
    qDebug() << piece_literals.at(this->piece) << this->start
             << this->destination << this->score;
}