class VisVector;

class Sorter {
private:
  static void heapify(VisVector *arr, int N, int i);
  static int Partition(VisVector *arr, int low, int high);
  
public:
  static void HeapSort(VisVector *vis);
  static void QuickSort(VisVector *arr, int low = 0, int high = -100);
  static void MergeSort(VisVector *arr, int low = 0, int high = -100);
};