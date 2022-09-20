/** @file test-int-template.cpp
 * @brief Unit tests for Assignment Overloading and Templates
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   June 1, 2021
 *
 * Overload operators for our List<int> user defined type and
 * templatize the class to containt any data type needed
 * in the list.
 *
 * This file contains test cases and individual unit tests for the
 * Assignment Overloading and Templates implementation.  This file uses
 * the catch2 unit test framework to define the test cases and test
 * assertions.
 */
#include "List.hpp"
#include "catch.hpp"
#include <iostream>
using namespace std;

/** Test List template with default constructor can compile
 */
TEST_CASE("List<int> test template class compiles", "[task0]")
{
  List<int> l1;
  // doesn't actually run any tests, so only need to
  // get the default constructor implemented here
}

/** Tests of the List type you have been given to use for
 * this assignment.
 */
TEST_CASE("List<int> test of List user defined type for this assignment", "[task0]")
{
  // construct an empty list
  List<int> l1;
  // CHECK(l1.getSize() == 0);
  // CHECK(l1.getAllocationSize() == 0);
  // CHECK(l1.str() == "<list> size: 0 allocationSize: 0 [ ]");

  // construct with a static array
  int values2[] = {1, 3, -2, -4, 7};
  List<int> l2(5, values2);
  // CHECK(l2.getSize() == 5);
  // CHECK(l2.getAllocationSize() == 5);

  // check the overloaded [] indexing operator
  // CHECK(l2[0] == 1);
  // CHECK(l2[1] == 3);
  // CHECK(l2[2] == -2);
  // CHECK(l2[3] == -4);
  // CHECK(l2[4] == 7);
  // CHECK(l2.str() == "<list> size: 5 allocationSize: 5 [ 1, 3, -2, -4, 7 ]");

  // check we are getting a valid reference back, allows us to modify
  // the list
  // l2[0] = 5;
  // CHECK(l2[0] == 5);

  // l2[4] = -7;
  // CHECK(l2[4] == -7);

  // l2[2] = l2[2] + 12;
  // CHECK(l2[2] == 10);

  // CHECK(l2.str() == "<list> size: 5 allocationSize: 5 [ 5, 3, 10, -4, -7 ]");

  // check that the values were copied into a new block of memory
  // CHECK(values2[0] == 1);
  // CHECK(values2[4] == 7);
  // CHECK(values2[2] == -2);

  // test bounds checking for operator[]
  // CHECK_THROWS_AS(l2[5], ListMemoryBoundsException);
  // CHECK_THROWS_AS(l2[-1], ListMemoryBoundsException);

  // test copy constructor works.
  List<int> l3 = l2;
  // CHECK(l3[0] == 5);
  // CHECK(l3[1] == 3);
  // CHECK(l3[2] == 10);
  // CHECK(l3[3] == -4);
  // CHECK(l3[4] == -7);
  // CHECK(l3.str() == "<list> size: 5 allocationSize: 5 [ 5, 3, 10, -4, -7 ]");

  // make sure l3 is truly a copy of l2
  // l3[0] = 6;
  // l3[2] = 11;
  // l3[4] = -6;
  // CHECK(l3[0] == 6);
  // CHECK(l3[1] == 3);
  // CHECK(l3[2] == 11);
  // CHECK(l3[3] == -4);
  // CHECK(l3[4] == -6);
  // CHECK(l3.str() == "<list> size: 5 allocationSize: 5 [ 6, 3, 11, -4, -6 ]");

  // was l2 modified when we changed l3?
  // CHECK(l2[0] == 5);
  // CHECK(l2[1] == 3);
  // CHECK(l2[2] == 10);
  // CHECK(l2[3] == -4);
  // CHECK(l2[4] == -7);
  // CHECK(l2.str() == "<list> size: 5 allocationSize: 5 [ 5, 3, 10, -4, -7 ]");

  // is l3 modified by changing l2?
  // l2[1] = 13;
  // l2[3] -= 10;
  // CHECK(l2[0] == 5);
  // CHECK(l2[1] == 13);
  // CHECK(l2[2] == 10);
  // CHECK(l2[3] == -14);
  // CHECK(l2[4] == -7);
  // CHECK(l2.str() == "<list> size: 5 allocationSize: 5 [ 5, 13, 10, -14, -7 ]");

  // CHECK(l3[0] == 6);
  // CHECK(l3[1] == 3);
  // CHECK(l3[2] == 11);
  // CHECK(l3[3] == -4);
  // CHECK(l3[4] == -6);
  // CHECK(l3.str() == "<list> size: 5 allocationSize: 5 [ 6, 3, 11, -4, -6 ]");

  // a bit more bounds checking on l3 for operator[]
  // CHECK_THROWS_AS(l3[100], ListMemoryBoundsException);
  // CHECK_THROWS_AS(l3[-100], ListMemoryBoundsException);

  // test overloaded boolean operator==
  // a list should be equal to itself
  // CHECK(l2 == l2);
  // CHECK(l3 == l3);

  // test unequal lists are not equal
  // CHECK_FALSE(l2 == l3);
  // CHECK_FALSE(l3 == l2);

  // test empty lists are equal
  List<int> l4; // another empty list, like l1
  // CHECK(l1 == l4);
  // CHECK(l4 == l1);

  // test that different lists can be equal and not equal again
  // l5 should be a copy of l3, so initially equal
  List<int> l5 = l3;
  // CHECK(l5 == l3);
  // CHECK(l3 == l5);

  // modify 1 value of l5, now lists are not equal
  // l5[3] = 0;
  // CHECK_FALSE(l5 == l3);
  // CHECK_FALSE(l3 == l5);

  // make equal again, and change values on both ends of both lists, just to
  // make sure about ending index manipulations
  // l3[3] = 0;
  // l5[0] = 42;
  // l5[4] = 42;
  // l3[0] = 42;
  // l3[4] = 42;
  // CHECK(l5 == l3);
  // CHECK(l3 == l5);

  // actually haven't checked if lists of unequal size are false yet
  int values6[] = {1, 2, 3};
  List<int> l6(3, values6);
  int values7[] = {1, 2, 3, 4};
  List<int> l7(4, values7);
  // CHECK_FALSE(l6 == l7);
  // CHECK_FALSE(l7 == l6);
}

