//
//  Integer.cpp
//  T.P.LB.2
//
//  Created by Артем Шарапов on 08/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//
/*Тоже для приматов*/
#include "Integer.hpp"
#include <iostream>
Integer::Integer()
{
    Data = new int;
    *Data = 0;
}
Integer::Integer(int Value)
{
    Data = new int;
    *Data = Value;
}
Integer::Integer(const Integer &init)
{
    Data = new int;
    *Data = *(init.Data);
}
Integer::~Integer()
{
    delete Data;
    Data = nullptr;
}
Integer& Integer::operator++()
{
    *(this->Data)+=1;
    return *this;
}
Integer& Integer::operator--()
{
    *(this->Data)-=1;
    return *this;
}
void operator++(Integer &obj , int)
{
    obj.setData(obj.getData()+2);
}
void operator--(Integer &obj , int)
{
    obj.setData(obj.getData()-2);
}
void Integer::print()
{
    std::cout<<*Data<<std::endl;
}
