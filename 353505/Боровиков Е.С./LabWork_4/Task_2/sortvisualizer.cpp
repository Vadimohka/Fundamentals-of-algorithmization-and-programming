#include "sortvisualizer.h"
#include "ui_sortvisualizer.h"

SortVisualizer::SortVisualizer(QWidget *parent)
    : QWidget(parent),
    timer(new QTimer(this)), ui(new Ui::SortVisualizer)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing, false);
    connect(timer, SIGNAL(timeout()), SLOT(slotMakeSortGreen()));
}

SortVisualizer::~SortVisualizer() {
    delete ui;
}

void SortVisualizer::InitByArray(int *array, int size) {
    if (array == nullptr || size < 1) { return; }

    _array = array;
    _min = *array;
    _max = *array;
    _size = size;

    int temp = 0;
    _sortingArray.clear();
    for (int i = 0; i < size; ++i) {
        temp = array[i];
        _sortingArray.push_back(temp);
        if (temp > _max) { _max = temp; }
        else if (temp < _min) {_min = temp; }
    }

    if (_min < 0) {
        _minElementTab = qAbs(static_cast<qreal>(_min) / (_max - _min == 0 ? _min : (_max - _min)) * _verMaxSize);
    } else { _minElementTab = 0; }

    _verMaxSize = ui->graphicsView->height() - VER_TAB_CNT * VER_TAB;
    _horWidth = ui->graphicsView->width() - 2 * HOR_TAB;

    timer->stop();
    timer->setInterval(qMax(MIN_GREEN_TIMER, MAX_GREEN_TIMER / _size));

    visualizeArray();
}

void SortVisualizer::visualizeArray() {
    if (_scene != nullptr) { delete _scene; }

    _horSize = qMax(MIN_HOR_SIZE, static_cast<int>(static_cast<qreal>(_horWidth - _size) / _size));
    _scene = new QGraphicsScene(0, 0, 2 * HOR_TAB + _size * (_horSize + 1), VER_TAB * 2 + _verMaxSize, this);
    //_scene->

    _visualArray.clear();
    _visualArray.resize(_size);

    for (int i = 0; i < _size; ++i) {
        _visualArray[i] = new QGraphicsRectItem(HOR_TAB + i * (_horSize + 1),
                                                VER_TAB + _minElementTab + (_verMaxSize - calcVerSize(i)),
                                                _horSize, calcVerSize(i));
        if ((i ) % 2 == 0) { // Если i+1 делится на 2
            _visualArray[i]->setBrush(QBrush(Qt::red)); // Установить красный цвет для кисти
        }else{
            _visualArray[i]->setBrush(QBrush(Qt::blue)); // Установить красный цвет для кисти
        }
        _scene->addItem(_visualArray[i]);
    }
    ui->graphicsView->setScene(_scene);
}

bool SortVisualizer::checkIfOutOfRange(int* firstElement, int* secondElement) {
    return firstElement < _array ||
           secondElement < _array  ||
           firstElement > _array + _size - 1 ||
           secondElement > _array + _size - 1;
}

int SortVisualizer::calcVerSize(int index) {
    if (_max - _min != 0) {
        return static_cast<int>(static_cast<qreal>(_sortingArray[index]) / (_max - _min) * _verMaxSize);
    } else if (_max != 0) {
        return _verMaxSize * _max / qAbs(_max);
    } else if (_min != 0) {
        return _verMaxSize * _min / qAbs(_min);
    } else {
        return _verMaxSize;
    }
}

void SortVisualizer::slotSetComparison(int *firstElement, int *secondElement) {
    if (checkIfOutOfRange(firstElement, secondElement)) { return; }

    // Установка кисти и обводки для первого элемента
    QColor firstColor(Qt::blue); // Цвет кисти и обводки для первого элемента - синий
    _visualArray[firstElement - _array]->setBrush(QBrush(firstColor));
    _visualArray[firstElement - _array]->setPen(QPen(firstColor));

    // Установка кисти и обводки для второго элемента
    QColor secondColor(Qt::green); // Цвет кисти и обводки для второго элемента - зеленый
    _visualArray[secondElement - _array]->setBrush(QBrush(secondColor));
    _visualArray[secondElement - _array]->setPen(QPen(secondColor));

    _scene->update();
}

void SortVisualizer::slotEndComparison(int *firstElement, int *secondElement) {
    if (checkIfOutOfRange(firstElement, secondElement)) { return; }

    // Установка кисти для первого элемента dddddssdsdsds
    _visualArray[firstElement - _array]->setBrush(QBrush(Qt::red)); // Красный цвет для кисти
    _visualArray[firstElement - _array]->setPen(QPen(Qt::blue, 2)); // Синий цвет для обводки с толщиной линии 2

    // Установка кисти для второго элемента
    _visualArray[secondElement - _array]->setBrush(QBrush(Qt::green)); // Зеленый цвет для кисти
    _visualArray[secondElement - _array]->setPen(QPen(Qt::yellow, 1, Qt::DashDotLine)); // Желтый цвет для обводки с толщиной линии 1 и пунктирным стилем

    _scene->update();
}

void SortVisualizer::slotSwapElements(int *firstElement, int *secondElement) {
    if (checkIfOutOfRange(firstElement, secondElement)) { return; }

    int fPos = firstElement - _array;
    int sPos = secondElement - _array;
    qSwap(_sortingArray[fPos], _sortingArray[sPos]);
    int fvSize = calcVerSize(fPos);
    int svSize = calcVerSize(sPos);

    _visualArray[fPos]->setRect(HOR_TAB + fPos * (_horSize + 1),
                                VER_TAB + _minElementTab + (_verMaxSize - fvSize),
                                _horSize, fvSize);
    _visualArray[sPos]->setRect(HOR_TAB + sPos * (_horSize + 1),
                                VER_TAB + _minElementTab + (_verMaxSize - svSize),
                                _horSize, svSize);
    _scene->update();
}

void SortVisualizer::slotChangeElement(int *ptr, int value)
{
    if (checkIfOutOfRange(ptr, ptr)) { return; }

    int pos = ptr - _array;
    _sortingArray[pos] = value;
    int vSize = calcVerSize(pos);
    _visualArray[pos]->setRect(HOR_TAB + pos * (_horSize + 1),
                               VER_TAB + _minElementTab + (_verMaxSize - vSize),
                               _horSize, vSize);
    _scene->update();
}

void SortVisualizer::slotEndSorting() {
    timer->start();
    _endIndex = 0;
}

void SortVisualizer::slotMakeSortGreen() {
    if (_endIndex >= _visualArray.size()) {
        timer->stop();
        return;
    }

    _visualArray[_endIndex]->setBrush(QBrush(Qt::green));
    _visualArray[_endIndex++]->setPen(QPen(Qt::green));
    _scene->update();
}
