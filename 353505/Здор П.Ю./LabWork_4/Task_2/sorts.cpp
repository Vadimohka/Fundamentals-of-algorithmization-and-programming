#include "sorts.h"

int SortS::partition( double *a,int low, int high, double pivot){
    i1 = low;
    j1 = low;
    while( i1 <= high){
        if(a[i1] > pivot){
            i1++;
        }
        else{
            std::swap(a[i1],a[j1]);




            i1++;
            j1++;
        }

    }

    return j1-1;
}
void SortS::sorting_q(double *a,int left,int right){

    if(left < right){
        double pvt = a[right];
        int pos = partition(a,left, right, pvt);
        // graphicsView->viewport()->repaint();

        sorting_q(a, left, pos-1);

        sorting_q(a, pos+1, right);


    }


}
