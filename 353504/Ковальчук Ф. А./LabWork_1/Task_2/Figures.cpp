#include "Figures.h"

void IFigure::Clear(){
    m_points.clear();
    m_centre = QPoint(0.0f, 0.0f);
    m_perimetr = 0.0f;
    m_square = 0.0f;
    m_scale = 1.0f;
}
void IFigure::UpdateMassCentre(){
    m_centre = QPoint(0.0f, 0.0f);
    for(int i = 0; i < m_points.size(); i++){
        m_centre += m_points[i];
    }
    m_centre /= m_points.size();
}
void IFigure::CalcPerimetr(){
    m_perimetr = 0;
    for(int i = 0; i < m_points.size() - 1; i++){
        float dX = m_points[i].x() - m_points[i+1].x();
        float dY = m_points[i].y() - m_points[i+1].y();
        m_perimetr += sqrt(dX * dX + dY * dY);
    }

    //connect last and first
    float dX = m_points[0].x() - m_points[m_points.size() - 1].x();
    float dY = m_points[0].y() - m_points[m_points.size() - 1].y();
    m_perimetr += sqrt(dX * dX + dY * dY);
}
void IFigure::CalcSquare(){
    m_square = 0.0f;

    if(m_points.size() >= 3){
        for(int i = 0; i < m_points.size() - 1; i++){
            m_square += m_points[i].x() * m_points[i + 1].y() - m_points[i].y() * m_points[i+1].x();
        }

        m_square += m_points[0].x() * m_points[m_points.size() - 1].y() - m_points[0].y() * m_points[m_points.size() - 1].x();
        m_square /= 2;
    }
}

void IFigure::Translate(float deltaX, float deltaY){
    for(int i = 0; i < m_points.size(); i++){
        m_points[i] -= QPointF(deltaX, deltaY);
    }
    m_centre -= QPointF(deltaX, deltaY);
}
void IFigure::Rotate(float delta){
    float sinA = std::sin(delta * 3.1415f / 180.0f);
    float cosA = std::cos(delta * 3.1415f / 180.0f);

    for(int i = 0; i < m_points.size(); i++){
        float localX = m_points[i].x() - m_centre.x();
        float localY = m_points[i].y() - m_centre.y();

        m_points[i] = QPointF(m_centre.x() + cosA * localX - sinA * localY,
                              m_centre.y() +  sinA * localX + cosA * localY);
    }
}
void IFigure::Scale(bool isNegative){
    float scale = m_scale;
    if(isNegative && m_scale > 0.0f){
        m_scale -= 0.01f;
    }
    else if(!isNegative){
        m_scale += 0.01f;
    }

    for(int i = 0; i < m_points.size(); i++){
        m_points[i] = m_centre + ((m_points[i] - m_centre) / scale * m_scale);
    }
    CalcPerimetr();
    CalcSquare();
}


void Triangle::Draw(QPainter* painter){
    if(m_points.size() == 0) return;
    QPolygonF polygonF;
    QPointF pointF;

    for(int i = 0; i < m_points.size(); i++){
        pointF = QPointF(m_points[i]);
        polygonF << pointF;
    }

    CalcPerimetr();
    CalcSquare();

    if(m_points.size() == 1) painter->drawPoint(pointF);
    else painter->drawPolygon(polygonF);
}
void Triangle::MouseEvent(QMouseEvent *mouseEvent){
    SetPoint(mouseEvent);
    UpdateMassCentre();

    CalcPerimetr();
    CalcSquare();
}

void Triangle::SetPoint(QMouseEvent* mouseEvent){
    if(m_points.size() >= 3) m_points.clear();

    m_points.push_back(mouseEvent->pos());
    if(m_points.size() == 3){
        m_centre = (m_points[0] + m_points[1] + m_points[2]) / 3;
        CalcPerimetr();
        CalcSquare();
    }
}


