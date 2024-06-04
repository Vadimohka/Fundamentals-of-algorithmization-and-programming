#ifndef SORTALGO_H
#define SORTALGO_H
#include "vector"

using std::vector;

class SortAlgo {
 public:
  SortAlgo() = default;

  static void heapify(std::vector<int>& vec, int n, int i);
  static double HeapSortTime(std::vector<int> vec);

  static int partition(std::vector<int>& vec, int low, int high);
  static void quickSort(std::vector<int>& vec, int low, int high);
  static double QuickSortTime(std::vector<int> vec);

  static void merge(std::vector<int>& vec, int left, int mid, int right);
  static void mergeSort(std::vector<int>& vec, int left, int right);
  static double MergeSortTime(std::vector<int> vec);
};

#endif  // SORTALGO_H
