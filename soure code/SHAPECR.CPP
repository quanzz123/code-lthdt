#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;
class Shape  //Lop co so truu tuong
{
	public:
    	float virtual dientich()
	  	{
		  	return 0;
		}
		float virtual chuvi()
	  	{
		  	return 0;
		}
        void virtual nhap() 
	   	{
	   	}
       void display()
	  	{
		  	cout<<"\n Dien tich = "<<dientich()<<"   "<<"Chu vi = "<<chuvi();
		}
  };
//------------------------------------------------------------------------
class Circle:public Shape
{	private:
       	float r;
   	public:
    	Circle(float ar=1) 
		{
			r=ar;
		}
    	void nhap()
	 	{
		 	cout<<"Nhap ban kinh hinh tron r = ";cin>>r;
		}
    	float dientich()
	 	{
		 	return M_PI*r*r;
		}
		float chuvi()
	 	{
		 	return 2*M_PI*r;
		}
};
//-------------------------------------------------------------------------
class Rectangle:public Shape
{
	private:
      	float a,b;
    public:
      	Rectangle(float oa=0, float ob=0) 
		{
		  	a=oa; 
			b=ob;
		}
      	void nhap()
	 	{
		 	cout<<"Nhap canh a = ";cin>>a;
	  		cout<<"Nhap canh b = ";cin>>b;
	 	}
     	float dientich()
	 	{
		 	return a*b;
		}
		float chuvi()
	 	{
		 	return 2*(a+b);
		}
  };
//-------------------------------------------------------------------------
int main()
{	
	Shape *s[5];
	int i;
   	for(i=0;i<5;i++)
    {
		s[i]= new Circle[1];
		s[i]->nhap();
	}
   	for(i=0;i<5;i++)
       s[i]->display();
	cout<<endl;
	Shape *t[5];
	for(i=0;i<5;i++)
    {
		t[i]= new Rectangle[1];
		t[i]->nhap();
	}
   	for(i=0;i<5;i++)
       t[i]->display();
	
	//SV tu bo sung cac toan tu so sanh
	//sap xep danh sach theo thu tu tang giam  	
}
   
