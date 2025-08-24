

/*Check for Height Balanced Tree
 ================================                    Max Height = 3
            20                                       H_L = 3, H_R = 2 = Diff =(H_L - H_R) = 1    level 1
	   10       15                            LST    H_L = 2, H_R = 1 = Diff =(H_L - H_R) = 1    level 2
    4     5        4                          RST    H_L = 0, H_R = 1 = Diff =(H_L - H_R) = 1    level 2
 3                                            LLST   H_L = 1, H_R = 0 = Diff =(H_L - H_R) = 1    level 3

*/

#include<iostream>
#include<memory>
using namespace std;

class Node
{
public:
	int key;
	shared_ptr<Node> left;
	shared_ptr<Node> right;

	Node(int k) :key(k), left(nullptr), right(nullptr) {}
};

void preOrder(shared_ptr<Node> root)
{
	if (root == nullptr) return;

	if (root != nullptr)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int height(shared_ptr<Node> root)
{
	if (root == nullptr)
		return 0;
	else
		return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(shared_ptr<Node> root)
{
	if (root == nullptr) return true;
	
	int lh = height(root->left);

	int rh = height(root->right);

	return ((abs(lh - rh) <= 1) && isBalanced(root->left) && isBalanced(root->right));
	
}

int main()
{
	shared_ptr<Node> root = make_shared<Node>(20);

	root->left = make_shared<Node>(10);
	root->right = make_shared<Node>(15);
	root->left->left = make_shared<Node>(4);
	root->left->right = make_shared<Node>(5);
	root->left->left->left = make_shared<Node>(3);
	root->right->right = make_shared<Node>(4);

	preOrder(root);
    
    cout << endl;
    
	isBalanced(root)?(cout<<"It is Height Balanced Tree" ) : (cout<<"It is not Height Balanced Tree");
	return 0;
}