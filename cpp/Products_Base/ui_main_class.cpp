#include "head/Products_Base/ui_main_class.h"

void UI_Main_Class::setPid(QLabel *l, QByteArray byte)
{
    l->setText(byte);
}

void UI_Main_Class::setIp(QLabel *l, QByteArray byte)
{
    l->setText(byte);
}

void UI_Main_Class::setPort(QLabel *l, QByteArray byte)
{
    l->setText(byte);
}

void UI_Main_Class::setState(QLabel *l, QByteArray byte)
{
    l->setText(byte);
}

void UI_Main_Class::setPid(QByteArray byte)
{
    pid = byte;
}

void UI_Main_Class::setIp(QByteArray byte)
{
    ip = byte;
}

void UI_Main_Class::setPort(QByteArray byte)
{
    port = byte;
}

void UI_Main_Class::setState(QByteArray byte)
{
    state = byte;
}

void UI_Main_Class::send(Server *s, DataType &d,qintptr socket)
{
    s->sendData(socket,d);
}
