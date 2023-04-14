#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(int data, node* next)
	{
		this->data = data;
		this->next = next;
	}

};

class Stack
{
public:
	node* head;
	Stack()
	{
		head = NULL;
		
	}
	void push(int val)
	{
		node* pt = new node;
		pt->next = head;
		pt->data = val;
		head = pt;
	}
	int pop()
	{
		node* temp = head;
		head = head->next;
		int n = temp->data;
		delete temp;
		return n ;
	}
	int peek()
	{
		node* temp = head;
		int val = temp->data;
		head = head->next;
		return val;
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			//cout << "Stack is empty\n";
			return true;
		}
		else
		{
			//cout << "Stack is not empty\n";
			return false;
		}
	}

	void display()
	{
		node* p = head;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}

	int sizeS()
	{
		node* v = head;
		int x = 0;
		while (v != NULL)
		{
			x++;
			v = v->next;
		}
		return x;
	}
	/*
	void sort(int d)
	{
		if (isEmpty())
		{
			push(d);
		}
		else
		{
			push(d);
			int size = sizeS();
			int arr[size];
			for (int i = 0; i < size; i++)
			{
				int j = pop();
				arr[i] = j;
			}
			int temp;
			for (int i = 0; i < size; i++)
			{
				for (int j = i +1; j <= size; j++)
				{
					if (arr[i] > arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			for (int i = size ; i >= 0; i--)
			{
				push(arr[i]);
			}
		}
	}*/
	Stack* SortTheStack(int v, Stack* s)
{
	if (s->isEmpty())
	{

		s->push(v);
		return s;

	}
	else if (v > s->peek())
	{

		s->push(v);
		cout << "Stack in descending order is : ";
		s->display();
		return s;
	}
	else
	{
		int value;
		value = s->pop();
		SortTheStack(v, s);
		s->push(value);
		return s;
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
/*	cout << "enter values:\n";
	while (in != -1)
	{
		cin >> in;
		if (in == -1)
			break;
		s.sort(in);
	}
    cout << "\n";*/
    obj.display();
    obj.sort(2);
	obj.display();
}

