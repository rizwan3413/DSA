

/*In Order Traversal:
=========================
9 10 11 12 15 16 17 23 24 25 */

/*In Order Traversal After Inversing:
=====================================
25 24 23 17 16 15 12 11 10 9          */

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
	~BinarySearchTree() {}

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

	void preOrder(shared_ptr<Node> root)
	{
		if (root != nullptr)
		{
			cout << root->key << " ";
			inOrder(root->left);
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

	shared_ptr<Node> searchRecursive(shared_ptr<Node> temp, T data)
	{
		if (temp == nullptr || temp->key == data)
			return temp;

		if (data < temp->key)
			return searchRecursive(temp->left, data);
		else
			return searchRecursive(temp->right, data);

	}

	shared_ptr<Node> findParent(shared_ptr<Node> child)
	{
		shared_ptr<Node> ptr = root;

		if (ptr == nullptr || ptr == child)
			return nullptr;

		//cout << " Begin While loop" << endl;
		while (ptr != nullptr)
		{
			//cout << ptr->key << endl;

			if (ptr->left == child || ptr->right == child)
				return ptr;

			if(child->key < ptr->key)
				ptr = ptr->left;

			else
				ptr = ptr->right;

		}
	 
	}

	shared_ptr<Node> findMinimum(shared_ptr<Node> ptr)
	{
		while (ptr->left != nullptr)
		{
			ptr = ptr->left;
		}
		return ptr;
	}

	void deleteNode(T data)
	{
		if (root == nullptr)
			return;

		shared_ptr<Node> ptr = searchIterative(data);

		shared_ptr<Node> temp = root;

		
		if (ptr->left == nullptr && ptr->right == nullptr)
		{
			//cout << "Case 1" << endl;

			auto parent = findParent(ptr);

			//cout << " Parent is " << parent->key << endl;

			if (ptr == root)
				root = nullptr;
			else {
				if (parent->left == ptr)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			ptr.reset();
		}

		else if (ptr->left != nullptr && ptr->right != nullptr)
		{
			//cout << "Case 2" << endl;
			auto minimumNode = findMinimum(ptr->right);

			int var = minimumNode->key;

			deleteNode(minimumNode->key);

			ptr->key = var;
		}
		else
		{
			//cout << "Case 3" << endl;

			shared_ptr<Node> child = nullptr;
			
			auto parent = findParent(ptr);

			if (ptr->left == nullptr)
			{
				child = ptr->right;
			}
			
			if (ptr->right == nullptr)
			{
				child = ptr->left;
			}

			if (ptr == root)
			{
				root = child;
			}

			else {
				if (parent->left == ptr)
					parent->left = child;

				else
					parent->right = child;
			}
			ptr.reset();
		}
		
	}

	T findFloor(T data)
	{
		T var{};

		shared_ptr<Node> temp = root;

		if (temp == nullptr)
			return 0;
		

		while (temp != nullptr)
		{ 
			if (data == temp->key)
				return temp->key;

			else if (data < temp->key)
				temp = temp->left;
			else
			{
				var = temp->key;
				temp = temp->right;
			}
		}
		return var;
	}
	
	T findCeil(T data)
	{
		T var{};

		shared_ptr<Node> temp = root;

		if (temp == nullptr)
			return 0;


		while (temp != nullptr)
		{
			if (data == temp->key)
				return temp->key;

			else if (data > temp->key)
				temp = temp->right;
			else
			{
				var = temp->key;
				temp = temp->left;
			}
		}
		return var;
	}

	void invertBinaryTree(shared_ptr<Node> root)
	{
		if (root == nullptr) return;
		if (root->left != nullptr || root->right != nullptr) {
			shared_ptr<Node> temp = root->left;
			root->left = root->right;
			root->right = temp;
		}
		invertBinaryTree(root->left);
		invertBinaryTree(root->right);
	}
};

int main()
{
	BinarySearchTree<int> B1;

	auto ptr = B1.insertRecursive(nullptr, 15);
	ptr = B1.insertRecursive(ptr, 12);
	ptr = B1.insertRecursive(ptr, 10);
	ptr = B1.insertRecursive(ptr, 11);
	ptr = B1.insertRecursive(ptr, 9);
	ptr = B1.insertRecursive(ptr, 23);
	ptr = B1.insertRecursive(ptr, 17);
	ptr = B1.insertRecursive(ptr, 16);
	ptr = B1.insertRecursive(ptr, 24);
	ptr = B1.insertRecursive(ptr, 25);

	B1.setRoot(ptr);

	cout << "Before Inversion" << endl;

	B1.inOrder(B1.getRoot());

	cout << endl;

	cout << "After Inversion" << endl;

	B1.invertBinaryTree(B1.getRoot());

	B1.inOrder(B1.getRoot());

	return 0;
}