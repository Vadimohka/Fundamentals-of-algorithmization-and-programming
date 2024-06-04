//
// Created by acryoz on 5/1/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->mate_checker = new QTimer;
    QObject::connect(this->mate_checker, SIGNAL(timeout()), this,
                     SLOT(mateCheck()));
    mate_checker->start(100);
    this->hide();
    this->start_menu = new StartMenu(nullptr);
    this->start_menu->show();
    QObject::connect(this->start_menu, SIGNAL(botChosen(bool, uint8_t)), this,
                     SLOT(start(bool, uint8_t)));

    this->end_menu = new EndMenu;
    QObject::connect(this->end_menu, SIGNAL(end()), this, SLOT(end()));
    QObject::connect(this->end_menu, SIGNAL(restart()), this, SLOT(restart()));

    QObject::connect(this, SIGNAL(gameEnd(uint8_t)), this, SLOT(mate(uint8_t)));

    this->reg_exprs = QVector<QRegExp>{};
    this->reg_exprs.push_back(QRegExp("([1-9][a-i][1-9][a-i]{1})\\+?"));
    this->reg_exprs.push_back(QRegExp("([PLNSGBRK][1-9][a-i])"));

    this->timer = new QTimer();
    this->timer->setInterval(TIMER_INTERVAL);
    this->timer->start();
    QObject::connect(this->timer, SIGNAL(timeout()), SLOT(tick()));

    this->black_time = new QTime(0, 10, 0);
    this->white_time = new QTime(0, 10, 0);

    this->black_timer =
        new QLabel("Black: " + this->black_time->toString("mm:ss"));
    this->white_timer =
        new QLabel("White: " + this->white_time->toString("mm:ss"));

    this->black_timer->setMinimumWidth(RIGHT_MENU_MINIMUM_WIDTH);
    this->white_timer->setMinimumWidth(RIGHT_MENU_MINIMUM_WIDTH);

    this->move_log = new QTextEdit;
    this->move_log->setReadOnly(true);
    this->move_log->setMinimumWidth(RIGHT_MENU_MINIMUM_WIDTH);
    this->move_log->setMaximumHeight(MOVE_LOG_MAX_HEIGHT);

    this->timer_vbox = new QVBoxLayout;
    this->timer_vbox->addWidget(this->white_timer);
    this->timer_vbox->addWidget(this->move_log);
    this->timer_vbox->addWidget(this->black_timer);

    this->board = Board(DEFAULT_BOARD);

    this->board_rep = new TextBoard;
    this->board_rep->setText(this->board.print());

    this->vertical_coords = new QLabel("a\nb\nc\nd\ne\nf\ng\nh\ni");
    this->horizontal_coords = new QLabel("9  8  7  6  5  4  3  2  1");

    this->black_komadai = new QLineEdit;
    this->black_komadai->setReadOnly(true);
    this->black_komadai->setFixedSize(KOMADAI_WIDTH, KOMADAI_HEIGHT);
    this->black_komadai->setText(this->board.printKomadai(Pieces::Black));

    this->white_komadai = new QLineEdit;
    this->white_komadai->setReadOnly(true);
    this->white_komadai->setFixedSize(KOMADAI_WIDTH, KOMADAI_HEIGHT);
    this->white_komadai->setText(this->board.printKomadai(Pieces::White));

    QFont font("JetBrains");
    font.setStyleHint(QFont::Monospace);
    font.setPointSize(16);
    this->vertical_coords->setFont(font);
    this->horizontal_coords->setFont(font);
    this->white_komadai->setFont(font);
    this->black_komadai->setFont(font);

    this->move_prompt = new MoveLineEdit;
    this->move_prompt->setMaximumWidth(MOVE_LINE_WIDTH);

    this->move_button = new QPushButton("Move");

    QObject::connect(this->move_button, SIGNAL(clicked()), SLOT(makeMove()));

    this->board_grid = new QGridLayout;
    this->board_grid->addWidget(this->white_komadai, 0, 0);
    this->board_grid->addWidget(this->black_komadai, 3, 0);
    this->board_grid->addWidget(this->horizontal_coords, 1, 0);
    this->board_grid->addWidget(this->board_rep, 2, 0);
    this->board_grid->addWidget(this->vertical_coords, 2, 1);


    this->main_grid = new QGridLayout;
    this->main_grid->addLayout(this->board_grid, 0, 0);
    this->main_grid->addLayout(this->timer_vbox, 0, 1);
    this->main_grid->addWidget(this->move_prompt, 1, 0);
    this->main_grid->addWidget(this->move_button, 1, 1);
    this->setLayout(this->main_grid);
}

void MainWindow::tick() {
    if (this->board.getTurnCount() == 0) {
        return;
    }
    if (this->board.mateState() != 0) {
        this->mateCheck();
        return;
    }
    if (this->board.sideToMove() == Pieces::Black) {
        this->black_time = new QTime(this->black_time->addSecs(-1));
    } else {
        this->white_time = new QTime(this->white_time->addSecs(-1));
    }
    this->black_timer->setText("Black: " + this->black_time->toString("mm:ss"));
    this->white_timer->setText("White: " + this->white_time->toString("mm:ss"));
}

void MainWindow::mateCheck() {
    if (this->board.mateState() != 0) {
        emit gameEnd(this->board.mateState());
    }
    return;
}

