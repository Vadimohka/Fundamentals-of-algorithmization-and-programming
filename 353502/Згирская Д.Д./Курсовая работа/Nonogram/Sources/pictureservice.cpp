//
// Created by zgdarya on 4/27/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PictureService.h" resolved

#include "../Headers/pictureservice.h"
#include "../Ui/ui_pictureservice.h"


PictureService::PictureService(QWidget *parent) :
        QWidget(parent), ui(new Ui::PictureService) {
    ui->setupUi(this);

    //размер экрана
    this->setGeometry(0, 0, parent->width(), parent->height());

    //обнуление данных
    _coloredCells = 0;
    _filledCells = 0;
    _mistakes = 0;
    _seconds = 0;

    //инициализация очков профиля
    _scoreFile = "/home/zgdarya/QTWORKS/Nonogram/Score.txt";
    if (_scoreFile != nullptr && !input.is_open()) {
        input.open(_scoreFile.toUtf8(), std::ofstream::in);
    }
    if (input.is_open()) {
        std::string profileScore;
        std::getline(input, profileScore);
        _profileScore = std::stoi(profileScore);
        input.close();
    }

    //запуск таймера
    _timer = new QTimer(this);
    _timer->setInterval(1000);
    ui->timer->setText(QString("00 : 00"));
    ui->timer->setReadOnly(true);
    ui->mistakes->setText(QString("Mistakes: 0"));
    ui->mistakes->setReadOnly(true);
    connect(_timer, SIGNAL(timeout()), this, SLOT(showTime()));
    _timer->start();

    //нажатие на клетку таблицы
    connect(ui->nonogram, SIGNAL(itemClicked(int, int)),
            ui->nonogram, SLOT(on_nonogram_cellClicked(int, int)));

    //уведомление Game Over!
    _gameOver = new QWidget(this);
    _gameOver->hide();
    _gameOver->setGeometry((this->width() - 400) / 2, (this->height() - 300) / 2, 400, 300);
    _gameOver->setStyleSheet("background-color:lightgray;");
    ok_button = new QPushButton(_gameOver);
    ok_button->setGeometry((_gameOver->width() - 100) / 2, (_gameOver->height()) / 2 + 50, 100, 50);
    ok_button->setText("Ok");
    QLabel *gameOverLabel = new QLabel(_gameOver);
    gameOverLabel->setText("Game over!");
    QFont font = gameOverLabel->font();
    font.setPointSize(36);
    gameOverLabel->setFont(font);
    gameOverLabel->setGeometry((_gameOver->width() - 250) / 2, (_gameOver->height() - 75) / 2, 250, 40);

    connect(ok_button, SIGNAL(clicked(bool)), this, SLOT(on_ok_button_clicked()));

    //уведомление Nonogram Solved!
    _nonogramSolved = new QWidget(this);
    _nonogramSolved->hide();
    _nonogramSolved->setGeometry((this->width() - 400) / 2, (this->height() - 300) / 2, 400, 300);
    _nonogramSolved->setStyleSheet("background-color:lightgray;");
    yep_button = new QPushButton(_nonogramSolved);
    yep_button->setGeometry((_nonogramSolved->width() - 100) / 2, (_nonogramSolved->height()) / 2 + 50, 100, 50);
    yep_button->setText("Yep!");
    QLabel *nonogramSolvedLabel = new QLabel(_nonogramSolved);
    nonogramSolvedLabel->setText("Nonogram Solved!");
    font = nonogramSolvedLabel->font();
    font.setPointSize(30);
    nonogramSolvedLabel->setFont(font);
    nonogramSolvedLabel->setGeometry((_nonogramSolved->width() - 340) / 2, (_nonogramSolved->height() - 200) / 2, 340,
                                     50);

    connect(yep_button, SIGNAL(clicked(bool)), this, SLOT(on_ok_button_clicked()));

    //результат проверки на единственность решения нонограммы
    _singleSolution_lineEdit = new QLineEdit(this);
    font = _singleSolution_lineEdit->font();
    font.setPointSize(24);
    _singleSolution_lineEdit->setFont(font);
    _singleSolution_lineEdit->setReadOnly(true);

    //
    _gameComplexity_lineEdit = new QLineEdit(this);
    font = _gameComplexity_lineEdit->font();
    font.setPointSize(24);
    _gameComplexity_lineEdit->setFont(font);
    _gameComplexity_lineEdit->setReadOnly(true);
}

PictureService::~PictureService() {
    delete ui;
}

