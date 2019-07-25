#ifndef PRODUCTB_H
#define PRODUCTB_H

#include <QWidget>
#include <QDebug>
#include "head/dataformat.h"
#include "head/server.h"
#include "head/Products_Base/ui_main_class.h"

namespace Ui {
class productB;
}

class Product_B : public QWidget,public UI_Main_Class
{
    Q_OBJECT

public:
    explicit Product_B();

    virtual void setSocketID(qintptr s)override;
    virtual void setSocket(QTcpSocket* s)override;
    virtual void setPid(QByteArray byte)override;
    virtual void setIp(QByteArray byte)override;
    virtual void setPort(QByteArray byte)override;
    virtual void setState(QByteArray byte)override;

    virtual void setServer(Server* s)override;

    ~Product_B()override;

public slots:
    virtual void get_send_Data()override;
    virtual void _show() override;

private:
    Ui::productB *ui;

    qintptr socketID;
    QTcpSocket* socket;
    QByteArray pid;
    QByteArray ip;
    QByteArray port;
    QByteArray state;

    Server* server;
};

#endif // PRODUCTB_H
