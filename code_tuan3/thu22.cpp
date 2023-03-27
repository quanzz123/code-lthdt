#include"thuvien.h"
int main()

{
	point A;
	A.init(10,20);
	circle c;
	c.init(A,5);
	c.display();
	cout<<endl;
	system("pause");
}