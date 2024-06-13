#ifndef CAR_H
#define CAR_H
#include <QString>
class Car
{
public:
    Car();

    QString getCountry() const;
    void setCountry(const QString &newCountry);

    QString getMark() const;
    void setMark(const QString &newMark);

    QString getEngineType() const;
    void setEngineType(const QString &newEngineType);

    int getPrice() const;
    void setPrice(int newPrice);

    int getGasolineSpend() const;
    void setGasolineSpend(int newGasolineSpend);

    int getReliability() const;
    void setReliability(int newReliability);

    int getComfortability() const;
    void setComfortability(int newComfortability);

    QString getModel() const;
    void setModel(const QString &newModel);

private:
    QString model;
    QString country;
    QString mark;
    QString engineType;
    int price;
    int gasolineSpend;
    int reliability;
    int comfortability;


};

#endif // CAR_H
