

 #include<iostream>
#include<string>
using namespace std;

#include<iostream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
    private:
    
    class Node
    {
        public:
       
        T data;
                     
        Node *next;
        Node *prev;
       
        Node():next(nullptr),prev(nullptr){}
       
        Node(T data1):data(data1){}
    };
    
    public :
    
    Node *head;
    
    DoubleLinkedList():head(nullptr){}
    
    /*
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
    */ ///  p-head-n p-0-n p-1-n p-2-n p-3-n p-4-n  
    
    void insertAtBegin(T data)
    {
        Node *curr = new Node(data);
       
        if(head == nullptr)
           head = curr;
         
         else
         {
             curr->next = head;
             head->prev = curr;
             head = curr;
             
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
    
    void printList()
    {
        Node *curr = head;
        
        while(curr!=nullptr)
        {
            cout << curr->data << " ";
       
             curr = curr->next;
        }
        
         cout << "\n";
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
        
        if(pos > l)
        {
            cout << "Out of Bound condition reached" << endl;
            return;
        }
        
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
        tmp1->prev = tmp;
        tmp->next = tmp1;
        (tmp->next)->prev = tmp1;
    }
   
   ///  p-head-n p-0-n p-1-n p-2-n p-5-n p-3-n p-4-n 
   
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
            curr->prev = curr1;
        }
    }
   
   
   
    /*
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
 */
};

int main()
{
    DoubleLinkedList<int> N1;
   
    N1.insertAtBegin(25);
   
    N1.insertAtBegin(2);
   
    N1.insertAtBegin(3);
   
    N1.insertAtEnd(5);
    
    N1.printList();
    
    N1.insertAtposition(6,11);
   
    N1.printList();
   
    cout << N1.size() << endl;

  /*  LinkedList<int> N2(N1);
    
    N2.printList();
    
    cout << "\n";
    
    LinkedList<int> N3;
    
     N3 = N2;
    
    N3.printList();
    
    cout << "\n";
    */
    return 0;
}
 