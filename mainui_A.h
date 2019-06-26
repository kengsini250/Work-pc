#ifndef MAINUI_A_H
#define MAINUI_A_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class mainui_A;
}

class mainui_A: public QWidget
{
    Q_OBJECT

public:
    explicit mainui_A();
    explicit mainui_A(QByteArray,QByteArray,QByteArray);
    ~mainui_A();

    void setIp(QByteArray);
    void setPort(QByteArray);
    void setState(QByteArray);


private:
    Ui::mainui_A *ui;
};

#endif // MAINUI_A_H
