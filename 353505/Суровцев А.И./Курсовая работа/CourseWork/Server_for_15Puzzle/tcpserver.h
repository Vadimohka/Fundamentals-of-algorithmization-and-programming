#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(int port, QObject *parent = nullptr);
    bool isStarted() const;
    void sendToAll(QString message);
signals:
    void newClientConnected();
    void clientDisconnect();
    void dataReceived(QString message);

private slots:
    void on_client_connecting();

    void clientDisconnected();

    void clientDataReady();


private:
    QTcpServer *_server;
    QList<QTcpSocket *> _socketsList;
    QMap<QString, QVector<int>> m_data3x3; // Для пятнашек 3x3
    QMap<QString, QVector<int>> m_data4x4; // Для пятнашек 4x4
    QMap<QString, QVector<int>> m_data5x5; // Для пятнашек 5x5
    QMap<QString, QVector<int>> m_data6x6; // Для пятнашек 6x6
    bool _isStarted;
};
#endif // TCPSERVER_H
