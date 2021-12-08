package Assignment9;

public class Q3 {
}

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