#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class NSX
{
    private :
        string Mansx; // mã nhà sản xuất
        string Tennsx; // Tên nhà sản xuất
        string Dcnsx; // Địa chỉ
    public:
        void NhapNSX();
        void XuatNSX();
};
class Hang
{
    private:
        string Mahang;
        string Tenhang;
        NSX x;
    public:
        void Nhaphang();
        void Xuathang();
};
void NSX::NhapNSX()
{
    // Nhập mã NSX
    cin>>Mansx;
    // Ten
    cin>>Tennsx;
    // Dia chi
    cin>>Dcnsx;

}
void Hang::Nhaphang()
{
    freopen("data.txt","r",stdin);
    // Nhập mã NSX
    cin>>Mahang;
    // Ten
    cin>>Tenhang;
    // Dia chi
    x.NhapNSX();
}
void NSX::XuatNSX()
{
    cout<<"| MA NXS : "<<Mansx<<"| TEN NSX : "<<Tennsx<<"| Dia Chi : "<<Dcnsx<<endl;
}
void Hang::Xuathang()
{
    cout<<"MA HANG : "<<Mahang<<"| TEN HANG : "<<Tenhang<<endl;
    x.XuatNSX();
}

int main()
{
    Hang h1;
    h1.Nhaphang();
    h1.Xuathang();

    return 0;
}
