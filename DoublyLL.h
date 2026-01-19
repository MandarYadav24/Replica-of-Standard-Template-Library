#pragma once
#include <iostream>
using namespace std;

template <class T>
struct DNODE
{
    T data;
    DNODE *next;
    DNODE *prev;
};

template <class T>
class DoublyLL
{
private:
    DNODE<T>* Head;
    int CountNode;

public:
    DoublyLL();

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
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    CountNode = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    DNODE<T>* newn = new DNODE<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = Head;

    if (Head != NULL)
        Head->prev = newn;

    Head = newn;
    CountNode++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    DNODE<T>* newn = new DNODE<T>;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        newn->prev = NULL;
        Head = newn;
    }
    else
    {
        DNODE<T>* temp = Head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newn;
        newn->prev = temp;
    }
    CountNode++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int pos)
{
    if (pos < 1 || pos > CountNode + 1) return;

    if (pos == 1)
        InsertFirst(no);
    else if (pos == CountNode + 1)
        InsertLast(no);
    else
    {
        DNODE<T>* newn = new DNODE<T>;
        newn->data = no;

        DNODE<T>* temp = Head;
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
void DoublyLL<T>::DeleteFirst()
{
    if (!Head) return;

    DNODE<T>* temp = Head;
    Head = Head->next;

    if (Head != NULL)
        Head->prev = NULL;

    delete temp;
    CountNode--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (!Head) return;

    if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        DNODE<T>* temp = Head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }
    CountNode--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > CountNode) return;

    if (pos == 1)
        DeleteFirst();
    else if (pos == CountNode)
        DeleteLast();
    else
    {
        DNODE<T>* temp = Head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        CountNode--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    DNODE<T>* temp = Head;
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return CountNode;
}
