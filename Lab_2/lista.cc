#include <iostream>
#include "lista.h"

void Sorted_List::Insert(int newData)
{
    Node* newNode = new Node;
    Node* pos;
    pos = first;
    newNode->data = newData;
    if(first == last) //Fallet där listan är tom och man ska lägga in sin första insertion UNDANTAG
    {
        newNode->next = last; //Vi säger åt nya nodens next att ha samma adress som last peka på
        first = newNode; //Här säger vi åt first att peka på den nya noden istället för dummyn
        last->prev = newNode;
    }
    else //Annars om listan har en nod i sig
    {
        while(pos->next != nullptr) //Medan det som pos pekar på vars next inte lika med nullptr
        {
            if(pos->data >= newNode->data)//händer bara om första insättningen är större än positionens värde
            {
                newNode->next = pos;
                pos->prev = newNode;
                first = newNode;

                break;
            }
            else if(pos->data <= newNode->data) //Kollar om datan är mindre än den nya nodens data
            {
              if(pos->next->next == 0) //undantag
              {
                newNode->prev = pos; //nodens prev peka på det som pos pekar på
                newNode->next = pos->next; //här säger vi att den nya nodens next ska peka på nästa nod från det som pos next pekar på
                pos->next = newNode;
                pos->next->prev = newNode;
              }
              else
              {
                while(pos->data < newNode->data) //medans mindre
                {
                  if(pos->next->data < newNode->data) //om det som det pekar på två framför är nullptr
                  {
                    if(pos->next->data == 0)
                    {
                      break;
                    }
                    pos = pos->next;
                  }
                  else
                  {
                    break;
                  }
                }
                newNode->prev = pos; //nodens prev peka på det som pos pekar på
                newNode->next = pos->next; //här säger vi att den nya nodens next ska peka på nästa nod från det som pos next pekar på
                pos->next = newNode;
                pos->next->prev = newNode;
              }
              break;
            }
        }
    }
}
void Sorted_List::Remove(int newData)
{

}
void Sorted_List::Check()
{
    Node* pos = first;
    std::cout << "------------------------UTSKRIFT------------------------------" << std::endl;
    std::cout << "   " << std::endl;
    while(pos->next != nullptr)
    {
        std::cout << " --------" << std::endl;
        std::cout << "|        |" << std::endl;
        std::cout << "|   " << pos->data << "    |" << std::endl;
        std::cout << "|        |" << std::endl;
        std::cout << " --------" << std::endl;
        std::cout << "  |  ^  " << std::endl;
        std::cout << "  v  |  " << std::endl;
        pos = pos->next;
        if(pos->data == 0)
        {
            std::cout << " --------" << std::endl;
            std::cout << "|        |" << std::endl;
            std::cout << "|   " << pos->data << "    |" << std::endl;
            std::cout << "|        |" << std::endl;
            std::cout << " --------" << std::endl;
        }
    }
}
