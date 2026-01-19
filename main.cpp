#include <iostream>

#include "SinglyLL.h"
#include "SinglyCL.h"
#include "DoublyLL.h"
#include "DoublyCL.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    cout << "\n--- Singly Linear Linked List ---\n";
    SinglyLL<int> sll;
    sll.InsertFirst(10);
    sll.InsertLast(20);
    sll.InsertAtPos(15, 2);
    sll.Display();
    sll.DeleteAtPos(2);
    sll.Display();

    cout << "\n--- Singly Circular Linked List ---\n";
    SinglyCL<int> scl;
    scl.InsertFirst(11);
    scl.InsertLast(21);
    scl.InsertAtPos(16, 2);
    scl.Display();

    cout << "\n--- Doubly Linear Linked List ---\n";
    DoublyLL<int> dll;
    dll.InsertFirst(30);
    dll.InsertLast(40);
    dll.InsertAtPos(35, 2);
    dll.Display();
    dll.DeleteAtPos(2);
    dll.Display();

    cout << "\n--- Doubly Circular Linked List ---\n";
    DoublyCL<int> dcl;
    dcl.InsertFirst(50);
    dcl.InsertLast(60);
    dcl.InsertAtPos(55, 2);
    dcl.Display();

    cout << "\n--- Stack ---\n";
    Stack<int> st;
    st.Push(100);
    st.Push(200);
    st.Display();

    cout << "\n--- Queue ---\n";
    Queue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Display();

    return 0;
}
