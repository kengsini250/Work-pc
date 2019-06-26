#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include "mainui_A.h"
#include "dataformat.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Server* server;
    QMap<qintptr,QString> AllPid;
    mainui_A* MainUI;

    DataType dataTemp;

signals:
    void getAllData(const qintptr&);
};

#endif // MAINWINDOW_H
