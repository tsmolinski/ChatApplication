#include "ServerManager.h"
#include <QTcpServer>
#include <QTcpSocket>

ServerManager::ServerManager(ushort port, QObject *parent)
    : QObject{parent}
{
    setupServer(port);
}

void ServerManager::newClientConnectionReceived()
{
    QTcpSocket* client = tcpServer->nextPendingConnection();
    clientsList.append(client);
    qsizetype id = clientsList.length();
    client->setProperty("id", id);

    connect(client, &QTcpSocket::disconnected, this, &ServerManager::onClientDisconnected);

    emit newClientConnected(client);
}

void ServerManager::onClientDisconnected()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());

    clientsList.removeOne(client);

    emit clientDisconnected(client);
}

void ServerManager::setupServer(ushort port)
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &ServerManager::newClientConnectionReceived);

    tcpServer->listen(QHostAddress::Any, port);
}
