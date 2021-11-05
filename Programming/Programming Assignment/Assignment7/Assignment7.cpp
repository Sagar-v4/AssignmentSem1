
// Assignment 7
// 202112114 | Sagar Variya
// Date : 18/10/2021

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
using uint = unsigned int;

const uint Size{100};
const uint Alphas{27};
const uint Strs{5};
const uint PAGES{3};
const uint ROWS{3};
const uint COLS{3};
const uint ChatMSGS{16};
const uint UIWidth{30};


void Ass7InputString(char (&string)[Size])
{
	char *const s{string};
	cout << endl
		 << "Enter String : ";
	cin.getline(s, Size);
}

/*
 
 1. Read a string from user. The program should then calculate the frequency of occurrence of characters in the input string. It should store the results in a two dimentional array - first column is for the characters and 2nd column is for their frequency (you can use 2nd column of type char to store int, as we can safely assume that the frequency number would fit in one byte). It should then display the 2-column table of char-frequency.

Input : "I am a programmer"

Output : [
	  ['i','1'],
	  ['a','3'],
	  ['m','3'],
	  ['p','1'],
	  ['r','3'],
	  ['o','1'],
	  ['g','1'],
	  ['e','1']
	 ] 

 */

void Q1countFrequency(char (&s)[Size], char (&a)[Alphas][2])
{
	char *ps{s}, *pa{nullptr};

	while (*ps != '\0')
	{
		if ((*ps >= 65 && *ps <= 90) || (*ps >= 97 && *ps <= 122))
		{
			pa = &a[0][0];
			bool notAvailable{true};
			*ps = (*ps >= 97 && *ps <= 122) ? *ps : (*ps + 32);

			while (*pa != '\0')
			{
				if (*pa == *ps && (*++pa += 1) && (notAvailable = false))
					break;
				pa += 2;
			}

			if (notAvailable && (*pa = *ps))
				*++pa = 1;
		}
		ps++;
	}
}

void Q1()
{
	char s[Size]{}, ans[Alphas][2]{}; // In ans[i][1...] we are storing hex value

	Ass7InputString(s);
	Q1countFrequency(s, ans);

	cout << endl
		 << "Words"
		 << " : "
		 << "Frequency";
	for (int i = 0; ans[i][0] != '\0'; i++)
		cout << endl
			 << setw(3) << ans[i][0] << "   : " << setw(3) << (int)ans[i][1]; // (int)ans[i][1] = storing hex & converted to int to go beyond 9 value
}

/*
2. Read a string from user. The program then should display the string with its charaters in alphabetic order.

Input : "I can do coding"

Output : "I acn do cdgino"
*/

