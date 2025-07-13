#include "ClientManager.h"
#include <QTcpSocket>

ClientManager::ClientManager(QHostAddress ip, ushort port, QObject *parent)
    : QObject{parent}
    , ipAddress(ip)
    , port(port)
{
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::connected, this, &ClientManager::connected);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &ClientManager::disconnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &ClientManager::readyRead);
}

void ClientManager::connectToServer()
{
    tcpSocket->connectToHost(ipAddress, port);
}

void ClientManager::sendMessage(QString message)
{
    tcpSocket->write(message.toUtf8());
}

void ClientManager::readyRead()
{
    QByteArray data = tcpSocket->readAll();

    emit dataReceived(data);
}
