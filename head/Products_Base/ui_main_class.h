#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include "head/dataformat.h"
#include "head/server.h"
#include <QLabel>
#include <QByteArray>
#include <QWidget>

class UI_Main_Class
{
public:
    virtual ~UI_Main_Class(){}
    virtual void setPid(QLabel *l,QByteArray byte);
    virtual void setIp(QLabel *l,QByteArray byte);
    virtual  void setPort(QLabel *l,QByteArray byte);
    virtual void setState(QLabel *l,QByteArray byte);

    void send(Server*s,DataType&d,qintptr socket);

public Q_SLOTS:
    virtual void get_send_Data()=0;
    virtual void _show()=0;

};

#endif // UI_INTERFACE_H
