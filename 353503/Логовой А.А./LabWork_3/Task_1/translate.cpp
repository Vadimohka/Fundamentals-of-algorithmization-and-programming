#include <translate.h>
#include <algorithm>

void signNum(double &num, QString &string){
    if(num<0){
        num*=-1;
        string += "1       ";
    }
    else{
         string += "0       ";
    }

}
void fracSecond(double frac, QString &string, int precision){
    if (precision == 0 || frac == 0.0) {
        return;
    }
    else {
        frac *= 2;
        int bit = int(frac);
        if (bit == 1) {
            frac -= bit;
            string += '1';
        }
        else {
            string += '0';
        }
        fracSecond(frac, string, precision - 1);
    }
}

void intSecond(double number, QString& string) {
    if (int(number) == 0) {
        std::reverse(string.begin(), string.end());
    }
    else {
        if (int(number) % 2 == 0){
            string += '0';
        }
        else if (int(number) % 2 == 1){
            string += '1';
        }
        intSecond(number / 2, string);
    }
}
