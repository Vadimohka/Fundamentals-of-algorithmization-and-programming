#include "graphicsort.h"

GraphicSort::GraphicSort() {}

bool GraphicSort::isSorted() const
{
    bool isSorted = true;
    for(int i = 0; i < array.size() - 1; i++){
        if(array.at(i) > array.at(i + 1)){
            isSorted = false;
        }
    }
    return isSorted;
}

void GraphicSort::setSize(int size)
{    for(int i = 0; i < array.size(); i++){
        rectArray.at(array.size() - 1 - i)->~Rect();
        rectArray.pop_back();
    }
    rectArray.clear();
    clear();
    array.clear();
    int value;
    for(int i = 0; i < size; i++){
        value = random() % size + 1;
        array.push_back(value);
        rectArray.push_back(new Rect());
        rectArray[i]->setParam(760.0/size * i, 450 - value * 4, 760.0/size, value * 4);
        addItem(rectArray[i]);
    }
}

void GraphicSort::swap(int i, int j)
{
    if(!running){
        return;
    }
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    temp = rectArray[i]->pos().x();
    rectArray[i]->setX(rectArray[j]->pos().x());
    rectArray[j]->setX(temp);
    rectArray[i]->aim = true;
    Rect *rTemp = rectArray[i];
    rectArray[i] = rectArray[j];
    rectArray[j] = rTemp;
    QCoreApplication::processEvents();
    QThread::msleep(10);
    rectArray[j]->aim = false;
    rectArray[j]->update();
}

int GraphicSort::binSearch(int digit)
{
    int begin = 0;
    int end = array.size() - 1;
    int mid = qRound((begin + end)/2.0);
    while(begin <= end){
        mid = qRound((begin + end)/2.0);
        if(array.at(mid) == digit){
            return mid + 1;
        }
        else if(digit < array.at(mid)){
            end = mid - 1;
        }
        else{
            begin = mid + 1;
        }
    }
    return -1;
}

void GraphicSort::heapify(int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest]){
        largest = l;
    }
    if (r < size && array[r] > array[largest]){
        largest = r;
    }
    if (largest != i) {
        swap(i, largest);
        heapify(size, largest);
    }
}

void GraphicSort::heapSort(int size)
{
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        swap(0, i);
        heapify(i, 0);
    }
}

void GraphicSort::quickSort(int begin, int end)
{
    if (begin < end && running){
        int pivot = array[end];
        int i = (begin - 1);
        for (int j = begin; j < end; j++){
            if (array[j] <= pivot){
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, end);

        int pi = i + 1;

        quickSort(begin, pi - 1);
        quickSort(pi + 1, end);
    }
}

void GraphicSort::merge(int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];
    auto *RleftArray = new Rect[subArrayOne],
        *RrightArray = new Rect[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++){
        leftArray[i] = array[left + i];
        RleftArray[i] = *rectArray[left + i];
    }
    for (auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
        RrightArray[j] = *rectArray[mid + 1 + j];
    }
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo && running) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            Rect* rect = rectArray[indexOfMergedArray];
            rect->~Rect();
            rectArray[indexOfMergedArray] = &RleftArray[indexOfSubArrayOne];
            rectArray[indexOfMergedArray]->setPos(760.0/array.size()*indexOfMergedArray, 450 - 4 * array[indexOfMergedArray]);
            addItem(rectArray[indexOfMergedArray]);
            rectArray[indexOfMergedArray]->aim = true;
            QCoreApplication::processEvents();
            QThread::msleep(10);
            rectArray[indexOfMergedArray]->aim = false;
            rectArray[indexOfMergedArray]->update();
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            Rect* rect = rectArray[indexOfMergedArray];
            rect->~Rect();
            rectArray[indexOfMergedArray] = &RrightArray[indexOfSubArrayTwo];
            rectArray[indexOfMergedArray]->setPos(760.0/array.size()*indexOfMergedArray, 450 - 4 * array[indexOfMergedArray]);
            addItem(rectArray[indexOfMergedArray]);
            rectArray[indexOfMergedArray]->aim = true;
            QCoreApplication::processEvents();
            QThread::msleep(10);
            rectArray[indexOfMergedArray]->aim = false;
            rectArray[indexOfMergedArray]->update();
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne && running) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        Rect* rect = rectArray[indexOfMergedArray];
        rect->~Rect();
        rectArray[indexOfMergedArray] = &RleftArray[indexOfSubArrayOne];
        rectArray[indexOfMergedArray]->setPos(760.0/array.size()*indexOfMergedArray, 450 - 4 * array[indexOfMergedArray]);
        addItem(rectArray[indexOfMergedArray]);
        rectArray[indexOfMergedArray]->aim = true;
        QCoreApplication::processEvents();
        QThread::msleep(10);
        rectArray[indexOfMergedArray]->aim = false;
        rectArray[indexOfMergedArray]->update();
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo && running) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        Rect* rect = rectArray[indexOfMergedArray];
        rect->~Rect();
        rectArray[indexOfMergedArray] = &RrightArray[indexOfSubArrayTwo];
        rectArray[indexOfMergedArray]->setPos(760.0/array.size()*indexOfMergedArray, 450 - 4 * array[indexOfMergedArray]);
        addItem(rectArray[indexOfMergedArray]);
        rectArray[indexOfMergedArray]->aim = true;
        QCoreApplication::processEvents();
        QThread::msleep(10);
        rectArray[indexOfMergedArray]->aim = false;
        rectArray[indexOfMergedArray]->update();
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void GraphicSort::mergeSort(int const begin, int const end)
{

    if (begin >= end){
        return;
    }
    if(!running){
        return;
    }
    int mid = (begin + end) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}
