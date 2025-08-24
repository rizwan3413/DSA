#include<iostream>
#include<algorithm>
#include<queue>
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
		Node(T k) :key(k),left(nullptr),right(nullptr),ht(1) {}
	};
	//Left-Left-Case
	shared_ptr<Node> llCase(shared_ptr<Node> Z)
	{
		shared_ptr<Node> Y = Z->left;
		shared_ptr<Node> T3 = Y->right;
		Z->left = T3;
		Y->right = Z;
		Z->ht = max(height(Z->left), height(Z->right)) + 1;
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
	shared_ptr<Node> rlCase(shared_ptr<Node> Z)
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

	AVLTree():root(nullptr){}

	const shared_ptr<Node> getRoot()
	{
		return root;
	}

	void setRoot(shared_ptr<Node> root)
	{
		this->root = root;
	}

	shared_ptr<Node> insertRecursive(shared_ptr<Node> node, T data)
	{

		if (node == nullptr)
			return make_shared<Node>(data);

		if (data < node->key)
			node->left = insertRecursive(node->left, data);

		else if (data > node->key)
			node->right = insertRecursive(node->right, data);
		else
			return node;

		node->ht = 1 + max(height(node->left), height(node->right));

		int htDiff = height(node->left) - height(node->right);

		//cout << node->ht << " " << node->key << " " << htDiff << endl;

		if (htDiff > 1 && data < node->left->key)
		{
			//cout << "Executing llCase at : " << node->key << endl;
			return llCase(node);
		}

		if (htDiff > 1 && data > node->left->key)
		{
			//cout << "Executing lrCase at : " << node->key << endl;
			return lrCase(node);
		}

		if (htDiff < -1 && data > node->right->key)
		{

			//cout << "Executing rrCase at : " << node->key << endl;
			return rrCase(node);
		}

		if (htDiff < -1 && data < node->right->key)
		{
			//cout << "Executing rlCase at : " << node->key << endl;
			return rlCase(node);
		}
		return node;
	}

	void insert(T data)
	{
		root = insertRecursive(root, data);
	}
	void inOrder(shared_ptr<Node> root)
	{
		if (root != nullptr)
		{
			inOrder(root->left);
			cout << root->key <<" ";
			inOrder(root->right);
		}
	}

	void levelOrder()
	{
		queue<shared_ptr<Node>> q;

		auto cur = root;
		q.push(cur);

		while (q.empty() == false)
		{
			shared_ptr<Node> ptr = q.front();
			q.pop();

			cout << ptr->key << " ";

			if (ptr->left != nullptr)
				q.push(ptr->left);

			if (ptr->right != nullptr)
				q.push(ptr->right);
		}
	}

	int height(shared_ptr<Node> node)
	{
		if (node == nullptr)
			return 0;
		else
			return node->ht;
	}
   
};

int main()
{
	AVLTree<int> A1;

	A1.insert(13);
	A1.insert(10);
	A1.insert(11);

	//cout << (A1.getRoot())->key << endl;

	A1.insert(5);
	A1.insert(6);
	A1.insert(4);
	A1.insert(15);
	A1.insert(16);
	A1.insert(7);

	cout << (A1.getRoot())->key << endl; 
	/*RR Case or Left Rotation Case
	A1.insert(5);
	A1.insert(30);
	A1.insert(35);
	A1.insert(32);
	A1.insert(40);
	A1.insert(45);*/
	
/* LL Case or Right Rotation Case
	A1.insert(13);
	A1.insert(10);
	A1.insert(11);
	A1.insert(5);
	A1.insert(6);
	A1.insert(4);
	A1.insert(15);
	A1.insert(14);
	A1.insert(3);*/

	A1.inOrder(A1.getRoot());

	cout << endl;

	A1.levelOrder();
	return 0;

}