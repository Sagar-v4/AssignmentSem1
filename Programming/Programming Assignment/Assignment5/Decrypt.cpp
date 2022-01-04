#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
int main(int argc, char* argv[])
{
	string encrypteddata = "";
	int var = 0, k = 1;
	int key[2][2] = { {1,2},{3,4} };
	float inversekey[2][2] = { {0,0},{0,0} };// declaring for taking inverse of key

	if (argc % 2 != 0)
	{
		var = argc / 2; // length / 2
	}
	else
	{
		var = (argc / 2) + 1;
	}

	int** dresult;
	dresult = new int* [var * 2];

	int** result;
	result = new int* [var * 2];

	for (int i = 0; i < var; i++)
	{
		dresult[i] = new int[2];// Similar to encryption- Creating a 2-d array dynamically for dresult
		result[i] = new int[2];
	}


	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < 2; j++)
		{

			result[i][j] = 0;
			if (k < argc)
				result[i][j] = stoi(argv[k]);
			k++;
		}
	}


	// Taken hardcoded matrix as key so finding determinant and inverse statically
	float determinant = (key[0][0] * key[1][1]) - (key[0][1] * key[1][0]);
	float temp = key[0][0] / determinant;
	inversekey[0][0] = key[1][1] / determinant;
	inversekey[1][1] = temp;
	inversekey[0][1] = (key[0][1] * -1) / determinant;
	inversekey[1][0] = (key[1][0] * -1) / determinant;


	float f = 0;
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dresult[i][j] = 0;
			f = 0;
			for (int k = 0; k < 2; k++)
			{
				f += result[i][k] * inversekey[k][j];
			}
			dresult[i][j] = f;
		}
	}
	cout << "Decrypted text: ";
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (dresult[i][j] == -1)
			{
				cout << " ";
				continue;
			}
			cout << (char)(dresult[i][j] + 'a');
		}
	}


}