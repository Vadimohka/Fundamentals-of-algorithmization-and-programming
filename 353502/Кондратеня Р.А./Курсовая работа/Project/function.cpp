#include "function.h"

long double Function::sumFunction(const QList<double> &values)
{
    double result = 0;
    for (double value : values) {
        result += value;
    }
    return result;
}

long double Function::multFunction(const QList<double> &values)
{
    long double result = 1;
    for (long double value : values) {
        result *= value;
    }
    return result;
}

QVector<long long> Function::randomFunction(int n)
{
    QVector<long long> values;
    Random64 random;
    for(int i = 0; i < n; i++)
    {
        long long result = random(0, 1000);
        values.push_back(result);
    }

    return values;
}

long double Function::averageFunction(const QList<double> &values)
{
    long double result = sumFunction(values);
    long count = values.size();
    return result / count;
}

QString Function::getFunction()
{
    return nameOfFunction;
}

void Function::setFunction(QString newName)
{
    nameOfFunction = newName;
}
