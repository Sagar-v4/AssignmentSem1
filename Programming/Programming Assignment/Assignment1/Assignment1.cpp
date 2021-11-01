// Assignment 1
// 202112114 : Sagar Variya
// Date : 28/8/2021

#include <iostream>
#include <string>

using namespace std;

void Q1()
{
	int i = 100;
	i = i + i;
	cout << "V1:" << i + i << i << endl;
}

void Q2()
{
	int i = 6;
	double j;
	j = i / 4;
	cout << "Val = " << j << endl;
}

void Q3()
{
	int n1{ 20 }, n2{ 50 };
	double result = double(n1) / double(n2);
	cout << "Division = " << result << endl;
}

void Q4()
{
	double i = 12, j = 5, avg;
	avg = (i + j) / 2;			// BUG : i+j/2;
	printf("Avg = %.2f\n", avg);
}

void Q5()
{
	string quote { "Aristotle said, \"Well begun is half done\"." };
	cout << quote << endl;
}

void Q6()
{
	string path{ "This is the share for lecture slides: \\\\10.100.56.21\\Lecture\\Lavneet Singh\\IT603." };
	cout << path << endl;
}

void Q7()
{
	string names[3];
	int marks[3][5]{};
	double scores[3]{};

	cout << "Enter three students name : " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Student " << (i + 1) << " name : ";
		cin >> names[i];
	}

	cout << endl << "Enter the marks of 3 students of 5 stubject(each out of 100) : " << endl;
	for (int i = 0; i < 3; i++)
	{
		int total{ 0 };
		cout << endl << "Enter 5 subject marks of " << names[i] << " : " << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "Subject " << (j+1) << " : ";
			cin >> marks[i][j];

			if (marks[i][j] > 100 || marks[i][j] < 0)
			{
				cout << "\nInvalid input...\nMarks Should be in between (0 to 100)" << endl;
				return;
			}
			total += marks[i][j];
		}
		scores[i] = double(total) / 5;
	}

	system("cls");
	for (int i = 0; i < 3; i++)
		cout << names[i] << " scored " << scores[i] << "%" << endl;

	// Without Loop
	/*
	cout << "Enter three students name : " << endl;
	cout << "Student 1 name : ";
	cin >> names[0];
	cout << "Student 2 name : ";
	cin >> names[1];
	cout << "Student 3 name : ";
	cin >> names[2];

	cout << endl << "Enter 5 subject marks of " << names[0] << " : " << endl;
	cout << "Subject 1 : ";
	cin >> marks[0][0];
	cout << "Subject 2 : ";
	cin >> marks[0][1];
	cout << "Subject 3 : ";
	cin >> marks[0][2];
	cout << "Subject 4 : ";
	cin >> marks[0][3];
	cout << "Subject 5 : ";
	cin >> marks[0][4];

	cout << endl << "Enter 5 subject marks of " << names[1] << " : " << endl;
	cout << "Subject 1 : ";
	cin >> marks[1][0];
	cout << "Subject 2 : ";
	cin >> marks[1][1];
	cout << "Subject 3 : ";
	cin >> marks[1][2];
	cout << "Subject 4 : ";
	cin >> marks[1][3];
	cout << "Subject 5 : ";
	cin >> marks[1][4];

	cout << endl << "Enter 5 subject marks of " << names[2] << " : " << endl;
	cout << "Subject 1 : ";
	cin >> marks[2][0];
	cout << "Subject 2 : ";
	cin >> marks[2][1];
	cout << "Subject 3 : ";
	cin >> marks[2][2];
	cout << "Subject 4 : ";
	cin >> marks[2][3];
	cout << "Subject 5 : ";
	cin >> marks[2][4];
	
	scores[0] = double(marks[0][0] + marks[0][1] + marks[0][2] + marks[0][3] + marks[0][4]) / 5;
	scores[1] = double(marks[1][0] + marks[1][1] + marks[1][2] + marks[1][3] + marks[1][4]) / 5;
	scores[2] = double(marks[2][0] + marks[2][1] + marks[2][2] + marks[2][3] + marks[2][4]) / 5;
	
	system("cls");
	
	cout << names[0] << " scored " << scores[0] << "%" << endl;
	cout << names[1] << " scored " << scores[1] << "%" << endl;
	cout << names[2] << " scored " << scores[2] << "%" << endl;
	*/
}

void Q8()
{
	string str;
	int words{ 0 }, vowels{ 0 }, i{ 0 };
	const char* allVowels = "aeiouAEIOU";

	cout << "Enter String : ";
	getline(cin, str, '\n');

	while (str[i] != '\0')
	{
		if ( isalpha(str[i]) && !isalpha(str[i+1]) )
			words++;

		if ( (strchr(allVowels, str[i]) != NULL) )
			vowels++;

		i++;
	}
	cout << "Number of words is : " << words << endl;
	cout << "Number of vowels is : " << vowels << endl;
}

