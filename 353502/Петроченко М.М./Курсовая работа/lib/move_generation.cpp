//
// Created by acryoz on 4/26/24.
//
#include "../include/Board.h"

void Board::generatePawnAttackMap() {
    QVector<uint8_t> new_black_pawnmap;
    QVector<uint8_t> new_white_pawnmap;
    for (uint8_t square : this->pawns[0]) {
        new_black_pawnmap.push_back(square +
                                    DIRECTION_OFFSET[Directions::North]);
    }
    for (uint8_t square : this->pawns[1]) {
        new_white_pawnmap.push_back(square +
                                    DIRECTION_OFFSET[Directions::South]);
    }
    this->pawn_attack_map[0] = new_black_pawnmap;
    this->pawn_attack_map[1] = new_white_pawnmap;
}

QVector<Move> Board::generateSlidingMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    int start_direction;
    int end_direction;
    bool turned_rook = false;
    bool turned_bishop = false;
    switch (piece & TYPE_MASK) {
        case Pieces::Rook:
            start_direction = 0;
            end_direction = 4;
            break;
        case Pieces::Bishop:
            start_direction = 4;
            end_direction = 8;
            break;
        case Pieces::TurnedRook:
            turned_rook = true;
            start_direction = 0;
            end_direction = 8;
            break;
        case Pieces::TurnedBishop:
            turned_bishop = true;
            start_direction = 0;
            end_direction = 8;
            break;
        default:
            throw "Not sliding piece";
    }
    uint8_t color = piece & COLOR_MASK;
    uint8_t opposite_color = (~color) & COLOR_MASK;
    for (int direction = start_direction; direction < end_direction;
         direction++) {
        int limiter = this->distance_to_edgs[square][direction];
        if (turned_bishop && direction < 4) {
            limiter = std::min(limiter, 1);
        } else if (turned_rook && direction >= 4) {
            limiter = std::min(limiter, 1);
        }
        for (int n = 0; n < limiter; ++n) {
            uint8_t destination =
                square + DIRECTION_OFFSET[direction] * (n + 1);
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) == color) {
                break;
            }
            uint8_t type = (this->squares[destination] == 0)
                               ? MoveType::Regular
                               : MoveType::Capture;
            if (color == Pieces::Black && destination < 3 * BOARD_SIZE &&
                !turned_rook && !turned_bishop) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            } else if (color == Pieces::White &&
                       destination >= 6 * BOARD_SIZE && !turned_bishop &&
                       !turned_rook) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            }
            res.push_back(
                Move(square, destination, this->squares[square], type));
            if ((piece_on_dest & COLOR_MASK) == opposite_color) {
                break;
            }
        }
    }
    return res;
}

QVector<Move> Board::generatePawnLanceMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    uint8_t type = piece & TYPE_MASK;
    uint8_t color = piece & COLOR_MASK;
    uint8_t opposite_color = (~color) & COLOR_MASK;
    uint8_t direction =
        (color == Pieces::White) ? Directions::South : Directions::North;
    uint8_t limiter = this->distance_to_edgs[square][direction];
    if (type == Pieces::Pawn) {
        limiter = std::min(limiter, (uint8_t)1);
    } else {
        limiter = limiter;
    }
    for (int n = 0; n < limiter; ++n) {
        uint8_t destination = square + DIRECTION_OFFSET[direction] * (n + 1);
        uint8_t piece_on_dest = this->squares[destination];
        if ((piece_on_dest & COLOR_MASK) == color) {
            break;
        }
        uint8_t move_type = (this->squares[destination] == 0)
                                ? MoveType::Regular
                                : MoveType::Capture;

        if (color == Pieces::Black && destination < 3 * BOARD_SIZE) {
            res.push_back(Move(square, destination, this->squares[square],
                               MoveType::Promotion));
        } else if (color == Pieces::White && destination >= 6 * BOARD_SIZE) {
            res.push_back(Move(square, destination, this->squares[square],
                               MoveType::Promotion));
        }
        if (color == Pieces::Black && destination >= BOARD_SIZE) {
            res.push_back(
                Move(square, destination, this->squares[square], move_type));
        } else if (color == Pieces::White && destination < 8 * BOARD_SIZE) {
            res.push_back(
                Move(square, destination, this->squares[square], move_type));
        }
        if ((piece_on_dest & COLOR_MASK) == opposite_color) {
            break;
        }
    }
    if (type == Pieces::Pawn) {
        this->generatePawnAttackMap();
    }
    return res;
}

