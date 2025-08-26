#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int x) {
        key = x;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Recursive insert (your original one)
    Node* insertRecursiveHelper(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }
        else if (val < root->key) {
            root->left = insertRecursiveHelper(root->left, val);
        }
        else if (val > root->key) {
            root->right = insertRecursiveHelper(root->right, val);
        }
        return root;
    }

    // Iterative insert
    Node* insertIterativeHelper(Node* root, int val) {
        Node* parent = nullptr;
        Node* curr = root;
        Node* temp = new Node(val);

        while (curr != nullptr) {
            parent = curr;
            if (val < curr->key) {
                curr = curr->left;
            }
            else if (val > curr->key) {
                curr = curr->right;
            }
            else {
                delete temp; // value exists, cleanup
                return root;
            }
        }

        if (parent == nullptr) {
            return temp; // tree empty
        }
        if (val < parent->key) parent->left = temp;
        else parent->right = temp;

        return root;
    }

    Node* getSuccessor(Node* curr) {
        curr = curr->right;
        while (curr != nullptr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    Node* deleteHelper(Node* root, int val) {
        if (root == nullptr) return nullptr;

        if (val < root->key) {
            root->left = deleteHelper(root->left, val);
        }
        else if (val > root->key) {
            root->right = deleteHelper(root->right, val);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* succ = getSuccessor(root);
                root->key = succ->key;
                root->right = deleteHelper(root->right, succ->key);
            }
        }
        return root;
    }

    bool searchHelper(Node* node, int val) {
        if (node == nullptr) return false;
        if (node->key == val) return true;
        if (val < node->key) return searchHelper(node->left, val);
        return searchHelper(node->right, val);
    }

    void inorderHelper(Node* root) {
        if (root == nullptr) return;
        inorderHelper(root->left);
        cout << root->key << " ";
        inorderHelper(root->right);
    }

public:
    BST() : root(nullptr) {}

    // Public wrappers
    void insertRecursive(int val) {
        root = insertRecursiveHelper(root, val);
    }

    void insertIterative(int val) {
        root = insertIterativeHelper(root, val);
    }

    void remove(int val) {
        root = deleteHelper(root, val);
    }

    bool search(int val) {
        return searchHelper(root, val);
    }

    void printInorder() {
        inorderHelper(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    // Insert using recursive
    bst.insertRecursive(10);
    bst.insertRecursive(5);
    bst.insertRecursive(15);

    // Insert using iterative
    bst.insertIterative(6);
    bst.insertIterative(28);
    bst.insertIterative(35);

    cout << "Inorder traversal: ";
    bst.printInorder();

    bst.remove(15);

    cout << "Inorder traversal after delete: ";
    bst.printInorder();

    if (bst.search(35)) {
        cout << "Value is present" << endl;
    } else {
        cout << "Value is not present" << endl;
    }

    return 0;
}

