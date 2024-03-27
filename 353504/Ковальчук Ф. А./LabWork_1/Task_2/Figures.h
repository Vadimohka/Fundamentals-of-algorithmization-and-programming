#ifndef FIGURES_H
#define FIGURES_H
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <math.h>
#include <QDebug>

class IFigure{
    friend class MainWindow;

public:
    virtual void Clear();
    virtual void UpdateMassCentre();
    virtual void CalcPerimetr();
    virtual void CalcSquare();

    virtual void Translate(float deltaX, float deltaY);
    virtual void Rotate(float delta);
    virtual void Scale(bool isNegative);

    virtual void Draw(QPainter* painter) = 0;
    virtual void MouseEvent(QMouseEvent *mouseEvent) = 0;
protected:
    QPointF m_centre;
    QVector<QPointF> m_points;

    float m_perimetr;
    float m_square;

    float m_scale = 1.0f;
};

class Triangle : public IFigure{
public:
    void Draw(QPainter* painter) override;
    void MouseEvent(QMouseEvent *mouseEvent) override;

    void SetPoint(QMouseEvent* mouseEvent);
};

class Circle : public IFigure{
public:
    void MouseEvent(QMouseEvent *mouseEvent) override;
    void Draw(QPainter* painter) override;

    void CalcPerimetr() override;
    void CalcSquare() override;
    void SetPoint(QMouseEvent* mouseEvent);

    void Scale(bool isNegative) override;

private:
    float m_radius = 0.0f;
    bool m_isInitCenter = false;
};


class Rhomb : public IFigure{
public:
    void MouseEvent(QMouseEvent *mouseEvent) override;
    void SetPoint(QMouseEvent* mouseEvent);

    void Draw(QPainter* painter) override;

    void CalcPerimetr() override;
    void CalcSquare() override;

private:
    bool m_isInitCenter = false;
};


class Rect : public IFigure{
    void MouseEvent(QMouseEvent *mouseEvent) override;
    void SetPoint(QMouseEvent* mouseEvent);

    void Draw(QPainter* painter) override;

    void CalcPerimetr() override;
    void CalcSquare() override;

private:
    float m_a;
    float m_b;

    bool m_isInitCenter = false;
};

class Scuare : public IFigure{
    void MouseEvent(QMouseEvent *mouseEvent) override;
    void SetPoint(QMouseEvent* mouseEvent);

    void Draw(QPainter* painter) override;

    void CalcPerimetr() override;
    void CalcSquare() override;

private:
    float m_a;

    bool m_isInitCenter = false;
};

class NStar : public IFigure{
    void MouseEvent(QMouseEvent *mouseEvent) override;
    void SetPoint(QMouseEvent* mouseEvent);

    void Draw(QPainter* painter) override;

public:
    int m_numAngles;
    bool m_isInitCenter = false;
};


#endif // FIGURES_H
