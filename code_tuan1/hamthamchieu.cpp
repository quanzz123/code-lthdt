#include <iostream>
#include <conio.h>
using namespace std;
int a=5;
int &f(int i)
{
	a+=i;
	return a;

}
//------------------
int main()
{
	//cout<<a<<"      "<<f(2); // xuat f(2) roi den xuat a
	cout<<f(2)<<"      "<<a; //xuat a roi den xuat f(2)
	cout<<a;
	cout<<endl;
	system("pause");
}
	
