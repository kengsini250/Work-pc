#include "head/server.h"
#include <QDebug>

Server::Server(QMainWindow *p)noexcept:QTcpServer(p)
{
    listen(QHostAddress::Any,55555);
}

int Server::getClientCount()noexcept
{
    return AllClient.count();
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* now = new QTcpSocket(this);

    now->setSocketDescriptor(socketDescriptor);
    connect(now,&QTcpSocket::readyRead,[=](){
        QByteArray myPid = now->readAll();

        //have data
        if(myPid[0]==START)
        {
            ConnectType connectTemp;
            MakeData md(myPid);
            connectTemp = md.makeData();
            //sand data
            emit DATA(connectTemp);
        }

        //first connect
        else
            emit ClientAndPidGet(socketDescriptor,myPid);
        myPid.clear();
    });
    AllClient.insert(socketDescriptor, now);

    connect(now,&QTcpSocket::disconnected,[=]{
        AllClient.remove(socketDescriptor);
        emit discon(socketDescriptor);
    });
    return emit QTcpServer::newConnection ();
}

QTcpSocket* Server::getSelect(qintptr i)noexcept
{
    auto p = AllClient.find(i);
    p.value()->write("GET_DATA");
    return p.value();
}

void Server::sendData(qintptr sockedDescriptor, const DataType & data)noexcept
{
    auto p = AllClient.begin();
    for(;sockedDescriptor!=p.key();p++);
    p.value()->
            write(QString::number(data.a).toUtf8()+MID+
                  QString::number(data.b).toUtf8()+MID+
                  QString::number(data.c).toUtf8()+END);
}
