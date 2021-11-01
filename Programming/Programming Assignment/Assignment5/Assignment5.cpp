// Assignment 5
// 202112114 : Sagar Variya
// Date : 4/10/2021

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;
using uint = unsigned int;

const uint M{ 4 }, N{ 3 }, L{ 5 };
const uint R{ 3 }, C{ 3 };
const uint trackR{ 4 }, trackC{ 25 };

void Q1()
{
	int matrix1[M][N]{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} },
		matrix2[N][L]{ {1, 2, 3, 4, 5}, {0, 1, 4, 7, 5}, {3, 6, 9, 8, 5} },
		result[M][L]{};

	for (int i = 0; i < M; i++)
		for (int j = 0; j < L; j++)
			for (int k = 0; k < N; k++)
				result[i][j] += matrix1[i][k] * matrix2[k][j];

	cout << endl << "Multiplication of matrix : " << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < L; j++)
			cout << setw(4) << result[i][j];
		cout << endl;
	}
}

void Q2getCofactor(int m[R][C], int temp[R][C], int p, int q, int n)
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
		for (int col = 0; col < n; col++)
			if (row != p && col != q)
			{
				temp[i][j++] = m[row][col];

				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
}

int Q2determinant(int m[R][C], int n)
{
	int D = 0;

	if (n == 1)
		return m[0][0];

	int temp[R][C];

	int sign = 1;

	for (int f = 0; f < n; f++)
	{
		Q2getCofactor(m, temp, 0, f, n);
		D += sign * m[0][f] * Q2determinant(temp, n - 1);

		sign = -sign;
	}

	return D;
}

void Q2adjoint(int m[R][C], int adj[R][C])
{
	if (N == 1)
	{
		adj[0][0] = 1;
		return;
	}

	int sign = 1, temp[R][C];

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			Q2getCofactor(m, temp, i, j, C);

			sign = ((i + j) % 2 == 0) ? 1 : -1 ;

			adj[j][i] = (sign) * (Q2determinant(temp, C - 1));
		}
	}
}

bool Q2inverse(int m[R][C], float inverse[R][C])
{
	int det = Q2determinant(m, R);
	if (det == 0)
	{
		cout << "Determinant is 0, We Can't fint it's inverse....";
		return false;
	}

	int adj[R][C];
	Q2adjoint(m, adj);

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			inverse[i][j] = adj[i][j] / float(det);

	return true;
}

template<class T>
void Q2display(T m[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << setw(6) << setprecision(3) << m[i][j] << " ";
		cout << endl;
	}
}

void Q2()
{
	// Sir writed MxN but its not possible..matrix should be squre..
	// i am using 3x3 matrix
	
	int matrix[R][C]{ {1, 2, 3},
					{4, 5, 6},
					{7, 8, 8} },
	
		adjoinMatrix[R][C]{};

	float inverseMatrix[R][C]{};

	cout << endl << "Input matrix : " << endl;
	Q2display(matrix);

	cout << endl << "Adjoint : " << endl;
	Q2adjoint(matrix, adjoinMatrix);
	Q2display(adjoinMatrix);

	cout << endl << "Inverse : " << endl;
	if (Q2inverse(matrix, inverseMatrix))
		Q2display(inverseMatrix);

}

void Q3collinearOrDeterminant(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int a{ x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) },
		l{ int( sqrt( pow(x3 - x1, 2) + pow(y3 - y1, 2) ) ) };

	if (a == 0)
	{
		cout << endl << "It's collinear" << endl;
		cout << endl << "Length of line is : " << l << endl;
	}
	else
	{
		float a = (((static_cast<float>(x2) * y3) - (y2 * x3)) - ((x1 * y3) - (y1 * x3)) + ((x1 * y2) - (x2 * y1))) / 2;
		cout << endl << "It's not collinear" << endl;
		cout << endl << "Area of triangle : " << a;
	}
}

