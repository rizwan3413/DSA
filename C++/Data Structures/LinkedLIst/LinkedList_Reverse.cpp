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
    
    ~LinkedList()
    {
        cout << "Destructor in Operation" << endl;
        
        Node *cur = head;
        
        Node * prev = nullptr;
        
        while(cur!=nullptr)
        {
            prev = cur->next;
            delete cur;
            cur = prev;
        }
    }
    
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
    
    void deleteAtBegin()
    {
        
        if(head == nullptr)
            return;
        else
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
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
    
    void deleteAtEnd()
    {
    
        if(head == nullptr)
            return;
        
        else
        {
            Node *cur = head;
            
            Node *prev = nullptr;
            
            while(cur->next != nullptr)
            {
                prev = cur;
                cur = cur->next;
            }
            
            delete cur;
            prev->next = nullptr;
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
    
    void deleteAtposition(int pos)
    {
        Node *cur = head;
    
        int count = 0;
        
        
        if(pos == 1)
        {   
            deleteAtBegin();
            return;
        }
        
        int last = size()+1;
        
        if(pos == last)
        {   
            deleteAtEnd();
            return;
        }
        
        Node *prev = nullptr;
        
        while(cur!=nullptr)
        {
            count++;
            
            if(count == pos) 
                break;
        
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = cur->next;
        
        delete cur;
        
    }
    
    bool search(T val)
    {
        bool flag = false;
        
        Node *cur = head;
        
        while(cur->next!=nullptr)
        {
            if(cur->data == val)
            {
                flag = true;
                break;
            }
            
            cur =  cur->next;
        }
        
        return flag;
    }
    
    void reverse()
    {
        Node *cur = head;
        
        Node *prev = nullptr;
        
        Node *next = nullptr;
        
        while(cur!=nullptr)
        {
             next = cur->next;
             
             cur->next = prev;
             
             prev = cur;
             
             cur = next;    
        }
         
        head = prev;
    }
};

int main()
{
    LinkedList<int> L1;
    
    L1.insertAtBegin(1);
    
    L1.insertAtBegin(2);
    
    L1.insertAtBegin(10);
    
    L1.insertAtBegin(25);
    
    L1.print();
    
    cout << L1.size() << endl;
    
    L1.insertAtEnd(30);
    
    L1.print();
    
    L1.insertAtposition(6,11);
    
    L1.print();
    
    L1.reverse();
    
    L1.print();
    
    return 0;

}
