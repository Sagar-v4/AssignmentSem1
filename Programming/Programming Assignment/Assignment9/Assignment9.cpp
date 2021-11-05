
// Assignment 9
// 202112114 | Sagar Variya
// Date : 31/10/2021

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

using uint = unsigned int;

const uint Pointers{ 5 };
const uint nameSize{ 100 };

/*

1. Write a program that declares array of 5 pointers to strings. That is, each element of this 5 element array is a char*. Allocate memory to read a maximum of 200 characters for each element of the array. Read 5 names from the user using these pointers. Display all names. Now, re-allocate memory to these pointers equal to the size of the names. Display the names again to verify it is correct allocation. Don't forget to free the pointers at end of the program.

 */

void Q1()
{
	string str[Pointers]{};
	char* p[Pointers]{};
	int j = 0;

	for (int i = 0; i < Pointers; i++)
		*(p + i) = new char[nameSize];

	cout << "Enter 5 names : \n";
	for (int i = 0; i < Pointers; i++)
	{
		cout << "Name " << (i+1) << " : ";
		getline(cin, str[i], '\n');
		int j = 0;

		for (j = 0; j < str[i].length(); j++)
			*(*(p + i) + j) = str[i][j];
		*(*(p + i) + j) = '\0';
	}

	cout << endl << "Before Allocationg : " << endl;
	for (int i = 0; i < Pointers; i++)
	{
		cout << _msize(*(p + i)) << " | " << * (p + i)  << endl;
	}

	cout << endl << "After Reallocating : " << endl;
	for (int i = 0; i < Pointers; i++)
	{
		*(p + i) = new char[str[i].length() + 1];
		for (j = 0; j < str[i].length(); j++)
			*(*(p + i) + j) = str[i][j];
		*(*(p + i) + j) = '\0';
	}

	for (int i = 0; i < Pointers; i++)
	{
		cout << setw(2) << _msize(*(p + i))  << " | " << *(p + i) << endl;
		delete[] p[i];
		p[i] = nullptr;
	}
}

/*

2. Declare a structure Player. It has following member variables (properties):
name: a pointer to string that is name of the player
age: an integer to store name
game: a pointer to string that stores game of the player
The program should read string inputs from user in single pointer variable named input. This input variable is pointer whose memory is allocated on heap with size of 100 characters. After user given an input (eg. for name) the program copies this string to the field of the structure (eg. the name field). Make sure only required characters are copied.
Display the name, age and game of the player after reading the data. Make sure you de-allocate all memories allocated before program exits.

*/

struct Player
{
	string name{};
	string game{};
	int age{};
};

void Q2Input(Player* p)
{
	char* input = new char[nameSize];

	cout << "Enter Name: ";
	cin.getline(input, nameSize);
	p->name = input;

	cout << "Enter Game Name: ";
	cin.getline(input, nameSize);
	p->game = input;

	cout << "Enter age: ";
	cin >> input;
	p->age = stoi(input);

	delete[] input;
}

void Q2display(Player* p)
{
	cout << endl << "Player Name: " << p->name << endl;
	cout << "Player age: " << p->age << endl;
	cout << "Player Game Name: " << p->game << endl;
}

void Q2()
{
	Player* p = new Player;

	Q2Input(p);

	Q2display(p);

	delete p;
}

/*

3. Write a program that reads the NxM dimensions of a two-dimensional array of doubles. If user enters 0  or less for either N or M, the program exits. After reading the size of array from user, i.e. N for rows and M for columns, it allocates memory as required. Then, it reads the numbers from user and puts these in appropriate 'cells' for the matrix. It then displays the numbers read and free's up memory before exiting.

*/

void Q3matrixInitialization(int& m, int& n)
{
	cout << "Enter No. of Rows : ";
	cin >> m;

	cout << "Enter No. of Columns : ";
	cin >> n;
}

bool Q3verify(const int m, const int n) { return (m > 0 && n > 0); }

void Q3inputMatrix(const int m, const int n, int **p)
{
	cout << endl << "Enter " << (m * n) << " Elements : " << endl;

	for (int i = 0; i < m; i++)
	{
		*(p + i) = new int[n];

		for (int j = 0; j < n; j++)
			cin >> *(*(p + i) + j);
	}
}

void Q3displayMatrix(const int m, const int n, int** p)
{
	cout << endl << endl << "The matrix : " << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << * (*(p + i) + j) << " ";
		cout << endl;
	}
}

void Q3()
{
	int m{}, n{};

	Q3matrixInitialization(m, n);

	if ( Q3verify(m, n) )
	{
		int** p{ new int* [m] };

		Q3inputMatrix(m, n, p);

		Q3displayMatrix(m, n, p);

		delete[]p;
	}
	else
	{
		cout << endl << "Invalid Row OR Col Initialized....." << endl;
	}
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

