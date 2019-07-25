/**
 * @file product_factory.h
 * @author orz (kengsini250@gmail.com)
 * @brief Factory
 * @version 0.1
 * @date 2019-07-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H

#include "head/Products_Base/ui_main_class.h"
#include "head/Products/productA.h"
#include "head/Products/productB.h"

class _Factory
{
public:
    virtual UI_Main_Class* getProduct(int i) = 0;
    virtual ~_Factory(){}
};

class Factory : public _Factory
{
public:
    UI_Main_Class* getProduct(int i)override
    {
        switch(i)
        {
            case 1:
                return new Product_A();
            case 2:
                return new Product_B();
            default:
                return nullptr;
        }
    }
};

#endif
