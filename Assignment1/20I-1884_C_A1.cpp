//Muhammad Ahmed Baig_20i-1884_Section C_Assignment 1
#include<iostream>
using namespace std;

class Polynomial
{
    class Term
    {
    public:
        int Exponent;
        int Coefficient;
        Term* next;

    };
    Term* head;
    int size;

public:
    Polynomial()
    {
        head = NULL;
        size = 0;
    }
    void Input();
    void Output();
    int Evaluate(int num);
    Polynomial operator +(Polynomial& a);
};

void Polynomial::Input()
{
    cout << "Please enter the number of Terms: ";
    cin >> size;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        int coef, exp;
        cout << "Please enter Coefficient No." << i + 1 << ": ";
        cin >> coef;
        cout << "Please enter Exponent No." << i + 1 << ": ";
        cin >> exp;
        cout << endl;

        Term* temp = new Term;
        temp->Coefficient = coef;
        temp->Exponent = exp;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Term* ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

}

void Polynomial::Output()
{
    //sorting
    int temp1, temp2;
    for (Term* i = head; i != NULL; i = i->next)
    {
        for (Term* j = i->next; j != NULL; j = j->next)
        {
            if (i->Exponent < j->Exponent)
            {
                temp1 = i->Exponent;
                i->Exponent = j->Exponent;
                j->Exponent = temp1;

                temp2 = i->Coefficient;
                i->Coefficient = j->Coefficient;
                j->Coefficient = temp2;
            }
        }
    }
    //display
    if (head == NULL)
    {
        cout << "LIST EMPTY!" << endl;
    }

    else
    {
        cout << "Polynomial: ";
        Term* ptr = head;
        while (ptr != NULL)
        {
            if (ptr->next != NULL)
            {
                cout << ptr->Coefficient << "n^" << ptr->Exponent << " + ";
            }
            else if (ptr->next == NULL)
            {
                cout << ptr->Coefficient << "n^" << ptr->Exponent;
            }
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int Polynomial::Evaluate(int num)
{
    int final = 0;
    Term* ptr = head;
    while (ptr != NULL)
    {
        int f = num;
        for (int i = 1; i < ptr->Exponent; i++)
        {
            f = f * num;
        }
        final = final + (ptr->Coefficient * f);
        ptr = ptr->next;
    }
    return final;

}

//Addition
Polynomial Polynomial::operator +(Polynomial& a)
{
    Polynomial poly;
    Term* ptr1 = head;
    Term* ptr2 = a.head;
    Term* add = new Term;

    if (ptr1 == NULL)
    {
        add = ptr2;
    }
    else if (ptr2 == NULL)
    {
        add = ptr1;
    }
    else
    {
        if (ptr1->Exponent > ptr2->Exponent)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr1->Coefficient;
            temp->Exponent = ptr1->Exponent;

            add = temp;
            ptr1 = ptr1->next;
        }
        else if (ptr1->Exponent < ptr2->Exponent)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr2->Coefficient;
            temp->Exponent = ptr2->Exponent;

            add = temp;
            ptr2 = ptr2->next;
        }
        else if (ptr1->Exponent == ptr2->Exponent)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr1->Coefficient + ptr2->Coefficient;
            temp->Exponent = ptr1->Exponent;

            add = temp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

    }

    poly.head = add;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->Exponent > ptr2->Exponent)
        {
            Term* temp = new Term;

            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient;

            add->next = temp;
            add = add->next;
            ptr1 = ptr1->next;
        }

        else if (ptr1->Exponent < ptr2->Exponent)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr2->Coefficient;
            temp->Exponent = ptr2->Exponent;

            add->next = temp;
            add = add->next;
            ptr2 = ptr2->next;
        }

        else if (ptr1->Exponent == ptr2->Exponent)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr1->Coefficient + ptr2->Coefficient;
            temp->Exponent = ptr1->Exponent;

            add->next = temp;
            add = add->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

    }

    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr2->Coefficient;
            temp->Exponent = ptr2->Exponent;

            add->next = temp;
            add = add->next;
            ptr2 = ptr2->next;
        }
    }
    else if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            Term* temp = new Term;

            temp->Coefficient = ptr1->Coefficient;
            temp->Exponent = ptr1->Exponent;

            add->next = temp;
            add = add->next;
            ptr1 = ptr1->next;
        }
    }
    add->next = NULL;
    return poly;
}
int main()
{
    Polynomial ob1;
    ob1.Input();
    ob1.Output();
    cout << endl;
    int num;
    cout << "Please enter an integer to evaluate the Polynomial: ";
    cin >> num;
    //"." operator cant be overloaded so used function
    cout << "Polynomial: " << ob1.Evaluate(num) << endl;
    //Addition
    Polynomial ob2;
    ob2.Input();
    Polynomial p4;
    p4 = ob1 + ob2;
    p4.Output();
    return 0;
}
