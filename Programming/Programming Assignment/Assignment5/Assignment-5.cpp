#include<iostream>
#include<math.h>
#include <iomanip>
int D(int m[3][3]);
int Adj(int a[3][3], float det);
using namespace std;

void Q1()
{
	int a[2][3], b[3][2], c[2][2]{ 0,0,0,0 };

	a[0][0] = 10, a[0][1] = 20, a[0][2] = 30;
	a[1][0] = 40, a[1][1] = 50, a[1][2] = 60;

	b[0][0] = 10, b[0][1] = 20;
	b[1][0] = 30, b[1][1] = 40;
	b[2][0] = 50, b[2][1] = 60;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; ++k)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}


	cout << "Multiplication of Matrix :" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << c[i][j] << "\t";
		}
		cout << "\n";
	}
}

void Q2()
{
	int a[3][3]{ {1,2,3}, { 0,1,4}, {5,6,0} };

	float det = D(a);
	Adj(a, det);

}

int D(int m[3][3])
{
	float det = 0;
	for (int i = 0; i < 3; i++)
	{
		det = det + (m[0][i] * (m[1][(i + 1) % 3] * m[2][(i + 2) % 3] -
			m[1][(i + 2) % 3] * m[2][(i + 1) % 3]));
	}
	return det;
}

int Adj(int m[3][3], float det)
{
	int n = 1;
	cout << "Inverse of Matrix :" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			cout << setw(4) << setfill(' ') << ((m[(j + 1) % 3][(i + 1) % 3] * m[(j + 2) % 3][(i + 2) % 3] - m[(j + 1) % 3][(i + 2) % 3] * m[(j + 2) % 3][(i + 1) % 3])) / det << " ";

		}
		cout << endl;
	}
	return 0;
}

void Q5()
{
	char race[4][21], power[4][21], just[4], x = 0, H;
	int StepX = 0, StepM = 0, StepT = 0, StepD = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			race[i][j] = '.';
			race[i][20] = '|';
		}
	}
	power[0][StepX] = 5;
	power[1][StepM] = 5;
	power[2][StepT] = 5;
	power[3][StepD] = 5;

	race[0][StepX] = 'X';
	race[1][StepM] = 'M';
	race[2][StepT] = 'T';
	race[3][StepD] = 'D';

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << race[i][j];
		}
		cout << endl;
	}
	
	while (race[0][19] != 'X' && race[1][19] != 'M' && race[2][19] != 'T' && race[3][19] != 'D') {
		race[0][StepX] = 'X';
		race[1][StepM] = 'M';
		race[2][StepT] = 'T';
		race[3][StepD] = 'D';

		just[0] = StepX;
		just[1] = StepM;
		just[2] = StepT;
		just[3] = StepD;

		system("cls");

		cout << "Race Begins: " << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < just[i]; j++)
			{
				race[i][j] = '-';
				race[i][20] = '|';
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				cout << race[i][j];
			}
			cout << endl;

		}
		srand(time(NULL));
		power[0][StepX] = power[0][StepX] + rand() % 5;
		power[1][StepM] = power[1][StepM] + rand() % 5;
		power[2][StepT] = power[2][StepT] + rand() % 5;
		power[3][StepD] = power[2][StepD] + rand() % 5;

		if (power[0][StepX] >= (StepX + 1) * 5)
		{
			StepX++;
		}
		if (power[1][StepM] >= (StepM + 1) * 5)
		{
			StepM++;
		}
		if (power[2][StepT] >= (StepT + 1) * 5)
		{
			StepT++;
		}
		if (power[3][StepD] >= (StepD + 1) * 5)
		{
			StepD++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (race[i][19] == 'X')
		{
			cout << "Winner is X" << endl;
			break;
		}
		else if (race[i][19] == 'M')
		{
			cout << "Winner is M" << endl;
			break;
		}
		else if (race[i][19] == 'T')
		{
			cout << "Winner is T" << endl;
			break;
		}
		else if (race[i][19] == 'D')
		{
			cout << "Winner is D" << endl;
			break;
		}


	}
}



int main() {
	Q1();
	Q2();
	Q5();
	return 0;
}