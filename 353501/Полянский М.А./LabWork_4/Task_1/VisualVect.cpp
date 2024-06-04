#include "VisualVect.h"

int VisualVector::op = 0;

VisualVector::VisualVector(QGraphicsScene* scene)
{

    this->scene = scene;
    scene->setSceneRect(0, 0, 900, 500);
    
}

void VisualVector::SetSize(const int n)
{
    size = n;
    for (int i = 0; i < array.size(); ++i)
    {
        delete visual[i];
    }
    array.resize(n);
    visual.resize(n);
    rectWidth = scene->width() / array.size();
    FillArray();
}

void VisualVector::FillArray()
{
    for (int i = 0; i < array.size(); ++i)
    {
        array[i] = rand() % (230 - 12) + 12;
        QGraphicsRectItem* rect = new QGraphicsRectItem(i * rectWidth, 500 - array[i], rectWidth, array[i]);
        rect->setBrush(Qt::white);
        visual[i] = rect;
    }
    op = 0;
}

void VisualVector::Show()
{
    for (int i = 0; i < array.size(); ++i)
    {
        scene->addItem(visual[i]);
    }
}

void VisualVector::QuickSort(const int left, const int right)
{
    if (left >= right)
        return;
    int pivot = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (array[i] < pivot)
        {
            UnderLine(i);
            i++;
        }
        while (array[j] > pivot)
        {
            UnderLine(j);
            j--;
        }

        if (i <= j)
        {
            Swap(i, j);
            std::swap(array[i++], array[j--]);
        }
    }
    if (left < j)
        QuickSort(left, j);
    if (right > i)
        QuickSort(i, right);
}

void VisualVector::MergeSort(const int left, const int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);

    QVector<int> t;
    for (int i = left, j = mid + 1; i <= mid || j <= right;)
    {
        if (i > mid)
        {
            t.push_back(array[j++]);
        }
        else if (j > right)
        {
            t.push_back(array[i++]);
        }
        else if (array[i] <= array[j])
        {
            t.push_back(array[i++]);
        }
        else
        {
            t.push_back(array[j++]);
        }
    }

    for (int i = 0; i < t.size(); i++)
    {
        visual[left + i]->setRect((left + i) * rectWidth, scene->height() - t[i], rectWidth, t[i]);
        UnderLine(left + i);
        array[left + i] = t[i];
    }
}

void VisualVector::HeapSort()
{
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--)
    {
        Swap(0, i);
        std::swap(array[0], array[i]);
        heapify(i, 0);
        QCoreApplication::processEvents();
    }
}
void VisualVector::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest != i)   
    {
        Swap(i, largest);
        std::swap(array[i], array[largest]);
        heapify(n, largest);
    }
}


int VisualVector::BinSearch(int n)
{
    int l = 0;
    int r = array.size() - 1;

    while (r > l)
    {
        int m = (l + r) / 2;
        UnderLine(l);
        UnderLine(r);
        UnderLine(m);
        auto time = QTime::currentTime().addMSecs(delay);
        while (QTime::currentTime() < time)
        {
            QApplication::processEvents(QEventLoop::AllEvents);
        }
        if (array[m] < n)
        {
            l = m + 1;
        }
        else if (array[m] > n)
        {
            r = m - 1;
        }
        else    
        {
            UnderLine(l);
            return m;
        }
    }

    if (array[l] == n)
    {
        UnderLine(l);
        return l;
    }
    else
    {
        return -1;
    }
}



const QVector<int> &VisualVector::GetArray()
{
    return array;
}



int VisualVector::GetSize()
{
    return array.size();
}

void VisualVector::SetRect(int h, int pos)
{
    visual[pos]->setRect(pos * rectWidth, 900 - h, rectWidth, h);
    visual[pos]->setBrush(Qt::red);

    auto time = QTime::currentTime().addMSecs(delay);
    while (QTime::currentTime() < time)
    {
        QApplication::processEvents(QEventLoop::AllEvents);
    }

    visual[pos]->setBrush(Qt::white);
}

void VisualVector::UnderLine(int index)
{
    visual[index]->setBrush(Qt::red);
    auto time = QTime::currentTime().addMSecs(delay);
    while (QTime::currentTime() < time)
    {
        QApplication::processEvents(QEventLoop::AllEvents);
    }
    visual[index]->setBrush(Qt::white);
}

void VisualVector::Swap(int index1, int index2)
{
    QRectF r1 = visual[index1]->rect();
    QRectF r2 = visual[index2]->rect();

    visual[index2]->setRect(index2 * rectWidth, scene->height() - array[index1], rectWidth, r1.height());
    visual[index1]->setRect(index1 * rectWidth, scene->height() - array[index2], rectWidth, r2.height());
    visual[index2]->setBrush(Qt::red);
    visual[index1]->setBrush(Qt::red);

    auto time = QTime::currentTime().addMSecs(delay);
    while (QTime::currentTime() < time)
    {
        QApplication::processEvents(QEventLoop::AllEvents);
    }

    visual[index2]->setBrush(Qt::white);
    visual[index1]->setBrush(Qt::white);
}
