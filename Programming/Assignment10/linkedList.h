#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

template<typename t>
struct node
{
	t data{};
	node<t>* next{};
};

template<typename t>
node<t>* createNode(t data)
{
	auto n = new node<t>();
	n->data = data;
	n->next = nullptr;
	return n;
}


template<typename t>
node<t>* insertAtEnd(t data, node<t>* start)
{
	auto n = createNode(data);

	if (start != nullptr)
	{
		auto last = start;

		while (last->next != nullptr)
			last = last->next;

		last->next = n;
	}
	return n;
}


template<typename t>
void sortData(node<t>* start, std::function<void(node<t>*, node<t>*)> checkData)
{
	if (start == nullptr) return;

	else
	{
		while (start->next != nullptr)
		{
			auto templl = start->next;
			while (templl->next != nullptr)
			{
				checkData(start, templl);
				templl = templl->next;
			}
			start = start->next;
		}
	}
}