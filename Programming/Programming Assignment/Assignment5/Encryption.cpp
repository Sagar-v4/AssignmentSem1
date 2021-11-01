// Assignment 5
// 202112114 : Sagar Variya
// Date : 9/10/2021
// Encryption

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    string txt{};

    for (int i = 1; i < argc; i++)
    {
        txt = txt + argv[i];
        if (i < (argc - 1))
            txt += " ";
    }

    const int t{ txt.size() / 2 };
    int mat1[t][2];
    int asc{ 0 }, count{ 0 };
    float x{ 0 };

    for (int i = 0; i < txt.size(); i++) { txt[i] = tolower(txt[i]); }

    cout << "Puted numeric value in the matrix :" << endl;
    for (int i = 0; i < txt.size() / 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (txt[count] == ' ' || txt[count] == '_')
                mat1[i][j] = 0;
            else 
            {
                asc = (int)txt[count];
                mat1[i][j] = asc - 96;
            }
            count++;
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    float key[2][2]{ {4,-2},{-1,3} }, encryptMat[txt.size() / 2][2]{};

    for (int a = 0; a < txt.size() / 2; a++)
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                x = x + mat1[a][j] * key[j][i];
            }
            encryptMat[a][i] = x;
            x = 0;
        }

    cout << "\nAfter encryption :" << endl;
    for (int i = 0; i < txt.size() / 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << encryptMat[i][j] << "\t";
        cout << endl;
    }

    return 0;
}