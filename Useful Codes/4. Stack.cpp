#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> stack)
{
	while(!stack.empty())
	{
		cout<<stack.top()<<endl;
		stack.pop();
	}
}


int main()
{
	//empt size push pop top
	stack<int>numbersStack;
	numbersStack.push(1);
	numbersStack.push(2);
	numbersStack.push(3);
	numbersStack.pop();
	/*numbersStack.pop();
	numbersStack.pop();
	*/
	
	print(numbersStack);
	/*
	if(numbersStack.empty())
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		cout<<"Stack is not empty"<<endl;
	}
	cout<<"Size of Stack is: "<<numbersStack.size()<<endl;
	*/return 0;
}
