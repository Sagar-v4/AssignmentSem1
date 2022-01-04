#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;

// Question 1 Starts Here
void answer1()
{
    char *ptr[5];
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = new char[200];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Name " << i + 1 << " - ";
        cin.getline(ptr[i], 200);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Name " << i + 1 << " - " << ptr[i] << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        char temp[strlen(ptr[i])];
        strcpy(temp, ptr[i]);
        free(ptr[i]);
        ptr[i] = new char[strlen(temp)];
        strcpy(ptr[i], temp);
    }
    cout<<"After Reallocation:-"<<endl;
    for (int i = 0; i < 5; i++)
    {

        cout << "Name " << i + 1 << " - " << ptr[i] << endl;
        free(ptr[i]);
    }
}
// Question 1 Ends Here

// Question 2 Starts Here
struct player
{
    char *name[1], *game[1];
    int age;
};
void answer2()
{
    player p;
    char *input = new char[100];
    cout << "Enter Name: ";
    cin.getline(input, 50, '\n');
    *p.name = input;
    while (*input != '\0')
    {
        input++;
    }
    *(input++) = '\0';
    cout << "Enter Age: ";
    cin.getline(input, 3, '\n');
    p.age = atoi(input);
    while (*input != '\0')
    {
        input++;
    }
    *(input++) = '\0';
    cout << "Enter Game: ";
    cin.getline(input, 40, '\n');
    *p.game = input;
    while (*input != '\0')
    {
        input++;
    }
    *(input++) = '\0';
    cout << endl
         << "Details Of The Player - " << endl
         << endl;
    cout << "Name - " << *p.name << endl;
    cout << "Age - " << p.age << endl;
    cout << "Game Name - " << *p.game << endl;
    input = *p.name;
    free(input);
}
// Question 2 Ends Here

// Question 3 Starts Here
void answer3()
{
    int M, N;
    cout << "Enter M - ";
    cin >> M;
    cout << "Enter N - ";
    cin >> N;
    if (M <= 0 || N <= 0)
    {
        cout << "Invalid Input." << endl;
        return;
    }
    cout << endl;
    double *arr = new double[M * N], *temp;
    temp = arr;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> *(arr++);
        }
        cout << endl;
    }
    arr = temp;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << *(arr++) << " ";
        }
        cout << endl;
    }
    arr = temp;
    free(arr);
}
// Question 3 Ends Here

int main()
{
    answer1();
    //answer2();
    //answer3();
    return 0;
}