/** Task 1: implement append() member function operation for List class
 */
/*
TEST_CASE("List<int>::append member function tests",
          "[task1]")
{
  SECTION("grow an initially empty list")
  {
    List<int> l1;

    l1.append(5);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");
  }

  SECTION("keep growing list of values")
  {
    List<int> l1;

    l1.append(5);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");

    l1.append(7);
    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1[1] == 7);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 10 [ 5, 7 ]");

    // add some more
    l1.append(9);
    l1.append(11);
    l1.append(13);
    l1.append(15);
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 5, 7, 9, 11, 13, 15 ]");
  }

  SECTION("test doubling of initially empty list")
  {
    List<int> l1;

    l1.append(5);
    l1.append(7);
    l1.append(9);
    l1.append(11);
    l1.append(13);
    l1.append(15);
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 5, 7, 9, 11, 13, 15 ]");

    // make the list allocation full
    l1.append(17);
    l1.append(19);
    l1.append(21);
    l1.append(23);
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 ]");
    // should cause the list to grow and double in size
    l1.append(25);
    CHECK(l1.getSize() == 11);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 11 allocationSize: 20 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25 ]");

    // add a few more
    l1.append(27);
    l1.append(29);
    l1.append(31);
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 ]");
  }

  SECTION("test appending to non-empty constructed list")
  {
    int l1Values[] = {13, 17};
    List<int> l1(2, l1Values);

    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 2);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 2 [ 13, 17 ]");

    // append causes doubling of size
    l1.append(19);
    CHECK(l1.getSize() == 3);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 3 allocationSize: 4 [ 13, 17, 19 ]");

    // won't grow yet
    l1.append(23);
    CHECK(l1.getSize() == 4);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 4 allocationSize: 4 [ 13, 17, 19, 23 ]");

    // should grow to allocation size of 8
    l1.append(29);
    CHECK(l1.getSize() == 5);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 5 allocationSize: 8 [ 13, 17, 19, 23, 29 ]");

    // won't grow yet
    l1.append(31);
    l1.append(37);
    l1.append(43);
    CHECK(l1.getSize() == 8);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 8 allocationSize: 8 [ 13, 17, 19, 23, 29, 31, 37, 43 ]");

    // allocation grows to 16
    l1.append(47);
    l1.append(51);
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 16);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 16 [ 13, 17, 19, 23, 29, 31, 37, 43, 47, 51 ]");
  }

  SECTION("test returns reference for chaining of method invocations")
  {
    List<int> l1;

    l1.append(5).append(7).append(9).append(11).append(13).append(15);
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 5, 7, 9, 11, 13, 15 ]");

    l1.append(17).append(19).append(21).append(23);
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 ]");
    l1.append(25).append(27).append(29).append(31);
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 ]");
  }
}
*/

