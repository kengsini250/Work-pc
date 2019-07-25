#include "head/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)noexcept :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(AllPid.isEmpty())
        ui->_Ok->setDisabled(true);
    else
        ui->_Ok->setDisabled(false);

    factory = new Factory;


    //----------------------------------------
    //new Client / disconnect Client
    //----------------------------------------
    server = new Server(this);
    connect(server,&Server::ClientAndPidGet,[=](const qintptr& socketID,const QByteArray& myPid){

        AllPid.insert(socketID,myPid);

        ui->_ComboBox->addItem(myPid);

        if(AllPid.isEmpty())
            ui->_Ok->setDisabled(true);
        else {
            ui->_Ok->setDisabled(false);
        }
    });

    connect(server,&Server::discon,[=](const qintptr& socketID){

        auto pos = AllPid.find(socketID);
        ui->_ComboBox->removeItem(ui->_ComboBox->findText(pos.value()));
        AllPid.remove(socketID);

        if(AllPid.isEmpty())
            ui->_Ok->setDisabled(true);
        else
            ui->_Ok->setDisabled(false);
    });
    //----------------------------------------
    //new Client / disconnect Client end
    //----------------------------------------


    connect(server,&Server::DATA,[&](const ConnectType& data){
        connectTemp=data;

        MainUI->setPid(connectTemp.pid);
        MainUI->setIp(connectTemp.ip);
        MainUI->setPort(connectTemp.port);
        MainUI->setState(connectTemp.state);
    });

    //----------------------------------------
    //new window
    //----------------------------------------
    connect(ui->_Ok,&QAbstractButton::clicked,[=](){
        QString pos = ui->_ComboBox->currentText();//get ComboBox Text
        auto p = AllPid.begin();
        for(;p.value()!=pos;p++);//get socketID

        QTcpSocket* socket = server->getSelect(p.key());
        
        MainUI = factory->getProduct(getProduct(p.value()));//pid

        MainUI->setSocketID(p.key());
        MainUI->setSocket(socket);
        MainUI->setServer(server);

        MainUI->_show();

    });
    //----------------------------------------
    //new window end
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
        return 1;
    }
    else if(s.at(0)=='2'){
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
