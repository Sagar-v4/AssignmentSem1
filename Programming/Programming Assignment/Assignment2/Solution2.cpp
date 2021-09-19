#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;

void Q1()
{
  int no, sum = 0;
  int j = 0;
  int average;
  cout << "Number of student : ";
  cin >> no;
  string Name[100];
  int Grade[100];
  for (int i = 0; i < no; i++)
  {
    cout << "Student Name:";
    cin >> Name[i];
    cout << "Enter Grade: ";
    cin >> Grade[i];
  }
  cout << endl;
  for (int i = 0; i < no; i++)
  {
    cout << Name[i] << "\t" << Grade[i] << "\t";
    ++j;
    if (j % 3 == 0)
    {
      cout << "\n" <<endl;
    }
  }
  for (int i = 0; i < no; i++)
  {
    sum = sum + Grade[i];

  }
  cout << endl;
  average = sum / no;
  cout << "Average Grade" << average<<endl;
}
void Q2() {
  int i = 0; int n = 0; int count[100]; string str; 
  cout << "Enter String: ";
  getline(cin, str);
  string words[100];
  
  while (i < str.length()) {
    while (isspace(str[i]) && i < str.length()) {
      i++;
    }
    while (!isspace(str[i]) && i < str.length()) {
      words[n] += str[i];
      i++;
    }
    n++;
    i++;
  }
  for (i = 0; i < n; i++) {
    count[i] = 1;
    for (int k = i + 1; k < n; k++) {
      if (words[i] == words[k]) {
        words[k] = "";
        count[i]++;
      }
    }
  }
  int k = 0;
  for (i = 0; i < n; i++) {
    if (k % 3 == 0)
      cout << endl;
    if (words[i] != "") {
      cout << words[i] << "  " << count[i] << "     ";
      k++;
    }
  }

}

void Q3() {

  int i = 0; int n = 0; int count[100]; string str; string rep[10]; string hold;
  cout << "Enter String: ";
  getline(cin, str);
  cout << "Enter word to be replaced by asteriks: ";
  cin >> rep[0];
  string words[100];

  while (i < str.length()) {
    while (isspace(str[i]) && i < str.length()) {
      i++;
    }
    while (!isspace(str[i]) && i < str.length()) {
      words[n] += str[i];
      i++;
    }
    n++;
    i++;
  }
  for (i = 0; i < n; i++) {
    if (words[i] == rep[0]) {
      hold = words[i];
      for (int j = 0; j < hold.length(); j++) {
        hold[j] = '*';
      }
      words[i] = hold;
    }
  }
  for  (i = 0; i < n; i++)
  {
    cout << words[i]<<" ";
    }
  
}

void Q4()
{
    string str1, str2;
    cout << "Enter first word: ";
    cin >> str1;
    cout << "Enter second word: ";
    cin >> str2;

    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2) {
        cout << endl << "Not anagram";
        exit(0);
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[i]) {
            cout << endl << "Not anagram";
            exit(0);
        }
    }

    cout << endl << "anagram";
}
void Q5() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());

    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2) {
        cout << endl << "Not anagram";
        exit(0);
    }

    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[i]) {
            cout << endl << "Not anagram";
            exit(0);
        }
    }

    cout << endl << "Anagram";
}
void Q6() {
  string str;
  char ch;
  cout << "Enter String: ";
  getline(cin, str);
  cout << "Enter char: ";
  cin >> ch;
  int i = 0, len = str.length(), n = 0, cnt[100];
  string words[100];

  while (i < len) {
    while (isspace(str[i]) && i < len) {
      i++;
    }
    while (!isspace(str[i]) && i < len) {
      words[n] += tolower(str[i]);
      i++;
    }

    if ((tolower(ch)) == (tolower(words[n][0]))) {
      cout << words[n] << "\t";
    }
    n++;
    i++;
  }
  cout << endl;
}

void Q7() {
  string str;
  cout << "Enter String: ";
  char ch;
  ch = getchar();
  while(ch != '#'){
    str+=ch;
    ch= getchar();
  }
  cout<<str;
  stringstream ss(str);
  string word;
  int sum = 0, num;
  while (ss >> num) {
    sum += num;
  }
  cout << "Sum: " << sum;
  cout << endl;
}

void Q8() {
  string str;
  int sum = 0, num;
  cout << "Enter String: ";
  char ch;
  ch = getchar();
  while(ch != '#'){
    str+=ch;
    ch= getchar();
  }
  int i = 0, len = str.length();
  while (i < len) {
    num = 0;
    while (isspace(str[i]) && i < len) {
      i++;
    }
    while (!isspace(str[i]) && i < len) {
      num = (num * 10) + (str[i] - '0');
      i++;
    }
    sum += num;
    i++;
  }
  cout << "Sum:" << sum;
  cout << endl;
}
int main()
{
//Q1();
 // Q2();
//  Q3();
 // Q4();
 // Q5();
 // Q6();
 // Q7();
  //Q8();
return 0;
}