QVector<Move> Board::generateKnightMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    uint8_t color = piece & COLOR_MASK;
    uint8_t direction =
        (color == Pieces::White) ? Directions::South : Directions::North;
    if (this->distance_to_edgs[square][Directions::West] > 0) {
        if (this->distance_to_edgs[square][direction] >= 2) {
            uint8_t destination = square + 2 * DIRECTION_OFFSET[direction] +
                                  DIRECTION_OFFSET[Directions::West];
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) != color) {
                uint8_t type = (this->squares[destination] == 0)
                                   ? MoveType::Regular
                                   : MoveType::Capture;
                if (color == Pieces::Black && destination < 3 * BOARD_SIZE) {
                    res.push_back(Move(square, destination,
                                       this->squares[square],
                                       MoveType::Promotion));
                } else if (color == Pieces::White &&
                           destination >= 6 * BOARD_SIZE) {
                    res.push_back(Move(square, destination,
                                       this->squares[square],
                                       MoveType::Promotion));
                }
                if (color == Pieces::White && (destination < 7 * BOARD_SIZE)) {
                    res.push_back(
                        Move(square, destination, this->squares[square], type));
                } else if (color == Pieces::Black &&
                           destination >= 2 * BOARD_SIZE) {
                    res.push_back(
                        Move(square, destination, this->squares[square], type));
                }
            }
        }
    }
    if (this->distance_to_edgs[square][Directions::East] > 0) {
        if (this->distance_to_edgs[square][direction] >= 2) {
            uint8_t destination = square + 2 * DIRECTION_OFFSET[direction] +
                                  DIRECTION_OFFSET[Directions::East];
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) != color) {
                uint8_t type = (this->squares[destination] == 0)
                                   ? MoveType::Regular
                                   : MoveType::Capture;
                res.push_back(
                    Move(square, destination, this->squares[square], type));
            }
        }
    }
    return res;
}

