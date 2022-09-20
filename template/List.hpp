/** @file List.hpp
 * @brief Declarations of List class for Assignment Overloading and Templates
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Overloading and Templates
 * @date   June 1, 2021
 *
 * Definitions of a basic List of integers.  Sort of a preview
 * of some of the data structures and abstract data types we
 * will be learning to build and understand.
 */
#ifndef _LIST_HPP_
#define _LIST_HPP_
#include <iostream>
#include <string>
using namespace std;

/** @class List
 * @brief A basic List of integer values for the assignment.
 *
 * A simple class that allows us to define and pass around a list of
 * string values.  To get more practice with classes in C/C++
 * and stop passing around size and array for all of our functions.
 * Notice the overloaded operator[].  We will talk more about operator
 * overloading in the next unit or two.
 */
template<class T>
class List
{
public:
  // constructors and destructors
  List();                     // default constructor
  List(int size, T values[]); // standard constructor
  List(const List<T>& list);  // copy constructor
  ~List();                    // destructor

  // accessor methods

  // overloaded operators

  // friend functions / operators
  template<typename U>
  friend ostream& operator<<(ostream& out, const List<U>& rhs);

private:
  /// @brief private constant, initial allocation size for empty lists
  ///   to grow to
  const int INITIAL_ALLOCATION_SIZE = 10;

  /// @brief the current size of the list of integer values
  int size;
  /// @brief the current amount of allocated memory being
  ///   managed by/for this list of values
  int allocationSize;
  /// @brief the integers values contained in the list.  This will
  ///   be a dynamically allocated array of integers.
  T* values;

  // private member methods for managing the List internally

};

/** @class ListMemoryBoundsException
 * @brief Memory Bounds Exception for the List class.
 *
 * Exception to be thrown by our List class if an illegal
 * memory bounds access is attempted.
 *
 */
class ListMemoryBoundsException : public exception
{
public:
  explicit ListMemoryBoundsException(const string& message);
  ~ListMemoryBoundsException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // define _LIST_HPP_
