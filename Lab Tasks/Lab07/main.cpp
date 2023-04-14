#include <iostream>
using namespace std;
#include "CDL.cpp"
int main()
{
    CDL list;

    int a = 0;
    while (a != -1)
    {
        cin >> a;
        list.InsertAtEnd(a);
        //cout << endl;
    }
    cout << "I am out\n";
    list.Display();
    list.RDisplay();
    cout << "Inserting 8 at start:\n";
    list.InsertAtStart(8);
    list.Display();
    cout << "\nRevsere list\n";
    list.reverse();
    list.Display();
    cout << "\nDeleting at location 3:\n";
    list.DeleteAtPos(3);
    list.Display();
    cout << "\nMiddle node\n";
    list.Middle();
    cout << "\nDelete at end\n";
    list.DeleteAtEnd();
    list.Display();
    cout << "\nDelete at start\n";
    list.DeleteAtStart();
    list.Display();
}