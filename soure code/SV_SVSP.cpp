#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;
class SV
{
	protected:
		string hoten; //hoac char *hoten; hoac char hoten[30];
		string lop;	//hoac char *lop; hoac char lop[10];
	public:
		SV()
		{
			hoten="";
			lop="";
		}
		SV(string h, string l)
		{
			hoten=h;
			lop=l;
		}
		void add()
		{
			fflush(stdin);
			cout<<"\nNhap hoten: "; getline(cin,hoten);
			cout<<"Nhap lop: "; fflush(stdin); getline(cin,lop);
		}
		SV (SV &a)
		{
			hoten=a.hoten;
			lop=a.lop;
		}
		void display()
		{
			cout<<setw(30)<<hoten<<setw(10)<<lop;
		}
}; //
//=================================================
class SVSP:public SV
{
	protected:
		float dtb,hocbong;
	public:
		SVSP():SV()
		{
			dtb=0;
			hocbong=0;
		}
		SVSP(string h, string l, float d, float hb):SV(h,l)
		{
			dtb=d;
			hocbong=hb;
		}
		SVSP (SVSP &a):SV ((SV&)a)
		{
			dtb=a.dtb;
			hocbong=a.hocbong;
		}
		void display() //Dinh nghia lai
		{
			SV::display();
			cout<<"     "<<dtb<<"     "<<hocbong;
		}	
		void add()  //Dinh nghia lai
		{
			SV::add();
			cout<<"Nhap diem trung binh: "; cin>>dtb;
			cout<<"Nhap hoc bong: "; cin>>hocbong;
		}
};
//=================================================
class SVCN:public SVSP
{
	protected:
		float hocphi;
	public:
		SVCN():SVSP()
		{
			hocphi=0;
		}
		SVCN(string h, string l, float d, float hb, float hp):SVSP(h,l,d,hb)
		{
			hocphi=hp;
		}
		SVCN (SVCN &a):SVSP ((SVSP&)a)
		{
			hocphi=a.hocphi;
		}
		void display()
		{
			SVSP::display();
			cout<<"     "<<hocphi;
			cout<<endl;
		}	
		void add()
		{
			SVSP::add();
			cout<<"Nhap hoc phi: "; cin>>hocphi;
		}
};
//=================================================

int main()
{	
	SVCN s[3];  
	for(int i=0;i<3;i++)
		s[i].add();
	for(int i=0;i<3;i++)
		s[i].display();
	
	//SVCN *s;
	//s=new SVCN[3];
	
	//SVCN *s[3];
}
