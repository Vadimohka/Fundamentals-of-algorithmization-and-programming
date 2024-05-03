#include "reversive.h"
bool reversive::check(int k){
    if(k!=0 && k%10==0) return false;

    else if(k!=0){
        return check(k/10);
    }
    return true;
}
int reversive::reverse(int k) {
    if(!check(k) && !fl1) {
        return 0;
        fl1=0;
    }
    else if(k!=0){
        fl1=1;
        return (k%10)*pow(10,(int)log10(std::abs(k)))+reverse(k/10);
    }
    else {
         fl1=0;
        return 0;
    }
}


