package Assignment9;

public class Q2 {
}


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
