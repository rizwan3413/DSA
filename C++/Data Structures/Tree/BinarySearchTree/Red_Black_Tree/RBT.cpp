#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/* RB Tree*/

template<typename T>
class RBTree
{
	class Node
	{
	public:
		T key;
		shared_ptr<Node> left;
		shared_ptr<Node> right;
		shared_ptr<Node> parent;
		enum Color
		{
			RED,
			BLACK
		}color;

		Node(T k) :key(k), left(nullptr), right(nullptr),parent(nullptr),color(RED){}
	};
	//Left-Left-Case
	shared_ptr<Node> llCase(shared_ptr<Node> GP)
	{
		shared_ptr P = GP->left;
		shared_ptr T2 = P->left;
		GP->left = P->right;
		P->right = GP;
		P->color = Node::Color::BLACK;
		GP->color = Node::Color::RED;
		return P;
	}
	//Left-Right-Case
	shared_ptr<Node> lrCase(shared_ptr<Node> GP)
	{
		shared_ptr<Node> P = GP->left;
		shared_ptr<Node> T2 = P->right
		P->right = T2->left;
		T2->left = P;
		GP->left = T2;
		GP->left = T2->right;
		T2->right = GP;

		T2->color = Node::Color::BLACK;
		GP->color = Node::Color::RED

		return T2;
	}

	//Right-Left-Case
	shared_ptr<Node> rlCase(shared_ptr<Node> Z)
	{
		shared_ptr<Node> P = GP->right;
		shared_ptr<Node> T2 = P->left;
		P->left = T2->right;
		T2->right = P;
		GP->right = T2;

		GP->right = T2->left;
		T2->left = GP;

		T2->color = Node::Color::BLACK;
		GP->color = Node::Color::RED;
		return T2;
	}

	//Right-Right-Case
	shared_ptr<Node> rrCase(shared_ptr<Node> GP)
	{
		shared_ptr<Node> P = GP->right;
		shared_ptr<Node> T2 = P->left;
		GP->right = P->left;
		P->right = T2;
		P->color = Node::Color::BLACK;
		GP->color = Node::Color::RED;
		return P;
	}


public:
	shared_ptr<Node> root;

	AVLTree() :root(nullptr) {}

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

		
		//cout << node->ht << " " << node->key << " " << htDiff << endl;

		if (node->color == Node::Color::RED && parent->color )
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
			cout << root->key << " ";
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
	RBTTree<int> A1;

	A1.insert(13);
	A1.insert(10);
	A1.insert(11);


	A1.insert(5);
	A1.insert(6);
	A1.insert(4);
	A1.insert(15);
	A1.insert(16);
	A1.insert(7);

	cout << (A1.getRoot())->key << endl;
	A1.inOrder(A1.getRoot());

	cout << endl;

	A1.levelOrder();
	return 0;

}