#include "sorter.h"

Sorter::Sorter(Linker* link) {
  m_link = link;
  m_size = m_link->getSize();
  ok = true;
}

void Sorter::stop() {
  ok = false;
}

// /////////// //
// BUBBLE-TYPE //
// /////////// //

void Sorter::Bubble_upwards() {
  for (int i = 0; i < m_size; i++) {
    bool sorted = true;
    for (int j = m_size - 1; j > i; j--) {
      BREAKPOINT;
      if (m_link->cmp_ii(j, j - 1)) {
        sorted = false;
        m_link->flip(j, j - 1);
      }
    }
    m_link->solved(i);
    if (sorted) {
      for (int j = i + 1; j < m_size; j++) {
        BREAKPOINT;
        m_link->solved(j);
      }
      break;
    }
  }
}

void Sorter::Bubble_downwards() {
  for (int i = m_size; i > 0; i--) {
    bool sorted = true;
    for (int j = 1; j < i; j++) {
      BREAKPOINT;
      if (m_link->cmp_ii(j, j - 1)) {
        sorted = false;
        m_link->flip(j, j - 1);
      }
    }
    m_link->solved(i - 1);
    if (sorted) {
      for (int j = 0; j < i; j++) {
        BREAKPOINT;
        m_link->solved(j);
      }
      break;
    }
  }
}

void Sorter::Bubble_shaker() {
  int lt = 0, rt = m_size;
  int upwards = true;
  while (rt > lt) {
    if (upwards) {
      int k = lt + 1;
      for (int i = lt + 1; i < rt; i++) {
        BREAKPOINT;
        if (m_link->cmp_ii(i, i - 1)) {
          m_link->flip(i, i - 1);
          k = i;
        }
      }
      do
        m_link->solved(--rt);
      while (rt > k);
      upwards = false;
    } else {
      int k = rt - 1;
      for (int i = rt - 1; i > lt; i--) {
        BREAKPOINT;
        if (m_link->cmp_ii(i, i - 1)) {
          m_link->flip(i, i - 1);
          k = i;
        }
      }
      do {
        BREAKPOINT;
        m_link->solved(lt++);
      } while (lt < k);
      upwards = true;
    }
  }
}

// ////////// //
// QUICK-TYPE //
// ////////// //

void Sorter::Quick_naive() {
  Quicksort(0, m_size, 0);
}

void Sorter::Quick_middle() {
  Quicksort(0, m_size, 1);
}

void Sorter::Quick_optimized() {
  Quicksort(0, m_size, 2);
}

void Sorter::Quick_median() {
  Quicksort(0, m_size, 3);
}

void Sorter::Quicksort(int a, int b, int part) {
  if (b - a == 1) {
    m_link->solved(a);
    return;
  } else if (b - a < 1) {
    return;
  } else if (b - a == 2) {
    m_link->flip_ifn_cmp(a, b - 1);
    m_link->solved(a);
    m_link->solved(b - 1);
    return;
  }
  int pv = 0;
  switch (part) {
    case 0:
      pv = Naive_partition(a, b);
      break;
    case 1:
      pv = Middle_partition(a, b);
      break;
    case 2:
      pv = Fast_partition(a, b);
      break;
    case 3:
      pv = Median_partition(a, b);
      break;
  }
  BREAKPOINT;
  m_link->solved(pv);
  Quicksort(a, pv, part);
  BREAKPOINT;
  Quicksort(pv + 1, b, part);
  BREAKPOINT;
}

int Sorter::Naive_partition(int a, int b) {
  item* pvVal = m_link->send(a);
  int pvIdx = a;
  int k = a + 1;
  while (k < b) {
    BREAKPOINT 0;
    if (m_link->cmp_ie(k, pvVal)) {
      m_link->flip(pvIdx++, k);
      if (pvIdx != k)
        m_link->flip(pvIdx, k);
      k++;
    } else {
      k++;
    }
  }
  return pvIdx;
}

int Sorter::Middle_partition(int a, int b) {
  int pvIdx = a;
  m_link->flip(pvIdx, (b + a) / 2);
  item* pvVal = m_link->send(a);
  int k = a + 1;
  while (k < b) {
    BREAKPOINT 0;
    if (m_link->cmp_ie(k, pvVal)) {
      m_link->flip(pvIdx++, k);
      if (pvIdx != k)
        m_link->flip(pvIdx, k);
      k++;
    } else {
      k++;
    }
  }
  return pvIdx;
}

