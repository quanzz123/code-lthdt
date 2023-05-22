#include<iostream>
#include<conio.h>
using namespace std;
class point
{
	private:
    	float x, y;
   	public:
    	point(float ox =0, float oy=0)
	 	{
		 	x=ox; y=oy;
		}

      	void virtual display()
	 	{
		 	cout<<"\n x ="<<x<<" y ="<<y;
		}
};
//==========================================================================
class coloredpoint : public point
{
	private:
    	int color;
   	public:
	   	coloredpoint(float ox=0, float oy=0, int c=0):point(ox,oy)
        {
			color = c;
		}
     	void display()
        {
			point::display();
          	cout<<" color ="<<color;
    	}
};
//-----------------------------------------------------------------------------------------
int main()
{
	coloredpoint m(1,2,3);       //  Khai bao doi tuong coloredpoint.
    point p(4,5);	        // Khai bao doi tuong point.  	
	point *ptr;	              // Khai bao con tro ptr kieu  point.
   	ptr = &p;	            // Cho ptr tro den p.
   	ptr->display();	          // Goi ham display cua lop point.     4   5
   	ptr = &m;	        // Cho ptr tro den m.	
   	ptr->display();	      // Goi ham display cua point.           1  2   3  
	cout<<endl;
	system("pause");
}
