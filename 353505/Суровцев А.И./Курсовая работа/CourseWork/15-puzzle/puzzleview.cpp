#include "puzzleview.h"

PuzzleView::PuzzleView(QWidget *parent)
    : QWidget(parent) {
    //
}

PuzzleView::~PuzzleView()
{
    for (Tile *tile : _buttons) {
        delete tile;
    }
    _buttons.clear();
}

void PuzzleView::SetPuzzleView(QGridLayout* grid, QGraphicsView* view, long long field_size)
{
    _grid = grid;
    _view = view;
    _field_size = field_size;
    _cnt_tiles = _field_size * _field_size;
}

void PuzzleView::setClient(Client_Part *client, QString nickname)
{
    _client = client;
    _nickname = nickname;
}

void PuzzleView::setLabel(QLabel *label)
{
    _label = label;
}

void PuzzleView::setSolving(bool isSolv)
{
    isSolving = isSolv;
}

void PuzzleView::setButtons(QPushButton *back, QPushButton *gen)
{
    _back = back;
    _gen = gen;
}

bool PuzzleView::getSolving()
{
    return currSolving;
}

void PuzzleView::generateInitialPuzzle()
{
    isPicture = false;
    QLayoutItem *child;
    while ((child = _grid->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    _buttons.clear();
    count_of_attempts = 0;
    int cellSize = std::min(_view->width(), _view->height()) / _field_size;
    _label->clear();

    for (int i = 0; i < _cnt_tiles; i++) {
        auto new_btn = new Tile(_view);
        new_btn->set_index(i);
        int tileSize = cellSize - 10;
        new_btn->setMinimumSize(tileSize, tileSize);
        _grid->addWidget(new_btn, i / _field_size, i % _field_size);
        connect(new_btn, &Tile::clicked, this, [this, new_btn]() {
            move(new_btn);
        });
        _buttons.append(new_btn);
    }
    for (int i = 0; i < _cnt_tiles; i++) {
        _buttons[i]->set_number(i);
        if (i == 0) {
            _buttons[i]->setVisible(false);
            _buttons[i]->setEnabled(false);
        }
    }
    shuffleTiles();
    _view->setLayout(_grid);
}

void PuzzleView::generateInitialPicturePuzzle()
{
    isPicture = true;
    QLayoutItem *child;
    while ((child = _grid->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    _buttons.clear();
    count_of_attempts = 0;
    int cellSize = std::min(_view->width(), _view->height()) / _field_size;

    getListOfPictures();
    int randomNumber = QRandomGenerator::global()->bounded(pictureList.size());
    QPixmap pixmap(pictureList[randomNumber]);
    QVector<QPixmap> tiles;
    QSize imageSize = pixmap.size();
    int tileSize = qMin(imageSize.width(), imageSize.height()) / _field_size;
    for (int i = 0; i < _field_size; ++i) {
        for (int j = 0; j < _field_size; ++j) {
            QRect rect(j * tileSize, i * tileSize, tileSize, tileSize);
            tiles.append(pixmap.copy(rect));
        }
    }
    int squareSize = qMin(imageSize.width(), imageSize.height());
    int startX = 0;
    int startY = 0;
    QRect squareRect(startX, startY, squareSize, squareSize);
    QPixmap squaredPixmap = pixmap.copy(squareRect);
    QPixmap scaledPixmap = squaredPixmap.scaled(_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    _label->setPixmap(scaledPixmap);

    for (int i = 0; i < _cnt_tiles; i++) {
        auto new_btn = new Tile(_view);
        new_btn->set_index(i);
        int tileSize = cellSize - (7 - _field_size);
        new_btn->setMinimumSize(tileSize, tileSize);
        _grid->addWidget(new_btn, i / _field_size, i % _field_size);
        connect(new_btn, &Tile::clicked, this, [this, new_btn]() {
            move(new_btn);
        });
        _buttons.append(new_btn);
    }
    for (int i = 0; i < _cnt_tiles; i++) {
        _buttons[i]->set_number(i);
        if (i == 0) {
            _buttons[i]->setVisible(false);
            _buttons[i]->setEnabled(false);
        }
    }

    for (int i = 1; i < _cnt_tiles; ++i) {
        _buttons[i]->set_image(tiles[i - 1]);
    }
    _buttons[0]->set_image(tiles[_cnt_tiles - 1]);
    shuffleTiles();
    _view->setLayout(_grid);
}

void PuzzleView::shuffleTiles()
{
    QVector<int> indices(_cnt_tiles);
    std::iota(indices.begin(), indices.end(), 0);
    fisherYatesShuffle(indices);
    for (int i = 0; i < _cnt_tiles; ++i) {
        int newIndex = indices[i];
        _buttons[newIndex]->set_index(i);
        int row = i / _field_size;
        int column = i % _field_size;
        _grid->addWidget(_buttons[newIndex], row, column);
    }
}

bool PuzzleView::isSolvable()
{
    QVector<short> vec_for_check(_cnt_tiles);
    for (Tile *button : _buttons) {
        vec_for_check[button->get_index()] = button->get_number();
    }

    int inv = 0;
    for (int i = 0; i < _cnt_tiles; ++i)
    {
        if (vec_for_check[i] != 0)
        {
            for (int j = 0; j < i; ++j)
            {
                if (vec_for_check[j] != 0 && vec_for_check[j] > vec_for_check[i])
                {
                    ++inv;
                }
            }
        }
    }
    if (_field_size % 2 == 0) {
        for (int i = 0; i < _cnt_tiles; ++i)
        {
            if (vec_for_check[i] == 0)
            {
                inv += 1 + i / _field_size;
            }
        }
    }
    return (inv % 2 == 0);
}

bool PuzzleView::checkSolved()
{
    for (Tile *button : _buttons) {
        if (button->get_number() == 0) {
            if (button->get_index() != (_cnt_tiles - 1)) return false;
        }
        else if (button->get_index() != (button->get_number() - 1)) return false;
    }
    return true;
}

void PuzzleView::appendAttemptsToFile(int count_of_attempts)
{
    QFile file;

    if (_field_size == 3) {
        file.setFileName("attempts3.txt");
    } else if (_field_size == 4) {
        file.setFileName("attempts4.txt");
    } else if (_field_size == 5) {
        file.setFileName("attempts5.txt");
    } else if (_field_size == 6) {
        file.setFileName("attempts6.txt");
    }

    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << count_of_attempts << "\n";
        file.close();
    } else {
        qDebug() << "Не удалось открыть/создать файл для записи!";
    }
}

void PuzzleView::readResultsFromFile()
{
    results.clear();
    QFile file;
    if (_field_size == 3) {
        file.setFileName("attempts3.txt");
    } else if (_field_size == 4) {
        file.setFileName("attempts4.txt");
    } else if (_field_size == 5) {
        file.setFileName("attempts5.txt");
    } else if (_field_size == 6) {
        file.setFileName("attempts6.txt");
    }
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            bool ok;
            long long result = line.toInt(&ok);
            if (ok) {
                results.append(result);
            } else {
                qDebug() << "Ошибка при чтении числа из файла!";
            }
        }
        file.close();
    } else {
        qDebug() << "Не удалось открыть файл для чтения!";
    }
}

void PuzzleView::showBestResults()
{
    if (results.isEmpty()) {
        QMessageBox::information(nullptr, "Мои результаты", "Нет доступных результатов.");
        return;
    }
    TimSort sorter;
    sorter.timSort(results, results.size());
    QVector<long long> bestResults;
    for (int i = 0; i < qMin(15, results.size()); ++i) {
        bestResults.append(results[i]);
    }
    QString message = "<html><body><h2>Лучшие результаты:</h2><ul>";
    for (int i = 0; i < bestResults.size(); ++i) {
        message += "<li>" + QString::number(i + 1) + ") " + QString::number(bestResults[i]) + "</li>";
    }
    message += "</ul></body></html>";
    QMessageBox::information(nullptr, "Мои результаты", message);
}

void PuzzleView::getListOfPictures()
{
    QDir directory(":/pictures");
    QStringList files = directory.entryList(QDir::Files);

    for (const QString &file : files) {
        QString path = ":/pictures/" + file;
        pictureList.append(path);
    }
}

QVector<Tile *> PuzzleView::get_buttons()
{
    return _buttons;
}

void PuzzleView::genInit()
{
    shuffleTiles();
    while (!isSolvable()) {
        shuffleTiles();
    }
}

void PuzzleView::removeWidgetAt(int row, int column)
{
    QWidget *widgetToRemove = _grid->itemAtPosition(row, column)->widget();
    if (widgetToRemove) {
        _grid->removeWidget(widgetToRemove);
        delete widgetToRemove;
    }
}

long long PuzzleView::get_count_of_attempts()
{
    return count_of_attempts;
}

void PuzzleView::solve(QVector<int> shifts)
{
    currSolving = true;
    Tile *null_tile = nullptr;
    Tile *shift_tile = nullptr;
    for (Tile *button : _buttons) {
        if (button->get_number() == 0) {
            null_tile = button;
        }
    }
    int i = 0;
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, [=]() mutable {
        if (isSolving) {
            currSolving = false;
            isSolving = false;
            _back->setEnabled(true);
            _gen->setEnabled(true);
            timer->stop();
            delete timer;
        }
        else if (i == shifts.size()) {
            isSolving = false;
            currSolving = false;
            _back->setEnabled(true);
            _gen->setEnabled(true);
            timer->stop();
            for (Tile *button : _buttons) {
                button->setEnabled(true);
            }
            QMessageBox msgBox;
            const QString message = "<html><body>"
                                    "<h1>Головоломка собрана!</h1>"
                                    "<p>Количество ходов: </p>" + QString::number(count_of_attempts) +
                                    "<p>Запускаем новую игру!!!</p>"
                                    "</body></html>";
            msgBox.setText(message);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.resize(600, 600);
            msgBox.adjustSize();
            QAbstractButton *okButton = msgBox.addButton(tr("OK"), QMessageBox::ActionRole);
            QObject::connect(okButton, &QAbstractButton::clicked, [=]() {
                if (isPicture) generateInitialPicturePuzzle();
                else generateInitialPuzzle();
                genInit();
            });
            QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
            int x = (screenGeometry.width() - msgBox.width()) / 2;
            int y = (screenGeometry.height() - msgBox.height()) / 2;
            msgBox.move(x, y);
            msgBox.exec();
            delete timer;
        }
        else {
            int sdvig;
            if (shifts[i] == 2) sdvig = -1;
            else if (shifts[i] == 3) sdvig = 1;
            else if (shifts[i] == 0) sdvig = -_field_size;
            else sdvig = _field_size;
            int tile_ind = null_tile->get_index() + sdvig;
            for (Tile *button : _buttons) {
                if (button->get_index() == tile_ind) shift_tile = button;
            }
            int column = shift_tile->get_index() % _field_size;
            int row = shift_tile->get_index() / _field_size;
            if (sdvig == -1) {
                moveTile(shift_tile, row, column + 1);
                moveTile(null_tile, row, column);
                null_tile->set_index(tile_ind);
                shift_tile->set_index(tile_ind + 1);
                count_of_attempts++;
            }
            else if (sdvig == 1) {
                moveTile(shift_tile, row, column - 1);
                moveTile(null_tile, row, column);
                null_tile->set_index(tile_ind);
                shift_tile->set_index(tile_ind - 1);
                count_of_attempts++;
            }
            else if (sdvig == -_field_size) {
                moveTile(shift_tile, row + 1, column);
                moveTile(null_tile, row, column);
                null_tile->set_index(tile_ind);
                shift_tile->set_index(tile_ind + _field_size);
                count_of_attempts++;
            }
            else {
                moveTile(shift_tile, row - 1, column);
                moveTile(null_tile, row, column);
                null_tile->set_index(tile_ind);
                shift_tile->set_index(tile_ind - _field_size);
                count_of_attempts++;
            }
            ++i;
        }
    });
    timer->start(500);
}

void PuzzleView::moveTile(Tile *tile, int row, int column)
{
    QPropertyAnimation *animation = new QPropertyAnimation(tile, "geometry", nullptr);
    int startX = _grid->itemAtPosition(tile->get_index() / _field_size, tile->get_index() % _field_size)->geometry().x();
    int startY = _grid->itemAtPosition(tile->get_index() / _field_size, tile->get_index() % _field_size)->geometry().y();

    QRect endRect = _grid->cellRect(row, column);

    int endX = endRect.x();
    int endY = endRect.y();

    animation->setDuration(150);
    animation->setStartValue(QRect(startX, startY, tile->width(), tile->height()));
    animation->setEndValue(QRect(endX, endY, tile->width(), tile->height()));
    connect(animation, &QPropertyAnimation::finished, [=]() {
        _grid->addWidget(tile, row, column);
        animation->deleteLater();
    });
    animation->start();
}

bool PuzzleView::isMovebleLeft(int index)
{
    if (index % _field_size != 0) {
        int find_index = index - 1;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                if (button->get_number() == 0) {
                    return true;
                }
                return false;
            }
        }
    }
    return false;
}

