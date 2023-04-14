//Muhammad Ahmed Baig
//20i-1884
//Section C and (Lab Section D)
//Assignment 2

#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	char data;
	node* next;
};

class Stack
{
private:
	node* top;

public:
	Stack()
	{
		top = NULL;
	}

	char topVal()
	{
		return top->data;
	}

	void push(char newelement)
	{
		node* newptr;
		newptr = new node();
		newptr->data = newelement;
		newptr->next = top;
		top = newptr;
	}

	int pop()
	{
		/*
		if (IsEmpty())
		{
			cout << "underflow error";
			//return;
		}
		char value;
		node* temp = top;
		value = top->data;
		top = top->next;
		delete temp;*/
		node *tmp = new node();
    	int item;

    	if(top == NULL)
        {
        	cout << "underflow error";
		}

    	else if(top->next == NULL)
    	{
    	    tmp = top;
        	item = top->data;
        	top = NULL;
        	delete tmp;
    	}

    	else
    	{
        	tmp = top;
        	item = top->data;
        	top = top->next;
        	delete tmp;
    	}

    	return item;
	}

	bool IsFull()
	{
		node* n = new node();
		if (n == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void display()
	{
		node* p = top;
		while (p != NULL)
		{
			cout << p->data;
			p = p->next;
		}
	}


};


void input(char* arr, int s)
{
	for (int i = 0; i < s; i++)
	{
		arr[i] = '\0';
	}
	cout << "Please enter the Infix Expression: ";
	cin >> arr;
}

bool expression(char* Array, int stackSize)
{
	int count = 0;
	for (int i = 0; i < stackSize; i++)
	{
		if (Array[i] == '(')
		{
			count++;
		}
		else if (Array[i] == ')')
		{
			count--;
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int prec(char c)
{
	if (c == '%')
	{
		return 3;
	}
	else if (c == '^' || c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
/*
char* reverse(char *arr, int count)
{
	char* temp = new char[count];
	for (int i = 0; i < count; i++)
	{
		temp[i] = '\0';
	}
	int j = 0;
	for (int i = count-1; i > -1; i--)
    {
        temp[j] = arr[i];
        j++;
    }
    for (int i = 0; i < count; i++)
    {
        if(temp[i] == ')')
        {
          temp[i] = '(';
        }
        else if(temp[i] == '(')
        {
          temp[i] = ')';
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout<<temp[i];
    }
	return temp;
}

char* reverse(char *arr, int count)
{
	Stack st;
	char* temp = new char[count];
	for(int i=0; i<count; i++)
	{
		st.push(arr[i]);
	}
	for(int i=0; i<count; i++)
	{
		temp[i] = st.topVal();
		st.pop();
	}
	 for (int i = 0; i < count; i++)
    {
        if(temp[i] == ')')
        {
          temp[i] = '(';
        }
        else if(temp[i] == '(')
        {
          temp[i] = ')';
        }
    }
	return temp;
}

char* reverse2(char *arr, int count)
{
	Stack st;
	char* temp = new char[count];
	for(int i=0; i<count; i++)
	{
		st.push(arr[i]);
	}
	for(int i=0; i<count; i++)
	{
		temp[i] = st.topVal();
		st.pop();
	}
	return temp;
}*/

char* reverse(char *arr, int count)
{
	Stack st;
    char* temp = new char[count];

    for (int i = 0; i < count; i++)
    {
        st.push(arr[i]);
    }

    for (int i = 0; i < count; i++)
    {
        temp[i] = st.topVal();
        st.pop();
    }
    for (int i = 0; i < count; i++)
    {
        if (temp[i] == '(')
        {
            temp[i] = ')';
        }

        else if (temp[i] == ')')
        {
            temp[i] = '(';
        }

    }
    return temp;
    
    /*
	Stack st3;

    for (int i = 0; i < count; i++)
    {
        st3.push(temp2[i]);
    }
    for (int i = 0; i < count; i++)
    {
        temp3[i] = st3.topVal();
        st3.pop();
    }*/

}

/*
void evaluatePostFix(char* str,int count) 
{

	int value = 0;
	Stack obj;

	for (int i = 0; i < count; i++) 
	{

		char symb = str[i]; //Char from Expression

		if (symb >= '0' && symb <= '9') //Char is Digit

			obj.push(symb - '0');

		else {

			//Operand 1
			int x = obj.topVal();
			obj.pop();

			//Operand 2
			int y = obj.topVal();
			obj.pop();

			//Solving and Adding to Stack
			if (symb == '+')		
				obj.push(y + x);
			else if (symb == '-')	
				obj.push(y - x);
			else if (symb == '*')	
				obj.push(y * x);
			else if (symb == '/')	
				obj.push(y / x);
			else if (symb == '^')	
				obj.push(pow(y, x));
		}
	}

	value = obj.topVal(); //Last Value in Stack is the Answer

	cout<<"After evaluation the answer = "<<value;
}
*/

void infixtoPostfix(char* arr, int size, int count)
{
	
	Stack st;
	char* temp = new char[count];
	
	//char c;
	for (int i = 0; i < count; i++)
	{
		temp[i] = '\0';
	}
	int j=0;
	for (int i = 0; i < count; i++)
	{
		//c = arr[i];
		
		if (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= '0' && arr[i] <= '9')
		{
			temp[j] += arr[i];
			j++;
		}
		else if (arr[i] == '(')
		{
			st.push(arr[i]);
		}
		else if (arr[i] == ')')
		{
			while (st.topVal() != '(')
			{
				temp[j] += st.topVal();
				j++;
				st.pop();
			}
			st.pop();
		}
		else
		{
			while ((!st.IsEmpty()) && prec(st.topVal()) >= prec(arr[i]))
			{
				temp[j] += st.topVal();
				j++;
				st.pop();
			}
			st.push(arr[i]);
		}
	}
	int i=0;
    while (!st.IsEmpty())
    {
        temp[i] += st.topVal();
        i++;
        st.pop();
    }
    cout<<"Infix to PostFix: "; 
	bool check= false;
    for(int i=0;i<count;i++)
    {
      	if(temp[i] != '\0')
	  	{
    		cout<<temp[i];
    		check = true;
		}
    	if(temp[i] == '\0' &&check == true)
    	{
    		cout<<" ";
    		check = false;
		}
		if(temp[i] == '^' || temp[i]  == '*' || temp[i]  == '/' || temp[i] == '+' || temp[i] == '-' || temp[i] == '%')
		{
			cout<< " ";
		}
    }
    /*cout<<endl;
    cout<<endl;
    evaluatePostFix(temp,count);
    cout<<endl;
    */
}

void infixtoPrefix(char* arr,int size, int count)
{

    //Reversing 
	char* temp = new char[count];
	temp = reverse(arr,count);
	
    //Convertig to Postfix
    Stack st2;
    char* temp2 = new char[count];
    int j = 0;
    for (int i = 0; i < count; i++)
    {

        if (temp[i] >= 'a' && temp[i] <= 'z' || temp[i] >= 'A' && temp[i] <= 'Z' || temp[i] >= '0' && temp[i] <= '9')
        {
            temp2[j] += temp[i];
            j++;
        }
        else if (temp[i] == '(')
        {
            st2.push('(');
        }
        else if (temp[i] == ')') 
        {
            while (st2.topVal() != '(') 
            {
                temp2[j] += st2.topVal();
                j++;
                st2.pop();
            }
            st2.pop();
        }
        else 
        {
            while (!st2.IsEmpty() && prec(temp[i]) <= prec(st2.topVal())) 
            {
                temp2[j] += st2.topVal();
                j++;
                st2.pop();
            }
            st2.push(temp[i]);
        }

    }

    while (!st2.IsEmpty())
    {
        temp2[j] += st2.topVal();
        j++;
        st2.pop();
    }
    

    //Reversing
    char* temp3 = new char[count];
    temp3 = reverse(temp2,count);
     
    //Output
    cout << "Infix to PreFix: ";
    bool check = false;

    for (int i = 0; i < count; i++)
    {
        if (temp3[i] != '\0')
        {
            cout << temp3[i];
            check = true;
        }
        if (temp3[i] == '\0' && check == true)
        {
            cout << " ";
            check = false;
        }
        if (temp3[i] == '^' || temp3[i] == '*' || temp3[i] == '/' || temp3[i] == '+' || temp3[i] == '-' || temp3[i] == '%')
        {
            cout << " ";
        }
    }

}

int main()
{

	int size = 100;
	char* charArray = new char[size];

	//Taking input
	input(charArray, size);

	//Checking validation
	if (expression(charArray, size))
	{
		cout << "Valid Expression" << endl;
	}
	else
	{
		cout << "Invalid Expression" << endl;
		exit(0);
	}

	int count = 0;
	while (charArray[count] != '\0')
	{
		count++;
	}
	count= count+1;
	cout << "\nLength of the Input: "<<count<<endl<<endl;
	
	infixtoPrefix(charArray,size, count);
	cout<<endl<<endl;
	infixtoPostfix(charArray, size, count);
	return 0;
}

