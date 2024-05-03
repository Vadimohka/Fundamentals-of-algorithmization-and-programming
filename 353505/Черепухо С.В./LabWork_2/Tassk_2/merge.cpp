#include "bibl.h"
template<typename T>
void merge_sort(T array[], size_t size, bool(*cmp) (const T&, const T&))
{
    if (size > 1)
       {
           size_t const left_size = size / 2;
           size_t const right_size = size - left_size;
           merge_sort(&array[0], left_size, cmp);
           merge_sort(&array[left_size], right_size, cmp);
           size_t lidx = 0, ridx = left_size, idx = 0;
           T* tmp_array(new T[size]);
           while (lidx < left_size or ridx < size)
           {
               if (cmp(array[lidx], array[ridx]))
               {
                   tmp_array[idx++] = move(array[lidx]);
                   lidx++;
               }
               else
               {
                   tmp_array[idx++] = move(array[ridx]);
                   ridx++;
               }
               if (lidx == left_size)
               {
                   copy(make_move_iterator(&array[ridx]), make_move_iterator(&array[size]), &tmp_array[idx]);
                   break;
               }
               if (ridx == size)
               {
                   copy(make_move_iterator(&array[lidx]), make_move_iterator(&array[left_size]), &tmp_array[idx]);
                   break;
               }
           }
            copy(make_move_iterator(tmp_array), make_move_iterator(&tmp_array[size]), array);
    }

}
