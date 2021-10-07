// Assignment 5
// 202112114 : Sagar Variya
// Date : 4/10/2021

#include <iostream>
#include <iomanip>

using namespace std;
using uint = unsigned int;

const uint S3{ 3 }, S4{ 4 }, S5{ 5 };

void Q1()
{
	int M[S4][S3]{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} }, r1[S4][S5]{},
		N[S3][S5]{ {1, 2, 3, 4, 5}, {0, 1, 4, 7, 5}, {3, 6, 9, 8, 5} }, r2[S3][S3]{},
		L[S5][S3]{ {1, 5, 9}, {3, 5, 7}, {4, 5, 6}, {2, 5, 8}, {7, 4, 1} };

	for (int i = 0; i < S4; i++)
		for (int j = 0; j < S5; j++)
			for (int k = 0; k < S3; k++)
				r1[i][j] += M[i][k] * N[k][j];

	for (int i = 0; i < S3; i++)
		for (int j = 0; j < S3; j++)
			for (int k = 0; k < S5; k++)
				r2[i][j] += N[i][k] * L[k][j];

	cout << endl << "Multiplication of matrix M and N : " << endl;
	for (int i = 0; i < S4; i++) {
		for (int j = 0; j < S5; j++)
			cout << setw(4) <<r1[i][j];
		cout << endl;
	}

	cout << endl << "Multiplication of matrix N and L : " << endl;
	for (int i = 0; i < S3; i++) {
		for (int j = 0; j < S3; j++)
			cout << setw(4) << r2[i][j];
		cout << endl;
	}
}

void main()
{
	auto loop{ false };

	do {
		// Just uncomment any function and you are good to go...

		Q1();
		//Q2();
		//Q3();
		//Q4();
		//Q5();

		cout << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}
