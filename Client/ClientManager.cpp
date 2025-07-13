#include "ClientManager.h"

ClientManager::ClientManager(QObject *parent)
    : QObject{parent}
{}

ClientManager::ClientManager(QHostAddress ip, ushort port, QObject *parent)
{

}
