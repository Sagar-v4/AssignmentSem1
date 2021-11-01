
// Assignment 8
// 202112114 | Sagar Variya
// Date : 23/10/2021

#include <iostream>
#include <iomanip>

using namespace std;
using uint = unsigned int;

const uint arrSize{ 4 };
const uint funcSize{ 2 };

struct Player
{
	unsigned short int age{};
	string fname{}, lname{}, game{};
};

struct Fraction { int p{}, q{}; };

struct Complex { double real{}, imag{}; };

typedef struct Player PLAYER;
PLAYER p1{}, * p2{ new PLAYER }, playerArr1[arrSize], playerArr2[arrSize];

/*

1. Create a structure representing a player. It should have player's first name, last name, age and name of the game. Do the following activities on this structure-
	a. Write a function that creates object of this structure, reads inputs from user for the properties of the object and prints the read values.
	b. Do a. above using pointer to the structure object.
	c. Create an array of size 4 and read from user the values and print them
	d. Do c. above using pointer notation to iterate through the array of structure.

 */

void Q1InputStructure(Player& pp)
{
	cout << "Enter First Name : ";
	cin >> pp.fname;

	cout << "Enter Last Name : ";
	cin >> pp.lname;

	cout << "Enter Age : ";
	cin >> pp.age;

	cout << "Enter Game Name : ";
	cin >> pp.game;
}

void Q1InputStructurePointer(Player* pp)
{
	cout << "Enter First Name : ";
	cin >> pp->fname;

	cout << "Enter Last Name : ";
	cin >> pp->lname;

	cout << "Enter Age : ";
	cin >> pp->age;

	cout << "Enter Game Name : ";
	cin >> pp->game;
}

void Q1printStructure(Player *pp, int n = 1)
{
	cout << endl << "[ Printing Structure ]" << endl;
	for (int i = 0; i < n; i++, pp++)
	{
		if (n > 1) cout << endl << (i + 1) << ")";
		cout << endl << "First name : " << pp->fname;
		cout << endl << "Last name : " << pp->lname;
		cout << endl << "Player age : " << pp->age;
		cout << endl << "Game name : " << pp->game << endl;
	}
}

Player& Q1createObject() { return p1; }

Player* Q1createObjectByPtr() { return p2; }

void Q1A(Player& p)
{	
	cout << endl << "Q1 -> A)" << endl << endl;
	Q1InputStructure(p);
}

void Q1B(Player* p)
{

	cout << endl << "Q1 -> B)" << endl << endl;
	Q1InputStructurePointer(p);
}

void Q1C(Player(& p)[arrSize], bool print = false)
{
	if(print) cout << endl << "Q1 -> C)" << endl;

	for (int i = 0; i < arrSize; i++)
	{
		cout << endl << (i + 1) << ")" << endl;
		Q1InputStructure(p[i]);
	}
}

void Q1D(Player(& p)[arrSize])
{
	PLAYER* pp{ p };
	cout << endl << "Q1 -> D)" << endl;

	for (int i = 0; i < arrSize; i++, pp++)
	{
		cout << endl << (i + 1) << ")" << endl;
		Q1InputStructurePointer(pp);
	}
}

void Q1()
{

	Q1A( Q1createObject() );		// p1
	Q1printStructure( &(Q1createObject()) );

	Q1B( Q1createObjectByPtr() );	// *p2
	Q1printStructure( Q1createObjectByPtr() );

	Q1C(playerArr1, 1);
	Q1printStructure(playerArr1, arrSize);

	Q1D(playerArr2);
	Q1printStructure(playerArr2, arrSize);
}

/*

2. Write a function SortByAge(PLAYER *players) that sorts the array of structure created in problem 1 by age property. PLAYER is the typedef of player structure.

*/