void Q2swap(char *xp, char *yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void Q2convertToAlphabeticly(char (&s)[Size])
{
	char *ps{s};

	for (int i = 0; *(ps + i) != '\0'; i++)
	{
		int f{i}, r{i};
		while (isalpha(*(ps + i)))
		{
			r++;
			i++;
		}

		for (int j = f; j < r - 1; j++)
			for (int k = j + 1; k < r; k++)
				if (*(ps + k) < *(ps + j))
					Q2swap((ps + k), (ps + j));
	}
}

void Q2()
{
	char s[Size]{};

	Ass7InputString(s);
	Q2convertToAlphabeticly(s);

	cout << endl
		 << "After Convertion : " << s;
}

/*
3. Read five strings from user. Find the longest string among the strings input and display it along with its length.

Input :
"a"
"ab"
"xyz"
"pqrs"
"x"

Output :
"pqrs"
length = 4
*/

void Q3findLongestString(char(s)[Strs][Size], int (&lss)[Strs], int(&mx))
{
	char *ps{s[0]};
	int *plss{lss}, *maxLen{&mx};

	for (int i = 0; i < Strs; i++, plss++)
	{
		int j{0};
		while (*(ps + (i * Size) + j) == 32)
			j++;
		for (; *(ps + (i * Size) + j) != '\0'; j++)
			if ((*(ps + (i * Size) + j) == 32) && ((*(ps + (i * Size) + j + 1) == 32 || (*(ps + (i * Size) + j + 1) == '\0'))))
			{
			}
			else
				(*plss)++;

		if (*plss > *maxLen)
			*maxLen = *plss;
	}
}

void Q3printLongestString(char(s)[Strs][Size], int(lss)[Strs], int(mx))
{
	char *ps{s[0]};
	int *plss{lss}, maxLen{mx};

	for (int i = 0; i < Strs; i++, plss++)
	{
		if (*plss == maxLen)
		{
			int j{0};
			while (*(ps + (i * Size) + j) == 32)
				j++;
			for (; *(ps + (i * Size) + j) != '\0'; j++)
				if ((*(ps + (i * Size) + j) == 32) && ((*(ps + (i * Size) + j + 1) == 32 || (*(ps + (i * Size) + j + 1) == '\0'))))
				{
				}
				else
					cout << *(ps + (i * Size) + j);
			cout << " | " << *plss << endl;
		}
	}
}

void Q3()
{
	char s[Strs][Size]{};
	int strSizes[Strs]{0}, max{0};

	for (int i = 0; i < Strs; i++)
		Ass7InputString(s[i]);

	Q3findLongestString(s, strSizes, max);

	cout << endl
		 << "Longest Strings : " << endl
		 << endl;
	Q3printLongestString(s, strSizes, max);
}

/*
4. There is a treasure that can be opened by a specific combination of three integers. These three integers are to be selected from numbers stored in a 3-d array, secrets[PAGES][ROWS][COLS] (take PAGES=ROWS=COLS=3).
The owner of this treasure knows a number whose individual digits are indices of numbers to be picked up from 1st, 2nd and 3rd page of the secrets array. Eg. if the number is 259, it means pick the 2nd number from page 1, 5th from page 2 and 9th from page 3.
Write a program that first fills up secrets array using numbers input by user. Then it takes the number from owner of treasure and displays the secret combination of 3 numbers.

Input :
int arr[3][3][3]=
		 { {{1,2,3},{4,5,6},{7,8,9}},
		   {{10,11,12},{13,14,15},{16,17,18}},
		   {{19,20,21},{22,23,24},{25,26,27}}
		 };

number = 259

Output : 21427

Explanation :

page(1)   1 2 3
		  4 5 6
		  7 8 9
				  3x3

page(2)   10 11 12
		  13 14 15
		  16 17 18
				   3x3

page(3)   19 20 21
		  22 23 24
		  25 26 27
				   3x3
*/

void Q4InputArray(int (&a)[PAGES][ROWS][COLS], bool inputManually = false)
{
	int *arr{&a[0][0][0]}, temp{1};

	cout << endl
		 << "Page No. | Row No. | Col No. : " << endl
		 << endl;
	for (int i = 0; i < PAGES; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			for (int k = 0; k < COLS; k++)
			{

				cout << setw(5) << (i + 1) << setw(5) << "|"
					 << setw(5) << (j + 1) << setw(5) << "|"
					 << setw(5) << (k + 1) << setw(6) << ": ";

				if (inputManually)
				{
					// Input all 27 elements manually
					cin >> *(arr + temp - 1);
				}
				else
				{
					// input default 1 to 27 values
					cout << temp << endl;
					*(arr + temp - 1) = temp;
				}

				temp++;
			}
			cout << endl;
		}
		cout << endl;
	}
}

void Q4InputNumber(int(&n))
{
	int *arr{&n};

	do
	{
		cout << "Enter Number : ";
		cin >> *arr;
	} while (*arr < 111 || *arr > 999);
}

