#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "lista.h"

using namespace std;
// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut


TEST_CASE ("insert function")
{
  Sorted_List l;
  l.insert(5);
  l.insert(3);
  l.insert(9);
  l.insert(2);

  CHECK(l.size() == 4);
  CHECK_FALSE(l.empty());
  l.clear();
  CHECK(l.empty());
  CHECK(l.size() == 0 );
}

TEST_CASE ("remove function")
{

  Sorted_List l;
//  l.remove(13);
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);

  l.remove(2);
  CHECK(l.size() == 3);
  //l.remove(15);
  CHECK_FALSE(l.empty());

}

TEST_CASE ("remove 2 function") 
{

  Sorted_List l;
//  l.remove(13);

  l.remove(3);
  CHECK(l.size() == 0);
  //l.remove(15);
  CHECK(l.empty());

}


TEST_CASE ("copy function")
{

  Sorted_List l;
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  Sorted_List l2;

  l2=l;

  CHECK(l2.at(1) == 1);
  CHECK(l2.at(2) == 2);
  CHECK(l2.at(3) == 3);
  CHECK(l2.at(4) == 4);
  CHECK(l.at(1) == 1);
  CHECK(l.at(2) == 2);
  CHECK(l.at(3) == 3);
  CHECK(l.at(4) == 4);
  CHECK_FALSE(l.at(1) == 4);
  CHECK_FALSE(l.empty());
  CHECK(l.size() == 4);
  CHECK(l2.size() == 4);
}


TEST_CASE("insert into an empty list")
{
  Sorted_List a{};

  CHECK(a.size() == 0);

  a.insert(7);
  CHECK(a.size() == 1);
  CHECK(a.at(0 + 1) == 7);

  CHECK_THROWS(a.at(1 + 1));

  //insert at beginninrg

  a.insert(3);
  CHECK(a.size() == 2);
  CHECK(a.at(0 + 1) == 3);
  CHECK(a.at(1 + 1) == 7);
  CHECK_THROWS(a.at(2 + 1));

  //insert in middle

  a.insert(5);
  CHECK(a.size() == 3);
  CHECK(a.at(0 + 1) == 3);
  CHECK(a.at(1 + 1) == 5);
  CHECK(a.at(2 + 1) == 7);
  CHECK_THROWS(a.at(3 + 1));

  //insert at end
  a.insert(9);
  CHECK(a.size() == 4);
  CHECK(a.at(0 + 1) == 3);
  CHECK(a.at(1 + 1) == 5);
  CHECK(a.at(2 + 1) == 7);
  CHECK(a.at(3 + 1) == 9);
  CHECK_THROWS(a.at(4 + 1));
}


TEST_CASE("insert into an existing list")
{
  Sorted_List a{5,3,9,8};

  CHECK(a.size() == 4);

  a.insert(7);
  CHECK(a.size() == 5);
  CHECK(a.at(0 + 1) == 3);
  CHECK(a.at(1 + 1) == 5);
  CHECK(a.at(2 + 1) == 7);
  CHECK(a.at(3 + 1) == 8);
  CHECK(a.at(4 + 1) == 9);

  CHECK_THROWS(a.at(5 + 1));

  //insert at beginninrg

  a.insert(1);
  CHECK(a.size() == 6);
  CHECK(a.at(0 + 1) == 1);
  CHECK(a.at(1 + 1) == 3);
  CHECK(a.at(2 + 1) == 5);
  CHECK(a.at(3 + 1) == 7);
  CHECK(a.at(4 + 1) == 8);
  CHECK(a.at(5 + 1) == 9);

  CHECK_THROWS(a.at(6 + 1));

  //insert in middle

  a.insert(5);
  CHECK(a.size() == 7);
  CHECK(a.at(0 + 1) == 1);
  CHECK(a.at(1 + 1) == 3);
  CHECK(a.at(2 + 1) == 5);
  CHECK(a.at(3 + 1) == 5);
  CHECK(a.at(4 + 1) == 7);
  CHECK(a.at(5 + 1) == 8);
  CHECK(a.at(6 + 1) == 9);
  CHECK_THROWS(a.at(7 + 1));

  //insert at end
  a.insert(9);
  CHECK(a.size() == 8);
  CHECK(a.at(0 + 1) == 1);
  CHECK(a.at(1 + 1) == 3);
  CHECK(a.at(2 + 1) == 5);
  CHECK(a.at(3 + 1) == 5);
  CHECK(a.at(4 + 1) == 7);
  CHECK(a.at(5 + 1) == 8);
  CHECK(a.at(6 + 1) == 9);
  CHECK(a.at(7 + 1) == 9);
  CHECK_THROWS(a.at(8 + 1));
}

TEST_CASE("empty constructor")
{
  Sorted_List const a;
  CHECK(a.size() == 0);
  CHECK_THROWS(a.at(-1));
  CHECK_THROWS(a.at(0));
  CHECK_THROWS(a.at(1));
}

TEST_CASE ("initializer_list check")
{
  Sorted_List l{8, 10, 11, 8, 9, 69, 40};
  CHECK(l.at(1) == 8);
  CHECK(l.at(2) == 8);
  CHECK(l.at(3) == 9);
  CHECK(l.at(4) == 10);
  CHECK(l.at(5) == 11);
  CHECK(l.at(6) == 40);
  CHECK(l.at(7) == 69);
  CHECK(l.size() == 7);
  CHECK_FALSE(l.empty());
}


TEST_CASE ("default konstruktor")
{
  Sorted_List l;
  CHECK(l.empty());
}

TEST_CASE ( "Size" )
{
  Sorted_List l;
  CHECK(l.size() == 0);
}


// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases
#if 0

#endif
