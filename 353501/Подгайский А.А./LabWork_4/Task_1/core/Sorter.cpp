#include "Sorter.h"
#include "SVector.h"
#include <QDebug>
#include <exception>
#include <QApplication>

bool Sorter::_terminated = false;

void Sorter::MergeSort(SVector& vect) {
    _mergeSort(vect, 0, vect.size());
}

void Sorter::_mergeSort(SVector& vect, size_t beg, size_t end) {
    if(end - beg <= 1){
        return;
    }

    auto mid = beg + (end - beg)/2;
    auto left_sz = mid - beg;
    auto right_sz = end - mid;

    // deal: including beg, not including end
    _mergeSort(vect, beg, mid);
    _mergeSort(vect, mid, end); 

    if(_terminated){
        qApp->quit();
    }
    
    SVector left;
    left.resize(left_sz);
    for(int i = beg, j = 0; i < mid; ++i, ++j){
        left[j] = vect[i];
    }

    SVector right;
    right.resize(right_sz);
    for(int i = mid, j = 0; i < end; ++i, ++j){
        right[j] = vect[i];
    }
    
    if(_terminated){
        qApp->quit();
    }

    size_t l_i = 0;
    size_t r_i = 0;
    size_t i = beg;
    while(l_i < left_sz && r_i < right_sz){
        if(left[l_i] < right[r_i]){
            vect.sigSet(i, left[l_i]);
            ++l_i;
        } else {
            vect.sigSet(i, right[r_i]);
            ++r_i;
        }
        ++i;
    }

    while(l_i < left_sz){
        vect.sigSet(i, left[l_i]);
        ++l_i; ++i;
    }
    while(r_i < right_sz){
        vect.sigSet(i,right[r_i]);
        ++r_i; ++i;
    }
}

void Sorter::HeapSort(SVector& vect) {
    _build_heap(vect, vect.size());

    auto sz = vect.size();
    for(int i = 0; i < vect.size(); ++i){
        vect.sigSwap(0,sz-i-1);
        _heapify(vect, 0, sz-i-1);
        if(_terminated){
            qApp->quit();
        }
    }
    
}

void Sorter::_build_heap(SVector& vect, size_t last){
    size_t nonleaf = last/2;
    for(int i = nonleaf; i >= 0; --i){
        _heapify(vect, i, last);
    }
}

void Sorter::_heapify(SVector& vect, size_t root, size_t last) {
    auto left = 2*root + 1;
    auto right = 2*root + 2;

    auto max = root;

    if(left < last && vect[left] > vect[max]){
        max = left;
    } 

    if(right < last && vect[right] > vect[max]){
        max = right;
    }

    if(max != root){
         vect.sigSwap(root, max);
         _heapify(vect, max, last);
    }
}

void Sorter::_quickSort(SVector& vect, size_t beg, size_t end){
    if(beg < end){
        auto piv = (beg + end)/2;
        auto new_piv = _partition(vect, beg, end);
        _quickSort(vect, beg, new_piv);
        _quickSort(vect, new_piv+1, end);
        if(_terminated){
            qApp->quit();
        }
    }
}

// size_t Sorter::_partition_SVector& vect, size_t beg, size_t end){
//     size_t l = beg;
//     size_t r = end-1;
//     while(l <= r){
//         while(vect[l] < vect[piv]){
//             ++l;
//         }
//         while(vect[r] > vect[piv]){
//             --r;
//         }
//         if(l >= r){
//             break;
//         }
//         vect.sigSwap(l, r);
//         ++l; --r;
//     }
//     return r;
// }

size_t Sorter::_partition(SVector& vect, size_t beg, size_t end){
    auto piv = end-1;
    long less_than_piv = beg - 1;
    for(long i = beg; i < end; ++i){
        if(vect[i] < vect[piv]){
            vect.sigSwap(++less_than_piv, i);
        }
    }
    vect.sigSwap(++less_than_piv, piv);
    return less_than_piv;
}

void Sorter::QuickSort(SVector& vect) {
    _quickSort(vect, 0, vect.size());

}

void Sorter::Terminate() { 
    _terminated = true;   
}
