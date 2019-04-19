#pragma once
/*Ну тут все банально*/
class Node
{
    int Data;
    Node *Left;
    Node *Right;
public:
    Node():Data(0),Left(nullptr),Right(nullptr){};
    void setData(int Value){Data = Value;}
    int getData(){return Data;}
    void setLeft(Node *Value){Left = Value;}
    void setRight(Node *Value){Right = Value;}
    Node* getLeft(){return Left;}
    Node* getRight(){return Right;}
};


