#include<iostream>
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
       
        Node():next(nullptr){}
       
        Node(T data1):data(data1){}
    };
    
    public :
    
    Node *head;
    
    LinkedList():head(nullptr){}
    
    
    //Assigment Operator 
    LinkedList& operator = (const LinkedList &rhs)
    {
        if(this!= &rhs)
        {
            Node *temp = new Node(rhs.head->data);
            
            head = temp;
            
            Node* curr = rhs.head;
            
            curr = curr->next;
            
            while(curr!=nullptr)
            {
                Node *temp1 = new Node(curr->data);
                
                temp->next = temp1;
                
                temp = temp->next;
                
                curr = curr->next;
            }
        }
        
        return *this;
    }
    
    //Copy Constructor
    LinkedList(const LinkedList &rhs)
    {
        Node *temp = new Node(rhs.head->data);
        
        head = temp;
        
        Node* curr = rhs.head;
        
        curr = curr->next;
        
        while(curr!=nullptr)
        {
            Node *temp1 = new Node(curr->data);
            
            temp->next = temp1;
            
            temp = temp->next;
            
            curr = curr->next;
            
            
        }
        
    }
    
    void insertAtBegin(T data)
    {
        Node *curr = new Node(data);
       
        if(head == nullptr)
           head = curr;
         
         else
         {
             curr->next = head;
             head = curr;
         }
    }
   
    void insertAtEnd(T data)
    {
        Node *curr = new Node(data);
       
        if(head == nullptr)
            head = curr;
       
        else
        {
            Node *curr1 = head;
       
            while(curr1->next!=nullptr)
            {
                curr1 = curr1->next;
            }
       
            curr1->next = curr;
            curr->next = nullptr;
        }
    }
   
   
    void printList()
    {
        Node *curr = head;
        
        while(curr!=nullptr)
        {
            cout << curr->data << " ";
       
             curr = curr->next;
        }
    }

   int size()
    {
        Node *curr = head;
       
        int count = 0 ;
       
        while(curr!= nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    
    void reverse()
    {
        if(head == nullptr)
            return;
        
        Node *curr = head;
        
        Node *next = nullptr;
        
        Node *prev = nullptr;
        
        while(curr!=nullptr)
        {
            next = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            
            curr = next;
            
        }
        
        head = prev;
    }
    
    void swap(Node *initial,Node *final)
    {
        Node* prev_initial = head;
        
        if(initial == head)
            prev_initial = nullptr;
        else
        {
            while(prev_initial->next!= initial)
            {
                prev_initial = prev_initial->next; 
            }
        
        }
        
        // temp = initial->next; initial->next = final->next, final->next = temp;
                               
        
        Node* prev_final = head;
        
        if(final == head)
            prev_final = nullptr;
        
        else
        {
            while(prev_final->next!= final)
            {
                prev_final = prev_final->next; 
            }
        }
        
        if(prev_initial == nullptr)
            head = final;
        else
            prev_initial->next = final;
        
        if(prev_final == nullptr)
            head = initial;
        else    
            prev_final->next = initial;
        
        auto temp = initial->next;
        initial->next = final->next;
        final->next = temp;
        
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
 
};

int main()
{
    LinkedList<int> N1;
   
    N1.insertAtBegin(1);
   
    N1.insertAtBegin(2);
   
    N1.insertAtBegin(3);
   
    N1.insertAtEnd(5);
   
    N1.printList();
   
    cout << "\n";
   
    cout << N1.size() << endl;

    LinkedList<int> N2(N1);
    
    N2.printList();
    
    cout << "\n";
    
    LinkedList<int> N3;
    
     N3 = N2;
    
    N3.printList();
    
    cout << "\n";
    
    return 0;
}