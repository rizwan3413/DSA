#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int data;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), data(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> storageMap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // Dummy head
        tail = new Node(-1, -1); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    // Insert node right after head (most recently used)
    void addNode(Node* newNode) { 
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    // Remove a node from the list
    void delNode(Node* oldNode) { 
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    
    int get(int key) { 
        if (storageMap.find(key) == storageMap.end()) {
            return -1;
        }

        Node* node = storageMap[key];
        int ans = node->data;

        // Move this node to front (most recently used)
        delNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int val) {
        // If already exists, remove old node
        if (storageMap.find(key) != storageMap.end()) {
            Node* oldNode = storageMap[key];
            delNode(oldNode);
            storageMap.erase(key);
            delete oldNode; // free memory
        }

        // If capacity full, remove LRU (node before tail)
        if (storageMap.size() == capacity) {
            Node* lru = tail->prev;
            delNode(lru);
            storageMap.erase(lru->key);
            delete lru;
        }

        // Create and add new node at front
        Node* newNode = new Node(key, val);
        addNode(newNode);
        storageMap[key] = newNode;
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LRUCache cache(2); // Capacity of 2
    cache.put(1, 1);   // cache = {1=1}
    cache.put(2, 2);   // cache = {1=1, 2=2}
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);   // evicts key 2 → cache = {1=1, 3=3}
    cout << cache.get(2) << endl; // returns -1
    cache.put(4, 4);   // evicts key 1 → cache = {4=4, 3=3}
    cout << cache.get(1) << endl; // returns -1
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}
