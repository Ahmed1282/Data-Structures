#include <iostream>
using namespace std;


class node {
public:
	int data;
	node* Next;
	node* pre;
};





class Dlist {
public:
	node* head;
	node* tail;
	Dlist()
	{
		head = NULL;
		tail = NULL;
	}
	void InsertAtEnd(int data) {
		node *temp = new node;
		temp->data = data;
		temp->Next = NULL;
		temp->pre = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->Next = temp;
			temp->pre = tail;
			tail = temp;
			temp = NULL;
			delete temp;
		}
	}

	void InsertAtFirst(int data) {
		node* temp = new node;
		temp->data = data;
		temp->Next = NULL;
		temp->pre = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			head->pre = temp;
			temp->Next = head;
			head = temp;
			temp = NULL;
			delete temp;
		}
	}

	void InsertAtPos(int loc, int data) {
		node* temp = new node;
		temp->data = data;
		//temp->Next = NULL;
		//temp->pre = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			node* p = head, * c = head;
			for (int i = 1; i < loc-1; i++)
			{
				p = c;
				c = c->Next;
			}
			p->Next = temp;
			temp->pre = p;
			c->pre = temp;
			temp->Next = c;
			//temp = NULL;
			//delete temp;
		}
	}
	void DeleteAtStart()
	{
		node* temp = head;
		head = head->Next;
		head->pre = NULL;
		temp->Next = NULL;
		delete temp;
		temp = NULL;
	}

	void DeleteAtEnd()
	{
		node* temp = tail;
		tail = tail->pre;
		tail->Next = NULL;
		temp->pre = NULL;
		delete temp;
		temp = NULL;
	}

	void DeleteAtLoc(int loc)
	{
		node* pre = head, * cur = head;
		for (int i = 1; i < loc;i++)
		{
			pre = cur;
			cur = cur->Next;
		}
		pre->Next = cur->Next;
		cur->Next->pre = pre;
		delete cur;
		cur = NULL;
	}

	void Display() {
		node* display = head;
		cout << "The value at nodes: " << endl;
		while (display != NULL)
		{
			cout << display->data << "  ";
			display = display->Next;
		}
	}
	void RDisplay() {
		node* temp = tail;
		while (temp != head) {
			cout <<  temp->data << endl;
			temp = temp->pre;
		}
	}
	void RemoveDup()
	{
		node* cur, *pre, *dup;
		cur = head;
		while (cur != NULL && cur->Next != NULL) 
		{
			pre = cur;

			while (pre->Next != NULL) //comparing itmes
			{
				if (cur->data == pre->Next->data) //delete if duplicate
				{
					dup = pre->Next;
					pre->Next = pre->Next->Next;
					delete dup;
				}
				else
					pre = pre->Next;
			}
			cur = cur->Next;
		}
	}

};


int main()
{
	Dlist list;
	int a = 0;
	while (a != -1) {
		cin >> a;
		list.InsertAtEnd(a);
	}
	list.Display();
	cout << endl;
	list.RDisplay();

	int b;
	cout << "Insert at first : \n";
	cin >> b;
	list.InsertAtFirst(b);
	list.Display();

	int da;
	cout << endl << "Insert value to be inserted at location\n";
	cin >> da;
	list.InsertAtPos(1, da);
	cout << endl;
	//list.Display();

	list.DeleteAtEnd();
	//list.Display();

	list.RemoveDup();
	list.Display();
	return 0;
}
