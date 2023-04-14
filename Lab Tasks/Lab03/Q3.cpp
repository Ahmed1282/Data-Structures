#include<iostream>
using namespace std;

int main()
{
	double n1,n2;
	double arr[3][2] = {{1,2.1}, {3,4.9} , {5,5}};
	for(int i = 0 ; i<3; i++)
	{
		for(int j=0; j<1; j++)
		{
			n1 = arr[i][j] / arr[i][j+1];
			n2 = arr[i][j+1] / arr[i][j];
			if((n1 >= 1.6 && n1 <= 1.7) || (n2 >= 1.6 && n2 <= 1.7))
			{
				cout<<"its golden ratio"<<endl;
			}
			else
			{
				cout<<"its not a golden ratio"<<endl;
			}
		}
	}
}
