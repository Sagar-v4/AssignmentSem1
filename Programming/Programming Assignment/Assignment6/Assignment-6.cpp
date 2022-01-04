#include <iostream>
#include<cstring>
#include <string>
#include<vector>
using namespace std;
using uint = unsigned int;

void q1()
{
    char str[100];
    char* p;
    int  vovels = 0;

    cout << "Enter any string: ";
    cin.getline(str, 50);

    p = str;// base address of str stored in pointer p

    while (*p != '\0')
    {
        if (*p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U'
            || *p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
        {
            vovels++;
        }
        p++;
    }

    cout << "Number of Vowels in String:" << vovels << endl;
}

void q2()
{
    char str[100];
    char* p;
    int  capital = 0;

    cout << "Enter any string: ";
    cin.getline(str, 50);

    p = str;

    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            capital++;
        }
        p++;
    }

    cout << "Number of Capital letters in String:" << capital << endl;
}


void q3()
{
    char str[100];
    char* p;

    cout << "Enter any string: ";
    cin.getline(str, 50);

    p = str;

    while (*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p = (*p - 32);
        }
        p++;
    }

    cout << "String in capital letters:" << str << endl;
}


void q4()
{
    char str[100];
    char* p;
    int  words = 0;

    cout << "Enter any string: ";
    cin.getline(str, 50);

    p = str;

    while (*p != '\0')
    {
        if (*p == ' ')
        {
            words++;
        }
        p++;
    }

    cout << "Number of words in String:" << words + 1 << endl;
}

void q5()
{
    char str1[50], str2[50];
    char* p, * q;

    cout << "Enter a String:";
    cin.getline(str1, 50);

    p = str1 + strlen(str1) - 1;
    q = str2;

    while (p >= str1)
    {
        *q = *p;
        q++;
        p--;
    }
    *q = '\0';

    cout << "Reverse String: " << str2 << endl;
}

void q6()
{
    char str[100];
    int len = 0, begin, end;

    cout << "Enter string: ";
    cin.getline(str, 50);

    char* s = str;

    len = strlen(s);
    end = len - 1;

    cout << endl << "Required String:";
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ' || i == 0)
        {
            if (i == 0)
                begin = 0;
            else
                begin = i + 1;
            for (int j = begin; j <= end; j++)
                cout << s[j];
            end = i - 1;
            cout << " " ;
        }
    }
}

void q7()
{
    char  str[100];
    char* p;
    cout << "Enter String: ";
    cin.getline(str, 100);
    p = str;

    int one = 0, two = 0, three = 0;
    string temp = "";

    while (*p)
    {
        if (*p == ' ')
        {

            if (temp.length() == 1)
            {
                one++;

            }
            else if (temp.length() == 2)
            {
                two++;

            }
            else if (temp.length() == 3)
            {
                three++;

            }

            temp = "";

        }
        else
        {
            temp += *p;
        }
        p++;
    }


    if (temp.length() == 1)
    {
        one++;

    }
    else if (temp.length() == 2)
    {
        two++;

    }
    else if (temp.length() == 3)
    {
        three++;

    }
    cout << "1 Letter Words Are:" << one << endl;
    cout << "2 Letter Words Are:" << two << endl;
    cout << "3 Letter Words Are:" << three << endl;
}

void q8()
{
    char str1[50], str2[50];
    char* p, * q;

    cout << "Enter a String:" << endl;
    cin.getline(str1, 50);

    p = str1 + strlen(str1) - 1;
    q = str2;

    while (p >= str1)
    {
        *q = *p;
        q++;
        p--;
    }
    *q = '\0';

    if (strcmp(str1, str2) == 0)
    {
        cout << "It is a palindrome..." << endl;
    }
    else
    {
        cout << "\nIt is not a palindrome..." << endl;
    }

}

void q9()
{
    char str1[100];
    char str2[20];

    cout << "Enter a String:" << endl;
    cin.getline(str1, 50);

    cout << "Enter String to be searched in above string:" << endl;
    cin.getline(str2, 50);

    strcat_s(str1, " ");
    char* p = str1;
    char* q = str2;
    int temp, j, flag = 0;

    for (int i = 0; p[i] != '\0'; i++)
    {
        j = 0;
        if (p[i] == q[j])
        {
            temp = i + 1;
            while (p[i] == q[j])
            {
                i++;
                j++;
            }

            if (q[j] == '\0')
            {
                flag = 1;
            }
            else
            {
                i = temp;
                temp = 0;
            }
        }
    }

    if (flag == 1)
    {
        cout << "String1 is present in string2" << endl;
    }
    else
    {
        cout << "String1 is not present in string2" << endl;
    }
}

void q10() {
    string String;
    cout << "Enter a String : ";
    getline(cin, String);
    int i;
    cout << "Enter a Length of sub strings : ";
    cin >> i;
    int n = ceil((float)String.size() / (2 * i));
    vector<vector<string>> arr(n, vector<string>(2));
    vector<vector<string>>* ptr = &arr;
    char* str = &String[0];
    int check = 1;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < 2; k++) {
            (*ptr)[j][k] = "";
            for (int l = 0; l < i; l++) {
                if (check == 1) {
                    while (*str == ' ') { str++; }
                    (*ptr)[j][k] = (*ptr)[j][k] + *str;
                    str++;
                    if (*str == '\0') {
                        check = 0;
                        break;
                    }
                }
            } cout << (*ptr)[j][k] << endl;
        }
    }
}

void q11()
{
    char str1[100];
    char str2[100];
    int t = 0;

    cout << "Enter a String:" << endl;
    cin.getline(str1, 50);

    int count = 0;

    for (int i = 0; str1[i]; i++)
    {
        if (str1[i] != ' ')
        {
            str1[count++] = str1[i];
        }
    }

    cout << "Enter String to be searched in above string:" << endl;
    cin.getline(str2, 50);

    strcat_s(str1, " ");
    char* p = str1;
    char* q = str2;
    int temp{ 0 }, j, flag = 0;

    for (int i = 0; p[i] != '\0'; i++)
    {
        j = 0;

        if (p[i] == q[j])
        {
            temp = i + 1;
            while (p[i] == q[j])
            {
                i++;
                j++;
            }

            if (q[j] == '\0')
            {
                flag = 1;
            }
            else
            {
                i = temp;
                temp = 0;
            }
        }
    }

    if (flag == 1)
    {
        cout << "String1 is present in string2" << endl;
    }
    else
    {
        cout << "String1 is not present in string2"<<endl;
    }
}

int main()
{
     //q1();
     //q2();
     //q3();
     //q4();
     //q5();
     //q6();
     //q7(); 
     //q8();
     //q9();
     //q10();
     //q11();
}