QVector<Move> Board::generateGeneralsKingMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    int start_direction = 0;
    int end_direction = 8;
    uint8_t color = piece & COLOR_MASK;
    uint8_t opposite_color = (~color) & COLOR_MASK;
    QVector<uint8_t> forbidden_directions;
    switch (piece & TYPE_MASK) {
        case Pieces::Silver:
            forbidden_directions = { Directions::West, Directions::East };
            (color == Pieces::White)
                ? forbidden_directions.push_back(Directions::North)
                : forbidden_directions.push_back(Directions::South);
            break;
        case Pieces::King:
            break;
        default:
            if (color == Pieces::White) {
                forbidden_directions = { Directions::NE, Directions::NW };
            } else {
                forbidden_directions = { Directions::SE, Directions::SW };
            }
            break;
    }
    bool forb_dir = false;
    for (int direction = start_direction; direction < end_direction;
         direction++) {
        for (uint8_t dir : forbidden_directions) {
            if (dir == direction) {
                forb_dir = true;
            }
        }
        if (forb_dir) {
            forb_dir = false;
            continue;
        }
        int limiter =
            std::min(this->distance_to_edgs[square][direction], (uint8_t)1);
        for (int n = 0; n < limiter; ++n) {
            uint8_t destination =
                square + DIRECTION_OFFSET[direction] * (n + 1);
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) == color) {
                break;
            }
            bool mateable = false;
            if ((piece & TYPE_MASK) == Pieces::King) {
                for (size_t i = destination % 9; i < BOARD_SIZE * BOARD_SIZE;
                     i += BOARD_SIZE) {
                    if (this->squares[i] != 0) {
                        if (i != destination &&
                            (this->squares[i] ==
                                 (opposite_color | Pieces::Rook) ||
                             this->squares[i] ==
                                 (opposite_color | Pieces::TurnedRook))) {
                            mateable = true;
                            break;
                        }
                        if (color == Pieces::Black && i < destination &&
                            this->squares[i] ==
                                (opposite_color | Pieces::Lance)) {
                            mateable = true;
                            break;
                        }
                        if (color == Pieces::White && i > destination &&
                            this->squares[i] ==
                                (opposite_color | Pieces::Lance)) {
                            mateable = true;
                            break;
                        }
                        break;
                    }
                }
                uint rank_start = destination - destination % BOARD_SIZE;
                uint rank_end = rank_start + BOARD_SIZE;
                for (size_t i = rank_start; i < rank_end && !mateable; ++i) {
                    if (this->squares[i] != 0) {
                        if (i != destination &&
                                this->squares[i] ==
                                    (opposite_color | Pieces::Rook) ||
                            this->squares[i] ==
                                (opposite_color | Pieces::TurnedRook)) {
                            mateable = true;
                            break;
                        }
                        break;
                    }
                }
                int dest_copy = destination;
                while (!mateable && isValid(dest_copy)) {
                    if (dest_copy != destination &&
                        (this->squares[dest_copy] ==
                             (opposite_color | Pieces::Bishop) ||
                         this->squares[dest_copy] ==
                             (opposite_color | Pieces::TurnedBishop))) {
                        mateable = true;
                        break;
                    }
                    dest_copy -= DIRECTION_OFFSET[Directions::NE];
                }
                dest_copy = destination;
                while (!mateable && isValid(dest_copy)) {
                    if (dest_copy != destination &&
                        (this->squares[dest_copy] ==
                             (opposite_color | Pieces::Bishop) ||
                         this->squares[dest_copy] ==
                             (opposite_color | Pieces::TurnedBishop))) {
                        mateable = true;
                        break;
                    }
                    dest_copy -= DIRECTION_OFFSET[Directions::NW];
                }
                dest_copy = destination;
                while (!mateable && isValid(dest_copy)) {
                    if (dest_copy != destination &&
                        (this->squares[dest_copy] ==
                             (opposite_color | Pieces::Bishop) ||
                         this->squares[dest_copy] ==
                             (opposite_color | Pieces::TurnedBishop))) {
                        mateable = true;
                        break;
                    }
                    dest_copy -= DIRECTION_OFFSET[Directions::SW];
                }
                dest_copy = destination;
                while (!mateable && isValid(dest_copy)) {
                    if (dest_copy != destination &&
                        (this->squares[dest_copy] ==
                             (opposite_color | Pieces::Bishop) ||
                         this->squares[dest_copy] ==
                             (opposite_color | Pieces::TurnedBishop))) {
                        mateable = true;
                        break;
                    }
                    dest_copy -= DIRECTION_OFFSET[Directions::SE];
                }
                if (color == Pieces::White) {
                    if (!mateable &&
                            (destination + 19 < BOARD_SIZE * BOARD_SIZE &&
                             this->squares[destination + 19] ==
                                 (opposite_color | Pieces::Knight)) ||
                        (destination + 17 < BOARD_SIZE * BOARD_SIZE &&
                         (this->squares[destination + 17]) ==
                             (opposite_color | Pieces::Knight))) {
                        mateable = true;
                    }
                    if (!mateable &&
                        (destination + DIRECTION_OFFSET[Directions::South] <
                         BOARD_SIZE * BOARD_SIZE) &&
                        this->squares[destination +
                                      DIRECTION_OFFSET[Directions::South]] ==
                            (opposite_color | Pieces::Pawn)) {
                        mateable = true;
                    }
                    if (!mateable) {
                        for (int8_t dir : DIRECTION_OFFSET) {
                            if (!(dir == DIRECTION_OFFSET[Directions::West] ||
                                  dir == DIRECTION_OFFSET[Directions::East] ||
                                  dir == DIRECTION_OFFSET[Directions::North]) &&
                                isValid(destination + dir) &&
                                this->squares[destination + dir] ==
                                    (opposite_color | Pieces::Silver)) {
                                mateable = true;
                                break;
                            }
                            if (!(dir == DIRECTION_OFFSET[Directions::NW] ||
                                  dir == DIRECTION_OFFSET[Directions::NE]) &&
                                isValid(destination + dir) &&
                                this->squares[destination + dir] ==
                                    (opposite_color | Pieces::Gold)) {
                                mateable = true;
                                break;
                            }
                            if (isValid(destination + dir) &&
                                (this->squares[destination + dir] ==
                                     (opposite_color | TurnedBishop) ||
                                 this->squares[destination + dir] ==
                                     (opposite_color | TurnedRook) ||
                                 this->squares[destination + dir] ==
                                     (opposite_color | King))) {
                                mateable = true;
                                break;
                            }
                        }
                    }
                }

                if (color == Pieces::Black) {
                    if (!mateable && (isValid(destination - 19) &&
                                      this->squares[destination - 19] ==
                                          (opposite_color | Pieces::Knight)) ||
                        (isValid(destination - 17) &&
                         (this->squares[destination - 17]) ==
                             (opposite_color | Pieces::Knight))) {
                        mateable = true;
                    }
                    if (!mateable &&
                        (isValid(destination +
                                 DIRECTION_OFFSET[Directions::North])) &&
                        this->squares[destination +
                                      DIRECTION_OFFSET[Directions::North]] ==
                            (opposite_color | Pieces::Pawn)) {
                        mateable = true;
                    }
                    if (!mateable) {
                        for (int8_t dir : DIRECTION_OFFSET) {
                            if (!(dir == DIRECTION_OFFSET[Directions::West] ||
                                  dir == DIRECTION_OFFSET[Directions::East] ||
                                  dir == DIRECTION_OFFSET[Directions::South]) &&
                                isValid(destination + dir) &&
                                this->squares[destination + dir] ==
                                    (opposite_color | Pieces::Silver)) {
                                mateable = true;
                                break;
                            }
                            if (!(dir == DIRECTION_OFFSET[Directions::SW] ||
                                  dir == DIRECTION_OFFSET[Directions::SE]) &&
                                isValid(destination + dir) &&
                                this->squares[destination + dir] ==
                                    (opposite_color | Pieces::Gold)) {
                                mateable = true;
                                break;
                            }
                            if (isValid(destination + dir) &&
                                (this->squares[destination + dir] ==
                                     (opposite_color | TurnedBishop) ||
                                 this->squares[destination + dir] ==
                                     (opposite_color | TurnedRook) ||
                                 this->squares[destination + dir] ==
                                     (opposite_color | King))) {
                                mateable = true;
                                break;
                            }
                        }
                    }
                }
            }
            uint8_t type = (this->squares[destination] == 0)
                               ? MoveType::Regular
                               : MoveType::Capture;
            if (piece == (Pieces::Black | Pieces::Silver) &&
                destination < 3 * BOARD_SIZE) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            } else if (piece == (Pieces::White | Pieces::Silver) &&
                       destination >= 6 * BOARD_SIZE) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            }
            if (!mateable) {
                res.push_back(
                    Move(square, destination, this->squares[square], type));
            }
            if ((piece_on_dest & COLOR_MASK) == opposite_color) {
                break;
            }
        }
    }
    return res;
}

