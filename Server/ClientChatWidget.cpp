#include "ClientChatWidget.h"
#include "ui_ClientChatWidget.h"
#include "QTcpSocket"

ClientChatWidget::ClientChatWidget(QTcpSocket* client, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientChatWidget)
    , tcpClient(client)
{
    ui->setupUi(this);

    connect(tcpClient, &QTcpSocket::readyRead, this, &ClientChatWidget::dataReceived);
    connect(tcpClient, &QTcpSocket::disconnected, this, &ClientChatWidget::clientDisconnected);
}

ClientChatWidget::~ClientChatWidget()
{
    delete ui;
}

void ClientChatWidget::dataReceived()
{
    auto data = tcpClient->readAll();
    ui->lstMessages->addItem(data);
}

void ClientChatWidget::on_btnSend_clicked()
{
    tcpClient->write(ui->lnMessage->text().trimmed().toUtf8());
    ui->lnMessage->setText("");
}

void ClientChatWidget::clientDisconnected()
{
    ui->wdgSend->setEnabled(false);
}

