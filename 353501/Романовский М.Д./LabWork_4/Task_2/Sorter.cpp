
#include "Sorter.h"
#include "VisVector.h"
#include <qdebug.h>
#include <qlogging.h>
#include <stdexcept>


void Sorter::InterpolatoinSort(VisVector *arr, int low, int high) {
  if (high == -100)
    high = arr->Size() - 1;

  if(high <= low) return;

  if (high - low == 1) {
    if (arr->Read(low) > arr->Read(high))
      arr->Swap(low, high);
    return;
  }

  int min = INT_MAX;
  int max = INT_MIN;
  for(int i = low; i <= high; i++) {
    int el = arr->Read(i);
    if(el < min) min = el;
    if(el > max) max = el;
  }

  if(min == max) return;

  QVector<QVector<int>> buckets;
  buckets.resize(high - low + 1);
  for(int i = low; i <= high; i++) {
    int el = arr->Read(i);
    int bucket = (el - min) * (buckets.count() - 1) / (max - min);
    // if(el == min && bucket != 0)  {
    //   throw std::invalid_argument("21312313123");
    // }
    buckets[bucket].push_back(el);
  }

  int curpos = low;
  for(int i = 0; i < buckets.count(); i++) {
    if(buckets[i].empty()) continue;
    int buckstart = curpos;
    
    if(buckets[i].count() == high - low + 1) {
      throw std::invalid_argument("123213");
    }
    // qDebug() << (int)buckets[i].count();

    for(auto e: buckets[i]) {
      arr->Write(curpos++, e);
    }
    InterpolatoinSort(arr, buckstart, curpos - 1);
  }
}