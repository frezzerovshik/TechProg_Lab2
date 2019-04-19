//  main.cpp
//  08.04.19
//  Artem Sharapov
//  1741
//  SUAI

#include <iostream>
#include "Integer.hpp"
#include "DoubleLinearList.hpp"
#include <Curses.h>
using namespace std;
int main(int argc, const char * argv[])
{
    unsigned  switcher;
    bool exit = true;
    Integer digit;
    Integer digit2;
    DoubleLinearList list;
    DoubleLinearList *buffer;
    do
    {
        
        cout<<"Здравствуйте! Выберите действие, которое Вы хотели бы выполнить"<<endl;
        cout<<"0 - создание копии объекта и вывод на экран"<<endl;
        cout<<"1 - создать целое число"<<endl;
        cout<<"2 - протестировать оператор префиксного инкремента"<<endl;
        cout<<"3 - протестировать оператор постфиксного инкремента"<<endl;
        cout<<"4 - протестировать оператор префиксного декремента"<<endl;
        cout<<"5 - протестировать оператор постфиксного декремента"<<endl;
        cout<<"6 - создать двусвязный линейный список"<<endl;
        cout<<"7 - проверить оператор >"<<endl;
        cout<<"8 - проверить оператор <"<<endl;
        cout<<"9 - проверить оператор !="<<endl;
        cout<<"10 - проверить оператор =="<<endl;
        cout<<"11 - вернуть подсписок"<<endl;
        cout<<"12 - выход из программы"<<endl;
        cout<<endl;
        cin>>switcher;
    switch (switcher) {
        case 0:
        {
            system("clear");
            cout<<"Выберите, копию объекта какого класса нужно создать:"<<endl;
            cout<<"1 - Integer\n2 - DoubleLinearList"<<endl;
            int chs;
            cin>>chs;
            switch (chs) {
                case 1:{
                    system("clear");
                    Integer copy (digit);
                    cout<<"Исходное число"<<endl;
                    digit.print();
                    cout<<"Копия числа"<<endl;
                    copy.print();
                    cout<<endl;
                    
                    break;}
                case 2:
                {
                    system("clear");
                    DoubleLinearList copy(list);//!!!!
                    cout<<"Исходный список"<<endl;
                    list.print();
                    cout<<"Копия списка"<<endl;
                    copy.print();
                    cout<<endl;
                
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 1:
        {
            system("clear");
            cout<<"Введите значение целого числа"<<endl;
            int bf;
            cin>>bf;
            digit.setData(bf);
            cout<<"Объект класса Integer создан"<<endl;
            
            break;
        }
        case 2:{
            system("clear");
            if(digit.getData() == 0)
            {
                cout<<"Целое число не существует"<<endl;
                continue;
            }
            cout << "Значение числа до операции: ";
            digit.print();
            cout<<endl;
           digit2 = ++digit;
            cout << "Значение числа теперь: ";
            digit.print() ;
            digit2.print();
           
            break;
        }
        case 3:{
            system("clear");
            if(digit.getData() == 0)
            {
                cout<<"Целое число не существует"<<endl;
                continue;
            }
            cout << "Значение числа до операции: ";
            digit.print();
            cout<<endl;
            digit2 = digit++;
            cout << "Значение числа теперь: ";
            digit.print() ;
            digit2.print();
          
            break;
        }
        case 4:{
            system("clear");
            if(digit.getData() == 0)
            {
                cout<<"Целое число не существует"<<endl;
                continue;
            }
            cout << "Значение числа до операции: ";
            digit.print();
            cout<<endl;
            --digit;
            cout << "Значение числа теперь: ";
            digit.print() ;
            
           
            break;
        }
        case 5:
        {
            system("clear");
            if(digit.getData() == 0)
            {
                cout<<"Целое число не существует"<<endl;
                continue;
            }
            cout << "Значение числа до операции: ";
            digit.print();
            cout<<endl;
           digit2 =  digit--;
            cout << "Значение числа теперь: ";
            digit.print() ;
            digit2.print();
           
            break;
        }
        case 6:{
            system("clear");
            cout<<"Введите размерность списка"<<endl;
            int Value;
            cin>>Value;
            list.create(Value);
            cout<<"Список создан"<<endl;
            
         
            break;
        }
        case 7:
        {
            system("clear");
            cout<<"Для проверки оператора программа создаст новую очередь"<<endl;
            cout<<"Выражение имеет вид: list>buffer"<<endl;
            int buf = list.getNum();
            buffer = new DoubleLinearList;
            if(buf == 0)
            {
                cout<<"Пустой список!"<<endl;
                continue;
            }
            buffer->create(buf);
            cout<<"Первый список:"<<endl;
            list.print();
            cout<<"Второй список:"<<endl;
            buffer->print();
            if(list>*buffer)
                cout<<"Первый список больше второго, выражение истинно"<<endl;
            else
                cout<<"Первый список меньше второго,выражение ложно"<<endl;
            delete buffer;
            buffer = nullptr;
            
            
            break;
        }
        case 8:
        {
            system("clear");
            cout<<"Для проверки оператора программа создаст новую очередь"<<endl;
            cout<<"Выражение имеет вид: list<buffer"<<endl;
            int buf = list.getNum();
            buffer = new DoubleLinearList;
            if(buf == 0)
            {
                cout<<"Пустой список!"<<endl;
                continue;
            }
            buffer->create(buf);
            cout<<"Первый список:"<<endl;
            list.print();
            cout<<endl;
            cout<<"Второй список:"<<endl;
            buffer->print();
            cout<<endl;
            if(list<*buffer)
                cout<<"Первый список меньше второго, выражение истинно"<<endl;
            else
                cout<<"Первый список больше второго второго, выражение ложно"<<endl;
            delete buffer;
            buffer = nullptr;
            
       
            break;
        }
            break;
         case 9:
        {
            system("clear");
            cout<<"Для проверки оператора программа создаст новую очередь"<<endl;
            cout<<"Выражение имеет вид: list!=buffer"<<endl;
            int buf = list.getNum();
            buffer = new DoubleLinearList;
            if(buf == 0)
            {
                cout<<"Пустой список!"<<endl;
                continue;
            }
            buffer->create(buf);
            cout<<"Первый список:"<<endl;
            list.print();
            cout<<endl;
            cout<<"Второй список:"<<endl;
            buffer->print();
            cout<<endl;
            if(list!=*buffer)
                cout<<"Списки не равны, выражение истинно"<<endl;
            else
                cout<<"Списки равны, выражение ложно"<<endl;
            delete buffer;
            buffer = nullptr;
        
           
            break;
        }
        case 10:
        {
            system("clear");
            cout<<"Для проверки оператора программа создаст новую очередь"<<endl;
            cout<<"Выражение имеет вид: list==buffer"<<endl;
            int buf = list.getNum();
            buffer = new DoubleLinearList;
            if(buf == 0)
            {
                cout<<"Пустой список!"<<endl;
                continue;
            }
            buffer->create(buf);
            cout<<"Первый список:"<<endl;
            list.print();
            cout<<endl;
            cout<<"Второй список:"<<endl;
            buffer->print();
            cout<<endl;
            if(list==*buffer)
                cout<<"Списки равны, выражение истинно"<<endl;
            else
                cout<<"Списки не равны, выражение ложно"<<endl;
            delete buffer;
            buffer = nullptr;
            
         
            break;
        }
        case 11:
        {
            system("clear");
            cout<<"Подсписок какой длины хотите взять?"<<endl;
            int len;
            cin>>len;
          
            buffer = list(len);
            cout<<"Исходный список"<<endl;
            list.print();
            cout<<endl;
            cout<<"Взятый подсписок длины "<<len<<endl;
            buffer->print();
            cout<<endl;
            break;
        }
        case 12:
            exit = false;
            break;
        default:
            break;
    }
    }while(exit);
    system("clear");
    cout<<"До новых встреч!"<<endl;
    return 0;
}

