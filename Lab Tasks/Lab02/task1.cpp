#include<iostream>
using namespace std;
 
template <typename T, typename W>
W add(T n1, W n2, T n3, W n4)
{
	return n1+n2+n3+n4;  
}
 
int main()
{
	cout<<"1) 1 + 2 + 1.1 + 1.2 = "<<add<int,float>(1,2,1.1f,1.2f)<<endl;
	cout<<"2) 1.1 + 1.2 + 1 + 2 = "<<add<int,float>(1.1f,1.2f,1,2)<<endl;
	cout<<"3) 1 + 2 + 3 + 4 = "<<add<int,int>(1,2,3,4)<<endl;
	cout<<"4) 1.2 + 2.2 + 3.3 + 4.4 = "<<add<float,float>(1.2f,2.2f,3.3f,4.4f)<<endl;

  return 0;
}

