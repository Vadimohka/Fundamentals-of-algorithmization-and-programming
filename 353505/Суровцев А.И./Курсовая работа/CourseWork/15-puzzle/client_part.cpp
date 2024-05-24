#include "client_part.h"

Client_Part::Client_Part(QObject *parent)
    : QObject{parent}
{
    connect(&_socket, &QTcpSocket::connected, this, &Client_Part::connected);
    connect(&_socket, &QTcpSocket::disconnected, this, &Client_Part::disconnected);
    connect(&_socket, &QTcpSocket::errorOccurred, this, &Client_Part::errorOccurred);
    connect(&_socket, &QTcpSocket::stateChanged, this, &Client_Part::socket_stateChanged);
    connect(&_socket, &QTcpSocket::readyRead, this, &Client_Part::socket_readyRead);
}

void Client_Part::connectToServer(QString ip, int port)
{
    if (_socket.isOpen()) {
        if (ip == _ip && port == _port) {
            return;
        }
        _socket.close();
    }
    _ip = ip;
    _port = port;
    _socket.connectToHost(_ip, _port);
}

void Client_Part::disconnect()
{
    _socket.close();
}

QAbstractSocket::SocketState Client_Part::state()
{
    return _socket.state();
}

bool Client_Part::isConnected()
{
    return _socket.state() == QAbstractSocket::ConnectedState;
}

void Client_Part::send_results(QString message)
{
    _socket.write(message.toUtf8());
}

void Client_Part::socket_stateChanged(QAbstractSocket::SocketState state)
{
    if (state == QAbstractSocket::UnconnectedState) {
        _socket.close();
    }
    emit stateChanged(state);
}

void Client_Part::socket_readyRead()
{
    auto data = _socket.readAll();
    emit dataReady(data);
}
