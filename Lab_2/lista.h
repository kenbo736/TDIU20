#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <utility>

class Sorted_List{
    public:
    Sorted_List(); // Konstruktor för att kunna hantera en tom lista
    Sorted_List(Sorted_List const &old_list); // Copy konstructor
    Sorted_List(Sorted_List &&old_list); // Move konstruktor
    Sorted_List(std::initializer_list<int> const &lista);
    ~Sorted_List();

    Sorted_List &operator=(Sorted_List const &old_list); // Copy assignment
    Sorted_List &operator=(Sorted_List &&old_list); // Move assignment

    void insert(int const newData);
    void remove(int const newData);
    int index(int const position) const;
    void copy(Sorted_List const &old_list); //kopierar listan
    void display() const;
    void clear(); //rensar hela listan

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
