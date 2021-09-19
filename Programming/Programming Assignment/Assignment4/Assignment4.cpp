// Assignment 4
// 202112114 : Sagar Variya
// Date : 18/9/2021

#include <iostream>
#include <array>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

void Q1() {

    const int N{ 5 };
    double arr[N]{};

    for (int i = 0; i < N; i++)
    {
        cout << "Enter Element No." << (i + 1) << " : ";
        cin >> arr[i];
    }

    reverse(arr, arr + N);

    cout << endl << "After Reversing : ";

    for (double x : arr ) cout << x << " ";

}

void Q2() {
    
    char arrA[100]{};
    char arrB[100]{};


    // A)
    cout << endl << "A)\n";

    char fname[100]{};
    char lname[10]{};

    cout << "Enter First Name : ";
    cin >> fname;
    strcpy_s(arrA, fname);

    cout << "Enter Last Name : ";
    cin >> lname;
    strcpy_s(arrB, lname);

    cout << "Result : " << endl;
    cout << "Fname : " << fname << endl << "Lname : " << lname << endl;


    // B)
    cout << endl << "B)\n";

    strcat_s(arrA, " ");
    strcat_s(arrA, arrB);

    cout << "Result from (A) : " << arrA << endl;


    // C)
    cout << endl << "C)\n";

    char word[100]{};
    cout << "Enter Multi word String : ";
    cin.ignore();
    cin.getline(word, 100);

    cout << "Result : " << word << endl;


    // D)
    cout << endl << "D)\n";

    strcpy_s(arrB, _strrev(arrA));
    cout << "Reverse of (B) : " << arrB << endl;


    // E)
    cout << endl << "E)\n";

    char temp[100]{};
    memset(arrA, 0, 100);

    for (int i = 0, j = 0; i <= strlen(arrB) ; i++) {
        if (!isalpha(arrB[i])) {

            strcat_s(arrA, _strrev(temp));
            strcat_s(arrA, " ");
            memset(temp, 0, 100);
            j = 0;

        }
        temp[j++] = arrB[i];
    }
    cout << "Reverse by Words of (D) : " << arrA << endl;


    // F)
    cout << endl << "F)\n";

    int i{ 0 };
    for (char c : word)
        if (isalpha(c)) temp[i++] = c;

    cout << "Only Alphabets of (C) : " << temp << endl;

}

void Q3() {

    int choice{};
    char seats[16][20]{};

    for (auto& rows : seats)
        for (auto& seat : rows)
            seat = '*';

    do {

        int col{ 1 };
        char row{ 65 };

        for (int i = -1; i < 17; i++) {
            if (i >= 0 && i < 16) cout << endl << " " << row++ << " | ";
            else cout << endl << "   | ";
            for (int j = 0; j < 20; j++) {
                if (i == -1) cout << setw(3) << col++;
                else if (i == 16) cout << ((j == 0) ? "  v" : "vvv");
                else cout << setw(3) << seats[i][j];
            }
        }

        cout << endl << endl << "Cinema Ticket Booking" << endl << endl;
        cout << "1. Buy Ticket" << endl;
        cout << "2. Cancel Ticket" << endl;
        cout << "3. Exit" << endl;
        cout << endl << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: {

            cout << endl << "Enter Row Column No. Book Seat [eg. A15] : ";
            cin >> row >> col;

            if ((row < 65 || row > 80) || (col < 1 || col > 20)) {
                cout << endl << "Invalid Seat number..." << endl;
            } else {
                row -= 65;
                col -= 1;
                if (seats[row][col] == 'X')
                    cout << endl << "Seat Already Booked... " << endl;
                else {
                    seats[row][col] = 'X';
                    cout << endl << "Seat Booked : " << char(row += 65) << " - " << (col += 1) << endl;
                }
            }

            break;
        }

        case 2: {

            cout << endl << "Enter Row Column No. Cancel Seat [eg. A15] : ";
            cin >> row >> col;

            if ((row < 65 || row > 80) || (col < 1 || col > 20)) {
                cout << endl << "Invalid Seat number..." << endl;
            }
            else {
                row -= 65;
                col -= 1;
                if (seats[row][col] == '*')
                    cout << endl << "Seat Not Booked yet... " << endl;
                else {
                    seats[row][col] = '*';
                    cout << endl << "Seat Cancelled : " << char(row += 65) << " - " << (col += 1) << endl;
                }
            }
            break;
        }

        case 3:
            exit(0);

        default:
            cout << endl << "Invalid Choice...";
            break;
        }

        cout << endl << "Do You Want To Continue? [1 for yes] : ";
    } while (cin >> choice && choice == 1);
}

void Q4() {

    int choice{ 0 }, totalOrders{ 0 }, placeOrder{ 0 };
    int orders[100]{ 0 };

    do {
        cout << "\nOrder Handling Software" << endl << endl;
        cout << "1. Place order" << endl;
        cout << "2. Pending orders" << endl;
        cout << "3. Serve order" << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: {
            orders[totalOrders] = placeOrder +++ 101;
            cout << endl << "Your order is placed. Order Number: " << orders[totalOrders++] << endl;
            break; 
        }

        case 2: {
            cout << endl << "Total Pending Orders : " << totalOrders << endl;
            for (int i = 0; i < totalOrders; i++) cout << orders[i] << endl;
            break;
        }

        case 3: {
            cout << endl << "List Of Pending Orders : " << endl;
            for (int i = 0; i < totalOrders; i++) cout << orders[i] << endl;

            int serve{ 0 };
            bool found{ false };

            cout << endl << "Pick Order No. to Serve : ";
            cin >> serve;

            for (int i = 0; i < totalOrders; i++) {
                if (orders[i] == serve || found) {
                    orders[i] = orders[i + 1];
                    found = true;
                }
            }

            if (found) {
                totalOrders--;
                cout << endl << "Order No." << serve << " Served." << endl;
            }
            else cout << endl << "Order No." << serve << " Not Found." << endl;
            break;
        }

        case 4:
            exit(0);

        default:
            cout << endl << "Invalid Choice...";
            break;
        }

        cout << endl << "Do You Want To Continue? [1 for yes] : ";
    } while ( cin >> choice && choice == 1 );

}

void Q5() {

    int N{};
    char decor[100][100]{};

    cout << "Enter Size of Row/Col : ";
    cin >> N;

    char x = 'x';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            decor[i][j] = x;
        }
    }

    for (int i = 0; i <= N / 2; i++) {

        if (i % 2 == 0) x = '-';

        else x = '*';

        for (int j = i; j <= N / 2; j++) {
            if (decor[i][j] == 'x') {
                decor[i][j] = x;

                decor[N - 1 - i][j] = x;
                decor[i][N - 1 - j] = x;
                decor[N - 1 - i][N - 1 - j] = x;
            }
            if (decor[j][i] == 'x') {
                decor[j][i] = x;

                decor[N - 1 - j][i] = x;
                decor[j][N - 1 - i] = x;
                decor[N - 1 - j][N - 1 - i] = x;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << decor[i][j] << " ";
        }
        cout << endl;
    }
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
		Q5();

		cout << endl << "Do you want to run this question again [1 for yes] : ";
	} while (cin >> loop && cin.ignore() && cout << "-----" << endl);
}
