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
              if(pos->next->next == nullptr) //undantag
              {
                newNode->prev = pos; //nodens prev peka på det som pos pekar på
                //std::cout << pos->data << "            " << newNode->prev->data << std::endl;
                newNode->next = pos->next; //här säger vi att den nya nodens next ska peka på nästa nod från det som pos next pekar på
                //std::cout << pos->next->data << "            " << newNode->next->data << std::endl;
                pos->next = newNode;
                //std::cout << pos->next->data << std::endl;
                newNode->next->prev = newNode;
                //std::cout << pos->next->prev->data << std::endl;
                //std::cout << pos->prev->data << std::endl;
              }
              else
              {
                while(pos->data < newNode->data) //medans mindre
                {
                  if(pos->next->data < newNode->data) //om det som det pekar på två framför är nullptr
                  {
                    if(pos->next->next == nullptr)
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
                newNode->next->prev = newNode;
              }
              break;
            }
        }
    }
}
void Sorted_List::Remove(int newData)
{
  Node* temp;
  Node* pos = first;

  while(pos->data < newData)
  {
    //std::cout << pos->data << std::endl;
    pos = pos->next;
  }
  std::cout << "temp: next-> "<< pos->next->data << "    Data:" << pos->data  << "     prev->" << pos->prev->data << std::endl;
  if(pos->data == newData) //Kollar om positonens data är samma sak som det vi vill ta bort
  {
    
    //std::cout << pos->next->prev->data << std::endl;

    pos->next->prev = pos->prev;
    temp = pos;
    pos->prev->next = pos->next;
    std::cout << temp->data << std::endl;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp;
  }
}
void Sorted_List::Check()
{
    Node* pos = first;
    std::cout << "------------------------UTSKRIFT------------------------------" << std::endl;
    std::cout << "   " << std::endl;
    while(pos->next != nullptr)
    {
        if(pos->prev == nullptr)
        {
        std::cout << " --------" << std::endl;
        std::cout << "| NULL   |" << std::endl;
        std::cout << "|   " << pos->data << "    |" << std::endl;
        std::cout << "|Next " << pos->next->data << "  |" << std::endl;
        std::cout << " --------" << std::endl;
        std::cout << "  |  ^  " << std::endl;
        std::cout << "  v  |  " << std::endl;
        pos = pos->next;
        }
        else if(pos->next == nullptr)
        {
            std::cout << " --------" << std::endl;
            std::cout << "|        |" << std::endl;
            std::cout << "|   " << pos->data << "    |" << std::endl;
            std::cout << "| NULL   |" << std::endl;
            std::cout << " --------" << std::endl;
        }
        else
        {
            std::cout << " --------" << std::endl;
            std::cout << "|Prev "<< pos->prev->data <<"  |" << std::endl;
            std::cout << "|   " << pos->data << "    |" << std::endl;
            std::cout << "|Next " << pos->next->data << "  |" << std::endl;
            std::cout << " --------" << std::endl;
            std::cout << "  |  ^  " << std::endl;
            std::cout << "  v  |  " << std::endl;
            pos = pos->next;
        }
    }
}
