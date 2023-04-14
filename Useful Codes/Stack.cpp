#include<iostream>
using namespace std;


class IntStack{ 
  private:    
    int *stackArray;
    int stackSize;
    int top;
  public:
  
    IntStack(int size)
    {
      stackArray = new int[size]; 
      stackSize = size; 
      top = -1;
    }
    
    ~IntStack( )
    {
      delete [] stackArray;
    }
    
    void push(int num)
    {
      
      if (isFull()) 
      {
        cout << "The stack is full.\n";
       }
      else 
       {
        top++;
        stackArray[top] = num;
       }
    }
    
    void pop(int &num)
    {
      if (isEmpty())
      {
        cout << "The stack is empty.\n";
        }
     else
     {
        num = stackArray[top];
        top--;
      }
    }
    
    bool isFull(void)
    {
   bool status;
   if (top == stackSize - 1)
    status = true;
   
   else
    status = false;
    return status; // return (top == stackSize-1);
    }
    
    
    bool isEmpty(void)
  {
    return (top == -1);
  }
  };
  
  
  int main()
{
  IntStack stack(4);
  int catchVar;
  
  cout << "Pushing Integers\n";
  stack.push(5);
  stack.push(10);
  stack.push(15);
  stack.push(20);
  
  cout << "Popping...\n";
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);
  cout << catchVar << endl;
  stack.pop(catchVar);

}

