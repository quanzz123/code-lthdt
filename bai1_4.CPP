#include"iostream"
using namespace std;
void nhapmang2(int a[][50], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
           cout << "Nhap gia tri phan tu [" << i << "][" << j << "]: "; 
            cin >> a[i][j];
        }

    }
}
void inmang2( int a[][50], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << a[i][j] << "\t ";
        }
        cout << endl;
    }
}
void dem( int a[][50], int n, int m)
{
    int demsoam =0;
    int demsoduong= 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] > 0)
                demsoduong++;
            else if(a[i][j] < 0)
                demsoam++;
        }
    }
    cout << "\nso phan tu duong trong mang la: " << demsoduong << endl;
    cout << "\nso phan tu am trong mang la: " << demsoam << endl;

}
void chuyenVi(int a[][50], int n, int m)
{
    cout << " \nma tran chuyen vị la: " << endl;
    int an;
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            an =a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = an;

        }
    }
}
int main()
{
    int n,m;
    cout << "\nnhap so hang: ";
    cin >> n;
    cout << "\nnhao so cot: ";
    cin >> m;
    int a[n][50];
    nhapmang2(a,n,m);
    inmang2(a,n,m);
    dem(a, n , m);
    chuyenVi(a,n,m);
    inmang2(a,n,m);
    return 0;
}