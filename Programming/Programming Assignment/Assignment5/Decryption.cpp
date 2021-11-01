// Assignment 5
// 202112114 : Sagar Variya
// Date : 9/10/2021
// Decryption

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    const int s{ (argc - 1) / 2 };
    float encryptMat[s][2];
    int count{ 1 };
    float x{ 0 };

    cout << "Encrypted matrix :" << endl;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            encryptMat[i][j] = atoi(argv[count++]);
            cout << encryptMat[i][j] << "\t";
        }
        cout << endl;
    }

    float keyi[2][2]{ {0.3,0.2}, {0.1,0.4} }, decryptMat[s][2]{};

    for (int a = 0; a < s; a++)
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                x = x + (encryptMat[a][j] * keyi[j][i]);
            }
            decryptMat[a][i] = x;
            x = 0.0;
        }

    cout << "\nAfter decryption :" << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << decryptMat[i][j] << "\t";
        cout << endl;
    }

    return 0;
}