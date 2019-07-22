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
    virtual ~UI_Main_Class(){}
    /**
     * @brief setPid
     * @param l Label
     * @param byte Data
     */
    virtual void setPid(QLabel *l,QByteArray byte);
    virtual void setIp(QLabel *l,QByteArray byte);
    virtual void setPort(QLabel *l,QByteArray byte);
    virtual void setState(QLabel *l,QByteArray byte);

    /**
     * @brief setPid
     * @param byte Data
     */
    virtual void setPid(QByteArray byte);
    virtual void setIp(QByteArray byte);
    virtual void setPort(QByteArray byte);
    virtual void setState(QByteArray byte);

    /**
     * @brief send
     * @param s Server
     * @param d Data
     * @param socket Target
     */
    void send(Server*s,DataType&d,qintptr socket);

public Q_SLOTS:
    virtual void get_send_Data(){}
    virtual void _show(){}

private:
    /**
     * @brief socket Target
     */
    qintptr socket;
    QByteArray pid;
    QByteArray ip;
    QByteArray port;
    QByteArray state;

};

#endif // UI_INTERFACE_H
