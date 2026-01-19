#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    SinglyLL<T> obj;

public:
    void Enqueue(T no) { obj.InsertLast(no); }
    void Dequeue() { obj.DeleteFirst(); }
    void Display() { obj.Display(); }
    int Count() { return obj.Count(); }
};
