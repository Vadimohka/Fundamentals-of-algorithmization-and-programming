#ifndef DECIMALTOBINARY_H
#define DECIMALTOBINARY_H

#include <QObject>
#include <QString>

class DecimalToBinary : public QObject
{
    Q_OBJECT
public:
    explicit DecimalToBinary(QObject *parent = nullptr);

    QString convert(const QString& decimal);

signals:
    void binaryResult(const QString& binary);

private:
    QString convertIntegerPart(int intPart, int fractionalPart);
    QString convertFractionalPart(double fractionalPart, int maxFractionalDigits);
};

#endif // DECIMALTOBINARY_H
