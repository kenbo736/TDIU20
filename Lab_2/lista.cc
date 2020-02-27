#include <iostream>
#include "lista.h"
 
void Sorted_List::Insert(int newData)
{
    Node* newNode = new Node;
    Node* pos;
    pos = first;
    newNode->data = newData;
    if(first == last) //Fallet där listan är tom och man ska lägga in sin första insertion
    {
        newNode->next = last; //Vi säger åt nya nodens next att ha samma adress som last peka på
        first = newNode; //Här säger vi åt first att peka på den nya noden istället för dummyn
        last->prev = newNode;
        //std::cout << newNode->data << std::endl;
    }
    else //Annars om listan har en nod i sig
    {
        while(pos->next != nullptr) //Medan det som pos pekar på vars next inte lika med nullptr
        {
            
            std::cout << pos->data << "   " << newNode->data << std::endl;
            
            if(pos->data <= newNode->data) //Kollar om datan är mindre än den nya nodens data
            {   
                if(pos->next == nullptr)
                {
                    newNode->prev = pos; //nodens prev peka på det som pos pekar på
                    newNode->next = pos->next; //här säger vi att den nya nodens next ska peka på nästa nod från det som pos next pekar på
                    pos->next = newNode;
                    pos->next->prev = newNode;
                }
                else
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
                            if(pos->next->next == nullptr) //om det som det pekar på två framför är nullptr
                            {
                                newNode->prev = pos; //nodens prev peka på det som pos pekar på
                                newNode->next = pos->next; //här säger vi att den nya nodens next ska peka på nästa nod från det som pos next pekar på
                                pos->next = newNode;
                                pos->next->prev = newNode;
                                break;
                            }
                            pos=pos->next;
                        }

                    }
                }
            break;
            }
            else if(pos->data >= newNode->data) //om pos data är större än newNodes data
            {
                
                newNode->next = pos;
                if(pos->prev == nullptr) //om det är första noden så är det en nullptr
                {
                    newNode->next = pos;
                    pos->prev = newNode;
                    first = newNode;       
                }
                else
                {
                    newNode->prev = pos->prev;
                    pos->prev->next = newNode;
                    pos->prev = newNode;
                }
                break;
            }




        }
        //std::cout << pos->next->data << std::endl;
    }
    //std::cout << pos->data << std::endl;
    //std::cout << pos->prev->data << std::endl;
}
void Sorted_List::Check()
{
    Node* pos = first;
    while(pos->next != nullptr)
    {
        std::cout << "--------" << std::endl;
        std::cout << "|      |" << std::endl;
        std::cout << "|  " << pos->data << "   |" << std::endl;
        std::cout << "|      |" << std::endl;
        std::cout << "--------" << std::endl;
        std::cout << "  |  A  " << std::endl;
        std::cout << "  v  |  " << std::endl;
        pos = pos->next;
        if(pos->data == 0)
        {
            std::cout << "--------" << std::endl;
            std::cout << "|      |" << std::endl;
            std::cout << "|  " << pos->data << "   |" << std::endl;
            std::cout << "|      |" << std::endl;
            std::cout << "--------" << std::endl;
        }
    }
}