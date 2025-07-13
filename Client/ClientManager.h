#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>

class QTcpSocket;
//class QHostAddress;

class ClientManager : public QObject
{
    Q_OBJECT
public:
    //explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost, QObject *parent = nullptr);

signals:
};

#endif // CLIENTMANAGER_H
