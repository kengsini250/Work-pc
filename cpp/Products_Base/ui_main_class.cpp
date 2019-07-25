#include "head/Products_Base/ui_main_class.h"

UI_Main_Class::~UI_Main_Class()
{

}

void UI_Main_Class::send(Server *s, DataType &d, qintptr socket)
{
    s->sendData(socket,d);
}