void Circle::MouseEvent(QMouseEvent *mouseEvent){
    SetPoint(mouseEvent);
}
void Circle::Draw(QPainter* painter){
    if(m_isInitCenter){
        QPen pen;
        pen.setColor(QColor("red"));
        pen.setWidth(5);
        painter->setPen(pen);
        painter->drawPoint(m_centre);
        //painter->drawPoint(m_points[0]);
    }
    if(m_points.size() == 0) return;

    //painter->drawEllipse(m_centre, m_points[0].x(), m_points[0].y());
    QPen pen;
    pen.setColor(QColor("black"));
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawPoint(m_points[0]);
    painter->drawEllipse(m_centre, m_radius, m_radius);
    pen.setColor(QColor("red"));
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawPoint(m_points[0]);
}

void Circle::CalcPerimetr(){
    m_perimetr = 2.0f * 3.1415f * m_radius;
}
void Circle::CalcSquare(){
    m_square = 3.1415f * m_radius * m_radius;
}
void Circle::SetPoint(QMouseEvent* mouseEvent){
    if(!m_isInitCenter){
        m_centre = mouseEvent->pos();
        m_isInitCenter = true;
    }
    else{
        if(m_points.size() == 0){
            m_points.push_back(mouseEvent->pos());
            float dX = m_centre.x() - m_points[0].x();
            float dY = m_centre.y() - m_points[0].y();
            m_radius = std::sqrt(dX * dX + dY * dY);

            CalcPerimetr();
            CalcSquare();

        }
        else{
            m_points.clear();
            m_centre = mouseEvent->pos();
        }
    }
}

void Circle::Scale(bool isNegative){
    float scale = m_scale;
    if(isNegative && m_scale > 0.0f){
        m_scale -= 0.01f;
    }
    else if(!isNegative){
        m_scale += 0.01f;
    }

    for(int i = 0; i < m_points.size(); i++){
        m_points[i] = m_centre + ((m_points[i] - m_centre) / scale * m_scale);
    }

    float dX = m_centre.x() - m_points[0].x();
    float dY = m_centre.y() - m_points[0].y();
    m_radius = std::sqrt(dX * dX + dY * dY);

    CalcPerimetr();
    CalcSquare();
}


void Rhomb::MouseEvent(QMouseEvent *mouseEvent){
    SetPoint(mouseEvent);
}
void Rhomb::SetPoint(QMouseEvent* mouseEvent){
    if(!m_isInitCenter){
        m_centre = mouseEvent->pos();
        m_isInitCenter = true;
    }
    else{
        if(m_points.size() != 4){
            float a = abs(mouseEvent->pos().x() - m_centre.x());
            float b = abs(mouseEvent->pos().y() - m_centre.y());
            m_points.push_back(m_centre + QPointF(a, 0));

            m_points.push_back(m_centre + QPointF(0, b));
            m_points.push_back(m_centre + QPointF(-a, 0));
            m_points.push_back(m_centre + QPointF(0, -b));
            //m_points.push_back(mouseEvent->pos());

            CalcPerimetr();
            CalcSquare();
        }
        else{
            m_points.clear();
            m_centre = mouseEvent->pos();
        }
    }
}

void Rhomb::Draw(QPainter* painter){
    if(m_points.size() != 4) return;
    painter->drawLine(m_points[0], m_points[1]);
    painter->drawLine(m_points[1], m_points[2]);
    painter->drawLine(m_points[2], m_points[3]);
    painter->drawLine(m_points[0], m_points[3]);
}

void Rhomb::CalcPerimetr(){
    float dX = m_points[0].x() - m_points[1].x();
    float dY = m_points[0].y() - m_points[1].y();
    m_perimetr = 4 * std::sqrt(dX * dX + dY * dY);
}
void Rhomb::CalcSquare(){
    float a = std::max(abs(m_points[0].x() - m_centre.x()), abs(m_points[0].y() - m_centre.y()));
    m_square = 2 * a * a;
}


void Rect::MouseEvent(QMouseEvent *mouseEvent){
    SetPoint(mouseEvent);
}
void Rect::SetPoint(QMouseEvent* mouseEvent){
    if(!m_isInitCenter){
        m_centre = mouseEvent->pos();
        m_isInitCenter = true;
    }
    else{
        if(m_points.size() != 4){
            float a = abs(mouseEvent->pos().x() - m_centre.x());
            float b = abs(mouseEvent->pos().y() - m_centre.y());
            m_a = a * 2;
            m_b = b * 2;
            m_points.push_back(m_centre + QPointF(-a, -b));

            m_points.push_back(m_centre + QPointF(-a, b));
            m_points.push_back(m_centre + QPointF(a, b));
            m_points.push_back(m_centre + QPointF(a, -b));
            //m_points.push_back(mouseEvent->pos());

            CalcPerimetr();
            CalcSquare();
        }
        else{
            m_points.clear();
            m_centre = mouseEvent->pos();
        }
    }
}

