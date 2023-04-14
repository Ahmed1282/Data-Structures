#include <iostream>
using namespace std;

class Stack 
{
private:
	int* arr;
	int top; 
	int size;
public:
	Stack(int s) {
		size = s;
		top = -1;
		arr = new int[size];
	}
	void Push(int data) {
		if (top == size - 1)
		{
			cout << "Stack is full!" << endl;

		}
		else
		{
			arr[++top] = data;
		}
	}
	int Pop() {
		if (top == -1)
		{
			cout << "Stack is empty!" << endl;
			return NULL;
		}
		else
		{
			return arr[top--];
		}
	}
	int Peek() {
		if (top == -1) {
			cout << "Stack is empty!" << endl;
			return NULL;
		}
		else {
			return arr[top];
		}
	}
	bool isFull() {
		if (top < size - 1) {
			return false;
		}
		else {
			return true;
		}
	}
	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	Stack Obj = Stack(5);
	Obj.Push(3);
	Obj.Push(8);
	Obj.Push(5);
	Obj.Push(3);
	Obj.Push(2);
	cout << Obj.Pop() << endl;
	cout << Obj.Pop() << endl;
	cout << Obj.Pop() << endl;
	cout << Obj.Pop() << endl;
	cout << Obj.Pop() << endl;
	return 0;
}
