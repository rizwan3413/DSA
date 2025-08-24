

/*In Order Traversal:
=========================
9 10 11 12 15 16 17 18*/

#include<iostream>
#include<memory>
#include<utility>
using namespace std;

template<typename T>
class BinarySearchTree
{
	class Node
	{
	public:
		T key;
		shared_ptr<Node> left;
		shared_ptr<Node> right;
		
		Node(T k) :key(k), left(nullptr), right(nullptr) {}
	};

	shared_ptr<Node> root;

public:
	BinarySearchTree() :root(nullptr) {}
	~BinarySearchTree(){}

	void insertIterative(T data)
	{
		shared_ptr<Node> cur = make_shared<Node>(data);

		if (root == nullptr)
		{
			root = cur;
			return;
		}

		shared_ptr<Node> temp = root;

		shared_ptr<Node> ptr = nullptr;

		while (temp != nullptr) //Iterative approach
		{
			ptr = temp;

			if (data < temp->key)
				temp = temp->left;
			else 
				temp = temp->right;
		}

		if (ptr->key > data)
			ptr->left = cur;
		else
			ptr->right = cur;

		//cout << "Inserted " << data << endl;
	}

	shared_ptr<Node> insertRecursive(shared_ptr<Node> root,T data)
	{	//Recursive approach
			
		if (root == nullptr)
			return make_shared<Node>(data);

		if (data < root->key)
			 root->left = insertRecursive(root->left, data);
		else
			root->right = insertRecursive(root->right, data);
		
		return root;
	}

	shared_ptr<Node> getRoot()
	{
		return root;
	}

	void setRoot(shared_ptr<Node> root)
	{
		this->root = root;
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

	shared_ptr<Node> searchIterative(T data)
	{

		shared_ptr<Node> temp = root;

		while (temp != nullptr)
		{
			if (temp->key == data)
				return temp;

			if (data < temp->key)
			{
				temp = temp->left;
			}

			else
				temp = temp->right;
		}

		return nullptr;
	}

	shared_ptr<Node> searchRecursive(shared_ptr<Node> temp,T data)
	{
		if (temp == nullptr ||temp->key == data )
			return temp;
		
		if (data < temp->key)
			return searchRecursive(temp->left, data);
		else
			return searchRecursive(temp->right, data);

	}
		/*
		if (data < root->key)
		{
			return search(root->left->key);
		}

		else
			return search(root->right->key);*/
};

int main()
{
	BinarySearchTree<int> B1;

	auto ptr = B1.insertRecursive(nullptr,15);
	ptr = B1.insertRecursive(ptr,12);
	ptr = B1.insertRecursive(ptr,10);
	ptr = B1.insertRecursive(ptr,11);
	ptr = B1.insertRecursive(ptr,9);
	ptr = B1.insertRecursive(ptr,16);
	ptr = B1.insertRecursive(ptr,17);
	ptr = B1.insertRecursive(ptr,18);

	B1.setRoot(ptr);

	B1.inOrder(B1.getRoot());

	cout << endl;

	auto ptr1 = B1.getRoot();

	if (B1.searchRecursive(ptr1,20)== nullptr)
		cout << "Element is not present" << endl;

	auto ptr2 = B1.searchRecursive(ptr1,18);

	cout << "Searched Element is " << ptr2->key << endl;

	return 0;
}