#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> queue)
{
	while(!queue.empty())
	{
		cout<< queue.front() << "  ";
		queue.pop();
		
	}
	cout<<endl;
}

int main()
{
	queue<int> myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	
	cout<<"Size of the queue: "<< myQueue.size() <<endl;
	cout<<"First element of the queue: "<< myQueue.front()<<endl;
	cout<<"Last element of the queue: "<< myQueue.back()<<endl;
	cout<<" My Queue: "<<endl;
	print(myQueue);
	
	return 0;
}
