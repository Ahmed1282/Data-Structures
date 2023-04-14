#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

void linkedListTraversal( Node *head)
{
	Node *ptr = head;
	do
    {
        cout<<"Element: "<<ptr->data<<endl;;
        ptr = ptr->next;
    }while (ptr != head);
}

 Node * insertAtFirst(struct Node *head, int data)
 {
    Node * ptr = new Node();
    ptr->data = data;
    
    Node * p = head->next;
    while(p->next != head)
	{
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
 
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
 
}

int main()
{
    Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node *fourth = new Node();


    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = head;

	cout<<"Linked list before insertion\n";
    linkedListTraversal(head);
    head = insertAtFirst(head,80);
    head = insertAtFirst(head,70);
    head = insertAtFirst(head,60);
   	cout<<"\nLinked list after insertion\n";
    linkedListTraversal(head);

    
    return 0;
}
