

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

	B1.inOrder(B1.getRoot());

	cout << endl;

	auto ptr1 = B1.getRoot();

	if (B1.searchRecursive(ptr1, 20) == nullptr)
		cout << "Element is not present" << endl;

	auto ptr2 = B1.searchRecursive(ptr1, 24);

	cout << "Searched Element is " << ptr2->key << endl;

	//auto ptr3 = B1.inOrderSuccesor(24);

//	if (ptr3 == nullptr)
	//	cout << "No InOrder Successor found" << endl;
	//else
	//	cout << "InOrder Successor found is : " << ptr3->key << endl;

	auto fP = B1.findParent(B1.searchIterative(11));

	cout << "Parent of the Node is " << fP->key << endl;

	B1.deleteNode(10);
	
	B1.inOrder(B1.getRoot());

	cout << endl;

	cout << " Floor of 30 is " << B1.findFloor(30) << endl;

	cout << " Floor of 15 is " << B1.findFloor(15) << endl;
	cout << " Floor of 10 is " << B1.findFloor(10) << endl;
	cout << " Floor of 13 is " << B1.findFloor(13) << endl;
	cout << " Floor of 14 is " << B1.findFloor(14) << endl;
	cout << " Floor of 26 is " << B1.findFloor(26) << endl;
	cout << " Floor of 18 is " << B1.findFloor(18) << endl;

	cout << " Ceil of 30 is " << B1.findCeil(30) << endl;

	cout << " Ceil of 15 is " << B1.findCeil(15) << endl;
	cout << " Ceil of 10 is " << B1.findCeil(10) << endl;
	cout << " Ceil of 13 is " << B1.findCeil(13) << endl;
	cout << " Ceil of 14 is " << B1.findCeil(14) << endl;
	cout << " Ceil of 26 is " << B1.findCeil(26) << endl;
	cout << " Ceil of 18 is " << B1.findCeil(18) << endl;
	return 0;
}