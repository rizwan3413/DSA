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
};

int main()
{
    LinkedList<string> L1;
    
    L1.insertAtBegin("Apple");
    
    L1.insertAtBegin("Microsoft");
    
    L1.insertAtBegin("Google");
    
    L1.insertAtBegin("Linkedin");
    
    L1.print();
    
    cout << L1.size() << endl;
    
    L1.insertAtEnd("All companies are waiting to hire Rizwan");
    
    L1.print();
    
    L1.insertAtposition(6,"Time will come where ");
    
    L1.print();
    
    return 0;

}
