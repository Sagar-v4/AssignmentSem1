#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;


void Q3()
{
	int i = 50, j = 20;
	cout << "Value = " << i / j << endl;
	cout << "or" << endl;
	cout << "Value = " << j / i;
}

void Q5()
{
	cout << "Aristotle said, \"Well begun is half done\".";
}

void Q6()
{
	cout << "This is the share for lecture slides: \\\\10.100.56.21\\Lecture\\Lavneet Singh\\IT603.";
}

void Q7() {
	string n[3];
	int m[3];
	cout << "Enter Student1 Name: ";
	cin >> n[0];
	cout << "Enter Student1 Marks: ";
	cin >> m[0];
	cout << "Enter Student2 Name: ";
	cin >> n[1];
	cout << "Enter Student2 Marks: ";
	cin >> m[1];
	cout << "Enter Student3 Name: ";
	cin >> n[2];
	cout << "Enter Student3 Marks: ";
	cin >> m[2];

	cout << n[0] << " scored " << (m[0] * 100) / 500 << "% \n";
	cout << n[1] << " scored " << (m[1] * 100) / 500 << "% \n";
	cout << n[2] << " scored " << (m[2] * 100) / 500 << "% \n";
}

void Q8()
{
	char s[100];
	cout << "Enter String (Max. 100 char):"<<endl;
	cin.getline(s,100);
	
	if (s == "")
	{
		cout <<"Invalid String";
	}
	else
	{
		int i,w=1,v=0;
		for  (i = 0; s[i] != '\0'; i++)
		{
			if (s[i]==' ')
			{
				w++;
			}
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			{
				v++;
			}
		}
		cout << "No. of Words="<<w<<endl;
		cout << "No. of Vovels=" << v;
	}

}


void Q9()
{
	int num = 0;
	cout << "Please enter the number : ";
	cin >> num;
	cout << "The multiplication table is : " << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << num << " x " << i << " = " << num * i << endl;
	}
}

void Q10()
{
	int num = 0, count = 0;
	cout << "Please enter the number : ";
	cin >> num;
	if (num == 0)
	{
		cout << "The number of digits are : 1" << endl;
		return;
	}
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	cout << "The number of digits are : " << count << endl;
}

void Q11()
{
	int num, n;
	cout << "Enter Number : ";
	cin >> num;
	cout << "Which bit you want to toggle : ";
	cin >> n;
	int n2 = 1 << (n - 1);
	cout << "Result : " << (num ^ n2) << endl;
}


void Q12()
{
	cout << "All the odd numbers between 1 to 100 : " << endl;
	for (int i = 1; i < 100; i++)
	{
		if (i % 2 != 0){
			cout << i << " ";
		}
	}
}

void Q13()
{
	int n{ 0 }, r, reverse{ 0 };
	cout << "Enter any number:"<<endl;
	cin >> n;

	while (n!=0)
	{
		r = n % 10;
		reverse = (reverse * 10) + r;
		n /= 10;
	}
	cout << "Reverse Number:"<<reverse;
}

void Q14()
{
	float ds, c, db, maths, cs,per;
	char grade;

	cout << endl << "Enter Marks of Data Structures : " ;
	cin >> ds;
	cout << endl << "Enter Marks of C Programming : ";
	cin >> c;
	cout << endl << "Enter Marks of Data Base : ";
	cin >> db;
	cout << endl << "Enter Marks of Mathematics : ";
	cin >> maths;
	cout << endl << "Enter Marks of Communication Skills : ";
	cin >> cs;

	per = ((ds + c + db + maths + cs) * 100) / 500;
	if (per < 40)
		grade = 'F';
	else if (per < 60)
		grade = 'E';
	else if (per < 70)
		grade = 'D';
	else if (per < 80)
		grade = 'C';
	else if (per < 90)
		grade = 'B';
	else
		grade = 'A';

	cout << endl << "Percentage : " << per;
	cout << endl << "Grade : " << grade;
}


void Q15()
{
	char c;
	cout << "Enter any character : ";
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
		cout << c << " is a vowel"<<endl;
	else
		cout << c << " is a consonant"<<endl;
}


void Q16()
{
	int num;
	cout << "Please enter month : ";
	cin >> num;
	if (num == 1 || num == 3 || num == 5 || num == 7 || num == 8 || num == 10 || num == 12)
	{
		cout << "It has 31 days.";
	}
	else if (num == 4 || num == 6 || num == 9 || num == 11)
	{
		cout << "It has 30 days.";
	}
	else if (num == 2)
	{
		cout << "It has 28 or 29 days.";
	}
	else
	{
		cout << "Wrong Input.";
	}
}

void Q17()
{
	float side1, side2, side3;
	cout << "Input Side 1 Of Triangle : ";
	cin >> side1;
	cout << "Input Side 2 Of Triangle : ";
	cin >> side2;
	cout << "Input Side 3 Of Triangle : ";
	cin >> side3;
	if (side1 == 0 || side2 == 0 || side3 == 0 || side1 + side2 < side3 || side1 + side3 < side2 || side2 + side3 < side1)
	{
		cout << "Triangle cannot be formed.";
	}
	else
	{
		cout << "Triangle can be formed.";
	}
}

int main()
{
// 	Q3();
// 	Q5();
// 	Q6();
// 	Q7();
// 	Q8();
// 	Q9();
// 	Q10();
// 	Q11();
// 	Q12();
// 	Q13();
// 	Q14();
// 	Q15();
// 	Q16();
// 	Q17();
	return 0;
}
