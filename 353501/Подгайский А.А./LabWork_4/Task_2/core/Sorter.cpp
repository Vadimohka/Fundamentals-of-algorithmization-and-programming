
#include "Sorter.h"
#include "SVector.h"
#include <climits>
#include <cstddef>

void Sorter::InterpSort(SVector& vect) {
    _interpSort(vect, 0, vect.size());
}

std::pair<size_t, size_t> Sorter::_findMinMax(SVector& vect, size_t beg, size_t end) {
    size_t max_i = 0;
    size_t min_i = 0;
    auto sz = vect.size();
    for(int i = beg; i < end; ++i){
        if(vect[i] < vect[min_i]){
            min_i = i;
        }
        if(vect[i] > vect[max_i]){
            max_i = i;
        }
    } 
    return {min_i, max_i};
}

// // deal: not including end
// void Sorter::_interpSort(SVector& vect, size_t beg, size_t end) {
//     if(end - beg <= 1){
//         return;
//     }

//     auto sz = end - beg;
//     QVector<long> indices(sz);
//     SVector tmp_vect(vect);
//     QVector<bucket> buckets;

//     size_t min, max;
//     {
//         auto minmax = _findMinMax(tmp_vect, beg, end);
//         min = minmax.first;
//         max = minmax.second;
//     }


//     for(int i = 0; i < sz; ++i){
//         if(tmp_vect[max] - tmp_vect[min] == 0){
//             return;
//         }

//         auto ind = (sz - 1) * (tmp_vect[i] - tmp_vect[min]) / (tmp_vect[max] - tmp_vect[min]);
//         indices[i] = ind;

//         if(buckets.size() <= ind){
//             buckets.resize(ind+1);
//         }
//         buckets[ind].sz++;
//     }


//     { // Set buckets start indices
//         auto buck_ind = 0;
//         for(int i = 0; i < buckets.size(); ++i){
//             buckets[i].start = buck_ind;
//             buck_ind += buckets[i].sz; 
//         }
//     }
    


//     for(int i = 0; i < sz; ++i){
//         auto buck_ind = indices[i];
//         auto vect_ind = buckets[buck_ind].start + buckets[buck_ind].cur;
//         vect.sigSet(vect_ind, tmp_vect[i]);
//         buckets[buck_ind].cur++;
//     }


//     for(int i = 0; i < buckets.size(); ++i){
//         _interpSort(vect, buckets[i].start, buckets[i].start + buckets[i].sz);
//     }
// }

void Sorter::_interpSort(SVector& vect, size_t beg, size_t end) {
    if(end - beg <= 1){
        return;
    }

    auto sz = end - beg;
    QVector<long> indices(sz);
    SVector tmp_vect(vect, beg, end);
    QVector<bucket> buckets;

    size_t min, max;
    {
        auto minmax = _findMinMax(tmp_vect, 0, sz);
        min = minmax.first;
        max = minmax.second;
    }


    for(int i = 0; i < sz; ++i){
        if(tmp_vect[max] - tmp_vect[min] == 0){
            return;
        }

        auto ind = (sz - 1) * (tmp_vect[i] - tmp_vect[min]) / (tmp_vect[max] - tmp_vect[min]);
        indices[i] = ind;

        if(buckets.size() <= ind){
            buckets.resize(ind+1);
        }
        buckets[ind].sz++;
    }


    { // Set buckets start indices
        auto buck_ind = 0;
        for(int i = 0; i < buckets.size(); ++i){
            buckets[i].start = buck_ind;
            buck_ind += buckets[i].sz; 
        }
    }
    
    for(int i = 0; i < sz; ++i){
        auto buck_ind = indices[i];
        auto vect_ind = buckets[buck_ind].start + buckets[buck_ind].cur;
        vect.sigSet(beg + vect_ind, tmp_vect[i]);
        buckets[buck_ind].cur++;
    }

    for(int i = 0; i < buckets.size(); ++i){
        _interpSort(vect, beg + buckets[i].start, beg + buckets[i].start + buckets[i].sz);
    }
}