void Q2swapStructure(PLAYER* p1, PLAYER* p2)
{
	PLAYER temp{};

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void Q2sortByAge(PLAYER* players)
{
	for (int i = 0; i < arrSize - 1; i++)
		for (int j = 0; j < arrSize - i - 1; j++)
			if ((players + j)->age > (players + j + 1)->age)
				Q2swapStructure((players + j), (players +  j + 1));

}

void Q2()
{
	Q1C(playerArr1);
	cout << endl << "Befor : ";
	Q1printStructure(playerArr1, arrSize);

	Q2sortByAge(playerArr1);
	cout << endl << "After sorting by AGE : ";
	Q1printStructure(playerArr1, arrSize);

}

/*

3. Write a function, FindPlayer, that finds a player in the array of PLAYER structures by player's first name.

*/

void Q3findPlayer(PLAYER* players, string fname)
{
	for (int i = 0; i < arrSize; i++)
		if (((players + i)->fname) == fname)
			Q1printStructure((players + i));
}

void Q3()
{
	string firstName;
	Q1C(playerArr1);

	cout << endl << "Enter First Name to find Player details : ";
	cin >> firstName;

	Q3findPlayer(playerArr1, firstName);
}

/*

4. Write a function FindRecord(PLAYER *players, PLAYER player), that finds if the player exists in the players list. This function should compare whole structure (unlike FindPlayer() in problem 3 which compares only first name).

*/

bool Q4compareStructure(PLAYER p1, PLAYER p2)
{
	if (p1.fname != p2.fname) return false;
	if (p1.lname != p2.lname) return false;
	if (p1.age != p2.age) return false;
	if (p1.game != p2.game) return false;

	return true;
}

void Q4findRecord(PLAYER* players, PLAYER player)
{
	for (int i = 0; i < arrSize; i++)
		if (Q4compareStructure(*(players + i), player))
			Q1printStructure((players + i));
}

void Q4()
{
	PLAYER player;
	Q1C(playerArr1);

	cout << endl << "Searching Player Details : " << endl << endl;
	Q1InputStructure(player);

	Q4findRecord(playerArr1, player);

}

/*

5. Creat a struct Fraction to represent a fraction p/q, where p and q are integers (could be signed) and q != 0. Write functions that operate on such fraction (like addition, subtraction, multiplication).

*/

void Q5inputFraction(Fraction& f)
{
	cout << "Enter Numerator : ";
	cin >> f.p;

	do
	{
		cout << "Enter Denominator : ";
		cin >> f.q;
	} while (f.q == 0);
}

void Q5printFraction(Fraction f)
{
	cout << f.p << " / " << f.q << endl;
}

void Q5divide(Fraction(&f))
{
	for (int i = 2; i <= ((((f.p < 0) ? ((f.p) * (-1)) : f.p) / 2) + ((f.p & 1) ? 2 : 1)); i++)
	{
		if ((f.p % i == 0) && (f.q % i == 0))
		{
			f.p /= i;
			f.q /= i;
			i = 1;
		}
		//cout << i << " ";
	}
}

void Q5addition(Fraction(fc)[funcSize])
{
	Fraction add{};

	add.p = (fc[0].p * fc[1].q) + (fc[0].q * fc[1].p);
	add.q = fc[0].q * fc[1].q;
	
	Q5divide(add);

	cout << endl << "Addition : ";
	Q5printFraction(add);

}

void Q5subtraction(Fraction(fc)[funcSize])
{
	Fraction sub{};

	sub.p = (fc[0].p * fc[1].q) - (fc[0].q * fc[1].p);
	sub.q = fc[0].q * fc[1].q;

	Q5divide(sub);

	cout << endl << "Subtraction : ";
	Q5printFraction(sub);
}

void Q5multiplication(Fraction(fc)[funcSize])
{
	Fraction mul{};

	mul.p = fc[0].p * fc[1].p;
	mul.q = fc[0].q * fc[1].q;

	Q5divide(mul);

	cout << endl << "Multiplication : ";
	Q5printFraction(mul);
}

void Q5division(Fraction(fc)[funcSize])
{
	Fraction div{};

	div.p = fc[0].p * fc[1].q;
	div.q = fc[0].q * fc[1].p;

	Q5divide(div);

	cout << endl << "Division : ";
	Q5printFraction(div);
}

void Q5()
{
	Fraction fc[funcSize]{};

	for (int i = 0; i < funcSize; i++)
	{
		cout << endl << "Enter Fraction " << (i + 1) << endl;
		Q5inputFraction(fc[i]);
	}

	Q5addition(fc);

	Q5subtraction(fc);

	Q5multiplication(fc);

	Q5division(fc);

}

/*

6. Create a struct Complex to represent a complex number a+ib where b is the imaginary part and a is the real part. Write functions to do complex number operations using this data structure.

*/

void Q6inputComplex(Complex& c)
{
	cout << "Enter Real Number : ";
	cin >> c.real;

	cout << "Enter Imaginary Number : ";
	cin >> c.imag;
}

void Q6printComplex(Complex c)
{
	cout << c.real << ((c.imag > 0) ? "+" : "") << c.imag << "i" << endl;
}

void Q6addition(Complex c[funcSize])
{
	Complex z{};
	z.real = c[0].real + c[1].real;
	z.imag = c[0].imag + c[1].imag;

	cout << endl << "Addition : ";
	Q6printComplex(z);
}

void Q6subtraction(Complex c[funcSize])
{
	Complex z{};
	z.real = c[0].real - c[1].real;
	z.imag = c[0].imag - c[1].imag;

	cout << endl << "Subtraction : ";
	Q6printComplex(z);
}

void Q6multiplication(Complex c[funcSize])
{
	Complex z{};
	double f{}, o{}, i{}, l{};

	f = c[0].real * c[1].real;
	o = c[0].real * c[1].imag;
	i = c[0].imag * c[1].real;
	l = (c[0].imag * c[1].imag) * (- 1);

	z.real = f + l;
	z.imag = o + i;

	cout << endl << "Multiplication : ";
	Q6printComplex(z);
}

void Q6division(Complex c[funcSize])
{
	Complex z{};
	double f{}, d{}, l{};

	f = (c[0].real * c[1].real) + ((c[0].imag * (c[1].imag * (-1))) * (-1));
	l = ((c[1].imag * (-1)) * c[0].real) + (c[1].real * c[0].imag);
	d = (c[1].real * c[1].real) + (c[1].real * (c[1].imag * (-1))) + (c[1].real * c[1].imag) + (c[1].imag * (((c[1].imag * (-1)))) * (-1));

	z.real = f / d;
	z.imag = l / d;
	
	cout << endl << "Division : ";
	Q6printComplex(z);
}

void Q6()
{
	Complex c[funcSize];

	for (int i = 0; i < funcSize; i++)
	{
		cout << endl << "Enter Complex Number " << (i + 1) << endl;
		Q6inputComplex(c[i]);
		Q6printComplex(c[i]);
	}

	Q6addition(c);

	Q6subtraction(c);

	Q6multiplication(c);

	//Q6division(c);
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
		Q5();
		//Q6();

		cout << endl << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}

