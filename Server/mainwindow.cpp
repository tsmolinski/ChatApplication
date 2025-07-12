#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ServerManager.h>
#include <QTcpSocket>
#include <ClientChatWidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newClientConnected(QTcpSocket *client)
{
    int id = client->property("id").toInt();
    ui->lstClients->addItem(QString("New client added: %1").arg(id));

    ClientChatWidget* clientChatWidget = new ClientChatWidget(client);
    ui->tbChats->addTab(clientChatWidget, QString("Client (%1)").arg(id));


}

void MainWindow::clientDisconnected(QTcpSocket *client)
{
    int id = client->property("id").toInt();
    ui->lstClients->addItem(QString("client disconnected: %1").arg(id));
}

void MainWindow::setupServer()
{
    serverManager = new ServerManager();
    connect(serverManager, &ServerManager::newClientConnected, this, &MainWindow::newClientConnected);
    connect(serverManager, &ServerManager::clientDisconnected, this, &MainWindow::clientDisconnected);
}
