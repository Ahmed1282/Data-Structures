#include<iostream>
using namespace std;

template <typename T, typename U, typename V>
class W
{
	private:
		T x;
		U y;
		V z;
	
	public:
		
		void setData(T x1, U y1, V z1)
		{
			x = x1;
			y = y1;
			z = z1;
		}
		
		T getx()
		{
			return x;
		}
		
		U gety()
		{
			return y;
		}
		
		V getz()
		{
			return z;
		}
		
};


int main()
{

	cout<<"Part 1"<<endl;
	W <int,float,double> obj;
	obj.setData(4,5.5f,6.666);
	cout<<obj.getx()<<endl;
	cout<<obj.gety()<<endl;
	cout<<obj.getz()<<endl;
	cout<<endl;
	
	cout<<"Part 2"<<endl;
	W <float,int ,double> obj2;
	obj2.setData(5.5f,4,6.666);
	cout<<obj2.getx()<<endl;
	cout<<obj2.gety()<<endl;
	cout<<obj2.getz()<<endl;
	cout<<endl;
	
	cout<<"Part 3"<<endl;
	W <int,double,float> obj3;
	obj3.setData(4,6.666,5.5f);
	cout<<obj3.getx()<<endl;
	cout<<obj3.gety()<<endl;
	cout<<obj3.getz()<<endl;
	cout<<endl;
	return 0;
}
