#include "../include/Board.h"

Board::Board(QString SFEN) {
    this->current_turn = Pieces::Black;
    this->initHash();
    this->squares = QVector<uint8_t>(BOARD_SIZE * BOARD_SIZE, 0);
    this->white_komadai = QVector<uint8_t>(0, 0);
    this->black_komadai = QVector<uint8_t>(0, 0);
    this->precalcDistanceToEdges();
    this->setBoardSFEN(SFEN);
    this->possible_moves = this->generateMoves(this->current_turn);
}

QString Board::print() {
    QString rep;
    QTextStream stream(&rep);
    QVector<QString> output(BOARD_SIZE * BOARD_SIZE, "-");
    for (uint8_t color = 0; color < 2; ++color) {
        uint8_t piece_color = (color == 0) ? Pieces::Black : Pieces::White;
        for (uint8_t square : this->pawns[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Pawn);
        }
        for (uint8_t square : this->lances[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Lance);
        }
        for (uint8_t square : this->knights[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Knight);
        }
        for (uint8_t square : this->silvers[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Silver);
        }
        for (uint8_t square : this->golds[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Gold);
        }
        for (uint8_t square : this->bishops[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Bishop);
        }
        for (uint8_t square : this->rooks[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::Rook);
        }
        for (uint8_t square : this->turned_pawns[color]) {
            output[square] =
                piece_literals.at(piece_color | Pieces::TurnedPawn);
        }
        for (uint8_t square : this->turned_lances[color]) {
            output[square] =
                piece_literals.at(piece_color | Pieces::TurnedLance);
        }
        for (uint8_t square : this->turned_knights[color]) {
            output[square] =
                piece_literals.at(piece_color | Pieces::TurnedKnight);
        }
        for (uint8_t square : this->turned_silvers[color]) {
            output[square] =
                piece_literals.at(piece_color | Pieces::TurnedSilver);
        }
        for (uint8_t square : this->turned_bishops[color]) {
            output[square] =
                piece_literals.at(piece_color | Pieces::TurnedBishop);
        }
        for (uint8_t square : this->turned_rooks[color]) {
            output[square] =
                piece_literals.at(piece_color | Pieces::TurnedRook);
        }
        for (uint8_t square : this->kings[color]) {
            output[square] = piece_literals.at(piece_color | Pieces::King);
        }
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = BOARD_SIZE - 1; j >= 0; --j) {
            if (j == 8) {

            } else if ((TYPE_MASK & this->squares[i * BOARD_SIZE + j]) ==
                           Pieces::TurnedPawn ||
                       (TYPE_MASK & this->squares[i * BOARD_SIZE + j]) ==
                           Pieces::TurnedLance ||
                       (TYPE_MASK & this->squares[i * BOARD_SIZE + j]) ==
                           Pieces::TurnedSilver ||
                       (TYPE_MASK & this->squares[i * BOARD_SIZE + j]) ==
                           Pieces::TurnedBishop ||
                       (TYPE_MASK & this->squares[i * BOARD_SIZE + j]) ==
                           Pieces::TurnedRook ||
                       (TYPE_MASK & this->squares[i * BOARD_SIZE + j]) ==
                           Pieces::TurnedKnight) {
                stream << " ";
            } else {
                stream << "  ";
            }

            stream << output[i * BOARD_SIZE + j];
        }
        stream << '\n';
    }
    return rep;
}

void Board::setPiece(uint8_t square, uint8_t piece) {
    this->squares[square] = piece;
}

QString Board::printKomadai(uint8_t color) {
    QString res;
    QTextStream stream(&res);
    QVector<uint8_t>& komadai =
        (color == Pieces::Black) ? this->black_komadai : this->white_komadai;
    int count = 0;
    for (uint8_t piece : komadai) {
        stream << piece_literals.at(piece);
        if (count != komadai.length() - 1) {
            stream << ", ";
        }
        ++count;
    }
    return res;
}

