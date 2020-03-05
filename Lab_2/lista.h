#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <utility>

class Sorted_List{
    public:
    Sorted_List(); // Konstruktor för att kunna hantera en tom lista
    Sorted_List(const Sorted_List &old_list); // Copy konstructor
    Sorted_List(Sorted_List &&old_list); // Move konstruktor
    ~Sorted_List();

    Sorted_List &operator=(const Sorted_List &old_list); // Copy assignment
    Sorted_List &operator=(Sorted_List &&old_list); // Move assignment

    void Insert(int newData);
    void Remove(int newData);
    void Index(int position);
    void Copy(const Sorted_List &old_list); //kopierar listan
    void Display() const;
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
