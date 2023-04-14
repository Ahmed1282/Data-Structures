#include <iostream>
using namespace std;

void swapping(int*a , int*b);


int main()
{
	int array[3][3]={3,5,9,4,5,4,9,7,7};

	cout << "The Matrix before sorting is= "<< endl;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//First Row Selection sort in Ascending Order
	int a=0, min;
		for (int b = 0; b < 3-1; b++)
		{
			min = b;
			
			for (int k = a + 1; k < 3; k++)
				if (array[a][k] < array[a][min])
					min = k;
			swapping(&array[a][min], &array[a][b]);
		}

		//Now Selection Sort for 1st row in Descending Order
		
		int max;
		for (int b = 0; b < 3-1; b++)
		{
			max = b;
			for (int k = b + 1; k < 3; k++)
				if (array[1][k] > array[1][max])
					max = k;
			swapping(&array[1][max], &array[1][b]);
		}

		a = 3;
	//Now for 3rd Row, doing Insertion Sort
		a = 2;
		int key;
		for (int k = 0; k < 3; k++)
		{
			key = array[a][k];
			int n = k - 1;
			while (n >= 0 && array[a][n] > key)
			{
				array[a][n + 1] = array[a][n];
				n = n - 1;
			}
			array[a][n + 1] = key;
		}
		cout << "The Matrix after sorting is="<<endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << array[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
}

void swapping(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
