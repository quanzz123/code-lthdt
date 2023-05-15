#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
class Mytime
{
	protected:
   		int h,m,s;
  	public:
    	Mytime(int hh=0,int mm=0,int ss=0)
		{
			h=hh;m=mm;s=ss;
		}
    	void nhap()
      	{
		  	cout<<"Nhap gio, phut, giay: ";cin>>h>>m>>s;
      	}
   		void display()
     	{
		 	cout<<"    "<<h<<":"<<m<<":"<<s;
		}
	
 }; //het lop
 //========================================================
class Mydate
{
	protected:
    	int d,m,y;
	public:
     	Mydate(int dd=1,int mm=1,int yy=1)
      	{
		  	d=dd;m=mm;y=yy;
		}
    	void nhap()
     	{
		 	cout<<"Nhap ngay, thang, nam: ";cin>>d>>m>>y;
     	}
    void display()
     	{
			cout<<"   "<<d<<"-"<<m<<"-"<<y;
     	}
 };
 //========================================================

class Myfile:public Mydate,public Mytime
{
	private:
   		string fname;
   		int fsize;
    public:
   		Myfile(int a=0,int b=0,int c=0,int d=1,int e=1,int f=1,string fn=NULL,int fs=0):Mytime(a,b,c),Mydate(d,e,f)
     	{
		 	fname=fn;
			fsize=fs;
		}
		void nhap()
		{
			cout<<"\n\nNhap ten file: "; cin.ignore();getline(cin,fname);
			cout<<"Nhap kich co: ";cin>>fsize;
			Mytime::nhap();
			Mydate::nhap();
		}
    	void display()
     	{
		 	cout<<"\n"<<setw(20)<<fname;
      		cout<<"  "<<fsize;
      		Mytime ::display();
      		Mydate::display();
     	}
     	int operator>(Myfile b)
     	{
     		if (fsize>b.fsize) return 1;
     		return 0;
		}
};
 //========================================================
 
int main()
{
	Myfile *s[20],*tg;
	int a,b,c,d,e,f,fs;
	string fn;

	freopen("dulieu.txt","r",stdin);
	freopen("kq.txt","w",stdout);

	int n=0;
	while(true)
	{
		fn = "";
		cin>>fn;
		if (fn.size()==0) break;
		string fn1;
		getline(cin, fn1);
		fn += fn1;
		cin >> fs;
		cin>>a>>b>>c; 
		cin>>d>>e>>f;
		s[n]=new Myfile(a,b,c,d,e,f,fn,fs);	
		n++;
	}
	cout<<"---------------------DANH SACH BAN DAU---------------------\n\n";
	for(int i=0;i<n;i++)
	{
		s[i]->display();
	}
	
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if (*s[i]>*s[j])
			{
				tg=s[i];
				s[i]=s[j];
				s[j]=tg;
				
			}
	cout<<"\n\n";
	cout<<"-----------------DANH SACH SAU KHI SAP XEP-----------------\n\n";
	for(int i=0;i<n;i++)
		s[i]->display();

	cerr<<"----CHUONG TRINH DA HOAN THANH----";	
	getch();
	return 0;	
}
