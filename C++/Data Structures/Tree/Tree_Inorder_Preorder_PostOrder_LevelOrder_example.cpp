
/*	    		   	       10
				 20                    30
		  40           50         60         70
	  1       2     3      4   5      6   7      8

	==============================================
 Print the Binary Tree using inOrder, PreOrder, PostOrder */

 // In-Order - left-root-right
 // Pre-Order -root-left-right
 //Post-Order - left-right-root	
// levelOrder - Print level by level

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

		root->left->right = new Node(50);

		root->right->left = new Node(60);

		root->right->right = new Node(70);

		root->left->left->left = new Node(1);

		root->left->left->right = new Node(2);

		root->right->right->left = new Node(3);

		root->right->right->right = new Node(4);

		inOrder(root);
		cout << endl;
		preOrder(root);
		cout << endl;
		postOrder(root);
		
		cout << endl;
		levelOrder(root);

		cout << endl;

		return 0;
	}

