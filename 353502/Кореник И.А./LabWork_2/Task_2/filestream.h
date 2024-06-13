#ifndef FILESTREAM_H
#define FILESTREAM_H
#include <QFile>
#include <QFileDialog>
#include <QPair>
#include <QVector>
#include "dish.h"
#include "order.h"
class FileStream
{
public:
    FileStream();


    QPair<QVector<Dish*>*, QVector<Order*>*> LoadFromFile(QString filename);

    void SaveToFile(QString filename, QVector<Dish*>menu, QVector<Order*>orders);
private:

};

#endif // FILESTREAM_H
