#include <QString>

class KidToy
{
public:
    KidToy();
    int GetAgeCar(){ return toy.AgeCategory;}
    void SetAgeCar(int Age){ toy.AgeCategory = Age;}

    double GetPrice(){return toy.Price;}
    void SetPrice(double pr){ toy.Price = pr;}

    QChar GetMaterial(){ return toy.Material;}
    void SetMaterial(QChar mat) {toy.Material = mat; }

    bool GetSafety(){ return toy.Safety;}
    void SetSafety(bool saf){ toy.Safety = saf;}

    QString GetName(){ return toy.Name;}
    void SetName(QString name) { toy.Name = name;}

    long long GetComment(int ind){ return toy.Comments[ind];}
    void SetComment(int ind, long long val){ toy.Comments[ind] = val;}

    QString generateReport();

private:
    struct TOY
    {
        int AgeCategory; 
        double Price;
        QChar Material;
        bool Safety;
        QString Name;
        long long Comments[2];
    };
    TOY toy;
    

};