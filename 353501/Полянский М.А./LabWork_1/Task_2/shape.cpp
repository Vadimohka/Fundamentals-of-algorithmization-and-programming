    #include "shape.h"
    #include <QPainter>
    #include <QTransform>
    #include <QGraphicsScene>

    Shape::Shape(QGraphicsItem *parent) : QGraphicsObject(parent), m_timer(this)
    {
        connect(&m_timer, &QTimer::timeout, this, [=](){ timerEvent(nullptr); });
        moveX = 0;
        moveY = 0;
        m_scaleFactor = 1.0;
    }

    void Shape::setCenter(const QPointF &center)
    {
        if (m_center != center) {
            prepareGeometryChange();
            m_center = center;
        }
    }

    void Shape::moveLeft()
    {
        moveX-=5;
        update();
    }

    void Shape::moveRight()
    {
        moveX+=5;
        update();
    }

    void Shape::moveUp()
    {
        moveY+=5;
        update();
    }

    void Shape::moveDown()
    {
        moveY-=5;
        update();
    }


    void Shape::scale(qreal x, qreal y, qreal scaleFactor)
    {
        qreal dx = m_center.x() - x;
        qreal dy = m_center.y() - y;
        QPointF scaledCenter(x + dx * scaleFactor, y + dy * scaleFactor);
        setCenter(scaledCenter);
        
    }

    QRectF Shape::boundingRect() const
    {
        qreal width = 200; 
        qreal height = 200; 
        return QRectF(-width / 2, -height / 2, width, height);
    }

    void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);

        QPointF rotationCenter(centX + rotatecenterx, centY + rotatecentery);
        QPointF move(moveX+ rotatecenterx, moveY+rotatecentery);

        painter->translate(rotationCenter);
        painter->rotate(rotate_angle);
        painter->translate(-rotationCenter);

        QPolygonF polygon;
        for (auto &point : points) {
            polygon << point * m_scaleFactor + move;
        }

    
        painter->drawPolygon(polygon);

    
        painter->drawEllipse(rotationCenter, 1, 1);

        painter->restore();
    }
    void Shape::zoomIn()
    {
        m_scaleFactor +=0.2;
        update();
        
    }

    void Shape::zoomOut()
    {
        m_scaleFactor -= 0.2;
        update();
        
    }
    void Shape::cnetermovex(double x){
        rotatecenterx = x;
        update();
    }
    void Shape::cnetermovey(double y){
        rotatecentery = y;
        update();
    }
    void Shape::rotateclockwise(){
        rotate_angle -= 10;
        update();
    }
    void Shape::unticlockwise(){
        rotate_angle+=10;
        update();
    }
    void Shape::resizeTriangle1(qreal side) {
        
    }

    void Shape::resizeTriangle2(qreal side) {
        
    }

    void Shape::resizeTriangle3(qreal side) {
        
    }
    void Shape::resizeRectH(qreal newwidth){

    }
    void Shape::resizeRectW(qreal newhieght){
        
    }
    void Shape::resSide(qreal newside){

    }

    void Shape::numberApexes(int apexes){

    }
    void Shape::changeRadius1(double spinrad1){

    }

    void Shape::changeRadius2(double spinrad1){
        
    }
    void Shape::change_side(double newside){

    }
    void Shape::changeangle(double newangle){
        
    }
    qreal Shape::perimeter(){
        return 1;
    }
    qreal Shape::area(){
        return 1;

    }
    void Shape::addPoint(const QPointF& point){

    }

    void Shape::timerEvent(QTimerEvent *event)
    {
        Q_UNUSED(event);
    }

