#include<iostream>
#include<string>
#include <algorithm>
using namespace std;


void Q1()
{
    cout << "Enter the string : ";
	string str;
	getline(cin, str);
	int n = str.size();
	char freq[26][2];
	for (int i = 0; i < 26; i++) {
		freq[i][0] = (char)('a'+(char)i);
		freq[i][1] = '0';
	}
	for (int i = 0; i < n; i++)
		freq[str[i] - 'a'][1] += 1;
	cout << "[\n";
	for (int i = 0; i < n; i++) {
		if (freq[str[i] - 'a'][1] != '0' && str[i] != ' ') {
			cout <<"\t['" << str[i]<< "','" << freq[str[i] - 'a'][1] << "'],\n";
			freq[str[i] - 'a'][1] = '0';
		}
	}
	cout << "]\n";
}

void Q2()
{
    cout << "Enter the string : ";
	string s; string curr = ""; string ans = "";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) != ' ') {
			curr = curr + s.at(i);
		}
		else {

			sort(curr.begin(), curr.end());
			if(ans != "")
			ans = ans + " ";
			ans += curr;
			curr = "";

		}
	}
	if (curr != "") {
		sort(curr.begin(), curr.end());
		ans = ans + " " + curr;
	}
	cout << ans;
}


void Q3() {

    string str[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter string " << i+1 << " : ";
        getline(cin, str[i]);
    }
    int max = str[0].length();
    for (int i = 0; i < 5; i++) {
        if (str[i].length() > max)
            max = str[i].length();
    }
    for (int i = 0; i < 5; i++) {
        if (max == str[i].length()) {
            cout << str[i] << endl;
            cout <<"length: "<< max;
        }
    }
    cout << endl;
}

void Q4()
{
	const int page=3;
	const int row=3;
	const int col=3;
	int secret[page][row][col]=	{0};

	cout<<"Enter the secret 27 integers : "<<endl;
	for(int i=0;i<page;i++)
	{
		for(int j=0;j<row;j++)
		{
			for (int k=0;k<col;k++)
			{
				cin>>secret[i][j][k];
			}

		}
	}

	cout<<"Enter any 3 digit number : "<<endl;
	int num;
	cin>>num;

	int div=100;
	int arr[3]={0};
	int *ptrtoarr=arr;
	int index=0;
	while(num!=0)
	{
		arr[index]=num/div;
		int x=arr[index]*div;
		num=num-x;
		div=div/10;
		index++;
	}

	int count=1;
	index=0;
	string output="";
	for(int i=0;i<page;i++)
	{
		for(int j=0;j<row;j++)
		{
			for(int k=0;k<col;k++)
			{
				if(count==*(ptrtoarr+index))
				{
					output+=to_string(*(*(*(secret+i)+j)+k));
				}
				count++;
			}
		}
		count=1;
		index++;
	}
	cout<<"Output is : "<<output<<endl;
}

void Q5() {
    int numOfStr=5;
    int maxLen = 50;
	char model[numOfStr][maxLen];
	char view[numOfStr][maxLen];
	char(*modelPtr)[maxLen] = model;
	char(*viewPtr)[maxLen] = view;

	for (int i = 0; i < numOfStr; i++) {
		cout << "Enter string " << i + 1 << " : ";
		cin.getline(*(modelPtr + i), maxLen);
	}
	cout << endl;

	for (int i = 0; i < numOfStr; i++) {
		int len{ 0 }, l{ 0 };

		while (*(modelPtr[i] + l) != '\0') {
			len++;
			l++;
		}

		if (i % 2 == 0) {

			for (int j = 0; j < maxLen; j++) {
				if (j < len) {
					*(viewPtr[i] + j) = *(modelPtr[i] + j);
				}
				if(j >= len){
					*(viewPtr[i] + j) = ' ';
				}
			}
			*(viewPtr[i] + maxLen - 1) = '\0';
		}
		else {

			int k{maxLen-len-1};
			for (int j = 0; j <len; j++) {
				if (j < len) {
					*(viewPtr[i] + k) = *(modelPtr[i] + j);
				}
				k++;
			}
			k = 0;
			while (k < maxLen - len - 1) {
				*(viewPtr[i] + k) = ' ';
				k++;
			}
			*(viewPtr[i] + maxLen - 1) = '\0';
		}
	}


	for (int i = 0; i < numOfStr; i++) {
		for (int j = 0; j < maxLen; j++) {
			cout << *(viewPtr[i] + j);
		}
		cout << endl;
	}
}


int main()
{
	Q1();
//	Q2();
//	Q3();
//	Q4();
//	Q5();
	return 0;
}