#include<iostream>
using namespace std;

/* AVL Tree*/

template<typename T>
class AVLTree
{
	class Node
	{
	public:
		T key;

		shared_ptr<Node> left;
		shared_ptr<Node> right;
		int ht;
		Node(T k) :key(k),left(nullptr),right(nullptr),ht(0) {}
	};
	//Left-Left-Case
	shared_ptr<Node> llCase(shared_ptr<Node> node)
	{
		shared_ptr<Node> Y = node->left;
		shared_ptr<Node> T3 = Y->right;
		node->left = T3;
		Y->right = node;
		node->ht = max(height(node->left), height(node->right)) + 1;
		Y->ht = max(height(Y->left), height(Y->right)) + 1;

		return Y;
	}
	//Left-Right-Case
	shared_ptr<Node> lrCase(shared_ptr<Node> Z)
	{
		shared_ptr<Node> X = rrCase(Z->left);
		Z->left = X;

		return llCase(Z);
	}

	//Right-Left-Case
	shared_ptr<Node> rlCase(shared_ptr<Node> node)
	{
		shared_ptr<Node> X = llCase(Z->right);
		Z->right = X;

		return rrCase(Z);
	}
	//Right-Right-Case
	shared_ptr<Node> rrCase(shared_ptr<Node> Z)
	{
		shared_ptr<Node> Y = Z->right;
		shared_ptr<Node> T2 = Y->left;
		Z->right = T2;
		Y->left = Z;
		Z->ht = max(height(Z->left), height(Z->right)) + 1;
		Y->ht = max(height(Y->left), height(Y->right)) + 1;
		return Y;
	}
	

public:
	shared_ptr<Node> root;

	AVLtree() :root(nullptr) {}

	const shared_ptr<Node> getRoot()
	{
		return root;
	}

	shared_ptr<Node> insertRecursive(shared_ptr<Node> root, T data)
	{	//Recursive approach

		if (root == nullptr)
			return make_shared<Node>(data);

		if (data < root->key)
			root->left = insertRecursive(root->left, data);
		else
			root->right = insertRecursive(root->right, data);

		return root;
	}

	void inOrder(shared_ptr<Node> root)
	{
		if (root != nullptr)
		{
			inOrder(root->left);
			cout << root->key << " ";
			inOrder(root->right);
		}
	}

	int height(shared_ptr<Node> node)
	{
		if (node == nullptr)
			return 0;
		else
			return 1 + max(height(node->left), height(node->right));
	}
   
};

int main()
{
	return 0;

}