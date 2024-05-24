#include "sortview.h"
long long SortView::op = 0;
SortView::SortView(QGraphicsScene* scene)
{

    this->scene = scene;
    array.resize(0);
    visualArray.resize(0);
}

void SortView::setArrSize(const long long n)
{
    for (int i = 0; i < array.size(); ++i)
    {
        delete visualArray[i];
    }
    array.resize(n);
    visualArray.resize(n);
    rectWidth = scene->width() / array.size() ;
}

void SortView::randArr()
{

    for (int i = 0; i < array.size(); ++i)
    {
        array[i] = QRandomGenerator::global()->bounded(20, 300);
        QGraphicsRectItem* rect = new QGraphicsRectItem(i * rectWidth, scene->height() - array[i], rectWidth, array[i]);
        rect->setBrush(Qt::black);
        rect->setPen(Qt::NoPen);
        visualArray[i] = rect;
    }
    op=0;
}

void SortView::showArr()
{

   /* QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        scene->removeItem(item);
    }*/
    for (int i = 0; i < array.size(); ++i) {
        scene->addItem(visualArray[i]);
    }
}

void SortView::doQSort(const long long left, const long long right)
{
    if (left >= right)
        return;
    long long pivot = array[(left + right) / 2];
    long long i = left;
    long long j = right;
   /* visualArray[(left + right) / 2]->setBrush(Qt::green);
    scene->removeItem(visualArray[(left + right) / 2]);
    scene->addItem(visualArray[(left + right) / 2]);*/
    while(i <= j)
    {
        while(array[i] < pivot)
        {
            hilight(i);
            i++;
        }
        while(array[j] > pivot)
        {
            hilight(j);
            j--;
        }

        if(i <= j){

            swapRect(i , j);

            std::swap(array[i++], array[j--]);
        }
    }
    /*visualArray[(left + right) / 2]->setBrush(Qt::white);
    scene->removeItem(visualArray[(left + right) / 2]);
    scene->addItem(visualArray[(left + right) / 2]);*/
    if(left < j)
        doQSort(left , j);
    if(right > i)
        doQSort(i, right);


}

void SortView::doMergeSort(const long long left, const long long right)
{
    if(left >= right)
        return;
    long long mid = left + (right - left) / 2;
    doMergeSort(left, mid);
    doMergeSort(mid + 1, right);
    // merge(left, mid, right);

    QVector<long long> t;
    for (int i = left, j = mid + 1; i <= mid || j <= right;) {
        if (i > mid) {
            t.push_back(array[j++]);
        } else if (j > right) {
            t.push_back(array[i++]);
        } else if (array[i] <= array[j]) {
            t.push_back(array[i++]);
        } else {
            t.push_back(array[j++]);
        }
    }


    for (int i = 0; i < t.size(); i++) {
        visualArray[left + i]->setRect((left + i) * rectWidth, scene->height() - t[i], rectWidth, t[i]);
        hilight(left + i);
        array[left + i] = t[i];
    }


}
/*void SortView::merge(const long long left , const long long mid, const long long right)
{
    QVector<long long> t;
    for (int i = left, j = mid + 1; i <= mid || j <= right;  ) {
        if (i > mid) {
            hilight(j);
            t.push_back(array[j++]);
        } else if (j > right) {
            hilight(i);
            t.push_back(array[i++]);
        } else if (array[i] <= array[j]) {
            hilight(i);
            t.push_back(array[i++]);
        } else {
            hilight(j);
            t.push_back(array[j++]);
        }

    }

    for (int i = 0; i < t.size(); i++) {
        visualArray[left + i]->setRect((left + i) * rectWidth, scene->height() - t[i], rectWidth, t[i]);
        hilight(left + i);
        array[left + i] = t[i];
    }
}*/
void SortView::doHeapSort()
{
    long long n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swapRect(0, i);
        std::swap(array[0], array[i]);
        heapify(i, 0);
    }

  /*  for (int i = 0; i < array.size(); ++i)
    {
        qDebug() << array[i] << ' ';
    }*/
}

long long SortView::doBinSearch(long long n)
{
    qDebug()<<n;
    long long l = 0;
    long long r = array.size() - 1;


    while (r > l) {
        int m = (l + r) / 2;
        visualArray[l]->setBrush(Qt::green);
        visualArray[r]->setBrush(Qt::green);
        visualArray[m]->setBrush(Qt::yellow);
        auto time = QTime::currentTime().addMSecs(delay);
        while(QTime::currentTime() < time){
            QApplication::processEvents(QEventLoop::AllEvents);
        }
        visualArray[m]->setBrush(Qt::black);
        visualArray[l]->setBrush(Qt::black);
        visualArray[r]->setBrush(Qt::black);
        if (array[m] < n) {
            l = m + 1;
        } else if (array[m] > n) {
            r = m - 1;
        } else {
            hilight(l);
            return m;
        }
    }

    if (array[l] == n) {
        hilight(l);
        return l;
    } else {
        return -1;
    }
}

