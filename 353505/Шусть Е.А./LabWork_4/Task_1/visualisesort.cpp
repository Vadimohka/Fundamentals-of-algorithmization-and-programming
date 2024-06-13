#include "visualisesort.h"
const qint64 DELAY = 100;
const qreal WIDTH = 15;

void VisualiseSort::Merge(int* target, int size_target, int* arr_1 , int size_1 , int* arr_2 , int size_2)
{
    int arrMin_1 = 0;
    int arrMin_2 = 0;
    int targetMin = 0;

    while(arrMin_1 < size_1 && arrMin_2 < size_2)
    {
        if(arr_1[arrMin_1] >= arr_2[arrMin_2])
        {
            target[targetMin] = arr_2[arrMin_2];
            changeHeight(*_items.at(targetMin),arr_2[arrMin_2]);
            arrMin_2++;
        }
        else
        {
            target[targetMin] = arr_1[arrMin_1];
            changeHeight(*_items.at(targetMin),arr_1[arrMin_1]);
            arrMin_1++;
        }
        targetMin++;
    }
    while(arrMin_1 < size_1)
    {
        target[targetMin] = arr_1[arrMin_1];
        changeHeight(*_items.at(targetMin),arr_1[arrMin_1]);
        arrMin_1++;
        targetMin++;
    }
    while(arrMin_2 < size_2)
    {
        target[targetMin] = arr_2[arrMin_2];
        changeHeight(*_items.at(targetMin),arr_2[arrMin_2]);
        arrMin_2++;
        targetMin++;
    }
}

int VisualiseSort::BinarySearch(int *arr, int left, int right, int target)
{
    while (left <= right)
    {
        int m = left + (right - left) / 2;

        if (m >= 0 && m < _items.size() && arr[m] == target)
        {
            _scene->update();
            _items.at(m)->setBrush(Qt::red);
            return m;
        }

        if (m >= 0 && m < _items.size() && arr[m] < target)
        {
            left = m + 1;
            if (left >= 0 && left < _items.size()) {
                _items.at(left)->setBrush(Qt::green);
            }
            _scene->update();
            skip(DELAY*2);
            if (left >= 0 && left < _items.size()) {
                _items.at(left)->setBrush(Qt::white);
            }
            _scene->update();
        }

        if (m >= 0 && m < _items.size() && arr[m] > target)
        {
            right = m - 1;
            if (right >= 0 && right < _items.size()) {
                _items.at(right)->setBrush(Qt::green);
            }
            _scene->update();
            skip(DELAY*2);
            if (right >= 0 && right < _items.size()) {
                _items.at(right)->setBrush(Qt::white);
            }
            _scene->update();
        }
    }
    return -1;
}

void VisualiseSort::heapify(int* arr, int size, int i)
{
    int largest = i;

    int l = 2 * i + 1;//left
    int r = l + 1;//right

    if (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        changeHeight(*_items.at(i),*_items.at(largest));
        heapify(arr, size, largest);
    }
}

void VisualiseSort::skip(int ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, &QEventLoop::quit);
    loop.exec();
}

void VisualiseSort::SuccessSorting()
{
    for (int i = 0; i < _size; ++i)
    {
        _items.at(i)->setBrush(Qt::green);
    }
    _scene->update();
}

void VisualiseSort::outputArray()
{
    _items.clear();
    _scene->clear();
    for (int i = 0; i < _size; ++i)
    {
        auto *temp = new QGraphicsRectItem(0,0,10,_arr[i]);
        temp->setBrush(QBrush(Qt::white));
        temp->setPos(i * WIDTH, 0);
        _items.push_back(temp);
        _scene->addItem(temp);
        _scene->update();
    }
}

void VisualiseSort::startVisualisation()
{
    timer->start();
    switch (_flag)
    {
    case 'q':
        QuickSort(_arr,0,_size - 1);
        skip(DELAY);
        SuccessSorting();
        break;
    case 'h':
        HeapSort(_arr,_size);
        skip(DELAY);
        SuccessSorting();
        break;
    case 'm':
        MergeSort(_arr,_size);
        skip(DELAY);
        SuccessSorting();
        break;
    default:
        QMessageBox::warning(nullptr,"Error","Incorrect data!");
        break;
    }
    qDebug() << "Execution time: " << timer->elapsed() << "milliseconds";
}

void VisualiseSort::QuickSort(int *arr, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = arr[(start + end )/ 2];
    do
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i <= j)
        {
            std::swap(arr[i],arr[j]);
            changeHeight(*_items.at(i),*_items.at(j));
            j--;
            i++;
        }
    }while(i <= j);

    if(j > start)
    {
        QuickSort(arr,start,j);
    }
    if(i < end)
    {
        QuickSort(arr,i,end);
    }
}

void VisualiseSort::HeapSort(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]);
        changeHeight(*_items.at(0),*_items.at(i));
        heapify(arr, i, 0);
    }
}

void VisualiseSort::MergeSort(int *arr, int size)
{
    if(size <= 1)
    {
        return;
    }

    int mid = size / 2;

    int* left = new int [mid];
    int* right = new int [size - mid];

    for (int i = 0; i < mid; ++i)
    {
        left[i] = arr[i];
    }

    for (int i = mid , j = 0; i < size; ++i , j++)
    {
        right[j] = arr[i];
    }

    MergeSort(right,size - mid);
    MergeSort(left,mid);
    Merge(arr,size,left,mid,right,size - mid);
    delete[] left;
    delete[] right;
}

void VisualiseSort::changeHeight(QGraphicsRectItem &item_1,QGraphicsRectItem &item_2)
{
    qreal tempHeight = item_1.rect().height();
    QRectF rect = item_1.rect();
    item_1.hide();
    rect.setHeight(item_2.rect().height());
    item_1.setRect(rect);
    item_1.show();

    item_1.hide();
    rect = item_2.rect();
    rect.setHeight(tempHeight);
    item_1.show();
    item_2.setRect(rect);

    item_1.setBrush(Qt::green);
    item_2.setBrush(Qt::green);

    skip(DELAY);
    _scene->update();

    item_1.setBrush(Qt::white);
    item_2.setBrush(Qt::white);
    _delay +=DELAY;
}

void VisualiseSort::changeHeight(QGraphicsRectItem &item_1, qreal height)
{
    qreal tempHeight = item_1.rect().height();
    item_1.hide();
    QRectF rect = item_1.rect();
    rect.setHeight(height);
    item_1.show();
    item_1.setRect(rect);

    item_1.setBrush(Qt::green);

    skip(DELAY);
    _scene->update();

    item_1.setBrush(Qt::white);
    _delay +=DELAY;
}

qreal VisualiseSort::getTime()
{
    return (timer->elapsed() - _delay);
}
