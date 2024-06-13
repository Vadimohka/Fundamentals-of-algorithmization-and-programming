#include <QApplication>
#include <QVector>
#include <QRandomGenerator>
#include <algorithm>
#include<magicnumbers.h>
int main()
{
    QVector<int> numbers(SIZE);
    QVector<int> medians;

    for(auto& i : numbers){
        i  = QRandomGenerator::global()->bounded(0, MAX_ELEMENT);
    }

    for(int i = 0; i < numbers.size(); i += 3){
        if(i + 2 < numbers.size()) {
            QVector<int> trio = {numbers[i], numbers[i+1], numbers[i+2]};
            std::sort(trio.begin(), trio.end());
            medians.push_back(trio[1]);
        } else {
            int sum = 0;
            int count = 0;
            for(int j = i; j < numbers.size(); ++j) {
                sum += numbers[j];
                ++count;
            }
            medians.push_back(sum / count);
        }
    }

    for(auto i: medians){
        qDebug() << i;
    }
}