void SortView::setDelay(int n)
{
    delay = n;
}

const QVector<long long> &SortView::getArray()
{
    return array;
}

void SortView::doInterpolationSort()
{
    interpolationSort(array, 0, -1);
    for(int i = 0; i < array.size(); i++)
        qDebug()<<array[i];
}



void SortView::heapify(long long n, long long i)
{
    long long largest = i;
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
        largest = l;


    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        swapRect(i, largest);
        std::swap(array[i], array[largest]);
        heapify(n, largest);
    }

}


void SortView::hilight(long long index)
{

    visualArray[index]->setBrush(Qt::red);
    /*QEventLoop eventLoop;
    QTimer timer;
    timer.setInterval(delay);
    QObject::connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    timer.start();
    eventLoop.exec();*/
    auto time = QTime::currentTime().addMSecs(delay);
    while(QTime::currentTime() < time){
        QApplication::processEvents(QEventLoop::AllEvents);
    }
    visualArray[index]->setBrush(Qt::black);

}



void SortView::swapRect(long long index1, long long index2)
{

    QRectF r1 = visualArray[index1]->rect();
    QRectF r2 = visualArray[index2]->rect();

    visualArray[index2]->setRect(index2 * rectWidth, scene->height() - array[index1], rectWidth, r1.height());
    visualArray[index1]->setRect(index1 * rectWidth, scene->height() - array[index2], rectWidth, r2.height());
    visualArray[index2]->setBrush(Qt::red);
    visualArray[index1]->setBrush(Qt::red);


   /* QEventLoop eventLoop;
    QTimer timer;
    timer.setInterval(delay);
    QObject::connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    timer.start();
    eventLoop.exec();*/
    auto time = QTime::currentTime().addMSecs(delay);
    while(QTime::currentTime() < time){
        QApplication::processEvents(QEventLoop::AllEvents);
    }

    visualArray[index2]->setBrush(Qt::black);
    visualArray[index1]->setBrush(Qt::black);

}


void SortView::interpolationSort(QVector<long long> &arr, long long low, long long high)
{
    if (high == -1)
        high = arr.size() - 1;

    if(high <= low) return;

    if (high - low == 1) {
        if (arr[low] > arr[high]){
            swapRect(low, high);
            std::swap(arr[low],arr[high]);
        }
        return;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = low; i <= high; i++) {
        int element = arr[i];
        if(element  < min) min = element ;
        if(element  > max) max = element ;
    }

    if(min == max) return;

    QVector<QVector<long long>> buckets;
    buckets.resize(high - low + 1);
    for(int i = low; i <= high; i++) {
        int el = arr[i];
        int bucket = (el - min) * (buckets.count() - 1) / (max - min);

        /*qDebug()<<el<< "   !";
        visualArray[i - low]->setBrush(QColor((bucket + 100 )%256,bucket%256,bucket%256));
        auto time = QTime::currentTime().addMSecs(delay);
        while(QTime::currentTime() < time){
            QApplication::processEvents(QEventLoop::AllEvents);
        }
*/

        buckets[bucket].push_back(el);
    }

    int curpos = low;
    for(int i = 0; i < buckets.count(); i++) {
        if(buckets[i].empty()) continue;
        int buckstart = curpos;

        if(buckets[i].count() == high - low + 1) {
            throw std::invalid_argument("123213");
        }


        for(auto e: buckets[i]) {
            setRect(e, curpos);
            arr[curpos++] = e;
        }
        /*auto time = QTime::currentTime().addMSecs(delay*50);
        while(QTime::currentTime() < time){
            QApplication::processEvents(QEventLoop::AllEvents);
        }*/


     //   qDebug()<<"!";
       // for(int i = 0; i < array.size(); i++)
          //  qDebug()<<array[i];
        interpolationSort(arr, buckstart, curpos - 1);
    }
}

long long SortView::binpow(long long a, long long n, long long q)
{
    if (n == 0)
        return 1;
    long long z = binpow(a % q, n / 2, q) % q;
    if (n % 2 == 0)
        return (z * z) % n;
    else
        return ((a % q) * ((z * z) % q)) % q;
}

long long SortView::getArrSize()
{
    return array.size();
}


void SortView::setRect(long long h, long long pos)
{

    visualArray[pos]->setRect(pos * rectWidth, scene->height() - h, rectWidth, h);

    visualArray[pos]->setBrush(Qt::red);


    auto time = QTime::currentTime().addMSecs(delay);
    while(QTime::currentTime() < time){
        QApplication::processEvents(QEventLoop::AllEvents);
    }

    visualArray[pos]->setBrush(Qt::black);
}


