#include<iostream>
using namespace std;

class DynIntQueue{
   private:
         struct QueueNode  // Structure to define linked list node      
		 {  	int value;      
		 		QueueNode *next;      
		};
      	QueueNode *front; // pointer to the first node      
		  QueueNode *rear;  // pointer to the last node
      int numItems;     // Number of nodes in the linked list
      
   public:
        DynIntQueue(void);
	     ~DynIntQueue(void);
	      void enqueue(int);
	      int dequeue(void);
	     bool isEmpty(void);
	    void makeNull(void);
};

DynIntQueue::DynIntQueue(void) 
{
	   front = NULL;
	      rear = NULL;
		  numItems = 0;
}

bool DynIntQueue::isEmpty(void)
{   if (numItems)
      return false;
	
	else      
		return true;
}

void DynIntQueue::enqueue(int num)
{
   QueueNode *newNode;
   newNode = new QueueNode;
   newNode->value = num;
   newNode->next = NULL;
   if (isEmpty()) {
      front = newNode;
      rear = newNode;
   }
   else {
      rear->next = newNode;
      rear = newNode;
   }
   numItems++;
}

int DynIntQueue::dequeue(void)
{
   QueueNode *temp;
   int num;
   if (isEmpty())
      cout << "The queue is empty.\n";
   else {
      num = front->value;
      temp = front->next;
      delete front;
      front = temp;
      numItems--;
      if(!numItems) rear = NULL;
   }
   return num;
}

DynIntQueue::~DynIntQueue(void)
{   
	makeNull();
}

void DynIntQueue::makeNull(void)
{   while(!isEmpty())
	{
     	dequeue();
	}
}

int main()
{
	DynIntQueue iQueue;   
	cout << "Enqueuing 5 items...\n";   // Enqueue 5 items   
	for (int x = 0; x < 5; x++)
	      iQueue.enqueue(x);   // Deqeue and retrieve all items in the queue   
	
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty())   
	{      int value;      
			value= iQueue.dequeue();
			cout << value << endl;   
	}
}




