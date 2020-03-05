#include <iostream>
#include "lista.h"

int main()
{
    Sorted_List empty_list{};
    empty_list.insert(5);
    empty_list.insert(3);
    empty_list.insert(1);
    empty_list.insert(9);
    empty_list.insert(7);
    empty_list.insert(3);
    //empty_list.remove(3);
    //empty_list.remove(9);
    //empty_list.index(4);
    //empty_list.display();
    //empty_list.index(1);
    //empty_list.index(2);
    //empty_list.index(3);
    //empty_list.index(-2);
    empty_list.remove(1);
    //empty_list.clear();
    empty_list.display();
    //Sorted_List list2{empty_list};
    //list2.display();
    Sorted_List list3{};
    list3 = empty_list;
    //list3.Display();
    Sorted_List listA{};
    Sorted_List listB{std::move(listA)};
    Sorted_List listC{};
    listC = std::move(listA);
    

    return 0;
}
