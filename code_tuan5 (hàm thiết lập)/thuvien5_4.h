#include<bits/stdc++.h>
using namespace std;
class TamGiac {
    private:
        float a, b, c;
    public:
        TamGiac(float a=0, float b = 0, float c = 0) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void nhap() {
            cout << "Nhap canh a = ";
            cin >> a;
            cout << "Nhap canh b = ";
            cin >> b;
            cout << "Nhap canh c = ";
            cin >> c;
        }
        float ChuVi() {
            return a + b + c;
        }
        float DienTich() {
            float p = (a+b+c) / 2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
        bool check(float a, float b, float c) {
            this->a = a;
            this->b = b;
            this->c = c;
            if(a+b>c && a+c>b && b+c>a) {
                return true;
            }
            return false;
        }
        float Geta() {
            return a;
        }
        float Getb() {
            return b;
        }
        float Getc() {
            return c;
        }
        void in() {
            cout << "\nDo dai canh a = " << a << endl;
            cout << "\nDo dai canh b = " << b << endl;
            cout << "\nDo dai canh c = " << c << endl;
            cout << "\nChu vi tam giac = " << ChuVi() << endl;
            cout <<"\nDien tich tam giac = " << DienTich() << endl;

        }
        /*void in() {
            cout << setw(20) << left << "Canh";
            cout << setw(10) << right << a ;
            cout << setw(15) << right << b;
            cout << setw(15) << right << c;
            cout << setw(15) << right << ChuVi();
            cout << setw(15) << right << DienTich() << endl;
            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ');
        }*/
        ~TamGiac() {
            cout << "\nhuy bo doi tuong TamGiac!" << endl;
        }
};