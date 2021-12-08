
// Assignment 10
// 202112114 | Sagar Variya
// Date : 1/12/2021

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "linkedList.h"

using namespace std;

struct GDP
{
	string countaryCode{}, name{}, gdpValue{};
	int rank{};
};

void displayLL(node<GDP*>* start)
{
	while (start->next != nullptr)
	{
		cout << start->data->countaryCode << setw(7);
		cout << start->data->rank << setw(25);
		cout << start->data->name << setw(15);
		cout << start->data->gdpValue << endl;
		start = start->next;
	}
}

void checkData(node<GDP*>* newll, node<GDP*>* templl)
{
	if (strcmp(newll->data->name.c_str(), templl->data->name.c_str()) > 0)
	{
		auto temp = newll->data;
		newll->data = templl->data;
		templl->data = temp;
	}
}


int main()
{
	ifstream f("../Assignment10/GDP.txt");
	GDP* c = new GDP[100];
	if (!f.is_open()) cout << "File Doesn't exits" << endl;

	else
	{
		int j{ 0 };
		string str{};

		while (f.good())
		{
			getline(f, str);
			stringstream ss(str);
			int i{ 0 };
			string data{};
			while (ss >> data)
			{
				if (i == 0) c[j].countaryCode = data;

				else if (i == 1) c[j].rank = stoi(data);

				else if (i == 2) c[j].name = data;

				else if (i == 3) c[j].gdpValue = data;

				i++;
			}
			j++;
		}
	}

	auto start = createNode(&c[0]);

	for (int i = 1; i < 100; i++)
		insertAtEnd(&c[i], start);

	cout << "Before Sorting : \n\n";

	displayLL(start);

	function<void(node<GDP*>*, node<GDP*>*)> fp = checkData;

	sortData(start, fp);

	cout << "\nAfter Sorting : \n\n";

	displayLL(start);

	f.close();
}