void Board::setBoardSFEN(QString SFEN) {
    uint8_t color;
    bool turned = false;
    QStringList list = SFEN.split(' ');
    size_t i = 0;
    size_t j = BOARD_SIZE - 1;
    for (size_t k = 0; k < list[0].length(); ++k) {
        char character = list[0].at(k).unicode();
        if (std::isdigit(character) != 0) {
            j -= character - '0';
            continue;
        }
        if (std::isupper(character) != 0) {
            color = Pieces::Black;
        } else {
            color = Pieces::White;
        }
        uint8_t color_index = (color == Pieces::Black) ? 0 : 1;
        switch (tolower(character)) {
            case '+':
                turned = true;
                continue;
            case 'k':
                this->squares[BOARD_SIZE * i + j] = color | Pieces::King;
                this->kings[color_index].push_back(BOARD_SIZE * i + j);
                break;
            case 'p':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedPawn;
                    turned = false;
                    this->turned_pawns[color_index].push_back(BOARD_SIZE * i +
                                                              j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Pawn;
                    this->pawns[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'l':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedLance;
                    turned = false;
                    this->turned_lances[color_index].push_back(BOARD_SIZE * i +
                                                               j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Lance;
                    this->lances[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'n':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedKnight;
                    turned = false;
                    this->turned_knights[color_index].push_back(BOARD_SIZE * i +
                                                                j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Knight;
                    this->knights[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 's':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedSilver;
                    turned = false;
                    this->turned_silvers[color_index].push_back(BOARD_SIZE * i +
                                                                j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Silver;
                    this->silvers[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'g':
                this->squares[BOARD_SIZE * i + j] = color | Pieces::Gold;
                this->golds[color_index].push_back(BOARD_SIZE * i + j);
                break;
            case 'b':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedBishop;
                    turned = false;
                    this->turned_bishops[color_index].push_back(BOARD_SIZE * i +
                                                                j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Bishop;
                    this->bishops[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'r':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedRook;
                    turned = false;
                    this->turned_rooks[color_index].push_back(BOARD_SIZE * i +
                                                              j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Rook;
                    this->rooks[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case '/':
                i += 1;
                j = BOARD_SIZE - 1;
                continue;
            default:
                throw "Logic error";
        }
        j--;
    }
    if (list[1] == "b") {
        this->current_turn = Pieces::Black;
    } else {
        this->current_turn = Pieces::White;
    }
    for (size_t k = 0; k < list[2].length(); ++k) {
        size_t count = 1;
        if (std::isdigit(list[2].at(k).unicode()) != 0) {
            count = list[2].at(k).unicode() - '0';
            k++;
        }
        QVector<uint8_t>* komadai;
        char character = list[2].at(k).unicode();
        if (std::isupper(character) != 0) {
            komadai = &this->black_komadai;
            color = Pieces::Black;
        } else {
            komadai = &this->white_komadai;
            color = Pieces::White;
        }
        switch (tolower(character)) {
            case 'p':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Pawn);
                }
                break;
            case 'l':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Lance);
                }
                break;
            case 'n':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Knight);
                }
                break;
            case 's':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Silver);
                }
                break;
            case 'g':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Gold);
                }
                break;
            case 'b':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Bishop);
                }
                break;
            case 'r':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Rook);
                }
                break;
            default:
                throw "Logic error";
        }
    }
    this->generatePawnAttackMap();
    this->possible_moves = generateMoves(this->current_turn);
}

void Board::precalcDistanceToEdges() {
    this->distance_to_edgs = QVector<QVector<uint8_t>>(BOARD_SIZE * BOARD_SIZE);

    for (int rank = 0; rank < BOARD_SIZE; ++rank) {
        for (int file = BOARD_SIZE - 1; file >= 0; --file) {
            uint8_t north = rank;
            uint8_t south = BOARD_SIZE - 1 - rank;
            uint8_t west = BOARD_SIZE - 1 - file;
            uint8_t east = file;
            uint8_t square = rank * BOARD_SIZE + file;
            this->distance_to_edgs[square] =
                QVector<uint8_t>{ north,
                                  south,
                                  east,
                                  west,
                                  std::min(north, west),
                                  std::min(north, east),
                                  std::min(south, west),
                                  std::min(south, east) };
        }
    }
}

