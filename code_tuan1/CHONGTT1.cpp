#include <iostream>
using namespace std;
typedef struct
{
	int ts,ms;
}ps;

ps taophanso(int t, int m)
{
	ps c;
  	c.ts=t;
  	c.ms=m;
  	return c;
}
//----------------------------------
ps cong(ps a, ps b) 
{
	ps c;
  	c.ts  =  a.ts*b.ms + a.ms*b.ts;
  	c.ms =  a.ms*b.ms;
  	return c;
}

//----------------------------------
ps tru(ps a, ps b) 
{
	ps c;
  	c.ts  =  a.ts*b.ms - a.ms*b.ts;
  	c.ms =  a.ms*b.ms;
  	return c;
}
//----------------------------------
ps dao_dau(ps a)
{
	a.ts=-a.ts;
  	return a;
}
//-----------------------------------  
void inphanso(ps a)
{
	if ((a.ts==0)||(a.ms==1)) cout<<a.ts;
   	else cout<<a.ts<<"/"<<a.ms;
}
//------------------------------------
int main()
{
	ps x,y,z,t;
  	x=taophanso(1,2);
  	y=taophanso(3,4); 
  	z=cong(x,y);//Goi ham cong
  	t=tru(x,y);//Goi ham tru 
  	inphanso(x);cout<<"   +   ";inphanso(y);cout<<"  =  ";inphanso(z);
	cout<<"\n\n";
  	inphanso(x);cout<<"   -   ";inphanso(y);cout<<"  =  ";inphanso(t);
}
