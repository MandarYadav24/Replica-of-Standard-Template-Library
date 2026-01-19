#pragma once
#include <iostream>
using namespace std;

template <class T>
struct SCNODE
{
    T data;
    SCNODE *next;
};

template <class T>
class SinglyCL
{
private:
    SCNODE<T>* Head;
    SCNODE<T>* Tail;
    int CountNode;

public:
    SinglyCL();
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
SinglyCL<T>::SinglyCL()
{
    Head = Tail = NULL;
    CountNode = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    SCNODE<T>* newn = new SCNODE<T>;
    newn->data = no;

    if (!Head)
    {
        Head = Tail = newn;
        newn->next = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
        Tail->next = Head;
    }
    CountNode++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    SCNODE<T>* newn = new SCNODE<T>;
    newn->data = no;

    if (!Head)
    {
        Head = Tail = newn;
        newn->next = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
        Tail->next = Head;
    }
    CountNode++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > CountNode + 1) return;

    if (pos == 1)
        InsertFirst(no);
    else if (pos == CountNode + 1)
        InsertLast(no);
    else
    {
        SCNODE<T>* newn = new SCNODE<T>;
        newn->data = no;

        SCNODE<T>* temp = Head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        temp->next = newn;
        CountNode++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (!Head) return;

    if (Head == Tail)
    {
        delete Head;
        Head = Tail = NULL;
    }
    else
    {
        SCNODE<T>* temp = Head;
        Head = Head->next;
        delete temp;
        Tail->next = Head;
    }
    CountNode--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (!Head) return;

    if (Head == Tail)
    {
        delete Head;
        Head = Tail = NULL;
    }
    else
    {
        SCNODE<T>* temp = Head;
        while (temp->next != Tail)
            temp = temp->next;

        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
    CountNode--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > CountNode) return;

    if (pos == 1)
        DeleteFirst();
    else if (pos == CountNode)
        DeleteLast();
    else
    {
        SCNODE<T>* temp = Head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        SCNODE<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        CountNode--;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    if (!Head) return;

    SCNODE<T>* temp = Head;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Head);
    cout << "(HEAD)\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return CountNode;
}