/** Task 1: overload operator>>() operation for append for List class
 */
/*
TEST_CASE("List<int>::operator>> overloaded operator tests",
          "[task1]")
{
  SECTION("grow an initially empty list")
  {
    List<int> l1;

    l1 >> 5;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");
  }

  SECTION("keep growing list of values")
  {
    List<int> l1;

    l1 >> 5;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");

    l1 >> 7;
    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1[1] == 7);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 10 [ 5, 7 ]");

    // add some more
    l1 >> 9;
    l1 >> 11;
    l1 >> 13;
    l1 >> 15;
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 5, 7, 9, 11, 13, 15 ]");
  }

  SECTION("test doubling of initially empty list")
  {
    List<int> l1;

    l1 >> 5;
    l1 >> 7;
    l1 >> 9;
    l1 >> 11;
    l1 >> 13;
    l1 >> 15;
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 5, 7, 9, 11, 13, 15 ]");

    // make the list allocation full
    l1 >> 17;
    l1 >> 19;
    l1 >> 21;
    l1 >> 23;
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 ]");
    // should cause the list to grow and double in size
    l1 >> 25;
    CHECK(l1.getSize() == 11);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 11 allocationSize: 20 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25 ]");

    // add a few more
    l1 >> 27;
    l1 >> 29;
    l1 >> 31;
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 ]");
  }

  SECTION("test appending to non-empty constructed list")
  {
    int l1Values[] = {13, 17};
    List<int> l1(2, l1Values);

    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 2);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 2 [ 13, 17 ]");

    // append causes doubling of size
    l1 >> 19;
    CHECK(l1.getSize() == 3);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 3 allocationSize: 4 [ 13, 17, 19 ]");

    // won't grow yet
    l1 >> 23;
    CHECK(l1.getSize() == 4);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 4 allocationSize: 4 [ 13, 17, 19, 23 ]");

    // should grow to allocation size of 8
    l1 >> 29;
    CHECK(l1.getSize() == 5);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 5 allocationSize: 8 [ 13, 17, 19, 23, 29 ]");

    // won't grow yet
    l1 >> 31;
    l1 >> 37;
    l1 >> 43;
    CHECK(l1.getSize() == 8);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 8 allocationSize: 8 [ 13, 17, 19, 23, 29, 31, 37, 43 ]");

    // allocation grows to 16
    l1 >> 47;
    l1 >> 51;
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 16);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 16 [ 13, 17, 19, 23, 29, 31, 37, 43, 47, 51 ]");
  }

  SECTION("test returns reference for chaining of method invocations")
  {
    List<int> l1;

    l1 >> 5 >> 7 >> 9 >> 11 >> 13 >> 15;
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 5, 7, 9, 11, 13, 15 ]");

    l1 >> 17 >> 19 >> 21 >> 23;
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 ]");
    l1 >> 25 >> 27 >> 29 >> 31;
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 ]");
  }
}
*/

