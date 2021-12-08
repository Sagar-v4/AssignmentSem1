package Assignment10;

public class Q2 {
}

/*


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


 */