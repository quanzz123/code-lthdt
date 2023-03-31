#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
///#include <bits/stdc++.h> /// cái này cân hết thư viện :3
using namespace std;

//Ham Nhap
void nhapmang(int n, int a[100])
{
    int i;
    for (i=0; i<n; i++)
    {
        cout << "A["<<i<<"] = ";
        cin >> a[i];
    }

/// Tham khảo thêm
/*
int n, a[100];
void Input ()
{
    freopen("Data.txt","r",stdin);
    cin >>n;
    for (i=0; i<n; i++)
    {
        cin >> a[i];
    }
}
*/
//ham hien thi mang
void htmang(int n,int a[100])
{
    int i;
    for (i=0; i<n; i++)
    {
        cout << "  A["<<i<<"] = "<<a[i];
    }
}
//ham tim max trong mang'
void maxmang(int n, int a[100])
{
    int i, ma, dem ;
    ma = a[0];
    for(i=0; i<n; i++)
    {
        if(a[i]>ma)
        {
            ma = a[i];
            dem = i +1 ;
        }
    }
    cout << "\nPT thu "<<dem<<" la max co gia tri la : "<<ma;
}
// ham tim min trong mang
void minmang(int n, int a[100])
{
    int i, mi, dem ;
    mi = a[0];
    for(i=0; i<n; i++)
    {
        if(a[i]<mi)
        {
            mi = a[i];
            dem = i +1 ;
        }
    }
    cout << "\nPT thu "<<dem<<" la min co gia tri la : "<<mi;
}

// ham sap xep theo phuong phap noi bot
void sapxep(int n, int a[100])  // tang dan
{
    for (int i=0; i<n; i++)
    {
        for (int j=n-1; j>=i; j--)
        {
            if(a[j]<a[j-1])
            {
                int tg;
                tg = a[j];
                a[j]= a[j-1];
                a[j-1]=tg;
            }
        }
    }
}

// ham chen phan tu

void chenx(int &n,int a[100],int k,int x)
{
    for(int i=n; i>=k; i--)
    {
        a[i]=a[i-1];
    }
    a[k-1]=x;
    n++;
}
void xoay (int &n,int a[100], int  y)
{
    for (int i=y; i<n; i++)
    {
        a[i-1]=a[i];
    }
    n--;
}
void maxam(int n,int a[100])
{
    int i=0;
    while (i<n&&a[i]>=0) i++;
    if(i==n)cout << "\n K co so am trong mang ";
    else
    {
        int ma = a[i];
        for(int j=i+1; j<n; j++)
            if(a[j]<0&&a[j]>ma)
                ma=a[j];
        cout << " \n max am : "<<ma;
    }

}
void minduong(int n,int a[100])
{
    int i=0;
    while (i<n&&a[i]<=0)i++;
    if(i==n)cout << "\n Khong co so duong trong mang ";
    else
    {
        int mi=a[i];
        for(int j=i+1; j<n; j++)
        {
            if(a[i]<mi)
            {
                mi=a[i];
                // d = 1;
            }

        }
        cout << " \n So duong min la : "<<mi;
    }
}
void chenptdau(int &n,int a[100],int x)
{
    for(int i=n; i>0; i--)
        a[i]=a[i-1];
    a[0]=x;
    n++;
}
void chenptcuoi(int &n,int a[100],int x)
{
    a[n]=x;
    n++;
}

void bai1sbt(int n,int a[100])
{
    a[0]=1;
    a[1]=1;
    int t=0;
    for(int i=2; i<n; i++)
    {
        if(i>=2)
        {
            a[i]=a[i-1]+a[i-2];
            t = t+a[i];
        }
    }
    cout << "\n Tong cac phan tu trong mang : "<<t;
}
void bai2sbt (int n,int a[100])
{
    int ta=0,gi=0,b=0;
    for(int i=0; i<=n-2; i++)
    {
        if(a[i]<a[i+1])
            ta++;
        else
        {
            if(a[i]>a[i+1])
                gi++;
            else
            {
                if(a[i]==a[i+1])
                    b++;
            }
        }
    }
    if(ta==0&&b==0)
        cout << "\n Mang giam thuc su ";
    else
    {
        if(gi==0&&b==0)
            cout << "\n Mang tang thuc su";
        else
        {
            if(ta==0&&b>0)
                cout << " \n Mang giam dan";
            else
            {
                if(gi==0&&b>0)
                    cout << "\n Mang tang dan ";
                else
                {
                    cout << "\n Mang khong co trat tu ";
                }
            }
        }
    }
}
void bai3sbta(int n,int a[100])
{
    cout << " \n Vi tri so chia het cho 3 : ";
    for(int i=0; i<n; i++)
    {
        if(a[i]%3==0)
            cout << "  "<<i;
    }
}
void bai3sbtb(int n,int a[100])
{
    int d=0;
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>=i; j--)
        {
            if(a[i]%2==0)
            {
                d++;
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0; i<=d-1; i++)
    {
        for(int j=i+1; j<=d; j++)
        {
            if(a[i]<a[j])
            {

                swap(a[i],a[j]);
            }
        }
    }

}
void bai4sbta(int n,int a[100])
{
    int t=0,d=0;
    cout << "\n Cac so co TTD > 5 la : ";
    for (int i=0 ; i<n; i++)
    {
        if(a[i]<-5&&a[i]*-1>5)
        {
            cout << " "<<a[i];
            d++;
            t = t+a[i];
        }
    }
    if(d>0)
        cout << " \n Tong cua cac so do la : "<<(t/d);
    else
        cout << " \n trong mang khong co so thoa man : ";
}
void bai4sbtb(int &n,int a[100])
{
    int k;
    cout << " \n Nhap vi tri can xoa : ";
    cin>>k;
    if(k<n)
    {
        for(int i=k; i<n; i++)
        {
            a[i-1]=a[i];
        }
        n--;
    }
    else
        cout << " \n K khong thoa ma < "<<n;
}
// phần đẹ quy mang
int tongmang(int n,int a[100])
{
    if (n==0)
    {
        return 0;
    }
    return tongmang((n-1),a)+a[n-1];
}

void maxchan (int n,int a[100])
{
    int i=0;
    while (a[i]%2&&i<n)i++;
    if(i==n)
        cout << " \n Mang khong co so chan ";
    else
    {
        int d=1,mc=a[i];
        for(i=0; i<n; i++)
        {
            if(a[i]==mc)
                d++;
            else if(a[i]%2==0&&a[i]>mc)
            {
                mc = a[i];
                d = 1;
            }
        }
        cout << " \n Max chan trong mang : "<<mc;
        cout << " \n Co "<<d<<" max chan ";
    }
}
void loaiptnhohonx(int &n,int a[100],int x)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>=i; j--)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0; i<n; i++)
        if(a[i]<x)
        {
            for(int j=i; j<n; j++)
            {
                a[j]=a[j+1];
            }
            n--;
            i--;
        }
}
void loaiptlonhonx(int &n,int a[100],int x)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>=i; j--)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]); // dao cho a[i] voi a[j];
            }
        }
    }
    for(int i=0; i<n; i++)
        if(a[i]>x)
        {
            for(int j=i; j<n; j++)
                a[j+1]=a[j];
            n--;
            i--;
        }
}
void sapxepluachon(int n,int a[100])
{
    int m;
    for(int i=0; i<n; i++)
    {
        m =i;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[m])m=j;
        if(m!=i)
        {
            swap(a[i],a[m]);
        }
    }
}
void loaicacptbangx(int &n,int a[100])
{
    int x;
    cout << " \n Nhap gia tri: ";
    cin>>x;
    for(int i=0; i<n; i++)
        if(a[i]==x)
        {
            for(int j=i; j<n; j++)
                a[j]=a[j+1];
            n--;
            i--;
        }
}
void donptxvedaumang(int n,int a[100],int x)
{
    int i=0;
    while(i<n&&a[i]==x)i++;
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]==x)
            {
                swap(a[i],a[j]);
                i++;
            }
        }
    }
}
void xoamaxmang(int a[100],int &n)
{
    int max_i=0;
    int ma=a[0];
    for(int i=0; i<n; i++)
    {
        if(ma<a[i])
        {
            ma = a[i];
            max_i=i;
        }
    }
    for(int i=max_i; i<n; i++)
        a[i]=a[i+1];
    n--;
}
void xoaptkbx(int &n,int a[100],int x)
{
    int i=0;
    int d =0;
    while (a[i]==x&&i<n)i++,d++;
    if(i==n)
        cout<< "\n Khong co PT khac "<<x;
    else
    {
        for(int j=i; j<n; j++)
        {
            a[j]=a[d];
        }
        n--;
        d=0;
        i=0;
        i++;
    }
}
void HienSNTtrongmang(int n,int a[100])
{
    cout<<endl<<"SNT"<<endl;
    for(int i=0; i<n; i++)
    {
        int dem=0;
        for(int j=2; j<sqrt(a[i])+1; j++)
        {
            if(a[i]%j==0)
            {
                dem=1;
                break;
            }
        }
        if(dem==0)
            cout<<"Vi tri "<<i<<" SNT la :"<<a[i]<<endl;
    }
}

