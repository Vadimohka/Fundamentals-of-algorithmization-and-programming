#include "components.h"

Components::Components()
{
    type = "";
    firm = "";
    model = "";
    parameters = "";
    price = 0.0;
    available = "";
}

QVector<Components> Components::readComponents(const QString &fileName)
{
    QFile file(fileName);
    QVector <Components> components;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            Components comp;
            comp.type = in.readLine();
            comp.firm = in.readLine();
            comp.model = in.readLine();
            comp.parameters = in.readLine();
            QString priceLine = in.readLine();
            QStringList priceParts = priceLine.split(" ");
            if(priceParts.size()==2){
                comp.price = priceParts[0].toDouble();
                comp.curr = priceParts[1];
            }
            comp.available = in.readLine();
            in.readLine();
            components.append(comp);
        }
        file.close();
    }
    return components;
}
