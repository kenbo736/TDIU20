#include <iostream>
#include "lista.h"

int main()
{
    Sorted_List empty_list{};
    empty_list.Insert(5);
    empty_list.Insert(3);
    empty_list.Insert(1);
    empty_list.Insert(9);
    empty_list.Insert(7);
    empty_list.Insert(3);
    //empty_list.Remove(3);
    //empty_list.Remove(9);
    empty_list.Index(0);
    empty_list.Index(1);
    empty_list.Index(2);
    empty_list.Index(3);
    empty_list.Index(-2);
    //empty_list.Remove(1);
    //empty_list.Clear();
    empty_list.Display();
    Sorted_List list2{empty_list};
    list2.Display();

    return 0;
}
