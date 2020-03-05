#include <iostream>
#include "lista.h"
#include <stdexcept>
#include <utility>
#include <initializer_list>

Sorted_List::Sorted_List()
{
  Node* dum = new Node; //Skapar en sentinel
  first = dum; //First pekar dum
  last = dum; //Last pekar på dum
  dum->next = nullptr;
  dum->prev = nullptr;
}

Sorted_List::Sorted_List(std::initializer_list<int> const &lista) : Sorted_List()
{
  for(int element : lista)
  {
    insert(element);
  }
}

Sorted_List::Sorted_List(Sorted_List const &old_list) : Sorted_List()
{
  copy(old_list);
}

Sorted_List::Sorted_List(Sorted_List &&old_list) : Sorted_List()
{

  std::swap(old_list.first, first);
  std::swap(old_list.last, last);
}

Sorted_List::~Sorted_List()
{ 
  clear(); 
}

void Sorted_List::copy(Sorted_List const &old_list)
{
  Node* pos = old_list.last->prev;
  
  while(pos != old_list.first)
  {
    insert(pos->data);
    pos = pos->prev;
  }
  if(pos == old_list.first)
  {
    insert(pos->data);
  }
}

Sorted_List& Sorted_List::operator=(Sorted_List const &old_list)
{
  clear(); // deallokerar
  copy(old_list); // Kopierar till den nya listan
  return *this;
}

Sorted_List& Sorted_List::operator=(Sorted_List &&old_list)
{
  std::swap(old_list.first, first);
  std::swap(old_list.last, last);
  return *this;
}

void Sorted_List::insert(const int newData)
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
void Sorted_List::remove(const int newData)
{
  Node* pos = first;
  while(pos->data < newData) // kollar om datan är mindre än det vi jämför med
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
int Sorted_List::index(const int position) const
{
  int lengthOfList{};
  Node* pos = first;
  while(pos != last)
  {
    pos = pos->next;
    lengthOfList++;
  }

  if((lengthOfList < position) || (position < 0))
  {
    std::cout << "out of border" << std::endl;
  }
  else
  {
    pos = first;
    for(int i=0; i < position; i++)
    {
      pos=pos->next;
    }
    std::cout << "INDEX: " << position << " har värdet " << pos->data << " i sig. " << std::endl;
  }
  return pos->data;
}

void Sorted_List::clear() 
{
  Node* pos = first;
  while(pos != last) {
    pos = pos->next;
    delete first;
    first = pos;
  }
  last->prev = nullptr;
}

void Sorted_List::display() const
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
