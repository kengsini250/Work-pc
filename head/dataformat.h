#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <QByteArray>

#define START '%'
#define MID '|'
#define END '&'

typedef struct
{
    QByteArray pid;
    QByteArray ip;
    QByteArray port;
    QByteArray state;
}ConnectType;

typedef struct
{
    QByteArray pid;
    int a;
    int b;
    int c;
}DataType;

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
