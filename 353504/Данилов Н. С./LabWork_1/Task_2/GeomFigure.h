#pragma once
#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QVector>
class GeomFigure
{
private:
    
public:
    GeomFigure(/* args */);
    virtual void Draw(QPainter *pr);
    virtual void SetCenter(int, int);
    virtual void CountCenter();
    virtual void SetWidth(int);
    virtual void SetHeight(int);
    int GetWidth();
    int GetHeight();
    virtual void Rotate(double);
    virtual void Resize(bool);
    QVector<QPointF> GetPolyg();
    void SetPolyg(QVector<QPointF>);
    QPointF GetCenter();
    int GetCountOfAngles();
    double GetS();
    double GetP();
    virtual void CountS();
    virtual void CountP();
    void PlusAng();
protected:
    int countofangles;
    QPointF center;
    int a, b;
    double S, P;
    QVector<QPointF> angles;    
};

