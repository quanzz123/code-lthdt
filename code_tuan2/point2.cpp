#include <iostream>
using namespace std;
class point
{	private:
     	float x,y;
	public:
       	void init(float ox, float oy) 
       	{
       		x=ox; y= oy;
       	}
       	void move(float dx, float dy);
     	   void display();			
   };  
  
    void point::move(float dx, float dy) 
       {x+= dx; y+= dy;}

    void point::display() 
       {cout<<"\n Toa do x= "<<x<<"   Toa do y  = "<<y;}
int main() 
   {
    point p;	
    p.init(2,3);	
    p.display();
    p.move(3,4);
    p.display();
    point q;
    q.init(10,20);
    q.display();
	cout<<endl;
	system("pause");
  }
