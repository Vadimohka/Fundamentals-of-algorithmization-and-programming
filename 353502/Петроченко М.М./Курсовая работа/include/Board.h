#pragma once
#ifndef COURSEWORK_LIB_BOARD_H_
#define COURSEWORK_LIB_BOARD_H_

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QVector>

#include <QRandomGenerator64>
#include "Move.h"
#include "Pieces.h"
#include "Squares.h"

static constexpr uint8_t BOARD_SIZE = 9;

static const QString DEFAULT_BOARD =
    "lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL b ";

class Board {
   public:
    Board(QString SFEN = DEFAULT_BOARD);
    Board(const Board&) = default;
    QString print();
    QString printKomadai(uint8_t color);
    void printMoves();
    void setBoardSFEN(QString);
    void precalcDistanceToEdges();
    void setPiece(uint8_t, uint8_t);
    void makeMove(Move);
    uint8_t mateState();
    bool isValid(uint8_t square);
    QVector<Move> generateMoves(uint8_t);
    QVector<Move> generateGeneralsKingMoves(uint8_t, uint8_t);
    QVector<Move> generateSlidingMoves(uint8_t, uint8_t);
    QVector<Move> generatePawnLanceMoves(uint8_t, uint8_t);
    QVector<Move> generateKnightMoves(uint8_t, uint8_t);
    QVector<Move> generatePlacements();
    void generatePawnAttackMap();
    void reorderMoves(QVector<Move>&);
    Move search(int);
    int negaMax(int, int, int);
    uint32_t mobilityScore(uint8_t color);
    int evalBoard();
    int countMaterial(uint8_t);
    int piecePositionScore();
    uint8_t sideToMove() const;
    const QVector<uint8_t>& getSquares() const;
    const QVector<Move>& getLegalMoves() const;
    const QVector<uint8_t>& getBlackKomadai() const;
    const QVector<uint8_t>& getWhiteKomadai() const;
    int getTurnCount();
    bool isAmbiguous(const Move& move);
    void initHash();
    uint64_t hash();

   private:
    uint8_t mated = 0;
    QVector<uint8_t> squares;
    //32 - black
    //16 - white
    uint8_t current_turn = 32;
    uint32_t number_of_turns = 0;
    QVector<uint8_t> white_komadai;
    QVector<uint8_t> black_komadai;
    QVector<Move> possible_moves;
    QVector<QVector<uint8_t>> distance_to_edgs;

    std::array<QVector<uint8_t>, 2> kings;
    std::array<QVector<uint8_t>, 2> pawns;
    std::array<QVector<uint8_t>, 2> lances;
    std::array<QVector<uint8_t>, 2> knights;
    std::array<QVector<uint8_t>, 2> silvers;
    std::array<QVector<uint8_t>, 2> golds;
    std::array<QVector<uint8_t>, 2> turned_pawns;
    std::array<QVector<uint8_t>, 2> turned_lances;
    std::array<QVector<uint8_t>, 2> turned_knights;
    std::array<QVector<uint8_t>, 2> turned_silvers;
    std::array<QVector<uint8_t>, 2> bishops;
    std::array<QVector<uint8_t>, 2> rooks;
    std::array<QVector<uint8_t>, 2> turned_rooks;
    std::array<QVector<uint8_t>, 2> turned_bishops;

    std::array<std::array<uint64_t, 28>, BOARD_SIZE * BOARD_SIZE + 1> zobrist;
    std::unordered_map<uint16_t, int32_t> transpositions;
    std::array<QVector<uint8_t>, 2> pawn_attack_map;
};

#endif  // COURSEWORK_LIB_BOARD_H_
