#include<iostream>
using namespace std;

int main()

{
	int  arr[8] = { 4,1,3,5,2,7,9,6 };
	int temp;
	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp =arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	
return 0;
}
