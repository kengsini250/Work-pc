/**
 * @file dataformat.h
 * @author orz (kengsini250@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <QByteArray>

//-------------------------------
//data formart sign
//-------------------------------
#define START '%'
#define MID '|'
#define END '&'

/**
  * @brief connecting Type and \n
  * state formart
  */
typedef struct
{
    QByteArray pid;
    QByteArray ip;
    QByteArray port;
    QByteArray state;
}ConnectType;

/**
  @brief Data formart
  */
typedef struct
{
    QByteArray pid;
    int a;
    int b;
    int c;
}DataType;

typedef struct{
    QByteArray pid;
    int a;
}DataTypeB;

/**
 * @brief The MakeData class \n
 * QByteArray to  @see ConnectType
 */
class MakeData
{
private:
    ConnectType temp;
public:
    MakeData(){}
    MakeData(QByteArray data)
    {
        int count=1;
        for(auto a = data.begin()+1;(*a)!=MID;a++)
        {
            temp.pid.push_back(*a);
            count++;
        }
        for(auto a = data.begin()+count+1;(*a)!=MID;a++)
        {
            temp.ip.push_back(*a);
            count++;
        }
        for(auto a = data.begin()+count+2;(*a)!=MID;a++)
        {
            temp.port.push_back(*a);
            count++;
        }
        for(auto a = data.begin()+count+3;(*a)!=END;a++)
        {
            temp.state.push_back(*a);
            count++;
        }
    }

    ConnectType makeData()
    {return temp;}

    ~MakeData(){}
};


#endif // DATAFORMAT_H
