// Assignment 2
// 202112114 : Sagar Variya
// Date : 4/9/2021

#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

void Q1() {
	
	int totalStudents{ 0 };
	double grades[100], totalGrades{ 0 }, avg{ 0 };
	string names[100];

	cout << "How many Students You Want? : ";
	cin >> totalStudents;

	for (int i = 0; i < totalStudents; i++)
	{
		cout << endl << "Enter Name of Student No. " << (i + 1) << " : ";
		cin >> names[i];

		cout << "Enter Grade[0 - 100] of " << names[i] << " : ";
		cin >> grades[i];
		
		totalGrades += grades[i];

		if (grades[i] > 100 || grades[i] < 0) {
			cout << names[i] << " Canceled...";
			totalGrades -= grades[i--];
		}
		cin.ignore();
	}

	avg = totalGrades / totalStudents;

	system("cls");
	cout << endl << "Average Grades : " << avg << "%" << endl << endl;

	cout << "|    NAMES    - GRADES |    NAMES    - GRADES |    NAMES    - GRADES | " << endl;

	for (int i = 0; i < totalStudents; i++)
	{
		if (i % 3 == 0) cout << endl << "| ";

		cout << setw(11) << names[i] << " - " << setw(5) << setprecision(4) << grades[i] << "% | ";
	}

	cout << endl;
}

void Q2() {

	string str, w;

	cout << "Enter String : ";
	getline(cin, str, '\n');

	istringstream iss(str);
	map<string, size_t> o;

	while (iss >> w)
		o[w]++;

	cout << endl << "|    WORDS    - COUNTS |    WORDS    - COUNTS |    WORDS    - COUNTS | " << endl;

	int j{ 0 };
	for (map<string, size_t>::iterator i = o.begin(); i != o.end(); i++, j++)
	{
		if (j % 3 == 0) cout << endl << "| ";
		cout << setw(11) << i->first << " - " << setw(6) << i->second << " | ";
	}

	cout << endl;
}

void Q3() {

	string str, word, replaced;
	int n;

	cout << endl << "Enter String : ";
	getline(cin, str, '\n');

	cout << endl << "Enter Word To be Replace : ";
	getline(cin, word, '\n');

	for (int i = 0; i < word.length(); i++)
		replaced += "*";

	istringstream iss(str);
	vector<string> result;

	for (string s; iss >> s;)
		result.push_back(s);

	n = result.size();

	cout << endl << "After Replacing " << word << " : ";
	for (int i = 0; i < n; i++)
	{
		if (result[i] == word)
			result[i] = replaced;

		cout << result[i] << ' ';
	}

	cout << endl;
}

void Q4() {

	string str1{}, str2{};
	bool isAnagram{ false };

	cout << "[ CHECK ANAGRAM (one word) ]" << endl;

	cout << "Enter String 1 : ";
	cin >> str1;
	cout << "Enter String 2 : ";
	cin >> str2;
	
	if (str1.length() == str2.length()) {
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		if (str1 == str2) isAnagram = true;
	}

	cout << endl << ((isAnagram) ? "Its Anagram" : "Its Not Anagram") << endl;
}

const std::string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string& s) {
	return rtrim(ltrim(s));
}

void Q5() {

	string str[2]{};

	cout << "[ CHECK ANAGRAM (string) ]" << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Enter String " << (i+1) <<" : ";
		getline(cin, str[i], '\n');

		sort(str[i].begin(), str[i].end());
		str[i] = trim(str[i]);
	}

	cout << endl << ((str[0].compare(str[1]) == 0) ? "Its Anagram" : "Its Not Anagram") << endl;
}

void Q6() {

	string str;
	cout << "Enter String : ";
	getline(cin, str, '\n');

	istringstream iss(str);
	vector<string> result;

	for (string s; iss >> s;)
		result.push_back(s);

	int n = result.size();

	for (int i = 0; i < n; i++)
		if (result[i].at(0) >= 65 && result[i].at(0) <= 90 || result[i].at(0) >= 97 && result[i].at(0) <= 122)
			cout << result[i] << ' ';

	cout << endl;
}

void Q7() {

	string str;
	stringstream strs;
	int total{ 0 }, n;

	cout << endl << "Enter Number : ";
	getline(cin, str, '\n');
	strs << str;

	while (strs >> n)
		total += n;

	cout << endl << "Total : " << total << endl;
}
void Q8() {

	int total{ 0 };
	string numbers, temp{ "" };

	cout << "Enter numbers terminated by # : " << endl;

	while (numbers != "#")
	{
		cin >> numbers;
		if (numbers != "#")
		{
			total += stoi(numbers);
			temp += numbers + " ";
		}
	}
	cout << endl << "Sum of Numbers ( " << temp << ") : " << total << endl;
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
		Q6();
		//Q7();
		//Q8();

		cout << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}
