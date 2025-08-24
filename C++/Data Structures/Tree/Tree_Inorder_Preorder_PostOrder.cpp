

/*Inorder (left-root-right)
=========================

Preorder(root-left-right)
=========================

PostOrder(left-right-root)
===========================*/

#include<iostream>
using namespace std;

class Node
{
public:

	int key;
	Node* left;
	Node* right;

	Node(int k) :key(k), left(nullptr), right(nullptr) {}
};

void inOrder(Node* root)
{
	if (root != nullptr)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

void preOrder(Node* root)
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		inOrder(root->left);
		inOrder(root->right);
	}
}

void postOrder(Node* root)
{
	if (root != nullptr)
	{
		inOrder(root->left);
		inOrder(root->right);
		cout << root->key << " ";
	}
}


int main()
{
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	
	inOrder(root);

	cout << "\n";
	preOrder(root);

	cout << "\n";
	postOrder(root);

	return 0;
}