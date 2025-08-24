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
    
    LinkedList operator + (LinkedList & rhs)
    {
        
        LinkedList result;
        
         Node *first = head;
         Node *second = rhs.head;
        
         if(first == nullptr && second == nullptr)
            return result;
        
        if(first == nullptr &&  second != nullptr)
            return rhs;
        
        if(first != nullptr &&  second == nullptr)
            return *this;
            
         size_t f_size = size();
         size_t s_size = rhs.size();
        
        int max_size = s_size > f_size ? s_size:f_size;
        
        bool f_flag = false;
        bool s_flag = false;
        
        int count = 0;
        int carry = 0;
        
        for(int i = 0;i < max_size;i++)
        {
            count = 0;
            
            while(first->next!= nullptr)
            {
                if(f_size - i <= 0)
                {
                    f_flag = true;
                    break;
                }
                
                count++;
                
                if(count == f_size - i) 
                    break;    
                
                first = first->next;
            }
            
            count = 0;
            
            while(second->next!= nullptr)
            {
                
                if(s_size - i <= 0)
                {
                    s_flag = true;
                    break;
                }
                
                count++;
                
                if(count == s_size - i) 
                    break;    
                
                second = second->next;
            }
            
            cout << (f_flag?0:first->data) << " " << (s_flag?0:second->data) << endl;
            
            result.insertAtBegin( ((f_flag?0:first->data) + (s_flag?0:second->data) + carry ) % 10);
            
            
            carry = ((f_flag ? 0 : first->data) + (s_flag ? 0:second->data))/10;
            
            first = head;
            second = rhs.head;
            
            f_flag = false;
            s_flag = false;
        }
        
    
        if(carry)
        result.insertAtBegin(carry);
        
        cout << " Completed the + operator" << endl;
        
        return result;
    }

};


int main()
{
    LinkedList<int> L1;
    
    L1.insertAtBegin(1);
    L1.insertAtBegin(2);
    L1.insertAtBegin(3);
    L1.insertAtBegin(4);
    //4  3 2 1 
    //8  7 6 5
    /*==========
    1 2  9  8 6*/
  
    //L1.print();
    
    cout << L1.size() << endl;
    
    LinkedList<int> L2;
/*    
    L2.insertAtBegin(5);//6
    L2.insertAtBegin(6);//8
    L2.insertAtBegin(7);//10
  */  
    L2.print();
    
    cout << L2.size() << endl;
    
    LinkedList<int> L3 = L1 + L2;
    
    L3.print();
    
    cout << L3.size() << endl;
    
    
    return 0;

}
