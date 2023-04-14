#include<iostream>
using namespace std;


class Stack
{
   struct node
   {
      int data;
      node *next;
   };
   node *top;
   
   public:
      void push(int newelement)
      {
        node *newptr;
        newptr=new node();
   
         newptr->data=newelement;
        newptr->next=top;
   
       top=newptr;

      }
      void pop(int &)
      {
          if (IsEmpty()) 
        { 
          cout<<"underflow error";  
          return;
        }

        node *tempptr = top;
      int   returnvalue = top->data;
      top = top->next;
   
        delete tempptr;

      }
    
    	bool IsFull()
    	{
    		node *n = new node();
    		if(n == NULL)
    		{
    			return true;
			}
    		else
    		{
    			return false; 
			}
    		
		}
      
      bool IsEmpty()
      {
           if (top==NULL) 
          {
            return true;
          }
        else 
        {
          return false;
          }
      }
      
      void display()
	{
		node* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
};

int main()
{
	Stack s;
	int in ;
	Stack obj;
	obj.push(10);
	obj.push(20);
	obj.push(40);
	obj.push(50);
	obj.push(60);
	obj.pop();
	obj.display();
}

