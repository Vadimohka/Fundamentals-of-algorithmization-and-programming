//
// Created by acryoz on 4/26/24.
//
#include "../include/Board.h"
#include "../include/SquareValues.h"

int Board::piecePositionScore() {
    int eval = 0;
    //piece formation
    if (this->kings[0].isEmpty()) {
        return std::numeric_limits<int>::max() - 1;
    }
    if (this->kings[1].isEmpty()) {
        return std::numeric_limits<int>::min() + 1;
    }
    for (uint8_t piece : this->pawns[1]) {
        eval += WHITE_PAWN_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->pawns[0]) {
        eval -= BLACK_PAWN_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->lances[1]) {
        eval += WHITE_LANCE_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->lances[0]) {
        eval -= BLACK_LANCE_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->knights[1]) {
        eval += WHITE_KNIGHT_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->knights[0]) {
        eval -= BLACK_KNIGHT_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->silvers[1]) {
        eval += WHITE_SILVER_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->silvers[0]) {
        eval -= BLACK_SILVER_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->golds[1]) {
        eval += WHITE_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->golds[0]) {
        eval -= BLACK_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->bishops[1]) {
        eval += WHITE_BISHOP_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->bishops[0]) {
        eval -= BLACK_BISHOP_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->rooks[1]) {
        eval += WHITE_ROOK_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->rooks[0]) {
        eval -= BLACK_ROOK_VALUES_MAP[piece];
    }
    //turned
    for (uint8_t piece : this->turned_pawns[1]) {
        eval += WHITE_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_pawns[0]) {
        eval -= BLACK_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_lances[1]) {
        eval += WHITE_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_lances[0]) {
        eval -= BLACK_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_knights[1]) {
        eval += WHITE_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_knights[0]) {
        eval -= BLACK_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_silvers[1]) {
        eval += WHITE_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_silvers[0]) {
        eval -= BLACK_GOLD_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_bishops[1]) {
        eval += WHITE_BISHOP_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_bishops[0]) {
        eval -= BLACK_BISHOP_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_rooks[1]) {
        eval += WHITE_ROOK_VALUES_MAP[piece];
    }
    for (uint8_t piece : this->turned_rooks[0]) {
        eval -= BLACK_ROOK_VALUES_MAP[piece];
    }
    //king safety
    eval += WHITE_SAFETY_TABLE[this->kings[1][0]];
    eval -= BLACK_SAFETY_TABLE[this->kings[0][0]];
    bool silvers_close = false;
    for (auto dir : DIRECTION_OFFSET) {
        if (this->kings[1][0] + dir >= 0 &&
            this->kings[1][0] + dir < BOARD_SIZE * BOARD_SIZE) {
            if (this->squares[this->kings[1][0] + dir] ==
                (Pieces::White | Pieces::Gold)) {
                eval += 5;
            }
            if (this->squares[this->kings[1][0] + dir] ==
                (Pieces::White | Pieces::Silver)) {
                if (!silvers_close) {
                    eval += 3;
                }
                silvers_close = true;
            }
        }
    }
    for (auto dir : DIRECTION_OFFSET) {
        if (this->kings[0][0] + dir >= 0 &&
            this->kings[0][0] + dir < BOARD_SIZE * BOARD_SIZE) {
            if (this->squares[this->kings[0][0] + dir] ==
                (Pieces::Black | Pieces::Gold)) {
                eval -= 5;
            }
            if (this->squares[this->kings[0][0] + dir] ==
                (Pieces::Black | Pieces::Silver)) {
                if (!silvers_close) {
                    eval -= 3;
                }
                silvers_close = true;
            }
        }
    }
    return eval;
}

int Board::evalBoard() {
    int perspective = (this->current_turn == Pieces::Black) ? -1 : 1;
    int color_index = (this->current_turn == Pieces::Black) ? 0 : 1;
    int opposite_index = (color_index == 0) ? 1 : 0;
    uint8_t player_color = this->current_turn;
    uint8_t opposite_color =
        (player_color == Pieces::Black) ? Pieces::White : Pieces::Black;
    int white_material = this->countMaterial(1);
    int black_material = this->countMaterial(0);
    if (this->possible_moves.isEmpty()) {
        return perspective * (std::numeric_limits<int>::min() + 1);
    }
    int eval = white_material - black_material;
    int mobility_eval = this->mobilityScore(1) - this->mobilityScore(0);
    eval += mobility_eval;
    eval += this->piecePositionScore();
    return eval * perspective;
}

int Board::countMaterial(uint8_t color_index) {
    int material = 0;
    material +=
        this->pawns[color_index].length() * piece_value.at(Pieces::Pawn);
    material +=
        this->lances[color_index].length() * piece_value.at(Pieces::Lance);
    material +=
        this->knights[color_index].length() * piece_value.at(Pieces::Knight);
    material +=
        this->silvers[color_index].length() * piece_value.at(Pieces::Silver);
    material +=
        this->golds[color_index].length() * piece_value.at(Pieces::Gold);
    material +=
        this->bishops[color_index].length() * piece_value.at(Pieces::Bishop);
    material +=
        this->rooks[color_index].length() * piece_value.at(Pieces::Rook);
    material += this->turned_pawns[color_index].length() *
                piece_value.at(Pieces::TurnedPawn);
    material += this->turned_lances[color_index].length() *
                piece_value.at(Pieces::TurnedLance);
    material += this->turned_knights[color_index].length() *
                piece_value.at(Pieces::TurnedKnight);
    material += this->turned_silvers[color_index].length() *
                piece_value.at(Pieces::TurnedSilver);
    material += this->turned_bishops[color_index].length() *
                piece_value.at(Pieces::TurnedBishop);
    material += this->turned_rooks[color_index].length() *
                piece_value.at(Pieces::TurnedRook);
    material += piece_value.at(Pieces::King);
    if (color_index == 0) {
        for (uint8_t piece : this->black_komadai) {
            material += piece_value.at(piece & TYPE_MASK);
        }
    } else {
        for (uint8_t piece : this->white_komadai) {
            material += piece_value.at(piece & TYPE_MASK);
        }
    }
    return material;
}

uint32_t Board::mobilityScore(uint8_t color) {
    this->generatePawnAttackMap();
    int opposite_color_index = (color == Pieces::Black) ? 1 : 0;
    return this->generateMoves(color).size() -
           this->pawn_attack_map[opposite_color_index].size();
}
