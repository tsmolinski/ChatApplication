#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ServerManager;
class QTcpSocket;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newClientConnected(QTcpSocket* client);
    void clientDisconnected(QTcpSocket* client);

private:
    Ui::MainWindow *ui;
    ServerManager* serverManager;

    void setupServer();
};
#endif // MAINWINDOW_H
