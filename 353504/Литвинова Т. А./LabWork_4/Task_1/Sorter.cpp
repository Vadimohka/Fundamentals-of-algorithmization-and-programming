
#include "Sorter.h"
#include "VisVector.h"

void Sorter::heapify(VisVector *arr, int N, int i) {
  int largest = i;
  int largest_val = arr->Read(largest);

  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < N) {
    int l_val = arr->Read(l);
    if (l_val > largest_val) {
      largest = l;
      largest_val = l_val;
    }
  }

  if (r < N) {
    int r_val = arr->Read(r);
    if (r_val > largest_val) {
      largest = r;
      largest_val = r_val;
    }
  }

  if (largest != i) {
    arr->Swap(i, largest);
    heapify(arr, N, largest);
  }
}

void Sorter::HeapSort(VisVector *arr) {
  for (int i = arr->Size() / 2 - 1; i >= 0; i--)
    heapify(arr, arr->Size(), i);

  for (int i = arr->Size() - 1; i > 0; i--) {
    arr->Swap(0, i);
    heapify(arr, i, 0);
  }
}

// Returns the index of pivot element
int Sorter::Partition(VisVector *arr, int low, int high) {
  int pivot = arr->Read(high);
  int i = (low - 1); // posiition of biggest element smaller than pibot

  for (int j = low; j <= high; j++) {
    if (arr->Read(j) < pivot) {
      i++;
      arr->Swap(i, j);
    }
  }

  arr->Swap(i + 1, high);
  return (i + 1);
}

void Sorter::QuickSort(VisVector *arr, int low, int high) {
  if (high == -100)
    high = arr->Size() - 1;

  if (low < high) {
    int pi = Partition(arr, low, high);

    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}

void Sorter::MergeSort(VisVector *arr, int low, int high) {
  if (high == -100)
    high = arr->Size() - 1;

  if (low >= high)
    return;
  if (high - low == 1) {
    if (arr->Read(low) > arr->Read(high))
      arr->Swap(low, high);
    return;
  }

  int mid = (high + low) / 2;
  MergeSort(arr, low, mid);
  MergeSort(arr, mid + 1, high);

  QVector<int> tempVal = {};
  int lp = low;
  int rp = mid + 1;

  while (lp <= mid && rp <= high) {
    int lv = arr->Read(lp);
    int rv = arr->Read(rp);
    if (lv < rv) {
      tempVal.push_back(lv);
      lp++;
    } else {
      tempVal.push_back(rv);
      rp++;
    }
  }

  while (lp <= mid) {
    tempVal.push_back(arr->Read(lp++));
  }

  while (rp <= high) {
    tempVal.push_back(arr->Read(rp++));
  }

  for(int i = 0; i < tempVal.count(); i++) {
    arr->Write(low + i, tempVal[i]);
  }
}