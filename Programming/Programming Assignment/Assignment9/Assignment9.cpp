
// Assignment 9
// 202112114 | Sagar Variya
// Date : 31/10/2021

#include <iostream>
#include <iomanip>

using namespace std;
using uint = unsigned int;

const uint arrSize{ 4 };
const uint funcSize{ 2 };


/*

1. Write a program that declares array of 5 pointers to strings. That is, each element of this 5 element array is a char*. Allocate memory to read a maximum of 200 characters for each element of the array. Read 5 names from the user using these pointers. Display all names. Now, re-allocate memory to these pointers equal to the size of the names. Display the names again to verify it is correct allocation. Don't forget to free the pointers at end of the program.

 */



void Q1()
{
}

/*

2. Declare a structure Player. It has following member variables (properties):
name: a pointer to string that is name of the player
age: an integer to store name
game: a pointer to string that stores game of the player
The program should read string inputs from user in single pointer variable named input. This input variable is pointer whose memory is allocated on heap with size of 100 characters. After user given an input (eg. for name) the program copies this string to the field of the structure (eg. the name field). Make sure only required characters are copied.
Display the name, age and game of the player after reading the data. Make sure you de-allocate all memories allocated before program exits.

*/


void Q2()
{
}

/*

3. Write a program that reads the NxM dimensions of a two-dimensional array of doubles. If user enters 0  or less for either N or M, the program exits. After reading the size of array from user, i.e. N for rows and M for columns, it allocates memory as required. Then, it reads the numbers from user and puts these in appropriate 'cells' for the matrix. It then displays the numbers read and free's up memory before exiting.

*/


void Q3()
{
}

/*

4. Go through assignments 4 onwards and do those exercises where you can use dynamic memory allocation instead of constant sized arrays.=> Not part of lab evaluation

*/


void Q4()
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
		//Q4();

		cout << endl << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}

