
// Assignment 6
// 202112114 | Sagar Variya
// Date : 13/10/2021

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
using uint = unsigned int;

const uint Size{ 100 };

void Ass6InputString(char (&string)[Size])
{
	char* const s{ string };
	cout << endl << "Enter String : ";
	cin.getline(s, Size);
}

int Q1countVowels(char(&string)[Size])
{
	const char* ps{ string };
	const char* const allVowels{ "aeiouAEIOU" };
	int vowels{};

	while (*ps != '\0')
		if (strchr(allVowels, *ps++) != NULL) vowels++;

	return vowels;
}

void Q1()
{
	char s[Size]{};
	int totalVowels{};

	Ass6InputString(s);

	totalVowels = Q1countVowels(s);
	cout << endl << "Total Vowels : " << totalVowels;
}

int Q2countCapitals(char(&string)[Size])
{
	const char* ps{ string };
	int capitals {};

	while (*ps != '\0')
	{
		if (*ps >= 65 && *ps <= 90)
			capitals++;
		ps++;
	}

	return capitals;
}

void Q2()
{
	char s[Size]{};
	int totalCapitals{};

	Ass6InputString(s);

	totalCapitals = Q2countCapitals(s);
	cout << endl << "Total Capital Letters : " << totalCapitals;
}

void Q3toUpperCase(char(&string)[Size])
{
	char* ps{ string };

	while (*ps != '\0')
		*ps++ = (*ps >= 97 && *ps <= 122) ? *ps - 32 : *ps;
}

void Q3()
{
	char s[Size]{};

	Ass6InputString(s);

	Q3toUpperCase(s);

	cout << endl << "Converted to All Capital Letters : " << s;
}

int Q4countWords(char(&string)[Size])
{
	const char* ps{ string };
	int words{};

	while (*ps != '\0')
		if (isalpha(*ps++) && !isalpha(*ps)) words++;

	return words;
}

void Q4()
{
	char s[Size]{};
	int totalWords{};

	Ass6InputString(s);

	totalWords = Q4countWords(s);
	cout << endl << "Total Words : " << totalWords;
}

void Q5reverseString(char(&string)[Size])
{
	char* ptr_begin{ string }, * ptr_end{ string };
	int strLength{}, i{};

	strLength = strlen(string);

	while (i++ < strLength - 1)
		ptr_end++;

	for (i = 0; i < strLength / 2; i++, ptr_begin++, ptr_end--)
	{
		char temp = *ptr_begin;
		*ptr_begin = *ptr_end;
		*ptr_end = temp;
	}
}

void Q5()
{
	char s[Size]{};

	Ass6InputString(s);

	Q5reverseString(s);

	cout << endl << "After Reversing : " << s;
}

void Q6reverseByWords(char(&string)[Size])
{
	const char* ps{ string };
	char temp[Size][Size]{};
	int len{}, i{}, j{}, n{};

	len = strlen(string);
	
	while(*ps != '\0')
	{
		while (*ps != '\0' && *ps == ' ') ps++;

		while (*ps != '\0' && *ps != ' ')
		{
			temp[i][j] = *ps;
			ps++;
			j++;
		}
		temp[i][j] = '\0';
		j = 0;
		i++;
	}

	for (int k = i - 1; k >= 0; k--)
	{
		for (int l = 0; temp[k][l] != '\0'; l++)
			string[n++] = temp[k][l];
		string[n++] = ' ';
	}

	while (n < len) string[n++] = ' ';
}

void Q6()
{
	char s[Size]{};

	Ass6InputString(s);

	Q6reverseByWords(s);

	cout << endl << "After Reversing Word by Word : " << s;
}

void Q7countLetters(char(&string)[Size], int(&letters)[Size])
{
	const char* ps{ string };

	while (*ps != '\0')
	{
		int count{ 0 };
		while (*ps++ != ' ')
		{
			count++;
			if (*ps == '\0') break;
		}
		if (count > 0) letters[count - 1]++;
	}
}