/*/// phuong phap de quy tham khao them
int timx(int n,int a[100],int x)
{
    // tim vi tri x va hhien thi

    if(n==0)
        return 0;
        else
        {
            if(a[n-1]==x&&n==2)
                return 1;
            else
            {
               return timx(n-1,a,x);
            }
        }

}*/

int main()
{
    int n,a[100];
    //int y;



    cout << "Bai Tap Ve Mang ";
    cout << " Nhap N = ";
    cin>>n;
    nhapmang(n,a);
    cout << "\n Mang vua nhap la : \n";
    htmang(n,a);
    int x;
    cout << " \n Nhap gia tri: ";
    cin>>x;
    // maxmang(n,a);
    //  minmang(n,a);
    //   sapxep(n,a); // tang dan
    //  cout << " \n Mang sau khi duoc sap xep la : \n";
    // snt(n,a);
    //cout << " \n Nhap vi tri can chen : ";cin>>k;
    // cout << " \n Nhap gia tri can chen : ";cin>>x;
    // chenx(n,a,k,x);
    //cout << " \n Nhap vi tri can xoa :";cin>>y;
    // xoay(n,a,y);
    //  maxam(n,a);
    //minduong(n,a);
    //chenptdau(n,a,x);
    //chenptcuoi(n,a,x);
    //bai1sbt(n,a);
    //bai2sbt(n,a);
    // bai3sbtb(n,a); ( chuwa lam duoc )
    //bai4sbta(n,a);
    // bai4sbtb(n,a);
    //bai3sbtb(n,a);
    //HienSNTtrongmang(n,a);
    // DE QUY

    // cout << " \n Tong cua mang la : "<<tongmang(n,a);
    // cout << " Vi tri PT "<<x<<" la : "<<timx(n,a,x);
    // maxchan(n,a);
    //loaiptnhohonx(n,a,x);
    //loaiptlonhonx(n,a,x);
    // sapxepluachon(n,a);
    // loaicacptbangx(n,a);

    //xoamaxmang(a,n);
    //xoaptkbx(n,a,x);
    //  cout << " \n ";
    //  htmang(n,a);
    return 0;
}
