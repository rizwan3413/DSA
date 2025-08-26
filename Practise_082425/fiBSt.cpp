 Node *root = nullptr;
    Node *prev = nullptr;
    Node *first = nullptr;
    Node *second = nullptr;
    void fixBST(Node * root){
        if( root == nullptr) return;
        
        fixBST(root->left);
        
        if(prev != nullptr && root->key < prev->key ){
            
            if(first == nullptr)
                first = prev;
            second = root;
        }
        prev = root;
        fixBST(root->right);
    }

 

bool isPairSum(Node* root, int sum, unordered_set<int>& s) {
    if (root == nullptr) return false;

    if (isPairSum(root->left, sum, s)) return true;

    if (s.find(sum - root->key) != s.end()) {
        return true;
    } else {
        s.insert(root->key);
    }

    return isPairSum(root->right, sum, s);
}
	
