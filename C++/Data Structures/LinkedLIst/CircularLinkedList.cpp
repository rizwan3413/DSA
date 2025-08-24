
#include<iostream>
using namespace std;

//nullptr -head- Node1 - Node2 - Node 3 - Node1 - Circular 

template<typename T>
class CircularLinkedList
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
    
    CircularLinkedList():head(nullptr){}
    
    void insertAtBegin(T data)
    {
        Node *cur = new Node(data);
       
        if(head == nullptr)
        {
           head = cur;
           cur->next = head;
        }        
        
         else
         {
             cur->next = head;
             
             Node *temp = head;
             
             while(temp->next!=head)
             {
                 temp = temp->next;
             }
             
             temp->next = cur;
             
             head = cur;
             
         }
    }
	
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
             
             Node *temp = head;
             
             while(temp->next!=head)
             {
                 temp = temp->next;
             }
             
             cur->next = temp->next;// Sunnys approach 
             temp->next = cur;
             
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
   
	///  p-head-n  p-1-n p-2-n p-5-n p-3-n p-4-n 
    void insertAtposition(int pos,T data)
    {
        if(pos == 1)
        {
            insertAtBegin(data);
            return;
        }
        
        int last = size();
        
        if(pos > last)
            cout << " Out of Bound Condition reached,exit";
        
        if(pos == last)
        {
            insertAtEnd(data);
            return;
        }
        
        int count = 0;
        
        Node *cur = head;
        
        while(cur->next!=head)
        {
            count++;
            
            if(count == (pos-1))
                break;
                
            cur = cur->next;
        }
        
        Node *temp = new Node(data);
        
        temp->next = cur->next;
        cur->next = temp;
        
    }
   
   //head- 1-n 2-n 5-n -1
    void deleteAtBegin()
    {
        Node *cur = head;
        
        if(head == nullptr)
            return;
        
        else
        {
            while(cur->next!=head)
            {
                cur = cur->next;
            }
            
            cur->next = head->next; //links
            delete head;
            head = cur->next;
            
        }
    }
    
    void deleteAtEnd()
    {
        Node *cur = head;
        
        Node *prev = nullptr;
        
        while(cur->next!=head)
        {
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = cur->next;
        delete cur;
        
    }
    
   ///  p-head-n p-0-n p-1-n p-2-n p-5-n p-3-n p-4-n 
   
    
    void printList()
    {
        Node *cur = head;
        
        if(cur == nullptr)
            return;

        do
        {
            cout << cur->data << " ";
            cur = cur->next;
        }while(cur!=head);
        
         cout << "\n";
         
    }

   
    ///  p-head-n p-0-n p-1-n p-2-n p-5-n p-3-n p-4-n
                        //2 steps
                        // (2-p)->n = 2-n;
                        //(2-n)->p = 2-p;
                        
   
};

int main()
{
    CircularLinkedList<int> N1;
   
    N1.insertAtBegin(25);
   
    N1.insertAtBegin(2);
   
    N1.insertAtBegin(3);
   
    N1.printList();
    
    cout << N1.size() << endl;
    
    N1.insertAtEnd(13);
    
    N1.printList();
    
    cout << N1.size() << endl;
    
    N1.insertAtposition(2,11);
    
    N1.printList();
    
    cout << N1.size() << endl;
    
    /*
    N1.insertAtEnd(1);
    
    N1.insertAtEnd(2);
    
    N1.insertAtEnd(3);
    
    N1.insertAtEnd(4);
    
    
   
    N1.printList();
   
    cout << N1.size() << endl;
    
    N1.printFromEnd();

    N1.deleteAtBegin();
    
    N1.printList();
    
    N1.deleteAtEnd();
    
    N1.printList();
    
    N1.deleteAtposition(2);
    
    N1.printList();
     
    //N1.printFromEnd();
    
    DoubleLinkedList<int> N2(N1);
    
    DoubleLinkedList<int> N3;
    
    N3 = N2;
    
    N2.printList();
    
    N3.printList();
      */ 
    return 0;
}
 