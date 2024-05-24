#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QQmlEngine>
#include <QtGui/QGuiApplication>

class MainMenu : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT
    Q_PROPERTY(int currState MEMBER currState NOTIFY currStateChanged)
    Q_PROPERTY(int prevState MEMBER prevState NOTIFY currStateChanged)
public:
    explicit MainMenu(QObject *parent = nullptr);
    int currState = 0;
    int prevState = 0;
    Q_INVOKABLE void setCurrState(int);
    Q_INVOKABLE void quit();
signals:
    void currStateChanged();
};

#endif // MENU_H
