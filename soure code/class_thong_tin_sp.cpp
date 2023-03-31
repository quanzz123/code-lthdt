#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hang
{
    private:
        string Mahang;
        string Tenhang;
        string Dongia;
    public:
        void Nhaphang();
        void Xuathang();
};
class Phieu
{
    private:
        string Maphieu;
        Hang H[50];
        int n;
    public:
        void Nhapphieu();
        void Xuatphieu();
};
void Hang::Nhaphang()
{
    // Nhập mã NSX
    cin>>Mahang;
    // Ten
    cin>>Tenhang;
    // Don gia
    cin>>Dongia;
}
void Phieu::Nhapphieu()
{
    freopen("data.txt","r",stdin);
    // Nhap so luong hang
    cin>>Maphieu;
    cin>>n;
    fflush(stdin);
    for(int i=0;i<n;i++)
    {
        H[i].Nhaphang();
    }
}
void Hang::Xuathang()
{
    cout<<"Ma Hang : "<<Mahang<<endl;
    cout<<"Ten Hang :"<<Tenhang<<endl;
    cout<<"Don Gia :"<<Dongia<<endl;
}
void Phieu::Xuatphieu()
{
    cout<<"Ma Phieu"<<Maphieu<<endl;
    for(int i=0;i<n;i++)
    {
        H[i].Xuathang();
    }
}
int main()
{
    Phieu p1;
    p1.Nhapphieu();
    p1.Xuatphieu();
    return 0;
}
