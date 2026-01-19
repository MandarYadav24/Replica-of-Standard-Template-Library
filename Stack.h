#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    SinglyLL<T> obj;

public:
    void Push(T no) { obj.InsertFirst(no); }
    void Pop() { obj.DeleteFirst(); }
    void Display() { obj.Display(); }
    int Count() { return obj.Count(); }
};
