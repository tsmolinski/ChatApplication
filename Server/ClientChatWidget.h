#ifndef CLIENTCHATWIDGET_H
#define CLIENTCHATWIDGET_H

#include <QWidget>

class QTcpSocket;

namespace Ui {
class ClientChatWidget;
}

class ClientChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientChatWidget(QTcpSocket* client, QWidget *parent = nullptr);
    ~ClientChatWidget();

private slots:
    void dataReceived();
    void on_btnSend_clicked();
    void clientDisconnected();

private:
    Ui::ClientChatWidget *ui;
    QTcpSocket* tcpClient;
};

#endif // CLIENTCHATWIDGET_H
