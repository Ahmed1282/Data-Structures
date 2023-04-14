#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

void linkedListTraversal( Node *ptr)
{
    while (ptr != NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;;
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
 Node * deleteFirst( Node * head)
 {
    Node * ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
 Node * deleteAtIndex( Node * head, int index){
     Node *p = head;
     Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    delete q;
    return head;
}

// Case 3: Deleting the last element
 Node * deleteAtLast( Node * head){
     Node *p = head;
     Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    delete q;
    return head;
}


// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteAtIndex2(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        delete q;
    }
    return head;
}
int main()
{
    Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node *fourth = new Node();

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    cout<<"Linked list before deletion\n";
    linkedListTraversal(head);

    //head = deleteFirst(head); // For deleting first element of the linked list
    //head = deleteAtIndex(head, 2);
    //head = deleteAtLast(head);
    head = deleteAtIndex2(head, 8);
    cout<<"\nLinked list after deletion\n";
    linkedListTraversal(head);

    return 0;
}