void Q9()
{
	int number{ 0 };

	cout << "Enter the Number to get its Table : ";
	cin >> number;

	for (int i = 1; i < 11; i++)
		cout << number << " x " << i << " = " << (number * i) << endl;
}

void Q10()
{
	long long int number{ 0 };
	int digits{ 0 };

	cout << "Enter Number : ";
	cin >> number;

	while (number != 0)
	{
		number /= 10;
		digits++;
	}
	cout << "Digits : " << digits << endl;
}

void Q11()
{
	int number, n, newNum;

	cout << "Enter any number : ";
	cin >> number;

	cout << "Enter nth bit to toggle : ";
	cin >> n;

	newNum = number ^ (1 << n -1);

	cout << "Number after toggling : " << newNum << endl;
}

void Q12()
{
	cout << "Odd numbers between 1 to 100 are : " << endl;

	for (int i = 1; i <= 100; i += 2)
		cout << i << " ";
}

void Q13()
{
	long long int number{ 0 }, reverse{ 0 };
	int rem{ 0 };

	cout << "Enter any Number to Reverse: ";
	cin >> number;

	while (number > 0)
	{
		rem = number % 10;
		reverse = reverse * 10 + rem;
		number /= 10;
	}
	cout << "Reverse : " << reverse << endl;
}

void Q14()
{
	int dsa{ 0 }, c{ 0 }, dbms{ 0 }, maths{ 0 }, cs{ 0 };

	cout << "Marks between 0 to 100." << endl;
	cout << "Enter the marks of Data Structures : ";
	cin >> dsa;
	cout << "Enter the marks of C Programming : ";
	cin >> c;
	cout << "Enter the marks of Database Management : ";
	cin >> dbms;
	cout << "Enter the marks of Mathematics : ";
	cin >> maths;
	cout << "Enter the marks of Communication Skills : ";
	cin >> cs;

	if ((dsa >= 0 && dsa <= 100) && (c >= 0 && c <= 100) && (dbms >= 0 && dbms <= 100) && (maths >= 0 && maths <= 100) && (cs >= 0 && cs <= 100))
	{
		float percentage = float(dsa + c + dbms + maths + cs) / 5;

		if (percentage >= 90)
			cout << "Percentage = " << percentage << " : Grade A." << endl;
		else if (percentage >= 80)
			cout << "Percentage = " << percentage << " : Grade B." << endl;
		else if (percentage >= 70)
			cout << "Percentage = " << percentage << " : Grade C." << endl;
		else if (percentage >= 60)
			cout << "Percentage = " << percentage << " : Grade D." << endl;
		else if (percentage >= 40)
			cout << "Percentage = " << percentage << " : Grade E." << endl;
		else if (percentage < 40)
			cout << "Percentage = " << percentage << " : Grade F." << endl;
	}
	else
		cout << "Invalid Marks." << endl;
}

void Q15()
{
	char alphabet;
	const char* allVowels = "aeiouAEIOU";

	cout << "Enter Character : ";
	cin >> alphabet;

	if ((alphabet >= 'a' && alphabet <= 'z') || (alphabet >= 'A' && alphabet <= 'Z'))
		if ((strchr(allVowels, alphabet) != NULL))
			cout << alphabet << " is vowel." << endl;
		else
			cout << alphabet << " is consonant." << endl;
	else
		cout << alphabet << " is neither vowel nor consonant." << endl;
}

void Q16()
{
	int month{ 0 };
	const char* days[12]{ "31", "28 or 29", "31", "30", "31", "30", "31", "31", "30", "31", "30", "31" };

	cout << "Enter month number : ";
	cin >> month;

	if (month >= 1 && month <= 12)
			cout << "Number of days in month " << month << " is " << days[month - 1] << "." << endl;
	else
		cout << "Invalid number of month." << endl;
 }

void Q17()
{
	int sides[3]{ 0 };
	bool isTriangle{false};

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter value of side " << (i + 1) << " : ";
		cin >> sides[i];
	}

	if ( ((sides[0] + sides[1]) > sides[2]) && ((sides[2] + sides[1]) > sides[0]) && ((sides[0] + sides[2]) > sides[1]) )
		isTriangle = true;

	cout << "Triangle is " << ((isTriangle) ? "valid." : "not valid.") << endl;
}

int main()
{
	bool loop{ false };

	do {
		// Just uncomment any function and you are good to go...

		//Q1();
		//Q2();
		//Q3();
		//Q4();
		//Q5();
		//Q6();
		//Q7();
		Q8();
		//Q9();
		//Q10();
		//Q11();
		//Q12();
		//Q13();
		//Q14();
		//Q15();
		//Q16();
		//Q17();
		
		cout << "\nDo you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}