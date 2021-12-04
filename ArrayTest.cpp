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

int      
main (int argc, char* argv[]) 
{ 

	Array<int> arr;

	arr.push_back(5);
  	arr.push_back(26);
  	arr.push_back(736);
  	arr.push_back(736);


	cout << "empty: " << arr.empty() << "\n";
	cout <<"size: " << arr.size() << "\n";
	cout << "capacity " << arr.capacity() << "\n";
	cout <<  arr[0] << " ";
	cout <<  arr[1] << " ";
	cout <<  arr[2] << " ";
	cout <<  arr[3] << " ";
	cout <<  arr[4] << " ";
	cout <<  arr[5] << " ";
	cout <<  arr[6] << " ";
	cout << arr[7] << " ";
	cout <<  arr[8] << " ";
	cout <<  arr[9] << " ";
	cout << arr[10] << " ";
	cout << arr[11] << " ";

	cout << "newSize \n";

	arr.resize(10, 44);


	cout << "empty: " << arr.empty() << "\n";
	cout <<"size: " << arr.size() << "\n";
	cout << "capacity " << arr.capacity() << "\n";
	cout << arr[0] << " ";
	cout  << arr[1] << " ";
	cout  << arr[2] << " ";
	cout  << arr[3] << " ";
	cout  << arr[4] << " ";
	cout  << arr[5] << " ";
	cout  << arr[6] << " ";
	cout  << arr[7] << " ";
	cout  << arr[8] << " ";
	cout  << arr[9] << " ";
	cout  << arr[10] << " ";
	cout  << arr[12] << " ";
	cout  << arr[13] << " ";
	cout  << arr[14] << " ";
	cout  << arr[15] << " ";
	cout  << arr[16] << " ";
	cout  << arr[17] << " ";
	cout  << arr[18] << " ";
	cout  << arr[19] << " ";
	cout  << arr[20] << " ";



	cout << "\n";

	/*arr.reserve(30);

	cout << "empty: " << arr.empty() << "\n";
	cout <<"size: " << arr.size() << "\n";
	cout << "capacity " << arr.capacity() << "\n";
	
	cout << "\n";

	cout << "array 2: ";

	Array<int> arr2;

	cout << "empty: " << arr2.empty() << "\n";
	cout <<"size: " << arr2.size() << "\n";
	cout << "capacity " << arr2.capacity() << "\n";

	cout << "\n";

	arr2 = arr;

	cout << "empty: " << arr2.empty() << "\n";
	cout <<"size: " << arr2.size() << "\n";
	cout << "capacity " << arr2.capacity() << "\n";
	cout << "index[] value: " << arr2[5] << "\n";

	cout << "\n";

	arr2.insert(arr2.begin(), 28);

	cout << "empty: " << arr2.empty() << "\n";
	cout <<"size: " << arr2.size() << "\n";
	cout << "capacity " << arr2.capacity() << "\n";
	cout << "index[] value: " << arr2[0] << "\n";

	arr2.push_back(5);
	arr2.push_back(10);
	arr2.push_back(15);

	cout << "empty: " << arr2.empty() << "\n";
	cout <<"size: " << arr2.size() << "\n";
	cout << "capacity " << arr2.capacity() << "\n";
	cout << "index[] value: " << arr2[11] << "\n";
	cout << "index[] value: " << arr2[12] << "\n";
	cout << "index[] value: " << arr2[13] << "\n";

	arr2.erase(arr2.begin());

	cout << "empty: " << arr2.empty() << "\n";
	cout <<"size: " << arr2.size() << "\n";
	cout << "capacity " << arr2.capacity() << "\n";
	cout << "index[] value: " << arr2[0] << "\n";
	*/




	return EXIT_SUCCESS;


}