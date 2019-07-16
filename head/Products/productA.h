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
    explicit Product_A(Server*,qintptr,QByteArray,QByteArray,QByteArray,QByteArray);
    ~Product_A()override;

public Q_SLOTS:
    virtual void get_send_Data()override;
    virtual void _show() override;


private:
    Ui::productA *ui;
    QByteArray pid = "";
    qintptr socket;
    Server* server;
};

#endif // MAINUI_A_H
