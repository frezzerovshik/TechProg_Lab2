//
//  DoubleLinearList.cpp
//  T.P.LB.2
//
//  Created by Артем Шарапов on 08/04/2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "DoubleLinearList.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

DoubleLinearList::DoubleLinearList(const DoubleLinearList& Init)
{
    Head = nullptr;
    Tail = nullptr;
    Num = 0;
    Node *tmp = Init.Head;
    int i;
    int *arr = new int[Init.Num];
    for(i = 0;i<Init.Num;++i)
    {
        arr[i] = tmp->getData();
        tmp = tmp->getRight();
    }
    tmp = nullptr;
    //Вот тот самый код добавления
    for(i = 0;i<Init.Num;++i)
    {
        Node *temp = new Node;
        temp->setRight(nullptr);
        temp->setData(arr[i]);
        
        if (Head != nullptr)
        {
            temp->setLeft(Tail);
            Tail->setRight(temp);
            Tail = temp;
        }
        else
        {
            temp->setLeft(nullptr);
            Head = Tail = temp;
        }
    }
    delete[] arr;
    arr = nullptr;
}
void DoubleLinearList:: create(int Value)
{
    long ltime;
    int stime;
    ltime = time (NULL);
    stime = (unsigned int) ltime/2;
            srand(stime);
            for(int i = 0;i<Value;++i)
                {
                    Node *temp = new Node;
                    temp->setRight(nullptr);
                    temp->setData(rand()%100+1);
        
                    if (Head != nullptr)
                        {
                            temp->setLeft(Tail);
                            Tail->setRight(temp);
                            Tail = temp;
                        }
                    else
                        {
                            temp->setLeft(nullptr);
                            Head = Tail = temp;
                        }
                }
    Num+=Value;
        }
void DoubleLinearList::print()
{
    
    Node *temp = Head;
    int i = 0;
    while (temp != nullptr)
    {
        if(i == Num-1)
        cout << temp->getData();
        else
            cout << temp->getData() << " >> ";
        temp = temp->getRight();
        i++;
    }
    cout<<endl;
}

bool DoubleLinearList::operator == (const DoubleLinearList &op2)
{
    bool flag = true;
    Node *tempThis = Head;
    Node *tempOp2 = op2.Head;
    for(int i = 0;i<Num;++i){
        if(tempThis->getData() != tempOp2->getData())
        {
            flag = false;
            break;
        }
        tempThis = tempThis->getRight();
        tempOp2 = tempOp2->getRight();
    }
    return flag;
}
bool DoubleLinearList::operator != (const DoubleLinearList &op2)
{
    bool flag = true;
    Node *tempThis = Head;
    Node *tempOp2 = op2.Head;
    for(int i = 0;i<Num;++i){
        if(tempThis->getData() == tempOp2->getData())
        {
            flag = false;
            break;
        }
        tempThis = tempThis->getRight();
        tempOp2 = tempOp2->getRight();
    }
    return flag;
}
bool operator >(const DoubleLinearList &op1 , const DoubleLinearList &op2)
{
    bool flag;
    Node *tempOp1 = op1.Head;
    Node *tempOp2 = op2.Head;
    int countOp1 , countOp2;
    countOp1 = countOp2 = 0;
    for(int i = 0;i<op1.Num;++i)
    {
        if(tempOp1->getData()>tempOp2->getData())
            countOp1++;
            else
            countOp2++;
        tempOp1 = tempOp1->getRight();
        tempOp2 = tempOp2->getRight();
    }
    if(countOp1>countOp2)
        flag = true;
    else
        flag = false;
    return flag;
}
bool operator <(const DoubleLinearList &op1 , const DoubleLinearList &op2)
{
    bool flag;
    Node *tempOp1 = op1.Head;
    Node *tempOp2 = op2.Head;
    int countOp1 , countOp2;
    countOp1 = countOp2 = 0;
    for(int i = 0;i<op1.Num;++i)
    {
        if(tempOp1->getData()<tempOp2->getData())
            countOp1++;
            else
                countOp2++;
        tempOp1 = tempOp1->getRight();
        tempOp2 = tempOp2->getRight();
    }
    if(countOp1>countOp2)
        flag = true;
    else
        flag = false;
    return flag;
}
DoubleLinearList* DoubleLinearList::operator() (int num)
{
    DoubleLinearList *temp = new DoubleLinearList;
    Node *tmp =Head;
    int *arr = new int[num];
    
    for(int i = 0;i<num;++i)
    {
        arr[i] = tmp->getData();
        tmp = tmp->getRight();
    }
    temp->create(num);
    tmp = temp->getHead();
    for(int i = 0;i<num;++i)
    {
        tmp->setData(arr[i]);
        tmp = tmp->getRight();
    }
    
    return temp;
}
DoubleLinearList::~DoubleLinearList()
{
    if(Num!=0)
    {
        Node *tmp;
        for(int i = 0; i<Num;++i)
        {
            tmp = Head->getRight();
            delete Head;
            Head = tmp;
        }
    }
}
