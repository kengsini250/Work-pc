#include "mainui_A.h"
#include "ui_mainui_A.h"

mainui_A::mainui_A(QByteArray _ip, QByteArray _port, QByteArray _state):
    ui(new Ui::mainui_A)
{
    ui->setupUi(this);

    ui->IpText->setText(_ip);
    ui->PortText->setText(_port);
    ui->StateText->setText(_state);

    connect(ui->SendButton,&QAbstractButton::clicked,[=]{
        qDebug()<<"send";
    });
    connect(ui->CancelButton,&QAbstractButton::clicked,[=]{
        this->close();
    });
}

mainui_A::mainui_A()
{
    ui->setupUi(this);


    connect(ui->SendButton,&QAbstractButton::clicked,[=]{
        qDebug()<<"send";
    });
    connect(ui->CancelButton,&QAbstractButton::clicked,[=]{
        this->close();
    });
}

mainui_A::~mainui_A()
{
    delete ui;
}

void mainui_A::setIp(QByteArray ip)
{
    ui->IpText->setText(ip);
}

void mainui_A::setPort(QByteArray port)
{
    ui->PortText->setText(port);
}

void mainui_A::setState(QByteArray state)
{
    ui->StateText->setText(state);
}
