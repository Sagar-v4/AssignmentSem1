
// Assignment 9
// 202112114 | Sagar Variya
// Date : 1/12/2021

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

using uint = unsigned int;

const uint Pointers{ 5 };
const uint nameSize{ 100 };

/*

1. Use templates to write generic code that can store user objects in a linked list. The linked list node should have pointer to the user objects i.e. they should not store the user objects inside linked list nodes. Use unit tests to test your template library code for all scenarios including possible edge cases.

 */

void Q1()
{
	

}

/*

2. Read data from file that has 100+ records to store the information in the linked list. You can get data from online resources, like top 100 contries by GDP or, 100 cities and data related to them. Top 100 noble prize winners - year, subject and name of scientist. Read this data and use the template code above to store the information in the linked list. Assume that data is in random order.

*/



void Q2()
{

}

/*

3. Now, we want to have another linked list on top of this linked list to provide to users sorted data. The data can be sorted using any field of the object that has been stored in the first linked list. Use callback (ie std::function) to provide a comparison function to the user of this template library, and create a linked list of nodes that are pointing to first linked list nodes such that iterating through this 2nd list would give the data in sorted order. You can implement any sorting algorithm for this.

*/

void Q3()
{

}

void main()
{
	auto loop{ false };

	do {
		// Just uncomment any function and you are good to go...

		//Q1();
		//Q2();
		//Q3();

		cout << endl << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}