void PictureService::createNonogram(QImage image) {
    _image = image;
    _size = image.size();

    if (_size != QSize(0, 0)) {

        //создание таблицы
        ui->nonogram->setGeometry((this->width() - ui->nonogram->width()) / 2,
                                  (this->height() - ui->nonogram->height()) / 2, ui->nonogram->width(),
                                  ui->nonogram->height());
        ui->nonogram->setRowCount(_size.height() + 1);
        ui->nonogram->setColumnCount(_size.width() + 1);
        ui->nonogram->setEditTriggers(QAbstractItemView::NoEditTriggers);

        int delta = (ui->nonogram->height() - 100) / _size.height();

        for (int i = 1; i < _size.width() + 1; ++i) {
            ui->nonogram->setRowHeight(i, delta);
            ui->nonogram->setColumnWidth(i, delta);
        }
        ui->nonogram->setRowHeight(0, ui->nonogram->height() - _size.height() * delta);
        ui->nonogram->setColumnWidth(0, ui->nonogram->width() - _size.width() * delta);

        //заполнение массивов закрашенных клеток
        for (int i = 0; i < _size.height(); ++i) {
            for (int j = 0; j < _size.width(); ++j) {
                if (image.pixel(j, i) == WHITE_NUMBER) {
                    _matrix40[i][j] = 0;
                } else {
                    _matrix40[i][j] = 1;
                    ++_coloredCells;
                    _coloredCellsRow[i] += 1;
                    _coloredCellsColumns[j] += 1;
                }
            }
        }

        //заполнение нулевых строк и столбцов (условия)
        QString numbers;
        for (int i = 0, column = 0; i < _size.height(); ++i) {
            for (int j = 0; j < _size.width(); ++j) {
                if (_matrix40[i][j]) { column++; }
                else if (column != 0) {
                    numbers += QString::number(column) + QString(' ');
                    column = 0;
                }
            }
            if (column != 0) {
                numbers += QString::number(column) + QString(' ');
                column = 0;
            }
            ui->nonogram->setItem(i + 1, 0, new QTableWidgetItem(numbers));
            numbers.clear();
        }

        //заполнение нулевых строк (условия)
        for (int j = 0, row = 0; j < _size.width(); ++j) {
            for (int i = 0; i < _size.height(); ++i) {
                if (_matrix40[i][j]) { ++row; }
                else if (row != 0) {
                    numbers += QString::number(row) + QString('\n');
                    row = 0;
                }
            }
            if (row != 0) {
                numbers += QString::number(row) + QString('\n');
                row = 0;
            }
            ui->nonogram->setItem(0, j + 1, new QTableWidgetItem(numbers));
            numbers.clear();
        }

        //заполнение клеток айтемами
        for (int j = 1; j < _size.width() + 1; ++j) {
            for (int i = 1; i < _size.height() + 1; ++i) {
                ui->nonogram->setItem(i, j, new QTableWidgetItem);
            }
        }

        //расстановка крестиков в строках и столбцах без закрашенных клеток
        for (int i = 1; i < _size.height() + 1; ++i) {
            if (ui->nonogram->item(i, 0)->text() == "") {
                for (int j = 1; j < _size.width() + 1; ++j) {
                    ui->nonogram->setItem(i, j, new QTableWidgetItem(QString("❌")));
                    ui->nonogram->item(i, j)->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
        for (int j = 1; j < _size.width() + 1; ++j) {
            if (ui->nonogram->item(0, j)->text() == "") {
                for (int i = 1; i < _size.width() + 1; ++i) {
                    ui->nonogram->setItem(i, j, new QTableWidgetItem(QString("❌")));
                    ui->nonogram->item(i, j)->setTextAlignment(Qt::AlignCenter);
                }
            }
        }

        //подсеч границ картинки для анализа единственности решения
        int upBoard = 0;
        int downBoard = 0;
        int leftBoard = 0;
        int rightBoard = 0;
        for (int i = 1; i <= _size.height(); ++i) {
            if (ui->nonogram->item(i, 0)->text() != "") {
                upBoard = i;
                break;
            }
        }
        for (int i = _size.height(); i >= 1; --i) {
            if (ui->nonogram->item(i, 0)->text() != "") {
                downBoard = i;
                break;
            }
        }
        for (int j = 1; j <= _size.width(); ++j) {
            if (ui->nonogram->item(0, j)->text() != "") {
                leftBoard = j;
                break;
            }
        }
        for (int j = _size.width(); j >= 1; --j) {
            if (ui->nonogram->item(0, j)->text() != "") {
                rightBoard = j;
                break;
            }
        }

        //анализ единственности решения
        std::vector<std::bitset<MAX_SIZE>> nonogram = imageToNonogram(image, upBoard, downBoard, leftBoard, rightBoard);

        if (isUniqueSolution(nonogram)) {
            _singleSolution_lineEdit->setText("Nonogram has single solution!");
            _singleSolution_lineEdit->setGeometry((this->width() - 440) / 2, 50, 440, 50);
            qDebug() << "Single";
        }
        else {
            _singleSolution_lineEdit->setText("Nonogram has multiple solutions!");
            _singleSolution_lineEdit->setGeometry((this->width() - 500) / 2, 50, 500, 50);
            qDebug() << "Multiple";
        }

        calculateGameComplexity();
        _gameComplexity_lineEdit->setText(QString::number(_gameComplexity));
        _gameComplexity_lineEdit->setGeometry(this->_singleSolution_lineEdit->width(), 50, 40, 50);
        _gameComplexity_lineEdit->isReadOnly();
    }
}

void PictureService::on_nonogram_cellClicked(int row, int column) {
    if (row != 0 && column != 0) {
        if (_filledCells < _coloredCells) {
            if (_matrix40[row - 1][column - 1] == 1) {
                if (ui->nonogram->item(row, column)->background() != Qt::black) {
                    ui->nonogram->item(row, column)->setBackground(Qt::black);
                    ++_filledCells;
                    ++_filledCellsRow[row - 1];
                    ++_filledCellsColumn[column - 1];
                }
            } else if (ui->nonogram->item(row, column)->text() != "❌") {
                ui->nonogram->setItem(row, column, new QTableWidgetItem(QString("❌")));
                ui->nonogram->item(row, column)->setTextAlignment(Qt::AlignCenter);
                ++_mistakes;
                ui->mistakes->setText("Mistakes: " + QString::number(_mistakes));
                if (_mistakes == 5) {
                    _gameOver->show();
                }
            }
        }
        if (_coloredCellsRow[row - 1] == _filledCellsRow[row - 1]) {
            for (int j = 1; j <= _size.height(); ++j) {
                if (ui->nonogram->item(row, j)->background() != Qt::black) {
                    ui->nonogram->setItem(row, j, new QTableWidgetItem(QString("❌")));
                    ui->nonogram->item(row, j)->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
        if (_filledCellsColumn[column - 1] == _coloredCellsColumns[column - 1]) {
            for (int i = 1; i <= _size.width(); ++i) {
                if (ui->nonogram->item(i, column)->background() != Qt::black) {
                    ui->nonogram->setItem(i, column, new QTableWidgetItem(QString("❌")));
                    ui->nonogram->item(i, column)->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
        if (_filledCells == _coloredCells) {
            disconnect(_timer, SIGNAL(timeout()), this, SLOT(showTime()));
            calculateGameScore();
            calculateProfileScore();

            QColor pixelColor;
            for (int i = 0; i < _size.height(); ++i) {
                for (int j = 0; j < _size.width(); ++j) {
                    ui->nonogram->setItem(i + 1, j + 1, new QTableWidgetItem);
                    pixelColor = _image.pixelColor(j, i);
                    ui->nonogram->item(i + 1, j + 1)->setBackground(pixelColor);
                }
            }
            _successMessageTimer = new QTimer(this);
            _successMessageTimer->setInterval(TIMER_INTERVAL);
            connect(_successMessageTimer, SIGNAL(timeout()), this, SLOT(showSuccessMessage()));
            _successMessageTimer->start();
        }
    }
}

void PictureService::showTime() {
    _seconds += 1;
    int minutes = _seconds / 60;
    int seconds = _seconds % 60;
    QString minutesString, secondsString;
    if (minutes < 10) {
        minutesString = '0' + QString::number(minutes);
    } else {
        minutesString = QString::number(minutes);
    }
    if (seconds < 10) {
        secondsString = '0' + QString::number(seconds);
    } else {
        secondsString = QString::number(seconds);
    }
    QString timeFromStart = minutesString + " : " + secondsString;
    ui->timer->setText(timeFromStart);
}

void PictureService::on_ok_button_clicked() {
    _gameOver->hide();
    _nonogramSolved->hide();
    this->hide();
}

void PictureService::calculateGameScore() {
    calculateGameComplexity();
    _gameScore = (1 - _mistakes * 0.2) * (300 / _seconds + 10) *
                 (sqrt(powl(_size.width(), 2) + powl(_size.height(), 2)) * 10) * (1 + _gameComplexity / 100);
}

void PictureService::calculateProfileScore() {
    _profileScore += _gameScore;

    output.open(_scoreFile.toUtf8(), std::ofstream::out | std::ofstream::trunc);
    output.close();

    output.open(_scoreFile.toUtf8(), std::ofstream::app);
    if (output.is_open()) {
        output << std::to_string(_profileScore);
        output.close();
    }
}

void PictureService::showSuccessMessage() {
    QLabel *gameScoreLabel = new QLabel(_nonogramSolved);
    gameScoreLabel->setText("Game Score: " + QString::number(_gameScore));
    QFont font = gameScoreLabel->font();
    font.setPointSize(24);
    gameScoreLabel->setFont(font);
    gameScoreLabel->setGeometry((_nonogramSolved->width() - 300) / 2, (_nonogramSolved->height() - 50) / 2, 300, 50);
    _nonogramSolved->show();
    _successMessageTimer->stop();
}

void PictureService::calculateGameComplexity() {
    double coloredCellsCount = 0;
    double uncoloredCells = 0;
    for (int i = 0; i < _size.height(); ++i) {
        for (int j = 0; j < _size.width(); ++j)
            if (_matrix40[i][j] == 1)
                coloredCellsCount += 1;
        else if (ui->nonogram->item(0, j + 1)->text() != "" && ui->nonogram->item(i + 1, 0)->text() != "")
            uncoloredCells += 1;
    }
    _gameComplexity = 1 - coloredCellsCount / uncoloredCells;
    if (_gameComplexity <= 0.2)
        _gameComplexity = 1;
    else if (_gameComplexity > 0.2 && _gameComplexity <= 0.4)
        _gameComplexity = 2;
    else if (_gameComplexity > 0.4 && _gameComplexity <= 0.6)
        _gameComplexity = 3;
    else if (_gameComplexity > 0.6 && _gameComplexity <= 0.8)
        _gameComplexity = 4;
    else
        _gameComplexity = 5;
}

std::vector<std::bitset<MAX_SIZE>>
PictureService::imageToNonogram(const QImage &image, int upBoard, int downBoard, int leftBoard, int rightBoard) {
    --upBoard, --downBoard, --leftBoard, --rightBoard;
    std::vector<std::bitset<MAX_SIZE>> nonogram;
    for (int i = upBoard; i <= downBoard; ++i) {
        std::bitset<MAX_SIZE> row;
        for (int j = leftBoard; j <= rightBoard; ++j) {
            QColor pixelColor = image.pixelColor(j, i);
            if (pixelColor != Qt::white) {
                row.set(j);
            }
        }
        nonogram.push_back(row);
    }
    return nonogram;
}

std::vector<std::bitset<MAX_SIZE>> PictureService::countGroups(const std::bitset<MAX_SIZE> &row) {
    std::vector<std::bitset<MAX_SIZE>> groups;
    std::bitset<MAX_SIZE> currentGroup;
    for (int i = 0; i < row.size(); ++i) {
        if (row.test(i)) {
            currentGroup.set(i);
        } else {
            if (currentGroup.any()) {
                groups.push_back(currentGroup);
                currentGroup.reset();
            }
        }
    }
    if (currentGroup.any()) {
        groups.push_back(currentGroup);
    }
    return groups;
}

bool PictureService::isUniqueSolution(const std::vector<std::bitset<MAX_SIZE>> &nonogram) {
    std::unordered_map<std::bitset<MAX_SIZE>, int> rowCounts, columnCounts;

    // Подсчет групп символов для каждой строки
    for (int i = 0; i < nonogram.size(); ++i) {
        std::vector<std::bitset<MAX_SIZE>> groups = countGroups(nonogram[i]);
        for (auto& group : groups) {
            rowCounts[group]++;
        }
    }

    // Подсчет групп символов для каждого столбца
    for (int j = 0; j < nonogram[0].size(); ++j) {
        std::bitset<MAX_SIZE> col;
        for (int i = 0; i < nonogram.size(); ++i) {
            col.set(i, nonogram[i].test(j));
        }
        std::vector<std::bitset<MAX_SIZE>> groups = countGroups(col);
        for (auto& group : groups) {
            columnCounts[group]++;
        }
    }

    // Проверка единственности решения
    for (auto& p : rowCounts) {
        if (p.second > 1) {
            return false;
        }
    }
    for (auto& p : columnCounts) {
        if (p.second > 1) {
            return false;
        }
    }

    return true;
}



