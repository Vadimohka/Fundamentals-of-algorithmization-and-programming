#ifndef STATEBYSCRAMBLE_H
#define STATEBYSCRAMBLE_H

#include <QObject>
#include <QQmlEngine>

class StateByScramble : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit StateByScramble(QObject *parent = nullptr);
    QMap<QString, QString> stateByScramble(QString);
signals:
};

#endif // STATEBYSCRAMBLE_H
