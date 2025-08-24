
// Node has two pointers which can point to random memory like binary tree, Copy the contents of node to another node :
//=====================================================================================================================

#include<iostream>
using namespace std;

class BinaryTree
{
    public:
    
    class Node 
    {
        public:
        
        int data;
        
        Node *left;
        Node *right;
        
        Node(int data1):data(data1),left(nullptr),right(nullptr){}
    };
    
    Node *root;
    
    BinaryTree():root(nullptr){}

    //in-order //pre-order //post order
   //In order method
    void printTree(Node *root)
    {
        if(root!=nullptr)
        {
            printTree(root->left);
            
            cout << root->data  << " ";
            
            printTree(root->right);
        }
    }
};

int main()
{
    BinaryTree B1;
    
    BinaryTree::Node *ptr = new Node(10);
    BinaryTree::Node *ptr1 = new Node(20);
    BinaryTree::Node *ptr2 = new Node(30);
    
    B1.root = ptr;
    
    B1.root->left = ptr1;
    
    B1.root->right = ptr2;
    
    B1.print(ptr);
    
    cout << "\n";
    
    return 0;
}
    
    
    
    
    
    return 0;
}