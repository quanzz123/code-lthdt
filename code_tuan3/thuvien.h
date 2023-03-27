#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
class point{
	private:
     	float x, y;
   	public:
        void init(float ox, float oy)
        	{x=ox; y=oy;}
     	void move(float dx, float dy)
     		{x+= dx; y+= dy;}
     	void display()		
	 		{cout<<"\nToa do x= "<<x<<"   Toa do y  = "<<y;}	
}; //Ket thuc lop point
//--------------------
class circle{
	private:
		float r;
		point O;
	public:
		void init(point A, float k)
		{O=A; r=k;}
		void display(){
			cout<<"\n\nr ="<< r;
			O.display();   //OK 
			//cout<<O.x<<O.y;//!OK v� x, y  private 	
			cout<<"\nChu vi = "<<chuvi();
			cout<<"\nDien tich = "<<dientich();
		}  
		void move(float dx, float dy)
      		{O.move(dx,dy);}
     	
      	float chuvi()
      	{
      		return 2*M_PI*r;	
		}
		float dientich()
		{
			return M_PI*r*r;
		}  	
};//Ket thuc lop circle