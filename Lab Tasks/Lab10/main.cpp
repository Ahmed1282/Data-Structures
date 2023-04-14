#include<iostream>
using namespace std;
#include "Queue.cpp"

int main()
{
	Queue q;
	q.enqueue(40);
	q.enqueue(30);
	q.enqueue(20);
	q.enqueue(10);
	q.enqueue(5);

	q.display();
	cout << endl;

	q.dequeue();
	q.display();
	cout << endl;

	q.roundRobin();
	
}