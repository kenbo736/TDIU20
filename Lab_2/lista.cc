#include <iostream>
#include "lista.h"

Sorted_List::Sorted_List()
{
        Node* dum = new Node; //Skapar en sentinel
        first = dum; //First pekar dum
        last = dum; //Last pekar på dum
        dum->next = nullptr;
        dum->prev = nullptr;
}

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

        while(pos->data < newNode->data) //medans mindre  
        {
          if(pos->next->data < newNode->data) //om det som det pekar på två framför är nullptr
          {
            if(pos->next->next == nullptr) // om den är i slutet
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
        break;
      }
    }
}
void Sorted_List::Remove(int newData)
{
  Node* pos = first;
  while(pos->data < newData)
  {
    pos = pos->next;
  }

  if(pos->data == newData) //Kollar om positonens data är samma sak som det vi vill ta bort
  {
      if (pos == last)
      { 
        std::cout << "sista elementet :( :( :(" << std::endl; 
        return; 
      }

      pos->next->prev = pos->prev;

      if (pos == first) 
      {
        first = pos->next;
      } 
      else 
      {
        pos->prev->next = pos->next;
      }
      delete pos;
  }
}
void Sorted_List::Index(int position)
{
  int index{};
  Node* pos = first;
  while(index < position)
  {
    pos = pos->next;
    index = index + 1;
  }
  std::cout << "INDEX: " << position << " har värdet " << pos->data << " i sig. " << std::endl;
}

void Sorted_List::Clear() {
  Node* pos = first;
  while(pos != last) {
    pos = pos->next;
    delete first;
    first = pos;
  }
  last->prev = nullptr;
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
    if((pos->next == nullptr) && (pos->prev != nullptr))
    {

            std::cout << " --------" << std::endl;
            std::cout << "|Prev " << pos->prev->data << "  |" << std::endl;
            std::cout << "|   " << pos->data << "    | <-------------THIS IS THE SENTINEL" << std::endl;
            std::cout << "| NULL   |" << std::endl;
            std::cout << " --------" << std::endl;
    }
    else
    {
            std::cout << " --------" << std::endl;
            std::cout << "| NULL   |" << std::endl;
            std::cout << "|   " << first->data << "    |" << std::endl;
            std::cout << "|Next  " << pos->next->next->data << " |" << std::endl;
            std::cout << " --------" << std::endl;
    }
}