void Q3()
{
	int x1{}, x2{}, x3{}, y1{}, y2{}, y3{};

	cout << "Enter the x1 :";
	cin >> x1;
	cout << "Enter the y1 :";
	cin >> y1;
	cout << "Enter the x2 :";
	cin >> x2;
	cout << "Enter the y2 :";
	cin >> y2;
	cout << "Enter the x3 :";
	cin >> x3;
	cout << "Enter the y3 :";
	cin >> y3;

	Q3collinearOrDeterminant(x1, y1, x2, y2, x3, y3);
}

void Q5initialization(char(&t)[trackR][trackC], char c[trackR], const char wl, const char r)
{
	cout << "Race Initializing..." << endl << endl;

	for (int i = 0; i < trackR; i++)
		for (int j = 0; j < trackC; j++)
			t[i][j] = (j == 0) ? c[i] : ( (j == (trackC - 1)) ? wl : r);
}

void Q5chooseHorse(char &horse, char(&c)[trackR])
{
	cout << endl << "Horses : ";
	for (auto& horse : c)
		cout << horse << " ";
	cout << endl;

	while (true)
	{
		cout << "Choose your horse : ";
		cin >> horse;
		for (auto& h : c)
			if (h == horse) return;
	}
}

void Q5askToStart(bool& s)
{
	int val{ 0 };

	cout << endl << "Lets start the race [1 for yes] : ";
	cin >> val;

	s = (val == 1) ? true : false;
}

void Q5checkWinner(int candidates[trackR], bool& raceIsOn, char c[trackR], char u)
{
	for (int i = 0; i < trackR; i++)
		if (candidates[i] >= trackC - 1)
		{
			raceIsOn = false;
			cout << endl << "Winner : " << c[i] << endl;
		}
}

void Q5positions(int candidates[trackR], char c[trackR])
{
	cout << endl << "Horse Positions : " << endl;
	for (int i = 0; i < trackR; i++)
		cout << c[i] << " - " << candidates[i] + 1 << endl;
}

void Q5display(char(&t)[trackR][trackC])
{
	for (auto& i : t)
	{
		for (auto& j : i)
			cout << " " << j;
		cout << endl;
	}
}

void Q5startRace(char(&t)[trackR][trackC], bool s, bool& raceIsOn, char c[trackR], const char wl, const char complated, char horse)
{
	int raceCandidates[trackR]{0}, raceCandidatesPosition[trackR]{0};
	
	if (s) {
		while (raceIsOn)
		{
			system("cls");

			for (int i = 0; i < trackR; i++)
			{
				raceCandidates[i] = rand() % 5;

				if (raceCandidates[i] >= rand() % 3) {
					t[i][raceCandidatesPosition[i]++] = complated;
					t[i][raceCandidatesPosition[i]] = c[i];
				}
			}
			cout << "Race is going..." << endl << endl;
			Q5display(t);

			Q5positions(raceCandidatesPosition, c);

			cout << endl << "Your horse is : " << horse << endl;

			Q5checkWinner(raceCandidatesPosition, raceIsOn, c, horse);

			Sleep(rand() % 567);
		}
	}
	else cout << endl << "Race is not started yet..." << endl;
}

void Q5()
{
	char track[trackR][trackC]{}, candidates[trackR]{ 'X', 'M', 'T', 'D' }, horse{};
	const char winLine{ '|' }, trackToRun{ '.' }, trackComplated{ '-' };
	bool start{ false }, raceIsOn{ true };

	Q5initialization(track, candidates, winLine, trackToRun);

	Q5display(track);

	Q5chooseHorse(horse, candidates);

	Q5askToStart(start);

	Q5startRace(track, start, raceIsOn, candidates, winLine, trackComplated, horse);
}

//void main()
void main1()
{
	auto loop{ false };

	do {
		// Just uncomment any function and you are good to go...

		//Q1();
		//Q2();
		//Q3();
		Q5();

		cout << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}
