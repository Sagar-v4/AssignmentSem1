
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <array>

using namespace std;

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

//int main() {
//    Q1();
//    Q2();
//    Q3();
//    Q4();
//    Q5();
//    return 0;
//}

void Q1() {
    double arr[5];
    double num = 1.1;
    for (int i = 0; i < 5; i++) {
        arr[i] = num;
        num += 0.1;
    }
    for (int i = 4; i >= 0; i--) {
        cout << arr[i] << "\t";
    }
}

void Q2() {
    //a
    {
        char chArrayA[30], chArrayB[30];
        char fname[30], lname[30];
        cout << "\nEnter FirstName: ";
        cin >> fname;
        cout << "\nEnter LastName: ";
        cin >> lname;
        strcpy(chArrayA, fname);
        strcpy(chArrayB, lname);
        cout << "\nQuestion 2(a): ";
        cout << chArrayA << " " << chArrayB;
        cout << endl;
    }
    //b
    {
        char chArrayA[30], chArrayB[30];
        char fname[30], lname[30];
        cout << "\nEnter FirstName: ";
        cin >> fname;
        cout << "\nEnter LastName: ";
        cin >> lname;
        strcpy(chArrayA, fname);
        strcpy(chArrayB, lname);
        strcat(chArrayA, " ");
        strcat(chArrayA, chArrayB);
        cout << "\nQuestion 2(b): " << chArrayA;
        cout << endl;
    }
    //c
    {
        char chArrayA[30];
        int flag = 0;
        cout << "\nEnter Name: ";
        cin.ignore();
        cin.getline(chArrayA, 30);
        for (int i = 1; chArrayA[i] != '\0'; i++) {
            if (chArrayA[i] == ' ') {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            cout << "\nQuestion 2(c): mutli word string  " << chArrayA;
        }
        else {
            cout << "\nQuestion 2(c): not multi word string";
        }
    }
    //d
    {
        char chArrayA[30], chArrayB[30];
        int flag = 0;
        cout << "\nEnter String : ";
        cin.getline(chArrayA, 30);
        int len = strlen(chArrayA);
        for (int i = 0, j = len - 1; i < len; i++, j--) {
            chArrayB[i] = chArrayA[j];
        }
        cout << "\nQuestion 2(d): Reverse String: " << chArrayB;
    }
    //e
    {
        char chArrayA[30], chArrayB[30];
        cout << "\nEnter String : ";
        cin.getline(chArrayA, 30);
        int len = strlen(chArrayA);
        int k = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (isspace(chArrayA[i])) {
                int j = i + 1;
                while (j < len && !isspace(chArrayA[j])) {
                    chArrayB[k++] = chArrayA[j++];
                }
                chArrayB[k++] = ' ';
            }
        }
        for (int i = 0; !isspace(chArrayA[i]); i++) {
            chArrayB[k++] = chArrayA[i];
        }
        cout << "Question 2 (e) : reverse words : " << chArrayB;
    }
    //f
    {
        char chArrayA[30], chArrayB[30];
        cout << "\nEnter String : ";
        cin.getline(chArrayA, 30);
        int len = strlen(chArrayA);
        int k = 0;
        for (int i = 0; i < len; i++) {
            if (isalpha(chArrayA[i])) {
                chArrayB[k++] = chArrayA[i];
            }
        }
        cout << "Question 2 (f) : " << chArrayB;
    }
}

void Q3() {
    char tickets[16][20];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 20; j++) {
            tickets[i][j] = '*';
        }
    }
    char ch;
    do {
        cout << "\n1. Buy a ticket. \n2. Cancel ticket. \n3. Exit the app.\n";
        int choice;
        cout << "Enter choice:";
        cin >> choice;
        switch (choice) {
        case 1: {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 20; j++) {
                    cout << tickets[i][j] << " ";
                }
                char letter = 65 + i;
                cout << "---> " << letter;
                cout << endl;
            }

            for (int i = 0; i < 20; i++) {
                cout << "VV";
            }
            cout << "Screen This Way..";

            cout << "\n * => Available Seat.\n X => Occupied Seat.\n";
            int row, col;
            char ch;
            cout << "\nEnter Row (A-P): ";
            cin >> ch;
            cout << "\nEnter Column (1-20): ";
            cin >> col;
            col--;
            row = ch - 65;
            if ((row >= 0 && row <= 15) && (col >= 1 && col <= 20)) {
                if (tickets[row][col] == '*') {
                    tickets[row][col] = 'X';
                    cout << "\nTicket Booked";
                }
                else {
                    cout << "Already booked.";
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 20; j++) {
                    cout << tickets[i][j] << " ";
                }
                char letter = 65 + i;
                cout << "---> " << letter;
                cout << endl;
            }

            for (int i = 0; i < 20; i++) {
                cout << "VV";
            }
            cout << "Screen This Way..";

            cout << "\n * => Available Seat.\n X => Occupied Seat.\n";
            int row, col;
            char ch;
            cout << "\nEnter Row (A-P): ";
            cin >> ch;
            cout << "\nEnter Column (1-20): ";
            cin >> col;
            col--;
            row = ch - 65;
            if ((row >= 0 && row <= 15) && (col >= 1 && col <= 20)) {
                if (tickets[row][col] == 'X') {
                    tickets[row][col] = '*';
                    cout << "\nTicket Cancelled.";
                }
                else {
                    cout << "Ticket isn't booked yet.";
                }
            }
            cout << endl;
            break;
        }

        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
        cout << "\nDo you want to continue[y/n]: ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}


void Q4() {
    int orders[100];
    int num = 100;
    int i = 0;
    char ch;
    do {
        int choice;
        cout << "\n1. Place order\n2. Pending orders\n3. Serve order\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            orders[i] = num++;
            cout << "\nYour order is placed. Order Number: " << orders[i++];
            break;
        }
        case 2: {
            cout << "\nPending Orders: \n";
            for (int j = 0; j < i; j++) {
                cout << orders[j] << " ";
            }
            break;
        }
        case 3: {
            int index = -1, order = 0;
            cout << "\nEnter Order no: ";
            cin >> order;
            for (int j = 0; j < i; j++) {
                if (orders[j] == order) {
                    index = j;
                }
            }
            if (index == -1) {
                cout << "\nEnter right order.";
            }
            else {
                for (int j = index; j < i - 1; j++) {
                    orders[j] = orders[j + 1];
                    i--;
                }
                for (int j = 0; j < i; j++) {
                    cout << orders[j] << " ";
                }
            }
            break;
        }
        default:
            cout << "\nInvalid Choice.";
        }
        cout << "\n Do you want to continue[y/n]: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void Q5() {
    int const max = 11;
    char decor[max][max]{};
    for (int i = 0; i <= max / 2; i++) {
        char ch;
        if (i % 2 == 0) {
            ch = '-';
        }
        else {
            ch = '*';
        }
        for (int j = i; j < max - i; j++) {
            decor[i][j] = ch;
            decor[j][i] = ch;
            decor[j][max - i - 1] = ch;
            decor[max - i - 1][j] = ch;
        }
    }
    cout << endl;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            cout << decor[i][j] << " ";
        }
        cout << endl;
    }