int Sorter::Fast_partition(int a, int b) {
  // Edge cases
  if (b - a <= 1) {
    return a;
  } else if (b - a == 2) {
    if (m_link->cmp_ii(a + 1, a)) {
      m_link->flip(a, a + 1);
    }
    m_link->solved(a + 1);
    return a;
  } else if (b - a < 6) {
    return Middle_partition(a, b);
  }
  int p1 = (a + b) / 2;
  int p2 = (a + p1) / 2;
  int p3 = (b + p1) / 2;
  item* pVal1 = m_link->send(p1);
  item* pVal2 = m_link->send(p2);
  item* pVal3 = m_link->send(p3);
  int p;
  // Find median
  if (m_link->cmp_ii(p1, p3)) {
    if (m_link->cmp_ee(pVal1, pVal2)) {
      if (m_link->cmp_ee(pVal2, pVal3)) {
        p = p2;
      } else {
        p = p3;
      }
    } else {
      p = p1;
    }
  } else {
    if (m_link->cmp_ee(pVal1, pVal2)) {
      p = p1;
    } else {
      if (m_link->cmp_ee(pVal2, pVal3)) {
        p = p2;
      } else {
        p = p3;
      }
    }
  }
  m_link->flip(p, a);
  int pv = a;
  item* pvVal = m_link->send(pv);
  int i = a, j = b;
  for (;;) {
    do {
      BREAKPOINT 0;
      j--;
    } while ((i < j) && !m_link->cmp_ie(j, pvVal));
    do {
      BREAKPOINT 0;
      i++;
    } while ((i < j) && m_link->cmp_ie(i, pvVal));
    if (i < j) {
      m_link->flip(i, j);
    } else {
      m_link->flip(pv, j);
      return j;
    }
  }
}

