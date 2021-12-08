#include "pch.h"
#include "../../Assignment10/linkedList.h"

using namespace std;

struct GDP
{
	string countaryCode{}, name{}, gdpValue{};
	int rank{};
};

auto start = new node<GDP*>();

//sll<s1> *s1;
TEST(shouldCreateLinkedLIstWithSampleData1, shouldCreateList1)
{
	GDP s1{};
	s1.countaryCode = "IND";
	s1.rank = 10;
	s1.name = "India";
	s1.gdpValue = "2021120";
	auto start = createNode(s1);

	GDP s2{};
	s2.countaryCode = "USA";
	s2.rank = 1;
	s2.name = "United States";
	s2.gdpValue = "20,936,600";
	insertAtEnd(s2, start);

	EXPECT_EQ(start->data.countaryCode, "IND");
	EXPECT_EQ(start->next->data.name, "United States");
	EXPECT_EQ(start->next->next, nullptr);

}

//sll<s1*> *s1;
TEST(shouldCreateLinkedLIstWithSampleData2, shouldCreateList2)
{
	GDP* s1 = new GDP();
	s1->countaryCode = "IND";
	s1->rank = 10;
	s1->name = "India";
	s1->gdpValue = "2021120";
	start = createNode(s1);

	GDP* s2 = new GDP();
	s2->countaryCode = "USA";
	s2->rank = 1;
	s2->name = "United States";
	s2->gdpValue = "20,936,600";
	insertAtEnd(s2, start);

	EXPECT_EQ(start->data->countaryCode, "IND");
	EXPECT_EQ(start->next->data->name, "United States");
	EXPECT_EQ(start->next->next, nullptr);

}