int Q4findLen(int n)
{
	int num{n}, count{0};

	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

void Q4findTreasureKeys(int(a)[PAGES][ROWS][COLS], int n, int(&k))
{
	int *arr{&a[0][0][0]}, *key{&k}, num{n}, targets[PAGES]{}, temp{};

	for (int i = PAGES - 1; i >= 0; i--)
	{
		temp = num % 10;
		num /= 10;
		targets[i] = temp;
	}

	temp = 1;
	for (int i = 0; i < PAGES; i++)
	{
		int val = 1;
		for (int j = 0; j < ROWS; j++)
		{
			for (int k = 0; k < COLS; k++)
			{
				if (targets[i] == val)
				{
					int increment = (Q4findLen(*(arr + temp - 1)));

					while (increment-- > 0)
						*key *= 10;

					*key += *(arr + temp - 1);
				}
				temp++;
				val++;
			}
		}
	}
}

void Q4()
{
	int arr[PAGES][ROWS][COLS]{}, number{}, key{};

	// default value(1 to 27)
	Q4InputArray(arr);

	// input manually
	//Q4InputArray(arr, true);

	Q4InputNumber(number);
	Q4findTreasureKeys(arr, number, key);

	cout << endl
		 << "Key : " << key;
}

/*
5. Simulate a chat UI in a 2-d array of characters. We can input few strings from console and consider every even string as reponse to the previous one. First store strings got from console in a 2-d array normally. Then from this array, store these input strings in a another two dimentional array such that 1,3,5... strings (which are assumed from chat user 1) should be left aligned and 2,4,6... (which from chat user 2) should be right aligned. This is your 'model' of data. Now we want to show it to user also - i.e. create a view. So copy these aligned stings to yet another array that is padded with spaces so that when you display this padded array on console using a pointer, it should show chat strings aligned.
Eg.
Input is -
Hello
hi
how are you
i'm fine, how about you?
me fine too

In the 'model' array (* signfies don't-care char as the string is null terminated, _ signfies null character):
Hello_************************
***************************hi_
how are you_******************
*****i'm fine, how about you?_
me fine too_******************

In the 'view' array- (* signfies space character and _ signfies null character - as we want to see the output just like in this array)
Hello*************************_
****************************hi_
how are you*******************_
******i'm fine, how about you?_
me fine too*******************_

Note both * and _ are for describing the question, not for your program. It should show space character as space.
*/

void Q5calculateRawData(char *ps, int (&userId)[ChatMSGS], int (&msgSize)[ChatMSGS], int (&totalWords)[ChatMSGS], int (&words)[ChatMSGS][Size])
{
	int word{}, wordCount{};

	for (int i = 0; i < ChatMSGS; i++)
	{
		word = 0;
		wordCount = 1;
		totalWords[i] = 0;
		int j{0};
		bool isSpace{false};

		while (*(ps + (i * Size) + j) == 32)
			j++;

		while (*(ps + (i * Size) + j) != '\0')
		{
			if (*(ps + (i * Size) + j) != 32 &&
				((*(ps + (i * Size) + j + 1) == 32) ||
				 (*(ps + (i * Size) + j + 1) == '\0')))
			{
				isSpace = true;
			}
			else
			{
				wordCount++;
			}

			if (isSpace)
			{
				words[i][word++] = wordCount;
				totalWords[i]++;
				wordCount = 0;
				isSpace = false;
			}
			if ((*(ps + (i * Size) + j) == 32) && ((*(ps + (i * Size) + j + 1) == 32 || (*(ps + (i * Size) + j + 1) == '\0'))))
			{
			}
			else
				msgSize[i]++;
			j++;
		}

		userId[i] = (i % 2 == 0) ? 2 : 1;
	}
}

void Q5setModel(char(s)[ChatMSGS][Size], char (&sm)[Size][UIWidth], int(&smi))
{
	char *ps{&s[0][0]}, *psm{&sm[0][0]};
	int msgSize[ChatMSGS]{0}, userId[ChatMSGS]{0}, words[ChatMSGS][Size]{0}, totalWords[ChatMSGS]{0};

	Q5calculateRawData(ps, userId, msgSize, totalWords, words);

	for (int i = 0; i < ChatMSGS; i++)
	{
		int j{0}, smj{0};
		while (*(ps + (i * Size) + j) == 32)
			j++;

		if (userId[i] == 1)
		{
			for (int k = 0; k < totalWords[i]; k++)
			{
				if (smj + words[i][k] < 25)
				{
					for (int l = 0; l < words[i][k]; l++)
					{
						char ch = *(ps + (i * Size) + j++);
						*(psm + (smi * UIWidth) + smj++) = ch;
					}
					*(psm + (smi * UIWidth) + smj++) = *(ps + (i * Size) + j++);
				}
				else
				{
					smi++;
					smj = 0;
				}
			}
		}

		if (userId[i] == 2)
		{

			int space{4};
			if (msgSize[i] < 25)
			{
				space = UIWidth - msgSize[i] - 1;
			}
			while (space-- > 0)
			{
				*(psm + (smi * UIWidth) + smj++) = 32;
			}
			for (int k = 0; k < totalWords[i]; k++)
			{
				if (smj + words[i][k] < UIWidth)
				{
					for (int l = 0; l < words[i][k]; l++)
					{
						char ch = *(ps + (i * Size) + j++);
						*(psm + (smi * UIWidth) + smj++) = ch;
					}
					if (smj + words[i][k] < UIWidth)
						*(psm + (smi * UIWidth) + smj++) = *(ps + (i * Size) + j++);
				}
				else
				{
					smi++;
					smj = 0;
					space = 4;
					while (space-- > 0)
					{
						*(psm + (smi * UIWidth) + smj++) = 32;
					}
				}
			}
		}
		smi++;
	}
}

void Q5viewChat(char(arr)[Size][UIWidth], int(r), bool mobileView = false)
{
	char *parr{arr[0]};
	int *rows{&r};
	char name[25]{};

	if (mobileView)
	{
		cout << "Enter persons name with whom you wanna chat : ";
		cin.getline(name, 25);
		system("cls");
	}
	char c[20]{};
	c[0] = 201;
	c[1] = 205;
	c[2] = 203;
	c[3] = 187;
	c[4] = 186;
	c[5] = 248;
	c[6] = 22;
	c[7] = 10;
	c[8] = 250;
	c[9] = 200;
	c[10] = 188;
	c[11] = 186;
	c[12] = 1;
	c[13] = 196;
	c[14] = 218;
	c[15] = 194;
	c[16] = 191;
	c[17] = 193;
	c[18] = 179;
	c[19] = 26;

	// sorry for this messy code but its GUI in CUI ☺
	if (mobileView)
	{
		cout << "\t" << c[0] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[2] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[2] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[3] << endl;

		cout << "\t" << c[4] << " " << c[8] << c[8] << c[8] << c[8] << c[8] << "   " << c[4] << " " << 0 << " " << c[6] << c[6] << c[6] << c[6] << " " << c[5] << " " << c[4] << "  9:52AM " << c[4] << endl;

		cout << "\t" << c[4] << "         " << c[9] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[1] << c[10] << "         " << c[4] << endl;

		cout << "\t" << c[4] << c[13] << c[13] << c[13] << c[15];
		for (int i = 0; i < 26; i++)
			cout << c[13];
		cout << c[4] << endl;

		cout << "\t" << c[4] << " " << c[12] << " " << c[18] << " " << name;
		int len = UIWidth - strlen(name) - 5;
		while (len-- > 0)
			cout << " ";
		cout << c[4] << endl;

		cout << "\t" << c[4] << c[13] << c[13] << c[13] << c[17];
		for (int i = 0; i < 26; i++)
			cout << c[13];
		cout << c[4] << endl;
	}

	for (int i = 0; i < ((*rows > 16) ? 16 : *rows); i++)
	{
		if (mobileView)
		{
			cout << "\t" << c[4];
		}
		for (int j = 0; j < UIWidth; j++)
		{
			if (*(parr + (i * UIWidth) + j) == NULL)
				cout << " ";
			else
				cout << *(parr + (i * UIWidth) + j);
		}
		if (mobileView)
			cout << c[4] << endl;
		else
			cout << endl;
	}

	if (mobileView)
	{
		if (*rows < 20)
			for (int i = 0; i < 20 - *rows - 4; i++)
				cout << "\t" << c[4] << "                              " << c[4] << endl;

		cout << "\t" << c[4] << c[13] << c[13] << c[13] << c[15] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[15] << c[13] << c[13] << c[13] << c[4] << endl;

		cout << "\t" << c[4] << " " << c[12] << " " << c[18] << " Type a message...    " << c[18] << " " << c[19] << " " << c[4] << endl;

		cout << "\t" << c[4] << c[13] << c[13] << c[13] << c[17] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[13] << c[17] << c[13] << c[13] << c[13] << c[4] << endl;

		cout << "\t" << c[4] << "         " << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << c[6] << "         " << c[4] << endl;

		cout << "\t" << c[9];
		for (int i = 0; i < 30; i++)
			cout << c[1];
		cout << c[10];
	}
}

void Q5()
{
	char sampleStrs1[ChatMSGS][Size]{
		{"Hello"},
		{"hi"},
		{"how   are you?"},
		{"i'm fine, how about you?"},
		{"me fine too"},
		{"okk"}};

	char sampleStrs[ChatMSGS][Size]{
		{"Hiii"},
		{"Hello"},
		{"Kya che dekhato nathi?"},
		{"Thodu kam ma chhu"},
		{"Meeting ma pn nai avto"},
		{"Ala pelu thay gyu etle"},
		{"Shuu?"},
		{"Setting"},
		{"O bhai koni sathe?"},
		{"P..."},
		{"Achha etle gayab chho"},
		{"Haaa"},
		{"Laga re laga ree.."}};

	char sampleStrs2[ChatMSGS][Size]{
		{"Hii"},
		{"Heloo"},
		{""}};

	char sModel[Size][UIWidth]{};
	int rows{0};

	Q5setModel(sampleStrs, sModel, rows);

	// GUI chat view
	Q5viewChat(sModel, rows, true);

	// CUI chat view
	//Q5viewChat(sModel, rows);
}

int main()
{
	auto loop{false};

	do
	{
		// Just uncomment any function and you are good to go...

		//Q1();
		//Q2();
		//Q3();
		//Q4();		// NOTE
		Q5(); // NOTE

		// NOTE :
		// Q4) two way to fill 3*3*3 array (Auto 1 to 27 & manually) inbuilt in Q4InputArray() ->  last patameter as bool inputManually... default value is false...
		// Q5) to show the chat there is 2 versions (GUI & CUI) inbuilt in Q5viewChat() -> last patameter as bool mobileView... default value is false...

		cout << endl
			 << endl
			 << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);

	return 0;
}
