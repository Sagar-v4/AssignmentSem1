// Assignment 3
// 202112114 : Sagar Variya
// Date : 16/9/2021

#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

typedef unsigned int uint;
typedef char byte;

void Q1() {

	uint a{ 0b10111001 & 0b10010110 },
		b{ 0b11011110 & 0b11000101 },
		c{ 0b01111101 | 0b10111110 },
		d{ 0b11000110 | 0b11011100 },
		e{ 0b10111001 ^ 0b11110110 },
		f{ 0b11000010 ^ 0b00000101 },
		g{ 0b1011100110010110 },
		h{ ~0b11011110 & 0b11000101 },
		i{ 1 << 7 },
		j{ uint(pow(2, 7)) >> 4 };

	cout << "A) " << a << endl
		<< "B) " << b << endl
		<< "C) " << c << endl
		<< "D) " << d << endl
		<< "E) " << e << endl
		<< "F) " << f << endl
		<< "G) " << ~g << endl
		<< "H) " << h << endl
		<< "I) " << i << endl
		<< "J) " << j << endl;
}

void Q2() {
	
	uint x{ 0b1010'1110'1010'1011'0101'1101'0011'1011 };

	cout << "Original : " << bitset<32>(x) << endl << endl;


	//Q2 a)
	uint a = x | 1 << 15;
	cout << "A) " << bitset<32>(a) << endl;

	//Q2 b)
	uint b = x & ~(1 << 27);
	cout << "B) " << bitset<32>(b) << endl;

	//Q2 C)
	uint odd = 0b1;
	uint even = 0b1;
	for (uint i = 0; i < 32; i++)
	{
		if (i % 2 == 0) odd = odd << 1 | (0b01 & ((x >> 31) - i));
		else even = even << 1 | (0b01 & ((x >> 31) - i));
	}
	cout << "C) Odds : " << bitset<16>(odd) << endl;
	cout << "C) Evens :" << bitset<16>(even) << endl;

	// Q2 D)
	uint nibble{ 3 };
	for (uint i = ((nibble - 1) * 4); i < (nibble * 4); i++)
	{
		x = x ^ (1 << (i));
	}

	cout << "D) After Flipping 3rd Nibble : " << bitset<32>(x) << endl;
}

void Q3() {

	int number{ 0 };

	cout << "Enter Number to cout their all 1 bits : ";
	cin >> number;

	bitset<32> bits(number); 
	
	cout << endl << "Converting " << number << " to Binary : " << bits << endl << "Total 1 bits in " << number << " are : " << bits.count() << endl;

	int n, count = 0;
	cout << "Enter Number";
	cin >> n;
	for (int i = 0; i < 32; i++)
	{
		if (n & (1 << i))
		{
			count++;
		}
	}
	cout << count;
}

void Q4() {

	int ch{0}, i{0};
	uint n{0};
	do {
		cout << endl << "1. Set Value" << endl;
		cout << "2. Print Value" << endl;
		cout << "3. Exit" << endl;

		cout << endl << "Enter Your Choice : ";
		cin >> ch;

		switch (ch)
		{
		case 1:

			cout << endl << "1. Tablet Mode" << endl;
			cout << "2. Wifi" << endl;
			cout << "3. Mute" << endl;
			cout << "4. Aeroplane Mode" << endl;
			cout << "5. Auto Hide Taskbar" << endl;
			cout << endl << "Select to set the settings : ";
			cin >> i;

			if (i == 1) n = n ^ 1 << 0;

			else if (i == 2) n = n ^ 1 << 1;

			else if (i == 3) n = n ^ 1 << 2;

			else if (i == 4) n = n ^ 1 << 3;

			else if (i == 5) n = n ^ 1 << 0;

			else cout << endl << "Invalid Choice..." << endl;

			break;

		case 2:

			if (n & (1 << 0)) cout << endl << endl << "Tablet Mode is : ON" << endl;

			else cout << endl << endl << "Tablet Mode is : OFF" << endl;

			if (n & (1 << 1)) cout << "Wifi is : ON" << endl;

			else cout << "Wifi is : OFF" << endl;

			if (n & (1 << 2)) cout << "Mute is : ON" << endl;

			else cout << "Mute is : OFF" << endl;

			if (n & (1 << 3)) cout << "Aeroplane Mode is : ON" << endl;

			else cout << "Aeroplane Mode is : OFF" << endl;

			if (n & (1 << 4)) cout << "Auto hide Taskbar Mode is : ON" << endl;

			else cout << "Auto hide Mode is : OFF" << endl;

			break;

		case 3:
			exit(0);

		default:
			cout << endl << "Invalid Choice..." << endl;
		}
	} while (ch != 3);
}

void Q5() {

	//Values:
		// Seat Covers selected - 1st bit
		// Alloys - 2nd bit
		// Color - 3rd bit
		// Steering Cover - 4th bit
		// Body Cover - 5th bit

			// 6th and 7th bit
		// []Coffee Brown - 00
		// []Pearl White - 01
		// []Marine Blue - 10
		// []Ash Grey - 11 


		//Variable Color
		//  []Beige - 1st and 2nd bit - 00
		//	[]Dark - 01
		//	[]Dual Pattern - 10

	byte bcv = 0, choice = 0, color = 0;
	int n1 = 0, n2 = 0;

	while (n1 != 6) {
		cout << "--------------Settings---------------" << endl;
		cout << "Press 1 to select seat covers" << endl;
		cout << "Press 2 to select Alloys." << endl;
		cout << "Press 3 to Select Color" << endl;
		cout << "Press 4 to Select Steering Cover" << endl;
		cout << "Press 5 to Select Body Cover" << endl;
		cout << "Press 6 to Confirm choices and Exit" << endl;
		cout << "-------------------------------------" << endl;
		cin >> n1;

		bcv = 1 << (n1 - 1);
		choice = choice ^ bcv;

		if (n1 == 1) {
			n2 = 0;
			while (n2 != 4) {
				cout << "-------Choose a seat Cover color:---------" << endl;
				cout << "Press 1 to select Beige." << endl;
				cout << "Press 2 to select Dark." << endl;
				cout << "Press 3 to Select Dual Pattern." << endl;
				cout << "Press 4  to Confirm choice and go back" << endl;
				cout << "-------------------------------------" << endl;
				cin >> n2;


				if (n2 == 1) {
					color = 0;
					cout << bitset<8 * sizeof(color)>(color) << endl;

				}
				else if (n2 == 2) {
					color = 0b01;
					cout << bitset<8 * sizeof(color)>(color) << endl;

				}
				else if (n2 == 3) {
					color = 1 << 1;
					cout << bitset<8 * sizeof(color)>(color) << endl;

				}

			}
		}
		else if (n1 == 3) {
			n2 = 0;

			while (n2 != 4) {
				cout << "------ -Choose a seat Color:---------" << endl;
				cout << "Press 1 to select Coffee Brown." << endl;
				cout << "Press 2 to select Pearl White." << endl;
				cout << "Press 3 to Select Marine Blue." << endl;
				cout << "Press 3 to Select Ash Grey." << endl;
				cout << "Press 4 to Confirm choice and go back" << endl;
				cin >> n2;


				if (n2 == 1) {
					choice = 0 << 5 | 0 << 6;
					cout << bitset<8 * sizeof(choice)>(choice) << endl;

				}
				else if (n2 == 2) {
					choice = 0 << 5 | 1 << 6;
					cout << bitset<8 * sizeof(choice)>(choice) << endl;

				}
				else if (n2 == 3) {
					choice = 1 << 5 | 0 << 6;
					cout << bitset<8 * sizeof(choice)>(choice) << endl;

				}
				else if (n2 == 4) {
					choice = 1 << 5 | 1 << 6;
					cout << bitset<8 * sizeof(choice)>(choice) << endl;

				}

			}

		}
		cout << bitset<8 * sizeof(choice)>(choice) << endl;
		cout << bitset<8 * sizeof(color)>(color) << endl;
	}
}

int main()
{
	auto loop{ false };

	do {
		// Just uncomment any function and you are good to go...

		//Q1();
		//Q2();
		//Q3();
		//Q4();
		//Q5();

		cout << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}
