#include"iostream"
using namespace std;
void nhap(int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            cout << " ";
        }
        for(int j=1; j<=i; j++)
        {
            cout << i << " ";

        }
        cout << endl;
    }
    
}
int main()
{
    int n;
    cout << "\nnhap n tu ban phim: ";
    cin >>n;
    nhap(n);
    return 0;
}
// sử dụng vong lặp đâu tiền để in số hàng
// sử dụng vòng lặp thứ hai đê in ra i sô trên i hàng
// trong vong lặp thứ hai ta sử dụng cout << " " để tạo ra dấu cách giữa cac số trong hàng