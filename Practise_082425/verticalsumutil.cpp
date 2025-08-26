// C++ program to find Vertical Sum in
// a given Binary Tree

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
	Node(int x){
     	data = x;
      	left = right = nullptr;
    }
};

// Traverses the tree in in-order form and
// populates a hashMap that contains the
// vertical sum
void verticalSumUtil(Node *node, int hd, map<int, int> &mp) {
  
    // Base case
    if (node == nullptr) return;

    // Recur for left subtree
    verticalSumUtil(node->left, hd-1, mp);

    // Add val of current node to
    // map entry of corresponding hd
    mp[hd] += node->data;

    // Recur for right subtree
    verticalSumUtil(node->right, hd+1, mp);
}

// Function to find vertical sum
vector<int> verticalSum(Node *root) {
  
    // a map to store sum of nodes for each 
    // horizontal distance
    map <int, int> mp;

    // populate the map
    verticalSumUtil(root, 0, mp);
	
  	vector<int> result;
    // Prints the values stored by VerticalSumUtil()
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      	result.push_back(it->second);
    }
  	return result;
}

int main() {
  
    // Create binary tree as shown in above figure
  	//        1
  	//      /  \  
  	//     2    3
  	//    / \  / \
  	//   4   5 6  7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = verticalSum(root);
	for(int i : res) {
      	cout << i << " ";
    }
    return 0;
}