void MainWindow::makeMove() {
    Move move = this->MoveValidator(this->move_prompt->text());
    if (move == Move(0, 0, 0, 0)) {
        this->move_prompt->setText("Invalid move");
    } else {
        this->move_prompt->clear();
        this->move_log->append(this->moveToPGN(move));
        this->board.makeMove(move);
        this->board_rep->setText(this->board.print());
        this->white_komadai->setText(this->board.printKomadai(Pieces::White));
        this->black_komadai->setText(this->board.printKomadai(Pieces::Black));
        if (isBot) {
            Move next_move = this->board.search(1);
            this->board.makeMove(next_move);
            this->move_log->append(this->moveToPGN(next_move));
            this->white_komadai->setText(
                this->board.printKomadai(Pieces::White));
            this->black_komadai->setText(
                this->board.printKomadai(Pieces::Black));
            this->board_rep->setText(this->board.print());
        }
    }
}

QString MainWindow::moveToPGN(const Move& move) {
    QString res;
    res.append(QString("%1. ").arg(this->move_count));
    this->move_count++;
    res.append(
        piece_literals.at((move.pieceType() & TYPE_MASK) | Pieces::Black));
    if (this->board.isAmbiguous(move)) {
        std::string coords;
        coords.push_back('1' + move.startSq() % BOARD_SIZE);
        coords.push_back('a' + move.startSq() / BOARD_SIZE);
        res.append(QString::fromStdString(coords));
    }
    QChar mt_char;
    switch (move.moveType()) {
        case MoveType::Regular:
            mt_char = '-';
            break;
        case MoveType::Capture:
            mt_char = 'x';
            break;
        case MoveType::Placement:
            mt_char = '*';
            break;
        case MoveType::Promotion:
            mt_char = '+';
            break;
    }
    res.push_back(mt_char);
    std::string coords;
    coords.push_back('1' + move.destSq() % BOARD_SIZE);
    coords.push_back('a' + move.destSq() / BOARD_SIZE);
    res.append(QString::fromStdString(coords));
    return res;
}

Move MainWindow::MoveValidator(QString move_string) {
    if (this->reg_exprs[0].exactMatch(move_string)) {
        std::string move_str = move_string.toStdString();
        bool promotion = false;
        int starting_square =
            (move_str[0] - '1') + BOARD_SIZE * (move_str[1] - 'a');
        int destination_square =
            (move_str[2] - '1') + BOARD_SIZE * (move_str[3] - 'a');
        if (move_str.back() == '+') {
            move_str.erase(move_str.end() - 1, move_str.end());
            promotion = true;
        }
        uint8_t piece = this->board.getSquares()[starting_square];
        uint8_t color = this->board.sideToMove();
        if (color != (piece & COLOR_MASK)) {
            return Move(0, 0, 0, 0);
        }
        MoveType move_type;
        if (promotion) {
            move_type = MoveType::Promotion;
        } else if (this->board.getSquares()[destination_square] != 0) {
            move_type = MoveType::Capture;
        } else {
            move_type = MoveType::Regular;
        }
        Move move = Move(starting_square, destination_square, piece, move_type);
        if (this->board.getLegalMoves().contains(move)) {
            return move;
        }
        return Move(0, 0, 0, 0);
    } else if (this->reg_exprs[1].exactMatch(move_string)) {
        std::string move_str = move_string.toStdString();
        uint8_t color = this->board.sideToMove();
        uint8_t piece = 0;
        switch (move_str[0]) {
            case 'P':
                piece = Pieces::Pawn;
                break;
            case 'L':
                piece = Pieces::Lance;
                break;
            case 'N':
                piece = Pieces::Knight;
                break;
            case 'S':
                piece = Pieces::Silver;
                break;
            case 'G':
                piece = Pieces::Gold;
                break;
            case 'B':
                piece = Pieces::Bishop;
                break;
            case 'R':
                piece = Pieces::Rook;
                break;
        }
        piece |= color;
        int destination_square =
            (move_str[1] - '1') + BOARD_SIZE * (move_str[2] - 'a');
        Move move(81, destination_square, piece, MoveType::Placement);
        if (this->board.getLegalMoves().contains(move)) {
            return move;
        }
        return Move(0, 0, 0, 0);
    } else {
        return Move(0, 0, 0, 0);
    }
}

void MainWindow::endGame(uint8_t color) {
    this->timer->stop();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::end() {
    this->hide();
    this->close();
}

void MainWindow::start(bool is_bot, uint8_t start_color) {
    this->show();
    this->isBot = is_bot;
    if (is_bot) {
        this->timer->stop();
        this->black_timer->hide();
        this->white_timer->hide();
        if (start_color == Pieces::White) {
            Move move = this->board.search(3);
            this->move_log->append(this->moveToPGN(move));
            this->board.makeMove(move);
            this->board_rep->setText(this->board.print());
            this->white_komadai->setText(
                this->board.printKomadai(Pieces::White));
            this->black_komadai->setText(
                this->board.printKomadai(Pieces::Black));
        }
    }
}

void MainWindow::mate(uint8_t mated) {
    this->hide();
    this->end_menu->set((~mated) & COLOR_MASK);
    this->end_menu->show();
}

void MainWindow::restart() {
    this->board = Board(DEFAULT_BOARD);
    this->move_log->clear();
    this->black_komadai->clear();
    this->white_komadai->clear();
    this->black_time->setHMS(0, 10, 0);
    this->white_time->setHMS(0, 10, 0);
    this->board_rep->setText(this->board.print());
    this->white_timer->show();
    this->black_timer->show();
    this->start_menu->show();
}
