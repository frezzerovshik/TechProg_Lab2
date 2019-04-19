#pragma once
class Integer
{
    int *Data;      //Целочисленное значение
public:
    Integer();      //Конструктор по умолчанию
    Integer(int Value);     //Конструктор с параметром
    explicit Integer(const Integer &init);      //Конструктор копирования
    ~Integer();     //Деструктор
    int getData(){return *Data;}        //Метод получения значения
    void setData(int Value = 0){*Data = Value;}     //Метод установки значения
    friend Integer& operator++(Integer &obj , int);     //Постфиксная форма, дружественная функция, увеличивает на 2
    friend Integer& operator--(Integer &obj , int);     //Постфиксная форма, дружественная функция, уменьшает на 2
    Integer& operator++();//Префиксная форма, увеличивает на 1
    Integer& operator--();//Префиксная форма, уменьшает на 1
    void print();//Вывод на экран
};
