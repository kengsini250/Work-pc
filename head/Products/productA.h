/**
 * @file productA.h
 * @author orz (kengsini250@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef MAINUI_A_H
#define MAINUI_A_H

#include <QWidget>
#include <QDebug>
#include "head/dataformat.h"
#include "head/server.h"
#include "head/Products_Base/ui_main_class.h"

namespace Ui {
class productA;
}

class Product_A: public QWidget,public UI_Main_Class
{
    Q_OBJECT

public:
    explicit Product_A();

    virtual void setSocketID(qintptr s)override;
    virtual void setSocket(QTcpSocket* s)override;
    virtual void setPid(QByteArray byte)override;
    virtual void setIp(QByteArray byte)override;
    virtual void setPort(QByteArray byte)override;
    virtual void setState(QByteArray byte)override;

    virtual void setServer(Server* s)override;

    ~Product_A()override;

public Q_SLOTS:
    virtual void get_send_Data()override;
    virtual void _show() override;


private:
    Ui::productA *ui;

    qintptr socketID;
    QTcpSocket* socket;
    QByteArray pid;
    QByteArray ip;
    QByteArray port;
    QByteArray state;

    Server* server;
};

#endif // MAINUI_A_H
