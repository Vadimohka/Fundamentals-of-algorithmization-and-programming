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
{
    for(int i = 0; i < array.size(); i++){
        rectArray.at(array.size() - 1 - i)->~Rect();
        rectArray.pop_back();
    }
    clear();
    array.clear();
    int value;
    for(int i = 0; i < size; i++){
        value = random() % size + 1;
        if(array.contains(value)){
            i--;
            continue;
        }
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

int GraphicSort::binPow(int digit, int powder, int mod)
{
    if(powder == 0){
        return 1;
    }
    else if(powder == 1){
        return digit % mod;
    }
    else if(digit % 2 ==0){
        return binPow((digit * digit)%mod, powder/2, mod) % mod;
    }
    else{
        return (binPow((digit * digit)%mod*digit, powder/2, mod)*digit) % mod;
    }
}

void GraphicSort::interpolationSort()
{
    int min = 100;
    int max = 0;
    for(int i = 0; i < array.size(); i++){
        if(min > array.at(i)){
            min = array.at(i);
        }
        if(max < array.at(i)){
            max = array.at(i);
        }
    }
    int pos = 0;

    int arr[array.size()];
    for(int i = 0; i < array.size(); i++){
        arr[i] = array.at(i);
    }

    for(int i = 0; i < array.size(); i++){
        pos = int((((double)arr[i] - min)/(max - min))*(array.size() - 1));

        array[pos] = arr[i];
        rectArray[i]->setX(pos*760/array.size());
        rectArray[i]->aim = true;
        QCoreApplication::processEvents();
        QThread::msleep(10);
        rectArray[i]->aim = false;
        rectArray[i]->update();
    }
}