bool PuzzleView::isMovebleRight(int index)
{
    if (index % _field_size != _field_size - 1) {
        int find_index = index + 1;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                if (button->get_number() == 0) {
                    return true;
                }
                return false;
            }
        }
    }
    return false;
}

bool PuzzleView::isMovebleUp(int index)
{
    if (index > _field_size - 1) {
        int find_index = index - _field_size;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                if (button->get_number() == 0) {
                    return true;
                }
                return false;
            }
        }
    }
    return false;
}

bool PuzzleView::isMovebleDown(int index)
{
    if (index < _cnt_tiles - _field_size) {
        int find_index = index + _field_size;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                if (button->get_number() == 0) {
                    return true;
                }
                return false;
            }
        }
    }
    return false;
}

void PuzzleView::move(Tile *tile)
{
    int tile_index = tile->get_index();
    Tile *null_tile;
    if (isMovebleLeft(tile_index)) {
        int find_index = tile_index - 1;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                null_tile = button;
            }
        }
        int column = tile_index % _field_size;
        int row = tile_index / _field_size;
        moveTile(tile, row, column - 1);
        moveTile(null_tile, row, column);
        null_tile->set_index(tile_index);
        tile->set_index(tile_index - 1);
        count_of_attempts++;
    }
    else if (isMovebleRight(tile_index)) {
        int find_index = tile_index + 1;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                null_tile = button;
            }
        }
        int column = tile_index % _field_size;
        int row = tile_index / _field_size;
        moveTile(tile, row, column + 1);
        moveTile(null_tile, row, column);
        null_tile->set_index(tile_index);
        tile->set_index(tile_index + 1);
        count_of_attempts++;
    }
    else if (isMovebleUp(tile_index)) {
        int find_index = tile_index - _field_size;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                null_tile = button;
            }
        }
        int column = tile_index % _field_size;
        int row = tile_index / _field_size;
        moveTile(tile, row - 1, column);
        moveTile(null_tile, row, column);
        null_tile->set_index(tile_index);
        tile->set_index(tile_index - _field_size);
        count_of_attempts++;
    }
    else if (isMovebleDown(tile_index)) {
        int find_index = tile_index + _field_size;
        for (Tile *button : _buttons) {
            if (button->get_index() == find_index) {
                null_tile = button;
            }
        }
        int column = tile_index % _field_size;
        int row = tile_index / _field_size;
        moveTile(tile, row + 1, column);
        moveTile(null_tile, row, column);
        null_tile->set_index(tile_index);
        tile->set_index(tile_index + _field_size);
        count_of_attempts++;
    }
    if (checkSolved()) {
        appendAttemptsToFile(count_of_attempts);
        if (_client != nullptr && _client->isConnected()) {
            QString message = QString::number(_field_size) + _nickname + " - " + QString::number(count_of_attempts);
            _client->send_results(message);
        }
        QMessageBox msgBox;
        const QString message = "<html><body>"
                                "<h1>Головоломка собрана!</h1>"
                                "<p>Количество ходов: </p>" + QString::number(count_of_attempts) +
                                "<p>Запускаем новую игру!!!</p>"
                                "</body></html>";
        msgBox.setText(message);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.resize(600, 600);
        msgBox.adjustSize();
        QAbstractButton *okButton = msgBox.addButton(tr("OK"), QMessageBox::ActionRole);
        QObject::connect(okButton, &QAbstractButton::clicked, [=]() {
            if (isPicture) generateInitialPicturePuzzle();
            else generateInitialPuzzle();
            genInit();
        });
        QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
        int x = (screenGeometry.width() - msgBox.width()) / 2;
        int y = (screenGeometry.height() - msgBox.height()) / 2;
        msgBox.move(x, y);
        msgBox.exec();
    }
}

void PuzzleView::fisherYatesShuffle(QVector<int> &array)
{
    int n = array.size();
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}
