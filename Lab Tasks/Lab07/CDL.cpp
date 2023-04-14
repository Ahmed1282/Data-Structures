#include "node.cpp"
#include <iostream>
using namespace std;
class CDL {
public:

	node* head;
	node* tail;

	CDL() {
		head = tail = NULL;
	}
	void InsertAtEnd(int d) {
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		temp->pre = NULL;
		if (head == NULL)
		{
			head = tail = temp;
			temp->next = temp;
			temp->pre = temp;
		}
		else {
			tail->next = temp;
			temp->pre = tail;
			temp->next = head;
			head->pre = temp;
			tail = temp;

		}
		temp = NULL;
		delete temp;
	}


	void InsertAtStart(int d) {
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		temp->pre = NULL;

		if (head == NULL) {
			head = tail = temp;
			temp->next = temp;
			temp->pre = temp;
		}
		else {
			temp->next = head;
			temp->pre = tail;
			tail->next = head->pre = temp;
			head = temp;
		}
		temp = NULL;
		delete temp;
	}

	void InsertAtPos(int d1, int d2) {
		node* temp = new node;
		temp->data = NULL;
		temp->next = NULL;
		temp->pre = NULL;

		node* temp2 = new node;
		temp2->data = d1;

		if (head == NULL) {
			head = tail = temp;
			temp->next = temp;
			temp->pre = temp;
		}
		else {
			temp = head;
			while (temp->data != d2) 
			{
				temp = temp->next;
			}

			node* temp2 = new node;
			temp2 = temp->next;

			temp->next = temp2;
			temp2->pre = temp;
			temp2->next = temp2;
			temp2->pre = temp2;
		}
		temp = NULL;
		delete temp;
	}

	void Display()
	{
		node* temp = head;
		cout << "----------- : \n";
		while (temp->next != head)
		{
			cout << temp->data<<" ";
			temp = temp->next;
		} 
	}

	void RDisplay() {
		node* temp = head;
		temp = tail->pre;
		cout << "\nReverse direction : \n";
		while (temp->pre != tail)
		{
			cout << temp->data << " ";
			temp = temp->pre;
		}
		cout << temp->data << endl;
	}

	void DeleteAtPos(int pos) {
		node* temp = head;
		for (int i = 0; i < pos; i++) {
			temp = temp->next;
		}
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
	}
	void DeleteAtEnd() {
		node* temp = head;
		if (head != NULL)
		{
			while (temp->next != head)
			{
				temp = temp->next;
			}
		}
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
	}
	
	void DeleteAtStart()
	{
		if (head != NULL)
		{
			if (head->next == head)
				head = NULL;
			else {
				node* temp = head;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				head = head->next;
				head->pre = temp;
				temp->next = head;
			}
		}
	}

	void deleteNode(node* val)
	{
		node* temp = val;
		node * t2 = val->pre;
		node * t3 = val->next;

		t2->next = t3;
		t3->pre = t2;
		delete temp;
	}

	void reverse()
	{
		node* d1 = head;
		node* d2 = tail;
		while (d1 != tail)
		{
			InsertAtStart(d1->data);
			node* temp = d1;
			d1 = d1->next;
			deleteNode(temp);
		}
	}

	int Middle()
	{
		int count = 0;
		node* c = head;
		do
		{
			c = c->next;
			count++;

		} while (c != head);
		node* temp = head;
		int a = 0;
		do
		{
			if (a == count / 2)
				return (temp->data);

			temp = temp->next;
			a++;

		} while (temp != head);
	}
}; 