void Rect::Draw(QPainter* painter){
    if(m_points.size() != 4) return;
    painter->drawLine(m_points[0], m_points[1]);
    painter->drawLine(m_points[1], m_points[2]);
    painter->drawLine(m_points[2], m_points[3]);
    painter->drawLine(m_points[0], m_points[3]);
}

void Rect::CalcPerimetr(){
    m_perimetr = m_a * 2 + m_b * 2;
}
void Rect::CalcSquare(){
    m_square = m_a * m_b;
}


void Scuare::MouseEvent(QMouseEvent *mouseEvent){
    SetPoint(mouseEvent);
}
void Scuare::SetPoint(QMouseEvent* mouseEvent){
    if(!m_isInitCenter){
        m_centre = mouseEvent->pos();
        m_isInitCenter = true;
    }
    else{
        if(m_points.size() != 4){
            m_a = std::max(abs(mouseEvent->pos().x() - m_centre.x()), abs(mouseEvent->pos().y() - m_centre.y()));

            m_points.push_back(m_centre + QPointF(-m_a, -m_a));
            m_points.push_back(m_centre + QPointF(-m_a, m_a));
            m_points.push_back(m_centre + QPointF(m_a, m_a));
            m_points.push_back(m_centre + QPointF(m_a, -m_a));

            CalcPerimetr();
            CalcSquare();
        }
        else{
            m_points.clear();
            m_centre = mouseEvent->pos();
        }
    }
}

void Scuare::Draw(QPainter* painter){
    if(m_points.size() != 4) return;
    painter->drawLine(m_points[0], m_points[1]);
    painter->drawLine(m_points[1], m_points[2]);
    painter->drawLine(m_points[2], m_points[3]);
    painter->drawLine(m_points[0], m_points[3]);
}

void Scuare::CalcPerimetr(){
    m_perimetr = m_a * 2 + m_a * 2;
}
void Scuare::CalcSquare(){
    m_square = m_a * m_a;
}


void NStar::MouseEvent(QMouseEvent *mouseEvent){
    SetPoint(mouseEvent);
}
void NStar::SetPoint(QMouseEvent* mouseEvent){
    if(!m_isInitCenter){
        m_centre = mouseEvent->pos();
        m_isInitCenter = true;
    }
    else{
        if(m_points.size() != m_numAngles * 2){
            float deltaX = mouseEvent->pos().x() - m_centre.x();
            float deltaY = mouseEvent->pos().y() - m_centre.y();

            float X = (m_centre.x() + mouseEvent->pos().x()) / 2.0f;
            float Y = (m_centre.y() + mouseEvent->pos().y()) / 2.0f;

            for(int i = 0; i < m_numAngles; i++){
                m_points.push_back(QPointF(X - deltaX * std::sin(2 * 3.1415f / m_numAngles * i),
                                           Y - deltaY * std::cos(2.0f * 3.1415f / m_numAngles * i)));
                m_points.push_back(QPointF(X - deltaX / 2.0f * std::sin(2 * 3.1415f / m_numAngles * (i + 0.5f)),
                                           Y - deltaY / 2.0f * std::cos(2.0f * 3.1415f / m_numAngles * (i + 0.5f))));
            }

            UpdateMassCentre();
            CalcPerimetr();
            CalcSquare();
        }
        else{
            m_points.clear();
            m_centre = mouseEvent->pos();
        }
    }
}

void NStar::Draw(QPainter* painter) {
    if(m_points.size() == 0) return;
    QPolygonF polygonF;
    QPointF pointF;

    for(int i = 0; i < m_points.size(); i++){
        pointF = QPointF(m_points[i]);
        polygonF << pointF;
    }

    CalcPerimetr();
    CalcSquare();

    if(m_points.size() == 1) painter->drawPoint(pointF);
    else painter->drawPolygon(polygonF);
}
