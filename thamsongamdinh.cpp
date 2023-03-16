#include "iostream"

using namespace std;
float dientich (float a=1, float b=2)
{
    return a*b;

}
float chuvi (float a, float b=1)
{
    return (a+b)*2;
}
int main()
{
    cout << "\ndien tich: " << dientich() << endl;
    cout << "dien tich: " << dientich(3) << endl;
    cout << "chuvi: " << chuvi(3) << endl;
    cout << "chu vi: " << chuvi(2,3) << endl;
    cout << "dien tich: " << dientich(4,5) << endl;

}
