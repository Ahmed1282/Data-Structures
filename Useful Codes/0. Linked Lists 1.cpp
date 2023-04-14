#include<iostream>
using namespace std;

class Node
{
	public:
		int Value;
		Node* Next;
	
};

void print(Node* n)
{
	while(n != NULL)
	{
		cout<<n->Value<<endl;
		n = n->Next;
	}
}

void insert_Front (Node** head, int newValue)
{
	//1) Prepare a new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	//2) Put it infront of the current head
	newNode->Next = *head;
	//3) Move head of the list to point to the newNode
	*head = newNode;
}

void insert_End (Node** head, int newValue)
{
	//1) Prepare a new node
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;
	//2) IF Linked Lists is empty, newNode be a head node
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	//3) Find the last node
	Node* last = *head;
	while(last->Next != NULL)
	{
		last = last->Next;
	}
	//4) Insert the newNode after last node in the end
	last->Next = newNode;
}

void insert_After (Node* previous, int newValue)
{
	//1) Check previous Node is not Null
	if(previous == NULL)
	{
		cout<<"Previous cannot be Null"<<endl;
		return;
	}
	//2) Prepare a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	//3) Insert newnode after previous
	newNode->Next = previous->Next;
	previous->Next = newNode;
}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	
	head->Value = 1;
	head->Next = second;
	second->Value = 2;
	second->Next = third;
	third->Value = 3;
	third->Next = NULL;
	
	//insert_Front(&head, -1);
	//insert_End(&head, 4);
	//insert_After(head, -1);
	
	print(head);
	
	return 0;
}