/** Task 2: implement prepend() member function operation for List class
 */
/*
TEST_CASE("List<int>::prepend member function tests",
          "[task2]")
{
  SECTION("grow an initially empty list")
  {
    List<int> l1;

    l1.prepend(5);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");
  }

  SECTION("keep prepending and growing list of values")
  {
    List<int> l1;

    l1.prepend(5);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");

    l1.prepend(7);
    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 7);
    CHECK(l1[1] == 5);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 10 [ 7, 5 ]");

    // add some more
    l1.prepend(9);
    l1.prepend(11);
    l1.prepend(13);
    l1.prepend(15);
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 15, 13, 11, 9, 7, 5 ]");
  }

  SECTION("test doubling of initially empty list")
  {
    List<int> l1;

    l1.prepend(5);
    l1.prepend(7);
    l1.prepend(9);
    l1.prepend(11);
    l1.prepend(13);
    l1.prepend(15);
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 15, 13, 11, 9, 7, 5 ]");

    // make the list allocation full
    l1.prepend(17);
    l1.prepend(19);
    l1.prepend(21);
    l1.prepend(23);
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
    // should cause the list to grow and double in size
    l1.prepend(25);
    CHECK(l1.getSize() == 11);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 11 allocationSize: 20 [ 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");

    // add a few more
    l1.prepend(27);
    l1.prepend(29);
    l1.prepend(31);
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
  }

  SECTION("test prepending to non-empty constructed list")
  {
    int l1Values[] = {13, 17};
    List<int> l1(2, l1Values);

    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 2);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 2 [ 13, 17 ]");

    // prepend causes doubling of size
    l1.prepend(19);
    CHECK(l1.getSize() == 3);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 3 allocationSize: 4 [ 19, 13, 17 ]");

    // won't grow yet
    l1.prepend(23);
    CHECK(l1.getSize() == 4);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 4 allocationSize: 4 [ 23, 19, 13, 17 ]");

    // should grow to allocation size of 8
    l1.prepend(29);
    CHECK(l1.getSize() == 5);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 5 allocationSize: 8 [ 29, 23, 19, 13, 17 ]");

    // won't grow yet
    l1.prepend(31);
    l1.prepend(37);
    l1.prepend(43);
    CHECK(l1.getSize() == 8);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 8 allocationSize: 8 [ 43, 37, 31, 29, 23, 19, 13, 17 ]");

    // allocation grows to 16
    l1.prepend(47);
    l1.prepend(51);
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 16);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 16 [ 51, 47, 43, 37, 31, 29, 23, 19, 13, 17 ]");
  }

  SECTION("test returns reference for chaining of method invocations")
  {
    List<int> l1;

    l1.prepend(5).prepend(7).prepend(9).prepend(11).prepend(13).prepend(15);
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 15, 13, 11, 9, 7, 5 ]");

    l1.prepend(17).prepend(19).prepend(21).prepend(23);
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
    l1.prepend(25).prepend(27).prepend(29).prepend(31);
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
  }
}
*/

/** Task 2: overload operator<<() operation for List class prepending
 */
