#include "tobinary.h"
#include <cmath>

QString ToBinary::get_first_bit(QChar a) {
    if(a=='-') return "1";
    else return "0";
}
double ToBinary::get_exp1(double tt){
    if(tt<=1 && tt>=0.1) return 0;
    else {
        return 1+get_exp1(tt/10.0);
    }
}
double ToBinary::get_exp2(double tt){
    if(tt<=1 && tt>=0.1 || tt==0) return 0;
    else {
        return +1+get_exp2(tt*10.0);
    }
}
double ToBinary::get_normalized(double tt){
    if(tt<10) return tt;
    else {
        exp++;
        return get_normalized(tt/10);
    }

}
double ToBinary::get_normalized1(double tt){
    if(tt>=1) return tt;
    else{
        exp--;
        return get_normalized1(tt*10);
    }

}

QString ToBinary::convert_ch(double k){
    if(k==0) return "";
    else{


        if(sch>51) {
            fl1=0;
            sch=0;
            exp=0;
            return "";
        }
        else {
        if(k*2>1){
            sch++;
            return "1"+convert_ch(2*k-1);
        }
        else {

                sch++;
                return "0"+convert_ch(2*k);
        }
        }
    }

}
QString ToBinary::convert_c(double k){
    if(k==0) {

        return "";
    }
    else{
        if(std::abs(k)>=1 && (int)k==k){
            if(floor(std::abs(k)/2)*2==std::abs(k)){
                return "0"+convert_c(floor(k/2));
            }
            else {
                return "1"+convert_c(floor(k/2));
            }



        }
    }
}
