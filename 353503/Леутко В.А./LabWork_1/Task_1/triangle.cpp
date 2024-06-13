#include "triangle.h"

triangle::triangle() {}

triangle::~triangle()
{

}

void triangle::initialization()
{
    int prX,prY,nxX,nxY;
    for(int i = 0; i < cords.length(); i++)
    {
        prX = cords[i].first;
        prY = cords[i].second;
        if (i==cords.length()-1)
        {
            nxX = cords[0].first;
            nxY = cords[0].second;
        }
        else
        {
            nxX = cords[i+1].first;
            nxY = cords[i+1].second;
        }
        int x = prX * nxY - nxX * prY;
        area += x;
        Center.first += (prX + nxX) * x;
        Center.second += (prY + nxY) * x;
    }
    Center.first /= area*3;
    Center.second /= area*3;
    area = abs(area/2);
    now_area = area;

    for (int i = 0;i<cords.length();i++)
    {
        perimeter += pow(pow(cords[i].first-cords[(i+1)%cords.length()].first,2.)+pow(cords[i].second-cords[(i+1)%cords.length()].second,2.),1/2.);
        minX = qMin(cords[i].first,minX);
        minY = qMin(cords[i].second,minY);
        maxX = qMax(cords[i].first,maxX);
        maxY = qMax(cords[i].second,maxY);
        triang << QPoint(cords[i].first-Center.first,cords[i].second-Center.second);
    }
    w = qMax(maxX-Center.first,Center.first - minX)*2;
    h = qMax(maxY-Center.second,Center.second - minY)*2;
    now_perimeter = perimeter;
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(252, 15, 192), 3) : QPen(QColor(138, 43, 226), 3));
    painter->drawPoint(0, 0);
    painter->setPen(QPen(QColor(R, G, B), PenSize));
    painter->drawPolygon(triang);

    QThread::msleep(5);

    double delta = ang - now_ang;
    now_ang += delta / 10;

    double deltaSize = size - now_size;
    now_size += deltaSize / 10;

    now_area = area * now_size * now_size;
    now_perimeter = perimeter * now_size;

    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
// int maxValue = *std::max_element(arr, arr + n); // Максимальное значение в массиве
// int maxHeight = 100; // Максимальная высота элемента (можно настроить по вашему усмотрению)

// for (int i = 0; i < n; ++i) {
//     QGraphicsRectItem *item = dynamic_cast<QGraphicsRectItem*>(scene->items().at(i * 2));
//     QGraphicsRectItem *boundingRect = dynamic_cast<QGraphicsRectItem*>(scene->items().at(i * 2 + 1));
//     QGraphicsItem *textItem = scene->items().at(i * 2 + 2);

//     int newPosition = sortedIndices[i] * (ARRAY_ELEMENT_WIDTH + ARRAY_ELEMENT_MARGIN);
//     double ratio = arr[sortedIndices[i]] / static_cast<double>(maxValue);
//     int newHeight = ratio * maxHeight;

//     item->setPos(newPosition, maxHeight - newHeight);
//     item->setRect(QRectF(0, 0, ARRAY_ELEMENT_WIDTH, newHeight));

//     boundingRect->setPos(item->pos());
//     boundingRect->setRect(item->rect());

//     textItem->setPos(newPosition, 0);
// }


// int maxValue = *std::max_element(arr, arr + n); // Максимальное значение в массиве
// int maxHeight = 100; // Максимальная высота элемента (можно настроить по вашему усмотрению)
// int totalWidth = n * (ARRAY_ELEMENT_WIDTH + ARRAY_ELEMENT_MARGIN); // Общая ширина прямоугольников

// scene->clear(); // Очищаем сцену

// for (int i = 0; i < n; ++i) {
//     QGraphicsRectItem *item = new QGraphicsRectItem(0, 0, ARRAY_ELEMENT_WIDTH, (arr[i] / static_cast<double>(maxValue)) * maxHeight);
//     item->setPos(i * (ARRAY_ELEMENT_WIDTH + ARRAY_ELEMENT_MARGIN), maxHeight - item->rect().height());
//     item->setBrush(QBrush(Qt::blue));
//     scene->addItem(item);

//     // Создаем и устанавливаем прямоугольную область ограничения
//     QGraphicsRectItem *boundingRect = new QGraphicsRectItem(item->rect());
//     boundingRect->setPos(item->pos());
//     boundingRect->setPen(Qt::NoPen); // Отключаем обводку
//     scene->addItem(boundingRect);

//     scene->update();
//     qApp->processEvents();

//     QThread::msleep(100); // Задержка в 100 миллисекунд
// }

// // Устанавливаем размер сцены в соответствии с прямоугольниками ограничения
// scene->setSceneRect(scene->itemsBoundingRect());
