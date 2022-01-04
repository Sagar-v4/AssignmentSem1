#include <iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
	string input = "", encryptdata = "";

	for (int i = 1; i < argc; i++)
	{
		input = input + argv[i];
		input = input + " ";
	}

	int len = 0;
	int key[2][2] = { {1,2},{3,4} }; // Taking hardcoded matrix as key

	if (input.length() % 2 == 0)
	{
		len = input.length() / 2;
	}
	else
	{
		len = (input.length() / 2) + 1;
	}

	int var = 0, temp = 0;

	int** arr;
	arr = new int* [len * 2];

	int** result;
	result = new int* [len * 2];

	for (int i = 0; i < len; i++)
	{
		arr[i] = new int[2]; // Creating a 2-d array dynamically for arr
		result[i] = new int[2]; // Creating a 2-d array dynamically for result
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp = (toupper(input[var]) - 'A');
			if (temp == -33)
			{
				arr[i][j] = -1;
			}
			else
			{
				arr[i][j] = temp;
			}
			var++;
		}
	}


	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				result[i][j] += arr[i][k] * key[k][j];
			}
		}
	}
	cout << "Result:\n";
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << result[i][j] << "\t";
			encryptdata += to_string(result[i][j]);
			encryptdata += " ";
		}
		cout << "\n";
	}
	cout << "\nData after Encryption:" << encryptdata;
}