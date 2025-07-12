#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>

class QTcpServer;
class QTcpSocket;

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500, QObject *parent = nullptr);

private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();

signals:
    void newClientConnected(QTcpSocket* client);
    void clientDisconnected(QTcpSocket* client);

private:
    QTcpServer* tcpServer;
    QList<QTcpSocket*> clientsList;

    void setupServer(ushort port);

signals:
};

#endif // SERVERMANAGER_H
