#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(AllPid.isEmpty())
        ui->_Ok->setDisabled(true);

    //-------------------new Client / disconnect Client----------------------------------------------
    server = new Server(this);
    connect(server,&Server::ClientAndPidGet,[=](const qintptr& number,const QByteArray& myPid){
        if(AllPid.isEmpty())
            ui->_Ok->setDisabled(true);
        server->getSelect(number);
        AllPid.insert(number,myPid);
        if(myPid[0]!='%')
            ui->_ComboBox->addItem(myPid);
    });

    connect(server,&Server::discon,[=](const qintptr& number){
        if(AllPid.isEmpty())
            ui->_Ok->setDisabled(true);
        auto pos = AllPid.find(number);
        ui->_ComboBox->removeItem(ui->_ComboBox->findText(pos.value()));
        AllPid.remove(number);
    });
    //-------------------! new Client / disconnect Client----------------------------------------------


    //------------------new window-------------------------
    connect(server,&Server::DATA,[=](const DataType& data){
        dataTemp=data;
    });

    connect(ui->_Ok,&QAbstractButton::clicked,[=](){
        QString pos = ui->_ComboBox->currentText();
        auto p = AllPid.begin();
        for(;p.value()!=pos;p++);
        server->getSelect(p.key());
        MainUI = new mainui_A(dataTemp.ip,dataTemp.port,dataTemp.state);
        MainUI->show();
    });
    //------------------! new window-------------------------

    connect(ui->_Exit,&QAbstractButton::clicked,[=](){this->close();});
}

MainWindow::~MainWindow()
{
    delete ui;
}
