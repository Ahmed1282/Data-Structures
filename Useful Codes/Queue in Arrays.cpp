#include<iostream>
using namespace std;

class IntQueue
{   
	private:
		int *queueArray; // Pointer to array implemented as Queue  
		int queueSize;   // Total size of the Queue	
		int front;
		int rear;
		int numItems;    // Number of items currently in the Queue
		
   public:
   		IntQueue(int);
	   	~IntQueue(void);   	
		void enqueue(int);
		int dequeue(void);   	
		bool isEmpty(void);   	
		bool isFull(void);   	
		void makeNull(void);
};

IntQueue::IntQueue(int s) //constructor
{
   queueArray = new int[s];
   queueSize = s;   
   front = -1;  
   rear = -1;   
   numItems = 0;
}

IntQueue::~IntQueue(void) //destructor
{
	delete [] queueArray;
}

bool IntQueue::isFull(void)
{
	if (numItems < queueSize)		
		return false;
			
	else		
		return true;
		
}

bool IntQueue::isEmpty(void)
{
	if (numItems == 0)
		return true;
		
	else
		return false;
}

void IntQueue::makeNull(void)
{	
	front = - 1;
	rear = - 1;
	numItems = 0;
}

void IntQueue::enqueue(int num)
{
   if (isFull())
        cout << "The queue is full.\n"; 
   
   else 
   {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;
      // Insert new item
      queueArray[rear] = num;
      // Update item count
      numItems++;
   }
   
}

int IntQueue::dequeue(void)
{
   int num;
   if (isEmpty())
      cout << "The queue is empty.\n";
      
   else	{
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      num = queueArray[front];
      // Update item count
      numItems--;
   }
   return num;
}


int main()
{
	IntQueue iQueue(5);
   cout << "Enqueuing 5 items...\n";
   // Enqueue 5 items.
   for (int x = 0; x < 5; x++)
      iQueue.enqueue(x);
   // Attempt to enqueue a 6th item.
   cout << "Now attempting to enqueue again...\n";
   iQueue.enqueue(5);
   // Deqeue and retrieve all items in the queue
   cout << "The values in the queue were:\n";
   while (!iQueue.isEmpty()){
      int value;
      value = iQueue.dequeue();
      cout << value << endl;
   }
}
