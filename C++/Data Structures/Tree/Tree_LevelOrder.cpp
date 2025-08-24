

/*Inorder (left-root-right)
=========================

Preorder(root-left-right)
=========================

PostOrder(left-right-root)
===========================
Level order Traversal = Printing Level By Level
================================================*/
#include<iostream>
#include<queue>
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

void levelOrder(Node* root)
{
	if (root == nullptr)
		return;
	
	queue<Node*> q;

	q.push(root);

	while (q.empty() == false)
	{
		Node* cur = q.front();
		q.pop();

		cout << cur->key << " ";

		if (cur->left != nullptr)
			q.push(cur->left);

		if (cur->right != nullptr)
			q.push(cur->right);
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

	cout << "\n";
	
	levelOrder(root);
	return 0;
}