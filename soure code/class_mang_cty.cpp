#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Corporation
{
    private :

        string nameCorp; // ten cong ty
        string fromCorp; // dia chi cong ty
        int soNV; // So nhan vien
        double doanhThu;
    public :

        void InputCorp(); // nhap vao thong tin cong ty
        void OutputCorp(); // in ra thong tin cong ty
        void InputArr(); // nhap vao 1 mang cong ty
        void OutputArr(); // in ra 1 mang cong ty

};
int n; // khai cao so luong cong ty
Corporation corp[100]; // khai bao mang cong ty

void Corporation::InputCorp()
{
        cin>>nameCorp;
        cin>>fromCorp;
        cin>>soNV;
        cin>>doanhThu;
}
void Corporation::OutputCorp()
{

        cout<<"Corporation "<<nameCorp<<endl;
        cout<<"\t"<<fromCorp<<endl;
        cout<<"\t"<<soNV<<endl;
        cout<<"\t"<<doanhThu<<endl;
        cout<<endl;
}
void InputArr()
{
    ///freopen("data.txt","r",stdin);  // cach nhap khac du lieu tu file data.txt trong project
    cin>>n;
    for(int i=0;i<n;i++)
    {
        corp[i].InputCorp(); // goi ham nhap
    }
}
void OutputArr()
{
    for(int i=0;i<n;i++)
    {
        corp[i].OutputCorp(); // goi ham xuat
    }
}
int main()
{
    InputArr();
    OutputArr();

    return 0;
}
