#ifndef CLIENT_PART_H
#define CLIENT_PART_H

#include <QObject>
#include <QTcpSocket>

class Client_Part : public QObject
{
    Q_OBJECT
public:
    explicit Client_Part(QObject *parent = nullptr);
    void connectToServer(QString ip, int port);
    void disconnect();
    QAbstractSocket::SocketState state();
    bool isConnected();
    void send_results(QString message);
signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);
    void dataReady(QByteArray);
private slots:
    void socket_stateChanged(QAbstractSocket::SocketState state);
    void socket_readyRead();
private:
    QTcpSocket _socket;
    QString _ip;
    int _port;
};

#endif // CLIENT_PART_H
