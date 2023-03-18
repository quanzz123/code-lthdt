#include <conio.h>
#include <iostream>
using namespace std;
typedef struct
 {int ts,ms;}ps;

ps taophanso(int t, int m)
 {ps c;
  c.ts=t;
  c.ms=m;
  return c;
 }
//----------------------------------
void inphanso(ps a)
 {if ((a.ts==0)||(a.ms==1)) cout<<a.ts;
   else cout<<a.ts<<"/"<<a.ms;
 }
//------------------------------------
ps operator++(ps &a)
{
	
	a.ts=a.ts+a.ms;
	return a;
}
//=====================================
int operator>(ps a, ps b)
{
	
}
	
//=====================================
int main()
{
	ps x,y;
	x=taophanso(1,2);
	++x;
	cout<<"Phan so x = ";inphanso(x);
	cout<<endl;
	cout<<"\nPhan so ++x = ";inphanso(x);
	cout<<endl;
	system("pause");
}
