#include <iostream>
using namespace std;
#include "Node.cpp"

class Queue
{
public:
	Node* head;
	Queue()
	{
		head = NULL;
	}
	void enqueue(int a)
	{
		Node* temp = new Node;
		temp->data = a;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			Node* p = head;
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = temp;
		}
		temp = NULL;
		delete temp;
	}
	void dequeue()
	{
		
		Node* c = head;
		head = c->next;
		delete c;
	}
	int peek()
	{
		Node* c = head;
		cout << "The starting value is : " << endl;
		return c->data;
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			cout << "Queue is empty\n";
			return true;
		}
		else
			return false;
	}
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
	}
	
	void roundRobin()
	{
		Node* temp;
		int sub;
		int val;
		cout << "Enter quantum value: ";
		cin >> val; 

		if (!isEmpty())
		{
			do
			{
				temp = head;
				sub = peek() - val;
				dequeue();

				if (sub > 0) {

					enqueue(sub);
				}
				display();
				cout << endl;
			} while (isEmpty() == false);
			cout << "It is Empty!"<<endl;
			display();
		}
	}
};