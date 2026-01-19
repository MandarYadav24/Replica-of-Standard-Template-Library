#pragma once
#include <iostream>
using namespace std;

template <class T>
struct SNODE
{
    T data;
    SNODE *next;
};

template <class T>
class SinglyLL
{
private:
    SNODE<T>* Head;
    int CountNode;

public:
    SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    CountNode = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    SNODE<T>* newn = new SNODE<T>;
    newn->data = no;
    newn->next = Head;
    Head = newn;
    CountNode++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    SNODE<T>* newn = new SNODE<T>;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
        Head = newn;
    else
    {
        SNODE<T>* temp = Head;
        while (temp->next)
            temp = temp->next;
        temp->next = newn;
    }
    CountNode++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > CountNode + 1) return;

    if (pos == 1)
        InsertFirst(no);
    else if (pos == CountNode + 1)
        InsertLast(no);
    else
    {
        SNODE<T>* newn = new SNODE<T>;
        newn->data = no;

        SNODE<T>* temp = Head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        temp->next = newn;
        CountNode++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (!Head) return;
    SNODE<T>* temp = Head;
    Head = Head->next;
    delete temp;
    CountNode--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (!Head) return;

    if (!Head->next)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        SNODE<T>* temp = Head;
        while (temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }
    CountNode--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > CountNode) return;

    if (pos == 1)
        DeleteFirst();
    else if (pos == CountNode)
        DeleteLast();
    else
    {
        SNODE<T>* temp = Head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        SNODE<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        CountNode--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    SNODE<T>* temp = Head;
    while (temp)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return CountNode;
}
