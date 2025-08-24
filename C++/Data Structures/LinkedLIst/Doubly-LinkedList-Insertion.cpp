
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
    */ ///  head  p-1-n p-2-n p-3-n p-4-n  //1-p =nullptr
          // head p-0-n p-1-n p-2-n p-3-n p-4-n -0- //  0-p =nullptr
    void insertAtBegin(T data)
    {
        Node *cur = new Node(data);
       
        if(head == nullptr)
        {
            head = cur;
            cur->next = head;
            cur->prev = head;
        }
         else
         {
             cur->next = head;
             
             cur->prev = head->prev;
             
             (head->prev)->next = cur;
             
             head->prev = cur;
             
             head = cur;
             
         }
    }
	
	///  p-head-n  p-1-n p-2-n p-5-n p-3-n p-4-n 
   
   void deleteAtBegin()
    {
        
        if(head == nullptr)
            return;
        else
        {
            Node *tmp = head;
            head = head->next;//2
			head->prev = nullptr;
            delete tmp;//1
        }
    }
   
    int size()
    {
        Node *cur = head;
       
        int count = 0 ;
        
        if(cur == nullptr)
            return count;
        do
        {
            count++;
            cur = cur->next;
        }while(cur!= head);
        
        return count;
    }
   
   
   ///  p-head-n p-0-n p-1-n p-2-n p-5-n p-3-n p-4-n 
   
    void insertAtEnd(T data)
    {
        Node *cur = new Node(data);
       
        if(head == nullptr)
        {
            head = cur;
            cur->next = head;
        }
        
        else
        {
            (head->prev)->next = cur;
            
            cur->prev = head->prev;
            
            cur->next = head;
            
            head->prev = cur;
    
        }
    }        

    void insertAtposition(int pos, T val)
    {
        Node *cur = head;
    
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
        
        if(pos > l)
        {
            cout << "Out of Bound condition reached" << endl;
            return;
        }
        
        while(cur->next!=head)
        {
            count++;
            
            if(count == (pos-1))
                break;
            
            cur = cur->next;
        }
        
        Node *tmp1 = new Node(val);
        
        tmp1->next = cur->next;
        tmp1->prev = cur;
        
        (cur->next)->prev = tmp1;
        cur->next = tmp1;
    }
   
      
    void printList()
    {
        Node *cur = head;
        
        do 
        {
            cout << cur->data << " ";
       
             cur = cur->next;
        }while(cur!=head);
        
         cout << "\n";
    }
    
    void printFromLast()
    {
        Node *cur = head;
        
        do 
        {
            cur = cur->prev;
            
            cout << cur->data << " ";
       
             
        }while(cur!=head);
        
         cout << "\n";
    }
};

int main()
{
    DoubleLinkedList<int> N1;
   
    N1.insertAtBegin(25);
   
    N1.insertAtBegin(2);
   
    N1.insertAtBegin(3);
    
    N1.insertAtEnd(55);
    
    N1.printList();
    
    N1.printFromLast();
    
    N1.insertAtposition(5,100);
    
    N1.printList();
    
    N1.printFromLast();
   
   /*
    N1.insertAtEnd(1);
    
    N1.insertAtEnd(2);
    
    N1.insertAtEnd(3);
    
    N1.insertAtEnd(4);
    
    N1.insertAtposition(2,11);
   
    N1.printList();
   
    cout << N1.size() << endl;
    
    N1.printFromEnd();

    N1.deleteAtBegin();
    
    N1.printList();
    
    N1.deleteAtEnd();
    
    N1.printList();
    
    N1.deleteAtposition(2);
    
    N1.printList();
     
    N1.printFromEnd();
     */  
    return 0;
}
 