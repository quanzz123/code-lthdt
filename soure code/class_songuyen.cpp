#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Interger
{
    private :
        int soNguyen;
        double arr[100];
    public :

        void InputArr() // nhap vao mang so nguyen
        {
            freopen("data1.txt","r",stdin); // cach nhap khac du lieu tu file data.txt trong project
            cin>>soNguyen;
            for(int i=0;i<soNguyen;i++)
            {
                cin>>arr[i];
            }
        }
        void Output() // in ra mang so nguyen
        {
            for(int i=0;i<soNguyen;i++)
            {
                cout<<"\t"<<arr[i];
            }
            cout<<endl;
        }
        void SelectionSoft() // ham sap xep lua chon
        {
            for(int i=0;i<soNguyen-1;i++)
            {
                int ma = i;
                for(int j=i+1;j<soNguyen;j++)
                {
                    if(arr[j]<arr[ma])
                    {
                        ma = j;
                    }
                }
                if(ma!=i)
                {
                    swap(arr[ma],arr[i]);
                }
            }
        }
        void Soft1(); // ham sap xep cua thay
        void MaxArr(); // max mang
        void MinArr(); // min mang
};
void Interger :: Soft1()
{
     for(int i=0;i<soNguyen-1;i++)
            {
                for(int j=i+1;j<soNguyen;j++)
                {
                    if(arr[j]<arr[i])
                    {
                        swap(arr[j],arr[i]);
                    }
                }
            }
}

void Interger :: MaxArr()
{
    cout<<endl;
    int max = arr[0];
    for(int i=1;i<soNguyen;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    cout<<"\t Max : "<<max<<endl;
}
void Interger :: MinArr()
{
    cout<<endl;
    int min = arr[0];
    for(int i=1;i<soNguyen;i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    cout<<"\t Min : "<<min<<endl;
}
int main()
{
    Interger itg; // khoi tao doi tuong so nguyen itg1
    itg.InputArr();
    itg.SelectionSoft();
    itg.Soft1();
    itg.Output();
    itg.MaxArr();
    itg.MinArr();


    return 0;
}
