#include "sorter.h"

//void Sorter::merge(QVector<float>& palki, QVector<float>& left, int leftSize, QVector<float>& right, int rightSize) {
 //   int i = 0;
//    int j = 0;
 //   int k = 0;
//    while (i < leftSize && j < rightSize) {
 //       if (left[i] <= right[j]){
 //           palki[k++] = left[i++];
 //       }
 //       else{
 //           palki[k++] = right[j++];
 //       }
 //   }
   // while (i < leftSize){
   //     palki[k++] = left[i++];
   // }
   // while (j < rightSize){
   //     palki[k++] = right[j++];
   // }
  //  emit updatesignal();
//}
//void Sorter::mergeSort(QVector<float>& palki) {
  //  int size = palki.size();
   // if (size < 2) return;
  //  int mid = size / 2;
  ///  QVector<float> left(mid);
   // QVector<float> right(size - mid);
//
   // for (int i = 0; i < mid; ++i){
  //      left[i] = palki[i];
 //   }
//    for (int i = mid; i < size; ++i){
//        right[i - mid] = palki[i];
 //   }
   // mergeSort(left);
   // mergeSort(right);

   // merge(palki, left, mid, right, size - mid);
//}
void Sorter::mergeSort(QVector<float>& palki, int low, int high) {
    if (high == -100)
        high = palki.size() - 1;

    if (low >= high)
        return;
    if (high - low == 1) {
        if (palki[low] > palki[high]) {
            std::swap(palki[low], palki[high]);
            emit updatesignal();
        }
        return;
    }

    int mid = (high + low) / 2;
    mergeSort(palki, low, mid);
    mergeSort(palki, mid + 1, high);

    QVector<float> tempVal;
    int lp = low;
    int rp = mid + 1;

    while (lp <= mid && rp <= high) {
        float lv = palki[lp];
        float rv = palki[rp];
        if (lv < rv) {
            tempVal.push_back(lv);
            lp++;
        } else {
            tempVal.push_back(rv);
            rp++;
        }
    }

    while (lp <= mid) {
        tempVal.push_back(palki[lp++]);
    }

    while (rp <= high) {
        tempVal.push_back(palki[rp++]);
    }

    for (int i = 0; i < tempVal.count(); i++) {
        palki[low + i] = tempVal[i];
        emit updatesignal();
    }
}
int Sorter::partition(QVector<float>& palki, int low, int high) {
    int pivot = palki[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (palki[j] <= pivot) {
            ++i;
            palki.swapItemsAt(i, j);
            emit updatesignal();
        }
    }

    palki.swapItemsAt(i + 1, high);
    emit updatesignal();
    return i + 1;
}

void Sorter::quickSort(QVector<float>& palki, int low, int high) {
    if (low < high) {
        int pi = partition(palki, low, high);

        quickSort(palki, low, pi - 1);
        quickSort(palki, pi + 1, high);
    }
}

void Sorter::heapify(QVector<float>& palki, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && palki[left] > palki[largest])
        largest = left;

    if (right < size && palki[right] > palki[largest])
        largest = right;

    if (largest != root) {
        palki.swapItemsAt(root, largest);
        emit updatesignal();
        heapify(palki, size, largest);
    }
}

void Sorter::heapSort(QVector<float>& palki) {
    int size = palki.size();

    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(palki, size, i);

    for (int i = size - 1; i > 0; --i) {
        palki.swapItemsAt(0, i);
        emit updatesignal();
        heapify(palki, i, 0);
    }
}

void Sorter::bubbleSort(QVector<float>& palki) {
    int size = palki.size();

    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            if (palki[j] > palki[j + 1]) {
                palki.swapItemsAt(j, j + 1);
                emit updatesignal();
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int Sorter::BinarySearch(QVector<float> &palki, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (palki[mid] == x)
            return mid;

        if (palki[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
void Sorter::interpolationSort(QVector<float>& palki, int low, int high) {
    if (high == -100)
        high = palki.size() - 1;

    if (high <= low)
        return;

    if (high - low == 1) {
        if (palki[low] > palki[high])
            std::swap(palki[low], palki[high]);
        emit updatesignal();
        return;
    }

    float min = std::numeric_limits<float>::max();
    float max = std::numeric_limits<float>::min();
    for (int i = low; i <= high; i++) {
        float el = palki[i];
        if (el < min)
            min = el;
        if (el > max)
            max = el;
    }

    if (qFuzzyCompare(min, max))
        return;

    QVector<QVector<float>> buckets;
    buckets.resize(high - low + 1);
    for (int i = low; i <= high; i++) {
        float el = palki[i];
        int bucket = static_cast<int>(((el - min) / (max - min)) * (buckets.size() - 1));
        buckets[bucket].push_back(el);
    }

    int curpos = low;
    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[i].empty())
            continue;
        int buckstart = curpos;

        for (const auto& e : buckets[i]) {
            palki[curpos++] = e;
            emit updatesignal();
        }
        interpolationSort(palki, buckstart, curpos - 1);
    }
}

Sorter::Sorter()
{

}
int Sorter::BinPow(int digit, int power, int mod) {
    if(power == 0) return 1;

    if(power % 2 == 1) {
        return digit * BinPow(digit, power - 1, mod) % mod;
    } else {
        int temp = BinPow(digit, power / 2, mod);
        return (temp * temp) % mod;
    }
}
