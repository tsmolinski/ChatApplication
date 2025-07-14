#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ClientManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralwidget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    clientManager = new ClientManager();

    connect(clientManager, &ClientManager::connected, [this](){
                ui->centralwidget->setEnabled(true);
            });

    connect(clientManager, &ClientManager::disconnected, [this](){
        ui->centralwidget->setEnabled(false);
    });

    connect(clientManager, &ClientManager::dataReceived, this, &MainWindow::dataReceived);

    clientManager->connectToServer();
}

void MainWindow::dataReceived(QByteArray data)
{
    ui->lstMessages->addItem(data);
}


void MainWindow::on_btnSend_clicked()
{
    QString message = ui->lnMessage->text().trimmed();
    clientManager->sendMessage(message);
    ui->lstMessages->addItem(message);
    //ui->lnMessage->setText("");
    ui->lnMessage->clear();
}
