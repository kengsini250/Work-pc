#include "head/Products/productA.h"
#include "ui_productA.h"

Product_A::Product_A():
    ui(new Ui::productA)
{
    ui->setupUi(this);

    connect(ui->SendButton,&QAbstractButton::clicked,this,&Product_A::get_send_Data);
    connect(ui->CancelButton,&QAbstractButton::clicked,[=]{
        this->close();
    });
}

void Product_A::setSocketID(qintptr s)
{
    socketID = s;
    ui->TestLabel2->setText(QString::number(s));
}

void Product_A::setSocket(QTcpSocket *s)
{
    socket = s;
}

void Product_A::setPid(QByteArray byte)
{
    pid = byte;
    ui->PidText->setText(byte);
}

void Product_A::setIp(QByteArray byte)
{
    ip = byte;
    ui->IpText->setText(byte);
}

void Product_A::setPort(QByteArray byte)
{
    port = byte;
    ui->PortText->setText(byte);
}

void Product_A::setState(QByteArray byte)
{
    state = byte;
    ui->StateText->setText(byte);
}

void Product_A::setServer(Server *s)
{
 server = s;
}


Product_A::~Product_A()
{
    delete ui;
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
    send(server,data,socketID);
}

void Product_A::_show()
{
    this->show();
}
