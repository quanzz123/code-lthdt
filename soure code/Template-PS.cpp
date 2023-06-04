#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
class  PS
{
	private:
		int ts,ms;
	public:
		PS(int t=0, int m=1)
		{
			ts=t; ms=m;
		}
		void add() //nen lam chong tt >>
		{
			cout<<"Nhap Tu so va Mau so: ";cin>>ts>>ms;
		}
		int operator>(PS a)
		{
			if (ms<0) 
				{ts=-ts;ms=-ms;}
			if (a.ms<0)
				{a.ts=-a.ts;a.ms=-a.ms;}
			if (ts*a.ms>a.ts*ms) return 1;
			return 0;
		}
		void display() //nen lam chong toan tu <<
		{
			if ((ts==0)||(ms==1)) cout<<ts;
			else cout<<ts<<"/"<<ms; cout<<"    ";
		}
};

//=====================================
template <class T>
T max(T a[], int n)
{
	T m=a[0];  //Neu T la PS thi m tu dong goi HTLSC ngam dinh
	for(int i=1;i<n;i++)
	{
		if (a[i]>m) //Neu T la PS thi su dung toan tu > cua PS
			m=a[i];//Neu T la PS thi m tu dong goi PGDT ngam dinh
	}
	return m;
}
//===================================
int main()
{
	int a[10];
	int n,i;
	cout<<"\nNhap n=";cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
	cout<<"\nMax:"<<max(a,n);
 	
	float b[10];
	int t;

	cout<<"\nNhap t=";cin>>t;
	for (i=0;i<t;i++)
	{
		cout<<"b["<<i<<"]="; cin>>b[i];
	}
	cout<<"\nMax:"<<max(b,t);
	cout<<endl<<endl;
	
	PS p[10];
	int u;
	cout<<"\nNhap u=";cin>>u;
	for(i=0;i<u;i++)
		p[i].add();
	for(i=0;i<u;i++)
		p[i].display();
	cout<<"\nMax:";
	PS m = max(p,u); //Su dung HTLSC ngam dinh
	m.display();
	//SV bo sung lop Mydate, Mytime va su dung mo hinh cho 
	//cac mang Mydate, Mytime
	cout<<endl<<endl;
}
