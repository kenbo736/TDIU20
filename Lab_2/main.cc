#include <iostream>
#include "lista.h"

int main()
{
    Sorted_List empty_list{};
    empty_list.Insert(1);
    empty_list.Insert(4);
    empty_list.Insert(7);
    empty_list.Insert(3);
    empty_list.Insert(3);

    empty_list.Check();


    return 0;
}
