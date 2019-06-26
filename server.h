#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QMap>

#include "dataformat.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QMainWindow *p = nullptr);
    int getClientCount()
    {
        return AllClient.count();
    }

    void getSelect(const qintptr);
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
    QMap<qintptr,QTcpSocket*> AllClient;
    void makedata(DataType* , QByteArray);

signals:
    void newClient();
    void ClientAndPidGet(const qintptr,const QByteArray&);
    void discon(const qintptr);
    void DATA(const DataType&);
};

#endif // SERVER_H
