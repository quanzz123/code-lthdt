#include"iostream"

using namespace std;

float kiemtra(float a, float b, float c=1)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main()
{
    float a,b,c;
    cout << "\nnhap a, b,c: ";
    cin >> a >> b >> c;
    if(kiemtra(a,b,c))
    {
        cout << "a,b,c tao thanh mot tam giac" << endl;
    }
    else 
    {
        cout << "a,b,c khong phai la ba canh cua tam giac" << endl;
    }


}