/*
TEST_CASE("List<int>::operator<< overloaded operator prepend tests",
          "[task2]")
{
  SECTION("grow an initially empty list")
  {
    List<int> l1;

    l1 << 5;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");
  }

  SECTION("keep prepending and growing list of values")
  {
    List<int> l1;

    l1 << 5;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 5);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 5 ]");

    l1 << 7;
    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1[0] == 7);
    CHECK(l1[1] == 5);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 10 [ 7, 5 ]");

    // add some more
    l1 << 9;
    l1 << 11;
    l1 << 13;
    l1 << 15;
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 15, 13, 11, 9, 7, 5 ]");
  }

  SECTION("test doubling of initially empty list")
  {
    List<int> l1;

    l1 << 5;
    l1 << 7;
    l1 << 9;
    l1 << 11;
    l1 << 13;
    l1 << 15;
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 15, 13, 11, 9, 7, 5 ]");

    // make the list allocation full
    l1 << 17;
    l1 << 19;
    l1 << 21;
    l1 << 23;
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
    // should cause the list to grow and double in size
    l1 << 25;
    CHECK(l1.getSize() == 11);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 11 allocationSize: 20 [ 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");

    // add a few more
    l1 << 27;
    l1 << 29;
    l1 << 31;
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
  }

  SECTION("test prepending to non-empty constructed list")
  {
    int l1Values[] = {13, 17};
    List<int> l1(2, l1Values);

    CHECK(l1.getSize() == 2);
    CHECK(l1.getAllocationSize() == 2);
    CHECK(l1.str() == "<list> size: 2 allocationSize: 2 [ 13, 17 ]");

    // prepend causes doubling of size
    l1 << 19;
    CHECK(l1.getSize() == 3);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 3 allocationSize: 4 [ 19, 13, 17 ]");

    // won't grow yet
    l1 << 23;
    CHECK(l1.getSize() == 4);
    CHECK(l1.getAllocationSize() == 4);
    CHECK(l1.str() == "<list> size: 4 allocationSize: 4 [ 23, 19, 13, 17 ]");

    // should grow to allocation size of 8
    l1 << 29;
    CHECK(l1.getSize() == 5);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 5 allocationSize: 8 [ 29, 23, 19, 13, 17 ]");

    // won't grow yet
    l1 << 31;
    l1 << 37;
    l1 << 43;
    CHECK(l1.getSize() == 8);
    CHECK(l1.getAllocationSize() == 8);
    CHECK(l1.str() == "<list> size: 8 allocationSize: 8 [ 43, 37, 31, 29, 23, 19, 13, 17 ]");

    // allocation grows to 16
    l1 << 47;
    l1 << 51;
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 16);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 16 [ 51, 47, 43, 37, 31, 29, 23, 19, 13, 17 ]");
  }

  SECTION("test returns reference for chaining of method invocations")
  {
    List<int> l1;

    l1 << 5 << 7 << 9 << 11 << 13 << 15;
    CHECK(l1.getSize() == 6);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 6 allocationSize: 10 [ 15, 13, 11, 9, 7, 5 ]");

    l1 << 17 << 19 << 21 << 23;
    CHECK(l1.getSize() == 10);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 10 allocationSize: 10 [ 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
    l1 << 25 << 27 << 29 << 31;
    CHECK(l1.getSize() == 14);
    CHECK(l1.getAllocationSize() == 20);
    CHECK(l1.str() == "<list> size: 14 allocationSize: 20 [ 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5 ]");
  }
}
*/

/** Task 3: implement concatenate() member function to concatenate
 *    two lists into a new list.
 */
