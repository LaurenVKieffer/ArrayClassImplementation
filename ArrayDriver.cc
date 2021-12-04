/*
  Filename   : ArrayDriver.cc
  Author     : Gary M. Zoppetti
  Course     : CSCI 362-01
  Assignment : N/A
  Description: Test some, but NOT ALL, methods of the Array class.
*/   

/************************************************************/
// System includes

#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <cassert>

/************************************************************/
// Local includes

#include "Array.hpp"

/************************************************************/
// Using declarations

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::ostringstream;

/************************************************************/
// Function prototypes/global vars/typedefs

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual);

/************************************************************/

int      
main (int argc, char* argv[]) 
{        
  Array<int> A;

  // For holding the actual result
  ostringstream output;
  // Put the actual result into the output stream
  output << A;
  printTestResult ("no-arg ctor", "[ ]", output);

  // Must clear the output stream each time
  output.str ("");
  output << A.empty ();
  // "1" for true, "0" for false
  printTestResult ("empty", "1", output);
  
  A.push_back (5);
  A.push_back (10);
  A.push_back (15);

  output.str ("");
  output << A;
  printTestResult ("push_back", "[ 5 10 15 ]", output);

  output.str ("");
  output << A.size ();
  printTestResult ("size", "3", output);
  
  A.pop_back ();
  A.pop_back ();

  output.str ("");
  output << A;
  printTestResult ("pop_back", "[ 5 ]", output);

  /************************************************************/
  // Convert the following tests to use printTestResult
  /************************************************************/
  for (int i = 0; i < 10; ++i)
    A.insert (A.begin (), i);

  output.str ("");
  output << A;
  printTestResult("insert", "[ 9 8 7 6 5 4 3 2 1 0 5 ]", output);


  for (Array<int>::iterator i = A.begin (); i != A.end (); )
    i = A.erase (i);

  output.str ("");
  output << A;
  printTestResult("erase", "[ ]", output);

  // Size ctor, with a fill value. 
  Array<int> B (3, 9);

  output.str ("");
  output << B;
  printTestResult("size ctor", "[ 9 9 9 ]", output);

  // Range ctor. 
  Array<int> C (B.begin (), B.begin () + 2);

  output.str ("");
  output << C;
  printTestResult("range", "[ 9 9 ]", output);
  

  // Assignment operator. 
  B = A;

  output.str ("");
  output << B;
  printTestResult("empty", "[ ]", output);

  for (int i = 0; i < 5; ++i)
    B.insert (B.begin (), i);
  
  output.str ("");
  output << B;
  printTestResult("insert", "[ 4 3 2 1 0 ]", output);

  /************************************************************/
  // START WRITING YOUR TESTS HERE
  /************************************************************/

  //Range ctor test

  Array<int>rangeTest (B.begin(), B.begin() + 3);

  output.str ("");
  output << rangeTest;
  printTestResult("range", "[ 4 3 2 ]", output);


  //copy ctor test
  Array<int> D;

  D.push_back(5);
  D.push_back(26);
  D.push_back(736);
  D.push_back(736);

  Array<int> E (D);

  output.str ("");
  output << E;
  printTestResult("copy", "[ 5 26 736 736 ]", output);


  //subscript test
  int check = E[3];

  output.str ("");
  output << check;
  printTestResult("subscript", "736", output);


  //capacity test;
  output.str ("");
  output <<  D.capacity();
  printTestResult("capacity", "4", output);


  //reserve higher value test
  D.reserve(10);

  output.str ("");
  output << D.capacity();
  printTestResult("reserve_capacity_higher", "10", output);

  output.str ("");
  output << D.size();
  printTestResult("reserve_size_higher", "4", output);


  //reserve lower value test, capacity and size are unchanged
  D.reserve(2);

  output.str ("");
  output << D.capacity();
  printTestResult("reserve_capacity_lower", "10", output);

  output.str ("");
  output << D.size();
  printTestResult("reserve_size_lower", "4", output);


  //test reserve with insert when capacity is 0, so capacity and size will be 1
  Array<int> F;

  F.insert(F.begin(), 5);

  output.str ("");
  output << F;
  printTestResult("reserve_capacity = 0", "[ 5 ]", output);

  //check size and capacity for insert on F
  output.str ("");
  output << F.capacity();
  printTestResult("new_capacity reserve", "1", output);

  output.str ("");
  output << F.size();
  printTestResult("new_size reserve", "1", output);


  //resize test, with higher and lower value
  D.resize(20);

  output.str ("");
  output << D;
  printTestResult("resize_higher", "[ 5 26 736 736 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ]", output);

  D.resize(3);

  output.str ("");
  output << D;
  printTestResult("resize_lower", "[ 5 26 736 ]", output);


  //dereference iterator-s

  Array<int>::iterator it = D.begin();

  it += 1;

  output.str ("");
  output << *it;
  printTestResult("dereference_iterator", "26", output);

  it += 2;

  output.str ("");
  output << *it;
  printTestResult("dereference_iterator", "736", output);

  //dereference const iterator-s 

  Array<int>::iterator const it2 = D.begin();

  output.str ("");
  output << *it2;
  printTestResult("dereference_const_iterator", "5", output);
  
  return EXIT_SUCCESS;
}

/************************************************************/

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual)
{
  cout << "Test: " << test << endl;
  cout << "==========================" << endl;
  cout << "Expected: " << expected << endl;
  cout << "Actual  : " << actual.str () << endl;
  cout << "==========================" << endl << endl;

  // Ensure the two results are the same
  assert (expected == actual.str ());
}

/************************************************************/
