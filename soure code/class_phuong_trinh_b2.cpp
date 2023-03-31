#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class PTB2
{
    private:
        int a,b,c;
    public:
        PTB2()
        {
            a=0;
            b=0;
            c=0;
        }
        PTB2(int a,int b,int c)
        {
            this->a=a;
            this->b=b;
            this->c=c;
        }
        void XulyKQ();
};

void PTB2::XulyKQ()
{
    cout<<a<<"X^2 + "<<b<<"X = "<<c<<endl;
    int denta;
    denta = b*b-4*a*c;
    if(denta<0)
        cout<<"PT Vo No"<<endl;
    else if(denta == 0)
        cout<<"PT co 1 No"<<(-b/2*a);
    else{
        cout<<"PT co 2 No:"<<endl;
        cout<<"X1 = "<<((-b+sqrt(denta))/2*a)<<endl;
        cout<<"X2 = "<<((-b-sqrt(denta))/2*a)<<endl;
    }

}
void Input()
{
    int x=0,y=0,z=0;
    freopen("data.txt","r",stdin);
    cin>>x;
    cin>>y;
    cin>>z;
    PTB2 pt(x,y,z);
    pt.XulyKQ();
}
int main()
{
    Input();
    return 0;
}
