/**
 * @file ui_main_class.h
 * @author orz (kengsini250@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include "head/dataformat.h"
#include "head/server.h"
#include <QLabel>
#include <QByteArray>
#include <QWidget>

/**
 * @brief Interface
 */
class UI_Main_Class
{
public:
    virtual ~UI_Main_Class();

    virtual void setSocketID(qintptr s) = 0;
    virtual void setSocket(QTcpSocket* s) = 0;
    virtual void setPid(QByteArray byte) = 0;
    virtual void setIp(QByteArray byte) = 0;
    virtual void setPort(QByteArray byte) = 0;
    virtual void setState(QByteArray byte) = 0;

    virtual void setServer(Server* s) = 0;

    /**
     * @brief send data
     * @param s Server
     * @param d Data
     * @param socket Target
     */
    virtual void send(Server*s,DataType&d,qintptr socket);

public Q_SLOTS:
    virtual void get_send_Data(){}
    virtual void _show(){}
};

#endif // UI_INTERFACE_H
