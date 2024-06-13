#include "filestream.h"

FileStream::FileStream() {}


QPair<QVector<Dish *>*, QVector<Order *>*> FileStream::LoadFromFile(QString filename)
{
    QFile file(filename);
    QVector<Dish*>*dishes = new QVector<Dish*>;
    QVector<Order*>*orders = new QVector<Order*>;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        QString in;
        in = stream.readLine();
        while(in != "```") {

            Dish* dish = new Dish(in);

            dishes->push_back(dish);
            in = stream.readLine();
        }

        while(!stream.atEnd()) {
            in = stream.readLine();
            Order* order = new Order(in);

            orders->push_back(order);
        }
        file.close();
    }

    QPair<QVector<Dish *>*, QVector<Order *>*>p{dishes, orders};
    return p;
}

void FileStream::SaveToFile(QString filename, QVector<Dish *> menu, QVector<Order *> orders)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        file.resize(0);
        QTextStream out(&file);

        for (auto dish : menu){
            out << dish->getName() << ' ' << dish->getPrice() << '\n';
        }
        out << "```\n";
        for (auto order : orders){
            out << order->num << ' ' << order->table << ' ' << order->dish << ' ' << order->count << '\n';
        }
        file.close();
    }

}



