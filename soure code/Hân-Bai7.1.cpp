#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;
class MyAddress
{
	protected:
		string Tinh;
		string Huyen;
	public:
		MyAddress()
		{
			Tinh="";
			Huyen="";
		}
		MyAddress(string t, string h)
		{
			Tinh=t;
			Huyen=h;
		}
		void add()
		{
			cout<<"Nhap tinh: ";fflush(stdin);getline(cin,Tinh);
			cout<<"Nhap huyen: ";fflush(stdin);getline(cin,Huyen);
		}
	
		MyAdress(MyAddress &a)
		{
			Tinh=a.Tinh;
			Huyen=a.Huyen;
		}
		void display()
		{
			cout<<setw(15)<<Tinh<<"|"<<setw(15)<<Huyen<<"|";
		}

};

class Person:public MyAddress
{
	protected:
		string Name;
		string Phone;
	public:
		Person():MyAddress()
		{
			Name="";
			Phone="";
		}
		Person(string t, string h, string n, string p):MyAddress(t,h)
		{
			Name=n;
			Phone=p;
		}
		void add()
		{
			MyAddress::add();
			cout<<"Nhap ten: ";fflush(stdin);getline(cin,Name);
			cout<<"Nhap so dien thoai: ";fflush(stdin);getline(cin,Phone);
		}
		Person(Person &a):MyAddress((MyAddress&)a)
		{
			Name=a.Name;
			Phone=a.Phone;
		}
		void display()
		{
			MyAddress::display();
			cout<<setw(20)<<Name<<"|"<<setw(15)<<Phone<<"|";
		}
		
};
class Officer:public Person
{
	protected:
		unsigned long long Salary;
	public:
		Officer():Person()
		{
			Salary=0;
		}
		Officer(string t, string h, string n, string p, unsigned long long s):Person(t, h, n, p)
		{
			Salary=s;
		}
		void add()
		{
			Person::add();
			cout<<"Nhap luong: ";cin>>Salary;
		}
		Officer(Officer &a):Person((Person&)a)
		{
			Salary=a.Salary;
		}
		void display()
		{
			Person::display();
			cout<<setw(10)<<Salary<<"|"<<endl;
		}
		
		friend operator >(Officer &a, Officer &b);
};
operator >(Officer &a, Officer &b)
{
	if(a.Salary>b.Salary)
		return 1;
	return 0;
}
int main()
{
	Officer s[100], tg;
	int n;
	cout<<"Nhap so nguoi: ";cin>>n;
	for(int i=0; i<n;i++)
	{
		cout<<"\nPhan tu thu "<<i+1<<endl;
		s[i].add();
	}
	cout<<"\n   ==================================Danh sach ban dau================================="<<endl;
	cout<<"    ___________________________________________________________________________________\n";
	cout<<"   |STT|      Tinh     |      Huyen    |        Ten         |      SDT      |   Luong  |\n";
	cout<<"   |---|---------------|---------------|--------------------|---------------|----------|\n";
	for(int i=0;i<n;i++)
	{
		cout<<"   |"<<setw(2)<<i+1<<" |";s[i].display();
	}
	cout<<"   |___|_______________|_______________|____________________|_______________|__________|\n";
	cout<<"\n";
	tg=s[0];
	for(int i=0;i<n;i++)
		for(int j = i + 1; j < n; j++)
		{
       		if(s[j] > s[i])
			{
            	tg = s[i];
            	s[i] = s[j];
            	s[j] = tg;        
            }
        }
	cout<<"\n   ===========================Mang phan so sap xep tang dan============================"<<endl;
	cout<<"    ___________________________________________________________________________________\n";
	cout<<"   |STT|      Tinh     |      Huyen    |        Ten         |      SDT      |   Luong  |\n";
	cout<<"   |---|---------------|---------------|--------------------|---------------|----------|\n";
	int d=1;
	for(int i=n-1;i>=0;i--)
	{
		cout<<"   |"<<setw(2)<<d++<<" |";s[i].display();
	}
	cout<<"   |___|_______________|_______________|____________________|_______________|__________|\n";
}