/*
TEST_CASE("List<int>::concatenate concatenate member function tests",
          "[task3]")
{
  SECTION("concatenation of two empty lists should result in an empty list.")
  {
    List<int> l1;
    List<int> l2;
    List<int> l3 = l1.concatenate(l2);

    CHECK(l1.getSize() == 0);
    CHECK(l1.getAllocationSize() == 0);

    CHECK(l2.getSize() == 0);
    CHECK(l2.getAllocationSize() == 0);

    CHECK(l3.getSize() == 0);
    CHECK(l3.getAllocationSize() == 0);
  }

  SECTION("concatenation of list of 1 item with empty list")
  {
    List<int> l1;
    List<int> l2;
    l1 >> 1;
    List<int> l3 = l1.concatenate(l2);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l2.getSize() == 0);
    CHECK(l2.getAllocationSize() == 0);

    CHECK(l3.getSize() == 1);
    CHECK(l3.getAllocationSize() == 1);
    CHECK(l3.str() == "<list> size: 1 allocationSize: 1 [ 1 ]");
  }

  SECTION("concatenation of empty list with list of 1 item")
  {
    List<int> l1;
    List<int> l2;
    l2 >> 1;
    List<int> l3 = l1.concatenate(l2);

    CHECK(l1.getSize() == 0);
    CHECK(l1.getAllocationSize() == 0);

    CHECK(l2.getSize() == 1);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l3.getSize() == 1);
    CHECK(l3.getAllocationSize() == 1);
    CHECK(l3.str() == "<list> size: 1 allocationSize: 1 [ 1 ]");
  }

  SECTION("concatenation of two lists of size 1")
  {
    List<int> l1;
    List<int> l2;
    l1 >> 1;
    l2 >> 2;
    List<int> l3 = l1.concatenate(l2);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l2.getSize() == 1);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 1 allocationSize: 10 [ 2 ]");

    CHECK(l3.getSize() == 2);
    CHECK(l3.getAllocationSize() == 2);
    CHECK(l3.str() == "<list> size: 2 allocationSize: 2 [ 1, 2 ]");

    // if concatenate in other order, should get l2 items first
    List<int> l4 = l2.concatenate(l1);

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l2.getSize() == 1);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 1 allocationSize: 10 [ 2 ]");

    CHECK(l4.getSize() == 2);
    CHECK(l4.getAllocationSize() == 2);
    CHECK(l4.str() == "<list> size: 2 allocationSize: 2 [ 2, 1 ]");

    // l3 and l4 are different Lists, they should not be pointing to same
    // result after second concatenate
    CHECK_FALSE(l3 == l4);
  }

  SECTION("concatenation of two list with a couple of values, one list is full")
  {
    List<int> l1;
    List<int> l2;
    l1 >> 1 << 3 >> 5 << 7 >> 9 << 11 >> 13;
    l2 >> 21 << 23 >> 25 << 27 >> 29 << 31 >> 33 << 35 >> 37 << 39;
    List<int> l3 = l1.concatenate(l2);

    CHECK(l1.getSize() == 7);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 7 allocationSize: 10 [ 11, 7, 3, 1, 5, 9, 13 ]");

    CHECK(l2.getSize() == 10);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 10 allocationSize: 10 [ 39, 35, 31, 27, 23, 21, 25, 29, 33, 37 ]");

    CHECK(l3.getSize() == 17);
    CHECK(l3.getAllocationSize() == 17);
    CHECK(l3.str() == "<list> size: 17 allocationSize: 17 [ 11, 7, 3, 1, 5, 9, 13, 39, 35, 31, 27, 23, 21, 25, 29, 33, 37 ]");

    // if concatenate in other order, should get l2 items first
    List<int> l4 = l2.concatenate(l1);

    CHECK(l1.getSize() == 7);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 7 allocationSize: 10 [ 11, 7, 3, 1, 5, 9, 13 ]");

    CHECK(l2.getSize() == 10);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 10 allocationSize: 10 [ 39, 35, 31, 27, 23, 21, 25, 29, 33, 37 ]");

    CHECK(l4.getSize() == 17);
    CHECK(l4.getAllocationSize() == 17);
    CHECK(l4.str() == "<list> size: 17 allocationSize: 17 [ 39, 35, 31, 27, 23, 21, 25, 29, 33, 37, 11, 7, 3, 1, 5, 9, 13 ]");

    // l3 and l4 are different Lists, they should not be pointing to same
    // result after second concatenate
    CHECK_FALSE(l3 == l4);
  }
}
*/

/** Task 3: implement operator+ overloaded concatenate operator
 */
