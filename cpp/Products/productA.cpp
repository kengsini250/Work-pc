#include "head/Products/productA.h"
#include "ui_productA.h"

Product_A::Product_A(Server* s ,qintptr _socket,QByteArray _pid, QByteArray _ip, QByteArray _port, QByteArray _state):
    ui(new Ui::productA),pid(_pid),socket(_socket)
{
    ui->setupUi(this);

    setPid(ui->PidText,pid);
    setIp(ui->IpText,_ip);
    setPort(ui->PortText,_port);
    setState(ui->StateText,_state);
    server = new Server;
    server = s;
    //test
    ui->TestLabel2->setText(QString::number(socket));

    connect(ui->SendButton,&QAbstractButton::clicked,this,&Product_A::get_send_Data);
    connect(ui->CancelButton,&QAbstractButton::clicked,[=]{
        this->close();
    });
}

Product_A::Product_A()
{
    ui->setupUi(this);

    connect(ui->SendButton,&QAbstractButton::clicked,this,&Product_A::get_send_Data);

    connect(ui->CancelButton,&QAbstractButton::clicked,[=]{
        this->close();
    });

}

Product_A::~Product_A()
{
    delete ui;
    delete server;
}

void Product_A::get_send_Data()
{
    int temp_a = ui->lineEdit_a->text().toInt();
    int temp_b = ui->lineEdit_b->text().toInt();
    int temp_c = ui->lineEdit_c->text().toInt();

    DataType data;
    data.a  = temp_a;
    data.b  = temp_b;
    data.c  = temp_c;

    data.pid = pid;
    send(server,data,socket);
}

void Product_A::_show()
{
    this->show();
}
