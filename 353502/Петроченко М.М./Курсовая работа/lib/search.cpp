//
// Created by acryoz on 4/26/24
//
#include "../include/Board.h"


static const uint8_t CAPTURE_MULTIPLIER = 2;

void Board::reorderMoves(QVector<Move>& moves) {
    for (auto& move : moves) {
        int move_score = 0;
        uint8_t opponent = (this->current_turn == Pieces::Black) ? 1 : 0;
        uint8_t color = COLOR_MASK & move.pieceType();
        uint8_t move_piece = TYPE_MASK & move.pieceType();
        uint8_t capture_piece = TYPE_MASK & this->squares[move.destSq()];
        if (capture_piece != Pieces::None) {
            move_score = CAPTURE_MULTIPLIER *
                         (static_cast<int>(piece_value.at(capture_piece)) -
                          static_cast<int>(piece_value.at(move_piece)) + 1);
        }
        if (move.moveType() == MoveType::Promotion) {
            switch (move.pieceType() & TYPE_MASK) {
                case Pieces::Pawn:
                    move_score += piece_value.at(Pieces::TurnedPawn);
                    break;
                case Pieces::Lance:
                    move_score += piece_value.at(Pieces::TurnedLance);
                    break;
                case Pieces::Knight:
                    move_score += piece_value.at(Pieces::TurnedKnight);
                    break;
                case Pieces::Silver:
                    move_score += piece_value.at(Pieces::TurnedSilver);
                    break;
                case Pieces::Bishop:
                    move_score += piece_value.at(Pieces::TurnedBishop);
                    break;
                case Pieces::Rook:
                    move_score += piece_value.at(Pieces::TurnedRook);
                    break;
            }
            move_score -= piece_value.at(move.pieceType() & TYPE_MASK);
        }
        if (std::count(this->pawn_attack_map[opponent].begin(),
                       this->pawn_attack_map[opponent].end(),
                       move.destSq()) != 0) {
            move_score -= CAPTURE_MULTIPLIER *
                          piece_value.at(move.pieceType() & TYPE_MASK);
        }
        if ((this->squares[move.destSq()] & TYPE_MASK) == Pieces::King) {
            move.setScore(6000);
        } else {
            move.setScore(move_score);
        }
    }
    std::sort(moves.begin(), moves.end());
}

int Board::negaMax(int depth, int alpha, int beta) {
    if (depth == 0) {
        return this->evalBoard();
    }
    QVector<Move> moves = this->generateMoves(this->current_turn);
    if (moves.isEmpty()) {
        int perspective = (this->current_turn == Pieces::Black) ? -1 : 1;
        return (std::numeric_limits<int>::min() + 1) * perspective;
    }
    uint64_t hashed_pos = this->hash();
    if (this->transpositions.contains(hashed_pos)) {
        int eval = this->transpositions.at(hashed_pos);
        if (eval >= beta) {
            return beta;
        }
        return std::max(alpha, eval);
    }
    this->reorderMoves(moves);
    for (Move move : moves) {
        Board tmp(*this);
        tmp.makeMove(move);
        int eval = -tmp.negaMax(depth - 1, -beta, -alpha);
        this->transpositions.insert(std::make_pair(hashed_pos, eval));
        if (eval >= beta) {
            return beta;
        }
        alpha = std::max(alpha, eval);
    }
    return alpha;
}

Move Board::search(int depth = 0) {
    QVector<Move> moves = this->generateMoves(this->current_turn);
    this->reorderMoves(moves);
    Move best_move(0, 0, 0, 0);
    int best_eval = std::numeric_limits<int>::min();
    for (Move move : moves) {
        Board tmp(*this);
        tmp.makeMove(move);
        int alpha = std::numeric_limits<int>::max() - 1;
        int beta = std::numeric_limits<int>::min() + 1;
        int eval = -tmp.negaMax(depth, beta, alpha);

        if (eval > best_eval) {
            best_eval = eval;
            best_move = move;
        }
    }
    return best_move;
}
