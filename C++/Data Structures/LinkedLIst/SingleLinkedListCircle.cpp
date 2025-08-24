
//At which node we are seeing a Circle:
/*=======================================*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class LinkedList
{
    private:
    
    class Node
    {
        public:
        
        T data;
        
        Node *next;
        
        Node(T data1):data(data1),next(nullptr){}
    };
    
    Node *head;    
    
    public:
    
    LinkedList():head(nullptr){}
    
    void insertAtBegin(T val)
    {
        Node *tmp = new Node(val);
        
        if(head == nullptr)
            head = tmp;
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }
    
    void print()
    {
        Node *tmp = head;
        
        while(tmp!=nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }

    size_t  size()
    {
        Node *tmp = head;
        
        size_t count = 0 ;
        
        while(tmp!=nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    
    void insertAtEnd(T val)
    {
        
        Node *tmp = new Node(val);
        
        if(head == nullptr)
            head = tmp;
        
        else
        {
            Node *tmp1 = head;
            
            while(tmp1->next != nullptr)
                tmp1 = tmp1->next;
            
            tmp1->next = tmp;
        }
        
    }
    
    void insertAtposition(int pos, T val)
    {
        Node *tmp = head;
    
        int count = 0;
        
        
        if(pos == 1)
        {   
            insertAtBegin(val);
            return;
        }
        
        int l = size()+1;
        
        if(pos == l)
        {   
            insertAtEnd(val);
            return;
        }
        
        while(tmp->next!=nullptr)
        {
            count++;
            
            if(count == (pos-1)) break;
            tmp = tmp->next;
        }
        
        Node *tmp1 = new Node(val);
        
        tmp1->next = tmp->next;
        tmp->next = tmp1;

    }
    
    Node* operator [] (int index)
    {
        if(index < 0) 
            throw index;
        
        Node  *curr = head;
        
        int count = -1;
        
        while(curr!=nullptr)
        {
            count++;
            
            if(count == index)
                break;
                
            curr = curr->next;
        }
        
        if(curr == nullptr) 
            throw index;
        
        return curr;
    }
 
    void addLoopAtPosition(int pos)
    {
        int last_idx = size()-1;
        
         Node *lastNode = (*this)[last_idx];
         
         lastNode->next = (*this)[pos-1];
        
    }
    
    //slow and fast moving pointer
    // One pointer will be moving slowly 
    // Second pointer will be moving fast
    
    void checkLoop()
    {
        Node *slow = head; 
        Node *fast = head->next->next;
        
        while(slow!=fast && fast!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast!=nullptr)
        cout << "Loop exists at Node " << slow->data << endl;
        
        else
        cout << "Loop doesn't exists " << endl;
    }
};

int main()
{
    LinkedList<int> L1;
    
    L1.insertAtBegin(1);
    L1.insertAtBegin(2);
    L1.insertAtBegin(3);
    L1.insertAtBegin(4);
    L1.insertAtBegin(5);
    

    L1.print();
    
    cout << L1.size() << endl;
    
    L1.insertAtposition(6,11);
    
    L1.print();
    
    //L1.addLoopAtPosition(2);
    
    cout << L1[0]->data << endl;
    
    //L1.checkLoop();
    
    return 0;

}
