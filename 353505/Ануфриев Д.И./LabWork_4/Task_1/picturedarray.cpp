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

QVector<std::pair<int, QColor>>& PicturedArray::getArray()
{
    return array;
}

QVector<std::pair<int, QColor>>& PicturedArray::getAux()
{
    return aux;
}


void PicturedArray::Merge(int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    // пока есть элементы в левом и правом рядах
    while (i <= mid && j <= high)
    {
        if (array[i].first <= array[j].first) {
            aux[k++] = array[i++];
        }
        else {
            aux[k++] = array[j++];
        }
    }

    // копируем оставшиеся элементы
    while (i <= mid) {
        aux[k++] = array[i++];
    }

    // Вторую половину копировать не нужно (поскольку остальные элементы
    // уже находятся на своем правильном месте во вспомогательном массиве)

    // копируем обратно в исходный массив, чтобы отразить порядок сортировки
    for (int i = low; i <= high; i++) {
        array[i] = aux[i];
        array[i].second = QColor(255,127,80);

        updateArray();
        QEventLoop loop;
        QTimer::singleShot(30, &loop, &QEventLoop::quit);
        loop.exec();

        resetColors();
    }

}

void PicturedArray::mergesort(int low, int high)
{
    // базовый вариант
    if (high <= low) {        // если размер прогона <= 1
        return;
    }

    // найти середину
    int mid = (low + ((high - low) >> 1));

    // рекурсивно разделяем прогоны на две половины до тех пор, пока размер прогона не станет <= 1,
    // затем объединяем их и возвращаемся вверх по цепочке вызовов

    mergesort(low, mid);          // разделить/объединить левую половину

    mergesort(mid + 1, high);     // разделить/объединить правую половину

    Merge(low, mid, high);        // объединить два полупрогона.
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
            array[l].second = QColor(255,127,80);
            array[r].second = QColor(255,127,80);
            updateArray();

            swap (l++, r--);
            updateArray();
            QEventLoop loop;
            QTimer::singleShot(30, &loop, &QEventLoop::quit);
            loop.exec();

            resetColors();
        }
    }
    if (left < r)
        QuickSort(left, r);
    if (right > l)
        QuickSort(l, right);
}
// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void PicturedArray::heapify(int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && array[l].first > array[largest].first)
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && array[r].first > array[largest].first)
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        array[i].second = QColor(255,127,80);
        array[largest].second = QColor(255,127,80);

        updateArray();

        swap(i, largest);

        updateArray();
        QEventLoop loop;
        QTimer::singleShot(30, &loop, &QEventLoop::quit);
        loop.exec();

        resetColors();

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void PicturedArray::heapSort(int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {

        array[i].second = QColor(255,127,80);
        array[0].second = QColor(255,127,80);

        updateArray();
        // Перемещаем текущий корень в конец
        swap(0, i);

        updateArray();
        QEventLoop loop;
        QTimer::singleShot(30, &loop, &QEventLoop::quit);
        loop.exec();


        resetColors();
        // вызываем процедуру heapify на уменьшенной куче
        heapify(i, 0);
    }
}

int PicturedArray::BinSearch(int digit)
{
    int left = 0, right = array.size() - 1, mid = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;

        array[left].second = Qt::red;
        array[right].second = Qt::red;
        array[mid].second = Qt::green;

        updateArray();

        QEventLoop loop;
        QTimer::singleShot(500, &loop, &QEventLoop::quit);
        loop.exec();

        if(array[mid].first == digit)
        {
            if(left != mid) array[left].second = QColor(0, 179, 134, array[left].first + 130);
            if(right != mid) array[right].second = QColor(0, 179, 134, array[right].first + 130);
            updateArray();

            return mid;
        }

        else if(array[mid].first > digit)
        {
            array[left].second = QColor(0, 179, 134, array[left].first + 130);
            array[right].second = QColor(0, 179, 134, array[right].first + 130);
            array[mid].second = QColor(0, 179, 134, array[mid].first + 130);
            updateArray();

            right = mid - 1;
        }
        else
        {
            array[left].second = QColor(0, 179, 134, array[left].first + 130);
            array[right].second = QColor(0, 179, 134, array[right].first + 130);
            array[mid].second = QColor(0, 179, 134, array[mid].first + 130);
            updateArray();

            left = mid + 1;
        }


    }

    return -1;

    //QColor(0, 179, 134, index + 130)
}

void PicturedArray::mergeSortForTime(int low, int high)
{
    if (high <= low) {
        return;
    }

    int mid = (low + ((high - low) >> 1));

    mergeSortForTime(low, mid);

    mergeSortForTime(mid + 1, high);

    mergeForTime(low, mid, high);
}

long long PicturedArray::timeMergeSort()
{
    copyOfArray.resize(array.size());
    copyOfAux.resize(array.size());

    for(int i = 0; i < array.size(); i++)
    {
        copyOfArray[i] = array[i];
        copyOfAux[i] = array[i];
    }

    clock_t t0 = clock();

    mergeSortForTime(0, copyOfArray.size() - 1);

    clock_t result = clock() - t0;

    long long time_of_sort = (double)result / CLOCKS_PER_SEC * 1000000.0;

    return time_of_sort;
}

void PicturedArray::quickSortForTime(int left, int right)
{
    int l = left, r = right;
    int piv = copyOfArray[(l + r) / 2].first; // Опорным элементом для примера возьмём средний

    while (l <= r)
    {
        while (copyOfArray[l].first < piv)
            l++;
        while (copyOfArray[r].first > piv)
            r--;
        if (l <= r)
        {
            std::pair<int, QColor> temp = copyOfArray[l];

            copyOfArray[l] = copyOfArray[r];
            copyOfArray[r] = temp;

            l++;
            r--;
        }
    }
    if (left < r)
        quickSortForTime(left, r);
    if (right > l)
        quickSortForTime(l, right);
}

void PicturedArray::mergeForTime(int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (copyOfArray[i].first <= copyOfArray[j].first) {
            copyOfAux[k++] = copyOfArray[i++];
        }
        else {
            copyOfAux[k++] = copyOfArray[j++];
        }
    }

    while (i <= mid) {
        copyOfAux[k++] = copyOfArray[i++];
    }

    for (int i = low; i <= high; i++) {
        copyOfArray[i] = copyOfAux[i];
    }
}

long long PicturedArray::timeQuickSort()
{
    copyOfArray.resize(array.size());

    for(int i = 0; i < array.size(); i++)
    {
        copyOfArray[i] = array[i];
    }

    clock_t t0 = clock();

    quickSortForTime(0, size() - 1);

    clock_t result = clock() - t0;

    long long time_of_sort = (double)result / CLOCKS_PER_SEC * 1000000.0;

    return time_of_sort;
}

void PicturedArray::heapSortForTime(int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyForTime(n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец

        copyOfArray[0];
        swapCopy(0, i);

        // вызываем процедуру heapify на уменьшенной куче
        heapifyForTime(i, 0);
    }
}

void PicturedArray::heapifyForTime(int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && copyOfArray[l].first > copyOfArray[largest].first)
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && copyOfArray[r].first > copyOfArray[largest].first)
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swapCopy(i, largest);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapifyForTime(n, largest);
    }
}

long long PicturedArray::timeHeapSort()
{
    copyOfArray.resize(array.size());

    for(int i = 0; i < array.size(); i++)
    {
        copyOfArray[i] = array[i];
    }

    clock_t t0 = clock();

    heapSortForTime(size() - 1);

    clock_t result = clock() - t0;

    long long time_of_sort = (double)result / CLOCKS_PER_SEC * 1000000.0;

    return time_of_sort;
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
