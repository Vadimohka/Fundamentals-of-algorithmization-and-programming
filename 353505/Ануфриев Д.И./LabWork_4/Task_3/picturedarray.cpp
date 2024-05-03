#include "picturedarray.h"
#include "qgraphicsview.h"

PicturedArray::PicturedArray()
{
    this->graphicsScene = nullptr;
    graphicsView = nullptr;
}

void PicturedArray::updateArray()
{
    if(!array.isEmpty())
    {
        for(QGraphicsItem* item : graphicsScene->items())
        {
            graphicsScene->removeItem(item);
        }

        indexesOfArray.clear();

        for(int i = 0; i < array.size(); i++)
        {
            IndexOfArray* newIndex = new IndexOfArray(i * graphicsView->width() / array.size(), (graphicsScene->height() / 2 - array[i].first * 3),
                                                      graphicsView->width() / array.size(), array[i].first * 3, array[i].second);

            indexesOfArray.push_back(newIndex);

            graphicsScene->addItem(indexesOfArray[i]);

            graphicsScene->update();
        }
    }
}

void PicturedArray::push_back(int num, QColor color)
{
    array.push_back(std::make_pair(num, color));
    aux.push_back(std::make_pair(num, color));
    updateArray();
}

void PicturedArray::setScene(QGraphicsScene *scene)
{
    this->graphicsScene = scene;

    graphicsView = graphicsScene->views().first();
}

int PicturedArray::size()
{
    return array.size();
}

void PicturedArray::swap(int first, int second)
{
    std::pair<int, QColor> temp = array[first];

    array[first] = array[second];
    array[second] = temp;
}

void PicturedArray::swapCopy(int first, int second)
{
    std::pair<int, QColor> temp = copyOfArray[first];

    copyOfArray[first] = copyOfArray[second];
    copyOfArray[second] = temp;
}

void PicturedArray::clear()
{
    indexesOfArray.clear();
    array.clear();
    aux.clear();
}

void PicturedArray::resetColors()
{
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i].second != QColor(0, 179, 134, array[i].first + 130))
        array[i].second = QColor(0, 179, 134, array[i].first + 130);
    }
    updateArray();
}

QVector<std::pair<double, QColor>>& PicturedArray::getArray()
{
    return array;
}

QVector<std::pair<double, QColor> > &PicturedArray::getAux()
{
    return aux;
}

void PicturedArray::lookingForMedians()
{
    int index;
    for(int i = 0; i + 2 < array.size(); i += 3)
    {
        QuickSort(i, i + 2);

        array[i + 1].second = QColor(205,92,92);
        updateArray();

        QEventLoop loop;
        QTimer::singleShot(75, &loop, &QEventLoop::quit);
        loop.exec();

        index = i;
    }

    index += 3;
    int count = array.size() - index, sum = 0;

    QuickSort(index, index + count - 1);

    for(int i = index; i < array.size(); i++)
    {
        sum += array[i].first;
    }

    double element = sum / (count * 1.0);
    bool isFinded = false;

    for(int i = index; i < array.size() && !isFinded; i++)
    {
        if(array[i].first == element)
        {
            array[i].second = QColor(205,92,92);
            updateArray();

            QEventLoop loop;
            QTimer::singleShot(1000, &loop, &QEventLoop::quit);
            loop.exec();

            isFinded = true;
        }
    }

    if(index < array.size() && !isFinded)
    {
        array[array.size() - 1].second = QColor(205,92,92);
        updateArray();

        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec();
    }

    aux.clear();
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i].second == QColor(205,92,92))
        {
            aux.push_back(array[i]);
        }
    }

    array.clear();
    array.assign(aux.begin(), aux.end());

    updateArray();
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, &QEventLoop::quit);
    loop.exec();

    resetColors();
}

void PicturedArray::QuickSort(int left, int right)
{
    int l = left, r = right;
    int piv = array[(l + r) / 2].first; // Опорным элементом для примера возьмём средний

    while (l <= r)
    {
        while (array[l].first < piv)
            l++;
        while (array[r].first > piv)
            r--;
        if (l <= r)
        {
            // array[l].second = QColor(255,127,80);
            // array[r].second = QColor(255,127,80);
            // updateArray();

            swap (l++, r--);
            updateArray();
            QEventLoop loop;
            QTimer::singleShot(30, &loop, &QEventLoop::quit);
            loop.exec();

            // resetColors();
        }
    }
    if (left < r)
        QuickSort(left, r);
    if (right > l)
        QuickSort(l, right);
}

void PicturedArray::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF PicturedArray::boundingRect() const
{
    return QRectF(0,0,0,0);
}
