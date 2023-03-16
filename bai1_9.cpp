#include "iostream"

using namespace std;

void doi( float& a, float& b)
{
    int tg;
    tg = a;
    a = b;
    b = tg;

}
int main()
{
    float x,y;
    cout << "\nx= ";
    cin >> x;
    cout << "\ny= ";
    cin >> y;
    cout << "\ntruoc khi doi: x= " << x << " y= " << y << endl;
    doi(x, y);
    cout << "\nsau khi doi: x= " << x << " y= " << y << endl;
    return 0;
}
