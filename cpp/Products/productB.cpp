#include "head/Products/productB.h"
#include "ui_productB.h"

Product_B::Product_B():
    ui(new Ui::productB)
{
    ui->setupUi(this);

    connect(ui->SendButton,&QAbstractButton::clicked,this,&Product_B::get_send_Data);
    connect(ui->CancelButton,&QAbstractButton::clicked,[=]{
        this->close();
    });
}

void Product_B::setSocketID(qintptr s)
{
    socketID = s;
    ui->TestLabel2->setText(QString::number(s));
}

void Product_B::setSocket(QTcpSocket *s)
{
    socket = s;
}

void Product_B::setPid(QByteArray byte)
{
    pid = byte;
    ui->PidText->setText(byte);
}

void Product_B::setIp(QByteArray byte)
{
    ip = byte;
    ui->IpText->setText(byte);
}

void Product_B::setPort(QByteArray byte)
{
    port = byte;
    ui->PortText->setText(byte);
}

void Product_B::setState(QByteArray byte)
{
    state = byte;
    ui->StateText->setText(byte);
}

void Product_B::setServer(Server *s)
{
    server = s;
}


Product_B::~Product_B()
{
    delete ui;
}

void Product_B::get_send_Data()
{
    int temp_a = ui->lineEdit->text().toInt();

    DataType data;
    data.a = temp_a;
    data.b=0;
    data.c=0;

    data.pid = pid;
    send(server,data,socketID);
}

void Product_B::_show()
{
    this->show();
}
