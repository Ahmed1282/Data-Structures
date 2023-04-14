

#include <iostream>

using namespace std;


class Node
{
public:
    double data;
    Node* next;
};

class List
{
public:
    Node* head;

    List(void)
    {
        head = NULL;
    }


    //friend void InsertAtStart(int);

    void InsertAtStart(int v)
    {
        Node* temp = new Node;
        temp->data = v;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }

        else

        {
            temp->next = head;
            head = temp;
        }

        temp = NULL;
        delete temp;

        // cout<<head->data;
    }

    void InsertToEnd(int v)
    {
        Node* temp = new Node;
        temp->data = v;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }

        else
        {
            Node* p = head;
            //p=head;

            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;


        }

        temp = NULL;
        delete temp;

    }






















    void InsertAtLoc(int l, int v)
    {
        Node* temp = new Node;
        temp->data = v;
        temp->next = NULL;

        Node* p = head;
        Node* q = head->next;

        for (int i = 0; i < l - 1; i++)
        {
            p = q;
            q = q->next;
        }

        p->next = temp;
        temp->next = q;
    }

    void InsertAfterValue(int c, int v)
    {

        Node* temp = new Node;
        temp->data = v;
        temp->next = NULL;

        Node* p = head;
        Node* q;

        while (p != NULL && p->data != c)
        {
            p = p->next;
        }

        q = p->next;
        p->next = temp;
        temp->next = q;
        temp = NULL;
        delete temp;
    }

    void DeleteAtStart()
    {
        Node* p = head;
        head = head->next;
        delete p;
    }

    void DeleteAtEnd()
    {
        Node* p = head;
        Node* q = head;

        while (q->next != NULL)
        {
            p = q;
            q = q->next;
        }
        p->next = NULL;
        delete q;
        q = NULL;

    }


    void DeleteATLocation(int l)
    {
        Node* p = head;
        Node* q = head;

        for (int i = 0; i < l; i++)
        {
            p = q;
            q = q->next;
        }

        p->next = q->next;
        delete q;
        q = NULL;
    }

    void DeleteAVAlue(int v)
    {
        Node* p = head;
        Node* q = head;

        while (q->data != v && q->next != NULL)
        {
            p = q;
            q = q->next;
        }

        p->next = q->next;
        delete q;
        q = NULL;
    }

    void Display()
    {
        if (head == NULL)
        {
            cout << "LIST EMPTY!" << endl;
        }

        else
        {
            Node* p = head;
            while (p != NULL)
            {
                cout << p->data << "     ";
                p = p->next;
            }
            cout << endl;
        }
    }

    


};





int main()
{

    List L;
    L.InsertAtStart(2);
    L.InsertToEnd(4);
    L.InsertAtLoc(1, 6);
    L.InsertAfterValue(2, 9);
    L.InsertAfterValue(9, 10);

    L.DeleteAtStart();
    L.DeleteAtEnd();
    cout << endl;
    // L.DeleteATLocation(1);
    //L.DeleteAVAlue(6);
  //  L.search(10);

    L.Display();
    return 0;
}
