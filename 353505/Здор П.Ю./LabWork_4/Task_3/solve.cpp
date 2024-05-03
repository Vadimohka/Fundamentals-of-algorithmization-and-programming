#include "solve.h"


int solve::partition( QVector<double> a,int low, int high, double pivot){
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
void solve::sorting_q(QVector<double>a,int left,int right){

    if(left < right){
        double pvt = a[right];
        int pos = partition(a,left, right, pvt);

        sorting_q(a, left, pos-1);

        sorting_q(a, pos+1, right);


    }


}
void solve::solution(){
    for(int i=0;i<100;++i){
        a.push_back((powf(2,(10*i+1+i)%7))*3);
    }
    for(int i=0;i<100; i+=3){
        if(i!=99)
        sorting_q(a,i,i+2);
        if(i==99){
            qDebug() << a[i];
        }
        else {
            qDebug() << a[i+1];
        }
    }
}
