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

    /**
     * @brief Product_A
     * @param s         server
     * @param _socket   socket
     * @param _pid      pid
     * @param _ip       ip
     * @param _port     port
     * @param _state    state
     */
    explicit Product_A(Server* s ,qintptr _socket,QByteArray _pid, QByteArray _ip, QByteArray _port, QByteArray _state);

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