void Q7()
{
	char s[Size]{};
	int letters[Size]{};

	Ass6InputString(s);

	Q7countLetters(s, letters);

	cout << endl << "Words" << " : " << "Letters";
	for (int i = 0; i < Size; i++)
	{
		if (letters[i] == 0) continue;
		cout << endl << setw(3) << i + 1 << "   : " << setw(3) << letters[i];
	}
}

bool Q8isPalindrome(char(&string)[Size])
{
	const char* ptr_begin{ string }, * ptr_end{ string };
	int strLength{}, i{};
	bool isPalindrome{ false };

	strLength = strlen(string);

	while (i++ < strLength - 1)
		ptr_end++;

	for (i = 0; i < strLength / 2; i++)
		if (*ptr_begin++ == *ptr_end--) isPalindrome = true;

	return isPalindrome;
}

void Q8()
{
	char s[Size]{};
	bool isPalindrome{};

	Ass6InputString(s);

	isPalindrome = Q8isPalindrome(s);
	cout << endl << "It's" << ((isPalindrome) ? " " : " Not ") << "Palindrome...";
}

bool Q9isSubString(char(&string1)[Size], char(&string2)[Size], bool spaceIgnore = false)
{
	const char* ptr_s1{ string1 }, * ptr_s2{ string2 };
	bool isSubString{ false };

	while (*ptr_s1 != '\0')
	{
		if (spaceIgnore)
			if (*ptr_s2 == ' ')
				while (*ptr_s2 == ' ') ptr_s2++;

		if (*ptr_s1 == *ptr_s2)
			while (*ptr_s2 != '\0')
			{
				if (spaceIgnore)
				{
					if (*ptr_s1 == ' ')
					{
						ptr_s1++;
						continue;
					}
					if (*ptr_s2 == ' ')
					{
						ptr_s2++;
						continue;
					}
				}
				isSubString = (*ptr_s1 == *ptr_s2++ && *ptr_s1++ != '\0') ? true : false;
				if (!isSubString)
				{
					ptr_s2 = string2;
					break;
				}
			}
		ptr_s1++;
	}

	return isSubString;
}

void Q9()
{
	char s1[Size]{}, s2[Size]{};
	bool isSubString{};

	Ass6InputString(s1);
	Ass6InputString(s2);

	isSubString = Q9isSubString(s1, s2);

	cout << endl << "[Not Ignoring Spaces]" << endl << s2 << " is" << ((isSubString) ? "" : " Not") << " Exists in " << s1;
}

void Q10splitString(char(&string)[Size], char(&stringArray)[Size][Size], int n, int &r)
{
	char* ps{ string };
	int splitNumber{ n };

	while (*ps != '\0')
	{
		for (int i = 0; i < splitNumber; i++)
		{
			if (*ps == '\0') break;
			if (*ps == ' ') *ps++;
			stringArray[r][i] = *ps++;
		}
		r++;
	}
}

void Q10()
{
	char s[Size]{}, sArr[Size][Size]{};
	int splitNumber{}, rows{};

	Ass6InputString(s);

	cout << "Split in How many characters : ";
	cin >> splitNumber;

	Q10splitString(s, sArr, splitNumber, rows);

	cout << endl << "After Spliting into " << splitNumber << " letters : " << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < splitNumber; j++) cout << sArr[i][j];
		cout << endl;
	}
}

void Q11()
{
	char s1[Size]{}, s2[Size]{};
	char* ptr_s1{ s1 }, * ptr_s2{ s2 };
	bool isSubString{ false };

	Ass6InputString(s1);
	Ass6InputString(s2);

	isSubString = Q9isSubString(s1, s2, true);

	cout << endl << "[Ignoring Spaces]" << endl << s2 << " is" << ((isSubString) ? "" : " Not") << " Exists in " << s1;
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
		//Q5();
		//Q6();
		//Q7();
		//Q8();
		//Q9();
		Q10();
		//Q11();
		
		// NOTE :
		// try Q9 & Q11 together
		// in Q11 using same function of Q9 with 3rd parameter sapaceIgnore = true

		cout << endl << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}