/*
TEST_CASE("List<int>::operator+ overloaded concatenate operator tests",
          "[task3]")
{
  SECTION("concatenation of two empty lists should result in an empty list.")
  {
    List<int> l1;
    List<int> l2;
    List<int> l3 = l1 + l2;

    CHECK(l1.getSize() == 0);
    CHECK(l1.getAllocationSize() == 0);

    CHECK(l2.getSize() == 0);
    CHECK(l2.getAllocationSize() == 0);

    CHECK(l3.getSize() == 0);
    CHECK(l3.getAllocationSize() == 0);
  }

  SECTION("concatenation of list of 1 item with empty list")
  {
    List<int> l1;
    List<int> l2;
    l1 >> 1;
    List<int> l3 = l1 + l2;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l2.getSize() == 0);
    CHECK(l2.getAllocationSize() == 0);

    CHECK(l3.getSize() == 1);
    CHECK(l3.getAllocationSize() == 1);
    CHECK(l3.str() == "<list> size: 1 allocationSize: 1 [ 1 ]");
  }

  SECTION("concatenation of empty list with list of 1 item")
  {
    List<int> l1;
    List<int> l2;
    l2 >> 1;
    List<int> l3 = l1 + l2;

    CHECK(l1.getSize() == 0);
    CHECK(l1.getAllocationSize() == 0);

    CHECK(l2.getSize() == 1);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l3.getSize() == 1);
    CHECK(l3.getAllocationSize() == 1);
    CHECK(l3.str() == "<list> size: 1 allocationSize: 1 [ 1 ]");
  }

  SECTION("concatenation of two lists of size 1")
  {
    List<int> l1;
    List<int> l2;
    l1 >> 1;
    l2 >> 2;
    List<int> l3 = l1 + l2;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l2.getSize() == 1);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 1 allocationSize: 10 [ 2 ]");

    CHECK(l3.getSize() == 2);
    CHECK(l3.getAllocationSize() == 2);
    CHECK(l3.str() == "<list> size: 2 allocationSize: 2 [ 1, 2 ]");

    // if concatenate in other order, should get l2 items first
    List<int> l4 = l2 + l1;

    CHECK(l1.getSize() == 1);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 1 allocationSize: 10 [ 1 ]");

    CHECK(l2.getSize() == 1);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 1 allocationSize: 10 [ 2 ]");

    CHECK(l4.getSize() == 2);
    CHECK(l4.getAllocationSize() == 2);
    CHECK(l4.str() == "<list> size: 2 allocationSize: 2 [ 2, 1 ]");

    // l3 and l4 are different Lists, they should not be pointing to same
    // result after second concatenate
    CHECK_FALSE(l3 == l4);
  }

  SECTION("concatenation of two list with a couple of values, one list is full")
  {
    List<int> l1;
    List<int> l2;
    l1 >> 1 << 3 >> 5 << 7 >> 9 << 11 >> 13;
    l2 >> 21 << 23 >> 25 << 27 >> 29 << 31 >> 33 << 35 >> 37 << 39;
    List<int> l3 = l1 + l2;

    CHECK(l1.getSize() == 7);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 7 allocationSize: 10 [ 11, 7, 3, 1, 5, 9, 13 ]");

    CHECK(l2.getSize() == 10);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 10 allocationSize: 10 [ 39, 35, 31, 27, 23, 21, 25, 29, 33, 37 ]");

    CHECK(l3.getSize() == 17);
    CHECK(l3.getAllocationSize() == 17);
    CHECK(l3.str() == "<list> size: 17 allocationSize: 17 [ 11, 7, 3, 1, 5, 9, 13, 39, 35, 31, 27, 23, 21, 25, 29, 33, 37 ]");

    // if concatenate in other order, should get l2 items first
    List<int> l4 = l2 + l1;

    CHECK(l1.getSize() == 7);
    CHECK(l1.getAllocationSize() == 10);
    CHECK(l1.str() == "<list> size: 7 allocationSize: 10 [ 11, 7, 3, 1, 5, 9, 13 ]");

    CHECK(l2.getSize() == 10);
    CHECK(l2.getAllocationSize() == 10);
    CHECK(l2.str() == "<list> size: 10 allocationSize: 10 [ 39, 35, 31, 27, 23, 21, 25, 29, 33, 37 ]");

    CHECK(l4.getSize() == 17);
    CHECK(l4.getAllocationSize() == 17);
    CHECK(l4.str() == "<list> size: 17 allocationSize: 17 [ 39, 35, 31, 27, 23, 21, 25, 29, 33, 37, 11, 7, 3, 1, 5, 9, 13 ]");

    // l3 and l4 are different Lists, they should not be pointing to same
    // result after second concatenate
    CHECK_FALSE(l3 == l4);
  }
}
*/