QVector<Move> Board::generatePlacements() {
    QVector<Move> res;
    QVector<uint8_t>* komadai;
    (this->current_turn == Pieces::Black) ? komadai = &this->black_komadai
                                          : komadai = &this->white_komadai;
    uint8_t color = this->current_turn;
    uint8_t starting = 0;
    uint8_t ending = BOARD_SIZE * BOARD_SIZE;
    QVector<bool> seen(9);
    for (uint8_t piece : *komadai) {
        uint8_t piece_type = piece & TYPE_MASK;
        if (seen[piece_type]) {
            continue;
        }
        if (piece_type == Pieces::Pawn || piece_type == Pieces::Knight ||
            piece_type == Pieces::Lance) {
            if (piece_type == Pieces::Pawn || piece_type == Pieces::Lance) {
                if (color == Pieces::Black) {
                    starting = 9;
                } else {
                    ending = 72;
                }
            } else {
                if (color == Pieces::Black) {
                    starting = 18;
                } else {
                    ending = 63;
                }
            }
        }
        for (uint8_t square = starting; square < ending; ++square) {
            bool legal = true;
            if (this->squares[square] == 0) {
                if (piece_type == Pieces::Pawn) {
                    uint8_t file = square % BOARD_SIZE;
                    for (uint8_t sq = file; sq < BOARD_SIZE * BOARD_SIZE;
                         sq += 9) {
                        if ((this->squares[sq]) ==
                            (this->current_turn | Pieces::Pawn)) {
                            legal = false;
                            break;
                        }
                    }
                }
                if (legal) {
                    res.push_back(Move(81, square, piece, MoveType::Placement));
                }
            }
        }
        seen[piece_type] = true;
    }
    return res;
}

QVector<Move> Board::generateMoves(uint8_t color) {
    QVector<Move> res;

    uint8_t color_index = (color == Pieces::Black) ? 0 : 1;
    for (uint8_t square : this->bishops[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->rooks[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_rooks[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_bishops[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->pawns[color_index]) {
        res.append(generatePawnLanceMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->lances[color_index]) {
        res.append(generatePawnLanceMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->knights[color_index]) {
        res.append(generateKnightMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->silvers[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->golds[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_pawns[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_lances[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_knights[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_silvers[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->kings[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    res.append(generatePlacements());
    return res;
}
