/** @file List.cpp
 * @brief Implementations of member functions of the List
 *   of ints class for the Assignment Overloading and Templates
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Overloading and Templates
 * @date   June 1, 2021
 *
 * Implementations of a List of ints ADT.  Sort of a preview
 * of some of the data structures and abstract data types we
 * will be learning to build and understand.
 */
#include "List.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/** @brief  Default constructor
 *
 * Construct an empty list.  The empty list will have no allocated memory
 * nor any values.
 */
template<class T>
List<T>::List()
{
  // Empty list has no values nor any allocated memory
  // associated with it
  this->size = 0;
  this->allocationSize = 0;
  values = nullptr;
}

/** @brief Standard constructor
 *
 * Construct a list of integer values from a (statically) defined and
 * provided array of integers.  We simply allocate a block of memory
 * dynamically large enough to hold the values, then copy the values
 * from the input parameter into our own private array of values.
 *
 * @param size The size of the input values were are given as well as the
 *   size of the new list we are to construct.
 * @param values The (static) array of string values to use to construct
 *   this List values with.
 */
template<class T>
List<T>::List(int size, T values[])
{
  // dynamically allocate a block of memory on the heap large enough to copy
  // the given input values into
  this->size = size;
  this->allocationSize = size;
  this->values = new T[allocationSize];

  // copy the values from the input paramter into our new shiny block of memory
  for (int index = 0; index < size; index++)
  {
    this->values[index] = values[index];
  }
}

/** @brief Copy constructor
 *
 * Provide a copy constructor for the List class.  A copy constructor
 * will be invoked whenver you assign one instance of a List to another.
 * For example
 *   List newList = existingList;
 * Where of course existingList was a previously created List.  This copy
 * constructor, as the name suggests, should make a copy of the values from
 * the given input list into a new List instance.
 *
 * @param list The other List type we are to make a copy of in this
 *   constructor.
 */
template<class T>
List<T>::List(const List<T>& list)
{
  // copy the size of the existing list and allocate memory to hold
  // values we will copy
  size = list.size;
  allocationSize = list.allocationSize;
  values = new T[allocationSize];

  // copy the values from the input List into this list
  for (int index = 0; index < size; index++)
  {
    values[index] = list.values[index];
  }
}

/** @brief Class destructor
 *
 * Destructor for the List class.  A List may (or may not) have
 * a dynamically allocated block of memory associated with it.
 * Free up this block on destruction of a List instance.
 */
template<class T>
List<T>::~List()
{
  // if values is not null, it points to a dynamic block of memory, so
  // delete that block.
  if (values != nullptr)
  {
    delete[] values;
  }
}

/** @brief overload output stream operator for List type.
 *
 * Overload the output stream operator so that we can display current
 * values of a List on standard output.
 *
 * @param out The output stream we should send the representation
 *   of the current List to.
 * @param rhs The List object to create and return a string
 *   representation of on the output stream.
 *
 * @returns ostream& Returns a reference to the originaly provided
 *   output stream, but after we  have inserted current List
 *   values / representation onto the stream
 */
template<typename U>
ostream& operator<<(ostream& out, const List<U>& rhs)
{
  // reuse List str() method to stream to output stream
  // out << rhs.str(); // uncomment this after templatizing str() if want output operator for List

  // return the modified output stream as our result
  return out;
}

/** @brief Memory bounds exception constructor
 *
 * Constructor for exceptions used for our
 * List  class.
 *
 * @param message The exception message thrown when an error occurs.
 */
ListMemoryBoundsException::ListMemoryBoundsException(const string& message)
{
  this->message = message;
}

/** @brief Memory bounds exception destructor
 *
 * Destructor for exceptions used for our ListMemoryBoundsException
 * class.
 */
ListMemoryBoundsException::~ListMemoryBoundsException() {}

/** @brief Memory bounds exception message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* ListMemoryBoundsException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class List<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template ostream& operator<<<int>(ostream&, const List<int>&);
template class List<int>;

template ostream& operator<<<string>(ostream&, const List<string>&);
template class List<string>;
