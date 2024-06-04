#pragma once

#include "linker.h"

#define BREAKPOINT  \
  if (!ok)          \
  return

class Sorter {
public:
  explicit Sorter(Linker *);
  void stop();

  void Bubble_upwards();
  void Bubble_downwards();
  void Bubble_shaker();

  void Quick_naive();
  void Quick_middle();
  void Quick_optimized();
  void Quick_median();

  void Mergesort_standard();
  void Mergesort_pack();
  void Mergesort_weave();

  void Heapsort_max();
  void Heapsort_sift();
  void Heapsort_min();
  void Heapsort_tern();
  void InterpolationSort();

private:
  void Quicksort(int, int, int);
  int Naive_partition(int, int);
  int Middle_partition(int, int);
  int Fast_partition(int, int);
  int Median_partition(int, int);
  int Median_of_medians(int, int);
  int Median_of_5(int);
  int Qselect(int, int, int);
  void Mergesort(int, int, item *[]);
  void merge(int, int, int, item *[]);
  void Weavesort(int a, int b, item* tab[]);
  void weave(int a, int b, int c, item* tab[]);
  void Reheapify_max(int, int);
  void Reheapify_sift(int);
  void Reheapify_min(int, int);
  void Reheapify_tern(int, int);
  void LocalInsertSort(int, int);
  void Interpolation(item*[]);
  Linker *m_link;
  int m_size;
  bool ok;
};
