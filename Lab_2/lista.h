#ifndef LISTA_H
#define LISTA_H

#include <iostream>


class Sorted_List{
    public:
    Sorted_List() //Konstruktor för att kunna hantera en tom lista
    {
        Node* dum = new Node; //Skapar en sentinel
        first = dum; //First pekar dum
        last = dum; //Last pekar på dum
        dum->next = nullptr;
        dum->prev = nullptr;
    }
    //~Sorted_List();
    void Insert(int newData);
    void Check();
    private:
    struct Node
    {
        Node* prev;
        int data;
        Node* next;
    };
    Node* first{};
    Node* last{};
};

#endif
