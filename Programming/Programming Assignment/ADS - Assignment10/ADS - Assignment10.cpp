// ADS Assignment 10
// Date : 6 / 12 / 2021

/* Q1

#include<iostream>
#include <list>
#include <map>

using namespace std;

class Graph {
public:
	map<int, bool> visited{};
	map<int, list<int> > adj{};

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

int main()
{
	Graph g;
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(3, 7);
	g.addEdge(4, 8);
	g.addEdge(5, 9);
	g.addEdge(7, 10);
	g.addEdge(7, 11);
	g.addEdge(8, 12);

	g.DFS(1);

	return 0;
}

/**/


/* Q2 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	int val{};
	Node* left{}, * right{};

	Node(int data)
	{
		this->val = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

string treeToStr(Node* node)
{
	if (node == nullptr) return "";

	if (node->left == nullptr && node->right == nullptr)
		return to_string(node->val);

	if (node->right == nullptr)
		return to_string(node->val) + "(" + treeToStr(node->left) + ")";

	return to_string(node->val) + "(" + treeToStr(node->left) + ")(" + treeToStr(node->right) + ")";
}

Node* createTree()
{
	Node* root{ nullptr };
	int data{ NULL };

	cout << "root node : ";
	cin >> data;

	if (data)
	{
		root = new Node(data);

		cout << "Enter left of " << data << " ";
		root->left = createTree();

		cout << "Enter right of " << data << " ";
		root->right = createTree();
	}

	return root;
}

int main()
{
	cout << "\n0 means no node\n\n";
	Node* root = createTree();

	string str = treeToStr(root);

	cout << endl << "String : " << str;

	return 0;
}

/**/
