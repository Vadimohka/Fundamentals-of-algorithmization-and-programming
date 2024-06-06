#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QVector>
#include <QVariant>
#include <QPair>
#include <QStack>
#include <QSoundEffect>

// модель игры
class BoardModel {
public:
    // размер стороны игрового квадрата
    static constexpr int GAME_SHAPE = 4;

    // размер поля
    static constexpr int GAME_SIZE = GAME_SHAPE * GAME_SHAPE;

    // пустой элемент
    static constexpr int EMPTY_ELEMENT = 0;

    BoardModel();

    // is_rnd - создать случайную расстановку или нет
    // complexity - сложность генерируемой расстановки
    BoardModel(const bool is_rnd, const int complexity);

    // проверить решена ли задача
    // если да то вернуть кол-во перестановок
    QPair<bool, QVariant> is_solved() const noexcept;

    // получить поле
    const QVector<int>& get_board() const noexcept;

    // проверить возможно ли
    // начать новую игру или сделать шаг назад
    bool check_back_moves_available() const noexcept;

    // вернуть к начальной расстановке
    void set_start_board() noexcept;

    // установить новую расстановку
    void set_new_board(const bool is_rnd, const int complexity);

    // совершить перестановку
    // если перестановка совершена вернуть
    // индекс пустой клетки, которая была переставлена
    // idx - индекс переставляемого элемента
    QPair<bool, QVariant> move(const int idx);

    // вернуться на шаг назад
    // если успешно, то вернуть индексы элементов,
    // которые поменялись местами
    QPair<bool, QPair<QVariant, QVariant>> back_move() noexcept;

private:
    enum class DIRECTION {
        UP = 1,
        DOWN,
        LEFT,
        RIGHT
    };

    // коэффицент сложности
    static constexpr int _COMPLEXITY_COEF = 10;

    // коэффицент кол-ва шагов на решение задачи
    static constexpr int _SHIFTS_PER_STEP_COEF = 100;

    // посчитать кол-во перестановок
    // по относительной сложности
    static int _compute_actual_complexity(const int complexity);

    // получить случайное направление
    static DIRECTION _gen_direction() noexcept;

    // проверить возможна ли перестановка в этом направлении
    static bool _check_direction(const int nul_idx, const DIRECTION direction) noexcept;

    // проверить является ли элемент по индексу rhs
    // соседом элементу по индексу lhs в данном направлении
    static bool _check_is_neighbour(const int lhs, const int rhs, const DIRECTION direction) noexcept;

    // сделать перестановку если возможно
    static bool _make_move(QVector<int>& board, int& nul_idx, const DIRECTION direction) noexcept;

    // получить решённую перестановку
    static QVector<int> _get_solved_board();

    // проверить решена ли расстановка
    // board - расстановка для проверки
    static bool _check_solved(const QVector<int>& board) noexcept;

    // сгенерировать расстановку
    // complexity - сложность генерируемой расстановки
    static QPair<QVector<int>, int> _gen_board(const int num_shifts);

    // вспомогательная функция для
    // инициализации случайной расстановки
    void init_random(const int complexity);

    QVector<int>              _board;             // расстановка
    int                       _nul_index;         // индекс пустого элемента
    bool                      _is_solved;         // решена ли расстановка

    QVector<int>              _start_board;       // начальная расстановка
    int                       _start_nul_index;   // начальный индекс пустого элемента
    bool                      _start_is_solved;   // решена ли начальная расстановка

    int                       _num_shifts;        // кол-во совершённых перестановок
    QStack<QPair<int, int>>   _states;            // история перестановок


    QSoundEffect sound;
};

#endif // BOARDMODEL_H