void Board::makeMove(Move move) {
    if (move == Move(0, 0, 0, 0)) {
        this->mated = this->current_turn;
        return;
    }
    this->possible_moves = this->generateMoves(this->current_turn);
    if (this->possible_moves.contains(move)) {
        if (this->squares[move.destSq()] != 0) {
            uint8_t color_index = (this->current_turn == Pieces::Black) ? 0 : 1;
            uint8_t opposite_color = (color_index == 0) ? 1 : 0;
            uint8_t captured_piece = this->squares[move.destSq()];
            captured_piece &= TYPE_MASK;
            switch (captured_piece) {
                case Pieces::King:
                    this->mated = (~this->current_turn) & COLOR_MASK;
                    this->kings[opposite_color].removeOne(move.destSq());
                    return;
                case Pieces::Pawn:
                    this->pawns[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Lance:
                    this->lances[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Knight:
                    this->knights[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Silver:
                    this->silvers[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Gold:
                    this->golds[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Bishop:
                    this->bishops[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Rook:
                    this->rooks[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::TurnedPawn:
                    this->turned_pawns[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::TurnedLance:
                    this->turned_lances[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedKnight:
                    this->turned_knights[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedSilver:
                    this->turned_silvers[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedBishop:
                    this->turned_bishops[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedRook:
                    this->turned_rooks[opposite_color].removeOne(move.destSq());
                    break;
            }
            if (this->current_turn == Pieces::Black) {
                switch (captured_piece) {
                    case Pieces::TurnedPawn:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Pawn);
                        break;
                    case Pieces::TurnedLance:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Lance);
                        break;
                    case Pieces::TurnedKnight:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Knight);
                        break;
                    case Pieces::TurnedSilver:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Silver);
                        break;
                    case Pieces::TurnedBishop:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Bishop);
                        break;
                    case Pieces::TurnedRook:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Rook);
                        break;
                    default:
                        this->black_komadai.push_back(Pieces::Black |
                                                      captured_piece);
                        break;
                }
            } else {
                switch (captured_piece) {
                    case Pieces::TurnedPawn:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Pawn);
                        break;
                    case Pieces::TurnedLance:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Lance);
                        break;
                    case Pieces::TurnedKnight:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Knight);
                        break;
                    case Pieces::TurnedSilver:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Silver);
                        break;
                    case Pieces::TurnedBishop:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Bishop);
                        break;
                    case Pieces::TurnedRook:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Rook);
                        break;
                    default:
                        this->white_komadai.push_back(Pieces::White |
                                                      captured_piece);
                        break;
                }
            }
        }
        if (move.startSq() != 81) {
            uint8_t color = move.pieceType() & COLOR_MASK;
            uint8_t color_index = (color == Pieces::Black) ? 0 : 1;
            switch (this->squares[move.startSq()] & TYPE_MASK) {
                case Pieces::King:
                    this->kings[color_index][this->kings[color_index].indexOf(
                        move.startSq())] = move.destSq();
                    this->squares[move.destSq()] = color | Pieces::King;
                    break;
                case Pieces::Pawn:
                    if (move.moveType() == MoveType::Promotion) {
                        this->pawns[color_index].removeOne(move.startSq());
                        this->turned_pawns[color_index].push_back(
                            move.destSq());
                        this->squares[move.destSq()] =
                            color | Pieces::TurnedPawn;
                    } else {
                        this->pawns[color_index][this->pawns[color_index]
                                                     .indexOf(move.startSq())] =
                            move.destSq();
                        this->squares[move.destSq()] = color | Pieces::Pawn;
                        this->generatePawnAttackMap();
                    }
                    break;
                case Pieces::Lance:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] =
                            color | Pieces::TurnedLance;
                        this->lances[color_index].removeOne(move.startSq());
                        this->turned_lances[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = color | Pieces::Lance;
                        this->lances[color_index]
                                    [this->lances[color_index].indexOf(
                                        move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Knight:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] =
                            color | Pieces::TurnedKnight;
                        this->knights[color_index].removeOne(move.startSq());
                        this->turned_knights[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = color | Pieces::Knight;
                        this->knights[color_index]
                                     [this->knights[color_index].indexOf(
                                         move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Silver:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] =
                            color | Pieces::TurnedSilver;
                        this->silvers[color_index].removeOne(move.startSq());
                        this->turned_silvers[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = color | Pieces::Silver;
                        this->silvers[color_index]
                                     [this->silvers[color_index].indexOf(
                                         move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Gold:
                    this->squares[move.destSq()] = color | Pieces::Gold;
                    this->golds[color_index][this->golds[color_index].indexOf(
                        move.startSq())] = (move.destSq());
                    break;
                case Pieces::Bishop:
                    this->squares[move.destSq()] = color | Pieces::TurnedBishop;
                    if (move.moveType() == MoveType::Promotion) {
                        this->bishops[color_index].removeOne(move.startSq());
                        this->turned_bishops[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = color | Pieces::Bishop;
                        this->bishops[color_index]
                                     [this->bishops[color_index].indexOf(
                                         move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Rook:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] =
                            color | Pieces::TurnedRook;
                        this->rooks[color_index].removeOne(move.startSq());
                        this->turned_rooks[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = color | Pieces::Rook;
                        this->rooks[color_index][this->rooks[color_index]
                                                     .indexOf(move.startSq())] =
                            (move.destSq());
                    }
                    break;
                case Pieces::TurnedPawn:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_pawns[color_index]
                                      [this->turned_pawns[color_index].indexOf(
                                          move.startSq())] = (move.destSq());
                    break;
                case Pieces::TurnedLance:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_lances[color_index]
                                       [this->turned_lances[color_index]
                                            .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedKnight:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_knights[color_index]
                                        [this->turned_knights[color_index]
                                             .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedSilver:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_silvers[color_index]
                                        [this->turned_silvers[color_index]
                                             .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedBishop:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_bishops[color_index]
                                        [this->turned_bishops[color_index]
                                             .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedRook:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_rooks[color_index]
                                      [this->turned_rooks[color_index].indexOf(
                                          move.startSq())] = (move.destSq());
                    break;
            }
            this->squares[move.startSq()] = 0;
        }
        if (move.startSq() == 81) {
            uint8_t color_index =
                ((move.pieceType() & COLOR_MASK) == Pieces::Black) ? 0 : 1;
            this->squares[move.destSq()] = move.pieceType();
            switch (move.pieceType() & TYPE_MASK) {
                case Pieces::Pawn:
                    this->pawns[color_index].append(move.destSq());
                    this->generatePawnAttackMap();
                    break;
                case Pieces::Lance:
                    this->lances[color_index].append(move.destSq());
                    break;
                case Pieces::Knight:
                    this->knights[color_index].append(move.destSq());
                    break;
                case Pieces::Silver:
                    this->silvers[color_index].append(move.destSq());
                    break;
                case Pieces::Gold:
                    this->golds[color_index].append(move.destSq());
                    break;
                case Pieces::Bishop:
                    this->bishops[color_index].append(move.destSq());
                    break;
                case Pieces::Rook:
                    this->rooks[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedPawn:
                    this->turned_pawns[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedLance:
                    this->turned_lances[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedKnight:
                    this->turned_knights[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedSilver:
                    this->turned_silvers[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedBishop:
                    this->turned_bishops[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedRook:
                    this->turned_rooks[color_index].append(move.destSq());
                    break;
            }
            if (this->current_turn == Pieces::Black) {
                this->black_komadai.removeOne(move.pieceType());
            } else {
                this->white_komadai.removeOne(move.pieceType());
            }
        }

        if (this->current_turn == Pieces::Black) {
            this->current_turn = Pieces::White;
        } else {
            this->current_turn = Pieces::Black;
        }
        this->number_of_turns += 1;
        this->possible_moves = generateMoves(this->current_turn);
        if (this->possible_moves.length() == 0) {
            this->mated = this->current_turn;
        }
    }
}

void Board::printMoves() {
    auto moves = this->generateMoves(this->current_turn);
    this->reorderMoves(moves);
    for (Move move : moves) {
        move.print();
    }
}

uint8_t Board::mateState() {
    return this->mated;
}

const QVector<uint8_t>& Board::getSquares() const {
    return this->squares;
}

const QVector<Move>& Board::getLegalMoves() const {
    return this->possible_moves;
}

uint8_t Board::sideToMove() const {
    return this->current_turn;
}

const QVector<uint8_t>& Board::getBlackKomadai() const {
    return this->black_komadai;
}

const QVector<uint8_t>& Board::getWhiteKomadai() const {
    return this->white_komadai;
}

int Board::getTurnCount() {
    return this->number_of_turns;
}

bool Board::isValid(uint8_t square) {
    return square < BOARD_SIZE * BOARD_SIZE && square >= 0;
}

bool Board::isAmbiguous(const Move& move) {
    for (Move mv : this->generateMoves(move.pieceType() & COLOR_MASK)) {
        if (move.ambiguous(mv)) {
            return true;
        }
    }
    return false;
}

void Board::initHash() {
    this->zobrist =
        std::array<std::array<uint64_t, 28>, BOARD_SIZE * BOARD_SIZE + 1>{ 0 };
    for (auto& line : this->zobrist) {
        QRandomGenerator64::global()->fillRange(line.data(), 28);
    }
}

uint64_t Board::hash() {
    uint64_t h;
    if (this->current_turn == Pieces::Black) {
        h ^= this->zobrist[81][0];
    }
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        if (this->squares[i] != 0) {
            uint8_t piece = zobrist_indicies.at(this->squares[i]);
            h ^= this->zobrist[i][piece];
        }
    }
    return h;
}