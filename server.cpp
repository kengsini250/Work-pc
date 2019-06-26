#include "server.h"
#include <QDebug>

Server::Server(QMainWindow *p):QTcpServer(p)
{
    listen(QHostAddress::Any,55555);

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* now = new QTcpSocket(this);


    now->setSocketDescriptor(socketDescriptor);
    connect(now,&QTcpSocket::readyRead,[=](){
        QByteArray myPid = now->readAll();

        if(myPid[0]=='%')
        {
           DataType dataTemp;
           makedata(&dataTemp,myPid);
           emit DATA(dataTemp);
        }
        else
            emit ClientAndPidGet(socketDescriptor,myPid);
        myPid.clear();
    });
    AllClient.insert(socketDescriptor, now);

    connect(now,&QTcpSocket::disconnected,[=](){
        AllClient.remove(socketDescriptor);
        emit discon(socketDescriptor);
    });


    return emit QTcpServer::newConnection ();
}

void Server::makedata(DataType *temp, QByteArray data)
{
    int count=1;
    for(auto a = data.begin()+1;(*a)!='|';a++)
    {
        temp->ip.push_back(*a);
        count++;
    }
    for(auto a = data.begin()+count+1;(*a)!='|';a++)
    {
        temp->port.push_back(*a);
        count++;
    }
    for(auto a = data.begin()+count+2;(*a)!='&';a++)
    {
        temp->state.push_back(*a);
        count++;
    }
}

void Server::getSelect(qintptr i)
{
    QTcpSocket* now = new QTcpSocket(this);
    auto p = AllClient.begin();
    for(;p!=AllClient.end();p++)
    {
        if(p.key()==i)
        {
            now=p.value();
            now->write("GET_DATA");
        }
    }
    //connect(now,&QTcpSocket::readyRead,[=](){
    //QByteArray data = now->readAll()
}
