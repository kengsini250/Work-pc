/**
 * @file mainwindow.h
 * @author orz (kengsini250@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "product_factory.h"

#include <QMainWindow>
#include "server.h"
#include "head/Products_Base/ui_main_class.h"
#include "head/Products/productA.h"
#include "head/Products/productB.h"

#include "dataformat.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr)noexcept;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    UI_Main_Class* MainUI;

    /**
     * @brief server
     */
    Server* server;

    /**
     * @brief AllPid
     * @brief qintptr socketID
     * @brief QString pid
     */
    QMap<qintptr,QString> AllPid;///< qintptr -> socketID
                                 ///< QString -> pid

    /**
     * @brief getProduct
     * @param s pid
     * @return product
     */
    int getProduct(QString s);

    /**
     * @brief Factory
     * 
     */
    Factory* factory;

    ConnectType connectTemp;
};

#endif // MAINWINDOW_H
