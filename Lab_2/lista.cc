#include <iostream>
#include "lista.h"
 
void Sorted_List::Insert(int newData)
{
    Node* newNode = new Node;
    newNode->data = newData;
    if(first == last) //Fallet där listan är tom och man ska lägga in sin första insertion
    {
        newNode->next = last; //Vi säger åt nya nodens next att ha samma adress som last peka på
        first = newNode; //Här säger vi åt first att peka på den nya noden istället för dummyn
        //std::cout << newNode->data;
        

    }
}