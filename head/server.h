/**
 * @file server.h
 * @author orz (kengsini250@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

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
    explicit Server(QMainWindow *p = nullptr)noexcept;
    int getClientCount()noexcept;
    void getSelect(const qintptr)noexcept;
    void sendData(qintptr ,const DataType&)noexcept;
protected:
    void incomingConnection(qintptr socketDescriptor)override;
private:

    /**
     * @brief AllClient
     * @brief qintptr     socket
     * @brief QTcpSocket* Client
     */
    QMap<qintptr,QTcpSocket*> AllClient;///< qintptr     -> socket
                                        ///< QTcpSocket* -> Client

Q_SIGNALS:
    void newClient();
    void ClientAndPidGet(const qintptr,const QByteArray&);
    void discon(const qintptr);
    void DATA(const ConnectType&);
};

#endif // SERVER_H
