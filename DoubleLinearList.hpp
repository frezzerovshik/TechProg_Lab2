#pragma once
#include "Node.hpp"
class DoubleLinearList
{
    Node* Head;
    Node* Tail;
    int Num;
public:
    /*Конструкторы из мяса и костей, детали складывают ложась по ночам в постель (с) Сметана Band*/
    DoubleLinearList ():Head(nullptr),Tail(nullptr),Num(0){};//Конструктор по умолчанию
    DoubleLinearList (int Value):Num(Value),Head(nullptr),Tail(nullptr){};//Конструктор с параметром
    explicit DoubleLinearList (const DoubleLinearList& Init);//Конструктор копирования
    /*Методы установки и получения значений private-членов класса*/
    ~DoubleLinearList ();
    void setNum(int Value){Num = Value;}
    Node* getHead(){return Head;}
    Node* getTail(){return Tail;}
    int getNum(){return Num;}
    
    void create(int Value);//Метод создания списка с рандомными целочисленными значениями, int Value - длина генерируемого списка
    void print();//Вывод на экран имеющегося списка
    
    /*Перегрузки методом*/
    bool operator == (const DoubleLinearList &op2);//Проверяет на полное совпадение элементов списка, если не совпадает хоть один - рез-т false
    bool operator != (const DoubleLinearList &op2);//Проверяет на полное совпадение по всем элементам списка, если хоть один не совпадает - рез-т true
    DoubleLinearList* operator ()( int num);//возвращает указатель на подсписок
    /*Перегрузки дружественными функциями*/
    friend bool operator >(const DoubleLinearList &op1 , const DoubleLinearList &op2);// В каком списке больше сравнений true, тото и больше
    friend bool operator <(const DoubleLinearList &op1 , const DoubleLinearList &op2);//Диаметрально противоположно предыдущему
};
