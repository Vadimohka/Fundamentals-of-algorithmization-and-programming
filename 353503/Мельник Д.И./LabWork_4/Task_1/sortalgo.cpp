#include "sortalgo.h"
#include "algorithm"
#include "chrono"

void SortAlgo::heapify(std::vector<int>& vec, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && vec[left] > vec[largest]) {
    largest = left;
  }

  if (right < n && vec[right] > vec[largest]) {
    largest = right;
  }

  if (largest != i) {
    std::swap(vec[i], vec[largest]);
    heapify(vec, n, largest);
  }
}

double SortAlgo::HeapSortTime(std::vector<int> vec) {
  auto start = std::chrono::high_resolution_clock::now();
  int n = vec.size();

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(vec, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    std::swap(vec[0], vec[i]);
    heapify(vec, i, 0);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  return diff.count();
}

int SortAlgo::partition(std::vector<int>& vec, int low, int high) {
  int pivot = vec[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (vec[j] < pivot) {
      i++;
      std::swap(vec[i], vec[j]);
    }
  }
  std::swap(vec[i + 1], vec[high]);
  return (i + 1);
}

void SortAlgo::quickSort(std::vector<int>& vec, int low, int high) {
  if (low < high) {
    int pi = partition(vec, low, high);
    quickSort(vec, low, pi - 1);
    quickSort(vec, pi + 1, high);
  }
}

double SortAlgo::QuickSortTime(std::vector<int> vec) {
  auto start = std::chrono::high_resolution_clock::now();
  quickSort(vec, 0, vec.size() - 1);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  return diff.count();
}

void SortAlgo::merge(std::vector<int>& vec, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1), R(n2);

  for (i = 0; i < n1; i++) {
    L[i] = vec[left + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = vec[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      vec[k] = L[i];
      i++;
    } else {
      vec[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    vec[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    vec[k] = R[j];
    j++;
    k++;
  }
}

void SortAlgo::mergeSort(std::vector<int>& vec, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
  }
}

double SortAlgo::MergeSortTime(std::vector<int> vec) {
  auto start = std::chrono::high_resolution_clock::now();
  mergeSort(vec, 0, vec.size() - 1);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  return diff.count();
}
