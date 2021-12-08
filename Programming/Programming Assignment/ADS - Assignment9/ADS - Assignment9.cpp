// ADS Assignment 9
// Date : 29 / 11 / 2021

/* Q1

#include<iostream>
#include <list>

using namespace std;

class Graph
{
	int V{};
	list<int>* adj{};
public:
	Graph(int V);

	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue{};

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	Graph g(13);
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

	g.BFS(1);

	return 0;
}

*/


/* Q2

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int val{};
	Node* left{}, * right{};

	Node(int data)
	{
		this->val = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void helper(vector<int>& res, Node* root, int d)
{
	if (!root) return;

	if (d == res.size()) res.push_back(root->val);
	else res[d] = max(res[d], root->val);

	helper(res, root->left, d + 1);
	helper(res, root->right, d + 1);
}

vector<int> largestValues(Node* root)
{
	vector<int> res{};
	helper(res, root, 0);
	return res;
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

	cout << "\n";
	vector<int> res = largestValues(root);
	for (int i = 0; i < res.size(); i++)
		cout << res.at(i) << " ";

	return 0;
}

*/


/* Q3

#include <iostream>
using namespace std;

struct Node
{
	int data{};
	Node* left{}, * right{}, * next{};

	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
		this->next = nullptr;
	}
};

Node* getNextRight(Node* p)
{
	Node* temp = p->next;

	while (temp != nullptr)
	{
		if (temp->left != nullptr)
			return temp->left;
		if (temp->right != nullptr)
			return temp->right;
		temp = temp->next;
	}

	return nullptr;
}

void connectAndPrint(Node* p)
{
	Node* temp{ nullptr };

	if (!p) return;

	while (p != NULL)
	{
		Node* q = p;

		while (q != NULL)
		{
			cout << q->data << " ";
			if (!q->next) cout << "null ";

			if (q->left) 
				q->left->next = (q->right) ? q->right : getNextRight(q);

			if (q->right) q->right->next = getNextRight(q);

			q = q->next;
		}

		if (p->left) p = p->left;
		else if (p->right) p = p->right;
		else p = getNextRight(p);
	}
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

	cout << "\n";
	connectAndPrint(root);

	return 0;
}

*/