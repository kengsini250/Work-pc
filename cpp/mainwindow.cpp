#include "head/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)noexcept :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //if(AllPid.isEmpty())
    //ui->_Ok->setDisabled(true);

    //----------------------------------------
    //new Client / disconnect Client
    //----------------------------------------
    server = new Server(this);
    connect(server,&Server::ClientAndPidGet,[=](const qintptr& number,const QByteArray& myPid){
        //if(AllPid.isEmpty())
        //ui->_Ok->setDisabled(true);
        server->getSelect(number);
        AllPid.insert(number,myPid);
        if(myPid[0]!='%')
            ui->_ComboBox->addItem(myPid);
    });

    connect(server,&Server::discon,[=](const qintptr& number){
        //if(AllPid.isEmpty())
        //ui->_Ok->setDisabled(true);
        auto pos = AllPid.find(number);
        ui->_ComboBox->removeItem(ui->_ComboBox->findText(pos.value()));
        AllPid.remove(number);
    });
    //----------------------------------------
    //new Client / disconnect Client end
    //----------------------------------------

    //----------------------------------------
    //new window
    //----------------------------------------
    connect(server,&Server::DATA,[=](const ConnectType& data){
        connectTemp=data;
    });

    connect(ui->_Ok,&QAbstractButton::clicked,[=](){
        QString pos = ui->_ComboBox->currentText();//get ComboBox Text
        auto p = AllPid.begin();
        for(;p.value()!=pos;p++);//get pid
        server->getSelect(p.key());//get socket

        getProduct(p.value());//get Products
        MainUI = new Product_A(server,p.key(),connectTemp.pid, connectTemp.ip,connectTemp.port,connectTemp.state);
        MainUI->_show();

    });
    //----------------------------------------
    //new window
    //----------------------------------------

    connect(ui->_Exit,&QAbstractButton::clicked,[=](){this->close();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getProduct(QString s)
{
    if(s.at(0)=='1'){
        qDebug()<<"Product A";
        return 1;
    }
    else if(s.at(0)=='2'){
        qDebug()<<"Product B";
        return 2;
    }
    else if(s.at(0)=='3'){
        qDebug()<<"Product C";
        return 3;
    }
    else if(s.at(0)=='4'){
        qDebug()<<"Product D";
        return 4;
    }
    else
        return -1;
}
