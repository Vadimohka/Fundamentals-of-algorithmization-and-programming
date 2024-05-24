#include "puzzle15.h"
#include "ui_puzzle15.h"


Puzzle15::Puzzle15(int size, QMainWindow *mainWindow, Client_Part *client, QString nick, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Puzzle15)
{
    ui->setupUi(this);
    setFixedSize(933, 603);
    _mainWindow = mainWindow;
    _fieldSize = size;
    _client = client;
    nickname = nick;
    connect(_client, &Client_Part::dataReady, this, &Puzzle15::handleServerResponse);
    setWindowTitle("Окно для игры");
    _grid = new QGridLayout(ui->graphicsView);
    pv = new PuzzleView();
    pv->SetPuzzleView(_grid, ui->graphicsView, size);
    pv->setLabel(ui->lbl_pixmap);
    pv->setButtons(ui->bnt_goBackToMainMenu, ui->bnt_generation);
    pv->generateInitialPuzzle();
    pv->genInit();
    pv->setClient(_client, nickname);
    _buttons = pv->get_buttons();
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        ui->lbl_count_attempts->setText(QString::number(pv->get_count_of_attempts()));
    });
    timer->start(25);
    connect(&_solver, &PuzzleSolver::solutionFound, this, &Puzzle15::handleSolution);
    if (_fieldSize != 3) {
        ui->bnt_solve->setVisible(false);
        ui->bnt_solve->setEnabled(false);
    }
    else {
        ui->bnt_solve->setVisible(true);
        ui->bnt_solve->setEnabled(true);
    }
}

Puzzle15::~Puzzle15()
{
    delete ui;
}

void Puzzle15::on_bnt_generation_clicked()
{
    if (ui->cbx_picture->isChecked()) pv->generateInitialPicturePuzzle();
    else pv->generateInitialPuzzle();
    pv->genInit();
    _buttons = pv->get_buttons();
}


void Puzzle15::on_bnt_get_my_result_clicked()
{
    pv->readResultsFromFile();
    pv->showBestResults();
}

void Puzzle15::on_bnt_servr_result_clicked()
{
    if (_client->isConnected()) _client->send_results(QString::number(_fieldSize) + "send_map_request");
    else {
        QString message = "Вы еще не подключились к серверу!!!";
        QMessageBox msgBox;
        msgBox.setText(message);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setFixedSize(1600, 1600);
        msgBox.move(QGuiApplication::primaryScreen()->geometry().center() - msgBox.rect().center());
        msgBox.exec();
    }
}

bool compareSecond(const QPair<QString, int> &pair1, const QPair<QString, int> &pair2)
{
    return pair1.second < pair2.second;
}

void Puzzle15::handleServerResponse(const QByteArray &data)
{
    QString response = QString::fromUtf8(data);
    if (response == "Welcome to this Server") {
        QString message = "Вы присоеденились к серверу!!!";
        QMessageBox msgBox;
        msgBox.setText(message);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.resize(600, 600);
        msgBox.exec();
    }

    QStringList lines = response.split("\n");

    QVector<QPair<QString, int>> results;

    for (const QString& line : lines) {
        int openBraceIndex = line.indexOf('{');
        int closeBraceIndex = line.indexOf('}');

        if (openBraceIndex == -1 || closeBraceIndex == -1)
            continue;

        QString nick = line.left(openBraceIndex - 3).trimmed();

        QString scoresStr = line.mid(openBraceIndex + 1, closeBraceIndex - openBraceIndex - 1);

        QStringList scoresList = scoresStr.split(", ");
        for (const QString& score : scoresList) {
            results.push_back(qMakePair(nick, score.toInt()));
        }
    }

    std::sort(results.begin(), results.end(), compareSecond);

    results = results.mid(0, 15);

    QString message = "<html><body><h2>Текущее положение на сервере:</h2><ol>";
    for (int i = 0; i < results.size(); ++i) {
        QString nick = results[i].first;
        int score = results[i].second;
        message += "<li><b>" + nick + "</b> - " + QString::number(score) + " очков</li>";
    }
    message += "</ol></body></html>";
    QMessageBox::information(nullptr, "Текущее положение на сервере", message);
}

void Puzzle15::on_bnt_goBackToMainMenu_clicked()
{
    hide();
    disconnect(_client, &Client_Part::dataReady, this, &Puzzle15::handleServerResponse);
    _mainWindow->show();
}


void Puzzle15::on_bnt_close_clicked()
{
    close();
}


void Puzzle15::on_bnt_solve_clicked()
{
    if (pv->getSolving()) {
        QVector<Tile*> temp_buttons = pv->get_buttons();
        for (Tile *button : temp_buttons) {
            button->setEnabled(true);
        }
        pv->setSolving(true);
    }
    else {
        QVector<Tile*> temp_buttons = pv->get_buttons();
        for (Tile *button : temp_buttons) {
            if (!ui->cbx_picture->isChecked()) button->setEnabled(false);
        }
        QVector<int> vec_for_check(temp_buttons.size());
        for (Tile *button : temp_buttons) {
            vec_for_check[button->get_index()] = button->get_number();
        }
        QVector<int> startState = vec_for_check;
        QVector<int> endState;
        for (int i = 1; i <= temp_buttons.size(); ++i){
            endState.push_back(i % temp_buttons.size());
        }
        Chain15 start(startState);
        Chain15 end(endState);
        QtConcurrent::run([=](){
            _solver.solvePuzzle(start, end.lastNode());
        });
        ui->bnt_generation->setEnabled(false);
        ui->bnt_goBackToMainMenu->setEnabled(false);
    }
}

void Puzzle15::handleSolution(const Chain15 &result)
{
    QVector<int> shifts;
    for (int i = 1; i < result.history_.size(); ++i) {
        QVector<int> prevBoardState = result.history_[i - 1].boardState_;
        QVector<int> currBoardState = result.history_[i].boardState_;
        shifts.push_back(_solver.get_empty_move(prevBoardState, currBoardState));
    }
    shifts.push_back(_solver.get_empty_move(result.history_[result.history_.size() - 1].boardState_, result.boardState_));
    pv->solve(shifts);
}
