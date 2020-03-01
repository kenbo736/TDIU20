#ifndef LISTA_H
#define LISTA_H

#include <iostream>


class Sorted_List{
    public:
    Sorted_List(); //Konstruktor för att kunna hantera en tom lista
    ~Sorted_List(){ Clear(); }

    void Insert(int newData);
    void Remove(int newData);
    void Index(int position);
    void Check();
    void Clear(); //rensar hela listan

    private:
    struct Node
    {
        Node* prev{};
        int data{};
        Node* next{};
    };
    Node* first{};
    Node* last{};
};

#endif
