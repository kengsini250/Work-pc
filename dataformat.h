#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <QByteArray>

typedef struct
{
    QByteArray ip;
    QByteArray port;
    QByteArray state;
}DataType;

#endif // DATAFORMAT_H
