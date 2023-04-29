#include <iostream>
#include <math.h>
using namespace std;
class point
{
	private:
		float x,y;
	public:
		point(float ox=0, float oy=0)
		{
			x=ox; y=oy;
		}
		void display()
		{
			cout<<"x = "<<x<<"   y =  "<<y<<endl;
		}
		friend float khoangcach(point a, point b);  //ban voi lop point
		//ham khoangcach khong phai la ham thanh phan cua lop point
};
//===================================================
float khoangcach(point a, point b) //dinh nghia
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); 
}
//===================================================
class line
{
	private:
		point a,b;
	public:
		line(point oa, point ob)
		{
			a=oa; b=ob;
		}
		void display()
		{
			a.display();  //a goi ham display cua point
			//cout<<a.x<a.y  //!OK
			b.display();  //b goi ham display cua point
			cout<<"Do dai = "<<khoangcach(a,b);
		}
};
//======================================================
//class triangle
//{
//	private:
//		point a,b,c;
//	public:
//		....
//======================================================
int main()
{
	point u(10,10), v(20,20);
	line l(u,v);
	l.display();
	cout<<endl;
}
