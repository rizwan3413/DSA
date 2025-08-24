#include<iostream>
using namespace std;

class Node;

Node* pre = nullptr;
//Convert a Tree in to a Doubly Linked List which in a inOrder Node* prev = nullptr; way

    /*        20
      10             15
 4        1     5         3


  InOrder Traversal Way - 4 10 1 20 5 15 3

*/

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
    if (root !=nullptr)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}


/*        20
    10             15
4        1     5         3
*/

Node* binToDLL(Node* root)
{
    if (root == nullptr)
        return root;

    Node* head = binToDLL(root->left);

    if (pre == nullptr)
        head = root;

    else
    {
        root->left = pre;
        pre->right = root;
    }
    pre = root;

    binToDLL(root->right);

    return head;
}

void printList(Node* root)
{
    Node* curr = root;

    while (curr != nullptr)
    {
        cout << curr->key << " ";

        curr = curr->right;
    }
}


int main()
{
    Node* root = new Node(20);
    root->left = new Node(10);
    root->left->left = new Node(4);
    root->left->right = new Node(1);
    root->right = new Node(15);
    root->right->left = new Node(5);
    root->right->right = new Node(3);

    inOrder(root);
    Node* head = binToDLL(root);

    cout << endl;

    printList(head);

    return 0;
}