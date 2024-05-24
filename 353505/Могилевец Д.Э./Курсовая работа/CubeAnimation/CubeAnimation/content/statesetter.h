#ifndef STATESETTER_H
#define STATESETTER_H

#include <QQmlEngine>
#include <QtWidgets/QWidget>
#include <QtUiTools/QtUiTools>

class StateSetter : public QWidget
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit StateSetter(QWidget *parent = nullptr);
    static QWidget *loadUiFile(QWidget *parent)
    {
        QFile file(":/statesetter.ui");
        file.open(QIODevice::ReadOnly);

        QUiLoader loader;
        return loader.load(&file, parent);
    }
signals:
};

#endif // STATESETTER_H
