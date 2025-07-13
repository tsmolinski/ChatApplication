#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QHostAddress>

class QTcpSocket;

class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);

    void connectToServer();
    void sendMessage(QString message);

signals:
    void connected();
    void disconnected();
    void dataReceived(QByteArray data);

private slots:
    void readyRead();

private:
    QTcpSocket* tcpSocket;
    QHostAddress ipAddress;
    ushort port;

};

#endif // CLIENTMANAGER_H
