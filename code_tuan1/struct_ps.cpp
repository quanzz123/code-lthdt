#include"iostream"

using namespace std;
typedef struct
{
    int ts;
    int ms;
}ps;    
ps taops(int m, int n)
{
    ps c;
    c.ts = m;
    c.ms = n;
    return c;
}
void xuatps(ps a)
{
    if((a.ts == 0) || (a.ms == 1)) cout << a.ts;
    else cout << a.ts << "/" << a.ms;
    

}
ps operator+(ps a, ps b)
{
    ps c;
    c.ts = a.ts*b.ms + b.ts*a.ms;
    c.ms = a.ms*b.ms;
    return c;      

}
ps operator-(ps a, ps b)
{
    ps c;
    c.ts = a.ts*b.ms + b.ts*a.ms;
    c.ms = a.ms*b.ms;
    return c;
}
int main()
{
    
    ps x,y,z,t;
    x = taops(2,5);
    y = taops(4,5);
    z = x+y;
    t = x+y;

    xuatps(x); cout << "\t+\t"; xuatps(y); cout << "\t=\t"; xuatps(z);
    cout << endl;
    xuatps(x); cout << "\t-\t"; xuatps(y); cout <<"\t=\t"; xuatps(t);
    cout << endl;
    
    return 0;
}

