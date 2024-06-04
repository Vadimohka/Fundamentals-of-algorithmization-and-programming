#include "median.h"

Median::Median(QVector<int> input)
    : arr(input)
{}

QVector<double> Median::findMedian()
{
    QVector<double> ans;
    int midVal{};
    int minVal{};
    qDebug() << arr;
    for (int i = 0; i < arr.size(); i += 3) {
        if (arr.size() - i < 3) {
            ans.push_back(static_cast<double>(arr[i] + arr[arr.size() - 1]) / 2);
        } else {
            minVal = arr[i];
            midVal = arr[i + 1];
            if (minVal > midVal) {
                int temp = minVal;
                minVal = midVal;
                midVal = temp;
            }
            if (arr[i + 2] < minVal) {
                midVal = minVal;
                minVal = arr[i + 2];
            }
            ans.push_back(midVal);
        }
    }
    qDebug() << ans;
    return ans;
}