inline void flip(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int Sorter::Median_of_5(int idx) {
  int a = idx, b = idx + 1, c = idx + 2, d = idx + 3, e = idx + 4;
  if (m_link->cmp_ii(b, a))
    flip(&a, &b);  // (a < b)
  if (m_link->cmp_ii(d, c))
    flip(&c, &d);  // (c < d)
  if (m_link->cmp_ii(c, a)) {
    flip(&a, &c);
    flip(&b, &d);
  }  // (a < b) ; (c < d) ; (a < c)
  // Therefore a < b, c, d : a is not the median
  if (m_link->cmp_ii(b, e))
    flip(&e, &b);  // (e < b) ; (c < d)
  if (m_link->cmp_ii(c, e)) {
    flip(&e, &c);
    flip(&b, &d);
  }  // (e < b) ; (c < d) ; (e < c) ;
  if (m_link->cmp_ii(c, b))
    flip(&b, &c);
  return b;
}

int Sorter::Qselect(int a, int b, int k) {
  if (b - a <= 1)
    return a;
  if (b - a == 2) {
    m_link->flip_ifn_cmp(a, a + 1);
    return a + k;
  }
  int pv = Median_partition(a + 1, b - 1);
  BREAKPOINT 0;
  if (a + k < pv) {
    return Qselect(a, pv, k);
  } else {
    return Qselect(pv, b, k - pv + a);
  }
}

int Sorter::Median_of_medians(int a, int b) {
  if (b - a <= 1) {
    return a;
  }
  int j = a;
  for (int i = a; i < b - 5; i += 5) {
    BREAKPOINT 0;
    m_link->flip(j++, Median_of_5(i));
  }
  m_link->flip(b - 1, j++);
  return Qselect(a, j, (j - a) / 2);
}

int Sorter::Median_partition(int a, int b) {
  //    printf("MeP : %d %d\n", a, b) ;
  // Edge cases
  if (b - a <= 1) {
    return a;
  } else if (b - a == 2) {
    if (m_link->cmp_ii(a + 1, a)) {
      m_link->flip(a, a + 1);
    }
    m_link->solved(a + 1);
    return a;
  } else if (b - a < 6) {
    return Middle_partition(a, b);
  }
  int pv = Median_of_medians(a, b);
  BREAKPOINT 0;
  m_link->flip(pv, a);
  pv = a;
  item* pvVal = m_link->send(pv);
  int i = a, j = b;
  for (;;) {
    do {
      BREAKPOINT 0;
      j--;
    } while ((i < j) && !m_link->cmp_ie(j, pvVal));
    do {
      BREAKPOINT 0;
      i++;
    } while ((i < j) && m_link->cmp_ie(i, pvVal));
    if (i < j) {
      m_link->flip(i, j);
    } else {
      m_link->flip(pv, j);
      return j;
    }
  }
}

// ////////// //
// MERGE-TYPE //
// ////////// //

void Sorter::Mergesort_standard() {
  item* tab[m_size];
  Mergesort(0, m_size, tab);
  for (int i = 0; i < m_size; i++) {
    BREAKPOINT;
    m_link->solved(i);
  }
}

void Sorter::Mergesort_pack() {
  item* tab[m_size];
  for (int d = 1; d < m_size; d <<= 1) {
    for (int i = 0; i + d < m_size; i += 2 * d) {
      BREAKPOINT;
      merge(i, i + d, i + 2 * d, tab);
    }
  }
  for (int i = 0; i < m_size; i++) {
    BREAKPOINT;
    m_link->solved(i);
  }
}

void Sorter::Mergesort_weave() {
  item* tab[m_size];
  Weavesort(0, m_size, tab);
  for (int i = 0; i < m_size; i++) {
    BREAKPOINT;
    m_link->solved(i);
  }
}

void Sorter::Weavesort(int a, int b, item* tab[]) {
  if (b - a < 2)
    return;
  int m = (a + b) / 2;
  Weavesort(a, m, tab);
  BREAKPOINT;
  Weavesort(m, b, tab);
  BREAKPOINT;
  weave(a, m, b, tab);
  BREAKPOINT;
  LocalInsertSort(a, b);
}

void Sorter::Mergesort(int a, int b, item* tab[]) {
  if (b - a < 2)
    return;
  int m = (a + b) / 2;
  Mergesort(a, m, tab);
  BREAKPOINT;
  Mergesort(m, b, tab);
  BREAKPOINT;
  merge(a, m, b, tab);
}

void Sorter::merge(int a, int b, int c, item* tab[]) {
  int i = a, j = b, k = 0;
  while ((i < b) && (j < c) && (j < m_size)) {
    BREAKPOINT;
    if (m_link->cmp_ii(i, j)) {
      tab[a + k++] = m_link->send(i++);
    } else {
      tab[a + k++] = m_link->send(j++);
    }
  }
  while ((i < b) && (i < m_size)) {
    BREAKPOINT;
    tab[a + k++] = m_link->send(i++);
  }
  for (int h = a; h < j; h++) {
    BREAKPOINT;
    m_link->receive(h, tab[h]);
    m_link->tmpsolve(h);
  }
  for (int h = j; (h < c) && (h < m_size); h++) {
    BREAKPOINT;
    m_link->tmpsolve(h);
  }
}

void Sorter::weave(int a, int b, int c, item* tab[]) {
  int i = a, j = b, k = 0;
  while ((i < b) && (j < c) && (j < m_size)) {
    BREAKPOINT;
    tab[a + k++] = m_link->send(i++);
    tab[a + k++] = m_link->send(j++);
  }
  while ((i < b) && (i < m_size)) {
    BREAKPOINT;
    tab[a + k++] = m_link->send(i++);
  }
  for (int h = a; h < j; h++) {
    BREAKPOINT;
    m_link->receive(h, tab[h]);
    m_link->tmpsolve(h);
  }
}

void Sorter::LocalInsertSort(int beg, int end) {
  for (int i = beg; i < end; i++) {
    int j = i;
    while ((j > beg) && (m_link->cmp_ii(j, j - 1))) {
      BREAKPOINT;
      m_link->flip(j, j - 1);
      m_link->tmpsolve(j);
      j--;
    }
    m_link->tmpsolve(j);
    if (j > beg)
      m_link->tmpsolve(j - 1);
  }
}

// ///////// //
// HEAP-TYPE //
// ///////// //

void Sorter::Reheapify_max(int i, int end) {
  int lt = 2 * i + 1;
  if (lt >= end) {
    return;
  }
  int maxson = lt;
  if ((lt < end - 1) && m_link->cmp_ii(lt, lt + 1)) {
    maxson++;
  }
  m_link->setBinHeapLv(lt);
  if (lt < end - 1)
    m_link->setBinHeapLv(lt + 1);
  if (m_link->cmp_ii(i, maxson)) {
    m_link->flip(i, maxson);
    m_link->setBinHeapLv(i);
    m_link->setBinHeapLv(maxson);
    BREAKPOINT;
    Reheapify_max(maxson, end);
  } else {
    m_link->setBinHeapLv(i);
    m_link->setBinHeapLv(maxson);
  }
}

void Sorter::Reheapify_sift(int i) {
  if (i == 0)
    return;
  int father = (i - 1) / 2;
  if (m_link->cmp_ii(father, i)) {
    BREAKPOINT;
    m_link->flip(i, father);
    m_link->setBinHeapLv(i);
    m_link->setBinHeapLv(father);
    Reheapify_sift(father);
  } else {
    m_link->setBinHeapLv(i);
    m_link->setBinHeapLv(father);
  }
}

void Sorter::Reheapify_min(int i, int end) {
  int lt = 2 * i + 1;
  if (lt >= end) {
    return;
  }
  int maxson = lt;
  if ((lt < end - 1) && m_link->cmp_ii(lt + 1, lt)) {
    maxson++;
  }
  m_link->setBinHeapLv(lt);
  if (lt < end - 1)
    m_link->setBinHeapLv(lt + 1);
  if (m_link->cmp_ii(maxson, i)) {
    m_link->flip(i, maxson);
    m_link->setBinHeapLv(i);
    m_link->setBinHeapLv(maxson);
    BREAKPOINT;
    Reheapify_min(maxson, end);
  } else {
    m_link->setBinHeapLv(i);
    m_link->setBinHeapLv(maxson);
  }
}

void Sorter::Reheapify_tern(int i, int end) {
  int lt = 3 * i + 1;
  if (lt >= end) {
    return;
  }
  int maxson = lt;
  if ((lt < end - 1) && m_link->cmp_ii(lt, lt + 1)) {
    maxson = lt + 1;
  }
  if ((lt < end - 2) && m_link->cmp_ii(maxson, lt + 2)) {
    maxson = lt + 2;
  }
  m_link->setTerHeapLv(lt);
  if (lt < end - 1)
    m_link->setTerHeapLv(lt + 1);
  if (lt < end - 2)
    m_link->setTerHeapLv(lt + 2);
  if (m_link->cmp_ii(i, maxson)) {
    m_link->flip(i, maxson);
    m_link->setTerHeapLv(i);
    m_link->setTerHeapLv(maxson);
    BREAKPOINT;
    Reheapify_tern(maxson, end);
  } else {
    m_link->setTerHeapLv(i);
    m_link->setTerHeapLv(maxson);
  }
}

void Sorter::Heapsort_max() {
  for (int i = m_size / 2 + 1; i >= 0; i--) {
    BREAKPOINT;
    Reheapify_max(i, m_size);
  }
  for (int i = m_size - 1; i >= 0; i--) {
    BREAKPOINT;
    m_link->flip(i, 0);
    m_link->solved(i);
    Reheapify_max(0, i);
    BREAKPOINT;
  }
}

void Sorter::Heapsort_sift() {
  for (int i = 0; i < m_size; i++) {
    BREAKPOINT;
    Reheapify_sift(i);
  }
  for (int i = m_size - 1; i >= 0; i--) {
    BREAKPOINT;
    m_link->flip(i, 0);
    m_link->solved(i);
    Reheapify_max(0, i);
    BREAKPOINT;
  }
}

void Sorter::Heapsort_min() {
  for (int i = m_size / 2 + 1; i >= 0; i--) {
    BREAKPOINT;
    Reheapify_min(i, m_size);
  }
  for (int i = m_size - 1; i >= 0; i--) {
    BREAKPOINT;
    m_link->flip(i, 0);
    m_link->tmpsolve(i);
    Reheapify_min(0, i);
    BREAKPOINT;
  }
  for (int i = 0; i < m_size / 2; i++) {
    BREAKPOINT;
    m_link->flip(i, m_size - 1 - i);
    m_link->solved(i);
    m_link->solved(m_size - 1 - i);
  }
  //m_link->solved(m_size/2+1) ;
}

void Sorter::Heapsort_tern() {
  for (int i = m_size / 3 + 2; i >= 0; i--) {
    BREAKPOINT;
    Reheapify_tern(i, m_size);
  }
  for (int i = m_size - 1; i >= 0; i--) {
    BREAKPOINT;
    m_link->flip(i, 0);
    m_link->solved(i);
    Reheapify_tern(0, i);
    BREAKPOINT;
  }
}

void Sorter::Interpolation(item* arr[]) {
  item buff;
  for (int i = 0; i < m_size; ++i) {
    arr[i] = m_link->send(i);
  }
  int min = arr[0]->val;
  int max = arr[0]->val;
  for (int i = 0; i < m_size; ++i) {
      if (arr[i]->val > max){
          max = arr[i]->val;
      }
      if (arr[i]->val < min){
          min = arr[i]->val;
      }
  }
  qDebug () << max;
  qDebug () << min;
  float avg = (max - min) / static_cast<float>(m_size);
  for (int i = 0; i < m_size; ++i) {
    buff.place = i;
    buff.val = i * avg;
    m_link->receive(i, &buff);
    m_link->solved(i);
  }
}

void Sorter::InterpolationSort() {
  item* arr[m_size];
  Interpolation(arr);
}
