#include<iostream>
using namespace std;

int main()
{
	char arr[7] = {'z', 'D', 'v','L','a', 'G', 'T'};
	int temp;
	
	for(int i= 0; i<7; i++)
	{
		for(int j = 0; j<6 ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}

	}
	
	for(int i=0; i<7; i++)
	{
		cout<<arr[i]<<" , ";
	}
	return 0;
}
