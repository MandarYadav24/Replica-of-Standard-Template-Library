#pragma once
#include <iostream>
using namespace std;

template <class T>
struct DCNODE
{
    T data;
    DCNODE *next;
    DCNODE *prev;
};

template <class T>
class DoublyCL
{
private:
    DCNODE<T>* Head;
    DCNODE<T>* Tail;
    int CountNode;

public:
    DoublyCL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    Head = Tail = NULL;
    CountNode = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    DCNODE<T>* newn = new DCNODE<T>;
    newn->data = no;

    if (!Head)
    {
        Head = Tail = newn;
        Head->next = Head;
        Head->prev = Head;
    }
    else
    {
        newn->next = Head;
        newn->prev = Tail;

        Head->prev = newn;
        Tail->next = newn;

        Head = newn;
    }
    CountNode++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    DCNODE<T>* newn = new DCNODE<T>;
    newn->data = no;

    if (!Head)
    {
        Head = Tail = newn;
        Head->next = Head;
        Head->prev = Head;
    }
    else
    {
        newn->next = Head;
        newn->prev = Tail;

        Tail->next = newn;
        Head->prev = newn;

        Tail = newn;
    }
    CountNode++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > CountNode + 1) return;

    if (pos == 1)
        InsertFirst(no);
    else if (pos == CountNode + 1)
        InsertLast(no);
    else
    {
        DCNODE<T>* newn = new DCNODE<T>;
        newn->data = no;

        DCNODE<T>* temp = Head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        CountNode++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (!Head) return;

    if (Head == Tail)
    {
        delete Head;
        Head = Tail = NULL;
    }
    else
    {
        DCNODE<T>* temp = Head;
        Head = Head->next;

        Head->prev = Tail;
        Tail->next = Head;

        delete temp;
    }
    CountNode--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (!Head) return;

    if (Head == Tail)
    {
        delete Head;
        Head = Tail = NULL;
    }
    else
    {
        DCNODE<T>* temp = Tail;
        Tail = Tail->prev;

        Tail->next = Head;
        Head->prev = Tail;

        delete temp;
    }
    CountNode--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > CountNode) return;

    if (pos == 1)
        DeleteFirst();
    else if (pos == CountNode)
        DeleteLast();
    else
    {
        DCNODE<T>* temp = Head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        CountNode--;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    if (!Head) return;

    DCNODE<T>* temp = Head;
    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    } while (temp != Head);

    cout << "(HEAD)\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return CountNode;
}
