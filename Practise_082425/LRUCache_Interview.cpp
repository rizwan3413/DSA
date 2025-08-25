#include <iostream>
#include <unordered_map>
#include <thread>
#include <chrono>
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

// Slow function (simulates expensive operation)
int slowFunction(int key) {
    cout << "Performing slow operation for key " << key << "...\n";
    this_thread::sleep_for(chrono::seconds(2)); // Simulate delay
    return key * 2; // Example computation
}

// Fast function using LRU cache
int fastFunction(LRUCache& cache, int key) {
    int value = cache.get(key);
    if (value == -1) {
        value = slowFunction(key);
        cache.put(key, value);
    } else {
        cout << "Cache hit for key " << key << " -> " << value << endl;
    }
    return value;
}

int main() {
    LRUCache cache(3); // Capacity = 3

    // First call -> slow
    cout << "Result: " << fastFunction(cache, 5) << endl; // slow
    // Second call -> fast (cache hit)
    cout << "Result: " << fastFunction(cache, 5) << endl; // cached

    // Another key -> slow
    cout << "Result: " << fastFunction(cache, 10) << endl; 
    // Cache hit again
    cout << "Result: " << fastFunction(cache, 10) << endl; 

    // Fill cache beyond capacity
    cout << "Result: " << fastFunction(cache, 20) << endl;
    cout << "Result: " << fastFunction(cache, 30) << endl; // evicts LRU (5)

    // Key 5 should be evicted → slow again
    cout << "Result: " << fastFunction(cache, 5) << endl;

    return 0;
}
